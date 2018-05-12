#include "GrundKlassen/GrundKlassen.H"

// Basisklasse fuer grafische Objekte des grafischen Editors
class GrafischesObjekt {
public:
	virtual void Bewege(const Punkt&);
};

class ConstraintLoeserMemento;


#include "Memento.H"

