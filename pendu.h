#ifndef DEF_PENDU
#define DEF_PENDU
void InitTab(char Tableau[],int long_tab);
char GetCaractere();
void FindInTheWord(char MotSecret[], char Discover[], char Letter, char* Essai);
void PrintSecretWordHided(char MotSecret[], char Discover[]);
char IsItDiscovered(char Discover[], char MotSecret[]);
int ChooseWordInDic(char MotSecret[]);
#endif
