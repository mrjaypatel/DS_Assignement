
#include <bits/stdc++.h>
using namespace std;

//standard stack data structure
/*
Here we will store two values: data and minimum
data is to store the data vale
minimum is to store the minimum till the current node
*/
struct Node{
        int data;
        int min;
        struct Node* link;
};

struct Node* top=NULL;
int minimum=INT_MAX;//this is used to store minimum value, initially its max value of int

void push(int data){

        //create a new node and allocate memory
        struct Node* newNode=new Node();

        if(newNode==NULL){
                cout<<"Memory is full. Memory overflow\n";
                exit(1);
        }

        newNode->data=data;//Initialize data into new node
        newNode->link=top;//the link contains the reference to top
        top=newNode;//top becomes new nodes reference
        if(data<minimum)//if current data is less than minimum then reinitialize minimum
        {
                minimum=data;
        }
        newNode->min=minimum;//min stores the minimumvale till the top of the stack
}

int isEmpty(){
        return top==NULL;//if top is null then it will return 1 else 0
}

void pop(){
        struct Node* temp;
        if (top==NULL)
        {
                cout<<"Stack is empty";
        }
        else{
                struct Node* temp;
                temp=top;
        cout<<"Popped element: "<<temp->data<<"\n";
                top=top->link;
                temp->link=NULL;
                free(temp);//popping the element
                if(top!=NULL)//After popping the top, minimum is initialized to min vale of top node
                {
                        minimum=top->min;
                }
                else{
                        minimum=INT_MAX;//if stack is empty then initialize minimum with garbage value
                }
        }
}

//as we are keeping track of minimum element, this function will return min in O(1)
int getMin(){
        if(top==NULL){
                cout<<"Stack is empty, so no minimum found and returning garbage value";
                return minimum;
        }
        return minimum;
}

int main(){
        while(1){
                cout<<"Enter\n1. Push\n2. Pop\n3. Get minimum\n4. Display stack\n5. Quit\n";
                int choice;
                cin>>choice;
                if (choice==1)
                {
                        cout<<"Enter element to push: ";
                        int element;
                        cin>>element;
                        push(element);
                }
                else if(choice==2){
                        pop();
                }
                else if(choice==3){
                        if(top!=NULL){
                                cout<<"Minimum Element is: "<<getMin()<<"\n";
                        }
                }
                else if(choice==4){
                        if(top==NULL){
                                cout<<"Stack is emptu=y\n";
                        }
                        else{
                cout<<"Stack is\n";
                                struct Node* ptr;
                                ptr=top;
                                while(ptr!=NULL){
                                        cout<<ptr->data<<"\n";
                                        ptr=ptr->link;
                                }
                        }
                }
                else if(choice==5){
                        break;
                }
                else{
                        cout<<"Please enter a valid choice\n";
                }
        }
}