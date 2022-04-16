#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	upper_bound() {
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itup);        // erases [itlow,itup)

	// print content:
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

int main() {
	upper_bound();
	exit(EXIT_SUCCESS);
}
