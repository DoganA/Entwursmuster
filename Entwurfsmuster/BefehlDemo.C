#include "GrundKlassen/GrundKlassen.H"


class Dokument {
public:
	Dokument(const char*);
	virtual void Oeffne();
	virtual void FuegeEin();
};

class Anwendung {
public:
	virtual void FuegeHinzu(Dokument*);
};



#include "Befehl.H"


class Klasse {
public:
	virtual void Aktion();
};

void BefehlDemo() {
	Klasse* empfaenger = new Klasse;
	// ...
	Befehl* einBefehl = new EinfacherBefehl<Klasse>(
		empfaenger, &Klasse::Aktion);
	// ...
	einBefehl->FuehreAus();
}



