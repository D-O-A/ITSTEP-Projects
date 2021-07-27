#include "Headers.h"

int main()
{
	Queue<int> queueList;

	queueList.Enqueue(42, LOW);
	queueList.Enqueue(31, HIGH);  
	queueList.Enqueue(15, MEDIUM);
	queueList.Enqueue(22, HIGH);
	queueList.Enqueue(11, MEDIUM);
	queueList.Enqueue(44);   //по умолчанию HIGH
	queueList.Enqueue(66, LOW);

	//42, 66, 11, 15, 44, 22, 31

	//queueList.Dequeue();
	//queueList.Dequeue();

	queueList.Peek();
	queueList.Print();
}