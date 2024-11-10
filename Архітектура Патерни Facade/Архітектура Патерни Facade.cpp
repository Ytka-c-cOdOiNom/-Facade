#include <iostream>
#include <windows.h>
using namespace std;

// Підсистема 1: Телевізор
class Television {
public:
    void on() const {
        cout << "Телевізор увімкнено." << endl;
    }
    void off() const {
        cout << "Телевізор вимкнено." << endl;
    }
};

// Підсистема 2: Аудіосистема
class AudioSystem {
public:
    void on() const {
        cout << "Аудіосистему увімкнено." << endl;
    }
    void setVolume(int level) const {
        cout << "Гучність встановлено на рівень " << level << "." << endl;
    }
    void off() const {
        cout << "Аудіосистему вимкнено." << endl;
    }
};

// Підсистема 3: DVD-програвач
class DVDPlayer {
public:
    void on() const {
        cout << "DVD-програвач увімкнено." << endl;
    }
    void play(const string& movie) const {
        cout << "Відтворення фільму: " << movie << "." << endl;
    }
    void off() const {
        cout << "DVD-програвач вимкнено." << endl;
    }
};

// Клас Фасад для домашнього кінотеатру
class HomeTheaterFacade {
private:
    Television tv;
    AudioSystem audio;
    DVDPlayer dvd;

public:
    HomeTheaterFacade(Television tv, AudioSystem audio, DVDPlayer dvd)
        : tv(tv), audio(audio), dvd(dvd) {}

    // Метод для запуску кінотеатру
    void watchMovie(const string& movie) {
        cout << "Готуємося до перегляду фільму..." << endl;
        tv.on();
        audio.on();
        audio.setVolume(20);
        dvd.on();
        dvd.play(movie);
        cout << "Приємного перегляду!" << endl;
    }

    // Метод для завершення перегляду фільму
    void endMovie() {
        cout << "Завершуємо перегляд фільму..." << endl;
        dvd.off();
        audio.off();
        tv.off();
        cout << "Систему вимкнено." << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення об'єктів підсистем
    Television tv;
    AudioSystem audio;
    DVDPlayer dvd;

    // Створення фасаду для домашнього кінотеатру
    HomeTheaterFacade homeTheater(tv, audio, dvd);

    // Використання фасаду
    homeTheater.watchMovie("Матриця");
    cout << endl;
    homeTheater.endMovie();

}

