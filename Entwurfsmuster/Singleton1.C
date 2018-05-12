#include <stdlib.h>
#include "GrundKlassen/GrundKlassen.H"
class Paar;
typedef Paar* NameSingletonPaar;



class Singleton1 {
public:
	static Singleton1* Exemplar();

protected:
	Singleton1();

private:
	static Singleton1* _exemplar;
};

Singleton1* Singleton1::_exemplar = 0;

Singleton1* Singleton1::Exemplar() {
	if (_exemplar == 0) {
		_exemplar = new Singleton1;
	}
	return _exemplar;
}


class Singleton2 {
public:
	static void Registriere(char* name, Singleton2*);
	static Singleton2* Exemplar();

protected:
	static Singleton2* Suche(const char* name);

private:
	static Singleton2* _exemplar;
	static Liste<NameSingletonPaar>* _registratur;
};

Singleton2* Singleton2::Exemplar() {
	if (_exemplar == 0) {
		const char* exemplarName = getenv("SINGLETON");
		// Benutzer oder Umgebung setzen die Variable beim Hochfahren

		_exemplar = Suche(exemplarName);
		// Suche gibt 0 zurueck, wenn es noch kein Singleton gibt
	}
	return _exemplar;
}



//MeinSingleton::MeinSingleton() {
//	//...
//	Singleton::Registriere("MeinSingleton", this);
//}
//
//static MeinSingleton dasSingleton;


