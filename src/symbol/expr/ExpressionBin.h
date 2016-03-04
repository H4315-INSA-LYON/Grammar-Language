#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <map>
#include <string>
#include "Expression.h"

namespace lutinCompiler
{
    class ExpressionBin : public Expression
    {
       public:
        ExpressionBin():Symbol(0){}
        virtual ~Expr(){}
        virtual double eval(const map<string,double> & values)=0;

    };
}

#endif
