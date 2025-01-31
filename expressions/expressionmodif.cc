#include "expressionmodif.hh"

ExpressionModif::ExpressionModif(std::string const & ident,Attributs attvar):
    _ident(ident),_attvar(attvar),_fig(""),_number(-1){}
    
ExpressionModif::ExpressionModif(std::string const & fig,int number,Attributs attvar):
    _ident(""),_attvar(attvar),_fig(fig),_number(number){}

void ExpressionModif::calculer( Contexte_fig& contexte) {
    
    if(_fig==""){ //modif a partir du nom de la variable
       contexte.ajouterAttributVariableForme(_ident,_attvar); 
        
    }else{ //modif a partir de fig[number]
     contexte.ajouterAttribut(_fig,_number, _attvar);   
    }
}
