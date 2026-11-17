#include "Bureaucrat.hpp"
#include "utils/utils.hpp"

int main()
{
	Bureaucrat robot("Bob", 40);
	Bureaucrat robot1;
	robot1 = robot;
	return (0);
}