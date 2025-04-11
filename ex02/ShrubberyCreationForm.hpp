/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:51 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 04:34:32 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
  public:
	// Constructor
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	// Copy constructor & assignment operator (optional but good practice)
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	// Destructor
	virtual ~ShrubberyCreationForm();
	// Override execute function from AForm
	void execute(const Bureaucrat &executor) const override;
};