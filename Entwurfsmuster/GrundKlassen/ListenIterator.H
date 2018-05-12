template<class Element>
class ListenIterator : public Iterator<Element> {
public:
	ListenIterator(const Liste<Element>* eineListe);

	virtual void Start();
	virtual void Weiter();
	virtual bool IstFertig() const;
	virtual Element AktuellesElement() const;
};

