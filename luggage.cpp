//Dening Zhang
//Class (CECS 282-01)
//Project Name (Prog 6 – Inheritance )
//I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <vector>
#include <cmath>
#include<iomanip>
using namespace std;
class luggage{
private:
    static int sn;
    static double  totalLuggageVolume;
    static int count;

protected:
    string type;
    double luggageVol = 0;
public:
    luggage(){
        sn ++ ;
        type = " ";
        count ++;
        luggageVol ;
        totalLuggageVolume += luggageVol;
    }
    virtual double getVolume() = 0;

    virtual ~luggage(){
        count --;
        luggageVol -= luggageVol;
    }

    static int totalCount(){
        return count;
    }
    virtual string getType()  {
        return type;
    }

    static double totalVolume(){
        return totalLuggageVolume;
    }
    virtual int setSn(){
        return sn ;
    }

    friend ostream &operator<<(ostream &out, luggage* &luggage1){
        cout<<fixed<<setprecision(1);
        out << setw(10)<<left<< luggage1 ->type  << setw(5)<<right<<luggage1 ->getVolume()  <<setw(10)<<right<<" (SN: "<< luggage1->setSn() <<")";
        return out;
    }
};
int luggage::sn = 0;
double  luggage::totalLuggageVolume = 0;
int luggage::count = 0;

class box:public luggage{
private:
    int sn;
    double width, height, length;
    static int count;
    static double totalBoxVolume ;
    double boxVolume = 0;

public:
    box(double w, double h, double d){
        sn = luggage::setSn();
        width = w;
        height = h;
        length = d;
        type = "Box";
        count ++;
        boxVolume = getVolume();
        totalBoxVolume += boxVolume;
    }
    int setSn(){
        return sn;
    }
    double getVolume(){
        return  width * height * length;
    }
    ~box(){
        count --;
        totalBoxVolume -=boxVolume;
    }
    static int totalCount(){
        return count;
    }
    string getType(){
        return type;
    }

    static double totalVolume(){
        return totalBoxVolume;
    }

};
double box::totalBoxVolume = 0;
int box::count = 0;

class sphere:public luggage{
private:
    int sn;
    double radius;
    static int count ;
    double sphereVol = 0;
    static double totalSphereVol;

public:
    sphere(double r){
        sn = luggage::setSn();
        radius = r;
        type = "Sphere";
        count ++;
        sphereVol = getVolume();
        totalSphereVol += sphereVol;
    }
    int setSn(){
        return sn;
    }
    double getVolume(){
        return double(4 * M_PI * radius * radius * radius) /3;
    }
    ~sphere(){
        count --;
        totalSphereVol -=sphereVol;
    }
    static int totalCount(){
        return count;
    }
    string getType(){
        return type;
    }
    static double totalVolume(){
        return totalSphereVol;
    }
};
int sphere::count = 0;
double sphere::totalSphereVol = 0;

class cube:public luggage{
private:
    int sn;
    double width;
    static int count ;
    static double totalCubeVolume;
    double cubeVol = 0;
public:
    cube(double w){
        sn = luggage::setSn();
        width = w;
        type = "Cube";
        count ++;
        cubeVol = getVolume();
        totalCubeVolume += cubeVol;
    }
    int setSn(){
        return sn;
    }
    double getVolume(){
        return width * width * width;
    }
    ~cube(){
        count--;
        totalCubeVolume -=cubeVol;
    }
    static int totalCount(){
        return count;
    }
    string getType(){
        return type;
    }
    static double totalVolume(){
        return totalCubeVolume;
    }
};
int cube::count = 0;
double cube::totalCubeVolume = 0;

class pyramid:public luggage{
private:
    int sn;
    double base, height;
    static int count ;
    static double totalPyramidVolume;
    double pyramidVol = 0;
public:
    pyramid(double b, double h){
        sn = luggage::setSn();
        base = b;
        height = h;
        type = "Pyramid";
        count++;
        pyramidVol = getVolume();
        totalPyramidVolume += pyramidVol;
    }
    int setSn(){
        return sn;
    }
    double getVolume(){
        return (base * base * height) / 3.0;
    }
    ~pyramid(){
        count --;
        totalPyramidVolume -=pyramidVol;
    }
    static int totalCount(){
        return count ;
    }
    string getType(){
        return type;
    }
    static double totalVolume(){
        return totalPyramidVolume;
    }

};
int pyramid::count = 0;
double pyramid::totalPyramidVolume = 0;

