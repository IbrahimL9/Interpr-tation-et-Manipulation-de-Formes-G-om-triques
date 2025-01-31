#include "contexte.hh"

double& Contexte::get(const std::string & nom) {
    return variables[nom];
}

const double& Contexte::get(const std::string & nom) const {
    return variables.at(nom);
}

double& Contexte::operator[](const std::string & nom) {
    return variables[nom];
}

const double& Contexte::operator[](const std::string & nom) const {
    return variables.at(nom);
}
VariableSansAffectation Contexte_fig::getVar_sans_aff() const
{
    return var_sans_aff;
}

std::string Contexte_fig::couleur_tostring()const {
    std::string resultat = "";
    for (const auto& paire : couleurs) {
        resultat += paire.first + " = " + paire.second + ", ";
    }
    if (!couleurs.empty()) {
        resultat.pop_back();
        resultat.pop_back();
    }
    return resultat;
}


bool Contexte_fig::eval(std::string const & cle, std::string const & critere, std::string const & signe, int val) {
   int k = -1;
   if (critere == "hauteur") {
       k = accesforme(cle)->gethaut();
   } else if (critere == "longueur") {
       k = accesforme(cle)->getlong();
   } else if (critere == "X") {
       k = accesforme(cle)->getx();
   } else if (critere == "Y") {
       k = accesforme(cle)->gety();
   }else if (critere == "X1") {
       k = accesforme(cle)->getx1();
   } else if (critere == "Y1") {
       k = accesforme(cle)->gety1();
   }else if (critere == "X2") {
       k = accesforme(cle)->getx2();
   } else if (critere == "Y2") {
       k = accesforme(cle)->gety2();
   }else if (critere == "X3") {
       k = accesforme(cle)->getx3();
   } else if (critere == "Y3") {
       k = accesforme(cle)->gety3();
   }else if (critere == "X4") {
       k = accesforme(cle)->getx4();
   } else if (critere == "Y4") {
       k = accesforme(cle)->gety4();
   }else if (critere == "taille") {
       k = accesforme(cle)->gettaille();
   } else if (critere == "ray") {
       k = accesforme(cle)->getray();
   }


   bool result = false;
   if (signe == ">") {
       result = (k > val);
   } else if (signe == ">=") {
       result = (k >= val);
   } else if (signe == "<") {
       result = (k < val);
   } else if (signe == "<=") {
       result = (k <= val);
   } else if (signe == "==") {
       result = (k == val);
   } else if (signe == "!=") {
       result = (k != val);
   }

   return result;
}


bool Contexte_fig::eval(std::string const & f,int cle, std::string const & critere, std::string const & signe, int val) {
    int k = -1;
        if (critere == "hauteur") {
        k = accesforme(f,cle)->gethaut();
    } else if (critere == "longueur") {
        k = accesforme(f,cle)->getlong();
    } else if (critere == "X") {
        k = accesforme(f,cle)->getx();
    } else if (critere == "Y") {
        k = accesforme(f,cle)->gety();
    }else if (critere == "X1") {
        k = accesforme(f,cle)->getx1();
    } else if (critere == "Y1") {
        k = accesforme(f,cle)->gety1();
    }else if (critere == "X2") {
        k = accesforme(f,cle)->getx2();
    } else if (critere == "Y2") {
        k = accesforme(f,cle)->gety2();
    }else if (critere == "X3") {
        k = accesforme(f,cle)->getx3();
    } else if (critere == "Y3") {
        k = accesforme(f,cle)->gety3();
    }else if (critere == "X4") {
        k = accesforme(f,cle)->getx4();
    } else if (critere == "Y4") {
        k = accesforme(f,cle)->gety4();
    }else if (critere == "taille") {
        k = accesforme(f,cle)->gettaille();
    } else if (critere == "ray") {
        k = accesforme(f,cle)->getray();
    }

    bool result = false;
    if (signe == ">") {
        result = (k > val);
    } else if (signe == ">=") {
        result = (k >= val);
    } else if (signe == "<") {
        result = (k < val);
    } else if (signe == "<=") {
        result = (k <= val);
    } else if (signe == "==") {
        result = (k == val);
    } else if (signe == "!=") {
        result = (k != val);
    }

    return result;
}


bool Contexte_fig::evaluationcoul(std::string const & cle,bool is, std::string const & clr) {
   std::string x=accesforme(cle)->getcouleur();
   if(x=="" || x!=clr){
       return (false==is);
   }else return (true==is);
}


bool Contexte_fig::evaluationcoul(std::string const & f,int cle,bool is, std::string const & clr) {
   std::string x=accesforme(f,cle)->getcouleur();
   if(x=="" || x!=clr){
       return (false==is);
   }else return (true==is);
}



