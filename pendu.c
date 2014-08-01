#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
void InitTab(char Tableau[],int long_tab)
{
     int i = 0;
     for(i = 0; i < long_tab; i++)
     {
           Tableau[i] = 0;
     }
}


char GetCaractere() 
{
    char caractere = 0;
    caractere = getchar();
    caractere = toupper(caractere);
    while(getchar() != '\n');
    return caractere;
}

void FindInTheWord(char MotSecret[], char Discover[], char Letter, char* Essai)
{
     char i = 0, Find = 0;
     for(i = 0; i < strlen(MotSecret); i++)
     {
           if(Letter == MotSecret[i])
           {
                     Discover[i] = 1;
                     Find = 1;
           }
     }
     if(Find == 0)
     {
             *Essai = *Essai - 1;
     } 
}

void PrintSecretWordHided(char MotSecret[], char Discover[])
{
     char i = 0;
     printf("Mot Secret: ");
     for(i = 0; i < strlen(MotSecret); i++)
     {
           if(Discover[i] == 1)
           {
                     printf("%c", MotSecret[i]);
           }
           else
           {
               printf("*");
           }
     }
}

char IsItDiscovered(char Discover[], char MotSecret[])
{
     char i = 0, ok = 1;
     for(i = 0; i < strlen(MotSecret); i++)
     {
              if(Discover[i] == 0)
              {
                             ok = 0;
              }
     }
     return ok;
}

int ChooseWordInDic(char MotSecret[])
{
     FILE* Dico = NULL;
     int carac = 0, NbMots = 0, MotChoisi = 0, i = 0;     
     Dico = fopen("Dictionnaire.txt","r");
     if(Dico == NULL)
     {
             printf("\n\n\n\nErreur produite lors de l'ouverture du Dictionnaire.");
             exit(0);
     }
     do
     {
            carac = fgetc(Dico); // On lit le caractère
            if(carac == '\n')
            {
                     NbMots++;
            }
     } while (carac != EOF); // On continue tant que fgetc n'a pas retourné EOF
     
     fseek(Dico, 0, SEEK_SET);//On se remet au debut du fichier
     srand(time(NULL));
     MotChoisi = (rand() % NbMots);
     i = 0;
     carac = 0;
     while(i < MotChoisi)
     {
            carac = fgetc(Dico); // On lit le caractère
            if(carac == '\n')
            {
                     i++;
            }
     }
     i = 0;
     carac = 0;
     while (carac != '\n')
     {
            carac = fgetc(Dico);
            MotSecret[i] = carac; // On lit le caractère
            i++;
     }
     MotSecret[i-1] = '\0';
     fclose(Dico);
}

