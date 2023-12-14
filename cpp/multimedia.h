#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class Multimedia
{

protected:
    string name;
    string pathname;
public:
    Multimedia(){};
    Multimedia(string n, string path);

    string getName(){return name;}
    string getPath(){return pathname;}
    void setName(string n){name = n;}
    void setPath(string path){pathname = path;}

    string affiche(ostream & s) const;
    string affiche() const;

    virtual void jouer() const = 0;

    ~Multimedia(){};
};

#endif // MULTIMEDIA_H
