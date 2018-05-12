#include "GrundKlassen/GrundKlassen.H"

class Dokument {
public:
	Dokument();
	virtual void Oeffne();
	virtual void LiesEin();
};

class Anwendung {
public:
	Anwendung();
	virtual void OeffneDokument(const char*);
	virtual bool KannDokumentOeffnen(const char*);
	virtual void VorDokumentOeffnen(Dokument*);
	virtual Dokument* ErzeugeDokument();

private:
	void FuegeDokumentHinzu(Dokument*);
	Liste<Dokument*>* _dokumente;
};



void Anwendung::OeffneDokument(const char* name) {
	if (!KannDokumentOeffnen(name)) {
		// kann dieses Dokument nicht bearbeiten
		return;
	}

	Dokument* dok = ErzeugeDokument();

	if (dok) {
		FuegeDokumentHinzu(dok);
		VorDokumentOeffnen(dok);
		dok->Oeffne();
		dok->LiesEin();
	}
}




class ElternKlasse {
public:
	void Operation();

protected:
	virtual void EinschubMethode();
};

void ElternKlasse::Operation() {
	// Verhalten der Elternklasse
	EinschubMethode();
}

void ElternKlasse::EinschubMethode() {}



class AbgeleiteteKlasse {

protected:
	virtual void EinschubMethode();
};

void AbgeleiteteKlasse::EinschubMethode() {
	// Erweiterungen durch abgeleitete Klasse
}



class Anzeige {
public:
	void ZeigeAn();
	
protected:
	virtual void NimmFokusAn();
	virtual void GibFokusFrei();
	virtual void TuZeigeAn();
};
	
void Anzeige::ZeigeAn() {
	NimmFokusAn();
	TuZeigeAn();
	GibFokusFrei();
}

void Anzeige::TuZeigeAn() {}



class EineAnzeige : public Anzeige {
protected:
	virtual void TuZeigeAn();
};

void EineAnzeige::TuZeigeAn() {
	// stelle den Inhalt der Anzeige dar
}

