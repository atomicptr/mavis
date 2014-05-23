#include "vector3.hpp"

vector3& vector3::operator+(vector3& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;

	return *this;
}

vector3& vector3::operator-(vector3& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;

	return *this;
}

vector3& vector3::operator*(int scalar) {
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;

	return *this;
}