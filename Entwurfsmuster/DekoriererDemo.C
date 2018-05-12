#include "GrundKlassen/GrundKlassen.H"

class VisuelleKomponente;

class Fenster {
public:
	virtual void SetzeInhalt(VisuelleKomponente*);
};



#include "Dekorierer.H"



class TextAnzeige : public VisuelleKomponente {
};

class ScrollDekorierer : public Dekorierer {
public:
	ScrollDekorierer(VisuelleKomponente*);
};



void DekoriererDemo() {
	Fenster* fenster = new Fenster;
	TextAnzeige* textAnzeige = new TextAnzeige;

	fenster->SetzeInhalt(textAnzeige);

	fenster->SetzeInhalt(
		new RahmenDekorierer(
			new ScrollDekorierer(textAnzeige), 1
		)
	);
}

