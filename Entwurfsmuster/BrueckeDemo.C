#include "GrundKlassen/GrundKlassen.H"
#include <math.h>
#include "GrundKlassen/GUIMockup.H"

class Fenster;
class FensterImp;

class Anzeige {
public:
	virtual void ZeichneAuf(Fenster*);
};

class FensterSystemFabrik {
public:
	static FensterSystemFabrik* GibExemplar();
	virtual FensterImp* ErzeugeFensterImp();
};



#include "Bruecke.H"

