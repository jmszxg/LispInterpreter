
%{

%}


/* Defintions of regular expressions go here */
INTCONST [+-]?[0-9]+
IDENT [a-zA-Z_]+[a-zA-Z0-9_]* 
STRCONST \"([^"\n])*\"
COMMENT ";".*

%%
" "             {}
"let*"          {
                    // printToken("LETSTAR", yytext);
                    enterScope();
                    return T_LETSTAR;
                }
"lambda"        {
                    // printToken("LAMBDA",  yytext);
                    enterScope();
                    return T_LAMBDA;
                }
"input"         {
                    // printToken("INPUT",   yytext);
                    return T_INPUT;
                }
"print"         {
                    // printToken("PRINT",   yytext);
                    return T_PRINT;
                }
"if"            {
                    // printToken("IF",      yytext);
                    return T_IF;
                }
"exit"          {
                    // printToken("EXIT",    yytext);
                    return T_EXIT;
                }
"progn"         {
                    // printToken("PROGN",   yytext);
                    return T_PROGN;
                }
"("             {
                    // printToken("LPAREN",  yytext);
                    return T_LPAREN;
                }
")"             {
                    // printToken("RPAREN",  yytext);
                    return T_RPAREN;
                }
"+"             {
                    // printToken("ADD",     yytext);
                    return T_ADD;
                }
"*"             {
                    // printToken("MULT",     yytext);
                    return T_MULT;
                }
"/"             {
                    // printToken("DIV",     yytext);
                    return T_DIV;
                }
"-"             {
                    // printToken("SUB",     yytext);
                    return T_SUB;
                }
"and"           {
                    // printToken("AND",     yytext);
                    return T_AND;
                }
"or"            {
                    // printToken("OR",      yytext);
                    return T_OR;

                }
"not"           {
                    // printToken("NOT",     yytext);
                    return T_NOT;
                }
"<"             {
                    // printToken("LT",      yytext);
                    return T_LT;
                }
">"             {
                    // printToken("GT",      yytext);
                    return T_GT;
                }
"<="            {
                    // printToken("LE",      yytext);
                    return T_LE;
                }
">="            {
                    // printToken("GE",      yytext);
                    return T_GE;
                }
"="             {
                    // printToken("EQ",      yytext);
                    return T_EQ;
                }
"/="            {
                    // printToken("NE",      yytext);
                    return T_NE;
                }
"t"             {
                    // printToken("T",       yytext);
                    return T_T;
                }
"nil"           {
                    // printToken("NIL",     yytext);
                    return T_NIL;
                }
{COMMENT}       { }
{IDENT}         {   // printToken("IDENT",   yytext);
                    yylval.text = strdup(yytext);
                    return T_IDENT;    
                }
{INTCONST}      {   // printToken("INTCONST",yytext);
                    yylval.intVal = atoi(yytext);
                    return T_INTCONST;    
                }
{STRCONST}      {   // printToken("STRCONST",yytext);
                    yylval.text = strdup(yytext);
                    return T_STRCONST;    
                }
[ \t\n\r]+      {
                    numLines++;
                }
.               {
                    // printToken("UNKNOWN", yytext);
                    return T_UNKNOWN;
                }

%%


