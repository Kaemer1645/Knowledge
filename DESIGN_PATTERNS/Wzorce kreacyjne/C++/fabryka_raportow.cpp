#include <iostream>
#include <string>

// Interfejs bazowy dla raport�w
class Raport {
public:
    virtual void generuj() = 0;
};

// Konkretne implementacje raport�w
class RaportFinansowy : public Raport {
public:
    void generuj() override {
        std::cout << "Generowanie raportu finansowego..." << std::endl;
        // Logika generowania raportu finansowego
    }
};

class RaportSprzedazowy : public Raport {
public:
    void generuj() override {
        std::cout << "Generowanie raportu sprzeda�owego..." << std::endl;
        // Logika generowania raportu sprzeda�owego
    }
};

// Metoda wytw�rcza dla raport�w
class FabrykaRaportow {
public:
    virtual Raport* stworzRaport() = 0;
};

class FabrykaRaportuFinansowego : public FabrykaRaportow {
public:
    Raport* stworzRaport() override {
        return new RaportFinansowy();
    }
};

class FabrykaRaportuSprzedazowego : public FabrykaRaportow {
public:
    Raport* stworzRaport() override {
        return new RaportSprzedazowy();
    }
};

int main() {
    // Utworzenie fabryk raport�w
    FabrykaRaportow* fabrykaFinansowa = new FabrykaRaportuFinansowego();
    FabrykaRaportow* fabrykaSprzedazowa = new FabrykaRaportuSprzedazowego();

    // Generowanie r�nych rodzaj�w raport�w
    Raport* raport1 = fabrykaFinansowa->stworzRaport();
    raport1->generuj();

    Raport* raport2 = fabrykaSprzedazowa->stworzRaport();
    raport2->generuj();

    // Zwolnienie pami�ci
    delete raport1;
    delete raport2;
    delete fabrykaFinansowa;
    delete fabrykaSprzedazowa;

    return 0;
}
