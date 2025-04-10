#include "Bureaucrat.hpp"
#include "Form.hpp"

// void	leaks(void)
// {
// 	system("leaks office");
// }

int	main(void)
{
	// atexit(leaks);
	Bureaucrat averageBureaucrat("Bureaucrat John", 43);
	std::cout << averageBureaucrat << std::endl;
	std::cout << std::endl;
	Form standardForm("Standard Form", 75, 75);
	std::cout << standardForm << std::endl;
	std::cout << std::endl;
	Form preseidentialForm("Presidential Form", 1, 1);
	std::cout << preseidentialForm << std::endl;
	std::cout << std::endl;
	try
	{
		averageBureaucrat.signForm(preseidentialForm);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		averageBureaucrat.signForm(standardForm);
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}