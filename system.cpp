#include <iostream>
#include<ctime>
#include<cstdlib>
#include<memory>

using namespace std;


struct Sensor{
    int id;
    float temperature;
    bool status;
    char* timestamp;

};
int main(){
    const int rows = 4;
    const int col = 6;
    srand(static_cast<unsigned int>(time(0)));
    
    Sensor** sensorptr = new Sensor* [rows];

    time_t now = time(nullptr);
    char* dt = ctime(&now);
    

    for(int i=0;i<rows;i++){
      sensorptr[i] = new Sensor[col];
    }
     int idcounter = 0;
    for (int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            sensorptr[i][j].id = idcounter++;
            sensorptr[i][j].temperature = 20.0f + static_cast<float>(rand() %1500)/100.0f;
            sensorptr[i][j].status = rand()%2;
            sensorptr[i][j].timestamp = dt;

        }
    }

    for (int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            Sensor& s = sensorptr[i][j];

            cout<<"Sensor_"<<s.id;
            cout<<",Temperature :"<<s.temperature;
            cout<<", Time Recorded :"<<s.timestamp;
            cout<<", Status: "<<(s.status? "Active":"Inactive")<<endl;




        }
    }

    for(int i=0;i<rows;i++){
        delete[] sensorptr[i];
    }
    delete[] sensorptr;

    return 0;
}