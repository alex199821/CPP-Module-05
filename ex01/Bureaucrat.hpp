#pragma once

#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Form;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();
	// Getters
	std::string const &getName() const;
	int getGrade() const;
	// Setters
	void setGrade(int grade);
	void incrementGrade();
	void decrementGrade();
	// Signing
	void signForm(Form &form);
	// Exception classes
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);