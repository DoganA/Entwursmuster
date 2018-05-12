#include "GrundKlassen/LabyrinthDefs.H"

class LabyrinthErbauer;

class LabyrinthSpiel {
public:
	Labyrinth* ErzeugeLabyrinth(LabyrinthErbauer&);
	Labyrinth* ErzeugeKomplexesLabyrinth(LabyrinthErbauer&);
};



#include "Erbauer.H"



void ErbauerDemo() {
	int raeume, tueren;
	LabyrinthSpiel spiel;
	ZaehlenderLabyrinthErbauer erbauer;

	spiel.ErzeugeLabyrinth(erbauer);
	erbauer.GibAnzahl(raeume, tueren);

	cout << "Das Labyrinth verfuegt ueber "
		<< raeume << " Raeume und "
		<< tueren << "Tueren." << endl;
}


