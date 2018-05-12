#include "GrundKlassen/GrundKlassen.H"
#include <string.h>

class Ereignis;



#include "Proxy.H"



void ProxyDemo() {
	TextDokument* text = new TextDokument;
	// ...
	text->FuegeHinzu(new BildProxy("DateiName"));
}

