#include "function.h"

int main(void) {
	pinMode('B',19, OUTPUT);		//verde configurar
	pinMode('B',18, OUTPUT);		//rojo	configurar
	pinMode('D',1, OUTPUT);		//azul	configurar

	digitalWrite('B',18,ON);		//rojo apagar
	digitalWrite('B',19,ON);		//verde apagar
	digitalWrite('D',1,ON);		//azul apagar

	digitalWrite('B',18,OFF);		//rojo prender
	digitalWrite('B',19,OFF);		//verde prender
	digitalWrite('D',1,OFF);		//azul prender

	pinMode('B',18, INPUT);		//rojo	configurar

	digitalWrite('B',19,ON);		//verde apagar
	digitalWrite('D',1,ON);		//azul apagar
}
