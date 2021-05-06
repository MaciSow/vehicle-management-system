#include "Page.h"

// protected
void Page::create() {
}

void Page::clear() {
}

void Page::createBtnBack() {
    float btnWidth = 150;
    float btnPosX = width - btnWidth - 32;
    float btnPosY = height - 50 - 32;

    btnBack = new Button({btnPosX, btnPosY}, "Back", font, btnWidth);
    btnBack->setColor({0, 0, 0, 205}, {196, 55, 55, 205});
}

void Page::drawBackBtn() {
    btnBack->drawTo(window);
}

bool Page::handleBtnBackClick() {
    return btnBack->isClick(window);
}

bool Page::handleBtnBackHover() {
    return btnBack->isMouseOver(window);
}

// public
Page::Page(MainController *controller, RenderWindow *window, const Font &font) {
    this->controller = controller;
    this->window = window;
    this->font = font;
    width = (float) (window->getSize().x);
    height = (float) (window->getSize().y);
}

Page::~Page() = default;

bool Page::isMouseOver() {
    return handleBtnBackHover();
}

PageName Page::mouseClick() {
    return PageName::home;
}

void Page::draw() {
}