#include <curses.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;
class EarnMoney{
	private:
		
	public:
		int carType;
		int busType;
		int truckType;
		int bikeType;
		int cycleType;
		int total;
		EarnMoney()
		{
			this->carType = 0;
			this->busType = 0;
			this->truckType = 0;
			this->bikeType = 0;
			this->cycleType = 0;
			this->total = 0;
		}
		void setEarnMoney(int car, int bus, int truck, int bike, int cycle, int totalMoney)
		{
			this->carType = car;
			this->busType = bus;
			this->truckType = truck;
			this->bikeType = bike;
			this->cycleType = cycle;
			this->total = totalMoney;
		}
		void printEarnMoney()
		{
			cout<<"\n--------------------------------------------------------------\n";
            cout<<setw(10)<<"Car|"<<setw(10)<<"Bus|"<<setw(10)<<"Truck|"<<setw(10)<<"Bike|"<<setw(10)<<"Cycle|"<<setw(10)<<"Total|";
            cout<<"\n--------------------------------------------------------------\n";
            cout<<setw(9)<<this->carType<<"|"<<setw(9)<<this->busType<<"|"<<setw(9)<<this->truckType<<"|"<<setw(9)<<this->bikeType<<"|"<<setw(9)<<this->cycleType<<"|"<<setw(9)<<this->total<<"|";
            cout<<"\n--------------------------------------------------------------\n";
		}
		void allEarnedMoney();
		friend void addTwoMoney(EarnMoney, EarnMoney&);
};
void EarnMoney::allEarnedMoney()
{
	ifstream fin;
	fin.open("earnedMoney.txt", ios_base::in|ios_base::binary);
	if(!fin)
	{
		cout << "File not found" << endl;
	}
	else
	{
		fin.read((char*)this, sizeof(*this));
		this->printEarnMoney();
	}
	fin.close();
}
void addTwoMoney(EarnMoney oldMoney, EarnMoney &newMoney)
{
	newMoney.carType += oldMoney.carType;
	newMoney.busType += oldMoney.busType;
	newMoney.truckType += oldMoney.truckType;
	newMoney.bikeType += oldMoney.bikeType;
	newMoney.cycleType += oldMoney.cycleType;
	newMoney.total += oldMoney.total;
}
class VehicleType
{
private:
    char vehicleTypeName[20];

public:
    VehicleType()
    {
        strcpy(vehicleTypeName, "vehicle");
    }
    void vehicleName(EarnMoney &earnMoney)
    {
        while (true)
        {
            cout << "SELECT VEHICLE TYPE: " << endl;
            cout << "1.CAR,   2.BUS,   3.TRUCK,   4.BIKE,   5.CYCLE"<<endl;
            int vehicletype;
            cin >> vehicletype;
            if (vehicletype == 1)
            {
                strcpy(vehicleTypeName, "CAR");
                earnMoney.setEarnMoney(100,0,0,0,0,100);
                break;
            }
            else if (vehicletype == 2)
            {
                strcpy(vehicleTypeName, "BUS");
                earnMoney.setEarnMoney(0,200,0,0,0,200);
                break;
            }
            else if (vehicletype == 3)
            {
                strcpy(vehicleTypeName, "TRUCK");
                earnMoney.setEarnMoney(0,0,350,0,0,350);
                break;
            }
            else if (vehicletype == 4)
            {
                strcpy(vehicleTypeName, "BIKE");
                earnMoney.setEarnMoney(0,0,0,50,0,50);
                break;
            }
            else if (vehicletype == 5)
            {
                strcpy(vehicleTypeName, "CYCLE");
                earnMoney.setEarnMoney(0,0,0,0,25,25);
                break;
            }
            else
            {
                cout << endl;
                cout << "invalid choice";
            }
        }
    }
    void printVehicleName(){
            cout << vehicleTypeName << endl;
        }
};
class Vehicle : public VehicleType
{
private:
    int vehicleNO;
    char description[100];
    char createdDateTime[50];
    char lastUpdatedTime[50];
    EarnMoney earnMoney;

public:
    Vehicle()
    {
        this->vehicleNO = 0;
        strcpy(this->description, "default");
        time_t t;
        time(&t);
        strcpy(this->createdDateTime, asctime(localtime(&t)));
        strcpy(this->lastUpdatedTime, asctime(localtime(&t)));
    }
    void setVehicle()
    {
        cout << "Enter vehicle number: ";
        cin >> vehicleNO;
        cin.ignore();
        cout << "Enter vehicle description: ";
        cin.getline(description, 100);
        vehicleName(earnMoney);
        time_t t;
        time(&t);
        strcpy(this->createdDateTime, asctime(localtime(&t)));
        strcpy(this->lastUpdatedTime, asctime(localtime(&t)));
    }
    void printVehicle()
    {
        cout << vehicleNO << endl;
        cout << description << endl;
        printVehicleName();
        cout << createdDateTime << " " << lastUpdatedTime << endl;
        earnMoney.printEarnMoney();
    }
    void addVehicle();
    void getAllVehicle();
    void searchVehicle(int vn);//vn = vehicel number
    void deleteVehicle(int vn);
    void updateVehicle(int vn);
};
void Vehicle::addVehicle()
{
	ofstream file;
	file.open("vehicleData.txt", ios_base::app|ios_base::binary);
	file.write((char*)this, sizeof(*this));
    file.close();
    EarnMoney em;
    em.allEarnedMoney();
    addTwoMoney(em,this->earnMoney);
    file.open("earnedMoney.txt", ios_base::out|ios_base::binary);
    file.write((char*)(&this->earnMoney), sizeof(this->earnMoney));
    file.close();
    cout << "Recored added" << endl;
}
void Vehicle:: getAllVehicle(){
	ifstream fin;
	int record = 0;
	fin.open("vehicleData.txt", ios_base::in|ios_base::binary);
	if(!fin)
	{
		cout << "\nFile not found..";
	}
	else
	{
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof())
		{
			this->printVehicle();
			record++;
			fin.read((char*)this, sizeof(*this));
		}
		fin.close();
		if(record == 0)
		{
			cout << "oops!!\nthe file has no record..."<<endl;
		}
	}
}
void Vehicle::searchVehicle(int vn)
{
	ifstream fin;
	int record = 0;
	fin.open("vehicleData.txt", ios_base::in|ios_base::binary);
	if(!fin)
	{
		cout << "\nFile not found..";
	}
	else
	{
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof())
		{
			if(this->vehicleNO==vn)
			{
				this->printVehicle();
				record = 1;
				break;
			}
			fin.read((char*)this, sizeof(*this));
		}
		fin.close();
		if(record == 0)
		{
			cout << "oops!!\nRecord not found..."<<endl;
		}
	}
}
void Vehicle::deleteVehicle(int vn)
{
	ifstream fin;
	ofstream fout;
	int flag = 0;
	fin.open("vehicleData.txt", ios_base::in|ios_base::binary);
	if(!fin)
	{
		cout << "\nFile NOT found!!";
	}
	else
	{
		fin.read((char*)this, sizeof(*this));
		fin.open("vehicleTempData.txt", ios_base::out|ios_base::binary);
		while(!fin.eof())
		{
			if(this->vehicleNO==vn)
			{
				flag = 1;
			}
			else
			{
				cout << "Recored deleted!!";
				remove("vehicleData.txt");
				rename("vehicleTempData.txt","vehicleData.txt");
			}
		}
	}
}
void Vehicle::updateVehicle(int vn)
{
	fstream fileinout;
	int flag = 0;
	fileinout.open("vehicleData.txt", ios_base::in|ios_base::out|ios_base::ate|ios_base::binary);
	fileinout.seekg(0);
	if(!fileinout)
	{
		cout << "File not found!!" << endl;
	}
	else
	{
		fileinout.read((char*)this, sizeof(*this));
		while(!fileinout.eof())
		{
			if(this->vehicleNO == vn)
			{
				cout<<"Updating The Data........" << endl;
                cout<<"Enter The Vehicle Number: " << endl;
                cin>>vehicleNO;
                cin.ignore();
                cout<<"Enter The Vehicle Description: " << endl;
                cin.getline(description,50);
                time_t t;
                time (&t);
                strcpy(lastUpdatedTime, asctime(localtime(&t)));
                fileinout.seekp((fileinout.tellp())-(sizeof(*this)));
                fileinout.write((char*)this, sizeof(*this));
                cout << "Record updated successfully.." << endl;
                flag = 1;
                break;
			}
			fileinout.read((char*)this, sizeof(*this));
		}
		fileinout.close();
		if(flag==0)
		{
			cout << "Record not found!!" << endl;
		}
	}
}
int menu()
{
    int ch;
    cout << "1. Add Vehicle" << endl;
    cout << "2. Search Vehicle"<< endl;
    cout << "3. Delete Vehicle" << endl;
    cout << "4. Update Vehicle" << endl;
    cout << "5. List All Vehicle" << endl;
    cout << "6. Check Earned Money"<< endl;
    cout << "7. Exit" << endl;
    cout << "Enter Your Choice: ";
    cin >> ch;
    return ch;
}
int main()
{
    Vehicle vehicle;
    EarnMoney earnedMoney;
    int breakInfiniteloop=0,vno; 
    
     while(1)
     {
        switch(menu())
        {
            case 1:
                vehicle.setVehicle();
                vehicle.addVehicle();
                break;
            case 2:
                cout<<"\nEnter The Vehicle Number To Searched: ";
                cin>>vno;
                vehicle.searchVehicle(vno);
                break;
            case 3:
                cout<<"\nEnter The Vehicle Number To Deleted: ";
                cin>>vno;
                vehicle.deleteVehicle(vno);
                break;
            case 4:
                cout<<"\nEnter The Vehicle Number To Updated: ";
                cin>>vno;
                vehicle.updateVehicle(vno);
                
                break;
            case 5:
                vehicle.getAllVehicle();
                break;
            case 6:
                earnedMoney.allEarnedMoney();
                earnedMoney.printEarnMoney();
                break;
            case 7:
                breakInfiniteloop=1;
                break;
            default:
                cout<<"\nInvalid Choice:";
        }//end of switch
        if(breakInfiniteloop==1)
        {
            break;
        }
    }//enf of infinite loop
    return(0);  
}
