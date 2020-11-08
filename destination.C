#include "destination.h"

#include <iostream>

std::string DestinationTToString(DestinationT a) {
  switch (a) {
    case ALBION:
      return "Albion";
    case BRADFORD:
      return "Bradford";
    case CAMBRIDGESPRINGS:
      return "Cambridge Springs";
    case EDINBORO:
      return "Edinboro";
    case ERIE:
      return "Erie";
    case UNKNOWN:
    default:
      return "UNKNOWN";
  }
}

DestinationT StringToDestinationT(std::string s) {
  size_t i;

  for (i = 0; i < s.size(); i++) {
    s[i] = toupper(s[i]);
  }
  if (s == "ALBION") {
    return ALBION;
  } else if (s == "CAMBRIDGE SPRINGS") {
    return CAMBRIDGESPRINGS;
  } else if (s == "EDINBORO") {
    return EDINBORO;
  } else if (s == "ERIE") {
    return ERIE;
  } else if (s == "BRADFORD") {
    return BRADFORD;
  } else {
    return UNKNOWN;
  }
}

DestinationT NextDestination(DestinationT a) {
  if (a < LAST_DESTINATION) {
    a = DestinationT(int(a) + 1);
  }
  return a;
}

DestinationT PrevDestination(DestinationT a) {
  if (a > FIRST_DESTINATION) {
    a = DestinationT(int(a) - 1);
  }
  return a;
}

DestinationT RandomDestination(void) {
  return DestinationT(drand48() * int(LAST_DESTINATION - FIRST_DESTINATION));
}
