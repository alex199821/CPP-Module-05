/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:35 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 19:54:02 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

// Constructors
AForm::AForm() : _name("Default"), _target("Default"), _gradeToSign(150), _gradeToExecute(150),
	_signed(false)
{
	std::cout << "Default AForm Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, const std::string &target, const int gradeToSign,
	const int gradeToExecute) : _name(name), _target(target), _gradeToSign(gradeToSign),
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
	std::cout << "AForm: " << name << " constructed with Grade To Sign " << gradeToSign << " and Grade To Execute " << gradeToExecute << "." << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _target(copy._target),
	_gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute),
	_signed(copy._signed)
{
	std::cout << "Copy constructor called for AForm: " << copy._name << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm with name of " << getName() << " is destroyed." << std::endl;
}

// Operators

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "Assignment operator called for AForm: '" << copy._name << "'." << std::endl;
	if (this != &copy)
	{
		this->_signed = copy._signed;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream& out, AForm const &form) {
	out << form.getName()
	    << ", AForm signed: " << (form.getSigned() ? "True" : "False")
		<< ", Target: " << form.getTarget()
		<< ", Grade to sign: " << form.getGradeToSign()
	    << ", Grade to execute: " << form.getGradeToExecute();
	return out;
}

// Getters
const std::string &AForm::getName(void) const
{
	return (this->_name);
}

const std::string &AForm::getTarget(void) const
{
	return (this->_target);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToSign);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

// Signing
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw GradeTooLowException();
	}
	_signed = true;
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}