class cylinder:public luggage{
private:
    int sn;
    double radius, length;
    static int count ;
    static double totalCylinderVolume;
    double cylinderVol = 0;
public:
    cylinder(double r, double l){
        sn = luggage::setSn();
        radius = r;
        length = l;
        type = "Cylinder";
        count  ++;
        cylinderVol =getVolume();
        totalCylinderVolume += cylinderVol;
    }
    int setSn(){
        return sn;
    }
    double getVolume(){
        return M_PI * radius * radius * length;
    }
    ~cylinder(){
        count --;
        totalCylinderVolume -= cylinderVol;
    }
    static int totalCount(){
        return count ;
    }
    string getType(){
        return type;
    }
    static double totalVolume(){

        return totalCylinderVolume;
    }
};
int cylinder::count = 0;
double cylinder::totalCylinderVolume = 0;

int main() {
    vector<luggage *> container;
    luggage *lptr;
    // save time to input
//    container.push_back(new box(1, 2, 3)); //item 1
//    container.push_back(new sphere(1.3));    //item 2
//    container.push_back(new pyramid(2.4, 5.2));//item 3
//    container.push_back(new box(2.3, 2.4, 1.5)); //item 4
//    container.push_back(new cylinder(2.5, 7)); //item 5
//    container.push_back(new cube(4.3));//item 6
//    container.push_back(new cube(7.3));//item 7
//    container.push_back(new cube(4)); //item 8
//    container.push_back(new cube(6.7)); //item 9
//    container.push_back(new cube(4.9)); //item 10
//    container.push_back(new box(2, 3, 4.5));//item 11
    int optionChoice = 0;
    while (optionChoice!=5) {
        cout << "1) Add luggage to storage container\n"
                "2) Remove luggage from storage container\n"
                "3) Show all luggage\n"
                "4) Show total volumes\n"
                "5) Quit\n";
        cin >> optionChoice;
        switch (optionChoice) {
            cout<< setprecision(1);
            case 1: {
                double boxWidth, boxHeight, boxLength;

                cout << "Available luggage types can added: \n1)Box\n2)Sphere\n3)Cube\n4)Pyramid\n5)Cylinder\n";
                int typeChoice;
                cin >> typeChoice;
                if (typeChoice == 1) {
                    cout<<fixed<< setprecision(1);
                    cout << "Add a Box with width, height and length: ";
                    cin >> boxWidth;
                    cout << "The width of box is: " + to_string(boxWidth) + "\n";
                    cin >> boxHeight;
                    cout << "The Height of box is: " + to_string(boxHeight) + "\n";
                    cin >> boxLength;
                    cout << "The Length of box is: " + to_string(boxLength) + "\n";

                    lptr = new box(boxWidth, boxHeight, boxLength);
                    container.push_back(lptr);
                    lptr->totalCount();
                    cout <<"A box added into the luggage and the volume is: " <<lptr->getVolume()<<endl;

                } else if (typeChoice == 2) {
                    cout<<fixed<< setprecision(1);
                    double sphereRadius;
                    cout << "Add a Sphere with radius: \n";
                    cin >> sphereRadius;
                    cout << "The radius of sphere is: " + to_string(sphereRadius) + "\n";
                    lptr = new sphere(sphereRadius);
                    container.push_back(lptr);
                    lptr->totalCount();
                    cout <<"A Sphere added into the luggage and the volume is: " <<lptr->getVolume()<<endl;

                } else if (typeChoice == 3) {
                    double cubeWidth;
                    cout << "Add a Cube with width: \n";
                    cin >> cubeWidth;
                    lptr = new cube(cubeWidth);
                    container.push_back(lptr);
                    lptr->totalCount();
                    cout<<fixed<< setprecision(1);
                    cout <<"A Cube added into the luggage and the volume is: " <<lptr->getVolume()<<endl;

                } else if (typeChoice == 4) {
                    double pyramidBase, pyramidHeight;
                    cout << "Add a pyramid with base and height: \n";
                    cin >> pyramidBase;
                    cin >> pyramidHeight;
                    cout << "The base and height of pyramid is: " << to_string(pyramidBase) << " "
                         << to_string(pyramidHeight) << "\n";
                    lptr = new pyramid(pyramidBase, pyramidHeight);
                    container.push_back(lptr);
                    lptr->totalCount();
                    cout<<fixed<< setprecision(1);
                    cout <<"A Pyramid added into the luggage and the volume is: " <<lptr->getVolume()<<endl;

                } else if (typeChoice == 5) {
                    double cylinderRadius, cylinderLength;
                    cout << "Add a Cylinder with radius and length: \n";
                    cin >> cylinderRadius;
                    cin >>cylinderLength;
                    cout << "the radius and length is: "
                         << to_string(cylinderRadius) + " " + to_string(cylinderLength) + "\n";
                    lptr = new cylinder(cylinderRadius, cylinderLength);
                    container.push_back(lptr);
                    cout <<"total Cylinder Count: " <<lptr->totalCount() <<endl;
                    cout <<"A Cylinder added into the luggage and the volume is: " <<lptr->getVolume()<<endl;
                }
                break;
            }
            case 2: {
                if(container.empty()){
                    cout<<"No luggage in the container now, please add at least one type of luggage\n";
                    break;
                }
                cout << "All the luggage in the container now: \n";
                cout<<fixed<< setprecision(1);
                int count = 0;
                for (auto l: container) // container is vector<luggage*>
                    cout << ++count << ") " << l << endl;

                cout<<"Enter the ordered number related to the luggage(SN) to delete it: " <<endl;
                int deleteChoice;
                cin >>deleteChoice;
                cout<<container[deleteChoice -1] ->getType() <<"   "<< container[deleteChoice - 1] ->getVolume() <<" has been deleted"<<endl;
                delete container.at(deleteChoice - 1);
                container.erase(container.begin() + deleteChoice  - 1);
                break;
            }
            case 3:{
                if(container.empty())
                    cout<<"No luggage in the container now, please add at least one type of luggage\n";
                else{
                    int count = 0;
                    for (auto l: container) // container is vector<luggage*>
                        cout << ++count << ") " << l << endl;

                    double totalVolume = 0.0;
                    for(int i = 0; i < container.size(); i++)
                        totalVolume += container[i] ->getVolume();
                    cout<<endl;
                    cout<<fixed;
                    cout<<setprecision(1);
                    cout<<"Total Volume: " << setw(10)<<right<< totalVolume<<endl<<endl;
                    cout <<"Total Luggage Items: " <<setw(3)<<right<<luggage::totalCount()<<endl
                        <<"Total Boxes: " <<setw(11)<<right<<box::totalCount()<<endl
                        <<"Total Spheres: "<<setw(9)<<right<<sphere::totalCount()<< endl
                        <<"Total Cubes: "<<setw(11)<<right<<cube::totalCount()<< endl
                        <<"Total Pyramids: "<<setw(8)<<right<<pyramid::totalCount()<< endl
                        <<"Total Cylinders: "<<setw(7)<<right<<cylinder::totalCount()<<endl<<endl;
                }
                break;
            }
            case 4: {
                double totalVolume = 0.0;
                for(int i = 0; i < container.size(); i++)
                    totalVolume += container[i] ->getVolume();
                cout<<fixed;
                cout <<setprecision(1);
                cout << "Item Type"<<setw(15) <<"Total Volume"<<endl;
                cout <<left <<setfill(' ') <<setw(15) <<"Box" <<setw(25) <<box::totalVolume() <<endl
                    <<setw(15)<<"Sphere"<<setw(15) <<sphere::totalVolume()<<endl
                    <<setw(15)<<"Cube"<<setw(15) <<cube::totalVolume()<<endl
                    <<setw(15)<<"Pyramid"<<setw(15) <<pyramid::totalVolume()<<endl
                    <<setw(15)<<"Cylinder"<<setw(15) <<cylinder::totalVolume()<<endl
                    <<setw(15)<<"Luggage"<<setw(15) <<totalVolume<<endl;
                break;
            }

            case 5:{
                cout << "Qutting...." <<endl;
                break;
            }
            default:
                cout <<"Wrong choice \n";
        }
    }
    return 0;
}

