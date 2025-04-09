#include "Bureaucrat.hpp"

// Constructors

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150)
{
	std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	setGrade(grade);
	std::cout << "Bureaucrat " << this->_name << " constructed with grade " << grade << "." << std::endl;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

// Bureaucrat::~Bureaucrat()
// {
// 	std::cout << "Bureaucrat with name of " << name << " is destroyed." << std::endl;
// }

// Animal &Animal::operator=(const Animal &copy)
// {
// 	if (this != &copy)
// 	{
// 		type = copy.type;
// 	}
// 	std::cout << "Assignment was made to Animal with type of " << type << "." << std::endl;
// 	return (*this);
// }

// Animal::Animal(const Animal &copy) : type(copy.type)
// {
// 	*this = copy;
// 	std::cout << "Animal with type of " << type << " was copied." << std::endl;
// };
// // Member Functions
// void Animal::makeSound() const
// {
// 	std::cout << "***MAKING ANIMAL SOUNDS***" << std::endl;
// }

// std::string Animal::getType(void) const
// {
// 	return (type);
// }


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}