#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Patient class
class Patient {
public:
    int id;
    string name;

    void input() {
        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Name: ";
        getline(cin, name);
    }
};

// Doctor class
class Doctor {
public:
    int id;
    string name;
    string specialization;

    void input() {
        cout << "Enter Doctor ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Doctor Name: ";
        getline(cin, name);
        cout << "Enter Specialization: ";
        getline(cin, specialization);
    }

    void display() const {
        cout << id << " - " << name << " (" << specialization << ")";
    }
};

// Appointment System class
class AppointmentSystem {
    queue<Patient> patientQueue;
    vector<Doctor> doctors;

public:
    void addPatient() {
        Patient p;
        p.input();
        patientQueue.push(p);
        cout << "Patient added to queue.\n";
    }

    void addDoctor() {
        Doctor d;
        d.input();
        doctors.push_back(d);
        cout << "Doctor added successfully.\n";
    }

    void assignAppointment() {
        if (patientQueue.empty()) {
            cout << "No patients in queue.\n";
            return;
        }
        if (doctors.empty()) {
            cout << "No doctors available.\n";
            return;
        }

        Patient p = patientQueue.front();
        patientQueue.pop();

        Doctor d = doctors[0]; 

        cout << "\n--- Appointment Slip ---\n";
        cout << "Patient ID: " << p.id << endl;
        cout << "Patient Name: " << p.name << endl;
        cout << "Doctor: ";
        d.display();
        cout << endl;
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Hospital Appointment Scheduler ---\n";
            cout << "1. Add Patient\n";
            cout << "2. Add Doctor\n";
            cout << "3. Assign Appointment\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addPatient(); break;
                case 2: addDoctor(); break;
                case 3: assignAppointment(); break;
                case 4: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    AppointmentSystem system;
    system.menu();
    return 0;
}
