#ifndef INST_H_INCLUDED
#define INST_H_INCLUDED

  class State6: public State
{
     State6 (string name);
     ~State6();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };

  class State10: public State
{
     State10 (string name);
     ~State10();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };

  class State11: public State
{
     State11 (string name);
     ~State11();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };
  class State12: public State
{
     State12 (string name);
     ~State12();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };

  class State13: public State
{
     State13 (string name);
     ~State13();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };

  class State18: public State
{
     State18 (string name);
     ~State18();
     void print();
     bool transition(Automat & automat, Symbol * s) = 0;
     };






#endif // INST_H_INCLUDED
