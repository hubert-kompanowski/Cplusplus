//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool OutOfRange(int value);

int FactorialIter(int value) {
  if(OutOfRange(value)){
    return 0;
  }

  int number = 1;
  if(value > 0) {
    for (int i = 1; i <= value; i++) {
      number *= i;
    }
  }
  else{
      value*= -1;
      for (int i = 1; i <= value; i++) {
        number *= i;
        number *= -1;
      }
    }

  return number;
}

int Factorial(int value) {
  if(OutOfRange(value)){
      return 0;
  }

  if(value >= 0) {
      if (value == 0) {
          return 1;
      } else {
          return value * Factorial(value - 1);
      }
  } else {
      if (value == 0) {
          return -1;
      } else {
          return value * Factorial(value + 1);
      }
  }
}

bool OutOfRange(int value) { return value <= -13 || value >= 13; }

