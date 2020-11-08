// This Driver will test both the CarT type, and the Stack Type 


#include <iostream>
#include "destination.h" 
#include "car.h"  
#include "stack.h"

using namespace std;


int main() { 

StackT s; 
int i;
CarT c;  

InitStack(s); 
cout << endl; 

// Check to see if the stack will fill, and stop filling at 100 

for (i=0; i < MAX_STACK; i++) {
Push(s, TEST_CAR);
if (s.size > MAX_STACK) {cout << "ERROR, SIZE HAS EXCEDED MAX";}        
}

cout << "There should be an overflow message directly under this: " << endl; 
Push(s, ERROR_CAR); 
cout << endl; 


// Check to see if stack will empty properly 

for(i=MAX_STACK; i > 0; i--){

Pop(s);
 
}

cout << "There should be an empty stack  message directly under this: " << endl;
Pop(s); 
cout << endl;


// Testing the top function to see if it works properly 

Push(s, TEST_CAR);

c = Top(s); 

cout << "Underneath this there should be a car string A, Albion:" << endl; 
cout << CarTToString(c) << endl; 
cout << endl; 


// Check to see if the is empty and is full functions are working properly 

Pop(s); // Stack s will now be empty 

cout << "If IsEmpty function is working, a message stating" 
         " the stack is empty will appear underneath this:" << endl; 

if (IsEmpty(s)) { cout << "The stack is empty";
                  cout << endl;  } 

cout << endl; 

for (i=0; i < MAX_STACK; i++) {   
Push(s, TEST_CAR);                 //Fills Stack 
}

cout << "The stack has been filled, and under this will be a message stating the stack is full:" << endl; 
if (IsFull(s)) {cout << "The stack is full" << endl; 
                cout << endl; }


// Testing the size of the stack to make sure it is accurate 


for(i=MAX_STACK; i > 0; i--){   // First the stack is emptied 
Pop(s);
}

for(i=0; i < 50; i++){ 
Push(s,TEST_CAR); 
}

cout << "The Stack should now have 50 elements, if this is true the number 50 will appear under this:" << endl; 
cout << s.size << endl; 
cout << endl;  
 
return 0; 

} 

