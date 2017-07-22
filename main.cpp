#include <iostream>
#include "bigNumber.h"
#include "string-class.h"

using namespace std;

int Prompt();
void Algorithms_Prompt(BigInt_t& _oldInt);

int main()
{
  Prompt();

  return 0;
}

int Prompt()
{
  char* incString;
  int userDecision, incNumber;
  BigInt_t newInt;

  while (userDecision != 4)
  {
    cout << "Welcome to the BigInt ALU! What would you like to do?: \n" << endl;
    cout << "1. Create a BigInt" << endl;
    cout << "2. Create a BigInt from a string" << endl;
    cout << "3. Create a BigInt from a number" << endl;
    cout << "4. Exit" << endl;
    cin  >> userDecision;

    switch(userDecision)
    {
      case 1:
        Algorithms_Prompt(newInt);
        break;

      case 2:
        {cout << "Input your stringified number: \n" << endl;
        cin  >> incString;
        BigInt_t newInt1(incString);
        Algorithms_Prompt(newInt1);}
        break;

      case 3:
        {cout << "Input your number: \n" << endl;
        cin  >> incNumber;
        BigInt_t newInt2(incNumber);
        Algorithms_Prompt(newInt2);}
        break;

      case 4:
        break;

      default:
        cout << "I didn't understand. Try again!\n" << endl;
        break;
    }
  }

  return 0;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void Algorithms_Prompt(BigInt_t& _oldInt)
{
  char* incString;
  int userDecision, incNumber, retVal;

  do
  {
    cout << "\nGreat! Your BigInt has been created. Now what would you like to do?: " << endl;
    cout << "1. Create a BigInt from your old one." << endl;
    cout << "2. Print out your BigInt's number." << endl;
    cout << "3. Add a number to your BigInt." << endl;
    cout << "4. Subtract a number to your BigInt." << endl;
    cout << "5. Put a new number into your BigInt." << endl;
    cout << "6. Compare a number to your BigInt." << endl;
    cout << "7. Check if a number is greater than your BigInt." << endl;
    cout << "8. Check if a number is lesser than your BigInt." << endl;
    cout << "9. Exit" << endl;
    cin  >> userDecision;
    system ("clear");

    switch(userDecision)
    {
      case 1:
        {
          BigInt_t newInt(_oldInt);
          cout << "Ok, your old BigInt has been copied to a new one.\n" << endl;
          Algorithms_Prompt(newInt);
        }
        break;

      case 2:
        {
          const char* resNum = _oldInt.returnCurrentNumber().getString();
          BigInt_t newInt(incString);
          cout << "Your BigInt number is: " << resNum << endl;
        }
        break;

      case 3:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          BigInt_t result;

          result = _oldInt+compInt;
          const char* resNum = result.returnCurrentNumber().getString();
          cout << "Your new BigInt number is: " << resNum << endl;
        }
        break;

      case 4:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          BigInt_t result;

          result = _oldInt - compInt;
          const char* resNum = result.returnCurrentNumber().getString();
          cout << "Your new BigInt number is: " << resNum << endl;
        }
        break;

      case 5:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          cout << "Done!" << endl;
          Algorithms_Prompt(compInt);
        }
        break;

      case 6:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          retVal = (_oldInt == compInt);
          (retVal == 0) ? cout << "TRUE: Your number is EQUAL than the given number." << endl : cout << "FALSE: Your number is NOT equal to the given number." << endl;
        }
        break;

      case 7:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          retVal = _oldInt > compInt;
          (retVal == 0) ? cout << "TRUE: Your number is GREATER than the given number." << endl : cout << "FALSE: Your number is NOT greater than the given number." << endl;
        }
        break;

      case 8:
        {
          cout << "Input your number: \n" << endl;
          cin  >> incNumber;
          BigInt_t compInt(incNumber);
          retVal = _oldInt<compInt;
          (retVal == 0) ? cout << "TRUE: Your number is LESSER than the given number." : cout << "FALSE: Your number is NOT lesser than the given number.";
        }
        break;

      default:
        {cout << "I didn't understand. Try again!" << endl;}
        break;
    }
  } while (userDecision != 9);

  return;
}

// /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// UNIT(Def_CTOR)
//   BigNumber num;
//   cout << num;
//   ASSERT_THAT(num == 0);
// END_UNIT

// UNIT(CHARS_CTOR)
//   BigNumber num("25");
//   cout << num;
//   ASSERT_THAT(num == 25);
// END_UNIT

// UNIT(INT_CTOR)
//   BigNumber num(25);
//   cout << num;
//   ASSERT_THAT(num == 25);
// END_UNIT

// UNIT(INT_BIGNUM)
//   BigNumber num(25);
//   BigNumber num2(num);
//   cout << num;
//   ASSERT_THAT(num == 25);
// END_UNIT

// UNIT(ADDITION)
//   BigNumber a(5);
//   BigNumber b(6);
//   BigNumber result;
//   result = a + b;
//   cout << result;
//   ASSERT_THAT(result == 11);
// END_UNIT

// UNIT(MORE)
//   BigNumber a(5);
//   BigNumber b(6);
//   ASSERT_THAT(b > a);
// END_UNIT

// UNIT(LESS)
//   BigNumber a(5);
//   BigNumber b(6);
//   ASSERT_THAT(a < b);
// END_UNIT

// TEST_SUITE(BigNumber test)
//   TEST(Def_CTOR)
//   TEST(CHARS_CTOR)
//   TEST(INT_CTOR)
//   TEST(INT_BIGNUM)
//   TEST(ADDITION)
//   TEST(MORE)
//   TEST(LESS)
// END_SUITE
