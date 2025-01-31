#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <memory>
#include <iostream>
#include "contexte.hh"


class Driver {
private:
    Contexte var;
    Contexte_fig variables;

public:
    Driver() = default;
    ~Driver() = default;


        //var_att
        Contexte_fig & getContexte(){
            return variables;
        }
        void ajouterVariableForme(const std::string& nom, std::shared_ptr<Forme> forme) {
            variables.ajouterVariableForme(nom, forme);
        }

        void ajouterAttributVariableForme(const std::string& nom, Attributs att) {
            variables.ajouterAttributVariableForme(nom, att);
        }

        std::string varAttToString() const {
                return variables.varatt_tostring();
            }

        //var sans aff
        void ajouterVariableSansAffectation(std::shared_ptr<Forme> f) {
                variables.ajouterVariableSansAffectation(f);
            }

        std::string varSansAffectationToString() const {
                return variables.var_sans_affec_tostring();
            }

        void ajouterAttribut(const std::string& nom, int n, Attributs att) {
               variables.ajouterAttribut(nom, n, att);
           }

        std::string afficher(std::string t, int n) {
                return variables.afficher(t, n);
            }

        //idb
        void ajouterIdb(const std::string &nom, VariableType valeur) {
                variables.ajouterIdb(nom, valeur);
            }

        std::string varIdbToString() const {
                return variables.varidb_tostring();
            }


        //couleur
        void ajouterCouleur(const std::string& nom, std::string c) {
                variables.ajouter_c(nom, c);
            }

        std::string couleur_toString() const {
                return variables.couleur_tostring();
            }

        //acceder aux formes
        std::shared_ptr<Forme> accesForme(std::string t, int n) {
                return variables.accesforme(t, n);
            }

        std::shared_ptr<Forme> accesForme(std::string t) {
                return variables.accesforme(t);
            }
       

        //appliquer une modification à une forme
            void appliquerModification(std::string fig, int cle, std::string const & cri, int val) {
                variables.appliquer(fig, cle, cri, val);
            }

            void appliquerModification(std::string const & cle, std::string const & cri, int val) {
                variables.appliquer(cle, cri, val);
            }
         bool evaluationcouleur(std::string const & cle,bool is, std::string const & clr) {
         
             return variables.evaluationcoul(cle,is,clr);
        }
         bool evaluationcouleur(std::string const & f,int cle,bool is, std::string const & clr) {
                      return variables.evaluationcoul(f,cle,is,clr);             
        }
        bool evaluation(std::string const & f,int cle, std::string const & critere, std::string const & signe, int val) {
                return variables.eval( f, cle, critere,signe,val);
        }
        bool evaluation(std::string const & cle, std::string const & critere, std::string const & signe, int val) {
                         return variables.eval(cle, critere,signe,val);   
        }


        Contexte_fig getVariables() const;
};

#endif
