#pragma once
#include "expression.hh"

enum class OperateurTernaire {
    ifthenelse,
    ifthen
};

class ExpressionTernaire : public Expression {
public:
    ExpressionTernaire(const ExpressionTernaire &) = default;
    ExpressionTernaire(bool condition, ExpressionPtr exp1, ExpressionPtr exp2, OperateurTernaire op);
    ~ExpressionTernaire() = default;

    void calculer( Contexte_fig& contexte)  override;

private:
    bool _condition;
    ExpressionPtr _exp1;
    ExpressionPtr _exp2;
    OperateurTernaire _op;
};
