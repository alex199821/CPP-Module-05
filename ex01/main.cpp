#include "Bureaucrat.hpp"

// void	leaks(void)
// {
// 	system("leaks office");
// }

int	main(void)
{
	// atexit(leaks);
	Bureaucrat specialBureaucrat("John", 43);
	std::cout << specialBureaucrat << std::endl;
	Bureaucrat bureaucrat;
	std::cout << bureaucrat << std::endl;
	try
	{
		bureaucrat.setGrade(1);
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		bureaucrat.decrementGrade();
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	try
	{
		bureaucrat.setGrade(151);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "Updated grade is: " << bureaucrat.getGrade() << std::endl;
	return (0);
}