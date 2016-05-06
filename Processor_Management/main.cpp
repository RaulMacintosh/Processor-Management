#include <QCoreApplication>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T>
string NumberToString(T number){
    ostringstream temp;
    temp << number;
    return temp.str();
}

void function1(vector<float> elements, int creationTime, int *totalTime){
    time_t functionTime1, functionTime2;

    functionTime1 = time(NULL);
        float summatory = 0;
        for(int i = 0; i < elements.size(); i++){
            summatory += elements.at(i);
        }
    functionTime2 = time(NULL);

    int functionTime = functionTime2 - functionTime1;
    *totalTime = functionTime + creationTime;
}

void function2(vector<float> elements, int creationTime, int *totalTime){
    time_t functionTime1, functionTime2;

    functionTime1 = time(NULL);
        float summatory = 0;
        for(int i = 0; i < elements.size(); i++){
            summatory += sin(elements.at(i));
        }
    functionTime2 = time(NULL);

    int functionTime = functionTime2 - functionTime1;
    *totalTime = functionTime + creationTime;
}

void function3(vector<float> elements, int creationTime, int *totalTime){
    time_t functionTime1, functionTime2;

    functionTime1 = time(NULL);
        float summatory = 0;
        for(int i = 0; i < elements.size(); i++){
            summatory += log(elements.at(i));
        }
    functionTime2 = time(NULL);

    int functionTime = functionTime2 - functionTime1;
    *totalTime = functionTime + creationTime;
}

int main(){
    time_t creationTime1, creationTime2;

    creationTime1 = time(NULL);
        vector<float> elements;
        srand(time(0));

        for(int i = 0; i < 100000000; i++){
            float randVal = (rand()%10)/10.0;
            if(rand()%2 == 0){
                randVal *= -1;
            }

            elements.push_back(randVal);
        }
    creationTime2 = time(NULL);

    int creationTime = creationTime2 - creationTime1;

    int totalTimeF1;
    int totalTimeF2;
    int totalTimeF3;

    cpu_set_t cpuset;

    thread t1(function1, elements, creationTime, &totalTimeF1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t1.native_handle(), sizeof(cpu_set_t), &cpuset);

    t1.join();

    thread t2(function2, elements, creationTime, &totalTimeF2);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t2.join();

    thread t3(function3, elements, creationTime, &totalTimeF3);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t3.native_handle(), sizeof(cpu_set_t), &cpuset);

    t3.join();

    //gravar em arquivo .dat

    int totalTimeF1_C1;
    int totalTimeF1_C2;

    int totalTimeF2_C1;
    int totalTimeF2_C2;

    int totalTimeF3_C1;
    int totalTimeF3_C2;

    thread t1_c1(function1, elements, creationTime, &totalTimeF1_C1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t1_c1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t1_c2(function1, elements, creationTime, &totalTimeF1_C2);
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(t1_c2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t1_c1.join();
    t1_c2.join();

    thread t2_c1(function2, elements, creationTime, &totalTimeF2_C1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t2_c1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t2_c2(function2, elements, creationTime, &totalTimeF2_C2);
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(t2_c2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t2_c1.join();
    t2_c2.join();

    thread t3_c1(function3, elements, creationTime, &totalTimeF3_C1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t3_c1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t3_c2(function3, elements, creationTime, &totalTimeF3_C2);
    CPU_ZERO(&cpuset);
    CPU_SET(1, &cpuset);
    pthread_setaffinity_np(t3_c2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t3_c1.join();
    t3_c2.join();

    //gravar em arquivo .dat

    int totalTimeF1_SameCore_1;
    int totalTimeF1_SameCore_2;

    int totalTimeF2_SameCore_1;
    int totalTimeF2_SameCore_2;

    int totalTimeF3_SameCore_1;
    int totalTimeF3_SameCore_2;

    thread t1_SameCore_1(function1, elements, creationTime, &totalTimeF1_SameCore_1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t1_SameCore_1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t1_SameCore_2(function1, elements, creationTime, &totalTimeF1_SameCore_2);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t1_SameCore_2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t1_SameCore_1.join();
    t1_SameCore_2.join();

    thread t2_SameCore_1(function2, elements, creationTime, &totalTimeF2_SameCore_1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t2_SameCore_1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t2_SameCore_2(function2, elements, creationTime, &totalTimeF2_SameCore_2);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t2_SameCore_2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t2_SameCore_1.join();
    t2_SameCore_2.join();

    thread t3_SameCore_1(function3, elements, creationTime, &totalTimeF3_SameCore_1);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t3_SameCore_1.native_handle(), sizeof(cpu_set_t), &cpuset);

    thread t3_SameCore_2(function3, elements, creationTime, &totalTimeF3_SameCore_2);
    CPU_ZERO(&cpuset);
    CPU_SET(0, &cpuset);
    pthread_setaffinity_np(t3_SameCore_2.native_handle(), sizeof(cpu_set_t), &cpuset);

    t3_SameCore_1.join();
    t3_SameCore_2.join();

    ofstream file;
    file.open("Function1.dat");
        file << NumberToString(1) + "  ";
        file << NumberToString(totalTimeF1) + "\n";
        file << NumberToString(2) + "  ";
        file << NumberToString((totalTimeF1_C1 + totalTimeF1_C2)) + "\n";
        file << NumberToString(3) + "  ";
        file << NumberToString((totalTimeF1_SameCore_1 + totalTimeF1_SameCore_2)) + "\n";
    file.close();

    file.open("Function2.dat");
        file << NumberToString(1) + "  ";
        file << NumberToString(totalTimeF2) + "\n";
        file << NumberToString(2) + "  ";
        file << NumberToString((totalTimeF2_C1 + totalTimeF2_C2)) + "\n";
        file << NumberToString(3) + "  ";
        file << NumberToString((totalTimeF2_SameCore_1 + totalTimeF2_SameCore_2)) + "\n";
    file.close();

    file.open("Function3.dat");
        file << NumberToString(1) + "  ";
        file << NumberToString(totalTimeF3) + "\n";
        file << NumberToString(2) + "  ";
        file << NumberToString((totalTimeF3_C1 + totalTimeF3_C2)) + "\n";
        file << NumberToString(3) + "  ";
        file << NumberToString((totalTimeF3_SameCore_1 + totalTimeF3_SameCore_2)) + "\n";
    file.close();
}
