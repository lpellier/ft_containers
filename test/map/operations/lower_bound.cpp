#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	lower_bound() {
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator itlow;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b

	mymap.erase(itlow);        // erases [itlow,itup)

	// print content:
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

int main() {
	lower_bound();
	exit(EXIT_SUCCESS);
}
