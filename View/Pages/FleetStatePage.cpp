#include "FleetStatePage.h"

// public
FleetStatePage::FleetStatePage(MainController *controller, RenderWindow *window, const Font &font)
        : Page(controller, window, font) {
    create();
    createBtnBack();
}

FleetStatePage::~FleetStatePage() = default;

void FleetStatePage::draw() {
    fillState();
    drawBtnBack();
}

bool FleetStatePage::isMouseOver() {
    return Page::isMouseOver();
}

PageName FleetStatePage::mouseClick() {
    if (handleBtnBackClick()) {
        clear();
        return PageName::home;
    }
    return PageName::fleetState;
}


// private
void FleetStatePage::create() {}

void FleetStatePage::clear() {}

void FleetStatePage::fillState() {
    float width = (float) (window->getSize().x);
    float posX;
    float posY = 60;
    float offset = 64;
    vector<String> labels = {
            "Vehicles amount", "Car amount", "Bus amount", "Van amount", "Truck amount",
            "Available vehicles", "On the road vehicles", "In repair vehicles", "Drivers amount", "Available drivers"
    };

    vector<int> values = controller->getStateData();

    int labelsLength = labels.size();

    for (int i = 0; i < labelsLength; ++i) {
        Text item(labels[i] + ':', font, 22);
        Text value(to_string(values[i]), font, 22);


        if (i < labelsLength / 2) {
            posX = width / 2 - 100;
        } else {
            posX = width / 2 + 260;
        }

        if (i == labelsLength / 2) {
            posY = 60;
        }

        item.setFillColor(Color::Black);
        item.setPosition({posX - item.getLocalBounds().width, posY += offset});

        value.setFillColor(Color::Black);
        value.setPosition({posX + 8, posY});

        window->draw(item);
        window->draw(value);
    }
}
