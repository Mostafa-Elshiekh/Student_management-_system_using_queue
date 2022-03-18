
/*FIFO data type*/
typedef struct
{

	unsigned int length;
	unsigned int count;
	SStudent_Info* base;
	SStudent_Info* head;
	SStudent_Info* tail;
}FIFO_Buf_t;



typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_NULL
}FIFO_Buf_status;


FIFO_Buf_status FIFO_is_full(FIFO_Buf_t* fifo);
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,SStudent_Info* buf,unsigned int length);
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudent_Info *item);
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudent_Info* item);

