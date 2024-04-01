#include<iostream>
#include"Wheel.h"

#pragma warning(disable:4996)
void Wheel::copyFrom(const Wheel& other) {
	setRadius(other._radius);
	setMaterial(other._material);
}

Wheel::Wheel(int radius, Material material) {
	setRadius(_radius);
	setMaterial(_material);
}

Wheel::Wheel(const Wheel& other) {
	copyFrom(other);
}
Wheel& Wheel::operator=(const Wheel& other) {
	if (this != &other) {
		copyFrom(other);
	}
	return *this;
}

void Wheel::setRadius(int radius) {
	_radius = radius;
}

void Wheel::setMaterial(Material material) {
	_material = material;
}

Material Wheel::getMaterial() const{
	return _material;
}

int Wheel::getRadius() const {
	return _radius;
}

