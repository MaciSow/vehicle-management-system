#include "GraphicView.h"

GraphicView::GraphicView(MainController *&ctr) {
    this->controller = ctr;

    createWindow();
    pageName = PageName::home;
    homePage = new HomePage(controller, window, font);
    fleetStatePage = new FleetStatePage(controller, window, font);
    showVehiclesPage = new ShowVehiclesPage(controller, window, font);
    vehicleDataPage = new VehicleDataPage(controller, window, font);
    changeStatusPage = new ChangeStatusPage(controller, window, font);
    availablePage = new AvailablePage(controller, window, font);
    roadPage = new RoadPage(controller, window, font);
    brokePage = new BrokePage(controller, window, font);
    repairPage = new RepairPage(controller, window, font);
    showRegisterPage = new ShowRegisterPage(controller, window, font);
    showRepairsPage = new ShowRepairsPage(controller, window, font);
    addEditVehiclePage = new AddEditVehiclePage(controller, window, font);
    showDriversPage = new ShowDriversPage(controller, window, font);
    driverDataPage = new DriverDataPage(controller, window, font);
    addEditDriverPage = new AddEditDriverPage(controller, window, font);
    exitPage = new ExitPage(controller, window, font);
}

GraphicView::~GraphicView() = default;

void GraphicView::start() {
    while (window->isOpen()) {
        Event event;

        while (window->pollEvent(event)) {
            switch (event.type) {
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Escape) {
                        window->close();
                    }
                    break;

                case Event::TextEntered:
                    textEnteredHandle(event);
                    break;

                case Event::MouseMoved:
                    mouseMovedHandle();
                    break;

                case Event::MouseButtonPressed:
                    mouseButtonPressedHandle(event);
                    break;

                case Event::MouseWheelMoved:
                    mouseWheelMovedHandle(event);
                    break;

                case Event::Closed:
                    window->close();
                    break;

                default:
                    break;
            }
        }

        window->clear();
        createBackground();
        drawPage();
        window->setMouseCursor(cursor);
        window->display();

        if (pageName == PageName::close) {
            cleanPage();
            window->close();
        }
    }
}

void GraphicView::textEnteredHandle(Event &event) {
    switch (pageName) {
        case PageName::addEditVehicle:
            addEditVehiclePage->textEntered(event);
            break;

        case PageName::road:
            roadPage->textEntered(event);
            break;

        case PageName::broke:
            brokePage->textEntered(event);
            break;

        case PageName::repair:
            repairPage->textEntered(event);
            break;

        case PageName::addEditDriver:
            addEditDriverPage->textEntered(event);
            break;
        default:
            break;
    }
}

