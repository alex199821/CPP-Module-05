#pragma once

#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;
    void setGrade(int grade);

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat() = default;

	std::string const &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
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
