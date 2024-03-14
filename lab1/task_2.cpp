#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

std::pair<int, int> smart_srch(int arr[], int size, int el){
    int i = 0;
    int j = size-1;
    while(arr[i]+arr[j]!=el and i<j){
        if (arr[i]+arr[j]>el){
            --j;
        }
        else if(arr[i]+arr[j]<el){
            ++i;
        }
    }
    if (i<j){
        return std::make_pair(i, j);
    }

    return std::make_pair(-1,-1);;
}
std::pair<int, int> full_srch(int arr[], int size, int el){

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; j++){
            //std::cout<< arr[i]<<'+'<<arr[j]<<'='<<arr[i]+arr[j]<<std::endl;
            if (arr[i] + arr[j] == el){
                return std::make_pair(i, j);

            }
        }
    }
    return std::make_pair(-1,-1);;
}

int main ( ) {
    int el = -1;
int arr[] = {1,2,3,4,5,6,7,8,9};
    std::cout<<smart_srch(arr,9,el).first<<' '<<full_srch(arr,9,el).second;
    smart_srch(arr,9,el);


    int amount = 46;
    long long full_time[amount];
    long long smart_time[amount];
    for (int i = 0; i<amount; ++i){
        full_time[i]=0;
        smart_time[i]=0;
    }
    int value[] = {200,400,800,1600,3000,5000,7000,10000,15000,20000,
                   25000,30000,35000,40000,45000,50000,55000,60000,65000,
                   70000,75000,80000,85000,90000,95000,100000,105000, 110000, 115000, 120000, 125000, 130000, 135000, 140000, 145000, 150000, 155000, 160000, 165000,
                   170000, 175000, 180000, 185000, 190000, 195000, 200000};
    int big_value[]= {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000, 45000, 50000, 55000, 60000, 65000, 70000, 75000, 80000, 85000,
                      90000,95000, 100000, 105000, 110000, 115000, 120000, 125000, 130000, 135000, 140000, 145000, 150000, 155000, 160000, 165000,
                      170000, 175000, 180000, 185000, 190000, 195000, 200000, 205000, 210000, 215000, 220000, 225000, 230000, 235000,
                      240000, 245000, 250000, 255000, 260000, 265000, 270000, 275000, 280000, 285000, 290000, 295000, 300000, 305000, 310000,
            315000, 320000, 325000, 330000, 335000, 340000, 345000, 350000, 355000, 360000, 365000, 370000, 375000, 380000, 385000,
            390000, 395000, 400000, 405000, 410000, 415000, 420000, 425000, 430000, 435000, 440000, 445000, 450000, 455000, 460000,
            465000, 470000, 475000, 480000, 485000, 490000, 495000,500000};
for (int i =1; i<100;++i){
        big_value[i] = 5000*i;
        std::cout<<big_value[i]<<", ";
    }

    int j=0;
    for (int rate : value) {
        int array[rate];
        for (int i = 0; i < rate; ++i) {
            array[i] = i;
        }


        auto begin = std::chrono::steady_clock::now();
        for (long long i = 0; i <= 10; ++i) {
            full_srch(array, rate, el);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        full_time[j]=time_span.count();


        std::cout << "\n";
        std::cout << "full " << time_span.count() << std::endl;



auto begin1 = std::chrono::steady_clock::now();
        for (long long i = 0; i <= 10000; ++i) {
            smart_srch(array, rate, el);
        }
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
                std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
        smart_time[j]=time_span1.count();
        std::cout << "smart " << time_span1.count() << std::endl;


        std::cout << rate << std::endl;
        ++j;
    }
   std::cout<<"full time: ";
    for (long long i : full_time){
        std :: cout <<i <<", " ;
    }
    std :: cout <<"\n";
std::cout<<"smart time: ";
    for (long long i : smart_time){
        std :: cout <<i <<", " ;
    }

    std :: cout <<"\n";
    return 0;

}
