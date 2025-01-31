 #pragma once
#include <memory>

class Contexte_fig;
class Expression {
public:

    virtual void calculer( Contexte_fig & contexte) =0;
        
};

using ExpressionPtr = std::shared_ptr<Expression>;

