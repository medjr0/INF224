#include "multimedia.h"

Multimedia::Multimedia(string n, string path)
{
    name = n;
    pathname = path;
}


string Multimedia::affiche(ostream & s) const{
    string l = "File name : "+ name+"  Pathname : "+pathname;
    s << l <<endl;
    return l;
}

string Multimedia::affiche() const{
    return affiche(std::cout);
}
