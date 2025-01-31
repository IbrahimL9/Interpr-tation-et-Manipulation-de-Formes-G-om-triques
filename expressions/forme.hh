#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <algorithm>




class Taille {
private:
    int longueur;
    int hauteur;

public:
    Taille(int longueur, int hauteur) : longueur(longueur), hauteur(hauteur) {}

    std::string tostring() const {
        return "Taille " + std::to_string(longueur) + " " + std::to_string(hauteur);
    }
};

struct Attributs {
    std::shared_ptr<std::string> couleur;
    std::shared_ptr<int> rotation;
    std::shared_ptr<std::string> remplissage;
    std::shared_ptr<int> opacite;
    std::shared_ptr<int> epaisseur;
};


class Forme {
    protected:
    std::vector<Attributs> _attributs;

public:
    Forme() = default;
    virtual ~Forme() {}
    virtual std::string type() const =0;
    virtual std::string dessiner() const=0;
    void ajouterAttribut(const Attributs& att);

    virtual std::string tostring() const;

       virtual int getx() const{ return 0;};
       virtual int gety() const{ return 0;};
       virtual int getx1() const{ return 0;};
       virtual int getx2() const{ return 0;};
       virtual int getx3() const{ return 0;};
       virtual int getx4() const{ return 0;};
       virtual int gety1() const{ return 0;};
       virtual int gety2() const{ return 0;};
       virtual int gety3() const{ return 0;};
       virtual int gety4() const{ return 0;};
       virtual int getlong() const { return 0;}
       virtual int gethaut() const { return 0;}
       virtual int getray() const { return 0;}
       virtual int gettaille() const { return 0;}

    std::string getcouleur ()const;

    static std::string traduireCouleur(const std::string& c) ;

     std::string style() const;
};



class Rectangle : public Forme {
private:
    int x1, y1, x2, y2, x3, y3, x4, y4;

public:
    Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :
        x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
    std::string type() const override{ return "rectangle";}

    std::string tostring() const override {
        return "Rectangle " + std::to_string(x1) + " " + std::to_string(y1) + " " + std::to_string(x2) + " " + std::to_string(y2) + " "
           + std::to_string(x3) + " " + std::to_string(y3) + " " + std::to_string(x4) + " " + std::to_string(y4)+ Forme::tostring();
    }

    int getx1() const override{ return x1;};
    int gety1() const override{ return y1;};
    int getx2() const override{ return x2;};
    int gety2() const override{ return y2;};
    int getx3() const override{ return x3;};
    int gety3() const override{ return y3;};
    int getx4() const override{ return x4;};
    int gety4() const override{ return y4;};
    void PositionX1(int x){ this->x1 = x;}
    void PositionY1(int x){ this->y1 = x;}
    void PositionX2(int x){ this->x2 = x;}
    void PositionY2(int x){ this->y2 = x;}
    void PositionX3(int x){ this->x3 = x;}
    void PositionY3(int x){ this->y3 = x;}
    void PositionX4(int x){ this->x4 = x;}
    void PositionY4(int x){ this->y4 = x;}
    std::string dessiner() const override;

};



class Carre : public Forme {
private:
    int x, y, taille;

public:
    Carre(int x, int y, int t) : x(x), y(y), taille(t) {}
    std::string type() const override{ return "carre";}

    std::string tostring() const override {
        return "Carre " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(taille)+ Forme::tostring();
    }
        int getx() const override{ return x;};
    int gety() const override{ return y;};
    int gettaille() const override{ return taille;}
    void PositionX(int x){ this->x = x;}
    void PositionY(int y) { this->y = y;}
    void Taille(int t) { this->taille = t;}
    std::string dessiner() const override;
};


class Triangle : public Forme {
private:
    int x, y, longueur, hauteur;

public:
    Triangle(int x, int y, int longueur, int hauteur) : x(x), y(y), longueur(longueur), hauteur(hauteur) {}
    std::string type() const override{ return "triangle";}

