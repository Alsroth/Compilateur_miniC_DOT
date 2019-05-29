%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include "fonction.h"
#include "fonction.c"
#include "fonction_g_code.h"
#include "fonction_g_code.c"


Environnement env = {NULL, 0, NULL};
Environnement* p_env = &env;
Environnement envNull = {NULL, 0, NULL};

Pile_node pile_node = {NULL};  
Pile_node pile_node_case = {NULL};  
Node node_case[100]; 
int inc = 0;
Pile_str pile_str = {NULL};  
Pile_str pile_expr = {NULL}; 
Node* p_node = NULL;   
Pile_str tabPile_str[100];
int i_tabPile_str = 0;
Pile pile = {&env};
Pile pileFonction = {&envNull};
int op = 0;
int parms = 0;
int exprs = 0;
char* isTab = "";
char* tab ;
int n_error = 0;
int yylex();
int isVoid = 0;
int isSwitch = 0;
char* nodeCase;
int testRetour = 0;
int yylineno;
char* yytext;
void yyerror(char *s) {
    fprintf(stderr, "* Error \"%s\", ligne %d: \n", s, yylineno);
    n_error++;
     /* le programe s'arrete lors d'une erreur de syntaxe */
}

void warningError(char *s) {
    fprintf(stdout, "* Avertissement \"%s\", ligne %d: \n", s, yylineno);
     /* le programe s'arrete lors d'une erreur de syntaxe */
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

%type<chaine> liste_declarateurs declarateur programme liste_declarations declaration type liste_parms liste_instructions binary_comp binary_rel condition expression_switch liste_fonctions fonction parm instruction iteration selection saut affectation bloc appel expression variable 
liste_expressions 
%union{
    char* chaine; 
    int valnum;
};

%%
programme    :    
        liste_declarations liste_fonctions {
            
            printf("Fin du programme: %d erreur(s) generee(s).\n",n_error);
                
        }
;
liste_declarations    :    
        liste_declarations declaration {
            $$ = concat(2, $1, $2);
        }
    |  {
            Pile_str pile_str = {NULL};
            tabPile_str[++i_tabPile_str] = pile_str;
            semantiqueEmpiler(&pile); 
            $$ = "";
        }
;
liste_fonctions    :    
        liste_fonctions fonction {
            $$ = concat(2, $1, $2);
    }
|               fonction {$$ = $1;}
;
declaration    :    
        type liste_declarateurs ';' {
             if(isVoid == 1){
                yyerror("declaration avec void");
                printf("Le type void ne peut etre utiliser pour la declaration de variable\n");
            }
            $$ = concat(4, $1, " ", $2, ";\n");
            
        }
;
liste_declarateurs    :    
        liste_declarateurs ',' declarateur {$$ = concat(3, $1, ",", $3);}
    |    declarateur {$$ = $1;}
;
declarateur    :    
        IDENTIFICATEUR {
            $$ = $1;
            sementiqueDeclaration2($1,&pile,&pileFonction,0,&yylineno);
            }
    |    declarateur '[' CONSTANTE ']' {$$ = concat(4, $1, "[",$3, "]");}
;
fonction    :    
        type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {
            $$ = $2;
            depiler(&pile);
            sementiqueDeclaration($2,&pile,parms,&yylineno);
            for(int cpt = 0; cpt < cpt_lva ; cpt++){
                Variable var = listeValeur_appel[cpt];
                Variable varPile = trouverVar_pile(var.nom,&pile);
                rechercheVarDansPile(var.nom , &pile ,&yylineno);
                if(var.valeur != varPile.valeur){
                    yyerror("nombre parametre");
                    printf("\til faut %d parametres a la fonction \" %s(int ...) \" , vous en avez mis %d !!!\n",varPile.valeur, var.nom , var.valeur);
                }
            }
            empiler(&pileFonction);
            parms = 0;
            cpt_lva = 0;
            if(strcmp($1,"int")==0 && testRetour == 0){
                warningError("Absence de retour d'expression");
                printf("La fonction int n'a pas de retour d'expression.\n\n");

            }
            testRetour = 0;
            
            
            char* bloc = myNodeName();
            char* fonction = myNodeName();
            char* label_fonction = concat(3,$1," , ",$2);
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],bloc);
            empiler_node(&pile_node,bloc,"BLOC",2,fonction);
            
            empiler_node(&pile_node,fonction,label_fonction,1,"");
            
            
            $$ = fonction;
            }
            
        
    |    EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {
            
            sementiqueDeclaration($3,&pile,parms,&yylineno);
            empiler(&pileFonction);
            parms = 0;
            $$ = "";
    
    }
;
type    :    
        VOID {
            $$ = "void";
            isVoid = 1;
        }
    |    INT {
        $$ = "int";
        isVoid = 0;
    }
