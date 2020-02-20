#include "pch.h"
#include "Window.h"


Window::Window(const vec2& winSize,const char& pixel)
{
	this->windowSize.x = winSize.x + 1;
	this->windowSize.y = winSize.y;

	this->length = windowSize.x * windowSize.y + windowSize.y;
	this->winMatrix = new char[length + 1];
	winMatrix[length] = '\0';

	for (size_t i = 0; i < length; i++)
	{
			winMatrix[i] = pixel;
	}

	for (size_t i = windowSize.x; i < length; i+=windowSize.x+1)
	{
		winMatrix[i] = '\n';
	}

	this->clearMatrix = new char[length + 1];
	clearMatrix[length] = '\0';

	for (size_t i = 0; i < length; i++)
	{
		clearMatrix[i] = pixel;
	}

	for (size_t i = windowSize.x; i < length; i += windowSize.x + 1)
	{
		clearMatrix[i] = '\n';
	}

}

void Window::setPixel(const vec2& pos, const char& pixel) {

	this->winMatrix[pos.y * windowSize.x + pos.x + pos.y] = pixel;
}

char Window::getPixel(const vec2& pos) {
	return this->winMatrix[pos.y * windowSize.x + pos.x + pos.y];
}

char* Window::getData() {
	return this->winMatrix;
}

void Window::setWindowSize(const vec2& sizeWindow) {
	windowSize.x = sizeWindow.x;
	windowSize.y = sizeWindow.y;

}

void Window::draw(Shape shape,const vec2& position,const char& clear_sym) {

	for (size_t i = 0; i < shape.getSize().y; i++)
	{

		for (size_t j = 0; j < shape.getSize().x; j++)
		{
			if(j + position.x < windowSize.x && i + position.y < windowSize.y && (shape.getData()[i * shape.getSize().x + j] != clear_sym))
			this->setPixel(vec2(j+position.x,i+position.y),shape.getData()[i * shape.getSize().x + j]);
		}
	}



}

void Window::clear() {

	for (size_t i = 0; i < length; i++)
	{
		this->winMatrix[i] = clearMatrix[i];
	}

}

Window::~Window()
{
}
