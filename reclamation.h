#ifndef RECLAMATION_H_INCLUDED
#define RECLAMATION_H_INCLUDED
#include <stdio.h>



typedef struct
{
        int id; 
	int num_bv;
        char type_reclamation[20];
	
        char text_reclamation[100];
        char liste_electoral[30];
}reclamation;
int ajouter(char *, reclamation);
int modifier( char *, int, reclamation );
int supprimer(char *, int );
#endif // POINT_H_INCLUDED
