class Punkt {
public:
	static const Punkt& NullPunkt;

	Punkt(Koordinate x = 0.0, Koordinate y = 0.0);

	Koordinate X() const;   void X(Koordinate x);
	Koordinate Y() const;   void Y(Koordinate y);

	friend Punkt& operator+(const Punkt&, const Punkt&);
	friend Punkt& operator-(const Punkt&, const Punkt&);
	friend Punkt& operator*(const Punkt&, const Punkt&);
	friend Punkt& operator/(const Punkt&, const Punkt&);

	Punkt& operator+=(const Punkt&);
	Punkt& operator-=(const Punkt&);
	Punkt& operator*=(const Punkt&);
	Punkt& operator/=(const Punkt&);

	Punkt operator-();

	friend bool operator==(const Punkt&, const Punkt&);
	friend bool operator!=(const Punkt&, const Punkt&);

	friend ostream& operator<<(ostream&, const Punkt&);
	friend istream& operator>>(istream&, const Punkt&);
};


