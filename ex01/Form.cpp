/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:50 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 04:08:51 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Constructors
Form::Form() : _name("Default"),  _gradeToSign(150), _gradeToExecute(150), _signed(false)
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

Form::Form(const Form &copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute), _signed(copy._signed)
{
	std::cout << "Copy constructor called for Form: " << copy._name << std::endl;
}

Form::~Form()
{
	std::cout << "Form with name of " << getName() << " is destroyed." << std::endl;
}

//Operators

Form &Form::operator=(const Form &copy)
{
	std::cout << "Assignment operator called for Form: '" << copy._name << "'." << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return *this;
}

std::ostream &operator<<(std::ostream& out, Form const &form) {
	out << form.getName()
	    << ", Form signed: " << (form.getSigned() ? "True" : "False")
	    << ", Grade to sign: " << form.getGradeToSign()
	    << ", Grade to execute: " << form.getGradeToExecute();
	return out;
}

// Getters
const std::string &Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToSign);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

//Signing
void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
}

//Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}