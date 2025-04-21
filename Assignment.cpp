#include <iostream>
#include <algorithm>
using namespace std;

struct Worker
{
    int id;
    string name, position;
    char gender;
    float hours, wage;

    void input()
    {
        system("cls");
        cout << "\t-> Enter Worker ID: ";
        cin >> id;
        cout << "\t-> Enter Worker Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t-> Enter Worker Gender (M/F): ";
        cin >> gender;
        cout << "\t-> Enter Worker Position: ";
        cin.ignore();
        getline(cin, position);
        cout << "\t-> Enter Work Hours: ";
        cin >> hours;
        cout << "\t-> Enter Wage: ";
        cin >> wage;
    }

    void update()
    {
        system("cls");
        cout << "Updating worker info..." << endl;
        cout << "\t-> Enter New Worker Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\t-> Enter New Worker Gender (M/F): ";
        cin >> gender;
        cout << "\t-> Enter New Worker Position: ";
        cin.ignore();
        getline(cin, position);
        cout << "\t-> Enter New Work Hours: ";
        cin >> hours;
        cout << "\t-> Enter New Wage: ";
        cin >> wage;
    }

    float findSalary()
    {
        float salary = hours * wage;
        if (salary >= 1000)
        {
            if (gender == 'F' || gender == 'f')
            {
                salary *= 0.75;
            }
            else
            {
                salary *= 0.70;
            }
        }
        return salary;
    }

    void output()
    {
        system("cls");
        cout << "\tWorker ID       : " << id << endl;
        cout << "\tName            : " << name << endl;
        cout << "\tGender          : " << gender << endl;
        cout << "\tPosition        : " << position << endl;
        cout << "\tHours Worked    : " << hours << " hr" << endl;
        cout << "\tWage per Hour   : $" << wage << endl;
        cout << "\tSalary          : $" << findSalary() << endl;
    }
};
void pressEnterToContinue()
{
    cout << "=========Enter to continue==========" << endl;
    cin.ignore();
    cin.get();
}

int printMainMenu()
{
    int option;
    system("cls");
    cout << "\n===== Worker Management System =====" << endl;
    cout << "1. Add New Worker" << endl;
    cout << "2. Edit Worker Information" << endl;
    cout << "3. Delete Worker Information" << endl;
    cout << "4. Search Worker Information" << endl;
    cout << "5. Show Worker Information" << endl;
    cout << "6. Exit" << endl;
    cout << ">> Choose an option: ";
    cin >> option;
    return option;
}

int searchWorkerbyId(Worker Workers[], int counter)
{
    int workerId;
    cout << "Enter Worker ID to search : ";
    cin >> workerId;
    int foundIndex = -1; // This variable will store the index of the found worker.It is initially set to -1, which means "not found".
    for (int i = 0; i < counter; i++)
    {
        if (workerId == Workers[i].id)
        {
            foundIndex = i;
            cout << "-----<<Output Worker Information>>-----" << endl;
            Workers[i].output();
        }
    }
    if (foundIndex == -1)
    {
        cout << "Worker record with id = "
             << workerId << "doesn't exist !" << endl;
    }
    return foundIndex;
}

void initWorker(Worker Workers[])
{
    system("cls");
    Workers[0] = {1, "Chea Sovandet", "Web Developer", 'M', 100, 9};
    Workers[1] = {2, "Chea Udom", "Waiter", 'M', 90, 9};
    Workers[2] = {3, "Chavrat Narong", "Seller Coffee", 'M', 80, 9};
}
void printWorkers(Worker workers[], int counter)
{
    system("cls");
    cout << "============ All Worker Info ============" << endl;
    for (int i = 0; i < counter; i++)
    {
        workers[i].output();
        cout << "-----------------[Worker]---------------" << endl;
    }
}

bool workerIdComparater(Worker a, Worker b)
{
    return a.id < b.id;
}
bool salaryComparater(Worker a, Worker b)
{
    return a.findSalary() > b.findSalary();
}

int main()
{
    system("cls");
    int option;
    int n = 5;
    Worker workers[n];
    int counter = 3;
    initWorker(workers);
    do
    {
        option = printMainMenu();
        switch (option)
        {
        case 1:
        {
            if (counter >= n)
            {
                cout << "Worker system is full...! Pls,Try delete data!!" << endl;
                break;
            }
            workers[counter++].input();
            cout << "Successfuly added a new worker! " << endl;
        }
        break;
        case 2:
        {
            if (counter == 0)
            {
                cout << " There is no worker to search!!" << endl;
                break;
            }
            int foundIndex = searchWorkerbyId(workers, counter);
            workers[foundIndex].update();
            cout << "Records has been updated successfully!!! " << endl;
        }
        break;
        case 3:
        {
            if (counter == 0)
            {
                cout << "There is no records in the system..." << endl;
                break;
            }
            int foundIndex = searchWorkerbyId(workers, counter);
            if (foundIndex >= 0)
            {
                char choice;
                bool isValid = false;
                while (!isValid)
                {
                    cout << "Are you sure to delete this record? (Y/N)";
                    cin >> choice;
                    bool isYes = (choice == 'y' || choice == 'Y');
                    bool isNo = (choice == 'n' || choice == 'N');
                    isValid = (isYes || isNo); // check if the input is valid stop it when it true
                    if (isYes)
                    {
                        for (int i = foundIndex; i < counter - 1; i++)
                        {
                            workers[i] = workers[i + 1];
                        }
                        counter--;
                        cout << "Worker deleted successfully! " << endl;
                    }
                    else if (isNo)
                    {
                        cout << "No changes. Delete operation is aborted!! " << endl;
                    }
                    else
                    {
                        cout << "Invalid option!! Chose agian!!" << endl;
                    }
                }
            }
        }
        break;

        case 4:
        {
            if (counter == 0)
            {
                cout << "There is no Worker on the system...!" << endl;
                break;
            }
            searchWorkerbyId(workers, counter);
        }
        break;
        case 5:
            if (counter == 0)
            {
                cout << "There is no Worker on the system...!" << endl;
                break;
            }
            while (true)
            {
                int showOption;
                cout << "================[ Show Worker info ]================" << endl;
                cout << "1. Show Ascending Order By ID " << endl;
                cout << "2. Show des Order By Salary " << endl;
                cout << "==>Choose from 1 - 2 or 0 to quit : ";
                cin >> showOption;
                if (showOption == 0)
                {
                    cout << "Exit from the show option..!" << endl;
                    break;
                }
                else if (showOption == 1)
                {
                    sort(workers, workers + counter, workerIdComparater);
                    printWorkers(workers, counter);
                }
                else if (showOption == 2)
                {
                    sort(workers, workers + counter, salaryComparater);
                    printWorkers(workers, counter);
                }
            }
            break;
        case 6:
            cout << "Exiting the program!! Thank you So Much!!" << endl;
            break;
        default:
            cout << "Invalid option!Pls Choose again!!" << endl;
            break;
        }
        pressEnterToContinue();
    } while (option != 6);

    return 0;
}
