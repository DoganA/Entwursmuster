class Befehl {
public:
	virtual ~Befehl();

	virtual void FuehreAus() = 0;

protected:
	Befehl();
};



class OeffnenBefehl : public Befehl {
public:
	OeffnenBefehl(Anwendung*);

	virtual void FuehreAus();

protected:
	virtual const char* FrageBenutzer();

private:
	Anwendung* _anwendung;
	char* _antwort;
};

OeffnenBefehl::OeffnenBefehl(Anwendung* anwendung) {
	_anwendung = anwendung;
}

void OeffnenBefehl::FuehreAus() {
	const char* name = FrageBenutzer();

	if (name != 0) {
		Dokument* dokument = new Dokument(name);
		_anwendung->FuegeHinzu(dokument);
		dokument->Oeffne();
	}
}



class EinfuegenBefehl : public Befehl {
public:
	EinfuegenBefehl(Dokument*);

	virtual void FuehreAus();

private:
	Dokument* _dokument;
};

EinfuegenBefehl::EinfuegenBefehl(Dokument* dok) {
	_dokument = dok;
}

void EinfuegenBefehl::FuehreAus() {
	_dokument->FuegeEin();
}



template<class Empfaenger>
class EinfacherBefehl : public Befehl {
public:
	typedef void (Empfaenger::* Operation)();

	EinfacherBefehl(Empfaenger* emp, Operation op) :
		_empfaenger(emp), _operation(op) {}

	virtual void FuehreAus();

private:
	Operation _operation;
	Empfaenger* _empfaenger;
};



template<class Empfaenger>
void EinfacherBefehl<Empfaenger>::FuehreAus() {
	(_empfaenger->*_operation)();
}



class MakroBefehl : public Befehl {
public:
	MakroBefehl();
	virtual ~MakroBefehl();

	virtual void FuegeHinzu(Befehl*);
	virtual void Entferne(Befehl*);

	virtual void FuehreAus();

private:
	Liste<Befehl*>* _befehle;
};



void MakroBefehl::FuehreAus() {
	ListenIterator<Befehl*> iter(_befehle);
 
	for (iter.Start(); !iter.IstFertig(); iter.Weiter()) {
		Befehl* befehl = iter.AktuellesElement();
		befehl->FuehreAus();
	}
}

void MakroBefehl::FuegeHinzu(Befehl* befehl) {
	_befehle->HaengeAn(befehl);
}

void MakroBefehl::Entferne(Befehl* befehl) {
	_befehle->Entferne(befehl);
}


