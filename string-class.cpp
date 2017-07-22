#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "string-class.h"

#define STARTER_SIZE 0

#define STRINGS_ARE_EQUAL 0
#define I_AM_LESSER 1
#define I_AM_GREATER 2

#define BAD_INPUT -1
#define TRUE 0
#define FALSE 1

using namespace std;

size_t String_t::m_numOfStrings = 0;
bool   String_t::m_caseSensitive = FALSE;
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t()
{
	m_string = new char[STARTER_SIZE]; /* CTOR + memory allocation */
  m_string[0] = 0;  /* this initialized it as 0 which can be freed */
  m_stringSize = STARTER_SIZE; /* make it equal to the starter size, to be changed later */
  ++m_numOfStrings;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::~String_t()
{
	delete[] m_string; /* DTOR and releases inner data */
  m_stringSize = 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t(const char* _string)
{
  this->m_string = createFrom(_string);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

String_t::String_t(const String_t& _string)
{
  this->m_string = createFrom(_string.m_string);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


char* String_t::createFrom(const char* _string)
{
  if (NULL == _string)
  {
    return NULL;
  }

  char* temp = new char[(strlen(_string) + 1)];
  strcpy(temp, _string);
  this->m_stringSize = (strlen(_string));
  return temp;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

size_t String_t::getLength() const
{
	return this->m_stringSize;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::reallocateString(int incomingSize)
{
  if((incomingSize > m_stringSize) && (incomingSize > 0))
  {
    delete[] m_string;
    m_string = new char[incomingSize + 1];
    m_stringSize = incomingSize;
  }
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::setString(const char* _newString)
{
  if (NULL == _newString)
  {
    return;
  }

  reallocateString(strlen(_newString));
  strcpy(this->m_string, _newString);
  //m_string[m_stringSize + 1] = 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const char* String_t::getString() const
{
	return this->m_string;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int String_t::compareStrings(const String_t& _string) const
{
	int comparison;
  if (NULL == _string.m_string)
  {
    return BAD_INPUT;
  }

  comparison = strcmp(this->m_string, _string.getString());
  if (comparison == 0)
  {
    return STRINGS_ARE_EQUAL;
  }
  return (comparison > 0) ? I_AM_GREATER : I_AM_LESSER;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::printString() const
{
	cout << this->m_string << "\n";
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::makeUpperCase()
{
  for(int i = 0; i <= strlen(this->m_string); i++)
  {
    this->m_string[i] = toupper(this->m_string[i]);
  }
  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::makeLowerCase()
{
  for(int i = 0; i <= strlen(this->m_string); i++)
  {
    this->m_string[i] = tolower(this->m_string[i]);
  }
  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::prependToString(const char* _string)
{
  int fullLength, i;
  int n = 0;
  char* oldString = this->m_string;

  if (NULL == _string)
  {
    return;
  }

  fullLength = (this->getLength() + strlen(_string));
  reallocateString(fullLength);

  for (i = 0; i <= strlen(_string); i++)
  {
    this->m_string[i] = _string[i];
  }

  for (i = strlen(_string) + 1; i <= fullLength; i++)
  {
    this->m_string[i] = oldString[n];
    n++;
  }

  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::prependToString(const String_t& _string) /* pull out the string and refer to previous function */
{
  prependToString(_string.m_string);
  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::appendToString(const char* _string)
{
  int fullLength, i;
  int n = 0;
  char* oldString = this->m_string;

  if (NULL == _string)
  {
    return;
  }

  fullLength = (this->getLength() + strlen(_string));
  reallocateString(fullLength);

  for (i = 0; i <= strlen(oldString); i++)
  {
    this->m_string[i] = oldString[i];
  }

  for (i = strlen(_string) + 1; i <= fullLength; i++)
  {
    this->m_string[i] = oldString[n];
    n++;
  }

  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void String_t::appendToString(const String_t& _string)
{
  appendToString(_string.m_string);
  return;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

int String_t::searchForString(const char* _string)
{
  if (!_string)
  {
    return FALSE;
  }

  return (NULL != strstr(m_string, _string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

char& String_t::returnFromString(int _index)
{
  char& outgoingChar;
  if (_index > this->m_stringSize)
  {
    return '\0';
  }
  outgoingChar = &this->m_string[_index];

  return outgoingChar;
}*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

const String_t& String_t::operator=(const String_t& incomingString)
{
  if(&incomingString != this)
  {
    reallocateString(incomingString.getLength());
    setString(incomingString.m_string);
  }

  return *this;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator<(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (-1 >= strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator>(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (1 <= strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator<=(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (0 >= strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator>=(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (0 <= strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator==(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (0 == strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::operator!=(const String_t& _str) const
{
  String_t originalString = *this;
  String_t newString = _str;
  if (TRUE == m_caseSensitive)
  {
    originalString.makeLowerCase();
    newString.makeLowerCase();
  }
  return (0 != strcmp(originalString.m_string, newString.m_string)) ? TRUE : FALSE;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ostream& operator<<(ostream& _os, String_t& _str)
{
  _os << _str.getString();

  return _os;
}*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

istream& operator>>(istream& _is, String_t& _str)
{
  char buff[128];

  _is >> buff;

  _str.setString(buff);

  return _is;
}*/

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::isCaseSensitive() const
{
  return String_t::m_caseSensitive;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

bool String_t::switchCaseSensitivity()
{
  bool oldStatus = String_t::m_caseSensitive;

  (FALSE == String_t::m_caseSensitive) ? String_t::m_caseSensitive = TRUE : String_t::m_caseSensitive = FALSE;

  return oldStatus;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
