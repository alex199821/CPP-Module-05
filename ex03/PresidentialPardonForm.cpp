/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:42 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 02:59:21 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream> // Add this include to use std::ofstream

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Shrubbery Creation",
	"Default Target", 25, 5)
{
	std::cout << "Default PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form",
	target, 25, 5)
{
	// setTarget(target);
	std::cout << "Custom PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm with name of " << getName() << " is destroyed." << std::endl;
}

// Copy Constructors
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
// delegate to base class copy constructor
{
	std::cout << "Copy constructor called for PresidentialPardonForm: " << copy.getName() << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "Assignment operator called for PresidentialPardonForm: '" << copy.getName() << "'." << std::endl;
	if (this == &copy)
	{
		return (*this);
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecutionRequirements(executor);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
