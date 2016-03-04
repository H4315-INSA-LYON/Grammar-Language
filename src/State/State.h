#ifndef STATE_H
#define STATE_H

namespace lutinCompiler
{
class State
{
    public:
        State (string name);
        virtual ~State();
        void print();
        virtual bool transition (Automate & automate, Symbole * s) = 0;
    protected:
        string name;
        }
}
#endif // STATE_H
