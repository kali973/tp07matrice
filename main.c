#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAB_MAX 3

#define TRUE    1

int main(int argc, char *argv[]) {

    char rep[100];
    int matrice01[TAB_MAX][TAB_MAX] = {0}, matrice02[TAB_MAX][TAB_MAX] = {0}, resultat[TAB_MAX][TAB_MAX] = {0};

    while (TRUE) {

        printf("\nIndiquez l'opération a effectuer [Quit/Aff/Mult/lire/Random] => ");
        scanf("%s", rep);

        switch (rep[0]) {
            case 'q':
            case 'Q':
                exit(0);
            case 'r':
            case 'R':

                srand(time(NULL));

                int ligne;
                for (ligne = 0; ligne < TAB_MAX; ligne++) {
                    int colonne;
                    for (colonne = 0; colonne < TAB_MAX; colonne++) {
                        matrice01[ligne][colonne] = rand() % 10 + 1;
                        matrice02[ligne][colonne] = rand() % 10 + 1;
                    }
                }
                printf("\nImplementation matrice A and B done , make option A to show them\n");
                break;
            case 'a':
            case 'A':

                printf("Première matrice\n");
                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");
                for (int ligne = 0; ligne < TAB_MAX; ligne++) {
                    printf("|");
                    for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                        printf("%10d|", matrice01[ligne][colonne]);
                    }
                    printf("\n");
                }
                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");
                printf("Deuxième matrice\n");

                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");
                for (int ligne = 0; ligne < TAB_MAX; ligne++) {
                    printf("|");
                    for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                        printf("%10d|", matrice02[ligne][colonne]);
                    }
                    printf("\n");
                }
                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");

                break;

            case 'l':
            case 'L':

                printf("Entrez les éléments de la première matrice carrée de dimension : %d \n", TAB_MAX);
                int colonne;
                for (ligne = 0; ligne < TAB_MAX; ligne++) {
                    for (colonne = 0; colonne < TAB_MAX; colonne++) {
                        scanf("%d", &matrice01[ligne][colonne]);
                    }
                }

                printf("Entrez les éléments de la première matrice carrée de dimension : %d \n", TAB_MAX);
                for (ligne = 0; ligne < TAB_MAX; ligne++) {
                    for (colonne = 0; colonne < TAB_MAX; colonne++) {
                        scanf("%d", &matrice02[ligne][colonne]);
                    }
                }
                break;

            case 'm':
            case 'M':
                // Initialisation matrice résultat
                for (int i = 0; i < TAB_MAX; i++) {
                    for (int j = 0; j < TAB_MAX; j++) {
                        for (int k = 0; k < TAB_MAX; k++) {
                            resultat[i][j] = 0;
                        }
                    }
                }
                // Multiplication matrice A * matrice B
                for (int i = 0; i < TAB_MAX; i++) {
                    for (int j = 0; j < TAB_MAX; j++) {
                        for (int k = 0; k < TAB_MAX; k++) {
                            resultat[i][j] += matrice01[i][k] * matrice02[k][j];
                        }
                    }
                }

                printf("Matrice résultat\n");

                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");
                for (int ligne = 0; ligne < TAB_MAX; ligne++) {
                    printf("|");
                    for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                        printf("%10d|", resultat[ligne][colonne]);
                    }
                    printf("\n");
                }
                printf("+");
                for (int colonne = 0; colonne < TAB_MAX; colonne++) {
                    printf("----------+");
                }
                printf("\n");

                break;
            default:
                printf("Choix incorrect !\n");
        }
    }
}
