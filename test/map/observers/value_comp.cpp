#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	value_comp() {
	NAMESPACE::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element

	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

int main() {
	value_comp();
	exit(EXIT_SUCCESS);
}
