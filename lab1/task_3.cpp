
#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <cstdlib>
#include "string"
#include "fstream"



void OUT (std::string file, int n, long double t){
    std::ofstream out(file, std::ios::app);
    if (out.is_open())
    {
        out << n << ";" << t <<std::endl;
    }
    out.close();
}

int srch_A(int arr[], int size, int el){
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == el){
            tmp = arr[0];
            arr[0] = arr[i];
            arr[i] = tmp;
            return i;
        }
    }
    return -1;
}

int srch(int arr[], int size, int el){
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == el){
            return i;
        }
    }
    return -1;
}

int srch_B(int arr[], int size, int el){
    int tmp = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == el){
            if (i>0) {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
            }
            return i;
        }
    }
    return -1;
}

int srch_C(int arr[], int size, int el){
    int ind[size];
    for (int i = 0; i < size; ++i){
        ind[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        if (arr[i] == el){
            int tmp = 0;
            ++ind[i];
            if (i>0 and ind[i]>ind[i-1]) {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
            }
            return i;
        }
    }
    return -1;
}




int main ( ) {
int amnt = 51;
    long long lin_time[amnt];
    long long bin_time[amnt];
    for (int i = 0; i<amnt; ++i){
        lin_time[i]=0;
        bin_time[i]=0;
    }
    int alue[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000,
                    90000,95000, 100000, 105000, 110000, 115000, 120000, 125000, 130000, 135000, 140000, 145000, 150000, 155000, 160000, 165000,
                    170000, 175000, 180000, 185000, 190000, 195000, 200000, 205000, 210000, 215000, 220000, 225000, 230000, 235000,
                    240000, 245000, 250000, 255000, 260000, 265000, 270000, 275000, 280000, 285000, 290000, 295000, 300000, 305000, 310000,
                    315000, 320000, 325000, 330000, 335000, 340000, 345000, 350000, 355000, 360000, 365000, 370000, 375000, 380000, 385000,
                    390000, 395000, 400000, 405000, 410000, 415000, 420000, 425000, 430000, 435000, 440000, 445000, 450000, 455000, 460000,
                    465000, 470000, 475000, 480000, 485000, 490000, 495000,500000};
    int balue[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000,
                   90000,95000, 100000, 105000, 110000, 115000, 120000, 125000, 130000, 135000, 140000, 145000, 150000, 155000, 160000, 165000,
                   170000, 175000, 180000, 185000, 190000, 195000, 200000, 205000, 210000, 215000, 220000, 225000, 230000, 235000,
                   240000, 245000, 250000, 255000};
    int calue[] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000,
                   90000,95000, 100000, 105000, 110000, 115000, 120000, 125000, 130000, 135000, 140000, 145000, 150000, 155000, 160000, 165000,
                   170000};
    int j=0;
int value[1000];
    for (int i = 0; i<1000; ++i)
        value[i]=1000*i;
        std::cout<<value[i]<<", ";
    }

    srand(time(nullptr));
    for (int rate : calue) {
        int ravn_arr[rate];
        int not_ravn_arr[rate];
        for (int i = 0; i < rate; ++i) {
            ravn_arr[i] = i;
            if (i%3 ==0){
                not_ravn_arr[i] = 1;
            }
            else{
                not_ravn_arr[i]=i;
            }
        }
        int el = 0;

        int test_1 = ravn_arr[rand()%rate];
        int test_2 = ravn_arr[rand()%rate];
        int test_3 = ravn_arr[rand()%rate];
        int test_4 = ravn_arr[rand()%rate];
        int test_5 = ravn_arr[rand()%rate];
        int test_6 = ravn_arr[rand()%rate];
        int test_ravn_arr[]={test_1,test_2,test_3,test_4,test_1,test_2,test_3,test_5,test_1,test_6};

        int not_test_1 = 1;
        int not_test_2 = 1;
        int not_test_3 = not_ravn_arr[rand()%rate];
        int not_test_4 = not_ravn_arr[rand()%rate];
        int not_test_5 = not_ravn_arr[rand()%rate];
        int not_test_6 = not_ravn_arr[rand()%rate];
        int not_test_ravn_arr[]={not_test_1,not_test_2,not_test_3,not_test_4,not_test_1,not_test_2,not_test_3,not_test_5,not_test_1,not_test_6};


        auto begin = std::chrono::steady_clock::now();
        for (long long i = 0; i <= 10000; ++i) {
            for (int g : test_ravn_arr){
                el = g;
                srch(ravn_arr, rate, el);
            }
            for (int g = 0; g < 3; ++g){
                el = rand()%rate;
                srch(ravn_arr, rate, el);
            }

        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        lin_time[j]=time_span.count();

        std::cout << "\n";
        std::cout << "lin " << time_span.count() << std::endl;
        std::cout << rate << std::endl;
        ++j;
        OUT("data.txt", rate, time_span.count());
    }
    for (long long i : lin_time){
        std :: cout <<i <<", " ;
    }
    std :: cout <<"\n";

    for (long long i : bin_time){
        std :: cout <<i <<", " ;
    }



    std :: cout <<"\n";
    return 0;
}
