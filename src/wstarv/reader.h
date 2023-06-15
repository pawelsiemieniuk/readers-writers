#ifndef READER_WSTARV
#define READER_WSTARV

void* reader();
/*
 * Funkcja reprezentująca wątek czytelnika.
 * 
 * Jeśli w czytelni niema pisarzy
 * Wątek czytelnika próbuje uzyskać dostęp do czytelni, redukując liczbę czytelników oczekujących na wejście
 * i zwiększając liczbę czytelników w czytelni. Następnie odczekuje określony czas czytania,
 * po czym opuszcza czytelnię, redukując liczbę czytelników w czytelni.
 * Po odczekaniu czasu odpoczynku, zwiększa liczbę czytelników oczekujących na wejście i kontynuuje działanie w pętli.
 */
#endif
