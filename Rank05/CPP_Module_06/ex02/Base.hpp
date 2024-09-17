#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

class Base {
	private:
	public:
		virtual ~Base();
		Base	*generate(void);
		virtual void identify(Base *p);
		virtual void identify(Base &p);

};