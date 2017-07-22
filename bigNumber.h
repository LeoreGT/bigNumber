#ifndef __BIG_INT_H__
#define __BIG_INT_H__

#include <iostream>
#include "string-class.h"

using namespace std;
class BigInt_t
{
  public:
    BigInt_t();
    BigInt_t(const char* _incomingString);
    BigInt_t(int _incomingNumber);
    BigInt_t(const BigInt_t& _oldNumber);
    ~BigInt_t();

    const String_t& returnCurrentNumber() const {return m_number;}

    BigInt_t& operator+(BigInt_t& _oldNumber) const;
    BigInt_t& operator-(BigInt_t& _oldNumber) const;

    BigInt_t& operator=(BigInt_t& _oldNumber);
    BigInt_t& operator=(int _incomingNumber);

    bool operator==(BigInt_t& _oldNumber) const {return this->m_number == _oldNumber.returnCurrentNumber();}
    bool operator>(BigInt_t& _oldNumber) const;// {return this->m_number > _oldNumber.returnCurrentNumber();}
    bool operator<(BigInt_t& _oldNumber) const;// {return this->m_number < _oldNumber.returnCurrentNumber();}

  private:
    String_t m_number;
};

#endif /* __BIG_INT_H__ */
