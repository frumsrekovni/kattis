#include<iostream>
#include<vector>

using namespace std;

// First input is the amount of corners the polygon has. 3<=N<=25
// Second input is the amount of lines drawn. Always even. 2<=M<=50
// Then N amount of 2 integers are input. Representing what corner the lines start and end on.
// 



int main(){
    int amount_of_vertices = 0;
    int amount_of_lines = 0;
    float input = 0.0;
    vector<pair<float,float>> vertex_coordinates;
    vector<pair<pair<float,float>,pair<float,float>>> line_endpoints;
    cin >> amount_of_vertices;
    cin >> amount_of_lines;
    
    for (int i = 0; i < amount_of_vertices; i++)
    {
        float x,y;
        cin >> x >> y;
        vertex_coordinates.push_back(pair<float,float>(x,y));
    }
    for (int i = 0; i < amount_of_lines; i++)
    {
        float x,y,a,b;
        cin >> x >> y >> a >> b;
        line_endpoints.push_back(pair<pair<float,float>,pair<float,float>>(pair<float,float>(x,y), pair<float,float>(a,b)));
    }
    
    


    return 0;
}