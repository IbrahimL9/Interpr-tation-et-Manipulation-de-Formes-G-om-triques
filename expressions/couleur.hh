#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>


class Couleur {
private:
    int r, g, b;
    std::string nom;

public:
    Couleur(int r, int g, int b,std::string c="") : r(r), g(g), b(b),nom(c) {}
    Couleur() : r(0), g(0), b(0), nom("") {}

    static Couleur Nom(const std::string& nom) {
        if (nom == "rouge") return Couleur(255, 0, 0,"rouge");
        else if (nom == "vert") return Couleur(0, 255, 0,"vert");
        else if (nom == "bleu") return Couleur(0, 0, 255,"bleu");
        else if (nom == "jaune") return Couleur(255, 255, 0,"jaune");
        else if (nom == "violet") return Couleur(128, 0, 128,"violet");
        else if (nom == "magenta") return Couleur(255, 0, 255,"magenta");
        else if (nom == "cyan") return Couleur(0, 255, 255,"cyan");
        else if (nom == "noir") return Couleur(0, 0, 0,"noir");
        else if (nom == "blanc") return Couleur(255, 255, 255,"blanc");

        return Couleur(0, 0, 0);
    }

    static Couleur depuisHex(const std::string& hex) {
        unsigned int r, g, b;
        sscanf(hex.c_str(), "#%02x%02x%02x", &r, &g, &b);
        return Couleur(r, g, b);
    }

    static Couleur rgb(int a, int b, int c){
        return Couleur(a,b,c);
    }

    std::string toString() const {
            if (!nom.empty()) {
                return nom;
            }

            std::ostringstream oss;
            oss << "RGB(" << r << ", " << g << ", " << b << ")";
            return oss.str();
        }
};

