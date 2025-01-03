#include "Shape.h"

bool Shape::is_valid_color(const std::string& c) const{
	return c == "red" || c == "green" || c == "blue";
}

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string color){
	if(!is_valid_color(color)){
		throw std::invalid_argument("El color no es válido");
	}

	this->color = color;
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if(!is_valid_color(c)){
		throw std::invalid_argument("El color no es válido");
	}
	
	color = c;
}

