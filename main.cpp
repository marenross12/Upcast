#include <iostream>
#include <cmath>
#include <memory> //low level memory

// Abstract base class
class Circle {
protected:
    double m_radius;
    double m_area;

public:
    virtual ~Circle() = default;

    Circle(double radius) {
        if (radius > 0) {
            m_radius = radius;
        }
        else {
            m_radius = 1;
        }
        m_area = M_PI * pow(m_radius, 2);
    }
    virtual void calcVolume()=0; //pure virtual func.
    virtual double getVolume()=0;
};

class Cylinder: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cylinder(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = m_area * m_height;
    }
    double getVolume() override {
        return m_volume;
    }
};

class Sphere: public Circle {
private:
    double m_volume;
public:
    Sphere(double radius):Circle(radius) {
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = (4.0/3.0) * M_PI * pow(m_radius, 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

class Cone: public Circle {
private:
    double m_volume;
    double m_height;
public:
    Cone(double radius, double height):Circle(radius) {
        if (height > 0) {
            m_height = height;
        }
        else {
            m_height = 1;
        }
        m_volume = 0;
    }
    void calcVolume() override {
        m_volume = M_PI * pow(m_radius, 2) * (m_height / 3);
    }
    double getVolume() override {
        return m_volume;
    }
};

int main() {
    // sandbox for playing with objects
    int choice;
    std::unique_ptr<Circle> object; //created smart pointer currently set to a safe memory location -nullptr
    //deleted when object it points to goes out of scope
    std::cout<< "Select an object:\n1. Cylinder\n2. Cone\n3. Sphere\nSelect:";
    std::cin >> choice;
    if (choice == 1) {
        double cylRadius, cylHeight;
        std::cout << "Enter Cylinder Radius:";
        std::cin >> cylRadius;
        std::cout << "Enter Cylinder Height:";
        std::cin >> cylHeight;
         object = std::make_unique<Cylinder>(cylRadius, cylHeight);
  //instantiated a cylinder object in the heap, passed radius and height
  // make_unique is the same as new operator
    }
    else if (choice == 2) {
        double coneRadius, coneHeight;
        std::cout << "Enter Cone Radius:";
        std::cin >> coneRadius;
        std::cout << "Enter Cone Height:";
        std::cin >> coneHeight;
        object = std::make_unique<Cone>(coneRadius, coneHeight);
    }
    else if (choice == 3) {
        double sphereRadius ;
        std::cout << "Enter Sphere Radius:";
        std::cin >> sphereRadius;
        object = std::make_unique<Sphere>(sphereRadius);
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }



//unified interface: we can interact w the object w/o knowing what shape it took

  object->calcVolume();
  std::cout << object->getVolume() << std::endl;
 //memory safe bc we used a smart pointer

    return 0;
}
