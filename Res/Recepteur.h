#pragma once
#include <iostream>
#include <string>


typedef void (*evt)(std::string, int);
extern evt e;

typedef struct Messages
{
	std::string contenu;
	int canal;
	struct Messages* next = NULL;
}Mes;

class Recepteur
{
private :
	static Mes* message_attente;
	static Mes* mes_temp;
	int* canaux;
	int nbCanauxTot;
public:
	Recepteur(void);
	Recepteur(int);
	~Recepteur(void);

	static void ecouter(std::string, int);
	void lire(int);
	void sAbonner(int);
};

