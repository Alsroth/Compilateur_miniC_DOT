//  main.c
//  Compilateur
//
//  Created by Swabahadine ABDALLAH on 13/03/2019.
//  Copyright © 2019 Swabahadine Abdallah. All rights reserved.
//
char* concat(int n_args, ...) {
    /* Fonction a arité variable qui concactène des chaines de caractères */
    va_list valist;
    int i;
    int BUFFER_SIZE;
    va_start(valist, n_args);
    for (i = 0; i < n_args; i++) BUFFER_SIZE += strlen(va_arg(valist, char*));
    va_end(valist);
    char* result = (char*) calloc(BUFFER_SIZE*2, sizeof(char));
    va_start(valist, n_args);
    for (i = 0; i < n_args; i++) strcat(result, va_arg(valist, char*));
    va_end(valist);
    return result;
}

int noEtq = 1;
int noVar = 0;
int break_temp = 0;
int addTabVar = 0;
int noNode = 1;

char* newNum(){
    char* nc = (char*) calloc(3, sizeof(char));
    sprintf(nc,"%d",noNode++);
    char* ncPrime = strdup(nc);
    free(nc);
    return ncPrime;
}

char* newNode(char* nom, char* label, int id_label){
    char* shape ;
    char* style ;
    char* color ;
    // Pour fonction
    if(id_label == 1){
        shape = "invtrapezium";
        color = "blue";
        style = "solid";
    }
    // Pour RETURN
    else if(id_label == 3){
        shape = "trapezium";
        color = "blue";
        style = "solid";
    }
    
    // Pour appel de fonction
    else if(id_label == 4){
        shape = "septagon";
        color = "black";
        style = "solid";
    }
    
    // Pour appel de break
    else if(id_label == 5){
        shape = "box";
        color = "black";
        style = "solid";
    }
    
    // Pour appel de break
    else if(id_label == 6){
        shape = "diamond";
        color = "black";
        style = "solid";
    }
    
    // Pour bloc
    else {
        shape = "ellipse";
        color = "black";
        style = "solid";
    }
    return concat(10,nom,"[shape=",shape," label=\"",label,"\" style=",style," color=",color,"]\n");
}

char* myNodeName(){
    return concat(2,"node",newNum());
}
char* newEtq() {
    char* nc = (char*) calloc(10, sizeof(char));
    sprintf(nc,"L%d",noEtq++);
    if(break_temp != 0){
        sprintf(nc,"L%d",break_temp);
        break_temp = 0;
    }
    return nc;
}

char* newVar() {
    char* nc = (char*) calloc(10, sizeof(char));
    sprintf(nc,"_t%d",addTabVar++);
    return nc;
}

char* tab3add[100];
char* tabVar[100];

typedef struct Case_instuction Case_instuction;
struct Case_instuction
{
    char* cons;
    char* instruction;
};

typedef struct Switcher Switcher;
struct Switcher
{
    Case_instuction tab_case[100];
    int n;
};

Switcher switcher;
char* conser[10];
char* caser[10];
int cpt_n = 0;

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    
    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    
    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);
    
    /* Add space for terminating null string so caller
     knows where the list of returned strings ends. */
    count++;
    
    result = malloc(sizeof(char*) * count);
    
    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);
        
        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    
    return result;
}


// Fontion pour pile
typedef struct Pile_node Pile_node;
typedef struct Node Node;
struct Node{
    char* nom;
    char* label;
    int id_label;
    Node* parent;
    char* suivant;
};

struct Pile_node
{
    Node* premier;
};

void empiler_node(Pile_node* pile , char* nom , char* label, int id_label , char* suivant)
{
    
    Node *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    nouveau->nom = nom;
    nouveau->id_label = id_label;
    nouveau->suivant = suivant;
    nouveau->label = label;
    nouveau->parent = pile->premier;
    pile->premier = nouveau;
    /*printf("Lab : %s\n",label);*/
}


