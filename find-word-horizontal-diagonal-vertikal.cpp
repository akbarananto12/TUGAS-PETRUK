/* 
ANGGOTA KELOMPOK
Ananto Akbar               2017051069
Assyfa Naziwa Ganandy      2017051046
Karina Adityas Ramadhanti  2017051041
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;
const int cols = 16, rows = 15;
int panjang = 0;

 char words[rows][cols] =      {"tgbwwinterwsesn",
                                "aaunttmmhfoodnb",
                                "jlwcqldzmpmvdmr",
                                "asagmquwvvbsohi",
                                "bwplotanadtpgnc",
                                "rewngodjcpnatnk",
                                "eeotwosbqharrsa",
                                "azcgeswewnaknpb",
                                "dinnerqodlwdcar",
                                "onopkwmparktzcc",
                                "qbfrogmamwpweey",
                                "lqzqnnmrzjjsclg",
                                "mosgzczetdbooto",
                                "pdcrzmsngrdnrpz",
                                "ohnkzwaterjgtra"};

char *getWordVertical(int a);
char *getWordHorizontal(int a);
char *getWordDiagonal(int a);
char *reverse(char *a);
bool searchVertical(char *a);
bool searchHorizontal(char *a);
bool searchDiagonal(char *a);


int main()
{
    char word[16];
    int n;
    cin>>n;
    cin.ignore(1,'\n');
    for (int i=0;i<n;i++){
        cin.getline(word,16,'\n');
        if (searchVertical(word)|| searchHorizontal(word) || searchDiagonal(word)) {
            cout << "Ada\n"; }
        else{
            cout << "Tidak Ada\n";}
    }
    return 0;
}

char *getWordVertical(int a){
char HurufVertikal[rows*rows+1];
    for (int i=0;i<cols-1;i++){
        for (int j=0;j<rows;j++){
        HurufVertikal[a] = words[j][i];
        a++;
        }
    }
    if (a == 225){
    a = 0;
    int panjang_huruf = strlen(HurufVertikal);
    char *KataVertikal = (char*)malloc((panjang_huruf+1) * sizeof(char));
    memcpy (KataVertikal,HurufVertikal,panjang_huruf+1);
    return KataVertikal;} }


char *getWordHorizontal(int a){
    char HurufHorizontal[rows*rows+1];
    for (int i=0;i<rows;i++){
    for (int j=0;j<cols-1;j++){
    HurufHorizontal [a] = words [i][j];
    a++;}
    
    if (a == 225){
    a = 0;
    int panjang_huruf = strlen(HurufHorizontal);
    char *KataHorizontal = (char*)malloc((panjang_huruf+1) * sizeof(char));
    memcpy (KataHorizontal,HurufHorizontal,panjang_huruf+1);
    return KataHorizontal;} } }


char *getWordDiagonal(int a){
    char HurufDiagonal[rows*rows+1];
    int diagonal = 0;
    if (a<=120){
    for(int i = cols-1;i>=0;i--){
    for (int j = i; j <= 14;j++){
    HurufDiagonal[a] = words [j][diagonal];
    diagonal++;
    a++; } diagonal = 0;
  }
} if (a == 120){diagonal=1;}

  if (a >= 120){
  for (int i = 0; i<14;i++){
    for (int j = diagonal-1;j<14;j++){
        for (int k = 0; k <= 14 - diagonal;k++){
            j = j +1;
            HurufDiagonal[a] = words [k][j];
            a++; } diagonal++; } }
  } if (a == 225){
    a = 0;
    int panjang_huruf = strlen(HurufDiagonal);
    char *KataDiagonal = (char*)malloc((panjang_huruf+1) * sizeof(char));
    memcpy (KataDiagonal,HurufDiagonal,panjang_huruf+1);
    return KataDiagonal;} }



char *reverse(char *a ){
  int panjang_char = strlen(a);
  reverse (a,a+panjang_char);
  return a; }


bool searchVertical(char *a){
char *ketemu = strstr(getWordVertical(panjang),a);
char *ketemu_kebalik = strstr(reverse(getWordVertical(panjang)),a);

for (int i = 0;i<15;i++){
    if (ketemu){return true;}
    else if (ketemu_kebalik){return true; } } }



bool searchHorizontal(char *a){
char *ketemu = strstr(getWordHorizontal(panjang),a);
char *ketemu_kebalik = strstr(reverse(getWordHorizontal(panjang)),a);

for (int i = 0;i<15;i++){
    if (ketemu){return true;}
    else if (ketemu_kebalik){return true; } } }


bool searchDiagonal(char *a){
char *ketemu = strstr(getWordDiagonal(panjang),a);
char *ketemu_kebalik = strstr(reverse(getWordDiagonal(panjang)),a);
 
for (int i = 0;i<15;i++){
    if (ketemu){return true;}
    else if (ketemu_kebalik){return true; } } }
