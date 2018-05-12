class Rechteck {
public:
	static const Rechteck& NullRechteck;

	Rechteck(Koordinate x, Koordinate y, Koordinate b, Koordinate h);
	Rechteck(const Punkt& ursprung, const Punkt& ausmasse);

	Koordinate Breite() const;  void Breite(Koordinate);
	Koordinate Hoehe() const;   void Hoehe(Koordinate);
	Koordinate Links() const;   void Links(Koordinate);
	Koordinate Unten() const;   void Unten(Koordinate);

	Punkt& Ursprung() const;    void Ursprung(const Punkt&);
	Punkt& Ausmasse() const;    void Ausmasse(const Punkt&);

	void BewegeNach(const Punkt&);
	void BewegeUm(const Punkt&);

	bool IstLeer() const;
	bool Enthaelt(const Punkt&) const;
};


