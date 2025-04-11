/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:42 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 22:49:22 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream> // Add this include to use std::ofstream

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
	std::cout << "Custom ShrubberyCreationForm Constructor Called" << std::endl;
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

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkExecutionRequirements(executor);
	std::string target = getTarget() + "_shrubbery";
	std::ofstream file(target);

	if (file.is_open())
	{
		file << "   *   \n";
        file << "  ***  \n";
        file << " ***** \n";
        file << "*******\n";
        file << "   |   \n";
        file << "   |   \n";
		file.close();
	}
	else
	{
		std::cerr << "Failed to create the file." << std::endl;
	}
}
