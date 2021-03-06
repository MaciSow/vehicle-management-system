#include "Car.h"

Car::Car(const string &plate, Status *status, const string &brand, const string &model, int seatsAmount,
         int doorsAmount, const string &bodyStyle, vector<Repair *> repairs, vector<Road *> roadRegister) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->seatsAmount = seatsAmount;
    this->doorsAmount = doorsAmount;
    this->bodyStyle = bodyStyle;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

Car::~Car() {

}

VehicleType Car::getVehicleType() {
    return CAR;
}

vector<string> Car::getVehicleAllData() {
    vector<string> vehicleData = {brand, model, "", "", bodyStyle, plate};
    vehicleData[2] = to_string(seatsAmount);
    vehicleData[3] = to_string(doorsAmount);
    vehicleData.push_back(status->getStatusName());

    return vehicleData;
}

Car::Car(const string &plate, Status *status, const string &brand, const string &model, int seatsAmount,
         int doorsAmount, const string &bodyStyle) {
    this->plate = plate;
    this->status = status;
    this->brand = brand;
    this->model = model;
    this->seatsAmount = seatsAmount;
    this->doorsAmount = doorsAmount;
    this->bodyStyle = bodyStyle;
    vector<Repair *> repairs;
    vector<Road *> roadRegister;
    this->repairs = repairs;
    this->roadRegister = roadRegister;
}

void Car::updateAllData(vector<string> vehicleData) {
    this->plate = vehicleData[0];
    this->brand = vehicleData[1];
    this->model = vehicleData[2];
    this->seatsAmount = stoi(vehicleData[3]);
    this->doorsAmount = stoi(vehicleData[4]);
    this->bodyStyle = vehicleData[5];
}

vector<string> Car::getSpecificPrintData() {
    vector<string> vehicleData;

    vehicleData.push_back("seats: " + to_string(seatsAmount));
    vehicleData.push_back("doors: " + to_string(doorsAmount));
    vehicleData.push_back("body: " + bodyStyle);

    return vehicleData;
}
