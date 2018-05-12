class Komposition {
public:
	Komposition(Formatierer*);
	void Repariere();

private:
	Formatierer* _formatierer;
	Komponente* _komponenten;	// die Liste von Komponenten
	int _komponentenAnzahl;		// die Anzahl der Komponenten in der Liste
	int _zeilenBreite;			// die Breite einer Zeile in der Komposition
	int* _zeilenUmbrueche;		// die Position der Zeilenumbrueche in den
											// Komponenten
	int _zeilenAnzahl;			// die Anzahl an Zeilen
};



class Formatierer {
public:
	virtual int Formatiere(Koordinate ausmasse[],
		Koordinate dehnbarkeit[], Koordinate stauchbarkeit[],
		int komponentenAnzahl, int zeilenBreite, int umbrueche[] ) = 0;

protected:
	Formatierer();
};



void Komposition::Repariere() {
	Koordinate* ausmasse;
	Koordinate* dehnbarkeit;
	Koordinate* stauchbarkeit;
	int komponentenAnzahl;
	int* umbrueche;

	// bereite die Arrays mit den gewuenschten Groessen
	// fuer die Komponenten vor
	// ...

	// bestimme die Position der Umbrueche:
	int umbruchAnzahl;
	umbruchAnzahl = _formatierer->Formatiere(ausmasse,
		dehnbarkeit, stauchbarkeit, komponentenAnzahl,
		_zeilenBreite, umbrueche);

	// stelle die Komponente gemaess der Umbrueche dar
	// ...
}



class EinfacherFormatierer : public Formatierer {
public:
	EinfacherFormatierer();

	virtual int Formatiere(Koordinate ausmasse[],
		Koordinate dehnbarkeit[], Koordinate stauchbarkeit[],
		int komponentenAnzahl, int _zeilenBreite, int umbrueche[]);
	// ...
};



class TeXFormatierer : public Formatierer {
public:
	TeXFormatierer();

	virtual int Formatiere(Koordinate ausmasse[],
		Koordinate dehnbarkeit[], Koordinate stauchbarkeit[],
		int komponentenAnzahl, int _zeilenBreite, int umbrueche[]);
	// ...
};



class ArrayFormatierer : public Formatierer {
public:
	ArrayFormatierer(int breite);

	virtual int Formatiere(Koordinate ausmasse[],
		Koordinate dehnbarkeit[], Koordinate stauchbarkeit[],
		int komponentenAnzahl, int _zeilenBreite, int umbrueche[]);
	// ...
};


