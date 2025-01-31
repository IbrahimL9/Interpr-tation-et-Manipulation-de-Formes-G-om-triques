#include "variable_att.hh"

std::vector<std::shared_ptr<Forme> > VariableSansAffectation::getVariable_sans_affect() const
{
    return variable_sans_affect;
}

void variable_att::ajouter(std::string const & cle, Attributs att){
    if (variables.find(cle) != variables.end()) {
                variables[cle]->ajouterAttribut(att);
            } else {
                std::cerr << "Erreur : La clé '" << cle << "' n'existe pas." << std::endl;
            }
}


std::string variable_att::tostring() const {
         std::ostringstream oss;
         for (const auto& pair : variables) {
                oss << pair.first << " = " << pair.second->tostring() << "\n";
         }
         return oss.str();
     }


std::shared_ptr<Forme> variable_att::acces(std::string t){
       if (variables.find(t) != variables.end()) {
                  return variables[t];
               }

       return nullptr; //  cas ou il nexiste pas
   }



std::shared_ptr<Forme> VariableSansAffectation::acces(std::string t, int n){
        int k=0;
        for(auto i : variable_sans_affect){
            if((*i).type()==t && k==n){
                return i;
            }
           if((*i).type()==t){
            k++;}
        }
        return nullptr; //  cas ou il nexiste pas
    }

std::string VariableSansAffectation::toString(std::string t, int n) const{
    int k=0;
    for(auto i : variable_sans_affect){
    if((*i).type()==t && k==n){
        return (*i).tostring();
    }
   if((*i).type()==t){
        k++;}
    }
return "n'existe pas";
}


std::string VariableSansAffectation::affichage() const {
             std::ostringstream oss;
             for (auto & p : variable_sans_affect) {
                    oss << p->tostring() << "\n";
             }
             return oss.str();
         }

void VariableSansAffectation::ajouter(std::string t, int n, Attributs att){
    if (acces(t,n)!=nullptr) {
                acces(t,n)->ajouterAttribut(att);
            } else {
                std::cerr << "Erreur : la variable n'existe pas §!!!!!!!!!!!"<<std::endl;
            }
}


std::string Variable_idb::variantToString(const VariableType& valeur) {
    if (auto val = std::get_if<int>(&valeur)) {
        return std::to_string(*val);
    } else if (auto val = std::get_if<double>(&valeur)) {
        return std::to_string(*val);
    } else if (auto val = std::get_if<bool>(&valeur)) {
        return *val ? "true" : "false";
    }
    return "inconnu";
}

std::string Variable_idb::tostring() const {
    std::ostringstream oss;
    for (const auto& pair : variables_idb) {
        oss << pair.first << " = " << variantToString(pair.second) << std::endl;
    }
    return oss.str();
}






