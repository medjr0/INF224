#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <iostream>
#include "multimedia.h"

using namespace std;

class Video : public Multimedia
{

protected:
    float duree{};

public:
    Video(){};
    Video(string n, string path, float d):Multimedia(n,path) , duree(d){};

    int getDuree(){return duree;}
    void setDuree(float d){duree = d;}

    //void affiche() const { Multimedia::affiche();}
    void jouer() const override{
        string cmd = "mpv ";
        cmd = cmd+pathname+" &";
        const char * c = cmd.data();
        system(c);
    };

    ~Video(){cout << name <<" is deleted"<<endl;};
};

#endif // MULTIMEDIA_H
