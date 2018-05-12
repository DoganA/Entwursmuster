class LabyrinthPrototypFabrik : public LabyrinthFabrik {
public:
	LabyrinthPrototypFabrik(Labyrinth*, Wand*, Raum*, Tuer*);

	virtual Labyrinth* ErzeugeLabyrinth() const;
	virtual Raum* ErzeugeRaum(int) const;
	virtual Wand* ErzeugeWand() const;
	virtual Tuer* ErzeugeTuer(Raum*, Raum*) const;

private:
	Labyrinth* _prototypLabyrinth;
	Raum* _prototypRaum;
	Wand* _prototypWand;
	Tuer* _prototypTuer;
};



LabyrinthPrototypFabrik::LabyrinthPrototypFabrik(
	Labyrinth* labyrinth, Wand* wand, Raum* raum, Tuer* tuer)
{
	_prototypLabyrinth = labyrinth;
	_prototypWand = wand;
	_prototypRaum = raum;
	_prototypTuer = tuer;
}



class Tuer : public KartenEintrag {
public:
	Tuer();
	Tuer(const Tuer&);

	virtual void Initialisiere(Raum*, Raum*);
	virtual Tuer* Klone() const;
	virtual void Betrete();
	Raum* AndereSeiteVon(Raum*);

private:
	Raum* _raum1;
	Raum* _raum2;
};

Tuer::Tuer(const Tuer& andereTuer) {
	_raum1 = andereTuer._raum1;
	_raum2 = andereTuer._raum2;
}

void Tuer::Initialisiere(Raum* raum1, Raum* raum2) {
	_raum1 = raum1;
	_raum2 = raum2;
}

Tuer* Tuer::Klone() const {
	return new Tuer(*this);
}



Wand* LabyrinthPrototypFabrik::ErzeugeWand() const {
//	return _prototypWand->Klone();
}

Tuer* LabyrinthPrototypFabrik::ErzeugeTuer(
	Raum* raum1, Raum* raum2) const
{
	Tuer* tuer = _prototypTuer->Klone();
	tuer->Initialisiere(raum1, raum2);
	return tuer;
}



class BombardierbareWand : public Wand {
public:
	BombardierbareWand();
	BombardierbareWand(const BombardierbareWand&);

	virtual Wand* Klone() const;
	bool IstBeschaedigt();

private:
	bool _istBeschaedigt;
};

BombardierbareWand::BombardierbareWand(
	const BombardierbareWand& andereWand) : Wand(andereWand)
{
	_istBeschaedigt = andereWand._istBeschaedigt;
}

Wand* BombardierbareWand::Klone() const {
	return new BombardierbareWand(*this);
}
