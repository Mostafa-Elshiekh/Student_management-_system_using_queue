
FIFO_Buf_status FIFO_is_full(FIFO_Buf_t* fifo)
{
	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is full ?*/
	if(fifo->count==fifo->length)
		return FIFO_full;

	return FIFO_no_error;
}



FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo ,SStudent_Info* buf,unsigned int length)
{
	if(buf== NULL)
		return FIFO_NULL;

	fifo->base=buf;
	fifo->tail=buf;
	fifo->head=buf;
	fifo->count=0;
	fifo->length=length;
	return FIFO_no_error;
}


FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudent_Info *item)
{

	//int *ptr=&item;
	int j=0;


	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	//check if queue is full ?
	if(FIFO_is_full(fifo)==FIFO_full)
		return FIFO_full;

	printf("\n===================\n");

	printf("\tEnter the first name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",fifo->head->FirstName);



	printf("\tEnter the last name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",fifo->head->LastName);

	printf("\tEnter the ID: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&fifo->head->ID);

	printf("\tEnter the GPA: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&fifo->head->GPA);

	printf("\tEnter the ID CoursesResgisterd\n ");
	fflush(stdin);fflush(stdout);
	for(j=0;j<5;j++)
	{
		printf("\tEntet the ID of the %d course: ",j+1);
		scanf("%d",&fifo->head->CoursesResgisterd[j]);
	}
	printf("===================\n");


	fifo->count++;

	/*circler fifo*/
	if(fifo->head == (fifo->base + (fifo->length * sizeof(SStudent_Info))))
		fifo->head=fifo->base;

	else
		fifo->head++;

	return FIFO_no_error;

}


FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudent_Info* item)
{

	/*check if queue is valid ?*/
	if(!fifo->base || !fifo->head  || !fifo->tail)
		return FIFO_NULL;

	/*check if queue is empty ?*/
	if(fifo->count==0)
	{
		printf("\n==================================\n");
		printf("The Queue Is Empty");
		printf("\n==================================\n");
		return 0;
	}

	/*dequeue data*/
	(item->ID)=(fifo->tail->ID);
	fifo->count--;
    
    printf("\n==========================================================\n");
	printf("FIFO DEQUEUE WHICH ID OF STUDENT IS %d-------->DONE :)\n",item->ID);
	printf("============================================================\n");
	/*circler fifo*/
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(SStudent_Info))))
		fifo->tail=fifo->base;

	else
		fifo->tail++;

	return FIFO_no_error;

}
