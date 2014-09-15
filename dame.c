#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static char* cartes[] = {"1","2","3","4","5","6","7","8","9","10","Valet","Dame","Roi","As"};

void main() {
	srand(time(NULL));
	
	//Nombre de joueurs
	printf("Combien de joueurs?\n");
	int n = 0;
	scanf("%d",&n);
	
	//Nom des joueurs
	char* players[n];	
	for (int i = 0; i < n; i++) {
		printf("Nom du joueur %d : ",i+1);
		players[i] = malloc(sizeof(char) * 64);
    		scanf("%s",players[i]);
	}

	printf("\n");
	fflush(stdin);
	
	//Nombre d'apparence de chaque carte, pour ne pas dépasser 4
	int appearance[13] = {};
	int numcards = 4*13;	

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
    	
	
	    
	
	    char* str;
	    
    	    switch(c + 1) {
		    case 1:
			    str = "Tu bois un coup\n";
			    break;
		    case 2:
			    str = "Carte sur le front !\n";
			    break;
		    case 3:
			    str = "Le joueur à droite boit un coup\n";
			    break;
		    case 4:
			    str = "Le joueur à gauche boit un coup\n";
			    break;
		    case 5:
			    str = "Thumb master\n";
			    break;
		    case 6:
			    str = "Viking\n";
			    break;		
			case 7:
	    		str = "Statue\n";
	    		break;	
			case 8:
	    		str = "Série\n";
	    		break;
			case 9:
	    		str = "Alter ego\n";
	    		break;
			case 10:
	    		str = "Tu donnes un coup\n";
	    		break;
			case 11:
    			str = "Invente une règle\n";
    			break;
			case 12:
    			str = "Les dames boivent\n";
    			break;
    		case 13:
    			str = "Les hommes boivent\n";
    			break;	
	}

	printf("%s pêche un %s : %s\n",players[p % n],cartes[c],str);
	p++;
	c = getchar();
	}
	printf("La partie est finie !\n");
	
}
