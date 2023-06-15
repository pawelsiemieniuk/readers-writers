#ifndef WRITER_RSTARV
#define WRITER_RSTARV

void* writer();
/*
 * Funkcja reprezentująca wątek pisarza.
 * 
 * Wątek pisarza próbuje uzyskać dostęp do czytelni, redukując liczbę pisarzy oczekujących na wejście
 * i zwiększając liczbę pisarzy w czytelni. Następnie odczekuje określony czas pisania,
 * po czym opuszcza czytelnię, redukując liczbę pisarzy w czytelni.
 * Jeśli niema już pisaży czekających na wejście, sygnalizuje czytelnikom możliwość dostępu.
 * Po odczekaniu czasu odpoczynku, zwiększa liczbę pisarzy w oczekujących na wejście i kontynuuje działanie w pętli.
 */

#endif
