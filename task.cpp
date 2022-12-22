#include <iostream>
using namespace std;

class Room{
    protected:
        int roomNo;
        string type;
        int rent;
        string status;
        int checkOutTime;
        int CheckInTime;
    
    public:
    // constructor fucntion for room class 
        Room(){
            this->roomNo = 0;
            this->rent = 0;
            this->status = "free";
            this->type = "null";
        }
        // setter function for room class to set the values
        void setData(int roomNo, int rent, string status, string type){
            this->rent = rent; // assigning the values to varibles;
            this->roomNo = roomNo;
            this->type = type;
            this->status = status;
        }
        // functioon to get data from the class
        int getRoomNo(){
            return this->roomNo;
        } 
        int getRent(){
            return this->rent;
        }
        string getStatus(){
            return this->status;
        }
        string getType(){
            return this->type;
        }
        int getCheckIntime(){
            return this->CheckInTime;
        }

};

//hotel class
class Hotel{
    private:
        string nameOfHotel;
        string location;
        string nameOfOwnwer;
        Room rooms[10];
        static int bookingId;

    public:
        //constructor for the hotel class
        Hotel(){
            this->nameOfHotel = "null";
            this->location = "null";
            this->nameOfOwnwer = "null";
            bookingId++;
        }
        void setData(string nameOfHotel, string location, string nameOfOwnwer){
            this->nameOfHotel = nameOfHotel;
            this->location = location;
            this->nameOfOwnwer = nameOfOwnwer;

        }
        void getAvailRoom(){
            for(int i = 0;i<= 0;i++){
                if(this->rooms[i].getStatus() == "free"){
                    cout << "room No: " << rooms[i].getRoomNo() << endl;
                    cout << "room type: " << rooms[i].getType() << endl;
                    cout << "room rent: " << rooms[i].getRent() << endl;
                }
            }
        }
        void showRoomSummary(int roomNo){
            cout << "the status of the room is: " << rooms[roomNo].getStatus() << endl;
            cout << "check in Time: " << rooms[roomNo].getCheckIntime();
        }
        // void CheckIn(int roomNo){
        //     this->rooms[roomNo].;
        // }

        //setter and getter of the hotel class

};
int Hotel::bookingId = 0;