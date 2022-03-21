#include "Widget.h"

#include <iostream>

#include "renderer/primitives/Button.h"
#include "renderer/drawable/Drawable.h"
#include "renderer/primitives/Object.h"
#include "renderer/primitives/Point.h"
#include "engine/components/buttons/BaseButton.h"
#include "engine/managers/ButtonManager.h"

Widget::Widget(ButtonManager& btnMngr): btnManager(btnMngr), origin(Point::ZERO) {
}

Widget::Widget(ButtonManager& btnMngr, Point p): btnManager(btnMngr), origin(p) {
}

void Widget::put(Object& drawable) {
	Point newDrawablePos = origin + drawable.getPosition();
	drawable.move(newDrawablePos.x, newDrawablePos.y);

	drawables.push_back(&drawable);
}

void Widget::put(BaseButton& btn) {
	drawables.push_back(&btn);
	btnManager.registerButton(btn);
}

void Widget::addChild(Widget& widget) {
	children.push_back(&widget);
}

std::vector<Widget*>& Widget::getChildren() {
	return children;
}

std::vector<Drawable*>& Widget::getDrawables() {
	return drawables;
}

void Widget::remove(Object& drawable) {
	for (Drawable* other : drawables) {
		if (&drawable == other) {
			//delete &drawable;
			break;
		}
	}
}

Widget::~Widget() {
	for (Widget* child : children) {
		delete child;
	}

	for (Drawable* drawable : drawables) {
		delete drawable;
	}

	// TODO: For now we will delete all buttons in btn Manager.
	// If we start implementing multi-widget screens then it will be a bad idea.
	btnManager.clear();

	std::cout << "Widget destroyed" << std::endl;
}
