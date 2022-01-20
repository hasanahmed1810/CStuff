#include <iostream>

using namespace std;

class Patient {
    int patientId{};
    string patientName;

public:
    Patient() {}

    Patient(int patientId, string patientName) {
        {
            this->patientName = patientName;
            this->patientId = patientId;
        }
    }

    int getPatientId() {
        return patientId;
    }

    string getPatientName() {
        return patientName;
    }
};

class WaitingRoom {
private:
    int capacity;
    int counter = 1;
    Patient *myQueue = new Patient[capacity];
    int front = -1;
    int rear = -1;

    void insertionSort(Patient array[], int n) {
        int i;
        int j;
        for (i = 1; i < n; i++) {
            Patient temp = array[i];
            for (j = i; j > 0 && temp.getPatientName().compare(array[j - 1].getPatientName()) == -1; j--) {
                array[j] = array[j - 1];
            }
            array[j] = temp;
        }
    }

public:
    WaitingRoom(int capacity) {
        this->capacity = capacity;
    }

    bool isFull() {
        return front == 0 && rear == capacity - 1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void registerPatient(string patient_name) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            myQueue[rear] = Patient(counter, patient_name);
            counter++;
            cout << "Patient " << patient_name << " has been registered" << endl;
        }
    }

    void servePatient() {
        if (isEmpty()) {
            cout << "No more patients waiting" << endl;
        } else {
            if (front == rear) {
                cout << "Calling patient " << myQueue[0].getPatientName() << " ID: " << myQueue[0].getPatientId()
                     << endl;
                rear = -1;
                front = -1;
            } else {
                cout << "Calling patient " << myQueue[0].getPatientName() << " ID: " << myQueue[0].getPatientId()
                     << endl;
                for (int i = front; i < rear; i++) {
                    myQueue[i] = myQueue[i + 1];
                }
                rear--;

            }
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No more patients waiting" << endl;
        } else {
            cout << "Displaying all patients sorted according to their IDs" << endl;
            for (int i = front; i <= rear; i++) {
                cout << "Patient ID: " << myQueue[i].getPatientId() << " Patient name: " << myQueue[i].getPatientName() << endl;
            }
        }
    }

    void getFront() {
        cout << "Patient ID: " << myQueue[front].getPatientId() << " Patient name: " << myQueue[front].getPatientName()
             << endl;
    }

    void cancelAll() {
        this->counter = 1;
        this->front = -1;
        this->rear = -1;
        delete[] myQueue;
        cout << "All appointments have been canceled" << endl;
    }

    bool canDoctorGoHome() {
        return isEmpty();
    }

    void showAllPatients() {
        if (isEmpty()){
            cout << "No more patients waiting" << endl;
        }
        else{
            cout << "Displaying all patients sorted according to their names" << endl;
            Patient *array = new Patient[capacity];
            for (int i = front; i <= rear; i++) {
                array[i] = myQueue[i];
            }
            insertionSort(array, capacity);
            for (int i = front; i <= rear; i++) {
                cout << "Patient ID: " << array[i].getPatientId() << " Patient name: " << array[i].getPatientName() << endl;
            }
        }
    }
};


int main() {
    WaitingRoom waitingRoom(1000);
    waitingRoom.registerPatient("hamza");
    waitingRoom.registerPatient("hasan");
    waitingRoom.registerPatient("ahmed");
    waitingRoom.showAllPatients();
    waitingRoom.servePatient();
    waitingRoom.servePatient();
    waitingRoom.servePatient();
    waitingRoom.showAllPatients();
    waitingRoom.registerPatient("rana");
    waitingRoom.registerPatient("raja");
    waitingRoom.showAllPatients();
    waitingRoom.cancelAll();
    waitingRoom.showAllPatients();
    return 0;
}
