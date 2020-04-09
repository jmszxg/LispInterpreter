/*
	parser.y

 	Example of a bison specification file.

	Grammar is:
	  <start> -> epsilon | <start> <expr>
	  <expr> -> quit | <calc> 
	  <calc> -> <operand> <op> <operand>
	  <op> -> add | sub | mult | div
	  <operand> -> intconst | ident 

      To create the syntax analyzer:
        flex parser.l
        bison parser.y
        g++ parser.tab.c -o parser
        parser < inputFileName
 */

%{


#include <stdio.h>
#include "SymbolTable.h"
#include "SymbolTableEntry.h"
#include <stack>





stack<SYMBOL_TABLE> scopeStack;

int numLines = 1; 

int numberCurrentParams = 0;
int numExprParams = 0;

void printRule(const char *, const char *);
void yyerror(const char *s); // void since we don't return, just exit.
void printToken(const char* tokenType, const char* lexeme);
void printStringEnding(const char *s, const int end);
void printIntegerEnding(const int i, const int end);
void printBooleanEnding(const int b, const int end);
void enterScope();
void leaveScope();
bool findEntryInAnyScope(const string name);
int findTypeOfEntry(const string name);
int findIntegerValue(const string name);
int findBooleanValue(const string name);
char* findStringValue(const string name);
int findReturnTypeOfEntry(const string name);
int findNumParamsOfEntry(const string name);

extern "C" 
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}

%}
%union
{
	char* text;
	int intVal;
	TYPE_INFO typeInfo;
};


/* Token declarations */
%token T_LETSTAR   T_LAMBDA    T_INPUT     T_PRINT     T_IF        T_EXIT      T_PROGN
%token T_LPAREN    T_RPAREN    T_ADD       T_MULT      T_DIV       T_SUB       T_AND       
%token T_OR        T_NOT       T_LT        T_GT        T_LE        T_GE        T_EQ        
%token T_NE        T_T         T_NIL       T_IDENT     T_INTCONST  T_STRCONST  T_UNKNOWN  

%type <text> T_IDENT T_STRCONST 
%type <intVal> T_INTCONST
%type <typeInfo> N_CONST N_EXPR N_PARENTHESIZED_EXPR N_IF_EXPR N_ARITHLOGIC_EXPR
%type <typeInfo> N_LET_EXPR N_PRINT_EXPR N_INPUT_EXPR N_PROGN_OR_USERFUNCTCALL
%type <typeInfo> N_UN_OP N_REL_OP N_LOG_OP N_ARITH_OP N_BIN_OP N_EXPR_LIST
%type <typeInfo> N_FUNCT_NAME N_ACTUAL_PARAMS

/* Starting point */
%start		N_START

/* Translation rules */
%%
N_START		: // epsilon
			{
				// printRule("START", "epsilon");
			}
			| N_START N_EXPR
			{	
				// printRule("START", "START EXPR");
				printf("\n---- Completed parsing ----\n\n");
				if ($2.integerValue != UNDEFINED)
					printIntegerEnding($2.integerValue, 1);
				else if ($2.booleanValue != UNDEFINED)
					printBooleanEnding($2.booleanValue, 1);
				else if ($2.stringValue != UNDEF_STR)
					printStringEnding($2.stringValue, 1);
				
			}
			;
N_EXPR		: N_CONST
			{
				// printRule("EXPR", "CONST");
				$$.type = $1.type;
				$$.numParams = NOT_APPLICABLE;
				$$.returnType = NOT_APPLICABLE;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
			}
			| T_IDENT
			{
				// printRule("EXPR", "IDENT");
				if(!findEntryInAnyScope(string($1)))
					yyerror("Undefined identifier");
				else
				{
					
					$$.type = findTypeOfEntry(string($1));
					$$.integerValue = findIntegerValue(string($1));
					$$.booleanValue = findBooleanValue(string($1));
					$$.stringValue = findStringValue(string($1));
					$$.numParams = UNDEFINED;
					$$.returnType = UNDEFINED;
				}
				
			}
			| T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
			{
				// printRule("EXPR","( PARENTHESIZED_EXPR )");
				$$.type = $2.type;
				$$.numParams = $2.numParams;
				$$.returnType = $2.returnType;
				$$.integerValue = $2.integerValue;
				$$.booleanValue = $2.booleanValue;
				$$.stringValue = $2.stringValue;
			}
			;
