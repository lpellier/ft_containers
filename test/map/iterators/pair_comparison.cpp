#include "../../../containers/map/map.hpp"
#include "../../test.hpp"

void	pair_comparison() {
	NAMESPACE::pair<int, std::string> p1 = NAMESPACE::make_pair(15, "alo");
	NAMESPACE::pair<int, std::string> p2 = NAMESPACE::make_pair(10, "banane");
	NAMESPACE::pair<int, std::string> p3 = NAMESPACE::make_pair(15, "alo");


	std::cout << (p1 > p2) << std::endl;
	std::cout << (p1 >= p2) << std::endl;
	std::cout << (p1 < p2) << std::endl;
	std::cout << (p1 <= p2) << std::endl;
	std::cout << (p1 == p2) << std::endl;
	std::cout << (p1 != p2) << std::endl;

	std::cout << (p1 > p3) << std::endl;
	std::cout << (p1 >= p3) << std::endl;
	std::cout << (p1 < p3) << std::endl;
	std::cout << (p1 <= p3) << std::endl;
	std::cout << (p1 == p3) << std::endl;
	std::cout << (p1 != p3) << std::endl;

	std::cout << (p3 > p2) << std::endl;
	std::cout << (p3 >= p2) << std::endl;
	std::cout << (p3 < p2) << std::endl;
	std::cout << (p3 <= p2) << std::endl;
	std::cout << (p3 == p2) << std::endl;
	std::cout << (p3 != p2) << std::endl;

}

int main() {
	pair_comparison();
	exit(EXIT_SUCCESS);
}
