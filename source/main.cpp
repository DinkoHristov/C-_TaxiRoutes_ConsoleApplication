#include <iostream>
#include <fstream>
#include <cstdlib> // for exit function

using namespace std;

class Car
{
public:
    string brand;
    string model;
    int yearOfCreation;
    int seats;
    double loadCapacity;
    double expense;
public:
    //Constructor 1: containing all of the car parameters:
    Car(string b, string m, int y, int s, double l, double e);
    //Constructor 2: containing 0 parameters and reset all of the values of a car to default value
    Car();
    void setBrand (string b);
    string getBrand (void);
    void setModel (string m);
    string getModel (void);
    void setYearOfCreation (int year);
    int getYearOfCreation (void);
    void setSeats (int s);
    int getSeats (void);
    void setLoadCapacity (double load);
    double getLoadCapacity (void);
    void setExpense (double expense);
    double getExpense (void);
};

void Car::setBrand(string currBrand){
    // Setter
    brand = currBrand;
}
string Car::getBrand(void){
    // Getter
    return brand;
}
void Car::setModel(string currModel){
    // Setter
    model = currModel;
}
string Car::getModel(void){
    // Getter
    return model;
}
void Car::setYearOfCreation(int year){
    if (yearOfCreation < 1886)
    {
        //1886 is the first ever made car!
        throw std::invalid_argument("Car year of creation cannot be less than 1886.");
    }
    // Setter
    yearOfCreation = year;
}
int Car::getYearOfCreation(void){
    // Getter
    return yearOfCreation;
}
void Car::setSeats(int currSeats){
    if (seats < 2)
    {
        throw std::invalid_argument("Car seats must be at least 2.");
    }
    // Setter
    seats = currSeats;
}
int Car::getSeats(void){
    // Getter
    return seats;
}
void Car::setLoadCapacity(double currCapacity){
    if (loadCapacity <= 0)
    {
        throw std::invalid_argument("Car load capacity cannot be less than or equal to 0.");
    }
    // Setter
    loadCapacity = currCapacity;
}
double Car::getLoadCapacity(void){
    // Getter
    return loadCapacity;
}
void Car::setExpense(double currExpense){
    if (expense <= 0)
    {
        throw std::invalid_argument("Car expense cannot be less than or equal to 0.");
    }
    // Setter
    expense = currExpense;
}
double Car::getExpense(void){
    // Getter
    return expense;
}

Car::Car(string b, string m, int y, int s, double l, double e)
{
    if (s < 2)
    {
        throw std::invalid_argument("Car seats must be at least 2.");
    }
    if (e <= 0)
    {
        throw std::invalid_argument("Car expense cannot be less than or equal to 0.");
    }
    if (l <= 0)
    {
        throw std::invalid_argument("Car load capacity cannot be less than or equal to 0.");
    }
    if (y < 1886)
    {
        //1886 is the first ever made car!
        throw std::invalid_argument("Car year of creation cannot be less than 1886.");
    }
    brand = b;
    model = m;
    yearOfCreation = y;
    seats = s;
    loadCapacity = l;
    expense = e;
}
Car::Car(){
    brand = "";
    model = "";
    yearOfCreation = 0;
    seats = 0;
    loadCapacity = 0.0;
    expense = 0.0;
}
//Overloading(Predefine) the C++ operation "<<", and print out car information
ostream & operator << (ostream &out, const Car &c)
{
    out << "1.Brand:" << c.brand;
    out << " 2.Model:" << c.model;
    out << " 3.Year:" << c.yearOfCreation;
    out << " 4.Seats:" << c.seats;
    out << "  5.Load capacity:" << c.loadCapacity;
    out << "  6.Expense:" << c.expense << endl;
    out << endl;
    return out;
}


