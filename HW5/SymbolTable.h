#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include <string>
#include "SymbolTableEntry.h"
#include <iostream>
using namespace std;

class SYMBOL_TABLE 
{
private:
  std::map<string, SYMBOL_TABLE_ENTRY> hashTable;


public:
  //Constructor
  SYMBOL_TABLE( ) { }

  int getSize() { return hashTable.size(); }

  // Add SYMBOL_TABLE_ENTRY x to this symbol table.
  // If successful, return true; otherwise, return false.
  bool addEntry(SYMBOL_TABLE_ENTRY x) 
  {
    // Make sure there isn't already an entry with the same name
    // cout << "___Adding " << x.getName() << " to symbol table\n";
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(x.getName())) == hashTable.end()) 
    {
      hashTable.insert(make_pair(x.getName(), x));
      
      return(true);
    }
    else return(false);
  }

  // If a SYMBOL_TABLE_ENTRY with name theName is
  // found in this symbol table, then return true;
  // otherwise, return false.
  bool findEntry(string theName) 
  {
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
      return(false);
    else return(true);
  }
  int findType(string theName)
  {
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
      return(NOT_FOUND);
    else 
    {
      int typeCode = hashTable.at(theName).getTypeCode();
      return(typeCode);
    }
  }
  int findReturnType(string theName)
  {
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
      return(NOT_FOUND);
    else 
    {
      int returnType = hashTable.at(theName).getReturnType();
      return(returnType);
    }
  }
  int findNumParams(string theName)
  {
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
      return(NOT_FOUND);
    else 
    {
      int numParams = hashTable.at(theName).getNumParams();
      return(numParams);
    }
  }
  int findIntegerVal(string theName)
  {
     map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
      return(NOT_FOUND);
    else 
    {
      int integerVal = hashTable.at(theName).getIntegerValue();
      return(integerVal);
    }
  }
  int findBooleanVal(string theName)
  {
     map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
      return(NOT_FOUND);
    else 
    {
      int booleanVal = hashTable.at(theName).getBooleanValue();
      return(booleanVal);
    }
  }
  char* findStringVal(string theName)
  {
     map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    itr = hashTable.find(theName);
    if (itr == hashTable.end())
    {
      return(UNDEF_STR);
    }
    else 
    {
      char* stringVal = hashTable.at(theName).getStringValue();
      return(stringVal);
    }
  }
};

#endif  // SYMBOL_TABLE_H
