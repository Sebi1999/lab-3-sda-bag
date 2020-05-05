#include "Bag.h"
#include "BagIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <exception>
#include <iostream>
using namespace std;



 Bag::Bag() {
	
	capacityX = 100;
	capacityZ = 200;
	lengthX = 0;
	lengthZ = 0;
	Z = new TElem[capacityZ];	//alocam spatiu pt X si Z
	X = new TElem[capacityX];
	//constructor
}



void Bag::add(TElem elem) {
	
	if (lengthZ == capacityX)				//cand lungime=capacitate,dublam capacitatea si prin urmare se aloca loc in X 
	{
		if (capacityX != 0) capacityX *= 2;
		else capacityX = capacityX + 1;
		TElem* U2 = new TElem[capacityX];
		for (int i = 0; i < lengthZ; ++i)
		{
			X2[i] = X[i];
		}
		delete X;
		X = X2;
	}
	if (lengthX == capacityZ)	//cand lungime=capacitate,dublam capacitatea si prin urmare se aloca un nou spatiu in P
		if (capacityZ != 0) capacityZ *= 2;
		else capacityZ = capacityZ + 1;
		capacityZ *= 2;
		TElem* Z2 = new TElem[capacityZ];
		for (int i = 0; i < lengthX; ++i)
		{
			Z2[i] = Z[i];
		}
		delete Z;
		Z = Z2;
	}

	if (search(elem) == false) {	//cand elem nu se afla in u,atunci Z si X se maresc
		X[lengthX] = elem;
		Z[lengthZ] = lengthX++;;
		lengthZ++;
	}
	else {
		for (int i = 0; i < lengthX; ++i) {	//doar Z se mareste
			if (X[i] == elem) {
				Z[lengthZ] = i;
				lengthZ++;
			}
		}
	}
}


bool Bag::remove(TElem elem)
{
	int iElem = -1;
	for (int i = 0; i < lengthX; i++)		//cand gasim elem,marcam pozitia acestuia
		if (X[i] == elem)  iElem = i;

	if (iElem != -1) {					//vedem daca exista elem
		int anz = 0, last = -1;
		for (int i = 0; i <= lengthZ; i++) {
			if (Z[i] == iElem) {
				anz++;					//vedem cate elem se afla in Z
				last = i;
			}
		}
		if (last != -1) {
			if (anz == 1) {				//daca apare doar odata
				for (int i = iElem; i < lengthX; i++)	//stergem din X
					X[i] = X[i + 1];
				lengthX--;
				if (iElem == lengthX)		//verificam deca este ultimul elem din Z
					for (int i = last; i < lengthZ; i++) { //in cazul asta il stergem din Z
						Z[i] = Z[i + 1];
					}
				else
				{
					for (int i = last; i < lengthZ; i++) {
						Z[i] = Z[i + 1];
					}
					for (int i = 0; i < lengthZ; i++) {
						if (Z[i] >= iElem)
							Z[i]--;
					}
				}
				lengthZ--;
				return true;
			}
			else {					//daca aapre un elem de mai multe ori,va fi sters din Z

				for (int i = last; i < lengthZ; i++)
					Z[i] = Z[i + 1];
				lengthZ--;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}



bool Bag::search(TElem elem) const {
	/
	for (int i = 0; i < lengthX; ++i) {		//cautam elem
		if (X[i] == elem) return true;
	}
	return false;
}



int Bag::nrOccurrences(TElem elem) const {
	
	if (search(elem) == true) {					
		int nr = 0;								
		for (int i = 0; i < lengthZ; ++i) {
			if (X[Z[i]] == elem) nr = nr + 1;
		}
		if (nr != 0)return nr;
	}
	return 0;
}



int Bag::size() const {
	
	if (lengthZ > 0) return lengthZ;		//numa daca lungimea>0,atunci returneaza
	return 0;
}



bool Bag::isEmpty() const {
	
	if (lengthZ == 0) return true;			//Array este gol sau nu
	return false;
}



BagIterator Bag::iterator() const {
	
	return BagIterator(*this);
}


Bag::~Bag() {
	
	delete[] X;				
	delete[] Z;
	//destructor
}
