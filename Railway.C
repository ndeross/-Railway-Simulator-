
#include <iostream>
#include <fstream>
#include <string>
#include "destination.h"
#include "car.h"
#include "stack.h"

using namespace std;

string GetCommand(string s);

void PopPrint(CarT item, StackT remove, StackT place);

string GetStation(string inputLine);

void Interpret(string command, string stationName, string inputLine,
               StackT &WEST, StackT &EAST, StackT &YARD, StackT &LOCAL,
               StackT &TRAIN, StackT &station);

void FixStation(string s, StackT &LOCAL, StackT &WEST, StackT &EAST,
                StackT &station);

int Exit(string stationName);

string ToUpper(string s);

string FindSpurName(string inputLine);

void InitializeStacks(StackT &WEST, StackT &EAST, StackT &YARD, StackT &LOCAL,
                      StackT &TRAIN);

StackT SpurAsStackT(string spurName, StackT &LOCAL, StackT &WEST, StackT &EAST,
                    StackT &YARD, StackT &TRAIN);

StackT GetTrains(string s, int count);

string Split(string s);

int CountTrains(string s);

string GetTrainString(string s);

void LoadSpur(string trainString, StackT &station, int count, StackT &YARD,
              StackT &TRAIN, StackT &LOCAL, StackT &WEST, StackT &EAST,
              string stationName);

void MoveTrain(StackT &a, StackT &b);

void Sort(StackT &station, StackT &YARD, StackT &LOCAL, StackT &WEST,
          StackT &EAST, string spurName, string stationName);

void Print(const StackT s);

string ReverseString(string s);

string GetSecondSpur(string s);

int main() {
  string inFileName, stationName, inputLine, command;
  ifstream railIn;
  StackT WEST, EAST, YARD, LOCAL, TRAIN, station;

  TRAIN.name = "arriving train";
  LOCAL.name = "Local";
  YARD.name = "Yard";
  EAST.name = "East";
  WEST.name = "West";

  InitializeStacks(WEST, EAST, YARD, LOCAL, TRAIN);

  cout << "Enter the file name => ";
  cin >> inFileName;
  cout << '\n';       
  railIn.open(inFileName.c_str());

  getline(railIn, stationName);

  getline(railIn, inputLine);

  while (railIn)

  {
    if (inputLine != "")

    {
      cout << "Executing " << inputLine << endl; 
      command = GetCommand(inputLine);
      Interpret(command, stationName, inputLine, WEST, EAST, YARD, LOCAL, TRAIN,
                station);
      getline(railIn, inputLine);

    } else
      getline(railIn, inputLine);
  }

  return 0;
}

void Interpret(string command, string stationName, string inputLine,
               StackT &WEST, StackT &EAST, StackT &YARD, StackT &LOCAL,
               StackT &TRAIN, StackT &station)

