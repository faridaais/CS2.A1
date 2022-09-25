
#include <iostream>
#include <queue>
using namespace std;

class Car {

    private:
        string Car_Brand;
        string Car_Type;
        string Car_Plate;
        int Speed;
        int Year_Model;

    public:
        Car(){
            Car_Brand = " ";
            Car_Type = " ";
            Car_Plate = " ";
            Speed = 0;
            Year_Model = 0;
        }

        Car(string brand, string Type, string plate, int MaxSpeed, int year){
            Car_Brand = brand;
            Car_Type = Type;
            Car_Plate =  plate;
            if (MaxSpeed > 0){
                MaxSpeed = Speed;
            }
            Year_Model = year;
        }

        //setters and getters
            void setBrand(string brand){
                brand = Car_Brand;
            }

            string getBrand(){
                return Car_Brand;
            }

            void setType(string type){
                type = Car_Type;
            }

            string getType(){
                return Car_Type;
            }

            void setPlate(string plate){
                plate = Car_Plate;
            }

            string getPlate(){
                return Car_Plate;
            }

            void setSpeed(int s){
                s = Speed;
            }

            int getSpeed(){
                return Speed;
            }

            void setYear(int year){
                year= Year_Model;
            }

            int getYear(){
                return Year_Model;
            }

};

class Road {

    private:
        char Road_Type;
        int Speed_Limit;
        int counter = 0;

    public:
        Road(){
            Road_Type = ' ';
            Speed_Limit = 0;
        }

        Road(char Type, int limit){
            if (Type == 'A' || Type == 'B' || Type == 'C'){
                Road_Type = Type;
            }

            if (limit >= 0){
                Speed_Limit = limit;
            }
        }

        bool radar(int car_speed, char RoadChar){
            if (car_speed > 80 && RoadChar == 'A'){
                return true;
            }
            else if (car_speed > 100 && RoadChar =='B'){
                return true;
            }
            else if (car_speed > 120 && RoadChar == 'C'){
                return true;
            }

            else {
                return false;
            }
            }

        void allow(string CarType){
            switch (Road_Type){
                case 'A':
                    if (CarType!= "Private" || CarType != "motorcycle"){
                        cout<< "This vehicle is not allowed on this road";
                    }
                    else{
                        cout<< "This vehicle is allowed on this road";
                        counter++;
                    }
                    break;

                case 'B':
                    cout<< "This vehicle is allowed on this road";
                    counter++;
                    break;

                case 'C':
                    if (CarType == "truck"){
                        cout<< "This vehicle is allowed on this road";
                        counter++;
                    }
                    else{
                        cout<< "This vehicle is not allowed on this road";
                    }
            }
        }

        int age(int YearModel){
            int x;
            x = 2022 - YearModel;
            return x;
        }

        int getcounter(){
            return counter;
        }
        
        char getRType(){
            return Road_Type;
        }
        
        //setters and getters
        
        void setRoadType(char RType){
            if (RType == 'A' || RType == 'B' || RType == 'C'){
                Road_Type = RType;}
        }
        
        char getRoadType(){
            return Road_Type;
        }
        
        void setRoadLimit(int RLimit){
            if (RLimit > 0){
                Speed_Limit = RLimit;
            }
        }
        
};


