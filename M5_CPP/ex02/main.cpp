#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils/utils.hpp"

void	title(std::string str)
{
	std::cout << BOLD_YELLOW << str << endofline;
}
int main()
{
	title("--- Creation d'un Form ---");
	try
	{
		Form form("A38", 50, 25);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	title("--- Form avec grade 0 ---");
	try
	{
		Form form("Bad", 0, 25);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	title("--- Form avec grade 151 ---");
	try
	{
		Form form("Bad", 151, 40);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	title("--- Signature reussie ---");
	try
	{
		Bureaucrat bob("Bob", 10);
		Form form("A38", 50, 25);
		bob.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	title("--- Signature ratee ---");
	try
	{
		Bureaucrat jim("Jim", 100);
		Form form("A38", 50, 25);
		jim.signForm(form);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	title("--- beSigned avec un grade trop bas ---");
	try
	{
		Bureaucrat jim("Jim", 100);
		Form form("B12", 50, 25);
		form.beSigned(jim);
		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << RED << e.what() << endofline;
	}

	return (0);
}
