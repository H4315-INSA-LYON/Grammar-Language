#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <map>
#include <string>
#include "../Symbol.h"

namespace lutinCompiler
{
    class Expression : public Symbol
    {
       public:
        Expression():Symbol(0){}
        virtual ~Expr(){}
        virtual double eval(const map<string,double> & values)=0;

    };
}

#endif
