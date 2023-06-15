#ifndef READER_EXCLUDE
#define READER_EXCLUDE

void* reader();

/*
 * Funkcja reprezentująca wątek czytelnika.
 * 
 * Funkcja ta jest odpowiedzialna za logikę działania wątku czytelnika.
 * Wątek czytelnika próbuje uzyskać dostęp do czytelni, redukując liczbę czytelników oczekujących na wejście
 * i zwiększając liczbę czytelników w czytelni. Następnie odczekuje określony czas czytania,
 * po czym opuszcza czytelnię, redukując liczbę czytelników w czytelni.
 * Jeśli nie ma innych czytelników w czytelni, sygnalizuje pisarzom możliwość dostępu.
 * Po odczekaniu czasu odpoczynku, zwiększa liczbę czytelników oczekujących na wejście i kontynuuje działanie w pętli.
 */

#endif
