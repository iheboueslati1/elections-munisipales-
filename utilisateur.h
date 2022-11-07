typedef struct 
{
int j ,m,a;

}Date;


typedef struct 
{
char nom[50];
char prenom [50];
int sexe;
int role;
int nationalite;  
int id;
int passp;
Date d ;
int idbur;
int vote ;
int apr ; 
} utilisateur ;


int ajouter(char *, utilisateur);
int modifier( char *, int, utilisateur );
int supprimer(char *, int );
utilisateur chercher(char *, int);



