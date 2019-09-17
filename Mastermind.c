#include <stdio.h>
#include <string.h>
#include "global.h"

	int main(){
		int reponseToInt;
		char reponse[30] = {0};
		printf("Bienvenue dans le jeu de Mastermind !\n");
   		printf("-------------------------------------\n");
		printf("Les regles sont simples :\n");
		printf("Essayez de devinez la combinaison de couleurs\n");
		printf("Le programme vous diras quand vous misez juste (ou pas)\n");
		printf("-------------------------------------\n");
		printf("Vous devez repondre sous la forme 'couleur, couleur, couleur, couleur'\n");
		printf("Soit 4 couleurs parmis orange, rouge, jaune, bleu et vert\n");
		printf("Par exemple 'jaune, rouge, vert, vert'\n");
		printf("-------------------------------------\n");
		printf("A tout moment, tapez 'SAUVEGARDER' pour enregistrer la partie afin de la reprendre plus tard\n");
		printf("-------------------------------------\n");
		printf("Pret ?\n");
		printf("1. Commencer une nouvelle partie\n");
		printf("2. Charger une partie existant\n");
		scanf("%f", reponse);
		reponseToInt = reponse - '0';
		getMenuReponse(reponseToInt);

   return 0;
	}

	void getMenuReponse(int answer){
		char location[200];
		switch(answer) {
			case 1 :
			startNewGame();
			break;
			case 2 :
			loadPartie();
			break;
			default :
			printf("Mauvaise entrée !");
			main();
			};
	return 0;
	}

	void loadPartie(){

	}

	void startNewGame(){
		int i;
		char rep[40];
		solution[0] = rand() % 5 + 1;
		solution[1] = rand() % 5 + 1;
		solution[2] = rand() % 5 + 1;
		solution[3] = rand() % 5 + 1;
		for (i = 0 ; i < 4 ; i++)
		{
		switch (solution[i]){
			case 1 :
			solution[i] = "jaune";
			break;
			case 2 :
			solution[i] = "rouge";
			break;
			case 3 :
			solution[i] = "vert";
			break;
			case 4 :
			solution[i] = "bleu";
			break;
			case 5 :
			solution[i] = "orange";
			break;
			};
		}
	
		printf("-------------------------------------");
		printf("Veuillez rentrer vos couleurs ! Premier essai");
		printf("-------------------------------------");
		scanf("%a", rep);
		checkAnswer(rep);

	;
	}

	void checkAnswer(char * rep){
		
	}

	void saveFile(char rep){
		char saveData[150];
		FILE * savePath = fopen("/saves/sauvegarde.txt", "w");
		strcpy(saveData, x);
		strcat(saveData, ",");
		strcat(saveData, y);
		strcat(saveData, ",");
		strcat(saveData, numTries);
		strcat(saveData, ",");
		strcat(saveData, solution[0]);
		strcat(saveData, ",");
		strcat(saveData, solution[1]);
		strcat(saveData, ",");
		strcat(saveData, solution[2]);
		strcat(saveData, ",");
		strcat(saveData, solution[3]);

		fputs(saveData, savePath);
		fclose(savePath);
		printf("--------------------");
		printf("Fichier sauvegardé !");
		printf("--------------------");
	}

	void manche(float previousAnswer){
		char theAnswer[40];
		scanf("votre réponse (couleur,couleur,couleur,couleur) : %a", theAnswer);
		checkAnswer(theAnswer);
	}