
#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

void InsertSort(int arr[], int n) {
    int i, j, key = 0, temp = 0;
    for (i = 0; i < n - 1; i++) {
        key = i + 1;
        temp = arr[key];
        for (j = i + 1; j > 0; j--) {
            if (temp < arr[j - 1]) {
                arr[j] = arr[j - 1];
                key = j - 1;
            }
        }
        arr[key] = temp;
    }

}


int bin_srch(int arr[], int size, int el){
    bool flag = false;
    int left = 0;
    int right = size-1;
    int mid = (left+right)/2;
    while ((left <= right) && !flag) {
        mid = (left + right) / 2;
        if (arr[mid] == el) {
            flag = true;
        }
        if (arr[mid] > el) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (flag){
        return mid;
    }
    return -1;
}



int srch(int arr[], int size, int el){

    for (int i = 0; i < size; ++i) {
        if (arr[i] == el){
            //err = 1;
            return i;
        }
    }
    return -1;
}
int main ( ) {
    int el = -1;
    int arr[] = {9,5,8,8,4,5,8} ;
    int size = std::end(arr)-std::begin(arr);

    for (int i = 0; i < size; ++i){
        std :: cout <<arr[i] <<" " ;
    }
    std :: cout <<"\n";

    InsertSort(arr,size);

    for (int i = 0; i < size; ++i){
        std :: cout <<arr[i] <<" " ;
    }
    std :: cout <<"\n";



    long long lin_time[29];
    long long bin_time[29];
    for (int i = 0; i<29; ++i){
        lin_time[i]=0;
        bin_time[i]=0;
    }
    int value[] = {100,200,400,800,1600,3200,5000,7000,10000,15000,20000,
                   25000,35000,45000,60000,75000,95000,115000,140000,165000,
                   195000,225000,260000,295000,335000,375000,420000,465000,500000};
    int j=0;
    for (int rate : value) {
        int array[rate];
        for (int i = 0; i < rate; ++i) {
            array[i] = i;
        }


        auto begin = std::chrono::steady_clock::now();
        for (long long i = 0; i <= 1000; ++i) {
            srch(array, rate, el);
        }
        auto end = std::chrono::steady_clock::now();
        auto time_span =
                std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        lin_time[j]=time_span.count();


        std::cout << "\n";
        std::cout << "lin " << time_span.count() << std::endl;



        auto begin1 = std::chrono::steady_clock::now();
        for (long long i = 0; i <= 100000; ++i) {
            bin_srch(array, rate, el);
        }
        auto end1 = std::chrono::steady_clock::now();
        auto time_span1 =
                std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
        bin_time[j]=time_span1.count();
        std::cout << "bin " << time_span1.count() << std::endl;
        std::cout << rate << std::endl;
        ++j;
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
