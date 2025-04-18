/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auplisas <auplisas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:09:10 by macbook           #+#    #+#             */
/*   Updated: 2025/04/12 04:09:18 by auplisas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

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
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &copy);
	std::string const &getName() const;
	int getGrade() const;

	void setGrade(int grade);
	void incrementGrade();
	void decrementGrade();
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