N_CONST		: T_INTCONST
			{
				$$.type = INT;
				$$.numParams = UNDEFINED;
				$$.returnType = UNDEFINED;
				$$.stringValue = UNDEF_STR;
				$$.booleanValue = UNDEFINED;
				$$.integerValue = $1;
				// printRule("CONST", "INTCONST");
			}
			| T_STRCONST
			{
				$$.type = STR;
				$$.numParams = UNDEFINED;
				$$.returnType = UNDEFINED;
				$$.stringValue = $1;
				$$.booleanValue = UNDEFINED;
				$$.integerValue = UNDEFINED;
				// printRule("CONST", "STRCONST");
			}
			| T_T
			{
				$$.type = BOOL;
				$$.numParams = UNDEFINED;
				$$.returnType = UNDEFINED;
				$$.integerValue = UNDEFINED;
				$$.booleanValue = 1;
				$$.stringValue = UNDEF_STR;
				// printRule("CONST", "T");
			}
			| T_NIL
			{
				$$.type = BOOL;
				$$.numParams = UNDEFINED;
				$$.returnType = UNDEFINED;
				$$.booleanValue = NIL;
				$$.integerValue = UNDEFINED;
				$$.stringValue = UNDEF_STR;
				// printRule("CONST","NIL");
			}
			;

N_PARENTHESIZED_EXPR : N_ARITHLOGIC_EXPR
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
			
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
			}
			| N_IF_EXPR
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "IF_EXPR");
			}
			| N_LET_EXPR
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "LET_EXPR");
			}
			| N_PRINT_EXPR
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
			}
			| N_INPUT_EXPR
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
			}
			| N_PROGN_OR_USERFUNCTCALL
			{
				$$.type = $1.type;
				$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				// printRule("PARENTHESIZED_EXPR", "PROGN_OR_USERFUNCTCALL");
			}
			| T_EXIT
			{
				// printRule("PARENTHESIZED_EXPR", "EXIT");
				printf("\nBye!");
				exit(1);
				
			}
			;
N_PROGN_OR_USERFUNCTCALL : N_FUNCT_NAME N_ACTUAL_PARAMS
			{
				if ($1.type == PROGN_CODE)
				{
					if($2.type == UNDEFINED)
						$$.type = BOOL;
					else
						$$.type = $2.type;
				}
				else 
				{
					$$.type = $1.returnType;
					if($2.numParams > $1.numParams)
						yyerror("Too many parameters in function call");
					else if($2.numParams < $1.numParams)
					{
						yyerror("Too few parameters in function call");
					}
					// check that ident params is the same as actual params
				}
				$$.numParams = UNDEFINED;
				$$.returnType = UNDEFINED;
				if($2.type != UNDEFINED)
				{
					$$.integerValue = $2.integerValue;
					$$.booleanValue = $2.booleanValue;
					$$.stringValue = $2.stringValue;
				}
				else 
				{
					$$.integerValue = UNDEFINED;
					$$.stringValue = UNDEF_STR;
					$$.booleanValue = NIL;
				}
				// printRule("PROGN_OR_USERFUNCTCALL", "FUNCT_NAME EXPR_LIST");
			}
			;
N_ACTUAL_PARAMS : N_EXPR_LIST
			{
				$$.type = $1.type;
				$$.returnType = UNDEFINED;
				$$.numParams = numExprParams;
				numExprParams = 0;
				
			}
			| // epsilon
			{
				$$.type = UNDEFINED;
				$$.returnType = UNDEFINED;
				$$.numParams = numExprParams;
			}
			;
N_FUNCT_NAME : T_PROGN
			{
				$$.type = PROGN_CODE;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				// printRule("FUNCT_NAME", "PROGN");
			}
			;
