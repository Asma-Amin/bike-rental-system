#include <iostream>
#include <fstream>

using namespace std;

class Rentallog
{
protected:                //file is proctect from public access
    fstream file;
public:
    // Ensures 'rental_log.txt' exists. Creates it if not found.
    void load_log()
    {
        if (file.is_open()) file.close();
        
        ifstream checkFile("rental_log.txt");
        if(!checkFile)
        {
            checkFile.close();
            ofstream createFile("rental_log.txt");
            createFile.close();
            cout << "File 'rental_log.txt' did not exist and was created." << endl;
        }
        else
        {
            checkFile.close();
        }
    }

    // Reads and displays the rental logs of bikes from 'rental_log.txt'
    void show_log()
    {
        if (file.is_open()) file.close();
        file.open("rental_log.txt", ios::in);
        
        if(!file)
        {
            cout << "File 'rental_log.txt' could not be opened for reading." << endl;
            return;
        }

        string current_line;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        cout << "| Payment ID | Rider ID |  Bike ID  | Rental Status |    Time    |    Day    |   Price/Hr   |" << endl;
        cout << "---------------------------------------------------------------------------------------------" << endl;
        
        while(getline(file, current_line))
        {
            int column_index = 0;                           
            size_t starts = 0;
            string field_data;
            cout << "| ";

            for(size_t i = 0; i <= current_line.length(); i++) {
                if(current_line[i] == ',' || i == current_line.length()) {
                    field_data = current_line.substr(starts, i - starts);
                    
                   // setting witdth of columns
                    if(column_index == 0) cout.width(14);
                    else if(column_index == 1) cout.width(11);
                    else if(column_index == 2) cout.width(11);
                    else if(column_index == 3) cout.width(12);
                    else if(column_index == 4) cout.width(15);
                    else if(column_index == 5) cout.width(11);
                    else if(column_index == 6) cout.width(10); 

                    cout << left << field_data;
                    
                    if(column_index < 6) cout << " "; 
                    
                    column_index++;
                    starts = i + 1;
                }
            }
            
            // Fill remaining columns with "xx" if a line is short
            for(int i = column_index; i < 7; i++) {
                if(i == 0) cout.width(15);
                else if(i == 1) cout.width(10);
                else if(i == 2) cout.width(10);
                else if(i == 3) cout.width(15);
                else if(i == 4) cout.width(10);
                else if(i == 5) cout.width(12);
                else if(i == 6) cout.width(12);
                cout << left << "xx";
                if(i < 6) cout << " ";
            }
            cout << "|" << endl;
        }
        cout << "---------------------------------------------------------------------------------------------" << endl;
        system("pause");
        system("cls");
        file.close();
    }
    
};

class Bike : public Rentallog {
    string bikeID, renttime, rentalStatus, rentday;
    double price_per_hour;
public:
    // Registers a new bike rental entry
    void registerBike()
    {
        string paymentID, riderID;
        
        cout << "\nEnter Payment ID: ";
        cin >> paymentID;
        
        cout << "Enter Rider ID: ";
        cin>>riderID;
        
        cout << "Enter Bike ID: ";
        cin>>bikeID;
        
        cout << "Enter Day of Rent (e.g., Mon, Tue): ";
        cin>>rentday;
        
        cout << "Enter Time of Rent (e.g., 10:00:00): ";
        cin>>renttime;

        cout << "Enter Price per Hour (e.g., 10.50): ";
        cin >> price_per_hour;
        
        
        cout << "Enter Rental Status (e.g., BOOKED, RETURNED): ";
        cin>>rentalStatus;

        file.open("rental_log.txt", ios::app);
        if (file.is_open()) {
            file << paymentID << " , " 
                 << riderID << " , " 
                 << bikeID << " , " 
                 << rentalStatus << " , " 
                 << renttime << " , " 
                 << rentday << " , " 
                 << price_per_hour << endl; 
            file.close();
            cout << "\nBike registered successfully!" << endl;
        } else {
            cout << "\nError: Could not open rentallog.txt for registering data." << endl;
        }
        system("pause");
        system("cls");
    }
};

class Rider : public Rentallog {
    string riderID, paymentID;
public:
    // Registers a new rider entry
    void registerRider()
    {
        cout << "\nEnter Payment ID: ";
        cin >> paymentID; 
        
        cout << "Enter Rider ID: ";
        cin>>riderID;

        file.open("rental_log.txt", ios::app);
        if (file.is_open()) {
            file << paymentID << " , " << riderID << " , xx , xx , xx , xx , xx" << endl;
            file.close();
            cout << "\nRider registered successfully!" << endl;
        } else {
            cout << "\nError: Could not open rental_log.txt for registering." << endl;
        }
          
    }
    
};



int main()
{
 
        Bike b;
        Rider r;
        Rentallog l;
        int choice;
        while (true) {
            cout << "\n\t\t\t\t\t===== Bike Rental Management =====\n" << endl;
            cout << "1. Display Rental Log" << endl;
            cout << "2. Add New Bike" << endl;
            cout << "3. Add New Rider" << endl;
            cout << "4. Load Rental Log (Ensures file exists)" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            if (cin.fail()) {
                cout << "Invalid input. Please enter a number." << endl;
                continue;
        }

            if (choice == 1) {
            	  l.show_log();
               
            } else if (choice == 2) {
            	 b.registerBike();
                
            } else if (choice == 3) {
            	r.registerRider();
                
            } else if (choice == 4) {
            	l.load_log();
            	    cout << "Rental log check complete." << endl;
            	 
            } else if (choice == 5) {
                cout << "Exiting program......." << endl;
    
            } else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    

}
