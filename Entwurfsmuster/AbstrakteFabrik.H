class LabyrinthFabrik {
public:
	LabyrinthFabrik();

	virtual Labyrinth* ErzeugeLabyrinth() const
		{ return new Labyrinth; }
	virtual Wand* ErzeugeWand() const
		{ return new Wand; }
	virtual Raum* ErzeugeRaum(int n) const
		{ return new Raum(n); }
	virtual Tuer* ErzeugeTuer(Raum* raum1, Raum* raum2) const
		{ return new Tuer(raum1, raum2); }
};



Labyrinth* LabyrinthSpiel::ErzeugeLabyrinth(LabyrinthFabrik& fabrik) {
	Labyrinth* einLabyrinth = fabrik.ErzeugeLabyrinth();
	Raum* raum1 = fabrik.ErzeugeRaum(1);
	Raum* raum2 = fabrik.ErzeugeRaum(2);
	Tuer* eineTuer = fabrik.ErzeugeTuer(raum1, raum2);

	einLabyrinth->FuegeRaumHinzu(raum1);
	einLabyrinth->FuegeRaumHinzu(raum2);

	raum1->SetzeSeite(Norden, fabrik.ErzeugeWand());
	raum1->SetzeSeite(Osten, eineTuer);
	raum1->SetzeSeite(Sueden, fabrik.ErzeugeWand());
	raum1->SetzeSeite(Westen, fabrik.ErzeugeWand());

	raum2->SetzeSeite(Norden, fabrik.ErzeugeWand());
	raum2->SetzeSeite(Osten, fabrik.ErzeugeWand());
	raum2->SetzeSeite(Sueden, fabrik.ErzeugeWand());
	raum2->SetzeSeite(Westen, eineTuer);
}



class VerzaubertesLabyrinthFabrik : public LabyrinthFabrik {
public:
	VerzaubertesLabyrinthFabrik();

	virtual Raum* ErzeugeRaum(int n) const
		{ return new VerzauberterRaum(n, BenoetigterZauberspruch()); }

	virtual Tuer* ErzeugeTuer(Raum* raum1, Raum* raum2) const
		{ return new TuerMitZauberspruch(raum1, raum2); }

protected:
	Zauberspruch* BenoetigterZauberspruch() const;
};