N_ARITHLOGIC_EXPR :  N_UN_OP N_EXPR
			{
				if($2.type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				$$.type = BOOL;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				$$.integerValue = UNDEFINED;
				$$.stringValue = UNDEF_STR;
				if($2.booleanValue != NIL)
					$$.booleanValue = NIL;
				else
					$$.booleanValue = 1;
				// printRule("ARITHLOGIC_EXPR","UN_OP EXPR");
			}
			| N_BIN_OP N_EXPR N_EXPR
			{
				
				if($1.type == MULT || $1.type == SUB || $1.type == DIV || $1.type == ADD)
				{
					// anything that has an int in it has a 1 in the far right place in binary
					// so, we take the two values and & them together to check the bits they share,
					// and then and them with INT to only set the far right bit if set, and then check 
					// if that far right int is set. 
					if((($2.type & $3.type) & INT) == INT)
					{
						$$.type = INT;
						$$.numParams = UNDEFINED;
						$$.returnType = UNDEFINED;

						int val1 = $2.integerValue;
						int val2 = $3.integerValue;
						int endResult;
						//printf("%u   ", $1.type);
						switch ($1.type)
						{
							case MULT:
								endResult = val1 * val2;
								break;
							case DIV:
								if (val2 == 0)
									yyerror("Attempted division by zero");
								else
									endResult = val1 / val2; 
								break;
							case ADD:
								endResult = val1 + val2;
								break;
							case SUB:
								endResult = val1 - val2;
								break;
						}
						$$.integerValue = endResult;

					}
					// else if these don't work then we need to determine who is the issue, 
					// starting with the first N_EXPR.
					else if(($2.type & INT) != INT)
						yyerror("Arg 1 must be integer");
					else if(($3.type & INT) != INT)
						yyerror("Arg 2 must be integer");
				}
				else if($1.type == LT || $1.type == GT || $1.type == LE || $1.type == GE || $1.type == EQ || $1.type == NE)
				{
					// same bitwise logic as above
					if($2.type == FUNCTION)
						yyerror("Arg 1 must be integer or string");
					else if($3.type == FUNCTION)
						yyerror("Arg 2 must be integer or string");
					if((($2.type & $3.type) & INT) == INT)  
					{
						$$.type = BOOL;
						$$.numParams = UNDEFINED;
						$$.returnType = UNDEFINED;
						int val1 = $2.integerValue;
						int val2 = $3.integerValue;
						int endResult = NIL;
						
						switch($1.type)
						{
							case LT:
								if (val1 < val2)
									endResult = 1;
								break;
							case GT:
								if (val1 > val2)
									endResult = 1;
								break;
							case LE:
								if (val1 <= val2)
									endResult = 1;
								break;
							case GE:
								if (val1 >= val2)
									endResult = 1;
								break;
							case EQ:
								if (val1 == val2)
									endResult = 1;
								break;
							case NE:
								if (val1 != val2)
									endResult = 1;
								break;
						}
						$$.booleanValue = endResult;
						$$.stringValue = UNDEF_STR;
						$$.integerValue = UNDEFINED;
					}
					else if ((($2.type & $3.type) & STR) == STR)
					{
						$$.type = BOOL;
						$$.numParams = UNDEFINED;
						$$.returnType = UNDEFINED;
						string val1 = static_cast<string>($2.stringValue);
						string val2 = static_cast<string>($3.stringValue);
						int endResult = NIL;
						
						switch($1.type)
						{
							case LT:
								if (val1 < val2)
									endResult = 1;
								break;
							case GT:
								if (val1 > val2)
									endResult = 1;
								break;
							case LE:
								if (val1 <= val2)
									endResult = 1;
								break;
							case GE:
								if (val1 >= val2)
									endResult = 1;
								break;
							case EQ:
								if (val1 == val2)
									endResult = 1;
								break;
							case NE:
								if (val1 != val2)
									endResult = 1;
								break;
						}
						$$.booleanValue = endResult;
						$$.stringValue = UNDEF_STR;
						$$.integerValue = UNDEFINED;
					}
					
					else if(($2.type | INT_OR_STR) != INT_OR_STR)
						yyerror("Arg 1 must be integer or string");
					else if(($3.type | INT_OR_STR) != INT_OR_STR)
						yyerror("Arg 2 must be integer or string");
				}
				else if($1.type == AND || $1.type == OR)
				{
					if($2.type == FUNCTION)
						yyerror("Arg 1 cannot be a function");
					else if($3.type == FUNCTION)
						yyerror("Arg 2 cannot be a function");
					// same bitwise logic as above
					else if(($2.type | $3.type) != FUNCTION)
					{
						$$.type = BOOL;
						$$.numParams = UNDEFINED;
						$$.returnType = UNDEFINED;
						int endResult = NIL, val1 = $2.booleanValue, val2 = $3.booleanValue;
						switch($1.type)
						{
							case AND:
								if(val1 != NIL && val2 != NIL)
									endResult = 1;
								break;
							case OR:
								if(val1 != NIL || val2 != NIL)
									endResult = 1;
								break;
						}
						$$.booleanValue = endResult;
						$$.integerValue = UNDEFINED;
						$$.stringValue = UNDEF_STR;
					}
				}
				// printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
			}
			;
N_IF_EXPR :    T_IF N_EXPR N_EXPR N_EXPR
			{
				
				//int theType;
				
				if($2.type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				else if($3.type == FUNCTION)
					yyerror("Arg 2 cannot be a function");
				else if($4.type == FUNCTION)
					yyerror("Arg 3 cannot be a function");
				/*
				else
				{
					if(($3.type | $4.type) == INT)
						theType = INT;
					else if(($3.type | $4.type) == STR)
						theType = STR;
					else if(($3.type | $4.type) == BOOL)
						theType = BOOL;
					// if we or the two types together and then and it with what we are checking, 
					// it should work
					else if((($3.type | $4.type) & INT_OR_STR) == INT_OR_STR)
						theType = INT_OR_STR;
					else if((($3.type | $4.type) & INT_OR_BOOL) == INT_OR_BOOL)
						theType = INT_OR_BOOL;
					else if((($3.type | $4.type) & STR_OR_BOOL) == STR_OR_BOOL)
						theType = STR_OR_BOOL;
					else if((($3.type | $4.type) & INT_OR_STR_OR_BOOL) == INT_OR_STR_OR_BOOL)
						theType = INT_OR_STR_OR_BOOL;
				}

					// can we get rid of all of the above now that we know the value of 
					// the if statement, and thus know for sure the type?

				*/
				// the below should be able to set everything correctly.
				if($2.booleanValue == NIL)
				{
					$$.integerValue = $4.integerValue;
					$$.booleanValue = $4.booleanValue;
					$$.stringValue = $4.stringValue;
					$$.type = $4.type;
					$$.numParams = $4.numParams;
					$$.returnType = $4.returnType;
				}
				else 
				{
					$$.integerValue = $3.integerValue;
					$$.booleanValue = $3.booleanValue;
					$$.stringValue = $3.stringValue;
					$$.type = $3.type;
					$$.numParams = $3.numParams;
					$$.returnType = $3.returnType;
				}	
				// printRule("IF_EXPR"," IF EXPR EXPR EXPR");
			}
			;
N_LET_EXPR :   T_LETSTAR T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
			{
				leaveScope();
				if($5.type == FUNCTION)
					yyerror("Arg 2 cannot be a function");
				$$.type = $5.type;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				$$.integerValue = $5.integerValue;
				$$.booleanValue = $5.booleanValue;
				$$.stringValue = $5.stringValue;
				// printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
				
			}
			;
// Adding a list of identifiers to the current scope
N_ID_EXPR_LIST : // epsilon
			{ 
				// printRule("ID_EXPR_LIST", "epsilon");
			}
			
			|   N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN 
			{
				// printRule("ID_EXPR_LIST","ID_EXPR_LIST ( IDENT EXPR )");
				bool found = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(string($3), $4.type, $4.returnType, $4.numParams, $4.integerValue, $4.booleanValue, $4.stringValue));
				if(!found)
					yyerror("Multiply defined identifer");
			}
			;
N_PRINT_EXPR : T_PRINT N_EXPR
			{
				// printRule("PRINT_EXPR", "print EXPR");
				if($2.type == FUNCTION)
					yyerror("Arg 1 cannot be a function");
				$$.type = $2.type;
				$$.returnType = $2.returnType;
				$$.numParams = $2.numParams;
				$$.integerValue = $2.integerValue;
				$$.booleanValue = $2.booleanValue;
				$$.stringValue = $2.stringValue;
				if($$.integerValue != UNDEFINED)
				{
					printIntegerEnding($$.integerValue, 0);
					printf("\n");
				}
				else if($$.booleanValue != UNDEFINED)
				{
					printBooleanEnding($$.booleanValue, 0);
					printf("\n");
				}
				
				else if ($$.stringValue != UNDEF_STR)
				{
					printStringEnding($$.stringValue, 0);
					printf("\n");
				}
			}
			;
N_INPUT_EXPR :  T_INPUT
			{
				string readIn;
				getline(cin, readIn);
				
				if(readIn[0] == '+' || readIn[0] == '-' || isdigit(readIn[0]))
				{
					$$.type = INT;
					$$.integerValue = atoi(readIn.c_str());
				}
				else
				{
					$$.type = STR;
					// ugly code but it wouldn't let me assign it any other fway
					char* temp = (char*)readIn.c_str();
					// strcpy(temp, readIn.c_str());
					$$.stringValue = temp;
				}
				// printRule("INPUT_EXPR", "INPUT");
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
			}
			;
N_EXPR_LIST :   N_EXPR N_EXPR_LIST
			{
				// printRule("EXPR_LIST", "EXPR EXPR_LIST");
				$$.type = $2.type;
				$$.integerValue = $2.integerValue;
				$$.booleanValue = $2.booleanValue;
				$$.stringValue = $2.stringValue;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				numExprParams++;
			}
			| N_EXPR
			{
				$$.type = $1.type;
				$$.integerValue = $1.integerValue;
				$$.booleanValue = $1.booleanValue;
				$$.stringValue = $1.stringValue;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				numExprParams++;
				// printRule("EXPR_LIST", "EXPR");
			}
			;
N_BIN_OP    : N_ARITH_OP  
			{
				$$.type = $1.type;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				// printRule("BIN_OP", "ARITH_OP");
			}
			| N_LOG_OP
			{
				$$.type = $1.type;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				// printRule("BIN_OP", "LOG_OP");
			}
			| N_REL_OP
			{
				$$.type = $1.type;
				$$.returnType = UNDEFINED;
				$$.numParams = UNDEFINED;
				// printRule("BIN_OP", "REL_OP");
			}
			;
N_ARITH_OP : T_MULT
			{
				$$.type = MULT;
				// printRule("ARITH_OP", "*");
			}
			| T_SUB
			{
				$$.type = SUB;
				// printRule("ARITH_OP", "-");
			}
			| T_DIV
			{
				$$.type = DIV;
				// printRule("ARITH_OP", "/");
			}
			| T_ADD
			{
				$$.type = ADD;
				// printRule("ARITH_OP", "+");
			}
			;
N_LOG_OP : T_AND
			{
				$$.type = AND;
				// printRule("LOG_OP", "and");
			}
			| T_OR
			{
				$$.type = OR;
				// printRule("LOG_OP", "or");
			}
			;
N_REL_OP :  T_LT
			{
				$$.type = LT;
				// printRule("REL_OP", "<");
			}
			| T_GT
			{
				$$.type = GT;
				// printRule("REL_OP", ">");
			}
			| T_LE
			{
				$$.type = LE;
				// printRule("REL_OP", "<=");
			}
			| T_GE
			{
				$$.type = GE;
				// printRule("REL_OP", ">=");
			}
			| T_EQ
			{
				$$.type = EQ;
				// printRule("REL_OP", "=");
			}
			| T_NE
			{
				$$.type = NE;
				// printRule("REL_OP", "!=");
			}
			;
N_UN_OP : T_NOT
			{
				// printRule("UN_OP", "not");
			}





%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) 
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

