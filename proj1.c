/* IZP Projekt 1 - Prace s textem
** autor: Patrik Demsky
** login: xdemsk00
** datum: 17.11.2019
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX 102 //maximalna dlzka retazca ktora zahrna 100 znakov, koncovy znak a znak noveho riadku

int compare(char entry, char number) {
    //funkcia porovnava znaky
    int is_same = 0;

    if(number == '1') {
        if(entry == '1')
            is_same = 1;
    }

    if(number == '2') {
        if(entry == '2' || entry == 'a' || entry == 'b' || entry == 'c' || entry == 'A' || entry == 'B' || entry == 'C')
            is_same = 1;
    }

    if(number == '3') {
        if(entry == '3' || entry == 'd' || entry == 'e' || entry == 'f' || entry == 'D' || entry == 'E' || entry == 'F')
            is_same = 1;
    }


    if(number == '4') {
        if(entry == '4' || entry == 'g' || entry == 'h' || entry == 'i' || entry == 'G' || entry == 'H' || entry == 'I')
            is_same = 1;
    }


    if(number == '5') {
        if(entry == '5' || entry == 'j' || entry == 'k' || entry == 'l' || entry == 'J' || entry == 'K' || entry == 'L')
            is_same = 1;
    }


    if(number == '6') {
        if(entry == '6' || entry == 'm' || entry == 'n' || entry == 'o' || entry == 'M' || entry == 'N' || entry == 'O')
            is_same = 1;
    }


    if(number == '7') {
        if(entry == '7' || entry == 'p' || entry == 'q' || entry == 'r' || entry == 's' || entry == 'P' || entry == 'Q' || entry == 'R' || entry == 'S')
            is_same = 1;
    }


    if(number == '8') {
        if(entry == '8' || entry == 't' || entry == 'u' || entry == 'v' || entry == 'T' || entry == 'U' || entry == 'V')
            is_same = 1;
    }


    if(number == '9') {
        if(entry == '9' || entry == 'w' || entry == 'x' || entry == 'y' || entry == 'z' || entry == 'W' || entry == 'X' || entry == 'Y' || entry == 'Z')
            is_same = 1;
    }


    if(number == '0') {
        if(entry == '0' || entry == '+')
            is_same = 1;
    }
    return is_same;
}

void search(char cislo[]) {
    //Funckia ktora naskenuje dva riadky
    char riadok[MAX];
    char riadok_druhy[MAX];
    bool naslo_zaznam = false;

    while(true) {

      if(fgets(riadok, MAX, stdin) == NULL) break; //vyskoci z mega whilu
      if(fgets(riadok_druhy, MAX, stdin) == NULL) break; //vyskoci z mega whilu

      bool found = false; // pravdivostna hodnota, ktora hlada zhodu v prvom riadku
      bool found_druhy = false; // pravdivostna hodnota, ktora hlada zhodu v druhom riadku

      //prejde kazdy prvok v prvom riadku
      for(int i = 0; riadok[i] != '\0'; i++) {
        bool is_same = false;
        for(int j = 0; cislo[j] != '\0'; j++) {
          //funkcia porovna znaky prveho riadku a vstupu
          if(compare(riadok[i+j], cislo[j]) == 1) is_same = true;
          else {
            is_same = false;
            break;
          }
        }
        if(is_same == true) {
          found = true;
          break;
        }
      }

      //prejde kazdy prvok v druhom riadku
      for(int i = 0; riadok_druhy[i] != '\0'; i++) {
        bool is_same = false;
        for(int j = 0; cislo[j] != '\0'; j++) {
          //funkcia porovna znaky druheho riadku a vstupu
          if(compare(riadok_druhy[i+j], cislo[j]) == 1) is_same = true;
          else {
            is_same = false;
            break;
          }
        }
        if(is_same == true) {
          found_druhy = true;
          break;
        }
      }

      // Ak program najde zhodu v prvom alebo v druhom riadku
      if(found || found_druhy) {
        naslo_zaznam = true;
        //nahradenie znaku noveho riadku medzerou
        int index;
        for(index = 0; riadok[index] != '\n'; index++);
        riadok[index] = '\0';

        printf("%s, %s", riadok, riadok_druhy);
      }
    }
	// program nenasiel zhodu znakov
    if(naslo_zaznam == false) {
      printf("Not found\n");
    }
}

int main (int argc, char *argv[])
{
    // Bez zadania argumentu vypise cely zoznam kontaktov
    if (argc < 2) {
      char riadok[MAX];
      char riadok_druhy[MAX];
      while(true) {
          if(fgets(riadok, MAX, stdin) == NULL) break;
          if(fgets(riadok_druhy, MAX, stdin) == NULL) break;
          //nahradenie znaku noveho riadku medzerou
          int index;
          for(index = 0; riadok[index] != '\n'; index++);
          riadok[index] = '\0';

          printf("%s, %s", riadok, riadok_druhy);
      }
    }
    // zadany argument, vykovana funkciu vyhladavania
    else search(argv[1]);

    return 0;
}