unsigned nascii(char); // numeri decimali dai rispettivi caratteri
double pot(double, unsigned int); // pot(x,y)= x^y
unsigned long fatt(unsigned long); //rende il fattoriale del numero
unsigned int strl(const char*); // strl("stringa")= lunghazza della stringa
long unint(const char*); // rende un intero da un array di caratteri
long double deci(const char*); // rende un numero decimale da un array di caratteri
unsigned long binario(unsigned long); // rende il valore binario di un intero
unsigned int match(const char*, char); // conta quante volte compare il carattere nella stringa
void copia(const char*, char*); // copia il primo array sul secondo
void scambia(char*, char*); // scambia il contenuto di due array
void ordina(long double*, unsigned int); // ordina l'array di numeri (ordine crescente)
void charbin(long, char*, unsigned int); //converte un numero a binario in n char
unsigned int compare(char*, char*); // rende il numero di caratteri comuni alle due stringhe

#define VET(FORMAT) if(argc-1< match(FORMAT,'[')){fprintf(stderr,"Inserire %s dopo \"%s \"\n",FORMAT,argv[0]); return 1;} //controlla se sono stati inseriti gli argomenti tra parentesi quadre

#define ABS(N) N < 0? -N: N

#define prinf printf
#define brack break
