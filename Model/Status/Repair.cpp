#include "Repair.h"

Repair::Repair(const string &name, const string &description, Date *fixDate)
        : Status(REPAIR),
          name(name),
          description(description),
          fixDate(fixDate) {}

Repair::~Repair() {

}

vector<string> Repair::getData() {
    vector<string> repairData;
    repairData.push_back(name);
    repairData.push_back(description);
    repairData.push_back(fixDate->getStringDate());
    return repairData;
}

vector<string> Repair::getStatusPrintData(bool shortVersion) {
    vector<string> repairData;

    if (!shortVersion) {
        repairData.push_back("type: " + getStatusTypeName());
    }
    repairData.push_back("name: " + name);
    repairData.push_back("description: " + description);
    repairData.push_back("fixDate: " + fixDate->getStringDate("-"));

    return repairData;
}
