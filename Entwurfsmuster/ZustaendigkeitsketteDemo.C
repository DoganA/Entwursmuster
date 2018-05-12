#include "GrundKlassen/GrundKlassen.H"



#include "Zustaendigkeitskette.H"



void ZustaendigkeitsketteDemo() {
	const Thema DRUCK_THEMA = 1;
	const Thema PAPIER_ORIENTIERUNGS_THEMA = 2;
	const Thema ANWENDUNGS_THEMA = 3;

	Anwendung* anwendung = new Anwendung(ANWENDUNGS_THEMA);
	Dialog* dialog = new Dialog(anwendung, DRUCK_THEMA);
	Knopf* knopf = new Knopf(dialog, PAPIER_ORIENTIERUNGS_THEMA);

	knopf->BearbeiteHilfsanfrage();
}

