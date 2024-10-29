#include <iostream>

using namespace std;

class Vector{
    private:
        int* data;
        int size;
        int capacity;
    public:
        Vector(): data(nullptr), size(0), capacity(0){}

        void push_back(int value)
        {
            if(size >= capacity){
                if(capacity == 0){
                    capacity = 1;
                } else{
                    capacity *=2;
                }

                int* newdata = new int[capacity];
                for(int i = 0; i< size; i++){
                    newdata[i] = data[i];
                }

                delete[] data;
                data = newdata;
            }

            data[size] = value;
            size++;
        }
        
        int at(int index){
            return data[index];
        }

        int getsize(){
            return size;
        }

        ~Vector(){
            if(data){
                delete[] data;
            }
        }
};

int absdauren(int v){
    return v*((v>0) - (v<0));
}
int main(){
    Vector v;
    int n,x;
    cin >> n;


    for(int i = 0; i<n; i++){
        int x,k;
        cin >> x;
        v.push_back(x);
    }
    cin >> x;
    int diff = absdauren(x - v.at(0));
    // 2
    for(int i = 0; i<v.getsize(); i++){
        // 3
        // 1
        if(diff > abs(x - v.at(i))){
            diff = i;
        }
    }

    cout << diff;

}