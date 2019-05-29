%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include "fonction.h"


int yylex();

int yylineno;
char* yytext;
void yyerror(char *s) {
    fprintf(stderr, "Error: %s ligne %d token:%s\n", s, yylineno, yytext);
    exit(1); /* le programe s'arrete lors d'une erreur de syntaxe */
}

%}
%token<chaine> VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token<chaine> IDENTIFICATEUR;
%token<chaine> CONSTANTE;


%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme

%type<chaine> liste_declarateurs declarateur programme liste_declarations declaration type liste_parms liste_instructions binary_op binary_comp binary_rel condition liste_fonctions fonction parm instruction iteration selection saut affectation bloc appel expression variable 
liste_expressions 
%union{
    char* chaine; 
    int valnum;
};

%%
programme    :    
        liste_declarations liste_fonctions 
;
liste_declarations    :    
        liste_declarations declaration 
    |    
;
liste_fonctions    :    
        liste_fonctions fonction 
|               fonction 
;
declaration    :    
        type liste_declarateurs ';' 
;
liste_declarateurs    :    
        liste_declarateurs ',' declarateur 
    |    declarateur 
;
declarateur    :    
        IDENTIFICATEUR {
            $$ = $1;
            char* c = $$;
            if(recherchePosVar(c,env) == env.num_derniere_var) { 
                addVariable(c,0,env); }
            else{ fprintf(stderr, "Erreur de redefinition: la variable \"%s\"  a la ligne : %d  a deja ete definie. \n",c,yylineno); exit(0); }
                       }
    |    declarateur '[' CONSTANTE ']' 
;
fonction    :    
        type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' 
    |    EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' 
;
type    :    
        VOID {$$ = "void";}
    |    INT {$$ = "int";}
;
liste_parms    : 
        parm 
    |    
        liste_parms ',' parm 
    |    {$$="";}
;
parm    :    
        INT IDENTIFICATEUR
;
liste_instructions :    
        liste_instructions instruction 
    | 
;
instruction    :    
        iteration 
    |    selection 
    |    saut 
    |    affectation ';' 
    |    bloc 
    |    appel 
; 
iteration    :    
        FOR '(' affectation ';' condition ';' affectation ')' instruction 
    |    WHILE '(' condition ')' instruction /*{$$ = concat(5,"while","(",$3,")",$5);}*/
;
selection    :    
        IF '(' condition ')' instruction %prec THEN 
    |    IF '(' condition ')' instruction ELSE instruction 
    |    SWITCH '(' expression ')' instruction 
    |    CASE CONSTANTE ':' instruction 
    |    DEFAULT ':' instruction 
;
saut    :    
        BREAK ';' 
    |    RETURN ';' 
    |    RETURN expression ';' 
;
affectation    :    
        variable '=' expression 
;
bloc    :    
        '{' liste_declarations liste_instructions '}' 
;
appel    :    
        IDENTIFICATEUR '(' liste_expressions ')' ';' 
            
variable    :    
        IDENTIFICATEUR {$$ = $1 ;}
    |    variable '[' expression ']' 
;
expression    :    
        '(' expression ')' 
    |    expression binary_op expression %prec OP 
    |    MOINS expression 
    |    CONSTANTE 
    |    variable 
    |    IDENTIFICATEUR '(' liste_expressions ')' 
;
liste_expressions    : 
        expression 
    | 
        liste_expressions ',' expression 
    | 
;
condition    :    
        NOT '(' condition ')' 
    |    condition binary_rel condition %prec REL 
    |    '(' condition ')' 
    |    expression binary_comp expression 
;
binary_op    :    
        PLUS {$$ = "+";}
    |       MOINS {$$ = "-";}
    |    MUL {$$ = "*";}
    |    DIV {$$ = "/";}
    |       LSHIFT {$$ = "<<";}
    |       RSHIFT {$$ = ">>";}
    |    BAND {$$ = "&";}
    |    BOR {$$ = "|";}
;
binary_rel    :    
        LAND {$$ = "&&";}
    |    LOR {$$ = "||";}
;
binary_comp    :    
        LT {$$ = "<";}
    |    GT {$$ = ">";}
    |    GEQ {$$ = ">=";}
    |    LEQ {$$ = "<=";}
    |    EQ {$$ = "==";}
    |    NEQ {$$ = "!=";}
;
%%

int main(int argc, const char *argv[]){    
     yyparse();
 }





