#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "functions.h"
#include "functionPrototype.h"

void main()
{
	int p;
	int q=4;
	printf("\nWELCOME TO MATH QUIZ\n");
	printf("Each coorect question carries 2 points and each wrong answer will reduce 1 point\n\n");
	printf("\n\nPlease choose the priority for each section:\n\nThe available sections are as follow:\n1.Addition\n2.Subraction\n3.Multiplication\n4.Division\n\n");
	printf("You can choose the priority based on your difficulty in each section, give your priority by 1-most familiar and 4-least familiar\n\n");
	printf("Addition: ");
	scanf("%d",&p);
	Node_PQ* pq = newNode_PQ(0, p);
	printf("\nSubraction: ");
	scanf("%d",&p); 
    push(&pq, 1, p);
	printf("\nMultiplication: ");
	scanf("%d",&p); 
    push(&pq, 2, p);
	printf("\nDivision: ");
	scanf("%d",&p); 
    push(&pq, 3, p); 
    printf("\n\n");
    
  
    while (!isEmpty(&pq)) { 
//      printf("%d ", peek(&pq));
		switch(peek(&pq))
		{
			case 0:
				file_data("add.txt",q);
				q-=1;
				break;
			case 1:
				file_data("sub.txt",q);
				q-=1;
				break;
			case 2:
				file_data("mul.txt",q);
				q-=1;
				break;
			case 3:
				file_data("div.txt",q);
				q-=1;
				break;
		 } 
        pop(&pq); 
    } 
	traverse_question();
}
 

