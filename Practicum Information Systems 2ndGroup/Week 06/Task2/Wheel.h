#pragma once


enum class Material {
	Steel,
	Aluminium,
	Carbon,
	Magnesium
};


class Wheel {

	int _radius;
	Material _material;

	void copyFrom(const Wheel& other);

public:

	Wheel() = default;
	Wheel(int radius, Material material);
	Wheel(const Wheel& other);
	Wheel&operator=(const Wheel& other);

	void setRadius(int radius);
	void setMaterial(Material material);

	Material getMaterial() const;
	int getRadius() const;
};