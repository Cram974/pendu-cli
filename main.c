#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "pendu.h"

int main(int argc, char *argv[])
{
  char Letter = 0;
  char Choix = 0;
  char MotSecret[100] = "";
  char Essai = 0;
  char *pntEssai = NULL;
  char *Discover = NULL;
  pntEssai = &Essai;
  while(Choix != 'N')
  {
        Essai = 10;      
        InitTab(MotSecret, 100);
        ChooseWordInDic(MotSecret);
        Discover = NULL;
        Discover = malloc(strlen(MotSecret)*sizeof(char));
        if(Discover == NULL)
        {
              exit(0);
        }
        InitTab(Discover, strlen(MotSecret));
        while(((IsItDiscovered(Discover, MotSecret) == 1) || (Essai <= 0))!= 1)
        {                                  
              printf("Vous avez %ld Chances\nEntrez une Lettre: ", Essai);
              Letter = GetCaractere();
              FindInTheWord(MotSecret, Discover, Letter, pntEssai);
              PrintSecretWordHided(MotSecret, Discover);
              printf("\n\n");
         }
         free(Discover);
         if(Essai == 0)
         {
              printf("Vous avez Perdu!\nLe mot secret etait : %s", MotSecret);
         }
         else
         {
              printf("Vous avez Gagne!");
         }
         printf("\nRejouer (O)ui ou (N)on ?: ");
         Choix = GetCaractere();
         printf("\n");
  }
  return 0;
}
