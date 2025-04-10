#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

//Constructors 
Form::Form() : _name("Default"), _signed(false), _gradeToSign(150),
	_gradeToExecute(150)
{
	std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(const std::string &name, const int gradeToSign,
	const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToExecute < 1 || gradeToSign < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if (gradeToExecute > 150 || gradeToSign > 150)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	std::cout << "Form: " << name << " constructed with Grade To Sign " << gradeToSign << " and Grade To Execute " << gradeToExecute << "." << std::endl;
}

Form::~Form()
{
	std::cout << "Form with name of " << getName() << " is destroyed." << std::endl;
}

std::string const &Form::getName() const
{
	return (this->_name);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}