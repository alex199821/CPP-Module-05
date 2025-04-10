/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:45 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 04:08:45 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

  public:
	// Constructors
	Form();
	Form(const std::string &name, const int signGrade, const int execGrade);
	Form(const Form &copy);
	~Form();
	Form &operator=(const Form &copy);

	// Getters
	std::string const &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;

	// Setters
	void beSigned(const Bureaucrat &bureaucrat);

	// Exceptions
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
std::ostream &operator<<(std::ostream &out, const Form &form);
