#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find(vector<vector<int> > sn, vector<int> el){
    int n = sn.size();
    int m = sn[0].size();

    vector<vector<int> > rawcoord(n, vector<int>(m));
    vector<vector<int> > colcoord(n, vector<int>(m));

    int raw = 0, col = 0;
    bool forw = true;

    for(int i = 0; i<n*m; i++){
        rawcoord[raw][col] = raw;
        colcoord[raw][col] = col;

        if(forw){
            if(col == m-1){
                raw++;
                forw = false;
            }
            else{
                col++;
            }
        }
        else{
            if(col == 0){
                raw++;
                forw = true;
            }
            else{
                col--;
            }
        }
    }
    
    for(int k = 0; k<el.size(); k++){
        bool f = false;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(sn[i][j] == el[k]){
                    cout << rawcoord[i][j] << " " << colcoord[i][j] <<  endl;
                    f = true;
                    break; 
                }
            }
            if(f) break;
        }
        if(!f){
            cout << "-1" << endl;
        }
    }
}


int main(){
    int t;
    cin >> t;

    vector<int>el(t);

    for(int i = 0; i<t; i++){
        cin >> el[i];
    }
    
    int n,m;
    cin >> n >> m;

    vector<vector<int> > sn(n, vector<int>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> sn[i][j];
        }
    }


    find(sn, el);

}