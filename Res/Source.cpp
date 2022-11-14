#include <iostream>
#include <string>
#include "Emetteur.h"

int main()
{
	Recepteur* liste;
	int listeLength = 0;
	int numCanAdd = 0;
	bool exec = true;
	Emetteur* e1 = new Emetteur();
	Emetteur* e2 = new Emetteur();
	

	
	Recepteur* r1 = new Recepteur();
	Recepteur* r2 = new Recepteur();
	Recepteur* r3 = new Recepteur();

	e1->diffuser("Allo", 1);
	e2->diffuser("Je suis un autre emetteur", 1);
	e2->diffuser("Vous ne m'entendez pas", 4);
	e1->diffuser("Trop bien, regardez les métérorites !!!", 2);
	r1->lire(2);
	r1->sAbonner(2);
	r2->sAbonner(1);
	r3->sAbonner(1);
	r3->lire(4);
	delete r3;
	r1->lire(2);
	e1->diffuser("Allez les bleus !!!!", 1);
	r1->lire(1);
	e1->diffuser("C'est la fin", 3);
	r2->lire(1);
	r2->lire(3);


	delete r1;
	delete r2;
	

	int pause;
	double i;
	Recepteur* r;
	for (i = 0; i < 10000; i++)
	{
		r = new Recepteur();
		delete r;
	}
	std::cin >> pause;

}