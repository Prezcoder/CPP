
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();

		Cat &operator=(const Cat &copy);

		virtual void makeSound() const;
		Brain *getBrain() const;

	private:
		Brain *_brain;

};

#endif