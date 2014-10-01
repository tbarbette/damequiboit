#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_BUFLEN   64

static char *cartes[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valet", "Dame", "Roi"};
static char *regles[] = {
          "Tu bois un coup",
          "Carte sur le front !",
          "Le joueur à droite boit un coup",
          "Le joueur à gauche boit un coup",
          "Thumb master",
          "Viking",
          "Statue",
          "Série",
          "Alter ego",
          "Tu donnes un coup",
          "Invente une règle",
          "Les dames boivent",
          "Les hommes boivent"
};

int main() {
          int i, n = 0;
          char **players;
          
          srand(time(NULL));

          // Nombre de joueurs
          printf("Combien de joueurs ?\n");
          scanf("%d", &n);

          // Nom des joueurs
          players = (char **) malloc(sizeof(char *) * n);
          
          for(i = 0; i < n; i++) {
                    printf("Nom du joueur %d: ", i + 1);
                    players[i] = malloc(sizeof(char) * PLAYER_BUFLEN);
                    scanf("%s", players[i]);
          }

          printf("\n");
          getchar();

          // Nombre d'apparence de chaque carte, pour ne pas dépasser 4
          int appearance[13] = {};
          int numcards = 4 * 13;        

          //Partie
          int p = 0;
          char c = getchar();
          while (c != 'q' && numcards > 0) {
                    int c = 0;
                    
                    //Random de la carte
                    do {
                                int i = rand(); 
                                double f = (((double)i / (double)RAND_MAX) * 13);
                                c = (int)f;
                                
                    } while (appearance[c] > 3);
                    
                    appearance[c]++;
                    numcards--;

                    printf("%s pêche un %s\n -> %s\n", players[p % n], cartes[c], regles[c]);
                    p++;
                    c = getchar();
          }
          
          printf("La partie est finie !\n");
          return 0;
}
