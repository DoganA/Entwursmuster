template<class Element>
class Iterator {
public:
	virtual void Start() = 0;
	virtual void Weiter() = 0;
	virtual bool IstFertig() const = 0;
	virtual Element AktuellesElement() const = 0;
protected:
	Iterator();
};