    std::string tostring() const override {
        return "Triangle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(longueur) + " " + std::to_string(hauteur)+ Forme::tostring();
    }
        int getx() const override{ return x;}
    int gety() const override{ return y;}
    int getlong() const override{ return longueur;}
    int gethaut() const override{ return hauteur;}
    void PositionX(int x){ this->x = x;}
    void PositionY(int y){ this->x = y;}
    void Longueur(int l) {this->longueur = l;}

        void Hauteur(int hauteur) {this->hauteur = hauteur;}

        std::string dessiner() const;

};



class Cercle : public Forme {
private:
    int x, y, rayon;

public:
    Cercle(int x, int y, int rayon) : x(x), y(y), rayon(rayon) {}
    std::string type() const override{ return "cercle";}

    std::string tostring() const override {
        return "Cercle " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(rayon)+ Forme::tostring();
    }
            int getx() const override{ return x;}
    int gety() const override{ return y;}
    int getray() const override{ return rayon;}
    void PositionX(int x){ this->x = x;}
    void PositionY(int y){ this->x = y;}
    void Rayon(int rayon) {this->rayon = rayon;}
    std::string dessiner() const override;
};



class Ellipse : public Forme {
private:
    int x, y, longueur, hauteur;

public:
    Ellipse(int x, int y, int longueur, int hauteur) : x(x), y(y), longueur(longueur), hauteur(hauteur) {}
    std::string type() const override{ return "ellipse";}

    std::string tostring() const override {
        return "Ellipse " + std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(longueur) + " " + std::to_string(hauteur)+ Forme::tostring();
    }
    int getx() const override{ return x;}
    int gety() const override{ return y;}
    int getlong() const override{ return longueur;}
    int gethaut() const override{ return hauteur;}
    void PositionX(int x){ this->x = x;}
    void PositionY(int y){ this->x = y;}
    void Longueur(int l) {
            this->longueur= l;
        }

    void Hauteur(int hauteur) {
            this->hauteur = hauteur;
        }
    std::string dessiner() const override;
};



class Ligne : public Forme {
private:
    int x1, y1, x2, y2;

public:
    Ligne(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
    std::string type() const override{ return "ligne";}

    std::string tostring() const override {
        return "Ligne de " + std::to_string(x1) + " " + std::to_string(y1) + " à " + std::to_string(x2) + " " + std::to_string(y2)+ Forme::tostring();
    }
    int getx1() const override{ return x1;}
    int gety1() const override{ return y1;}
    int getx2() const override{ return x2;}
    int gety2() const override{ return y2;}
    void PositionX1(int x){ this->x1 = x;}
    void PositionY1(int x){ this->y1 = x;}
    void PositionX2(int x){ this->x2 = x;}
    void PositionY2(int x){ this->y2 = x;}
    std::string dessiner() const override;
};

class Chemin : public Forme {
private:
    std::vector<std::pair<int, int>> points;

public:
    Chemin(const std::vector<std::pair<int, int>>& points) : points(points) {}
    std::string type() const override{ return "chemin";}

    std::string tostring() const override {
        std::string ss="Chemin ";
        for (const auto& point : points) {
            ss +=std::to_string(point.first) + " " + std::to_string(point.second) + ", ";
        }

        if (!ss.empty() && ss.length() > 2) {
                    ss.erase(ss.size()-2);
                }
        return ss+ Forme::tostring();
    }
    int getx() const override{ return points[0].first;}
    int gety() const override{ return points[0].second;}
    std::string dessiner() const override;
};


class Texte : public Forme {
private:
    int x, y;
    std::string texte, police;

public:
    Texte(int x, int y, const std::string& texte, const std::string& police) :
        x(x), y(y), texte(texte), police(police) {}
    std::string type() const override{ return "texte";}

    std::string tostring() const override {
        return "Texte " + std::to_string(x) + " " + std::to_string(y) + " " + texte + " " + police+ Forme::tostring();
    }
     int getx() const override{ return x;}
    int gety() const override{ return y;}
    void PositionX(int x){ this->x = x;}
    void PositionY(int y){ this->x = y;}

    void setTexte(const std::string &value);
    void setPolice(const std::string &value);
    std::string dessiner() const override;
};
