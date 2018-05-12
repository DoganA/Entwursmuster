class LabyrinthSpiel {
public:
	Labyrinth* ErzeugeLabyrinth();

	// Die Fabrikmethoden:
	virtual Labyrinth* ErzeugeLabyrinth() const
		{ return new Labyrinth; }
	virtual Raum* ErzeugeRaum(int raumNr) const
		{ return new Raum(raumNr); }
	virtual Wand* ErzeugeWand() const
		{ return new Wand; }
	virtual Tuer* ErzeugeTuer(Raum* raum1, Raum* raum2) const
		{ return new Tuer(raum1, raum2); }
};



Labyrinth* LabyrinthSpiel::ErzeugeLabyrinth() {
	Labyrinth* einLabyrinth = ErzeugeLabyrinth();

	Raum* raum1 = ErzeugeRaum(1);
	Raum* raum2 = ErzeugeRaum(2);
	Tuer* dieTuer = ErzeugeTuer(raum1, raum2);

	einLabyrinth->FuegeRaumHinzu(raum1);
	einLabyrinth->FuegeRaumHinzu(raum2);

	raum1->SetzeSeite(Norden, ErzeugeWand());
	raum1->SetzeSeite(Osten, dieTuer);
	raum1->SetzeSeite(Sueden, ErzeugeWand());
	raum1->SetzeSeite(Westen, ErzeugeWand());

	raum2->SetzeSeite(Norden, ErzeugeWand());
	raum2->SetzeSeite(Osten, ErzeugeWand());
	raum2->SetzeSeite(Sueden, ErzeugeWand());
	raum2->SetzeSeite(Westen, dieTuer);

	return einLabyrinth;
}



class LabyrinthMitBombenSpiel : public LabyrinthSpiel {
public:
	LabyrinthMitBombenSpiel();

	virtual Wand* ErzeugeWand() const
		{ return new BombardierbareWand; }

	virtual Raum* ErzeugeRaum(int raumNr) const
		{ return new RaumMitBombe(raumNr); }
};



class VerzaubertesLabyrinthSpiel : public LabyrinthSpiel {
public:
	VerzaubertesLabyrinthSpiel();

	virtual Raum* ErzeugeRaum(int raumNr) const
		{ return new VerzauberterRaum(raumNr,
				BenoetigterZauberspruch()); }

	virtual Tuer* ErzeugeTuer(Raum* raum1, Raum* raum2) const
		{ return new TuerMitZauberspruch(raum1, raum2); }

protected:
	Zauberspruch* BenoetigterZauberspruch() const;
};