int main(){

Car car1;
Car car2;
Car car3;
Car car4;
Car car5;

car1.setBrand("Mercedes");
car1.setType( "Private");
car1.setPlate("FIMY2422");
car1.setSpeed(120);
car1.setYear(2016);

car2.setBrand("Mitsubishi");
car2.setType("Bus");
car2.setPlate("DSBA9911");
car2.setSpeed(140);
car2.setYear(2004);

car3.setBrand("Chevrolet");
car3.setType("motorcycle");
car3.setPlate("HH7778");
car3.setSpeed(60);
car3.setYear(2018);

car4.setBrand("Suzuki");
car4.setType("truck");
car4.setPlate( "FACE476");
car4.setSpeed(70);
car4.setYear(2007);

car5.setBrand("Renault");
car5.setType("Private");
car5.setPlate("ALYI0412");
car5.setSpeed(150);
car5.setYear(2022);


queue <Car> carsQueue;

std::queue<Car> cars{};

cars.push(car1);
cars.push(car2);
cars.push(car3);
cars.push(car4);
cars.push(car5);

Road rd1;
Road rd2;
Road rd3;

rd1.setRoadType('A');
rd1.setRoadLimit(80);

rd2.setRoadType('B');
rd2.setRoadLimit(100);

rd3.setRoadType('C');
rd3.setRoadLimit(120);

while(!carsQueue.empty()){
    if ((rd1.radar(carsQueue.front().getSpeed(), rd1.getRType() )) == true){

        cout<<"This car will be fined \n The car's info:"<< carsQueue.front()::getType()<<" "<<carsQueue.front()::getSpeed()<<" "<<
        carsQueue.front()::getBrand()<<" "<<carsQueue.front()::getPlate<<" "<<carsQueue.front()::getYear();
    }
    rd1.allow(carsQueue.front().getType());

    rd1.age(carsQueue.front().getYear());

    carsQueue.pop();
}

while(!carsQueue.empty()){
    if ((rd2.radar(carsQueue.front().getSpeed(), rd1.getRType() )) == true){

        cout<<"This car will be fined \n The car's info:"<< carsQueue.front()::getType()<<" "<<carsQueue.front()::getSpeed()<<" "<<
        carsQueue.front()::getBrand()<<" "<<carsQueue.front()::getPlate<<" "<<carsQueue.front()::getYear();
    }
    rd2.allow(carsQueue.front().getType());
    
    rd2.age(carsQueue.front().getYear());

    carsQueue.pop();
}

while(!carsQueue.empty()){
    if ((rd3.radar(carsQueue.front().getSpeed(), rd1.getRType() )) == true){

        cout<<"This car will be fined \n The car's info:"<< carsQueue.front()::getType()<<" "<<carsQueue.front()::getSpeed()<<" "<<
        carsQueue.front()::getBrand()<<" "<<carsQueue.front()::getPlate<<" "<<carsQueue.front()::getYear();
    }
    rd3.allow(carsQueue.front().getType());
    
    rd3.age(carsQueue.front().getYear());

    carsQueue.pop();
}

rd1.getcounter();
rd2.getcounter();
rd3.getcounter();

int biggestcount;
if (rd1.getcounter() > rd2.getcounter() && rd1.getcounter() > rd3.getcounter()){
    biggestcount = rd1.getcounter();
    
    cout<< "The road with the highest number of vehicles is road A.\n"<<
    biggestcount<< "is the number of vehicles it had and its efficiency is 100%";
    
    cout<<"Road B had "<< rd2.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd2.getcounter() <<"%";
    cout<<"Road C had "<< rd3.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd3.getcounter() <<"%";
}
else if (rd2.getcounter() > rd3.getcounter() && rd2.getcounter() > rd3.getcounter()){
    biggestcount = rd2.getcounter();
    
    cout<< "The road with the highest number of vehicles is road B.\n"<<
    biggestcount<< "is the number of vehicles it had and its efficiency is 100%";
    
    cout<<"Road A had "<< rd1.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd1.getcounter() <<"%";
    cout<<"Road C had "<< rd3.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd3.getcounter() <<"%";
}

else if(rd3.getcounter() > rd2.getcounter() && rd3.getcounter() > rd1.getcounter()){
    biggestcount = rd3.getcounter();
    
    cout<< "The road with the highest number of vehicles is road C.\n"<<
    biggestcount<< "is the number of vehicles it had and its efficiency is 100%";
    
    cout<<"Road A had "<< rd1.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd1.getcounter() <<"%";
    cout<<"Road B had "<< rd2.getcounter()<< " number of vehicles and efficiency of"<<
    biggestcount/rd2.getcounter() <<"%";
}



}