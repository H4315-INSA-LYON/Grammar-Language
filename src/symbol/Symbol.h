#ifndef SYMBOL_H
#define SYMBOL_H
#include "lutin.h"
namespace lutinCompiler
{
    class Symbol
    {
        public:
            Symbol(TOKEN token);
            virtual ~Symbol();
            void print();
            operator int() const;
        protected:
            TOKEN token;
    };

}

#endif // SYMBOL_H
