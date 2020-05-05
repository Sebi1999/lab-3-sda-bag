#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;



BagIterator::BagIterator(const Bag& c) : bag(c)
{
	i = 0;
}



void BagIterator::first() {
	
	i = 0;							//returneaza primu elem
}



void BagIterator::next() {
	
	if (i < bag.lengthX) {		//returneaza urmatorul elem,asta doar daca nu a ajuns la final
		i += 1;
	}
	else {
		exception e;
		throw e;
	}
}


bool BagIterator::valid() const {

	if (i < bag.lengthX) {		//verificam daca se afla in Array
		return true;
	}
	return false;
}

TElem BagIterator::getCurrent() const
{
	if (valid() == true) {				//returneaza elem daca se afla inca in Array
		return bag.U[bag.P[i]];
	}
	else {
		exception e;
		throw e;
	}
	return NULL_TELEM
}
