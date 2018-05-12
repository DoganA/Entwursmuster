class Kompositum;

class Komponente {
public:
	// ...
	virtual Kompositum* GibKompositum() { return 0; }
};

class Kompositum : public Komponente {
public:
	void FuegeHinzu(Komponente*);
	// ...
	virtual Kompositum* GibKompositum() { return this; }
};

class Blatt : public Komponente {
	// ...
};



void Kompositum1Demo() {
	Kompositum* einKompositum = new Kompositum;
	Blatt* einBlatt = new Blatt;

	Komponente* eineKomponente;
	Kompositum* einTest;

	eineKomponente = einKompositum;
	einTest = eineKomponente->GibKompositum();
	if (einTest != 0) {
		einTest->FuegeHinzu(new Blatt);
	}

	eineKomponente = einBlatt;
	einTest = eineKomponente->GibKompositum();
	if (einTest != 0) {
		// wird nicht ausgefuehrt
		einTest->FuegeHinzu(new Blatt);
	}
}


