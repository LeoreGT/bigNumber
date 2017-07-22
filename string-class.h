#ifndef __STRING_CLASS_H__
#define __STRING_CLASS_H__

#include <stdlib.h>
#include <string.h>

#define TRUE 0
#define FALSE 1

/*
 * Leore Golan
 * C++ implementation of string class functions
*/

class String_t
{
	public:
    static size_t m_numOfStrings;
    static bool   m_caseSensitive;

		String_t();
    ~String_t();
    String_t(const char* _string);
    String_t(const String_t& _string);
    const String_t& operator=(const String_t& _str);

    bool     operator<(const String_t& _str) const;
    bool     operator>(const String_t& _str) const;
    bool     operator<=(const String_t& _str) const;
    bool     operator>=(const String_t& _str) const;
    bool     operator==(const String_t& _str) const;
    bool     operator!=(const String_t& _str) const;



    size_t      getLength() const; /* const outside because it recieves but doesn't alter the struct data */
		void        setString(const char* _string);
		const char* getString() const; /* const outside because it recieves but doesn't alter the struct data */
		int         compareStrings(const String_t& _string) const; /* checking against a reference to another string */
		void        printString() const;

    void        makeUpperCase();
    void        makeLowerCase();

    void        prependToString(const char* _string);
    void        prependToString(const String_t& _string);

    void        appendToString(const char* _string);
    void        appendToString(const String_t& _string);

    int         searchForString(const char* _string);
    char&       returnFromString(int _index);

    bool        isCaseSensitive() const;
    bool        switchCaseSensitivity(); /* returns old status */


	private:
		char* m_string;
    int   m_stringSize;
		char* createFrom(const char* _string);
    void  reallocateString(int _incomingSize); /* acts as a reallocator if it's needed */
};

//ostream& operator<<(ostream& _os, String_t& _str);
//istream& operator>>(ostream& _is, String_t& _str);

#endif /* __STRING_CLASS_H__ */
