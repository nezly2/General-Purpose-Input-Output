// function.c
//   Created on: Mar 15, 2021
//     Author: Nezly Yanez & Flavio Jimenez
#define PDDRA (int *)0x400FF014
#define PDORA (int *)0x400FF000
#define PDDRB (int *)0x400FF054
#define PDORB (int *)0x400FF040
#define PDDRC (int *)0x400FF094
#define PDORC (int *)0x400FF080
#define PDDRD (int *)0x400FF0D4
#define PDORD (int *)0x400FF0C0
#define PDDRE (int *)0x400FF114
#define PDORE (int *)0x400FF100

void pinMode(unsigned char puerto, int bit, unsigned char mode){
int *p2SCGC5; 				//apuntador a clock
int *p2Pcr;					//apuntador a PCRn
int *p2Pddr;				//apuntador a PDDR
p2SCGC5 = (int *)0x40048038;

		switch (puerto){
				case 'A':
					*p2SCGC5 = 0x200;							//prende el reloj de puerto A
					p2Pcr = (int *) (0x40049000 + (bit*4));		//direccion inicial de A
					*p2Pcr = 0x100;
					p2Pddr =  PDDRA;
						mode == 1 ? (*p2Pddr = *p2Pddr | (1<<bit)) : (*p2Pddr = *p2Pddr & ~(1<<bit));
				break;

				case 'B':
					*p2SCGC5 = 0x400;							//prende el reloj de puerto B
					p2Pcr =  (int *)(0x4004A000 + (bit*4));		//direccion inicial de B
					*p2Pcr = 0x100;
					p2Pddr =  PDDRB;
						mode == 1 ? (*p2Pddr = *p2Pddr | (1<<bit)) : (*p2Pddr = *p2Pddr & ~(1<<bit));
				break;

				case 'C':
					*p2SCGC5 = 0x800;							//prende el reloj de puerto C
					p2Pcr = (int *)(0x4004B000 + (bit*4));		//direccion inicial de C
					*p2Pcr = 0x100;
					p2Pddr =  PDDRC;
						mode == 1 ? (*p2Pddr = *p2Pddr | (1<<bit)) : (*p2Pddr = *p2Pddr & ~(1<<bit));
				break;

				case 'D':
					*p2SCGC5 = 0x1000;							//prende el reloj de puerto D
					p2Pcr = (int *)(0x4004C000 + (bit*4));		//direccion inicial de D
					*p2Pcr = 0x100;
					p2Pddr =  PDDRD;
						mode == 1 ? (*p2Pddr = *p2Pddr | (1<<bit)) : (*p2Pddr = *p2Pddr & ~(1<<bit));
				break;

				case 'E':
					*p2SCGC5 = 0x2000;							//prende el reloj de puerto E
					p2Pcr = (int *)(0x4004D000 + (bit*4));		//direccion inicial de E
					*p2Pcr = 0x100;
					p2Pddr =  PDDRE;
						mode == 1 ? (*p2Pddr = *p2Pddr | (1<<bit)) : (*p2Pddr = *p2Pddr & ~(1<<bit));
				break;
		}//end switch
}//end pinMode

void digitalWrite(unsigned char puerto, int bit, unsigned char data){
int *p2Pdor;

	switch (puerto){
			case 'A':
				p2Pdor = PDORA;
					data == 0 ? (*p2Pdor = *p2Pdor & ~(1<<bit)) : (*p2Pdor = *p2Pdor | (1<<bit));
			break;

			case 'B':
				p2Pdor = PDORB;
					data == 0 ? (*p2Pdor = *p2Pdor & ~(1<<bit)) : (*p2Pdor = *p2Pdor | (1<<bit));
			break;

			case 'C':
				p2Pdor = PDORC;
					data == 0 ? (*p2Pdor = *p2Pdor & ~(1<<bit)) : (*p2Pdor = *p2Pdor | (1<<bit));
			break;

			case 'D':
				p2Pdor = PDORD;
					data == 0 ? (*p2Pdor = *p2Pdor & ~(1<<bit)) : (*p2Pdor = *p2Pdor | (1<<bit));
			break;

			case 'E':
				p2Pdor = PDORE;
					data == 0 ? (*p2Pdor = *p2Pdor & ~(1<<bit)) : (*p2Pdor = *p2Pdor | (1<<bit));
			break;
	}//end switch
}//end digitalWrite
