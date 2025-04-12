/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:42 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 02:59:04 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream> // Add this include to use std::ofstream

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy Request Form",
	"Default Target", 72, 45)
{
	std::cout << "Default RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request Form",
	target, 72, 45)
{
	// setTarget(target);
	std::cout << "Custom Robotomy Request Form Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm with name of " << getName() << " is destroyed." << std::endl;
}

// Copy Constructors
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
// delegate to base class copy constructor
{
	std::cout << "Copy constructor called for RobotomyRequestForm: " << copy.getName() << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "Assignment operator called for RobotomyRequestForm: '" << copy.getName() << "'." << std::endl;
	if (this == &copy)
	{
		return (*this);
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkExecutionRequirements(executor);
	std::cerr << "****DRILLING NOISES****" << std::endl;

	std::srand(std::time(0));
	int randomNumber = std::rand() % 2;

	if (randomNumber)
	{
		std::cerr << getTarget() << "has been robotomized." << std::endl;
	}
	else
	{
		std::cerr << "Robotomy Failed." << std::endl;
	}
}
