#include <iostream>
#include <stdlib.h> /* atoi */

#include "bigNumber.h"
#include "string-class.h"

#define SUCCESS 0
#define FAIL    1
#define MAX_NUMBER_LENGTH 20

BigInt_t::BigInt_t():m_number("0"){}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t::BigInt_t(const char* _incomingString):m_number(_incomingString){}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t::BigInt_t(int _incomingNumber)
{
  char numAsString[MAX_NUMBER_LENGTH];
  sprintf(numAsString, "%d", _incomingNumber);
  m_number.setString(numAsString);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t::BigInt_t(const BigInt_t& _oldNumber)
{
  m_number = _oldNumber.m_number;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t::~BigInt_t(){}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t& BigInt_t::operator+(BigInt_t& _oldNumber) const
{
  const char* myString = this->m_number.getString();
  const char* incString = _oldNumber.m_number.getString();
  if ((myString[0] == '-') || (incString[0] == '-'))
  {
    return _oldNumber;
  }
  BigInt_t* resultingNumber;
  int remainder = 0;
  int sum, i;

  int myLength = this->m_number.getLength();
  int incLength = _oldNumber.m_number.getLength();
  int longerLength = myLength > incLength ? myLength : incLength;
  int shorterLength = myLength < incLength ? myLength : incLength;

  char* outcome = new char[longerLength + 2]; /* plus 2 for null terminator and possible remainder */

  int myPlace = myLength - 1;
  int incPlace = incLength - 1;
  int overallPlace = longerLength ;

  outcome[overallPlace] = '\0';
  --overallPlace;

  for (i = 0; i < shorterLength; ++i)
  {
    sum = atoi(&myString[myPlace]) + atoi(&incString[incPlace]) + remainder;
    remainder = (sum >= 10) ? 1 : 0; //check for a remainder
    outcome[overallPlace] = sum % 10 + '0'; //turn it into a char

    --overallPlace;
    --myPlace;
    --incPlace;
  }

  outcome[0] = remainder + '0';
  resultingNumber = new BigInt_t(outcome);
  delete[] outcome;

  return *resultingNumber;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t& BigInt_t::operator-(BigInt_t& _oldNumber) const
{
  const char* myString = this->m_number.getString();
  const char* incString = _oldNumber.m_number.getString();
  if ((myString[0] == '-') || (incString[0] == '-'))
  {
    return _oldNumber;
  }

  BigInt_t* resultingNumber;
  int remainder = 0;
  int sum, i;

  int myLength = this->m_number.getLength();
  int incLength = _oldNumber.m_number.getLength();
  int longerLength = myLength > incLength ? myLength : incLength;
  int shorterLength = myLength < incLength ? myLength : incLength;

  char* outcome = new char[longerLength + 2]; /* plus 2 for null terminator and possible remainder */

  int myPlace = myLength - 1;
  int incPlace = incLength - 1;
  int overallPlace = longerLength ;

  outcome[overallPlace] = '\0';
  --overallPlace;

  for (i = 0; i < shorterLength; ++i)
  {
    sum = atoi(&myString[myPlace]) - atoi(&incString[incPlace]) + remainder;
    if (sum < 0)
    {
      remainder = -1;
      sum += 10;
    }
    else
    {
      remainder = 0;
    }
    outcome[overallPlace] = sum + '0'; //turn it into a char

    --overallPlace;
    --myPlace;
    --incPlace;
  }

  if (remainder == 0)
  {
   outcome[0] = 0 + '0';
  }
  outcome[0] = 0;

  resultingNumber = new BigInt_t(outcome);
  delete[] outcome;

  return *resultingNumber;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t& BigInt_t::operator=(BigInt_t& _oldNumber)
{
  const char* incomingString = _oldNumber.m_number.getString();
  this->m_number.setString(incomingString);

  return *this;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

BigInt_t& BigInt_t::operator=(int _incomingNumber)
{
  char numAsString[MAX_NUMBER_LENGTH];
  sprintf(numAsString, "%d", _incomingNumber);
  m_number.setString(numAsString);

  return *this;
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool BigInt_t::operator>(BigInt_t& _oldNumber) const
{
  int myLength = this->m_number.getLength();
  int incLength = _oldNumber.returnCurrentNumber().getLength();

  return this->m_number > _oldNumber.returnCurrentNumber();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool BigInt_t::operator<(BigInt_t& _oldNumber) const
{
  int myLength = this->m_number.getLength();
  int incLength = _oldNumber.returnCurrentNumber().getLength();

  return this->m_number < _oldNumber.returnCurrentNumber();
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

