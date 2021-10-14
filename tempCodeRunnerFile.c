#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#define maxsize 5

void menu();
void initdeque();
void enqueBeg(int);
void enqueEnd(int);
int dequeueBeg();
int dequeueEnd();
void display();

int deque[maxsize];
int front, rare;

int main()
{
    initdeque();
    menu();
    return 0;
}


void menu()
{
    int choice;
    char ch;
    do{
        //clrscr();
        printf("**************** MENU *******************\n");
        printf("Choose any one form the below option:-\n");
        printf("1. Insert to deQueue from beg\n");
        printf("2. Insert from deQueue from end\n");
        printf("3. Delete to deQueue from beg\n");
        printf("4. Delete to deQueue from end\n");
        printf("5. Display the Queue\n");
        printf("6. Exit\n");

        scanf("%d", &choice);  
        int data;      
        switch(choice){
            case 1: printf("Enter the element to insert at begin\n");
            scanf("%d", data);
            enqueBeg(data);
            break;
            
            case 2: printf("Enter the element to insert at end\n");
            scanf("%d", data);
            enqueEnd(data);
            break;

            case 3: dequeueBeg();//printf("Deleted front element is: %d\n", dequeBeg());
            break;

            case 4: dequeueEnd();//printf("Deleted rare element is: %d\n", dequeEnd());
            break;

            case 5:display();
            getch();
            break;

            case 6: //exit(0); 
            printf("Hi\n");
        }
    } while(1);
}

void initdeque()
{
    front = rare = -1;
}

void enqueBeg(int data)
{
    //if(front == 0 && rare == maxsize-1) overflow
    if(front == -1){
        front = rare = 0;
        deque[front] = data;
    }
    else if(front=0 && rare != maxsize-1){
        for(int i= front; i<=rare; i++){
            deque[i+1] = deque[i];
        }
        deque[front] = data;
    }
    else if(front > 0){
        deque[--front] = data;
    }
}

void enqueEnd(int data)
{
    if(front == -1){
        front = rare =0;
        deque[front] = data;
    }
    else if(front != 0 && rare == maxsize-1){
        for(int i=front; i<=rare; i++){
            deque[i-1] = deque[i];
        }
        deque[rare] = data;
    }
    else if(rare < maxsize){
        deque[++rare] = data;
    }
}

int dequeueBeg()
{
    int data;
    if(front == -1){
        printf("Underflow\n");
        return -1;
    }
    else{
        data = deque[front];
        deque[front]= 0;
        if(front== rare){
            initdeque();
        }
        else{
            front++;
        }
    }
    return data;
}

int dequeueEnd()
{
    int data;
    if(front == -1){
        printf("Underflow\n");
        return -1;
    }
    else{
        data = deque[rare];
        deque[rare] = 0;
        if(rare == front){
            front = rare = -1;
        }
        else{
            rare--;
        }        
    }
    return data;
}

void display(){
    for(int i= front; i<=rare; i++){
        printf("%d\t", deque[i]);
    }
    printf("\n");
}