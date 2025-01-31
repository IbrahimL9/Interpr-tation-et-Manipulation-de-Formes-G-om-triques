#pragma once

#include <string>
#include <map>
#include <memory>
#include "variable_att.hh"
#include "expressionmodif.hh"




class Contexte {
private:
    std::map<std::string, double> variables;

public:
    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    double& get(const std::string & nom);
    const double& get(const std::string & nom) const;

    double& operator[](const std::string & nom);
    const double& operator[](const std::string & nom) const;

};


class Contexte_fig{
 private:
    variable_att var_att;
    VariableSansAffectation var_sans_aff;
    Variable_idb var_idb;
    std::map<std::string,std::string> couleurs;

 public:
 Contexte_fig()=default;
 ~Contexte_fig()=default;
 

    //var_att
    void ajouterVariableForme(const std::string& nom, std::shared_ptr<Forme> forme) { var_att.ajouter(nom, forme);}

    void ajouterAttributVariableForme(const std::string& nom, Attributs att) { var_att.ajouter(nom, att);}
    
    std::string varatt_tostring() const { return var_att.tostring(); }
    std::shared_ptr<Forme> accesforme(std::string t){ return var_att.acces(t); }
 
 
 
    //var_sans_aff
    void ajouterAttribut(const std::string& nom,int n, Attributs att) { var_sans_aff.ajouter(nom,n, att);}
    
    std::string var_sans_affec_tostring() const { return var_sans_aff.affichage(); }
    
    void ajouterVariableSansAffectation(std::shared_ptr<Forme> f){ var_sans_aff.ajouter(f); }
    
    std::shared_ptr<Forme> accesforme(std::string t, int n){
        return var_sans_aff.acces(t,n);
    }
    std::string afficher(std::string t, int n){
        return  var_sans_aff.toString(t,n);
    }

    
    
    //idb
    void ajouterIdb(const std::string &nom,VariableType valeur){ var_idb.ajouter(nom,valeur);}
    std::string varidb_tostring() const { return var_idb.tostring(); }

    

    //couleur
    void ajouter_c(const std::string& cle, const std::string& valeur) { couleurs[cle] = valeur; }
    std::string couleur_tostring()const;
 
   bool eval(std::string const & cle, std::string const & critere, std::string const & signe, int val);
   bool eval(std::string const & f,int cle, std::string const & critere, std::string const & signe, int val);

   bool evaluationcoul(std::string const & cle,bool is, std::string const & clr);
   bool evaluationcoul(std::string const & f,int cle,bool is, std::string const & clr);

   void  appliquer(std::string fig,int cle ,std::string const & cri ,int val);
   void  appliquer(std::string const &  cle ,std::string const & cri ,int val);

    VariableSansAffectation getVar_sans_aff() const;
};

