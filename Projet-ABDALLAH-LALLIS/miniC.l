D                   	[0-9]
L                   	[a-zA-Z_]
H                   	[a-fA-F0-9]
E                   	[Ee][+-]?{D}+
FS                  	(f|F|l|L)
IS                  	(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"


%}

%option yylineno
%option noyywrap

%%

 /* MOT CLÉ */
"break"             	{ return BREAK ;}
"case"              	{ return CASE;}
"default"           	{ return DEFAULT;}
"else"              	{ return ELSE;}
"extern"            	{ return EXTERN;}
"for"               	{ return FOR;}
"if"                	{ return IF;}
"int"               	{ return INT;}
"return"            	{ return RETURN;}
"switch"            	{ return SWITCH;}
"void"              	{ return VOID;}
"while"             	{ return WHILE;}
“then”        		{return THEN;}

{L}({L}|{D})*       	{yylval.chaine = strdup(yytext); return IDENTIFICATEUR; }
{D}+                 	{yylval.chaine = strdup(yytext); return CONSTANTE;}

 /*AFFECTATION*/
"="        	{return '=';}

 /* OPERATEUR DE COMPARAISON */
"<"                 	{return LT;}
">"                 	{return GT;}
"<="                	{return LEQ;}
">="                	{return GEQ;}
"=="                	{return EQ;}
"!="                	{return NEQ;}

 /* OPERATEUR BOOLEEN */
"&&"                	{return LAND;}
"||"                	{return LOR;}
"!"        	{return NOT;}

 /* OPERATEUR BINAIRE */
"+"        	{return PLUS;}
"-"        	{return MOINS;}
"*"        	{return MUL;}
"/"        	{return DIV;}
"&"        	{return BAND;}
"|"        	{return BOR;}
","        	{return ',';}

 /* ESPACE,TABULATION */
[ \t\v\n\f]         	{ ; }

 /* COMMENTAIRE */
"/*"([^*]|\*+[^*/])*\*+"/"    	{}

 /* AUTRE */
">>"                	{return RSHIFT;}
"<<"                	{return LSHIFT;}
"("        	{return '(';}
")"        	{return ')';}
"["        	{return '[';}
"]"        	{return ']';}
"{"        	{return '{';}
"}"        	{return '}';}
":"        	{return ':';}
";"        	{return ';';}
.                   	{ return yytext[0]; }

%%