{
  string spurName, trainString, spur2;
  StackT action, station2;
  int count;
  StackT temp;

  if (command == "EXIT") {
    Exit(stationName);
  } else

      if (command == "ARRIVE")

  {
    spurName = GetStation (inputLine); 
    station = SpurAsStackT(spurName, LOCAL, WEST, EAST, YARD, TRAIN);

    cout << "New train arriving on the " << station.name << " spur." << endl;

    if (IsEmpty(station)) {
      trainString = GetTrainString(inputLine);
      count = CountTrains(trainString);
      LoadSpur(trainString, station, count, YARD, TRAIN, LOCAL, WEST, EAST,
               spurName);
    

      cout << endl;

    } else if (!IsEmpty(station)) {

      MoveTrain(station, YARD);
      trainString = GetTrainString(inputLine);
      count = CountTrains(trainString);  
      LoadSpur(trainString, station, count, YARD, TRAIN, LOCAL, WEST, EAST,
               spurName); 
 
    cout << endl; 
    }
  }

  if (command == "SORT") {
   
    spurName = GetStation(inputLine); 
    station = SpurAsStackT(spurName, LOCAL, WEST, EAST, YARD, TRAIN);
    cout << "Sorting the " << station.name << " spur." << endl;
    Sort(station, YARD, LOCAL, WEST, EAST, spurName, stationName);
    cout << endl;
    return;

  } else

      if (command == "DEPART") {
    spurName = GetStation(inputLine); 
    station = SpurAsStackT(spurName, LOCAL, WEST, EAST, YARD, TRAIN);
    cout << "A train departs from the " << station.name << " spur." << endl;
    InitStack(station);
    FixStation(spurName, LOCAL, WEST, EAST, station); 
    cout << endl;
    return;


  } else if (command == "PRINT") {
  
    spurName = GetStation(inputLine); 
    station = SpurAsStackT(spurName, LOCAL, WEST, EAST, YARD, TRAIN);

    Print(station); 
    return;

  } else

      if (command == "MOVE") {
    
    spurName = GetStation(inputLine); 
    station = SpurAsStackT(spurName, LOCAL, WEST, EAST, YARD, TRAIN);
    spur2 = GetSecondSpur(inputLine);
    spur2 = ToUpper(spur2);
    station2 = SpurAsStackT(spur2, LOCAL, WEST, EAST, YARD, TRAIN);

    cout << "Moving from the " << station.name << " spur "
         << "to the " << station2.name << " spur." << endl;

    MoveTrain(station, station2);

    FixStation(spur2, LOCAL, WEST, EAST, station2);
    FixStation(spurName, LOCAL, WEST, EAST, station);

    cout << endl;

  }

  else

    return;
}


void InitializeStacks(StackT &WEST, StackT &EAST, StackT &YARD, StackT &LOCAL,
                      StackT &TRAIN)

{
  InitStack(LOCAL);
  InitStack(WEST);
  InitStack(EAST);
  InitStack(YARD);
  InitStack(TRAIN);

  return;
}

StackT SpurAsStackT(string s, StackT &LOCAL, StackT &WEST, StackT &EAST,
                    StackT &YARD, StackT &TRAIN)

{
  StackT station;

  if (s == "LOCAL") {
    station = LOCAL;
  } else if (s == "WEST") {
    station = WEST;
  } else if (s == "EAST") {
    station = EAST;
  } else if (s == "YARD") {
    station = YARD;
  } else if (s == "TRAIN") {
    station = TRAIN;
  }

  return station;
}

int Exit(string stationName)

{
  cout << "Thank you for using the " << stationName << " Switching Station";
  cout << endl;       
  return 0;
}

string GetCommand(string s)

{
  string command, commandUpper;
  size_t pos;

  pos = s.find(' ');
  command = s.substr(0, pos);
  commandUpper = ToUpper(command);
  return commandUpper;
}

string ToUpper(string s) {
  int i;
  char c;
  string stringUpper;

  for (i = 0; i < int(s.size()); i++)

  {
    c = s[i];
    c = toupper(c);
    stringUpper = stringUpper + c;
  }
  return stringUpper;
}

string FindSpurName(string s)

{
  string spurName;
  size_t pos, pos2;

  pos = s.find(' ');
  pos = pos + 1;
  spurName = s.substr(pos);

  pos2 = spurName.find(' ');

  spurName = s.substr(pos, pos2);

  return spurName;
}

string GetTrainString(string s)

{
  string carString;

  carString = Split(s);
  carString = Split(carString);

  return carString;
}

string Split(string s)

{
  size_t pos;
  string splitString;

  pos = s.find(' ');
  splitString = s.substr(pos + 1);

  return splitString;
}

int CountTrains(string s)

{
  size_t i;
  int count;

  i = 0;
  count = 0;

  for (i = 0; i < s.size(); i++)

  {
    if (s[i] == ',') {
      count++;
    } else {
      count = count;
    }
  }

  return count;
}

void LoadSpur(string trainString, StackT &station, int count, StackT &YARD,
              StackT &TRAIN, StackT &LOCAL, StackT &WEST, StackT &EAST,
              string spurName)

