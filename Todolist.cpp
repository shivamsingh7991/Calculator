#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct todolist{
    int id;
    string task;
};

int ID;

void banner();
void addTask();
void viewTask();
void deleteTask();

int main(){
    system(" cls ");
    while(true){
        banner();
        cout<<"\n\t1. Add Task";
        cout<<"\n\t2. View Task";
        cout<<"\n\t3. Delete Task";

        int choice;
        cout<<"\n\tEnter choice: ";
        cin>>choice;

        switch (choice){
        case 1: 
            addTask();
            break;

        case 2:
            viewTask();
            break;

        case 3: 
           deleteTask();
            break;
        
        default:
            break;
        }
    }
    return 0;
} 

void banner(){
    cout<<"_______________________________________"<<endl;
    cout<<"\t      My Todo"<<endl;
    cout<<"_______________________________________"<<endl;
}

void addTask(){
    system("cls");
    banner();
    todolist todo;
    cout<<"Enter new Task: "<<endl;
    cin.get();
    getline(cin, todo.task);
    char save;
    cout<<"Save? (y/n): ";
    cin>>save;
    if(save == 'y'){
        ID++;
        ofstream fout;
        fout.open("todo.txt", ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<todo.task;
        fout.close();

        char more;
        cout<<"Add more task? (y/n): ";
        cin>>more;

        if(more == 'y'){
            addTask();
        }
        else{
            system("cls");
            cout<<"Added Successfully!"<<endl;
            return ;
        }
    }
    system("cls");
}

void viewTask(){
    system("cls");
    banner();
    todolist todo;
    ifstream fin;
    fin.open("todo.txt");
    cout<<"Task: "<<endl;

    while(!fin.eof()){
       fin>>todo.id;
       fin.ignore();
       getline(fin, todo.task);
       if(todo.task != ""){
        cout<<"\t"<<todo.id<<": "<<todo.task<<endl;
       }
       else{
        cout<<"\tEmpty! "<<endl;
       }
    }
   fin.close();
    char exit;
    cout<<"Exit? (y/n): ";
    cin>>exit;
    if(exit != 'y'){
        viewTask();
    }
    system("cls");
}

void deleteTask(){
    system("cls");
    if(ID != 0){
        char del;
        cout<<"\n\t Delete? (y/n): ";
        cin>>del;

        if (del == 'y'){
            todolist todo;
            ofstream tempFile;
            tempFile.open("temp.txt");
            ifstream fin;
            fin.open("todo.text");
            int index = 1;
            while(! fin.eof()){
                fin>> todo.id;
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != ID){
                    tempFile << "\n"<<index;
                    tempFile << "\n"<<todo.task;
                    index++;
                    ID--; 
                }
            }
            fin.close();
            tempFile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            system("cls");
            cout<<"\n\tDelete Successfully!"<<endl;
        }
        else{
            system("cls");
            cout<<"NOt deleted! "<<endl;
        }
    }
}