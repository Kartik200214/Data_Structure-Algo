//  Program Name : Generic Stack                                                              
                                                                                           
//  Description :  This application implement the stack by using linkedlist which accept      
//                  any given datatype.                                                       

#include<iostream>
using namespace std;

// Structure node
template <typename T>
struct node
{
    T data;
    struct node * next;
};

#define NODE node<T>
#define PNODE node<T>*

template <class T>
class Stack     // Singly linked list
{
    private :
        int size;
        PNODE Top;

    public :
    Stack();
    void Push(T iNo);
    void Pop();
    int Count();
    void Display();
    bool isEmpty();
};

template <class T>
Stack<T> :: Stack()
{
    size = 0;
    Top = NULL;
}

template <class T>
void Stack<T> :: Push(T iNo)     // Insert at first
{
    // Memory allocation
    PNODE newN = new NODE();

    // Intilize new node
    newN->data = iNo;
    newN->next = NULL;

    // Insert node
    if(Top == NULL)
    {
        Top = newN;
    }
    else
    {
        newN->next = Top;
        Top = newN;
    }
    size++;
}

template <class T>
void Stack<T> :: Pop()
{
    if(Top == NULL)
    {
        return;
    }
    else if(Top->next == NULL)
    {
        Top = NULL;
        delete(Top);
    }
    else
    {
        PNODE target = Top;
        Top = Top->next;
        target = NULL;
        delete(target);
    }
    size--;
}

template <class T>
void Stack<T> :: Display()
{
    PNODE temp = Top;

    if(Top == NULL)
    {
        cout << "\nEmpty stack" << endl;
    }
    else
    {
        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}

template <class T>
bool Stack<T> :: isEmpty()
{
    if(Top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
int Stack<T> :: Count()
{
    return size;
}


// Entry point function
int main()
{
    // Local variables
    Stack <char> sobj;
    int iChoice = 1, iRet = 0;
    char value = '\0';
    bool bAns = false;

    printf("\nStack\n");

    while (iChoice != 0)
    {
        printf("\n_________________________________________________\n");
        printf("Stack operations : \n\n");
        printf("1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : isEmpty\n");
        printf("4 : Count\n");
        printf("5 : Display\n");
        printf("0 : Terminate the application\n");
        printf("\nSelect Option -> ");
        scanf("%d", &iChoice);
        printf("\n_________________________________________________\n");

        switch (iChoice)
        {
        case 1:
            printf("Enter the data to push into stack\n");
            cin >> value;
            sobj.Push(value);
            printf("\nData pushed at top of stack\n");
            break;

        case 2:
            sobj.Pop();
            break;

        case 3:
            bAns = sobj.isEmpty();
            if (bAns == true)
            {
                printf("Stack is empty");
            }
            else
            {
                printf("Stack is not-empty");
            }
            break;

        case 4:
            iRet = sobj.Count();
            printf("Total elements in stack : %d", iRet);
            break;

        case 5:
            sobj.Display();
            break;

        case 0:
            printf("\nThankyou for using Stack...\n\n");
            break;

        default:
            printf("\nPlease enter proper choice\n");
            break;
        }
    }

    return 0; 
}
