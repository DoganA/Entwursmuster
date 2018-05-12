class TCPOktettStream;
class TCPZustand;

class TCPVerbindung {
public:
	TCPVerbindung();

	void OeffneAktiv();
	void OeffnePassiv();
	void Schliesse();
	void Sende();
	void Bestaetige();
	void Synchronisiere();

	void BearbeiteOktett(TCPOktettStream*);

private:
	friend class TCPZustand;
	void AendereZustand(TCPZustand*);

private:
	TCPZustand* _zustand;
};



class TCPZustand {
public:
	virtual void Uebertrage(TCPVerbindung*, TCPOktettStream*);
	virtual void OeffneAktiv(TCPVerbindung*);
	virtual void OeffnePassiv(TCPVerbindung*);
	virtual void Schliesse(TCPVerbindung*);
	virtual void Synchronisiere(TCPVerbindung*);
	virtual void Bestaetige(TCPVerbindung*);
	virtual void Sende(TCPVerbindung*);

protected:
	void AendereZustand(TCPVerbindung*, TCPZustand*);
};



void TCPVerbindung::AendereZustand(TCPZustand* zustand) {
	_zustand = zustand;
}

void TCPVerbindung::OeffneAktiv() {
	_zustand->OeffneAktiv(this);
}

void TCPVerbindung::OeffnePassiv() {
	_zustand->OeffnePassiv(this);
}

void TCPVerbindung::Schliesse() {
	_zustand->Schliesse(this);
}

void TCPVerbindung::Bestaetige() {
	_zustand->Bestaetige(this);
}

void TCPVerbindung::Synchronisiere() {
	_zustand->Synchronisiere(this);
}



void TCPZustand::Uebertrage(TCPVerbindung*, TCPOktettStream*) {};
void TCPZustand::OeffneAktiv(TCPVerbindung*) {};
void TCPZustand::OeffnePassiv(TCPVerbindung*) {};
void TCPZustand::Schliesse(TCPVerbindung*) {};
void TCPZustand::Synchronisiere(TCPVerbindung*) {};

void TCPZustand::AendereZustand(TCPVerbindung* v, TCPZustand* z) {
	v->AendereZustand(z);
}



class TCPEtabliert : public TCPZustand {
public:
	static TCPZustand* Exemplar();

	virtual void Uebertrage(TCPVerbindung*, TCPOktettStream*);
	virtual void Schliesse(TCPVerbindung*);
};

class TCPBereit : public TCPZustand {
public:
	static TCPZustand* Exemplar();

	virtual void Sende(TCPVerbindung*);
	// ...
};

class TCPBeendet : public TCPZustand {
public:
	static TCPZustand* Exemplar();

	virtual void OeffneAktiv(TCPVerbindung*);
	virtual void OeffnePassiv(TCPVerbindung*);
};

TCPVerbindung::TCPVerbindung() {
	_zustand = TCPBeendet::Exemplar();
}

void TCPBeendet::OeffneAktiv(TCPVerbindung* v) {
	// sende SYN, empfange SYN, ACK usw.

	AendereZustand(v, TCPEtabliert::Exemplar());
}

void TCPBeendet::OeffnePassiv(TCPVerbindung* v) {
	AendereZustand(v, TCPBereit::Exemplar());
}

void TCPEtabliert::Schliesse(TCPVerbindung* v) {
	// sende FIN, empfange ACK fuers FIN

	AendereZustand(v, TCPBereit::Exemplar());
}

void TCPEtabliert::Uebertrage(TCPVerbindung* v, TCPOktettStream* o) {
	v->BearbeiteOktett(o);
}

void TCPBereit::Sende(TCPVerbindung* v) {
	// sende SYN, empfange SYN, ACK usw.

	AendereZustand(v, TCPEtabliert::Exemplar());
}


