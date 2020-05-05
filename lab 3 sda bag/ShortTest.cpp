#include "Bag.h"
#include "BagIterator.h"
#include "ExtendedTest.h"
#include "ShortTest.h"
#include <iostream>
#include <assert.h>
using namespace std;

void testAll() {
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	b.add(7);
	b.add(6);
	b.add(10);
	b.add(99);
	b.add(3);
	b.add(18);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(6) == true);
	assert(b.remove(1) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
}