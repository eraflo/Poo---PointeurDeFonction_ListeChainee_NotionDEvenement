#include "Recepteur.h"

evt e;
Mes* Recepteur::message_attente = NULL;
Mes* Recepteur::mes_temp = NULL;

Recepteur::Recepteur(void)
{
	std::cout << "Création du poste " << this << std::endl;
	e = &Recepteur::ecouter;
	nbCanauxTot = 0;
}

Recepteur::Recepteur(int nbCanaux)
{
	std::cout << "Création du poste " << this << std::endl;

	e = &Recepteur::ecouter;
	this->nbCanauxTot = nbCanaux;
	this->canaux = new int[nbCanaux];


	for (int i = 0; i < nbCanaux; i++)
	{
		int choix;
		std::cout << "Quel est le numéro du " + std::to_string(i+1)
			+ " canal auquel s'abonner ? : ";
		std::cin >> choix;
		std::cout << std::endl;
		this->canaux[i] = choix;
	}
}


Recepteur::~Recepteur(void)
{
	delete[] this->canaux;
	std::cout << "Supression des abonnements canaux du poste " << this << std::endl;
}


void Recepteur::ecouter(std::string mes, int canal)
{
	Mes* message = new Mes();
	message->contenu = mes;
	message->canal = canal;
	message->next = NULL;
	if (message_attente == NULL)
	{
		mes_temp = message;
		message_attente = mes_temp;
	}
	else
	{
		mes_temp->next = message;
		mes_temp = mes_temp->next;
	}
}

void Recepteur::lire(int canal)
{
	bool present = false;
	for (int i = 0; i < this->nbCanauxTot; i++)
	{
		if (this->canaux[i] == canal)
		{
			present = true;
		}
	}

	if (present == true)
	{
		std::cout << "Lecture du canal " << std::to_string(canal) << " sur le poste " << this << std::endl;
		Mes* tmp = message_attente;
		while (tmp != NULL)
		{
			if (tmp->canal == canal)
			{
				std::cout << tmp->contenu << std::endl;
			}
			tmp = tmp->next;
		}
	}
	else
	{
		std::cout << "Le poste " << this << " n'est pas abonné au canal " << std::to_string(canal) << ". Lecture impossible..." << std::endl;
	}
}

void Recepteur::sAbonner(int nbCanaux)
{
	std::cout << "Abonnement pour le poste " << this << std::endl;
	if (this->nbCanauxTot == 0)
	{
		this->canaux = new int[nbCanaux];
	}
	for (int i = this->nbCanauxTot; i < this->nbCanauxTot + nbCanaux; i++)
	{
		int choix;
		std::cout << "Quel est le numéro du " + std::to_string(i + 1)
			+ " canal auquel s'abonner ? : ";
		std::cin >> choix;
		std::cout << std::endl;
		this->canaux[i] = choix;
	}
	this->nbCanauxTot += nbCanaux;
}