class Route{
public:
    string startPoint;
    string endPoint;
    double distance;
    int repetitions;
public:
    void setStartPoint(string startPoint);
    string getStartPoint(void);
    void setEndPoint(string endPoint);
    string getEndPoint(void);
    void setDistance(double distance);
    double getDistance(void);
    void setRepetitions(int repetitions);
    int getRepetitions(void);
    //Constructor 1(Containing all of the Route parameters)
    Route(string from, string to, double dist, int reps);
    //Constructor 2(Resets all of the Route parameters to default value)
    Route();
};
void Route::setStartPoint(string from){
    startPoint = from;
}
string Route::getStartPoint(void){
    return startPoint;
}
void Route::setEndPoint(string to){
    endPoint = to;
}
string Route::getEndPoint(void){
    return endPoint;
}
void Route::setDistance(double dist){
    distance = dist;
}
double Route::getDistance(void){
    return distance;
}
void Route::setRepetitions(int reps){
    repetitions = reps;
}
int Route::getRepetitions(void){
    return repetitions;
}
Route::Route(string from, string to, double dist, int reps){
    if(dist <= 0)
    {
        throw std::invalid_argument("Distance cannot be less than or equal to 0.");
    }
    if (reps < 1)
    {
        throw std::invalid_argument("Repetitions cannot be less than 1.");
    }
    startPoint = from;
    endPoint = to;
    distance = dist;
    repetitions = reps;
}
Route::Route(){
    startPoint = "";
    endPoint = "";
    distance = 0.0;
    repetitions = 0;
}
//Overloading(Predefine) the C++ operation "<<", and print out car information
ostream & operator << (ostream &out, const Route &r)
{
    out << "1.Starting point:" << r.startPoint;
    out << " 2.End point:" << r.endPoint;
    out << " 3.Distance:" << r.distance;
    out << "  4.Repetitions:" << r.repetitions;
    out << endl;
    return out;
}


class RoutesDone{
public:
    Car car;
    Route route;
public:
    void setCar(Car c);
    Car getCar(void);
    void setRoute(Route r);
    Route getRoute(void);
    //Constructor 1 (Containing all the parameter for one route for a car)
    RoutesDone(Car c, Route r);
    double calculateNeededFuel();
};
void RoutesDone::setCar(Car c){
    car = c;
}
Car RoutesDone::getCar(void){
    return car;
}
void RoutesDone::setRoute(Route r){
    route = r;
}
Route RoutesDone::getRoute(void){
    return route;
}
RoutesDone::RoutesDone(Car c, Route r){
    car = c;
    route = r;
}
double RoutesDone::calculateNeededFuel(){
    return ((route.getDistance() / 100) * car.getExpense()) * route.getRepetitions();
}

int main()
{
    //Our file(outdata is like cin)
    ofstream outdata;

    string command;
    cout << "Do you want to create a brand new car: [Yes / No]" << endl;
    cin >> command;

    if (command == "Yes")
    {
        //Write our car and route to a file
        outdata.open("cars.txt"); // opens the file
        if (!outdata){ // file couldn't be opened
            cerr << "Error: file could not be opened!" << endl;
            exit(1);
        }

        int counter = 1;
        while (true)
        {
            string brand;
            cout << "Enter car brand:" << endl;
            cin >> brand;

            string model;
            cout << "Enter car model:" << endl;
            cin >> model;

            int year;
            cout << "Enter car year of creation:" << endl;
            cin >> year;

            int seats;
            cout << "Enter car seats:" << endl;
            cin >> seats;

            int loadCapacity;
            cout << "Enter car load capacity:" << endl;
            cin >> loadCapacity;

            int expense;
            cout << "Enter car expense:" << endl;
            cin >> expense;

            Car car(brand, model, year, seats, loadCapacity, expense);

            //Print our car data
            cout << endl;
            cout << "Car:" << endl;
            cout << car;
            cout << endl;

            cout << "Let's make a route for our new car:" << endl;
            string startPoint;
            cout << "Enter route starting point:" << endl;
            cin >> startPoint;

            string endPoint;
            cout << "Enter route end point:" << endl;
            cin >> endPoint;

            double distance;
            cout << "Enter route distance:" << endl;
            cin >> distance;

            int repetitions;
            cout << "Enter route repetitions:" << endl;
            cin >> repetitions;

            Route route(startPoint, endPoint, distance, repetitions);

            //Print our route data
            cout << endl;
            cout << "Route:" << endl;
            cout << route;
            cout << endl;

            RoutesDone routeDone(car, route);
            double neededFuel = routeDone.calculateNeededFuel();
            double totalDistance = distance * repetitions;
            cout << "Needed fuel for " << totalDistance << "km"<< " is:" << neededFuel << "!" << endl;

            //If we could opened the file:
            outdata << "-> Car " << counter << endl;
            outdata << car << endl;
            outdata << "-> Route " << counter << endl;;
            outdata << route;
            outdata << "Needed fuel for " << totalDistance << "km"<< " is:" << neededFuel << "!" << endl;
            outdata << endl;

            string command;
            cout << "Do you want to continue adding brand new cars: [Yes / No]" << endl;
            cin >> command;
            if (command == "No")
            {
                cout << "See you next time!" << endl;
                outdata.close();
                return 0;
            }

            counter++;
        }
    }
    else
    {
        cout << "See you next time!" << endl;
        return 0;
    }
}
