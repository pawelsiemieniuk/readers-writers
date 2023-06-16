#ifndef FUNC
#define FUNC

void printStatus();
/*
 * Deklaracja funkcji do wyświetlania aktualnego stanu kolejek
 * Wyświetla aktualny stan kolejek czytelników i pisarzy.
 */

void signalHandler();
/*
 * Deklaracja funkcji do obsługi sygnału
 * Funkcja jest wywoływana w momencie obsługi sygnału.
 * Przeprowadza ona analizę czasu działania wątków i wyświetla
 * statystyki dotyczące oczekiwania w kolejce dla czytelników i pisarzy.
 */

void logEntryTime(int id);
/*
 * Deklaracja funkcji do logowania czasu wejścia wątku do kolejki
 * Funkcja jest wywoływana, gdy wątek wchodzi do kolejki.
 * Zapisuje ona czas wejścia wątku do kolejki oraz aktualizuje najdłuższy czas oczekiwania w kolejce.
 */

#endif
