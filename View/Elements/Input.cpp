#include "Input.h"

Input::Input(Vector2f position, Font &font, string label, float width, float height, string id) {
    this->width = width;
    this->height = height;
    this->limit = (int) floor((width - 20) / 10);
    create(position, font, label);
    this->id = id;
}

Input::~Input() {
}


void Input::setValue(string value) {
    string newT = "";

    for (int i = 0; i < (int) value.length(); i++) {
        newT += value[i];
    }

    text << newT;
    input.setString(newT);
}


void Input::setWidth(float width) {
    this->width = width;
    limit = (int) floor((width - 20) / 10);
    frame.setSize({width, height});
}

string Input::getId() {
    return id;
}

bool Input::isMouseOver(RenderWindow *&window) {
    if (!isEditable) {
        return false;
    }

    int mouseX = Mouse::getPosition(*window).x;
    int mouseY = Mouse::getPosition(*window).y;

    int btnPosX = (int) frame.getPosition().x;
    int btnPosY = (int) frame.getPosition().y;

    if (mouseX > btnPosX && mouseX < btnPosX + width &&
        mouseY > btnPosY && mouseY < btnPosY + height) {
        if (!isSelected) {
            setInputState(hover);
        }

        return true;
    }

    if (!isSelected) {
        setInputState(inactive);
    }

    return false;
}

void Input::checkSelection(RenderWindow *&window) {
    if (isMouseOver(window)) {
        if (!isSelected) {
            setSelected(true);
        }

    } else {
        setSelected(false);
    }
}

void Input::setSelected(bool isSelected) {
    this->isSelected = isSelected;

    if (isSelected) {
        setInputState(active);
    } else {
        string t = text.str();
        string newT = "";

        for (int i = 0; i < (int) t.length(); i++) {
            newT += t[i];
        }

        input.setString(newT);
        setInputState(inactive);
    }
}

void Input::drawTo(RenderWindow *&window) {
    window->draw(frame);
    window->draw(input);
    window->draw(label);
}

void Input::typeOn(Event event) {
    if (isSelected) {
        int charTyped = event.text.unicode;

        if (charTyped < 128) {
            if ((int) text.str().length() <= limit) {
                inputLogic(charTyped);
            } else if ((int) text.str().length() > limit && charTyped == DELETE_KEY) {
                deleteLastChar();
            }

            validate();

            if (charTyped == ENTER_KEY) {
                setSelected(false);
            }
        }
    }
}

void Input::clear() {
    text.str("");
    input.setString("");
    isValid = true;
    pattern = "^[A-Za-z\\d]{1}[A-Za-z\\d\\ ]*$";
}

string Input::getText() {
    return text.str();
}

// private methods

void Input::create(Vector2f position, Font &font, string label) {
    float posX = position.x;
    float posY = position.y;

    input.setFont(font);
    input.setCharacterSize(fontSize);
    frame.setSize({width, height});
    frame.setOutlineThickness(1);
    frame.move(posX, posY);

    this->label.setString(label);
    this->label.setFont(font);
    this->label.setCharacterSize(18);
    this->label.setPosition({posX, posY - 22});
    this->label.setFillColor(Color::Black);

    setInputState(inactive);

    float centerY = posY + (height > 40 ? height / 4 : height / 2) - (fontSize / 2) - 3;

    input.setPosition({posX + 10, centerY});
}

void Input::setInputState(State state) {

    switch (state) {
        case inactive:
            frame.setFillColor({255, 255, 255, 150});
            frame.setOutlineColor({0, 0, 0, 100});
            input.setFillColor(Color::Black);
            break;
        case hover:
            frame.setFillColor({255, 255, 255, 200});
            break;
        case active:
            addSlash();
            frame.setFillColor({255, 255, 255, 250});
            frame.setOutlineColor({0, 0, 0, 250});
            break;
        default:
            break;
    }

    if (!isValid) {
        frame.setOutlineColor({175, 28, 28, 255});
    } else {
        frame.setOutlineColor({0, 0, 0, 250});
    }
}

void Input::inputLogic(int charTyped) {
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
        text << static_cast<char>(charTyped);

    } else if (charTyped == DELETE_KEY) {
        if (text.str().length() > 0) {
            deleteLastChar();
        }
    }

    input.setString(text.str() + "_");
}

void Input::deleteLastChar() {
    string t = text.str();
    string newT = "";

    for (int i = 0; i < (int) t.length() - 1; i++) {
        newT += t[i];
    }

    text.str("");
    text << newT;

    input.setString(text.str());
}

void Input::addSlash() {
    string t = input.getString();
    string newT = "";

    for (int i = 0; i < (int) t.length(); i++) {
        newT += t[i];
    }

    text.str("");
    text << t;
    input.setString(text.str() + "_");
}

void Input::validate() {
    string value = getText();

    regex reg(pattern);
    smatch matches;
    isValid = regex_search(value, matches, reg);
    setInputState(valid);
}

void Input::setLabel(string label) {
    this->label.setString(label);
}

bool Input::getIsEditable() const {
    return isEditable;
}

void Input::setIsEditable(bool isEditable) {
    Input::isEditable = isEditable;
}

void Input::setPattern(const string &pattern) {
    Input::pattern = pattern;
}

bool Input::getValid() const {
    return isValid;
}
