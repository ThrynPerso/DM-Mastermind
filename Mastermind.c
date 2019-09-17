#include <stdio.h>
#include <string.h>
#include "global.h"

	int main(){
		int reponse;
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

		scanf("%i", &reponse);

		if (reponse == 1)
		{startNewGame();}
		else if (reponse == 2)
		{loadPartie();}
		else
		{printf("\n \nMauvaise entree !\n \n ");
		main();}

   return 0;
	}


	void loadPartie(){
		FILE * savePath = fopen("/saves/sauvegarde.txt", "r");
		char textChar = fgetc(savePath);
		char *token;
		int i = 1;

		token = strtok(textChar, ",");
		while(token != NULL){
			switch(i){
				case 1 :
				x = token;
				break;
				case 2 :
				y = token;
				break;
				case 3 :
				numTries = token;
				break;
				case 4 :
				solution[0] = token;
				break;
				case 5 :
				solution[1] = token;
				break;
				case 6 :
				solution[2] = token;
				break;
				case 7 :
				solution[3] = token;
				break;
			}
		i++;
		}
		manche();
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
	
		printf("-------------------------------------\n");
		printf("Veuillez rentrer vos couleurs ! Premier essai\n");
		printf("-------------------------------------\n");
		scanf("Votre réponse : %s", rep);
		checkAnswer(rep);
	}

	void checkAnswer(char * rep){
		int n;
		int i;
		int j;

		n=0;
		i=0;
		x=0;
		y=0;

		for (j = 0; j < solution; j++)
		{
		if (playerAnswer[n] == solution[i] && n == i)
		{
		x++;
		}
		n++;
		i++;
		}
		printf("Couleur existants et bien placées: %d",x);


		n=0;
		i=0;
		for (j = 0; j < solution; j++)
		{
		if (playerAnswer[n] == solution[i] && n != i)
		{
		y++;
		}
		n++;
		i++;
		}
		printf("Couleur existantes mais mal placées : %d",y);
		numTries++;
		manche();
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

	void manche(){
		char theAnswer[40];
		scanf("votre réponse (couleur,couleur,couleur,couleur) : %s", theAnswer);
		checkAnswer(theAnswer);
	}