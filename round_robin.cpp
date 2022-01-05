#include <iostream>
using namespace std;

class Process
{
public:
    string processName;
    int processTime;

    Process(string name, int time)
    {
        processTime = time;
        processName = name;
    }
};

struct Node
{
    Process *process;
    Node *next;
};

class CircularLinkedList
{
    Node *head;
    Node *tail;

public:
    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void pushProcessAtEnd(Process *process)
    {
        Node *newNode = new Node();
        newNode->process = process;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->process->processName << " has a process time of " << temp->process->processTime << endl;
            if (temp->next == head)
            {
                break;
            }
            temp = temp->next;
        }

        if (getSize() == 0)
        {
            cout << "Completed all processes" << endl;
        }
    }

    void removeCompletedProcess()
    {
        Node *temp = head;

        cout << head->process->processName << " is completed" << endl;

        if (head == tail)
        {
            delete temp;
            head = nullptr;
            tail = nullptr;
            return;
        }
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void moveProcessToEnd()
    {
        tail = head;
        head = head->next;
    }

    void decreaseTimeOfProcess(int timeToBeDecreased)
    {
        head->process->processTime -= timeToBeDecreased;
    }

    int getSize()
    {
        Node *temp = head;
        int counter = 0;
        while (temp)
        {
            counter++;
            if (temp->next == head)
            {
                break;
            }
            temp = temp->next;
        }
        return counter;
    }

    Node getItem(int position)
    {
        int counter = 0;
        Node *temp = head;
        while (counter <= getSize())
        {
            if (counter == position)
            {
                return *temp;
            }
            temp = temp->next;
            counter++;
        }
        return *temp;
    }
};

class Runner
{
    CircularLinkedList circularLinkedList;
    int quantumTime = 5000; // 5000ms
public:
    void add(string name, int time)
    {
        Process *process = new Process(name, time);
        circularLinkedList.pushProcessAtEnd(process);
    }

    void startProcessing()
    {
        circularLinkedList.display();
        cout << endl;
        while (true)
        {
            if (circularLinkedList.getSize() == 0)
            {
                break;
            }
            Node node = circularLinkedList.getItem(0);

            if (node.process->processTime <= quantumTime)
            {
                circularLinkedList.removeCompletedProcess();
            }
            else
            {
                circularLinkedList.decreaseTimeOfProcess(quantumTime);
                circularLinkedList.moveProcessToEnd();
            }
        }
        circularLinkedList.display();
        cout << endl;
    }
};

int main()
{
    try
    {
        Runner runner;
        runner.add("Process 1", 1000);
        runner.add("Process 2", 7000);
        runner.add("Process 3", 4000);
        runner.add("Process 4", 9000);
        runner.add("Process 5", 3000);
        runner.add("Process 6", 2000);
        runner.startProcessing();
    }
    catch (...)
    {
        cout << "problem is not schedulable under said scheduling algorithm" << endl;
    }
}