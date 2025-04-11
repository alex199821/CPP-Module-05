/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:07:51 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 22:10:07 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
  public:
	// Constructor
	PresidentialPardonForm();
	PresidentialPardonForm(std::string &target);
	// Copy constructor & assignment operator (optional but good practice)
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
	// Destructor
	virtual ~PresidentialPardonForm();
	// Execute function
	void execute(const Bureaucrat &executor) const override;
};