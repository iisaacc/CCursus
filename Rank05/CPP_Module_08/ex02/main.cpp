#include "MutantStack.hpp"


// Own tests
int main()
{
	MutantStack<int> mstack;
	MutantStack<int> mstack_cpy;
	mstack.push(5);
	mstack.push(17);
	mstack_cpy = mstack;
	std::cout << "Original stack top: "<< mstack.top() << std::endl;
	std::cout << "Copied stack top: "<< mstack_cpy.top() << std::endl;
	mstack_cpy.pop();
	std::cout << "Original stack size: "<< mstack.size() << std::endl;
	std::cout << "Copied stack size: "<< mstack_cpy.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(1);
	//Print stack
	std::cout << "Original stack: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// Subject tests
/*int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}*/
// Same code but using deque
/*int main()
{
	std::deque<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::deque<int>::iterator it = mstack.begin();
	std::deque<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}*/
