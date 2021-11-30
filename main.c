#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int rows = 5;
int cols = 5;

void print_arr(int arr[rows][cols]) {
    // Gehe das Array Reihe für reihe durch und gebe es aus.
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("|%i\t", arr[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int check_horizontal(int arr[rows][cols]) {
    // Gehe das Array durch und Teste vertical
    // Beim ersten Fehler springe sofort in die Nächste Reihe da hier kein bingo besteht.
    // Bei 5 Treffern sende return 1. Es besteht ein Bingo
    int i, j;
    int c = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                c++;
                if (c == 5) {
                    return 1;
                }
            } else {
                c = 0;
                j = cols;
            }
        }
    }
    return 0;
}

int check_vertical(int arr[rows][cols]) {
    // Gehe das Array durch und Teste vertical
    // Beim ersten Fehler springe sofort in die Nächste Spalte da hier kein bingo besteht.
    // Bei 5 Treffern sende return 1. Es besteht ein Bingo
    int i, j;
    int c = 0;
    for (j = 0; j < rows; j++) {
        for (i = 0; i < cols; i++) {
            if (arr[i][j] == 0) {
                c++;
                if (c == 5) {
                    return 1;
                }
            } else {
                c = 0;
                j = cols;
            }
        }
    }
    return 0;
}

int check_dia(int arr[rows][cols]) {
    // Gehe das Array durch und Teste ob ein Diagonaler Treffer ist
    // Da dies nur an einer Stelle der Fall sein kann sende Return 0 beim ersten fehler
    // Bei 5 Treffern sende return 1 Es besteht ein Bingo
    int i, j;
    int c = 0;
    for (j = 0, i = 0; j < rows, i < cols; j++, i++) {
        if (arr[i][j] == 0) {
            c++;
            if (c == 5) {
                return 1;
            }
        } else {
            return 0;
        }
    }
    return 0;
}

void shuffle(int zahlen[], int N) {
    // Lade Zahlen in Array bis größe N
    // So existiert jede Zahl nur einmal
    for (int i = 0; i <= N - 1; i++) {
        zahlen[i] = i + 1;
    }

    //Mische da Zahlen
    for (int i = 0; i < N - 1; ++i) {

        int j = rand() % (N - i) + i;
        int temp = zahlen[i];
        zahlen[i] = zahlen[j];
        zahlen[j] = temp;
    }
}

int main() {
    // N = Reichweite der Zahlen auf der Bingo Karte
    int N = 90;
    int zahlen[N];
    int playAgain = 0;
    srand((unsigned) time(NULL));

    while(playAgain == 0) {
        int winCon = 0;
        shuffle(zahlen, N);

        //Setzte gemische Zahlen in unser 2d Array ein
        int arr[rows][cols];
        int i, j;
        int c = 0;
        N = 0;
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++, N++) {
                arr[i][j] = zahlen[N];
            }
        }

        // Setzte das mittlere Feld auf 0 da dies immer frei ist
        arr[2][2] = 0;
        N = 90;
        int winner[N];
        shuffle(winner, N);


        //Solange die Sieges bedingung nicht erfüllt ist Spiele die Runde
        while (winCon == 0) {
            // Gebe die Bingo Karte aus
            print_arr(arr);

            printf("Ziehe n\204chste Zahl? \n");
            getch();

            printf("Es wurde: %i gezogen\n", winner[c]);
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (arr[i][j] == winner[c]) {
                        arr[i][j] = 0;
                        printf("Treffer!\n"
                               "");
                        // Überprüfe ob Treffer gefunden
                        if (check_horizontal(arr) == 1 || check_vertical(arr) == 1 || check_dia(arr) == 1) {
                            print_arr(arr);
                            printf("BINGO!\nSIE HABEN GEWONNEN!");
                            winCon = 1;
                            j = cols;
                            i = rows;
                        }
                    }

                }
            }
            c++;
        }
        printf("\nNochmal spielen? " );
        int ant;
        scanf("%i", &ant);
        switch(ant){
            case 0: playAgain = 0;
            break;
            case 1: playAgain = 1;
            break;
            default:
                break;
        }
    }

    return 0;
}