void GraphicView::mouseMovedHandle() {
    bool isCursorChange = false;

    switch (pageName) {
        case PageName::home:
            if (homePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::fleetState:
            if (fleetStatePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showVehicles:
            if (showVehiclesPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::vehicleData:
            if (vehicleDataPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::changeStatus:
            if (changeStatusPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::available:
            if (availablePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::road:
            if (roadPage->isMouseOver()) {
                isCursorChange = true;
            }

        case PageName::broke:
            if (brokePage->isMouseOver()) {
                isCursorChange = true;
            }

        case PageName::repair:
            if (repairPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showRegister:
            if (showRegisterPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showRepairs:
            if (showRepairsPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::addEditVehicle:
            if (addEditVehiclePage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::showDrivers:
            if (showDriversPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::driverData:
            if (driverDataPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::addEditDriver:
            if (addEditDriverPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        case PageName::exit:
            if (exitPage->isMouseOver()) {
                isCursorChange = true;
            }
            break;

        default:
            break;
    }

    if (isCursorChange) {
        cursor.loadFromSystem(Cursor::Hand);
    } else {
        cursor.loadFromSystem(Cursor::Arrow);
    }
}

void GraphicView::mouseButtonPressedHandle(Event &event) {
    if (event.key.code == (int) Mouse::Left) {
        switch (pageName) {

            case PageName::home:
                pageName = homePage->mouseClick();
                break;

            case PageName::fleetState:
                pageName = fleetStatePage->mouseClick();
                break;

            case PageName::showVehicles:
                pageName = showVehiclesPage->mouseClick();
                break;

            case PageName::vehicleData:
                pageName = vehicleDataPage->mouseClick();
                break;

            case PageName::changeStatus:
                pageName = changeStatusPage->mouseClick();
                break;

            case PageName::available:
                pageName = availablePage->mouseClick();
                break;

            case PageName::road:
                pageName = roadPage->mouseClick();
                break;

            case PageName::broke:
                pageName = brokePage->mouseClick();
                break;

            case PageName::repair:
                pageName = repairPage->mouseClick();
                break;

            case PageName::showRegister:
                pageName = showRegisterPage->mouseClick();
                break;

            case PageName::showRepairs:
                pageName = showRepairsPage->mouseClick();
                break;

            case PageName::addEditVehicle:
                pageName = addEditVehiclePage->mouseClick();
                break;

            case PageName::showDrivers:
                pageName = showDriversPage->mouseClick();
                break;

            case PageName::driverData:
                pageName = driverDataPage->mouseClick();
                break;

            case PageName::addEditDriver:
                pageName = addEditDriverPage->mouseClick();
                break;

            case PageName::exit:
                pageName = exitPage->mouseClick();
                break;

            default:
                break;

        };
    }
}

void GraphicView::mouseButtonReleasedHandle() {

}

void GraphicView::mouseWheelMovedHandle(Event &event) {
    switch (pageName) {
        case PageName::showVehicles:
            showVehiclesPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::showRegister:
            showRegisterPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::showRepairs:
            showRepairsPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::showDrivers:
            showDriversPage->scroll(event.mouseWheel.delta);
            break;

        case PageName::road:
            roadPage->scroll(event.mouseWheel.delta);
            break;

        default:
            break;
    };
}

void GraphicView::drawPage() {
    int frameHeight = 380;
    int framePosY = 90;
    string vehicleType = "";

    switch (pageName) {
        case PageName::home:
            createTitle("Vehicle Management System");
            homePage->draw();
            break;

        case PageName::fleetState:
            createTitle("Fleet state");
            createFrame(width - 200, frameHeight, framePosY);
            fleetStatePage->draw();
            break;

        case PageName::showVehicles:
            createTitle("Show vehicles");
            createFrame(width - 200, frameHeight, framePosY);
            showVehiclesPage->draw();
            break;

        case PageName::vehicleData:
            vehicleType = controller->getSelectedVehicle()->getVehicleTypeName();
            createTitle(vehicleType + " data");
            createFrame(width - 200, frameHeight, framePosY);
            vehicleDataPage->draw();
            break;

        case PageName::changeStatus:
            createTitle("Change status");
            createFrame(width - 300, 250, framePosY + 60);
            changeStatusPage->draw();
            break;

        case PageName::available:
            createTitle("Available");
            createFrame(width - 300, 250, framePosY + 60);
            availablePage->draw();
            break;

        case PageName::road:
            createTitle("On the road");
            createFrame(width - 300, frameHeight, framePosY);
            roadPage->draw();
            break;

        case PageName::broke:
            createTitle("Broke down");
            createFrame(width - 300, 250, framePosY + 60);
            brokePage->draw();
            break;

        case PageName::repair:
            createTitle("In repair");
            createFrame(width - 300, 250, framePosY + 60);
            repairPage->draw();
            break;

        case PageName::showRegister:
            createTitle("Show register");
            createFrame(width - 200, frameHeight, framePosY);
            showRegisterPage->draw();
            break;

        case PageName::showRepairs:
            createTitle("Show repairs");
            createFrame(width - 200, frameHeight, framePosY);
            showRepairsPage->draw();
            break;

        case PageName::addEditVehicle:
            if (!controller->getSelectedVehicle()) {
                createTitle("Add Vehicle");
            } else {
                vehicleType = controller->getSelectedVehicle()->getVehicleTypeName();
                createTitle("Edit " + vehicleType);
            }
            createFrame(width - 200, frameHeight, framePosY);
            addEditVehiclePage->draw();
            break;

        case PageName::showDrivers:
            createTitle("Show drivers");
            createFrame(width - 200, frameHeight, framePosY);
            showDriversPage->draw();
            break;

        case PageName::driverData:
            createTitle("Driver data");
            createFrame(width - 300, 250, framePosY + 60);
            driverDataPage->draw();
            break;

        case PageName::addEditDriver:
            if (!controller->getSelectedDriver()) {
                createTitle("Add Vehicle");
            } else {
                createTitle("Edit Vehicle");
            }
            createFrame(width - 300, 250, framePosY + 60);
            addEditDriverPage->draw();
            break;

        case PageName::exit:
            createTitle("Close");
            createFrame(width - 300, 250, framePosY + 60);
            exitPage->draw();
            break;

        default:
            break;
    };
}

void GraphicView::createWindow() {
    loadFont();

    window = new RenderWindow(VideoMode(width, height), "Vehicle Menagment System", Style::Titlebar | Style::Close);

    window->display();
    View view(FloatRect(0, 0, float(width), float(height)));
    window->setView(view);
}

void GraphicView::createTitle(string title) {
    Text text(title, font, 36);
    text.setPosition(50, 16);
    text.setFillColor({0, 0, 0, 200});

    RectangleShape line({(float) width - 100, 2});
    line.setFillColor({0, 0, 0, 200});
    line.move(50, 64);

    window->draw(text);
    window->draw(line);
}

void GraphicView::createFrame(int width, int height, int offsetY) {
    RectangleShape frame;

    frame.setSize({(float) width, (float) height});
    frame.setPosition((float) (this->width - width) / 2, (float) offsetY);
    frame.setFillColor({255, 255, 255, 160});

    window->draw(frame);
}

void GraphicView::createBackground() {
    Sprite background;
    Texture texture;

    if (!texture.loadFromFile(resourcePath + "bgr.jpg")) {
        cout << "Fail load bgr";
    }

    background.setTexture(texture);
//    background.setScale(0.5, 0.5);

    window->draw(background);
}

void GraphicView::cleanPage() {
    delete homePage;
    delete exitPage;
    controller->clean();
}

void GraphicView::loadFont() {
    if (!font.loadFromFile(resourcePath + "font.ttf")) {
        cout << "Fail load font";
    }
}
