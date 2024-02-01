#include<stdio.h>
#include<stdlib.h>

int mutex=1,full=0,empty,x=0;

main()
{
	int n,size;
	void producer();
	void consumer();
	int wait(int);
	int signal(int);

	printf("Enter the size :");
	scanf("%d",&size);
	empty=size;
	printf("\n1.producer\n2.consumer\n3.exit\n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
					producer();
				else
					printf("buffer is full\n");
				break;
			case 2:	if((mutex==1)&&(full!=0))
					consumer();
				else
					printf("buffer is empty\n");
				break;
			case 3:	exit(0);
		}
	}
}
void producer()
{
	mutex=wait(mutex);
	full=signal(full);
	empty=wait(empty);
	x++;
	printf("producer produces the item %d\n",x);
	mutex=signal(mutex);
}




void consumer()
{
	mutex=wait(mutex);
	full=wait(full);
	empty=signal(empty);
	printf("consumer consumes the item %d\n",x);
	x--;
	mutex=signal(mutex);
}
int wait(s)
{
	return (--s);
}
int signal(s)
{
	return (++s);
}

