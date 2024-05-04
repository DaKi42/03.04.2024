#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class MilitaryBase {
public:
    virtual void Show(int x, int y) const = 0;
    virtual int GetSpeed() const = 0;
    virtual int GetStrength() const = 0;
};

class LightInfantry : public MilitaryBase {
public:
    void Show(int x, int y) const override { cout << "Light infantry at position [" << x << ", " << y << "]" << endl; }
    int GetSpeed() const override {
        return 20;
    }
    int GetStrength() const override {
        return 10;
    }
};

class TransportVehicle : public MilitaryBase {
public:
    void Show(int x, int y) const override { cout << "Transport vehicle at position - [" << x << ", " << y << "]" << endl; }
    int GetSpeed() const override {
        return 70;
    }
    int GetStrength() const override {
        return 0;
    }
};

class HeavyGroundCombatVehicle : public MilitaryBase {
public:
    void Show(int x, int y) const override { cout << "Heavy ground combat vehicle position - [" << x << ", " << y << "]" << endl; }
    int GetSpeed() const override {
        return 15;
    }
    int GetStrength() const override {
        return 150;
    }
};

class LightGroundCombatVehicle : public MilitaryBase {
public:
    void Show(int x, int y) const override { cout << "Light ground combat vehicle position - [" << x << ", " << y << "]" << endl; }
    int GetSpeed() const override {
        return 50;
    }
    int GetStrength() const override {
        return 30;
    }
};

class AviationVehicle : public MilitaryBase {
public:
    void Show(int x, int y) const override { cout << "Aviation vehicle position - [" << x << ", " << y << "]" << endl; }
    int GetSpeed() const override {
        return 300;
    }
    int GetStrength() const override {
        return 100;
    }
};

class MilitaryFactory {
private:
    map<string, MilitaryBase*> units;
public:
    MilitaryBase* GetUnit(const string& type) {
        if (units.find(type) != units.end()) {return units[type];}
        if (type == "LightInfantry") {units[type] = new LightInfantry();} 
        else if (type == "TransportVehicle") {units[type] = new TransportVehicle();} 
        else if (type == "HeavyGroundCombatVehicle") {units[type] = new HeavyGroundCombatVehicle();} 
        else if (type == "LightGroundCombatVehicle") {units[type] = new LightGroundCombatVehicle();} 
        else if (type == "AviationVehicle") {units[type] = new AviationVehicle();}
        return units[type];
    }
};

int main() {
    srand(time(nullptr));
    MilitaryFactory factory;

    for (int i = 0; i < 5; ++i) {
        MilitaryBase* unit = nullptr;
        int x = rand() % 1000;
        int y = rand() % 1000;
        switch (i) {
        case 0:
            unit = factory.GetUnit("LightInfantry");
            break;
        case 1:
            unit = factory.GetUnit("TransportVehicle");
            break;
        case 2:
            unit = factory.GetUnit("HeavyGroundCombatVehicle");
            break;
        case 3:
            unit = factory.GetUnit("LightGroundCombatVehicle");
            break;
        case 4:
            unit = factory.GetUnit("AviationVehicle");
            break;
        }
        unit->Show(x, y);
        cout << "Speed: " << unit->GetSpeed() << "; Strength: " << unit->GetStrength() << endl;
    }
    system("pause");
    return 0;
}