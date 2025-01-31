#pragma once
#include "expression.hh"
#include "contexte.hh"

class ExpressionModif : public Expression {
public:
    ExpressionModif(std::string const & ident,Attributs attvar);
    ExpressionModif(std::string const & fig,int number,Attributs attvar);
    ~ExpressionModif() = default;

    void calculer( Contexte_fig& contexte) override;

private:
    std::string _ident;
    Attributs _attvar;
    std::string _fig;
    int _number;
};
 
