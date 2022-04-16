#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	clear() {
	NAMESPACE::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

}

int main() {
	clear();
	exit(EXIT_SUCCESS);
}