void afficherPile_node(Pile_node *pile)
{
    printf("\t->Pile :  ");
    int i = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Node *actuel = pile->premier;
    
    while (actuel != NULL && i<50)
    {
        printf("%s\n",actuel->nom);
        actuel = actuel->parent;
        i++;
    }
    printf("\n");
}

Node depiler_node(Pile_node* pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Node envPremier;
    Node *elementDepile = pile->premier;
    
    if (pile != NULL && pile->premier != NULL)
    {
        envPremier = *elementDepile;
        pile->premier = elementDepile->parent;
        free(elementDepile);
    }
    
    return envPremier;
}

void modifParentNode(Pile_node* pile,char* nom,char* parent){
    int i = 0;
    int booleen = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Node* actuel = pile->premier;
    while (actuel != NULL && i<5000)
    {
        if(strcmp(nom , actuel->nom) == 0 && strcmp(actuel->suivant,"")==0){
            /*printf("Label = %s\n",actuel->label);*/
            actuel->suivant = parent;
            i = 100;
        }
        actuel = actuel->parent;
        i++;
    }
}


// PILE EXPRS



typedef struct Pile_str Pile_str;
typedef struct Str Str;

typedef struct Pile_pile_str Pile_pile_str;

struct Str{
    char* nom;
    Str* parent;
    
};

struct Pile_str
{
    Str* premier;
    Pile_str* parent;
};

struct Pile_pile_str
{
    Pile_str* premier;
};

void empiler_str(Pile_str* pile , char* nom)
{
    
    Str *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    nouveau->nom = nom;
    nouveau->parent = pile->premier;
    pile->premier = nouveau;
    /*printf("Nom : %s \n",pile->premier->nom);*/
}
void afficherPile_str(Pile_str *pile)
{
    printf("\t->Pile :  ");
    int i = 0;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Str *actuel = pile->premier;
    
    while (actuel != NULL && i<50)
    {
        printf("%s -> ",actuel->nom);
        actuel = actuel->parent;
        i++;
    }
    printf("\n");
}

void empiler_pile_str(Pile_pile_str* pile)
{
    
    Pile_str *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->parent = pile->premier;
    pile->premier = nouveau;
}

Pile_str depiler_pile_str(Pile_pile_str* pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Pile_str envPremier;
    Pile_str* elementDepile = pile->premier;
    
    if (pile != NULL && pile->premier != NULL)
    {
        envPremier = *elementDepile;
        pile->premier = elementDepile->parent;
        free(elementDepile);
    }
    
    return envPremier;
}


Str depiler_str(Pile_str* pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    Str envPremier;
    Str *elementDepile = pile->premier;
    
    if (pile != NULL && pile->premier != NULL)
    {
        envPremier = *elementDepile;
        pile->premier = elementDepile->parent;
        free(elementDepile);
    }
    
    return envPremier;
}

void modifParentNode_str(Pile_node* pile, Pile_str* pile_str,char* parent){
    int i = 0;
    int booleen = 0;
    if (pile_str == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Str* actuel = pile_str->premier;
    /*printf("GO : %s ",actuel->nom);*/
    while (actuel != NULL && i<5000)
    {
        /*printf("Actuel = %s ",actuel->nom);*/
        modifParentNode(pile,actuel->nom , parent);
        depiler_str(pile_str);
        actuel = pile_str->premier;
        i++;
    }
}


Node* trouve_i_node(Pile_node* pile, char* nomParent, int i){
    int j = 0;
    Node* nodeTrouvee = pile->premier;
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Node* actuel = pile->premier;
    while (actuel != NULL && j<i)
    {
        if(strcmp(nomParent , actuel->suivant) == 0){
            /*printf("good = %s\n",actuel->label);*/
            nodeTrouvee = actuel;
            j++;
        }
        actuel = actuel->parent;
        i++;
    }
    return nodeTrouvee;
}
