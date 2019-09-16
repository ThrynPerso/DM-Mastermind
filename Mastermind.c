#include <stdio.h>
float solution[4]
float playerAnswer[4]
int try

	int main(){
		char reponse[30] = {0};
		printf("Bienvenue dans le jeu de Mastermind !");
   		printf("-------------------------------------");
		printf("Les règles sont simples :");
		printf("Essayez de devinez la combinaison de couleurs");
		printf("Le programme vous diras quand vous misez juste (ou pas)");
		printf("-------------------------------------");
		printf("Vous devez répondre sous la forme 'couleur, couleur, couleur, couleur'");
		printf("Soit 4 couleurs parmis orange, rouge, jaune, bleu et vert");
		printf("Par exemple 'jaune, rouge, vert, vert'");
		printf("-------------------------------------");
		printf("A tout moment, tapez 'SAUVEGARDER' pour enregistrer la partie afin de la reprendre plus tard");
		printf("-------------------------------------");
		printf("Prêt ?");
		printf("1. Commencer une nouvelle partie");
		printf("2. Charger une partie existant");
		scanf("%f", reponse)
		getMenuReponse(reponse)

   return 0;
	}

	int getMenuReponse(char answer){
		char location[200]
		switch(answer) (
			case '1' :
			startNewGame();
			break;
			case '2' :
			printf("Veuillez entrer la localisation du fichier");
			scanf("%c", location);
			loadPartie(location);
			break;
			default :
			printf("Mauvaise entrée !");
			main();
			)
	return 0;
	}

	int loadPartie(char loc){

	}

	int startNewGame(char loc){
		int i
		char rep
		solution[0] = rand() % 5 + 1
		solution[1] = rand() % 5 + 1
		solution[2] = rand() % 5 + 1
		solution[3] = rand() % 5 + 1
		for (i = 0 ; i < 4 ; i++)
		{
		switch(
			case solution[i] = 1
			solution[i] = "jaune"
			break;
			case solution[i] = 2
			solution[i] = "rouge"
			break;
			case solution[i] = 3
			solution[i] = "vert"
			break;
			case solution[i] = 4
			solution[i] = "bleu"
			break;
			case solution[i] = 5
			solution[i] = "orange"
			break;
			)
		}

		printf("-------------------------------------")
		printf("Veuillez rentrez vos couleurs ! Premier essai")
		printf("-------------------------------------")
		scanf("%a", rep)
		checkAnswer(rep)

	return 0;
	}

	char checkAnswer(char rep){
		
	}

	void manche(float previousAnswer){

	}