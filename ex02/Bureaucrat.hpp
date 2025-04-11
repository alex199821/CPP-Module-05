/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:09 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 19:56:18 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

class AForm;

class Bureaucrat
{
  private:
	const std::string _name;
	int _grade;

  public:
	// Constructors
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();
	// Getters
	std::string const &getName() const;
	int getGrade() const;
	// Setters
	void setGrade(int grade);
	void incrementGrade();
	void decrementGrade();
	// Signing
	void signAForm(AForm &form);
	// Exception classes
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

// ostream Overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);