void  Contexte_fig::appliquer(std::string fig,int cle ,std::string const & cri ,int val){

    auto rec=std::dynamic_pointer_cast<Rectangle> (accesforme(fig,cle) );
   if(rec != nullptr){
       if(cri=="X1"){rec->PositionX1(val);}
       else if(cri=="Y1"){ rec->PositionY1(val);}
       else if(cri=="X2"){ rec->PositionY1(val);}
       else if(cri=="Y2"){rec->PositionY2(val);}
       else if(cri=="X3"){rec->PositionX3(val);}
       else if(cri=="Y3"){rec->PositionY3(val);}
       else if(cri=="X4"){rec->PositionX4(val);}
       else if(cri=="Y4"){rec->PositionY4(val);}
       else {std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;}
    }else{
     auto  car=std::dynamic_pointer_cast<Carre> (accesforme(fig,cle));
    if(car != nullptr){
         if(cri=="X"){car->PositionX(val);}
       else if(cri=="Y"){ car->PositionY(val);}
       else if(cri=="taille"){ car->Taille(val);}
              else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;
    }
    else{
        auto tri=std::dynamic_pointer_cast<Triangle> (accesforme(fig,cle));
        if(tri != nullptr){
             if(cri=="X"){tri->PositionX(val);}
            else if(cri=="Y"){ tri->PositionY(val);}
            else if(cri=="longueur"){ tri->Longueur(val);}
            else if(cri=="hauteur"){ tri->Hauteur(val);}
            else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

        }
        else{
          auto crcl=  std::dynamic_pointer_cast<Cercle> (accesforme(fig,cle));
          if(crcl != nullptr){
            if(cri=="X"){crcl->PositionX(val);}
            else if(cri=="Y"){ crcl->PositionY(val);}
            else if(cri=="ray"){ crcl->Rayon(val);}
            else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

        }
          else{
              auto eli = std::dynamic_pointer_cast<Ellipse> (accesforme(fig,cle)) ;
              if(eli!= nullptr){
                if(cri=="X"){eli->PositionX(val);}
                else if(cri=="Y"){ eli->PositionY(val);}
                else if(cri=="longueur"){ eli->Longueur(val);}
                else if(cri=="hauteur"){ eli->Hauteur(val);}
                else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;
            }
              else{
                  auto lgn= std::dynamic_pointer_cast<Ligne> (accesforme(fig,cle));
                  if(lgn!= nullptr ){
                        if(cri=="X1"){lgn->PositionX1(val);}
                        else if(cri=="Y1"){ lgn->PositionY1(val);}
                        else if(cri=="X2"){ lgn->PositionX2(val);}
                        else if(cri=="Y2"){ lgn->PositionY2(val);}
                        else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

                }
                  else{
                      auto chmn=std::dynamic_pointer_cast<Chemin> (accesforme(fig,cle));
                      if(chmn!= nullptr){
                          //jsp quoi faire
                    }
                      else{ //textes
                        auto txt =  std::dynamic_pointer_cast<Texte> (accesforme(fig,cle));
                                                  //jsp quoi faire

                    }
                }
            }
        }
        }
    }
    }


}


void  Contexte_fig::appliquer(std::string const &  cle ,std::string const & cri ,int val){
    auto rec=std::dynamic_pointer_cast<Rectangle> (accesforme(cle) );
   if(rec != nullptr){
       if(cri=="X1"){rec->PositionX1(val);}
       else if(cri=="Y1"){ rec->PositionY1(val);}
       else if(cri=="X2"){ rec->PositionY1(val);}
       else if(cri=="Y2"){rec->PositionY2(val);}
       else if(cri=="X3"){rec->PositionX3(val);}
       else if(cri=="Y3"){rec->PositionY3(val);}
       else if(cri=="X4"){rec->PositionX4(val);}
       else if(cri=="Y4"){rec->PositionY4(val);}
       else {std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;}
    }else{
     auto  car=std::dynamic_pointer_cast<Carre> (accesforme(cle));
    if(car != nullptr){
         if(cri=="X"){car->PositionX(val);}
       else if(cri=="Y"){ car->PositionY(val);}
       else if(cri=="taille"){ car->Taille(val);}
              else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;
    }
    else{
        auto tri=std::dynamic_pointer_cast<Triangle> (accesforme(cle));
        if(tri != nullptr){
             if(cri=="X"){tri->PositionX(val);}
            else if(cri=="Y"){ tri->PositionY(val);}
            else if(cri=="longueur"){ tri->Longueur(val);}
            else if(cri=="hauteur"){ tri->Hauteur(val);}
            else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

        }
        else{
          auto crcl=  std::dynamic_pointer_cast<Cercle> (accesforme(cle));
          if(crcl != nullptr){
            if(cri=="X"){crcl->PositionX(val);}
            else if(cri=="Y"){ crcl->PositionY(val);}
            else if(cri=="ray"){ crcl->Rayon(val);}
            else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

        }
          else{
              auto eli = std::dynamic_pointer_cast<Ellipse> (accesforme(cle)) ;
              if(eli!= nullptr){
                if(cri=="X"){eli->PositionX(val);}
                else if(cri=="Y"){ eli->PositionY(val);}
                else if(cri=="longueur"){ eli->Longueur(val);}
                else if(cri=="hauteur"){ eli->Hauteur(val);}
                else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;
            }
              else{
                  auto lgn= std::dynamic_pointer_cast<Ligne> (accesforme(cle));
                  if(lgn!= nullptr ){
                        if(cri=="X1"){lgn->PositionX1(val);}
                        else if(cri=="Y1"){ lgn->PositionY1(val);}
                        else if(cri=="X2"){ lgn->PositionX2(val);}
                        else if(cri=="Y2"){ lgn->PositionY2(val);}
                        else std::cerr<<"la figure n'a pas comme attribus : "<<cri<<std::endl;

                }
                  else{
                      auto chmn=std::dynamic_pointer_cast<Chemin> (accesforme(cle));
                      if(chmn!= nullptr){
                          //jsp quoi faire
                    }
                      else{ //textes
                        auto txt =  std::dynamic_pointer_cast<Texte> (accesforme(cle));
                                                  //jsp quoi faire

                    }
                }
            }
        }
        }
    }
    }


}




































