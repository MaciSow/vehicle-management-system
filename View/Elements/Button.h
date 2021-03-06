#ifndef VEHICLEMENAGMENTSYSTEM_VIEW_BUTTON_H
#define VEHICLEMENAGMENTSYSTEM_VIEW_BUTTON_H

#include <SFML/Graphics.hpp>
#include "iostream"

using namespace std;
using namespace sf;

class Button {
private:
    RectangleShape button;
    Text text;
    Color baseCol = {0, 0, 0, 205};
    Color hoverCol = {78, 112, 30, 205};
    Color blockCol = {130, 130, 130, 255};
    Color pressedCol = hoverCol;

    bool isActive = false;
    bool isHidden = false;
    bool isBlock = false;
    float width = 250;
    float height = 50;
    int fontSize = 16;

    string id = "";
    enum State {
        normal,
        hover,
        block
    };

    void create(Vector2f position, string title, Font &font);

    void setButtonState(State state);

public:
    Button(Vector2f position, string title, Font &font, float width = 250, float height = 50, string id = "");

    ~Button();

    string getId();

    void setColor(Color base, Color hover);

    void setPosition(Vector2f position);

    void setActive(bool isActive);

    void setBlock(bool isBlock = true);

    bool getActive();

    bool isMouseOver(RenderWindow *&window);

    bool isClick(RenderWindow *&window);

    void drawTo(RenderWindow *&window);

    void setIsHidden(bool isHidden);

    bool getIsHidden() const;
};

#endif  //VEHICLEMENAGMENTSYSTEM_VIEW_BUTTON_H