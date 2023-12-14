/*
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "groupe.h"*/

#include "base.h"
#include <iostream>
#include <vector>

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"

const int PORT = 3331;

using namespace std;

int main(int argc, const char* argv[])
{
    /*Multimedia * m = new Photo("photo", "photo_identité.jpg", 924, 608);
    m->affiche();*/

    /*vector<Multimedia*> mediaList;

    Photo* photo1 = new Photo("photo1", "path/to/photo1.jpg", 48.8566, 2.3522);
    Video* video1 = new Video("video1", "path/to/video1.mp4", 120);
    Photo* photo2 = new Photo("photo2", "path/to/photo2.jpg", 64, 89);

    mediaList.push_back(photo1);
    mediaList.push_back(video1);
    mediaList.push_back(photo2);

    for (Multimedia* media : mediaList) {
        media->affiche();
        //media->jouer();
    }*/

    /*int * chapitres = new int[3];
    chapitres[0] = 60;
    chapitres[1] = 60;
    chapitres[2] = 30;

    Film * m = new Film("Interstellar","/home/movies/movie1.mp4",150,chapitres, 3);

    delete []chapitres;

    m->displayChapitres();*/

    /*
    Groupe<Photo> * g = new Groupe<Photo>("Photo vacances");

    Photo* photo1 = new Photo("photo1", "path/to/photo1.jpg", 48.8566, 2.3522);
    Photo* photo2 = new Photo("photo2", "path/to/photo2.jpg", 64, 89);
    Photo* photo3 = new Photo("photo3", "path/to/photo3.jpg", 64, 89);
    Photo* photo4 = new Photo("photo4", "path/to/photo4.jpg", 64, 89);

    g->push_back(photo1);
    g->push_back(photo2);
    g->push_back(photo3);
    g->push_back(photo4);

    g->afficher();

    delete g;

    photo1->affiche();
    */
   
   /*
    Groupe * g1 = new Groupe("Photo vacances");
    Groupe * g2 = new Groupe("Photo avril");

    using PhotoPtr = shared_ptr<Photo>;


    MultimediaPtr photo1(new Photo("photo1", "path/to/photo1.jpg", 48.8566, 2.3522));
    MultimediaPtr photo2(new Photo("photo2", "path/to/photo2.jpg", 64, 89));
    MultimediaPtr photo3(new Photo("photo3", "path/to/photo3.jpg", 64, 89));
    MultimediaPtr photo4(new Photo("photo4", "path/to/photo4.jpg", 64, 89));

    g1->push_back(photo1);
    g1->push_back(photo2);
    g1->push_back(photo3);
    g1->push_back(photo4);
    g2->push_back(photo1);
    g2->push_back(photo2);

    g1->afficher();
    cout <<" ------------"<< endl;
    g2->afficher();

    delete g1;

    g2->afficher();

    delete g2;
    cout << "---------------" <<endl;

    photo1->affiche();
    */


    /*
    Base * b = new Base();

    MultimediaPtr photo1(new Photo("photo1", "path/to/photo1.jpg", 48.8566, 2.3522));
    MultimediaPtr photo2(new Photo("photo2", "path/to/photo2.jpg", 64, 89));
    MultimediaPtr photo3(new Photo("photo3", "path/to/photo3.jpg", 64, 89));
    MultimediaPtr photo4(new Photo("photo4", "path/to/photo4.jpg", 64, 89));

    b->ajouterMultimedia(photo1);
    b->ajouterMultimedia(photo2);
    b->ajouterMultimedia(photo3);

    GroupePtr g2(new Groupe("Photo avril"));

    b->ajouterGroupe(g2);

    g2->push_back(photo1);
    g2->push_back(photo2);

    MultimediaPtr p = b->chercherMultimedia("photo3");
    p->affiche();

    cout << "---------------"<<endl;

    GroupePtr g = b->chercherGroupe("Photo avril");
    g->afficher();
    */

   Base * b = new Base();

    MultimediaPtr photo1(new Photo("piano", "piano.jpg", 48.8566, 2.3522));
    MultimediaPtr photo2(new Photo("photo2", "piano.jpg", 64, 89));
    MultimediaPtr photo3(new Photo("photo3", "path/to/photo3.jpg", 64, 89));
    MultimediaPtr photo4(new Photo("photo4", "path/to/photo4.jpg", 64, 89));

    MultimediaPtr video1(new Video("earth", "earth.mp4", 30));



    b->ajouterMultimedia(photo1);
    b->ajouterMultimedia(photo2);
    b->ajouterMultimedia(photo3);
    b->ajouterMultimedia(video1);

    GroupePtr g2(new Groupe("Photo avril"));

    b->ajouterGroupe(g2);
    b->ajouterGroupe("photo vacances");

    g2->push_back(photo1);
    g2->push_back(photo2);

    string command1 = "findMultimedia";
    string command2 = "findGroupe";
    string command3 = "play";

   // cree le TCPServer
  auto* server =
  new TCPServer( [&](std::string const& request, std::string& response) {
    
    std::cout << "request: " << request << std::endl;

    if (request.substr(0, command1.length()).compare(command1) == 0) {

        MultimediaPtr result = b->chercherMultimedia(request.substr(command1.length()+1, request.length()));

        if (result != nullptr){
        string rps = "Found ! "+result->affiche();

        response = rps;} else { response = "No such file found !";}

    }else if(request.substr(0, command2.length()).compare(command2) == 0){

        GroupePtr result = b->chercherGroupe(request.substr(command2.length()+1, request.length()));

        if (result != nullptr){
        string rps = "Found ! "+ result->afficher();

        response = rps;} else { response = "No such Groupe found !";}

    } else if(request.substr(0, command3.length()).compare(command3) == 0){
        response = b->jouerMultimedia(request.substr(command3.length()+1, request.length()));
    } else {
        response = "Couldn't find your request";
    }

    // the response that the server sends back to the client
    //response = "RECEIVED: " + request;

    // return false would close the connecytion with the client
    return true;
  });


  // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

  int status = server->run(PORT);

  // en cas d'erreur
  if (status < 0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;
  }

  return 0;
}
