# include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	std::cout << "New zombie <" << name << "> has been created!" << std::endl;
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": NOOOO MOREEEEE braiiiiiiinnnzzzZ...\n";
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
