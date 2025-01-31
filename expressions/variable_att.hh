#include "forme.hh"
#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <variant>

class variable_att{
public:
    variable_att()=default;
    void afficher();
    void ajouter(std::string const & cle, std::shared_ptr<Forme> valeur){ variables[cle]=valeur; };
    void ajouter(std::string const & cle, Attributs att);
   std::string tostring() const;
   std::shared_ptr<Forme> acces(std::string t);

private:
     std::map<std::string, std::shared_ptr<Forme>> variables;
};

class VariableSansAffectation{
public:
    VariableSansAffectation()=default;
    void ajouter(std::shared_ptr<Forme> f){  variable_sans_affect.push_back(std::move(f));   }
    std::shared_ptr<Forme> acces(std::string t, int n);
    std::string toString(std::string t, int n) const;

    std::string affichage() const ;
    void ajouter(std::string t, int n, Attributs att);
    std::vector<std::shared_ptr<Forme> > getVariable_sans_affect() const;

private:
std::vector<std::shared_ptr<Forme>> variable_sans_affect;
};


using VariableType = std::variant<int, double, bool>;

class Variable_idb {
public:
    Variable_idb() = default;

    void ajouter(const std::string& nom, VariableType valeur) { variables_idb[nom] = valeur;}
    static std::string variantToString(const VariableType& valeur);
    std::string tostring() const;

private:
    std::map<std::string, VariableType> variables_idb;
};


