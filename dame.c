#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFLEN          64
#define N_DIFF_CARTES   13
#define N_CARTES        N_DIFF_CARTES * 4

typedef struct {
    char *nom;
    char *regle;
} carte_t;

static const carte_t cartes[N_DIFF_CARTES] = {
      { "As",           "Tu bois un coup" }
    , { "2",            "Carte sur le front !" }
    , { "3",            "Le joueur à droite boit un coup" }
    , { "4",            "Le joueur à gauche boit un coup" }
    , { "5",            "Thumb master" }
    , { "6",            "Viking" }
    , { "7",            "Statue" }
    , { "8",            "Série" }
    , { "9",            "Alter ego" }
    , { "10",           "Tu donnes un coup" }
    , { "Valet",        "Invente une règle" }
    , { "Dame",         "Les dames boivent" }
    , { "Roi",          "Les hommes boivent" }
};

void swap(const carte_t **ptr1, const carte_t **ptr2)
{
    const carte_t *tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}

int main()
{
    int n_joueurs = 0;
    char **joueurs;

    {
        char buffer[BUFLEN];

        // Nombre de joueurs

        do {
            printf("Combien de joueurs ?\n");
            while (!fgets(buffer, sizeof buffer, stdin));

            n_joueurs = atoi(buffer);
        } while (n_joueurs <= 0);

        // Nom des joueurs

        joueurs = (char **) malloc(sizeof (char *) * n_joueurs);

        for (int i = 0; i < n_joueurs; i++) {
            printf("Nom du joueur %d: ", i + 1);
            while (!fgets(buffer, sizeof buffer, stdin));

            int n_bytes = strlen(buffer);
            joueurs[i] = malloc(sizeof (char) * n_bytes);
            strncpy(joueurs[i], buffer, n_bytes);
        }
    }

    printf("\n");

    // Construit un vecteur de N_CARTES cartes. Il va permettre de reconnaitre
    // les cartes déjà tirées des cartes non tirées et simulera une réelle
    // distribution.

    const carte_t *tas_cartes[N_CARTES];

    for (int i = 0; i < N_DIFF_CARTES; i++) {
        for (int j = 0; j < 4; j++) {
            tas_cartes[i * 4 + j] = &cartes[i];
        }
    }

    // Partie

    {
        int n_cartes_restantes = N_CARTES
          , joueur             = 0;

        srand(time(NULL));

        while (n_cartes_restantes > 0) {
            {
                char c = getchar();
                if (c == 'q')
                    break;
            }

            // Sélectionne la carte.

            int i = rand() % n_cartes_restantes;
            const carte_t *carte = tas_cartes[i];

            printf(
                "%s pêche un %s\n -> %s\n",
                joueurs[joueur], carte->nom, carte->regle
            );

            // Retire la carte du tas.
            swap(&tas_cartes[i], &tas_cartes[n_cartes_restantes - 1]);
            n_cartes_restantes--;

            joueur = (joueur + 1) % n_joueurs;
        }

        printf("La partie est finie !\n");
    }

    return 0;
}
