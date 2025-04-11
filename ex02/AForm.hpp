/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <macbook@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:08:24 by macbook           #+#    #+#             */
/*   Updated: 2025/04/11 13:08:45 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	std::string _target;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

  public:
	// Constructors
	AForm();
	AForm(const std::string &name, std::string &target, const int signGrade, const int execGrade);
	AForm(const AForm &copy);
	~AForm();
	AForm &operator=(const AForm &copy);

	// Getters
	std::string const &getName() const;
	std::string const &getTarget(void) const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;

	// Setters
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(const Bureaucrat &executor) const = 0;
	void setTarget(std::string const &target);
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
std::ostream &operator<<(std::ostream &out, const AForm &form);
