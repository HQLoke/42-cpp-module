# include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "New zombie has been created!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": NOOOO MOREEEEE braiiiiiiinnnzzzZ...\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
