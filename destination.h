#ifndef DESTINATION
#define DESTINATION


#include <string>

enum DestinationT {ALBION, BRADFORD, CAMBRIDGESPRINGS, EDINBORO,
                                ERIE, UNKNOWN};  
                          

const DestinationT FIRST_DESTINATION  = ALBION;
const DestinationT LAST_DESTINATION  = UNKNOWN;


std::string DestinationTToString(DestinationT a);

DestinationT StringToDestinationT(std::string s);

DestinationT NextDestination(DestinationT a);

DestinationT PrevDestination(DestinationT a);

DestinationT RandomDestination (void);

#endif

