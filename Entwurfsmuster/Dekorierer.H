class VisuelleKomponente {
public:
	VisuelleKomponente();

	virtual void Zeichne();
	virtual void VeraendereGroesse();
	// ...
};



class Dekorierer : public VisuelleKomponente {
public:
	Dekorierer(VisuelleKomponente*);

	virtual void Zeichne();
	virtual void VeraendereGroesse();
	// ...

private:
	VisuelleKomponente* _komponente;
};



void Dekorierer::Zeichne() {
	_komponente->Zeichne();
}

void Dekorierer::VeraendereGroesse() {
	_komponente->VeraendereGroesse();
}



class RahmenDekorierer : public Dekorierer {
public:
	RahmenDekorierer(VisuelleKomponente*, int rahmenBreite);

	virtual void Zeichne();

private:
	void ZeichneRahmen(int);

private:
	int _breite;
};

void RahmenDekorierer::Zeichne() {
	Dekorierer::Zeichne();
	ZeichneRahmen(_breite);
}



void Fenster::SetzeInhalt(VisuelleKomponente* inhalt) {
	// ...
}

