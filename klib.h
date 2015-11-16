int nascii(char); // numeri decimali dai rispettivi caratteri
double pot(double, unsigned int); // pot(x,y)= x^y
size_t strl(const char*); // strl("stringa")= lunghazza della stringa
long unint(const char*); // rende un intero da un array di caratteri
long double deci(const char*); // rende un numero decimale da un array di caratteri
unsigned long binario(unsigned long); // rende il valore binario di un intero
unsigned int match(const char*, char); // conta quante volte compare il carattere nella stringa
void copia(char*, char*); // copia il primo array sul secondo
void scambia(char* uno, char* due); // scambia il contenuto di due array

#define VET(FORMAT) if(argc-1< match(FORMAT,'[')){fprintf(stderr,"Inserire %s dopo \"%s \"\n",FORMAT,argv[0]);return 1;} //controlla se sono stati inseriti gli argomenti tra parentesi quadre

#define ABC(N) for(char lettera='A'; lettera-64<= N; lettera++) printf("%c", lettera); puts("");
