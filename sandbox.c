
#include <malloc.h>
#include <stdio.h>
#include <ucontext.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>

extern void readString(char *s, int r); 
extern void main(int argc, char *argv[]);

void protectHandler(int signo, siginfo_t* siginfo, void* unused);

long (* addressOfReadString)(char *, int );
long (* addressOfMain)(int , char *);
long mainReturnAddress;

/*
 * initilize sandbox
 * Store addressed in global variables
 * Install signal handler for SIGSEGV
 */
void init_sandbox()
{
	int pageSize = 1;
	/*Store address of readString and main`*/
	addressOfReadString = (void*) readString;
	addressOfMain = (void*) main;
	
	/*Remove execute permission from readString*/
	mprotect((void*)((long)addressOfReadString & 0xfffffffffffff000), pageSize, PROT_READ);
	mprotect((void*)((long)addressOfMain & 0xfffffffffffff000), pageSize, PROT_READ | PROT_EXEC);
	
	/*Install SignalHandler*/
	struct sigaction new_sa;
	memset(&new_sa, 0, sizeof(new_sa));
	new_sa.sa_sigaction = protectHandler;
	new_sa.sa_flags = 0;
	new_sa.sa_flags = new_sa.sa_flags | SA_SIGINFO | SA_RESTART;
	sigemptyset(&new_sa.sa_mask);
	sigaddset(&new_sa.sa_mask, SIGSEGV);
	
	sigaction(SIGSEGV, &new_sa, NULL);
	
	sigset_t new_mask;
	sigemptyset(&new_mask);
	sigaddset(&new_mask, SIGSEGV);
	
	sigprocmask(SIG_UNBLOCK, &new_mask, NULL);
}
/*Signal handler for SIGSEGV*/
void protectHandler(int signo, siginfo_t* siginfo, void* contextInfo)
{
	int pageSize = 1;
	void* segmentFaultAddress;
	ucontext_t *context;
	
	segmentFaultAddress = siginfo->si_addr;
	context = (ucontext_t *) contextInfo;
	/*If readString is called*/
	if( ((long)addressOfReadString) == ((long)segmentFaultAddress))
	{
		/*Return address of readString, stored in global variable*/
		mainReturnAddress = *(int *)context->uc_mcontext.gregs[15];
		/*Give execute permission to readString, remove execute permission from main*/
		mprotect((void*)((long)addressOfReadString & 0xfffffffffffff000), pageSize, PROT_EXEC | PROT_READ);
		mprotect((void*)((long)addressOfMain & 0xfffffffffffff000), pageSize, PROT_READ);
	}
	/*If readString returned to main*/
	else if( ((long)addressOfMain & 0xfffffffffffff000) == ((long)segmentFaultAddress & 0xfffffffffffff000) )
	{
		/*If returned at correct address*/
		if(((long)mainReturnAddress) == ((long)segmentFaultAddress))
		{
			/*Give execute permission to main, remove execute permission from readString*/
			mprotect((void*)((long)addressOfMain & 0xfffffffffffff000), pageSize, PROT_EXEC | PROT_READ);
			mprotect((void*)((long)addressOfReadString & 0xfffffffffffff000), pageSize, PROT_READ);
		}
		/*returned at incorrect address in main*/
		else
		{
			printf("malicious buffer overflow detected, will exit!\n");
			exit(0);
		}
	}
	/*Returned to somewhere else, other than main*/
	else{
		printf("malicious buffer overflow detected, will exit!\n");
		exit(0);
	}
}
