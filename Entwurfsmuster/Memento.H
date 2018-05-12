class BewegenBefehl {
public:
	BewegenBefehl(GrafischesObjekt* objekt, const Punkt& delta);
	void FuehreAus();
	void Rueckgaengig();

private:
	ConstraintLoeserMemento* _zustand;
	Punkt _delta;
	GrafischesObjekt* _objekt;
};



class ConstraintLoeser {
public:
	static ConstraintLoeser* Exemplar();

	void Loese();
	void FuegeConstraintHinzu(GrafischesObjekt* anfangVerbindung,
		GrafischesObjekt* endeVerbindung);
	void EnferneConstraint(GrafischesObjekt* anfangVerbindung,
		GrafischesObjekt* endeVerbindung);

	ConstraintLoeserMemento* ErzeugeMemento();
	void SetzeMemento(ConstraintLoeserMemento*);

private:
	// nicht trivialer Zustand sowie Operationen zur Wahrung
	// der Verbindungssemantik
};

class ConstraintLoeserMemento {
public:
	virtual ~ConstraintLoeserMemento();

private:
	friend class ConstraintLoeser;
	ConstraintLoeserMemento();

	// privater ConstraintLoeser-Zustand
};



void BewegenBefehl::FuehreAus() {
	ConstraintLoeser* constraintLoeser = ConstraintLoeser::Exemplar();
	// erzeuge ein Memento
	_zustand = constraintLoeser->ErzeugeMemento();
	_objekt->Bewege(_delta);
	constraintLoeser->Loese();
}

void BewegenBefehl::Rueckgaengig() {
	ConstraintLoeser* constraintLoeser = ConstraintLoeser::Exemplar();
	_objekt->Bewege(_delta);
	// setze ConstraintLoeser-Zustand zurueck
	constraintLoeser->SetzeMemento(_zustand);
	constraintLoeser->Loese();
}

