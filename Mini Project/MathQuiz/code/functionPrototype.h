
void insert(char q[],int a);              //inserts question and its answer to the linked list	
void traverse_question();                          //displays all the question and answer
void file_data(char file[], int q_no);    //gets the mentioned number of question from the mentioned file
Node_PQ* newNode_PQ(int d, int p);        //start node of the priority queue
int peek(Node_PQ** head);                 //peek the top element
void pop(Node_PQ** head);                 //pops the top element
void push(Node_PQ** head, int d, int p);  //push the element to the queue
int isEmpty(Node_PQ** head);              //checks whether the queue is empty
void checkAnswer(char q[],int a);          //checks the answer and updates the score;

