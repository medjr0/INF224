#include "video.h"

class Film : public Video {

private:
    int* chapitres_;
    int nChapitres_;

public:

    Film(string nom, string pathname, float duree, const int* chapitres=nullptr, const int nChapitres = 0)
        : Video(nom, pathname, duree), nChapitres_(nChapitres) {
        if(nChapitres > 0) {
            chapitres_ = new int[nChapitres];
            copy(chapitres, chapitres + nChapitres, chapitres_);
        }
        else {
            chapitres_ = nullptr;
        }
    }

    Film(const Film& other)
        : Video(other), nChapitres_(other.nChapitres_) {
        if(nChapitres_ > 0) {
            chapitres_ = new int[nChapitres_];
            std::copy(other.chapitres_, other.chapitres_ + nChapitres_, chapitres_);
        }
        else {
            chapitres_ = nullptr;
        }
    }

    void setChapitres(int* chapitres, const int nChapitres) {

        delete[] chapitres_;
        nChapitres_ = nChapitres;
        if(nChapitres_ > 0) {
            chapitres_ = new int[nChapitres_];
            std::copy(chapitres, chapitres + nChapitres_, chapitres_);
        }
        else {
            chapitres_ = nullptr;
        }
    }

    int* getChapitres() const {
        int* result = nullptr;
        if(nChapitres_ > 0) {
            result = new int[nChapitres_];
            std::copy(chapitres_, chapitres_ + nChapitres_, result);
        }
        return result;
    }

    int getNChapitres() const { return nChapitres_; }

    void displayChapitres() const {
        std::cout << "Chapitres: ";
        for(int i=0; i<nChapitres_; i++) {
            std::cout << chapitres_[i] << " ";
        }
        std::cout << std::endl;
    }


    ~Film() {
        if(chapitres_ != nullptr) {
            delete[] chapitres_;
        }
        cout << name <<" is deleted"<<endl;
    }

    
};
