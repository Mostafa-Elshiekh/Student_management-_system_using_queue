#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student_data_base.h"



int main(void)
{

	FIFO_Buf_t student;
	int i;
	int Selection;
	SStudent_Info test;

	if(FIFO_init(&student,student_buffer,3)==FIFO_no_error)
	{
		printf("\n=============================================");
		printf("\nFIFO INIT HAS BEEN --------------->DONE:) \n");
		printf("===============================================");
    }



	while(1)
	{
		printf("\nPress 1 If You Need Add Student: ");
		printf("\nPress 2 to read from file: ");
		printf("\nPress 3 If You Need View Students Info: ");
		printf("\nPress 4 If You Need Dequeue: ");
		printf("\nPress 5 If You Need Count Of Students: " );
		printf("\nPress 6 To Find The Student By ID :");
		printf("\nPress 7 To Find The Student By FirstName: ");
		printf("\nPress 8 To Find The Students Registered In course: ");
		printf("\nPress 9 To Delete Student By ID: ");
		printf("\nPress 10 To Updata Student Info: ");
		printf("\nPress 11 If You Need End The Program: ");

		scanf("%d",&Selection);


		if(Selection==1)
		{
			if(FIFO_enqueue(&student,&test)==FIFO_no_error)
			{
				printf("====================================\n");
				printf("\t FIFO ENQUEUE -------->Done :)\n");
				printf("====================================\n");
			}

			else if((FIFO_enqueue(&student,student_buffer)==FIFO_full))
			{
				printf("\n====================================\n");
				printf("FIFO IS FULL\n");
				printf("====================================\n");
			}
			else
			{
				printf("\t FIFO ENQUEUE ------->FAILD :( \n");
			}
		}
		if(Selection==2)
		{
			add_student_file(&student,student_buffer);
		}

		if(Selection==3)
		{
			FIFO_print(&student);
		}

		else if(Selection==4)
		{
			if(FIFO_dequeue(&student,&test)==FIFO_no_error);
		}

		if(Selection==5)
		{
			printf("\n====================================\n");
			printf("NUMBER OF SUDENTS IS %d \n",CountOFStudent(&student));
			printf("======================================\n");
		}
		if(Selection==6)
		{
			Find_The_Student_By_ID(&student,student_buffer);
		}
		if(Selection==7)
		{
			Find_The_Student_By_FirstName(&student,student_buffer);
		}
		if(Selection==8)
		{
			Find_The_Students_Registered_In_course(&student,student_buffer);
		}
		if(Selection==9)
		{
			Delete_Student_By_ID(&student,student_buffer);
		}
		if(Selection==10)
		{
			Updata_Student(&student,student_buffer);
		}
		
		if(Selection==11)
		{
			break;
		}

	}

	return 0;
}