;
liste_parms    : 
        parm {$$ = $1;}
    |    
        liste_parms ',' parm {$$ = concat(3,$1,",",$3);}
    |    {$$="";}
;
parm    :    
        INT IDENTIFICATEUR {
            $$ = concat(2,"int ",$2);
            sementiqueDeclaration($2,&pileFonction,parms,&yylineno);
            parms++;
        }
;
liste_instructions :    
        liste_instructions instruction {
            empiler_str(&tabPile_str[i_tabPile_str],$2);
            p_node = pile_node.premier;
            $$ = $2;
        }
    | {
        $$ = "";
        
    }
;
instruction	:	
		iteration {$$ = $1;}
	|	selection {$$ = $1;}
	|	saut {
        $$ = $1;
        if(isSwitch>0){
            modifParentNode(&pile_node,$$,nodeCase);
            isSwitch = 0;
        }
    }
	|	affectation ';' {$$ = concat(2,$1,"");}
	|	bloc {$$ = $1;}
	|	appel {$$ = $1;}
; 
iteration    :    
        FOR '(' affectation ';' condition ';' affectation ')' instruction {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$3,parent);
            modifParentNode(&pile_node,$5,parent);
            modifParentNode(&pile_node,$7,parent);
            modifParentNode(&pile_node,$9,parent);
            empiler_node(&pile_node,parent,"FOR",2,""); 
            $$ = parent;
        }
    |    WHILE '(' condition ')' instruction {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$3,parent);
            modifParentNode(&pile_node,$5,parent);
            empiler_node(&pile_node,parent,"WHILE",2,""); 
            $$ = parent;
    }
;
selection    :    
        IF '(' condition ')' instruction %prec THEN {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$3,parent);
            modifParentNode(&pile_node,$5,parent);
            empiler_node(&pile_node,parent,"IF",6,""); 
            $$ = parent;
        }
    |    IF '(' condition ')' instruction ELSE instruction {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$3,parent);
            modifParentNode(&pile_node,$5,parent);
            modifParentNode(&pile_node,$7,parent);
            empiler_node(&pile_node,parent,"IF",6,""); 
            $$ = parent;
        
        }
    |    SWITCH '(' expression_switch ')' instruction {
            isSwitch = 0;
            /*pile_node.premier = p_node;
            depiler_node(&pile_node);*/
            pile_node.premier->label = "SWITCH";
            char* parent = pile_node.premier->nom;
            
           
            /*int i = 0;
            while(i<inc){
                Node n = node_case[i++];
                empiler_node(&pile_node,n.nom,n.label,2,parent); 
            }
            inc = 0;*/
            $$ = parent;
        }
    |    CASE CONSTANTE ':' instruction {
            isSwitch = 1;
            char* myCase = myNodeName();        
            char* case_label = concat(2,"case",$2);
            modifParentNode(&pile_node,$4,myCase);
            empiler_node(&pile_node,myCase,case_label,2,"");
            Node n = {myCase,case_label,2,NULL,""};
            node_case[inc++] = n;
            nodeCase = myCase;
            $$ = myCase;
        }
    |    DEFAULT ':' instruction {
            isSwitch = 1;
            char* myCase = myNodeName();        
            char* case_label = "case_default";
            modifParentNode(&pile_node,$3,myCase);
            empiler_node(&pile_node,myCase,case_label,2,"");
            Node n = {myCase,case_label,2,NULL,""};
            node_case[inc++] = n;
            nodeCase = myCase;
            $$ = myCase;
        }
;
saut    :    
        BREAK ';' {
            char* nom = myNodeName();
            empiler_node(&pile_node,nom,"BREAK",5,""); 
            $$ = nom;
        }
    |    RETURN ';' {
        
            char* parent = myNodeName();
            empiler_node(&pile_node,parent,"RETURN",3,""); 
            $$ = parent;
        
        }
    |    RETURN expression ';' {
             testRetour = 1;
             char* parent = myNodeName();        
             modifParentNode(&pile_node,$2,parent);
             empiler_node(&pile_node,parent,"RETURN",3,""); 
             $$ = parent;
        
             if(isVoid == 1){
                yyerror("retour d'un void");
                printf("Une fonction de type void ne peut pas avoir de retour\n");
            }
    }
;

expression_switch : 
        expression {
            pile_node.premier = p_node;
            $$ = $1;
        }
;
affectation    :    
        variable '=' expression {
        char* parent = myNodeName();        
        modifParentNode(&pile_node,$1,parent);
        modifParentNode(&pile_node,$3,parent);
        empiler_node(&pile_node,parent,":=",2,""); 
        $$ = parent;
        }
;
bloc    :    
        '{' liste_declarations liste_instructions '}' {
            char* bloc = myNodeName();
            
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],bloc);
            empiler_node(&pile_node,bloc,"BLOC",2,"");
            $$ = bloc;
            
            depiler(&pile);            
           
        }
