#include "../utils/utils.hpp"

// reset couleur + retour a la ligne
std::ostream& endofline(std::ostream& os) {
	return os << RESET << std::endl;
}