#include "Rectangle.h"

bool Rectangle::check(Point2D* vertices){
	double d1 = Point2D::distance(vertices[0], vertices[1]);
	double d2 = Point2D::distance(vertices[2], vertices[3]);
	double d3 = Point2D::distance(vertices[1], vertices[2]);
	double d4 = Point2D::distance(vertices[3], vertices[0]);

	return (d1 == d2 && d3 == d4);
}

Rectangle::Rectangle() : Shape() {
	vs = new Point2D[N_VERTICES];
	vs[0] = Point2D(-1, 0.5);
	vs[1] = Point2D(1, 0.5);
	vs[2] = Point2D(1, -0.5);
	vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color){
	if(!check(vertices)){
		throw std::invalid_argument("Los vértices no forman un rectángulo");
	}

	vs = new Point2D[N_VERTICES];
	for(int i=0; i<N_VERTICES; ++i){
		vs[i] = vertices[i];
	}
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color){
	vs = new Point2D[N_VERTICES];
	for(int i=0; i<N_VERTICES; ++i){
		vs[i] = r.vs[i];
	}
}

Rectangle::~Rectangle(){
	delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind >= N_VERTICES){
		throw std::out_of_range("El índice no es válido");
	}

	return vs[ind];
}

Point2D Rectangle::operator[](int ind) const{
	return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices){
	if(!check(vertices)){
		throw std::invalid_argument("Los vértices no forman un rectángulo");
	}

	for(int i=0; i<N_VERTICES; ++i){
		vs[i] = vertices[i];
	}
}

double Rectangle::area() const{
	double ancho = Point2D::distance(vs[0], vs[1]);
	double alto = Point2D::distance(vs[1], vs[2]);

	return ancho * alto;
}

double Rectangle::perimeter() const{
	double ancho = Point2D::distance(vs[0], vs[1]);
	double alto = Point2D::distance(vs[1], vs[2]);

	return 2 * (ancho + alto);
}

void Rectangle::translate(double incX, double incY){
	for(int i=0; i<N_VERTICES; ++i){
		vs[i].x += incX;
		vs[i].y += incY;
	}
}

void Rectangle::print(std::ostream &out) const{
	out << *this;
}

Rectangle& Rectangle::operator=(const Rectangle &r){
	if(this == &r){
		return *this;
	}

	Shape::color = r.color;
	for(int i=0; i<N_VERTICES; ++i){
		vs[i] = r.vs[i];
	}

	return *this;
}


std::ostream& operator<<(std::ostream &out, const Rectangle &r){
	out << "Rectángulo: ";

	for(int i=0; i < Rectangle::N_VERTICES; ++i){
		out << r.vs[i];
		if(i < Rectangle::N_VERTICES-1){
			out << ", ";
		}
	}

	out << ", Color = " << r.color;

	return out;
}


