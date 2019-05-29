//  main.c
//  Compilateur
//
//  Created by Swabahadine ABDALLAH on 13/03/2019.
//  Copyright © 2019 Swabahadine Abdallah. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void yyerror(char *s);
int yylineno;
char* yytext;

typedef struct Variable Variable;
typedef struct Environnement Environnement;
typedef struct Pile Pile;



struct Variable;
struct Environnement;

struct Pile;
void afficherPile(Pile *pile);
int recherchePosVar(char* nom , Environnement env);

Variable trouveVar(char* nom , Environnement env);

int isExiste(char* nom , Environnement env);


void addVariable(char* nom, int valeur, Environnement* env);
void addVariableSansValeur(char* nom, Environnement* env);
void afficherTableEnv(Environnement env);

void create_copy( Environnement* env , Environnement* n_env );

// Fonction pour pile

void empiler(Pile* pile);


void afficherPile(Pile *pile);

Environnement depiler(Pile* pile);


int isExistePile(char* nom , Pile *pile);

Variable trouverVar_pile(char* nom , Pile *pile);

void rechercheVarDansPile( char* var , Pile *pile , int* yylineno);

void rechercheVarDansPile2( char* var , Pile *pile ,Pile *pileFontion, int* yylineno);
void sementiqueDeclaration(char* var , Pile *pile , int valeur, int* yylineno);

void sementiqueDeclaration2(char* var , Pile *pile ,Pile *pileFontion, int valeur, int* yylineno);

void semantiqueAppel(char* var , Pile *pile , int* valeur, int* yylineno);
void semantiqueEmpiler(Pile *pile);
