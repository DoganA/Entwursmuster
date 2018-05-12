#include "GrundKlassen/GrundKlassen.H"

class Formatierer;
class Komponente;



#include "Strategie.H"



void StrategieDemo() {
	Komposition* schnell = new Komposition(new EinfacherFormatierer);
	Komposition* schick = new Komposition(new TeXFormatierer);
	Komposition* icons = new Komposition(new ArrayFormatierer(10));
}



