#include <iostream>
#include <map>
#include <memory>
#include <string>

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"

using namespace std;

typedef shared_ptr<Multimedia> MultimediaPtr;
typedef shared_ptr<Groupe> GroupePtr;
typedef map<string, MultimediaPtr> MultimediaMap;
typedef map<string, GroupePtr> GroupeMap;

class Base {

private:
    MultimediaMap multimediaTable;
    GroupeMap groupeTable;

public:

    Base(){};
    ~Base();

    MultimediaPtr ajouterPhoto(const string& name, const string& pathname, float lat, float lon) {
        MultimediaPtr photo(new Photo(name, pathname, lat, lon));
        multimediaTable[name] = photo;
        return photo;
    }

    MultimediaPtr ajouterVideo(const string& name, const string& pathname, float d) {
        MultimediaPtr video(new Video(name, pathname, d));
        multimediaTable[name] = video;
        return video;
    }

    MultimediaPtr ajouterFilm(string name, string pathname, int d, const int* chapitres, const int nbChapitres) {
        MultimediaPtr film(new Film(name, pathname,d, chapitres, nbChapitres));
        multimediaTable[name] = film;
        return film;
    }

    void ajouterMultimedia(MultimediaPtr m){
        multimediaTable[m->getName()]=m;
    }

    GroupePtr ajouterGroupe(string name) {
        GroupePtr group(new Groupe(name));
        groupeTable[name] = group;
        return group;
    }

    GroupePtr ajouterGroupe(GroupePtr g){
        groupeTable[g->getNom()]=g;
        return g;
    }

    MultimediaPtr chercherMultimedia(string name) {
        MultimediaMap::iterator it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            return it->second;
        }
        else {
            return nullptr;
        }
    }

    string jouerMultimedia(string name) {
        MultimediaMap::iterator it = multimediaTable.find(name);
        if (it != multimediaTable.end()) {
            it->second->jouer();
            return "fichier joué";
        }
        else {
            return "Fichier n'est pas trouvé";
        }
    }


    GroupePtr chercherGroupe(string name) {
        GroupeMap::iterator it = groupeTable.find(name);
        if (it != groupeTable.end()) {
            return it->second;
        }
        else {
            return nullptr;
        }
    }


};