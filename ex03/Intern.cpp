/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:18 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 03:47:39 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "Default Intern Constructor Called" << std::endl;
}

Intern::Intern(const Intern &)
{
	std::cout << "Copy constructor called for Intern" << std::endl;
}

Intern &Intern::operator=(const Intern &)
{
	std::cout << "Assignment operator called for Intern" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern is destroyed." << std::endl;
}

const char	*formNames[] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};

AForm	*createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm		*(*createForms[])(const std::string &target) = 
{
	createShrubberyCreationForm,
	createRobotomyRequestForm, 
	createPresidentialPardonForm
};

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (createForms[i](target));
		}
	}

	std::cout << "Intern couldn't find the form \"" << formName << "\" to create." << std::endl;

	return (nullptr);
}