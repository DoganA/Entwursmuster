#include "GrundKlassen/GrundKlassen.H"

typedef float Watt;
typedef float Betrag;

class Geraet;
class Bus;
class Karte;
class FloppyDisk;
class Gehaeuse;

class GeraetBesucher;

class Stueckliste {
public:
	virtual void FuegeHinzu(Geraet*);
	friend ostream& operator<<(ostream&, Stueckliste);
};



#include "Besucher.H"



void BesucherDemo() {
	Geraet* komponente;
	StuecklistenBesucher besucher;

	komponente->NimmEntgegen(besucher);
	cout << "Inhalt "
		<< komponente->Name()
		<< besucher.GibStueckliste();
}


