#include "GrundKlassen/GrundKlassen.H"

typedef float Watt;
typedef float Betrag;



#include "Kompositum.H"



class Karte : public Geraet {
public:
	Karte(char*);
};

class Rahmen : public ZusammengesetztesGeraet {
public:
	Rahmen(char*);
};

class Bus : public ZusammengesetztesGeraet {
public:
	Bus(char*);
};



void KompositumDemo() {
	Gehaeuse* gehaeuse = new Gehaeuse("PC Gehaeuse");
	Rahmen* rahmen = new Rahmen("PC Rahmen");

	gehaeuse->FuegeHinzu(rahmen);

	Bus* bus = new Bus("MCA Bus");
	bus->FuegeHinzu(new Karte("16Mbs Token Ring"));

	rahmen->FuegeHinzu(bus);
	rahmen->FuegeHinzu(new FloppyDisk("3.5in Floppy"));

	cout << "Der Gesamtpreis betraegt " << gehaeuse->GesamtPreis()
		<< endl;
}


