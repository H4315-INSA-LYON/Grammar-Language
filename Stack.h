#include "lutin.h"

namespace lutinCompiler
{
	template <class T>
	class Stack
	{
	public:
		Stack()
		{

		}
		~Stack();

		bool push(T);
		bool pop(T&);
		bool empty();
		T top();

	private:


	};

}