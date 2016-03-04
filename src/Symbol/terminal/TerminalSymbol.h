#ifndef TERMINALSYMBOL_H
#define TERMINALSYMBOL_H

class Var : public Symbol
{
    public:
        Var();
        ~Var();

};

class Const : public Symbol
{
    public:
        Const();
        ~Const();

};

class Ecrire : public Symbol
{
    public:
        Ecrire();
        ~Ecrire();
        virtual void eval();

};

class Lire : public Symbol
{
    public:
        Ecrire();
        ~Ecrire();
        virtual void eval();

};

class Id : public Symbol
{
    public:
        Ecrire();
        ~Ecrire();
};
class Num : public Symbol
{
    public:
        Num();
        ~Num();
};
class Equal : public Symbol
{
    public:
        Ecrire();
        ~Ecrire();
};
class Affect : public Symbol
{
    public:
        Ecrire();
        ~Ecrire();
};
class Coma : public Symbol
{
    public:
        Coma();
        ~Coma();
};
class PComa : public Symbol
{
    public:
        PComa();
        ~PComa();
};
class OpenBracket : public Symbol
{
    public:
        OpenBracket();
        ~OpenBracket();

};
class CloseBracket : public Symbol
{
    public:
        CloseBracket();
        ~CloseBracket();

};
class Plus : public Symbol
{
    public:
        Plus();
        ~Plus();

};
class Minus : public Symbol
{
    public:
        Minus();
        ~Minus();

};
class Times : public Symbol
{
    public:
        Times();
        ~Times();

};
class Div : public Symbol
{
    public:
        Div();
        ~Div();

};
class Eof : public Symbol
{
    public:
        Eof();
        ~Eof();

};

#endif // TERMINALSYMBOL_H
