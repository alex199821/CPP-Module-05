/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:51 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 22:07:05 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
  public:
	// Constructor
	RobotomyRequestForm();
	RobotomyRequestForm(std::string &target);
	// Copy constructor & assignment operator (optional but good practice)
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	// Destructor
	virtual ~RobotomyRequestForm();
	// Execute function
	void execute(const Bureaucrat &executor) const override;
};