#ifndef CAR
#define CAR

#include <string>
#include <fstream>
#include "destination.h" 

using namespace std; 
 
struct CarT{
    std::string name;
    DestinationT destination; 
};   

const CarT ERROR_CAR {"ERROR", DestinationT:: UNKNOWN};
const CarT TEST_CAR {"A", DestinationT:: ALBION};   

const string ITEM_OVERFLOW_ERROR = "ERROR spur capacity exceeded!";  
 
const string NO_ITEM_ERROR = "ERROR spur is empty, cannot remove a car!"; 

std:: string CarTToString (const CarT & c); 

CarT StringToCarT (const std:: string & car); 

bool IsSmaller (const CarT & a, const CarT & b); 

std:: string CarName(const CarT & a); 

DestinationT CarDestination(const CarT & c);   
 
typedef CarT ItemT; 

const CarT NO_ITEM = ERROR_CAR;  

#endif 