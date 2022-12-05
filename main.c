#include <stdio.h>
#include <stdlib.h>

void spielfeld(int zug, char spielfeld[]);
void abbruch (char feld []);

int main() {
    //zweidimensionaler Array
    char feld[3 * 3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (int zug = 1; zug<=9;zug++) {
        int positon;
        int zähler;
        spielfeld(zug, feld);
        do {
            if (zähler > 0) printf("Diese Eingabe ist ungueltig, bitte versuche es erneut!\n");

            scanf("%d", &positon);
            zähler++;
        } while (feld[positon-1] == 'X' || feld[positon-1] == 'O' && positon<0 || positon>9);
        zähler = 0;

        if (zug%2) //Spieler 1
            feld[positon-1] = 'X'; //zug-1, da die Werte im char feld um eins verschoben wurden

        if (zug%2 == 0 && feld[positon-1] != 'O') //Spieler 2
            feld[positon-1] = 'O';
        
        //prüft mögliche Abbruchbedienungen (Sieg)
        abbruch(feld);
    }
    printf("Alle Zuege sind aufgebraucht, es konnte kein Gewinner ermittelt werden!");
    return 0;
}

//in dieser Funktion wird das Spielfeld ausgegeben
void spielfeld(int zug, char spielfeld[]){
    //durch die vielen Zeilenumbrüche wird das alte Feld "gelöscht"
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Willkommen bei TicTacToe!\n");
    printf("Spieler eins ist X und Spieler zwei O\n\n");

    if (zug%2 == 0) {
        printf("Spieler zwei (0) ist am Zug!\n");
    } else
        printf("Spieler eins (X) ist am Zug!\n");

    printf(" %c | %c | %c \n", spielfeld[0],spielfeld[1],spielfeld[2]);
    printf("------------\n");
    printf(" %c | %c | %c \n", spielfeld[3],spielfeld[4],spielfeld[5]);
    printf("------------\n");
    printf(" %c | %c | %c \n", spielfeld[6],spielfeld[7],spielfeld[8]);
}

//abfragen, ob eine Sieg-Situation vorliegt
void abbruch (char feld []){
    //abfragen, ob eine Sieg-Situation vorliegt Waagerecht
    for (int i = 0; i < 9; i += 3) {
        //Sieg für X bei Waagerecht
        if (feld[i] == 'X' && feld[i+1] == 'X' && feld[i+2] == 'X'){
            printf("Herzlichen Glueckwunsch, X hat gewonnen!");
            exit(0);
        }
        //Sieg für O bei Waagerecht
        if (feld[i] == 'O' && feld[i+1] == 'O' && feld[i+2] == 'O'){
            printf("Herzlichen Glueckwunsch, X hat gewonnen!");
            exit(0);
        }
    }
    //abfragen, ob eine Sieg-Situation vorliegt Senkrecht
    for (int i = 0; i < 3; ++i) {
        //Sieg für X bei Senkrecht
        if (feld[i] == 'X' && feld[i+3] == 'X' && feld[i+6] == 'X'){
            printf("Herzlichen Glueckwunsch, X hat gewonnen!");
            exit(0);
        }
        //Sieg für O bei Senkrecht
        if (feld[i] == 'O' && feld[i+3] == 'O' && feld[i+6] == 'O'){
            printf("Herzlichen Glueckwunsch, X hat gewonnen!");
            exit(0);
        }
    }
    //abfrage Sieg für X bei Quer von oben links nach unten recht
    if (feld[0] == 'X' && feld[4] == 'X' && feld[8] == 'X'){
        printf("Herzlichen Glueckwunsch, X hat gewonnen!");
        exit(0);
    }
    //abfrage Sieg für O bei Quer von oben links nach unten recht
    if (feld[0] == 'O' && feld[4] == 'O' && feld[8] == 'O'){
        printf("Herzlichen Glueckwunsch, X hat gewonnen!");
        exit(0);
    }
    //abfrage Sieg für X bei Quer von oben links nach unten recht
    if (feld[2] == 'X' && feld[4] == 'X' && feld[8] == 'X'){
        printf("Herzlichen Glueckwunsch, X hat gewonnen!");
        exit(0);
    }
    //abfrage Sieg für O bei Quer von oben links nach unten recht
    if (feld[2] == 'O' && feld[4] == 'O' && feld[8] == 'O'){
        printf("Herzlichen Glueckwunsch, X hat gewonnen!");
        exit(0);
    }
    return;
}