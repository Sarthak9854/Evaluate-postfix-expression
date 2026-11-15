#include<iostream>
#include<cmath>
using namespace std;

class stack
{
    private:
    int arr[100];
    int top;

    public:
    stack()
    {
        top=-1;
    }
    void push(int val)
    {
        arr[++top]=val;
    }
    int pop()
    {
        int p=arr[top--];
        return p;
    }
};

int evaluate(char x, int op1, int op2)
{
    if(x=='+') return(op1+op2);
    if(x=='-') return(op1-op2);
    if(x=='*') return(op1*op2);
    if(x=='/') return(op1/op2);
    if(x=='%') return(op1%op2);
    if(x=='$') return(pow(op1,op2));
}

int main(void)
{
    stack s;
    char x;
    int op1, op2, val;

    cout<<"\n Enter Postfix Expression:";
    while((x= getchar()) != '\n')
    {
        if(isdigit(x))
        {
            s.push(x-48);
        }
        else
        {
            op2=s.pop();
            op1=s.pop();
            
            val=evaluate(x, op1,op2);
            s.push(val);
        }
    }

    val=s.pop();
    cout<<"\n Answer="<<val;
    return 0;
}


/*
OUTPUT
PS D:\Sarthak C> 




               > cd "d:\Sarthak C\" ; if ($?) { g++ Eval_Postfix.cpp -o Eval_Postfix } ; if ($?) { .\Eval_Postfix }

 Enter Postfix Expression:1 2 3 4 5 6 7 8 9

 Answer=9
PS D:\Sarthak C> 
*/