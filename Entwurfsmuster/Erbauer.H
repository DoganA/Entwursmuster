class LabyrinthErbauer {
public:
	virtual void BaueLabyrinth() {}
	virtual void BaueRaum(int raumNr) {}
	virtual void BaueTuer(int vonRaumNr, int nachRaumNr) {}

	virtual Labyrinth* GibLabyrinth() { return 0; }

protected:
	LabyrinthErbauer();
};



Labyrinth* LabyrinthSpiel::ErzeugeLabyrinth(
	LabyrinthErbauer& erbauer)
{
	erbauer.BaueLabyrinth();

	erbauer.BaueRaum(1);
	erbauer.BaueRaum(2);
	erbauer.BaueTuer(1, 2);

	return erbauer.GibLabyrinth();
}



Labyrinth* LabyrinthSpiel::ErzeugeKomplexesLabyrinth(
	LabyrinthErbauer& erbauer)
{
	erbauer.BaueRaum(1);
	// ...
	erbauer.BaueRaum(1001);

	return erbauer.GibLabyrinth();
}



class StandardLabyrinthErbauer : public LabyrinthErbauer {
public:
	StandardLabyrinthErbauer();

	virtual void BaueLabyrinth();
	virtual void BaueRaum(int raumNr);
	virtual void BaueTuer(int vonRaumNr, int nachRaumNr);

	virtual Labyrinth* GibLabyrinth();

private:
	Richtung GemeinsameWand(Raum*, Raum*);
	Labyrinth* _aktuellesLabyrinth;
};



StandardLabyrinthErbauer::StandardLabyrinthErbauer() {
	_aktuellesLabyrinth = 0;
}

void StandardLabyrinthErbauer::BaueLabyrinth() {
	_aktuellesLabyrinth = new Labyrinth;
}

Labyrinth* StandardLabyrinthErbauer::GibLabyrinth() {
	Labyrinth* labyrinth = _aktuellesLabyrinth;
	return labyrinth;
}

void StandardLabyrinthErbauer::BaueRaum(int raumNr) {
	if (!_aktuellesLabyrinth->RaumNr(raumNr)) {
		Raum* raum = new Raum(raumNr);
		_aktuellesLabyrinth->FuegeRaumHinzu(raum);

		raum->SetzeSeite(Norden, new Wand);
		raum->SetzeSeite(Sueden, new Wand);
		raum->SetzeSeite(Osten, new Wand);
		raum->SetzeSeite(Westen, new Wand);
	}
}

void StandardLabyrinthErbauer::BaueTuer(int raumNr1, int raumNr2) {
	Raum* raum1 = _aktuellesLabyrinth->RaumNr(raumNr1);
	Raum* raum2 = _aktuellesLabyrinth->RaumNr(raumNr2);
	Tuer* tuer = new Tuer(raum1, raum2);

	raum1->SetzeSeite(GemeinsameWand(raum1, raum2), tuer);
	raum2->SetzeSeite(GemeinsameWand(raum2, raum1), tuer);
}



class ZaehlenderLabyrinthErbauer : public LabyrinthErbauer {
public:
	ZaehlenderLabyrinthErbauer();

	virtual void BaueLabyrinth();
	virtual void BaueRaum(int);
	virtual void BaueTuer(int, int);
	virtual void FuegeWandHinzu(int, Richtung);

	void GibAnzahl(int&, int&) const;

private:
	int _tueren;
	int _raeume;
};

ZaehlenderLabyrinthErbauer::ZaehlenderLabyrinthErbauer() {
	_raeume = _tueren = 0;
}

void ZaehlenderLabyrinthErbauer::BaueRaum(int) {
	_raeume++;
}

void ZaehlenderLabyrinthErbauer::BaueTuer(int, int) {
	_tueren++;
}

void ZaehlenderLabyrinthErbauer::GibAnzahl(int& raeume,
	int& tueren) const
{
	raeume = _raeume;
	tueren = _tueren;
}