;
appel    :    
        IDENTIFICATEUR '(' liste_expressions ')' ';' {
            
            char* parent = myNodeName();
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],parent);
            empiler_node(&pile_node,parent,$1,4,"");
            $$= parent;
            semantiqueAppel($1,&pile,&exprs,&yylineno);
            exprs = 0;
        }
            
variable    :    
        IDENTIFICATEUR {
            char* nom = myNodeName();
            $$ = nom;
            tab = myNodeName();
            empiler_node(&pile_node,nom,$1,2,"");
            rechercheVarDansPile2($1 , &pile, &pileFonction ,&yylineno);
        }
    |    variable '[' expression ']' { 
            if(strcmp(isTab,tab)!=0){
                isTab = tab;
                empiler_node(&pile_node,tab,"TAB",2,"");
                modifParentNode(&pile_node,$1,tab);
            }
            modifParentNode(&pile_node,$3,tab);
            $$ = tab;
        }
;
expression    :    
        '(' expression ')' {
            $$ = $2;
        }
    |    expression PLUS expression  {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"+",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression MOINS expression {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"-",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression MUL expression {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"*",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression DIV expression {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"/",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression LSHIFT expression  {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"<<",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression RSHIFT expression  {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,">>",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression BAND expression  {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"&",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    expression BOR expression {
        
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"|",2,"");
            /*if(condition_trois_adresses(&pile_node,$2,parent)){
                printf("->>>%s\n",$2);
                code_trois_adresses(&pile_node);
            }*/
            $$ = parent;
    }
    |    MOINS expression {
        
        char* parent = myNodeName();        
        modifParentNode(&pile_node,$2,parent);
        empiler_node(&pile_node,parent,":-",2,""); 
        $$ = parent;
    }
    |    CONSTANTE {
            char* nom = myNodeName();
            empiler_node(&pile_node,nom,$1,2,"");
            $$ = nom;
    }
    |    variable {
            $$ = $1;
    }
    |    IDENTIFICATEUR '(' liste_expressions ')' {
            char* parent = myNodeName();
            modifParentNode_str(&pile_node,&tabPile_str[i_tabPile_str--],parent);
            empiler_node(&pile_node,parent,$1,2,"");
            $$= parent;
            semantiqueAppel($1,&pile,&exprs,&yylineno);
            exprs = 0;
    }
;
liste_expressions    : 
        expression {
            exprs++;
            /*empiler_str(&pile_expr,$1);*/
            Pile_str pile_str = {NULL};
            tabPile_str[++i_tabPile_str] = pile_str;
            empiler_str(&tabPile_str[i_tabPile_str],$1);
            $$ = $1;
            
        }
    | 
        liste_expressions ',' expression {
            exprs++;
            empiler_str(&tabPile_str[i_tabPile_str],$3);
            /*empiler_str(&pile_expr,$3);*/
            $$ = $3;

    }
    | {$$ = "";}
;
condition    :    
        NOT '(' condition ')' {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,"NOT",2,""); 
            $$ = parent;
        }
    |    condition binary_rel condition %prec REL {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,$2,2,""); 
            $$ = parent;
    }
    |    '(' condition ')' {$$ = $2;}
    |    expression binary_comp expression {
            char* parent = myNodeName();        
            modifParentNode(&pile_node,$1,parent);
            modifParentNode(&pile_node,$3,parent);
            empiler_node(&pile_node,parent,$2,2,""); 
            $$ = parent;
        }
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

int main(int argc, char *argv[]){    
     yyparse();
    if(n_error>0){
                printf("%d erreur(s) de semantique. Aucun fichier n'a ete genere. \n",n_error);
                exit(1);
            }
            
            char* node_reste = "";
            char* node_liaison = "";
            char* contenu = "";
            while(pile_node.premier != NULL){
                Node ins = depiler_node(&pile_node);
                if(strlen(ins.suivant) == 0){
                    node_reste = concat(2,newNode(ins.nom,ins.label,ins.id_label),node_reste);
                    
                        
                }
                else{
                    node_liaison = concat(4,ins.suivant,"->",ins.nom,"\n");
                    node_reste = concat(3,newNode(ins.nom,ins.label,ins.id_label),node_reste,node_liaison);
                }
            }
        
            
            
            
            contenu = concat(3 , "digraph mon_programme {\n",node_reste,"\n}");
            
            char* nomFichier;
            if(argv[1] != NULL)
            {
                nomFichier = argv[1];
                nomFichier = concat(3,"DOT/",argv[1],".dot");
            }
            else
            {
                nomFichier = "DOT/out.dot";

            }
            FILE* fichier = fopen(nomFichier,"w");
            fprintf(fichier, "%s\n", contenu);
            fclose(fichier);
            printf("Un fichier \"%s\" a ete genere.\n",nomFichier);
 }


