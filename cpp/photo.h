#ifndef PHOTO_H
#define PHOTO_H
#include <string>
#include <iostream>
#include "multimedia.h"

using namespace std;

class Photo : public Multimedia
{

private:
    int latitude;
    int longitude;
public:
    Photo(){};
    Photo(string n, string path, int lat, int lon): Multimedia(n,path), latitude(lat), longitude(lon){};

    int getLat(){return latitude;}
    int getLon(){return longitude;}
    void setLat(int lat){latitude = lat;}
    void setLon(int lon){longitude = lon;}

    //void affiche() const { this->affiche();}
    void jouer() const override{
        string cmd = "imagej ";
        cmd = cmd+pathname+" &";
        const char * c = cmd.data();
        system(c);
    };

    ~Photo(){cout << name <<" is deleted"<<endl;};
};

#endif // MULTIMEDIA_H
