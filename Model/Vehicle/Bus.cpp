#include "Bus.h"

Bus::Bus(const string &plate1, const string &status1, const string &brand1, const string &model1,
         const string &plate, const string &status, const string &brand, const string &model, int seatsAmount,
         bool isCoach, bool hasWc) : Vehicle(plate1, status1, brand1, model1),
                                     PeopleTransport(plate, status, brand, model, seatsAmount), isCoach(isCoach),
                                     hasWC(hasWc) {}

Bus::~Bus() {

}