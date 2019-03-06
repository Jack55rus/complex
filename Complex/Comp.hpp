#pragma once
#include "pch.h"
#include "Comp.h"
#include <iostream>

template <typename T>
Comp<T>::Comp()
{
	++count;
	std::cout << "There has just been created an object (default constructor)" << std::endl; // отладочный вывод
}
// copy constructor
template <typename T>
Comp<T>::Comp(Comp const &c) 
{
	std::cout << "Copy constructor has been called: " << c.Re << "  " << c.Im << std::endl;
	++count;
	Re = c.Re;
	Im = c.Im;
}
// move constructor
template <typename T>
Comp<T>::Comp(Comp &&c)
{
	std::cout << "Move constructor has been called: " << c.Re << "  " << c.Im << std::endl;
	++count;
	Re = c.Re;
	Im = c.Im;
}

template <typename T>
Comp<T>::~Comp()
{
	std::cout << "The desctructor has been called" << std::endl; // отладочный вывод
	--count;
}

template <typename T>
Comp<T>::Comp(T real, T imag)
{
	++count;
	Re = real;
	Im = imag;
	
	std::cout << "An object with real and imaginary parts has been created" << std::endl; // отладочный вывод
}

template <typename T>
Comp<T>::Comp(T real)
{
	++count;
	Re = real;
	Im = 0;
	std::cout << "An object with only one part has been created" << std::endl; // отладочный вывод
}
// move assignment operator
template<typename T>
Comp<T>& Comp<T>::operator =(Comp<T>&& c2) 
{
	std::cout << "move assignment operator has been called" << std::endl;
	if (this != &c2)
	{
		Re = c2.Re;
		Im = c2.Im;
	}
	return *this;
}
// copy assignment operator
template<typename T>
Comp<T>& Comp<T>::operator =(const Comp<T>& c2)
{
	std::cout << "copy assignment operator has been called" << std::endl;
	if (this != &c2)
	{
		Re = c2.Re;
		Im = c2.Im;
	}
	return *this;
}

template<typename T>
//сложение
Comp<T>& Comp<T>::operator +=(const Comp<T>& c2) 
{
	Re += c2.Re;
	Im += c2.Im;
	return *this;
}
//вычитание
template<typename T>
Comp<T>& Comp<T>::operator -=(const Comp<T>& c2) {
	Re -= c2.Re;
	Im -= c2.Im;
	return *this;
}
template<typename T>
//умножение
Comp<T>& Comp<T>::operator *=(const Comp<T>& c2) {
	T real = Re * c2.Re - Im * c2.Im;
	T imag = Re * c2.Im + Im * c2.Re;
	Re = real;
	Im = imag;
	return *this;
}
//деление
template<typename T>
Comp<T>& Comp<T>::operator /=(const Comp<T>& c2) {
	Comp<T> nm = Comp<T>(*this) * Comp<T>(c2.Re, -c2.Im);
	T dn = c2.Re * c2.Re + c2.Im * c2.Im;
	Re = nm.Re / dn;
	Im = nm.Im / dn;
	return *this;
}

template <typename T>
Comp<T> Comp<T>::operator +(const Comp<T>& c2) const {
	return Comp<T>(*this) += c2;
}

template <typename T>
Comp<T> Comp<T>::operator -(const Comp<T>& c2) const {
	return Comp<T>(*this) -= c2;
}

template <typename T>
Comp<T> Comp<T>::operator *(const Comp<T>& c2) const {
	return Comp<T>(*this) *= c2;
}

template <typename T>
Comp<T> Comp<T>::operator /(const Comp<T>& c2) const {
	return Comp<T>(*this) /= c2;
}
//ввод
template<typename T>
std::ostream& operator <<(std::ostream& os, const Comp<T>& c) {
	os << c.Re;
	if (c.Im < 0)
		os << c.Im << "i";
	else if (c.Im > 0)
		os << "+" << c.Im << "i";
	return os;
}
//вывод
template<typename T>
std::istream& operator >>(std::istream& is,  Comp<T>& c) {
	is >> c.Re;
	is >> c.Im;
	return is;
}

template <typename T>
T Comp<T>::getReal()
{
	return Re;
}

template <typename T>
T Comp<T>::getImag()
{
	return Im;
}

template <typename T>
bool Comp<T>::operator == (const Comp<T>& c2)
{
	return this->Re == c2.Re && this->Im == c2.Im;
}