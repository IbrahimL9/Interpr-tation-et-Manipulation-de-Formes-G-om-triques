#pragma once
#include "expression.hh"
#include "contexte.hh"

class ExpressionCritere : public Expression {
public:
    ExpressionCritere(std::string const & ident,std::string const & cri,int val);
    ExpressionCritere(std::string const & fig,int number,std::string const & cri,int val);
    ~ExpressionCritere() = default;

    void calculer( Contexte_fig& contexte) override;

private:
    std::string _ident;
    std::string _fig;
    int _number;
    std::string _cri;
    int _val;
};
  
