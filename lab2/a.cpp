#include <iostream>

using namespace std;

class SkaparVector{
    private:
        int* data;
        int size;
        int capacity;

public:
    SkaparVector(): data(nullptr), size(0), capacity(0) {}

    void push_back(int value)
    {
        if(size >= capacity){
            if(capacity == 0){
                capacity = 1;
            } else {
                capacity *=2;
            }

            int* newData = new int[capacity];
            for(int i = 0; i < size; i++){
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
        }

        data[size] = value;
        size++;
    }

    int at(int index) {
        return data[index];
    }

    int getsize(){
        return size;
    }


    ~SkaparVector(){
        if(data){
            delete[] data;
        }
    }
    
};

int main(){
    SkaparVector v;
    
    int n,k;
    cin >> n;

    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cin >> k;

    int nindex = 0;
    int diff = abs(k - v.at(nindex)); 
    for(int i = 0; i<v.getsize(); i++){
        int current_difka = abs(k - v.at(i)); 
        if(current_difka < diff ){
            nindex = i;
            diff = current_difka;
        }
    }
    cout << nindex ;





}