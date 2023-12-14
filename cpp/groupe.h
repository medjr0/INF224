#include <list>
#include <memory>
#include "multimedia.h"

using namespace std;

using MultimediaPtr = shared_ptr<Multimedia>;

//template<class T>
class Groupe : public list<MultimediaPtr> {
private:
    string nom;

public:
    Groupe(string nom) : nom(nom) {}

    string getNom() const {
        return nom;
    }

    string afficher() const {
        string s = "Groupe " + nom +" : ";
        std::cout << "Groupe " << nom << " :\n";
        for (auto& objet : *this) {
            objet->affiche();
            s = s + objet->affiche()+" --- ";
        }
        std::cout << std::endl;
        return s;
    }
};