{
  size_t pos;
  string car;
  int i;
  CarT partyWithCarT;
  CarT top;
  StackT newStation;
  CarT item;

  i = 0;

  trainString = ReverseString(trainString);
  
  while (i < count) {

    pos = trainString.find(','); 
    car = trainString.substr(0, pos);
    car = ReverseString(car); 
    partyWithCarT = StringToCarT(car);
    Push(TRAIN, partyWithCarT);
    trainString = trainString.substr(pos + 1);
    i++;
  }

  trainString = ReverseString(trainString);

  item = StringToCarT(trainString);

  Push(TRAIN, item);
 
  MoveTrain (TRAIN, YARD); 

  MoveTrain(YARD, station);

  FixStation(spurName, LOCAL, WEST, EAST, station);

  return;
}


void MoveTrain(StackT &a, StackT &b)

{
  CarT item;

  while (!IsEmpty(a))

  {
    if (a.name == "arriving train")

    {
      item = Pop(a);
      Push(b, item);
      cout << "Remove " << item.name << " from the " << a.name
           << " and place it on the " << b.name << " spur." << endl;
    }

    else

    {
      item = Pop(a);

      PopPrint(item, a, b);

      Push(b, item);

    }
  }

  return;
}


void Print(const StackT a)

{
  int i;
  string value;

  i = a.top;

  value = CarTToString(a.spur[i]);

  cout << "The " << a.name << " spur"
       << " contains:" << endl;

  for (i = a.size; i > 0; i--)

  {
    cout << "	" << CarTToString(a.spur[i]) << endl;
  }
  cout << endl;
  return;
}


string ReverseString(string phrase) {
  string returnValue;
  size_t i;

  for (i = 0; i < phrase.size(); i++) {
    returnValue = phrase[i] + returnValue;
  }
  return returnValue;
}


void Sort(StackT &station, StackT &YARD, StackT &LOCAL, StackT &WEST,
          StackT &EAST, string spurName, string stationName)
		  
{
   CarT item;
  string checkItemName;

  if (!IsEmpty(LOCAL)) {
  MoveTrain(LOCAL, station);

}

  while (!IsEmpty(station)) {


    item = Pop(station);
    Push(LOCAL, item);
    PopPrint(item, station, LOCAL);

    checkItemName = DestinationTToString(LOCAL.spur[LOCAL.top].destination);

 
    if (checkItemName != stationName){
      if (!IsEmpty(YARD)){

     while (!IsEmpty(YARD) and LOCAL.spur[LOCAL.top].destination > YARD.spur[YARD.top].destination) // Clean

         {
        item  = Pop(YARD);
        Push(station, item);
        PopPrint(item, YARD, station);
       
       }
      
     }     

      item = Pop(LOCAL);

      PopPrint(item, LOCAL, YARD);

      Push(YARD, item);
    }

  }
  

  MoveTrain(YARD, station);

  FixStation(spurName, LOCAL, WEST, EAST, station);

  return;
}


string GetSecondSpur(string s)

{
  size_t pos, pos2;
  string returnString;

  pos = s.find(' ');
  returnString = s.substr(pos + 1);
  pos = returnString.find(' ');
  returnString = returnString.substr(pos + 1);
  pos2 = returnString.find(' ');
  returnString = returnString.substr(0, pos2);

  return returnString;
}

void FixStation(string s, StackT &LOCAL, StackT &WEST, StackT &EAST,
                StackT &station) {
  if (s == "LOCAL") {
    LOCAL = station;
  } else if (s == "WEST") {
    WEST = station;
  } else if (s == "EAST") {
    EAST = station;
  }

  return;
}


string GetStation(string inputLine)

{
  string spurName;

  spurName = FindSpurName(inputLine);
  spurName = ToUpper(spurName);

  return spurName;

}

void PopPrint(CarT item, StackT remove, StackT place)

{
  cout << "Remove " << item.name << " from the " << remove.name << " spur"
       << " and place it on the " << place.name << " spur." << endl;

  return;
}