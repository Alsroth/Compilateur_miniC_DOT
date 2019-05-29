//  main.c
//  Compilateur
//
//  Created by Swabahadine ABDALLAH on 13/03/2019.
//  Copyright © 2019 Swabahadine Abdallah. All rights reserved.
//


typedef struct Variable Variable;
typedef struct Environnement Environnement;
typedef struct Pile Pile;



struct Variable{
    char* nom;
    int valeur;
};

Variable listeValeur_appel[100];
int cpt_lva = 0;
struct Environnement{
    Variable table_de_variable[100];
    int num_derniere_var ;
    Environnement* parent;
};


struct Pile
{
    Environnement* premier;
};
void afficherPile(Pile *pile);
int recherchePosVar(char* nom , Environnement env){
    int i = 0;
    for(i = 0; i< env.num_derniere_var; i++){
        Variable t = env.table_de_variable[i];
        if(strcmp(t.nom,nom) == 0 ){
            return i;
        }
    }
    return i;
}

Variable trouveVar(char* nom , Environnement env){
    Variable v = {"null",-1};
    int i = 0;
    for(i = 0; i< env.num_derniere_var; i++){
        Variable t = env.table_de_variable[i];
        if(strcmp(t.nom,nom) == 0 ){
            return t;
        }
    }
    return v;
}

int isExiste(char* nom , Environnement env){
    int booleen = 1;
    if(recherchePosVar(nom,env) == env.num_derniere_var){
        booleen = 0;
    }
    return booleen;
}


void addVariable(char* nom, int valeur, Environnement* env){
    int position = recherchePosVar(nom,*env);
    Variable v ;
    v.nom = nom;
    v.valeur = valeur;
    env->table_de_variable[position] = v;
    if(position == env->num_derniere_var){
        env->num_derniere_var++;
    }
    
}
void addVariableSansValeur(char* nom, Environnement* env){
    addVariable(nom, 0, env);
}

void afficherTableEnv(Environnement env){
    printf("[");
    for(int i = 0; i< env.num_derniere_var; i++){
        Variable t = env.table_de_variable[i];
        printf(" %s:%d ,",t.nom , t.valeur);
    }
    printf("]->");
}

void create_copy( Environnement* env , Environnement* n_env ){
    Variable table_de_variable[100];
    Variable v;
    char* nom;
    int valeur;
    int taille = env->num_derniere_var;
    for(int i = 0; i< taille; i++){
        n_env->table_de_variable[i] = env->table_de_variable[i];
    }
    n_env->num_derniere_var = env->num_derniere_var;
    n_env->parent = env->parent;
}

// Fonction pour pile

void empiler(Pile* pile)
{

    Environnement *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    nouveau->num_derniere_var = 0;
    nouveau->parent = pile->premier;
    pile->premier = nouveau;
}


void afficherPile(Pile *pile)
{
    printf("\t->Pile :  ");
    int i = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Environnement *actuel = pile->premier;
 
    while (actuel != NULL && i<50)
    {
        afficherTableEnv(*actuel);
        actuel = actuel->parent;
        i++;
    }
    printf("\n");
}

Environnement depiler(Pile* pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Environnement envPremier;
    Environnement *elementDepile = pile->premier;
    
    if (pile != NULL && pile->premier != NULL)
    {
        envPremier = *elementDepile;
        pile->premier = elementDepile->parent;
        free(elementDepile);
    }
    
    return envPremier;
}


int isExistePile(char* nom , Pile *pile){
    int i = 0;
    int booleen = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Environnement *actuel = pile->premier;
    while (actuel != NULL && i<50)
    {
        if(isExiste(nom , *actuel)){
            return 1;
        }
        actuel = actuel->parent;
        i++;
    }
    return 0;
}

Variable trouverVar_pile(char* nom , Pile *pile){
    int i = 0;
    int booleen = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Environnement *actuel = pile->premier;
    while (actuel != NULL && i<50)
    {
        
        if(isExiste(nom , *actuel)){
            return trouveVar(nom , *actuel);
        }
        actuel = actuel->parent;
        i++;
    }
    Variable v = {nom,-1};
    
    return v;
}

void rechercheVarDansPile( char* var , Pile *pile , int* yylineno){
    if(!isExistePile(var,pile)){
        yyerror("aucune declaration");
        printf("\tla Variable/Fonction: %s n'a pas ete definie\n",var);
    }
}

void rechercheVarDansPile2( char* var , Pile *pile ,Pile *pileFontion, int* yylineno){
    Environnement *actuel = pileFontion->premier;
    if(!isExiste(var , *actuel)){
        rechercheVarDansPile( var , pile , yylineno);
    }
}

void sementiqueDeclaration(char* var , Pile *pile , int valeur, int* yylineno){

    Environnement nEnv = *pile->premier;
    if(!isExiste(var,*pile->premier)) {
        addVariable(var,valeur,pile->premier);
    }
    else{
        yyerror("multiple declaration");
        fprintf(stderr, "\tla variable \"%s\" a ete re declaree. \n",var); }
}

void sementiqueDeclaration2(char* var , Pile *pile ,Pile *pileFontion, int valeur, int* yylineno){
    
    Environnement nEnv = *pile->premier;
    Environnement nEnvFonction = *pileFontion->premier;
    if(!isExiste(var,*pileFontion->premier)) {
        sementiqueDeclaration(var , pile , valeur, yylineno);
    }
    else{
        yyerror("multiple declaration");
        fprintf(stderr, "\tla variable \"%s\" a ete declaree dans les parametres et ne peut etre re declaree. \n",var);
    }
}

void semantiqueAppel(char* var , Pile *pile , int* valeur, int* yylineno){
    Variable v = trouverVar_pile(var,pile);
    v.valeur = *valeur;
    listeValeur_appel[cpt_lva++] = v;
    *valeur = 0;
}

void semantiqueEmpiler(Pile *pile){
    empiler(pile);
    
}
