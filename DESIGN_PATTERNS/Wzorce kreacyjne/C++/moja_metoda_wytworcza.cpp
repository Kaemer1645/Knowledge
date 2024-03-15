#include "design_pattern.h"
#include <cstdlib>

class Bike {
public:
	virtual ~Bike() {}; // destruktor wirtualny aby poprawnie zwalniać pamięć podczas dziedziczenia i używania polimorfizmu
	virtual std::string ride() const = 0; //const oznacza, że metoda nie zmienia stanu obiektu.
										  //= 0 oznacza, że metoda jest czysto wirtualna i musi być zaimplementowana przez klasy pochodne.
};

class roadBike : public Bike {
public:
	std::string ride() const override {
		return "Jadę rowerem szosowym";
	}
};

class trackBike : public Bike {
public:
	std::string ride() const override {
		return "Jadę rowerem torowym";
	}
};

class Creator {
public:
	virtual ~Creator() {};
	virtual Bike* FactoryMethod() const = 0;
	std::string createObject() const {
		Bike* object = this->FactoryMethod();
		std::string result = "Moj obiekt mówi, że " + object->ride();
		delete object;
		return result;
	}
};

class roadBikeFactory : public Creator {
	Bike* FactoryMethod() const override{
		return new roadBike(); // new dynamicznie alokuje pamięć i rzutuje na obiekt typu klasy bazowej a nie klasy pochodnej
	}
};

class trackBikeFactory : public Creator {
	Bike* FactoryMethod() const override { //override oznacza, że metoda w klasie pochodnej przesłania metodę wirtualną z klasy bazowej, zapewniając zgodność sygnatury.
		return new trackBike();
	}
};

void funkcjaKliencka(const Creator& creator) {
	std::cout << creator.createObject() << std::endl;
}

//int main() {
//	#ifdef _WIN32
//		std::system("chcp 65001 > nul");
//	#endif
//	Creator* creator = new roadBikeFactory;
//	funkcjaKliencka(*creator);
//	Creator* creator1 = new trackBikeFactory;
//	funkcjaKliencka(*creator1);
//	delete creator;
//	delete creator1;
//	return 0;
//}