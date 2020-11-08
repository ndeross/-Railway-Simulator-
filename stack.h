#ifndef STACK
#define STACK
 

const int MAX_STACK = 100;       

 
struct StackT{ 
    int top; 
    int size;
    string name;  
    CarT spur[MAX_STACK];   
    }; 

  
    
void InitStack(StackT & s); 
void Push(StackT & s, ItemT item); 
ItemT Pop(StackT & s); 
ItemT Top(const StackT & s); 
bool IsEmpty(const StackT & s);
bool IsFull(const StackT & s);
int Size(const StackT & s);
 
 
#endif