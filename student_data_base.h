#include "Queue.h"


#define width 3

typedef struct
{
	char FirstName[20];
	char LastName[20];
	int ID;
	float GPA;
	int CoursesResgisterd[5];
}SStudent_Info;


/*determine type of array with same of type of element*/
SStudent_Info student_buffer[width];


int add_student_file(FIFO_Buf_t*fifo,SStudent_Info* item);
void FIFO_print(FIFO_Buf_t* fifo);
int CountOFStudent(FIFO_Buf_t* fifo);
int Find_The_Student_By_FirstName(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Find_The_Students_Registered_In_course(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Delete_Student_By_ID(FIFO_Buf_t* fifo,SStudent_Info *pStudent);
int Updata_Student(FIFO_Buf_t* fifo,SStudent_Info *pStudent);

