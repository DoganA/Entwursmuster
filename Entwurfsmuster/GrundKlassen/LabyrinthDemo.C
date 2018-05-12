#include "LabyrinthDefs.H"



class LabyrinthSpiel {
public:
	Labyrinth* ErzeugeLabyrinth();
};



Labyrinth* LabyrinthSpiel::ErzeugeLabyrinth() {
	Labyrinth* einLabyrinth = new Labyrinth;
	Raum* raum1 = new Raum(1);
	Raum* raum2 = new Raum(2);
	Tuer* dieTuer = new Tuer(raum1, raum2);

	einLabyrinth->FuegeRaumHinzu(raum1);
	einLabyrinth->FuegeRaumHinzu(raum2);

	raum1->SetzeSeite(Norden, new Wand);
	raum1->SetzeSeite(Osten, dieTuer);
	raum1->SetzeSeite(Sueden, new Wand);
	raum1->SetzeSeite(Westen, new Wand);

	raum2->SetzeSeite(Norden, new Wand);
	raum2->SetzeSeite(Osten, new Wand);
	raum2->SetzeSeite(Sueden, new Wand);
	raum2->SetzeSeite(Westen, dieTuer);

	return einLabyrinth;
}

