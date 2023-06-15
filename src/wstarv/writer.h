#ifndef WRITER_WSTARV
#define WRITER_WSTARV

void* writer();
/*
 * Funkcja reprezentująca wątek pisarza.
 * 
 * Jeśli w czytelni niema czytelników ani pisarzy oraz na wejście nie oczekują żadni czytelnicy
 * Wątek pisarza próbuje uzyskać dostęp do czytelni, redukując liczbę pisarzy oczekujących na wejście
 * i zwiększając liczbę pisarzy w czytelni. Następnie odczekuje określony czas pisania,
 * po czym opuszcza czytelnię, redukując liczbę pisarzy w czytelni.
 * Po odczekaniu czasu odpoczynku, zwiększa liczbę pisarzy w oczekujących na wejście i kontynuuje działanie w pętli.
 */

#endif