void yyerror(const char *s) 
{

  printf("Line %d: %s\n", numLines, s);
  printf("\nBye!");
  exit(1);
}

void printToken(const char* token, const char* lexeme) 
{
  printf("TOKEN: %s  LEXEME: %s\n", token, lexeme);
}
void printStringEnding(const char* s, const int end)
{
	if(end)
  		printf("\nValue of the expression is: %s\n", s);
	else
		printf("%s",s);
}
void printIntegerEnding(const int i, const int end)
{
	if(end)
		printf("\nValue of the expression is: %d\n", i);
	else
		printf("%d",i);
}
void printBooleanEnding(const int b, const int end)
{
	if (!end)
	{ 
		if (b != NIL)
		printf("t");
	else if(b == NIL)
		printf("nil");
	}
	else
	{
		if (b == 1)
			printf("\nValue of the expression is: %s\n", "t");
		else if(b == NIL)
			printf("\nValue of the expression is: %s\n", "nil");
	}	
}
void enterScope()
{
	scopeStack.push(SYMBOL_TABLE());
	// printf("\n___Entering new scope...\n\n");
}
void leaveScope()
{
	scopeStack.pop();
	// printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(const string name)
{
	if(scopeStack.empty()) return(false);

	/*
		scopeStack.top() -> the most recent scope
		top().findEntry(name) -> findEntry inside of specific scope
	*/
	bool found = scopeStack.top().findEntry(name);
	if(found) 
		return(true);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top(); 
		scopeStack.pop();
		found = findEntryInAnyScope(name);
		scopeStack.push(tmp);
		return(found);
	}

}
// a modified version of findEntryinAnyScope that returns the typecode
int findTypeOfEntry(const string name)
{
	if(!findEntryInAnyScope(name))
		return NOT_FOUND;
	int type = NOT_FOUND;
	bool found = scopeStack.top().findEntry(name);
	if(found)
	{
		return(scopeStack.top().findType(name));
	}
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		type = findTypeOfEntry(name);
		scopeStack.push(tmp);
		return(type);
	}
}
int findReturnTypeOfEntry(const string name)
{
	{
		if(!findEntryInAnyScope(name))
			return NOT_FOUND;
		int type = NOT_FOUND;
		bool found = scopeStack.top().findEntry(name);
		if(found)
		{
			return(scopeStack.top().findReturnType(name));
		}
		else
		{
			SYMBOL_TABLE tmp = scopeStack.top();
			scopeStack.pop();
			type = findReturnTypeOfEntry(name);
			scopeStack.push(tmp);
			return(type);
		}
	}
}
int findIntegerValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findIntegerVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		int val = findIntegerValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
int findBooleanValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findBooleanVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		int val = findBooleanValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
char* findStringValue(const string name)
{
	bool found = scopeStack.top().findEntry(name);
	if(found)
		return scopeStack.top().findStringVal(name);
	else
	{
		SYMBOL_TABLE tmp = scopeStack.top();
		scopeStack.pop();
		char* val = findStringValue(name);
		scopeStack.push(tmp);
		return(val);
	}
}
int findNumParamsOfEntry(const string name)
{
	{
		if(!findEntryInAnyScope(name))
			return NOT_FOUND;
		int type = NOT_FOUND;
		bool found = scopeStack.top().findEntry(name);
		if(found)
		{
			return(scopeStack.top().findNumParams(name));
		}
		else
		{
			SYMBOL_TABLE tmp = scopeStack.top();
			scopeStack.pop();
			type = findNumParamsOfEntry(name);
			scopeStack.push(tmp);
			return(type);
		}
	}
}
int main(int argc, char** argv) 
{
	if(argc < 1)
	{
		printf("You must specify a file in the command line!\n");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	do 
	{
		yyparse();
  	} while (!feof(yyin));
  	printf("\nBye!");
  	return(0);
}
