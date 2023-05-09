//stack using array
#include <iostream>
#include <iomanip>    
#include <ctime>
#include <cstdlib>
using namespace std;

#define LENGTH 12 //defines the size of the stack


//creating a class for stack
class Stack{

   public:

        int top = -1; 
        int stack_arr[LENGTH];

    //functions of the stack
    //checks whether the stack is full
    bool isFull(){

        if(top == LENGTH){
            //cout<<"stack Overflow"<<endl;
            return true;
        }else{
            return false;
        }
    }

    //checks whether the stack is empty
    bool isEmpty(){

        if(top == -1){
            //cout<<"stack Underflow"<<endl;
            return true;
        }else{
            return false;
        }
    }

    //push an elemet to stack
    void push(int data){

        top = top + 1;
        if(isFull() != true){
            stack_arr[top] = data;
        }else{
            cout<<"stack overflow"<<endl;
            exit(1);
        }
    }   
    
    //pop an element from the stack
    int pop(){

        int value;
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
            exit(1);
        }
        else{ 
            value = stack_arr[top];
            top = top - 1;
            return value;
        }
    }

    //display the stack
    void Display(){
       
        for(int i =0; i <= top; i++){
            cout<<stack_arr[i]<<" ";   
        }
    }

    //returns the top element of the stack
    int stack_top(){
        
        if(isEmpty()){
            cout<<"stack underflow"<<endl;
            exit(1);
        }else{
            return stack_arr[top];
        }
    }

};


//function to generate random numbers
void generateRandomArray(int arr[], int length)
{
    srand(time(NULL)); 

    for (int i = 0; i < length; i++) {
        arr[i] = rand()%100;
    }
}


int main(){
    cout<<"Array implementation of a Stack"<<endl;
    //int arr[LENGTH];      //uncomment use random values

    //generateRandomArray(arr, LENGTH);     //uncomment use random values

    clock_t start1 = clock();

    Stack stack;

    //for(int j=0; j < LENGTH; j++){    //uncomment use random values

      //  stack.push(arr[j]);       
    //}

    stack.push(51);  //comment when using random values
    stack.push(65); //comment when using random values
    stack.push(0);  //comment when using random values
    stack.push(14); //comment when using random values
    stack.push(41); //comment when using random values
    stack.push(103); //comment when using random values
    stack.push(15); //comment when using random values
    stack.push(8); //comment when using random values
    stack.push(35); //comment when using random values
    stack.push(23); //comment when using random values
    stack.push(53);
    stack.push(73);
    stack.Display(); //comment when using random values
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
    stack.push(12);
    stack.Display();
    cout << "Top element is " << stack.stack_top() << endl;

    clock_t finish1 = clock();
    double doneTime1 = (finish1 - start1) / (double)CLOCKS_PER_SEC;
    cout <<"time taken "<< fixed << setprecision(10) << doneTime1 <<" ms"<<"\n\n";


}
