//stack using linked list
#include <iostream>
#include <iomanip>    
#include <ctime>
#include <cstdlib>
using namespace std;

# define LENGTH 12  //defines the size of the stack

//creating a class for Create nodes for linked list
class Node{

    public:
        int value;
        Node* next;
    
        Node(int n){
            this->value = n;
            this->next = NULL;
        }
    };

//creating a class for stack 
class Stack {
    
    Node* top;
  
    public:
        Stack() {
             top = NULL; 
         }
        
        //functions of the stack
        //checks whether the stack is empty
        bool isEmpty(){
            if(top == NULL){
                return true;
            }else return false;
        }

        //push an elemet to stack
        void push(int value)
        {

            Node* newNode = new Node(value);
  
            if (!newNode) {
                cout << "Stack Overflow"<<endl;
                exit(1);
            }
  
            newNode->value = value;
            newNode->next = top;
            top = newNode;
        }

        //pop an element from the stack
        void pop(){
            Node* temp;
  
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                exit(1);
            }
            else {
  
                temp = top;
                top = top->next;
                free(temp);
            }
        }

        //returns the top element of the stack
        int stack_top(){

            if (isEmpty()){
                cout << "Stack Underflow" << endl;
                exit(1);
            }
         
            else return top->value;
        }

        //display the stack
        void Display(){
            
            Node* temp;

            if (isEmpty()) {
                cout << "Stack Underflow"<<endl;
                exit(1);
            }
            else {
                temp = top;
                while (temp != NULL) {
  
                    cout << temp->value<<" ";
                    temp = temp->next;
                }
            }

        }
    };

//function to generate random numbers
void generateRandomArray(int arr[], int length){
    srand(time(NULL)); 

    for (int i = 0; i < length; i++) {
        arr[i] = rand()%100; 
    }
}


int main(){
    cout<<"Linked List implementation of a Stack"<<endl;
    //int arr[LENGTH]; //uncomment use random values

    //generateRandomArray(arr, LENGTH);  //uncomment use random values

    clock_t start1 = clock();

    Stack stack;

    //for(int j=0; j < LENGTH; j++){ //uncomment use random values

    //    stack.push(arr[j]); 
    
    //}                        

    stack.push(51);      //comment when  using random values
    stack.push(65);     //comment when  using random values
    stack.push(0);      //comment when  using random values
    stack.push(14);     //comment when  using random values
    stack.push(41);     //comment when  using random values
    stack.push(103);    //comment when  using random values
    stack.push(15);     //comment when  using random values
    stack.push(8);      //comment when  using random values
    stack.push(35);     //comment when  using random values
    stack.push(23);     //comment when  using random values
    stack.push(53);
    stack.push(73);
    stack.Display();
    cout << "Top element is " << stack.stack_top() << endl;
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.Display();
    cout << "Top element is " << stack.stack_top() << endl;
    stack.push(5);
    stack.push(35);
    stack.push(13);
    stack.Display();

    cout << "Top element is " << stack.stack_top() << endl;
    
    clock_t finish1 = clock();
    double doneTime1 = (finish1 - start1) / (double)CLOCKS_PER_SEC;
    cout <<"time taken "<< fixed << setprecision(10) << doneTime1 <<" ms"<<"\n\n";

}
