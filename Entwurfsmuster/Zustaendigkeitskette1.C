class HilfeBearbeiter {
public:
	HilfeBearbeiter(HilfeBearbeiter* nf) :
		_nachfolger(nf) {}
	virtual void BearbeiteHilfsanfrage();

private:
	HilfeBearbeiter* _nachfolger;
};

void HilfeBearbeiter::BearbeiteHilfsanfrage() {
	if (_nachfolger) {
		_nachfolger->BearbeiteHilfsanfrage();
	}
}



class Anfrage {
public:
	// nicht gerade die feine Art..
	enum { Hilfe, Drucken, Vorschau } GibTyp();
};

class HilfsAnfrage : public Anfrage {};
class DruckAnfrage : public Anfrage {};

class Bearbeiter {
public:
	virtual void BearbeiteAnfrage(Anfrage*);

protected:
	virtual void BearbeiteHilfsAnfrage(HilfsAnfrage*);
	virtual void BearbeiteDruckAnfrage(DruckAnfrage*);
};

void Bearbeiter::BearbeiteAnfrage(Anfrage* dieAnfrage) {
	switch (dieAnfrage->GibTyp()) {
	case Hilfe:
		// caste Argument auf richtige Klasse
		BearbeiteHilfsAnfrage((HilfsAnfrage*) dieAnfrage);
		break;

	case Drucken:
		BearbeiteDruckAnfrage((DruckAnfrage*) dieAnfrage);
		// ...
		break;

	default:
		// ...
		break;
	}
}



class ErweiterterBearbeiter : public Bearbeiter {
public:
	virtual void BearbeiteAnfrage(Anfrage* dieAnfrage);
	// ...
};

void ErweiterterBearbeiter::BearbeiteAnfrage(Anfrage* dieAnfrage) {
	switch(dieAnfrage->GibTyp()) {
	case Vorschau:
		// bearbeite die Vorschauanfrage
		break;

	default:
		// lass die Bearbeiterklasse weitere Anfragen bearbeiten
		Bearbeiter::BearbeiteAnfrage(dieAnfrage);
		break;
	}
}


