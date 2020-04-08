#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define UNDEFINED 99
#define FUNCTION 0
#define INT 1
#define STR 2
#define INT_OR_STR 3
#define BOOL 4
#define INT_OR_BOOL 5
#define STR_OR_BOOL 6
#define INT_OR_STR_OR_BOOL 7
#define REL_OP_CODE 8
#define LOG_OP_CODE 9
#define ARITH_OP_CODE 10
#define PROGN_CODE 11
#define MULT 12
#define DIV 13
#define SUB 14
#define ADD 15
#define AND 16
#define OR 17
#define LT 18
#define GT 19
#define LE 20
#define GE 21
#define EQ 22
#define NE 23
#define NOT_APPLICABLE -1
#define NOT_FOUND -999
#define NIL 67543
char UNDEF_STR[] = " ";


typedef struct
{
	int type;
	int numParams; // not_applicable if not function
	int returnType; // ^
  int integerValue;
  int booleanValue;
  char* stringValue;
} TYPE_INFO;

class SYMBOL_TABLE_ENTRY 
{
private:
  // Member variables
  string name;
  int typeCode; 
  int returnType;
  int numParams; 
  int integerValue;
  int booleanValue;
  char* stringValue;
public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) { name = ""; typeCode = UNDEFINED; returnType = UNDEFINED; numParams = UNDEFINED; integerValue = UNDEFINED; booleanValue = UNDEFINED; stringValue = UNDEF_STR; }

  SYMBOL_TABLE_ENTRY(const string theName, const int theType, const int theReturnType, const int theNumParams, const int theIntegerValue, const int theBooleanValue, char* theStringValue) 
  {
    name = theName;
    typeCode = theType;
    returnType = theReturnType;
    numParams = theNumParams;
    integerValue = theIntegerValue;
    booleanValue = theBooleanValue;
    stringValue = theStringValue;

  }

  // Accessors
  string getName() const { return name; }
  int getTypeCode() const { return typeCode; }
  int getReturnType() const { return returnType; }
  int getNumParams() const { return numParams;}
  int getIntegerValue() const {return integerValue;}
  int getBooleanValue() const {return booleanValue;}
  char* getStringValue() const {return stringValue;}
};

#endif  // SYMBOL_TABLE_ENTRY_H
