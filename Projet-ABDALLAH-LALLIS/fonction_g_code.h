//  main.c
//  Compilateur
//
//  Created by Swabahadine ABDALLAH on 13/03/2019.
//  Copyright © 2019 Swabahadine Abdallah. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* concat(int n_args, ...);
char* newNum();

char* newNode(char* nom, char* label, int id_label);

char* myNodeName();
char* newEtq() ;
char* newVar() ;

typedef struct Case_instuction Case_instuction;
struct Case_instuction;

typedef struct Switcher Switcher;
struct Switcher;


char** str_split(char* a_str, const char a_delim);


// Fontion pour pile
typedef struct Pile_node Pile_node;
typedef struct Node Node;
struct Node;

struct Pile_node;

void empiler_node(Pile_node* pile , char* nom , char* label, int id_label , char* suivant);
void afficherPile_node(Pile_node *pile);

Node depiler_node(Pile_node* pile);

void modifParentNode(Pile_node* pile,char* nom,char* parent);

// PILE EXPRS



typedef struct Pile_str Pile_str;
typedef struct Str Str;

typedef struct Pile_pile_str Pile_pile_str;

struct Str;

struct Pile_str;
struct Pile_pile_str;

void empiler_str(Pile_str* pile , char* nom);
void afficherPile_str(Pile_str *pile);

void empiler_pile_str(Pile_pile_str* pile);
Pile_str depiler_pile_str(Pile_pile_str* pile);

Str depiler_str(Pile_str* pile);

void modifParentNode_str(Pile_node* pile, Pile_str* pile_str,char* parent);


Node* trouve_i_node(Pile_node* pile, char* nomParent, int i);
