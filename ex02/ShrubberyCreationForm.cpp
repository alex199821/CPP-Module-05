/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:42 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 20:11:44 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery Creation",
	"Default Target", 145, 137)
{
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("Shrubbery Creation Form",
	target, 145, 137)
{
	// setTarget(target);
	std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm with name of " << getName() << " is destroyed." << std::endl;
}

// Copy Constructors
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
	// delegate to base class copy constructor
{
	std::cout << "Copy constructor called for ShrubberyCreationForm: " << copy.getName() << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "Assignment operator called for ShrubberyCreationForm: '" << copy.getName() << "'." << std::endl;

	if (this == &copy)
	{
		return (*this);
	}
	return (*this);
}