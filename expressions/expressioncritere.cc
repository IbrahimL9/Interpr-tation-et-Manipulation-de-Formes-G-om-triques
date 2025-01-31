#include "expressioncritere.hh"

ExpressionCritere::ExpressionCritere(std::string const & ident,std::string const & cri,int val):
    _ident(ident),_fig(""), _number(-1), _cri(cri), _val(val){} 
    
ExpressionCritere::ExpressionCritere(std::string const & fig,int number,std::string const & cri,int val):
  _ident(""),_fig(fig) ,_number(number), _cri(cri),_val(val){} 

void ExpressionCritere::calculer( Contexte_fig& contexte) {
    
    if(_fig==""){ //modif a partir du nom de la variable
       contexte.appliquer(_ident,_cri,_val); 
        
    }else{ //modif a partir de fig[number]
     contexte.appliquer(_fig,_number,_cri,_val);   
    }
}
