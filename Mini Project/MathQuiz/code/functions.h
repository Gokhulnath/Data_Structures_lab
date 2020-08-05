// node for linked list 
struct node_LL {
   char Q_data[500];
   int A_data;
   struct node_LL *next;
};

// Node for priority queue
typedef struct node_PQ { 
    int data; 
  
    // Lower values indicate higher priority 
    int priority; 
  
    struct node_PQ* next; 
  
} Node_PQ;  

int count = 0;
int score;
struct node_LL *start = NULL;


void insert(char q[], int a) {
   struct node_LL *t, *temp;
   
   t = (struct node_LL*)malloc(sizeof(struct node_LL));
   count++;
   
   if (start == NULL) {
      start = t;
      strcpy(start->Q_data, q);
      start->A_data = a;
      start->next = NULL;
      return;
   }
   
   temp = start;
   
   while (temp->next != NULL)
      temp = temp->next;  
   
   temp->next = t;
   strcpy(t->Q_data, q);
   t->A_data = a;
   t->next    = NULL;
}
 
void traverse_question() {
   int q_no=10;
   struct node_LL *t;
   t = start;
   //system("cls");
   if (t == NULL) {
      printf("Linked list is empty.\n");
      return;
   }
      
   for(int i=0;i<q_no;i++) {
   	checkAnswer(t->Q_data,t->A_data);
     // printf("%s\n\n\n", t->Q_data);
      t = t->next;
   }
   system("cls");   
   printf("\n\n\n\n\t\t\t\tYOUR FINAL SCORE IS %d points\n\n\n\t\t\t\t\tTHANK YOU!!!!!!!!\n\n\n\n\n",score);
}
 
void file_data(char file[], int q_no)
{
	int A_data;
   char Q_data[500];
   FILE *f = fopen(file, "r");
   int c = getc(f);
   int i=1;
   while (i<=q_no) {
      fscanf(f,"%s",Q_data);
      
      c = getc(f);
      fscanf(f,"%d",&A_data);
      c = getc(f);
      insert(Q_data,A_data);
      i++;
   }
   fclose(f);
}

// Function to Create A New Node_PQ 
Node_PQ* newNode_PQ(int d, int p) 
{ 
    Node_PQ* temp = (Node_PQ*)malloc(sizeof(Node_PQ)); 
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL; 
  
    return temp; 
} 
  
// Return the value at head 
int peek(Node_PQ** head) 
{ 
    return (*head)->data; 
} 
  
// Removes the element with the 
// highest priority form the list 
void pop(Node_PQ** head) 
{ 
    Node_PQ* temp = *head; 
    (*head) = (*head)->next; 
    free(temp); 
} 
  
// Function to push according to priority 
void push(Node_PQ** head, int d, int p) 
{ 
    Node_PQ* start = (*head); 
  
    // Create new Node_PQ 
    Node_PQ* temp = newNode_PQ(d, p); 
  
    // Special Case: The head of list has lesser 
    // priority than new node_PQ. So insert new 
    // node_PQ before head node_PQ and change head node_PQ. 
    if ((*head)->priority > p) { 
  
        // Insert New Node_PQ before head 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
  
        // Traverse the list and find a 
        // position to insert new node_PQ 
        while (start->next != NULL && 
               start->next->priority < p) { 
            start = start->next; 
        } 
  
        // Either at the ends of the list 
        // or at required position 
        temp->next = start->next; 
        start->next = temp; 
    } 
} 
  
// Function to check is list is empty 
int isEmpty(Node_PQ** head) 
{ 
    return (*head) == NULL; 
} 


void checkAnswer(char q[],int a)
{
	int data;
	system("cls");
	printf("\n\n\n\nScore:%d\n\n\n",score);
	printf("\t\t\t\t%s\n",q);
	printf("\t\t\t\tAnswer= ");
	scanf("%d",&data);
	if(data==a)
	{
		printf("\n\n\n\t\t\t\tCORRECT ANSWER!!!!!!!!!!");
		score+=2;
		sleep(1);
	}
	else
	{
		printf("\n\n\n\t\t\t\tWRONG ANSWER!!!!!!!!!!");
		score-=1;
		sleep(1);		
	}
	
}
