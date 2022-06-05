#include "graph.h"
#include <fstream>
#include <iostream>
#include <string>

void Graph::LoadMatrix(std::string &filename){
    std::ifstream file(filename);
    if(file.is_open()){
        file>>n;
        vertex=new int*[n];
        for(int i=0; i<n; i++)
            vertex[i]=new int[n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                file>>vertex[i][j];
    }
    file.close();
}

void Graph::PrintMatrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            std::cout<<vertex[i][j]<<" ";
        std::cout<<"\n";
    }
}

int Graph::GetSize(){
    return n;
}

void Graph::PrintShortestPathWeight(int s){
    int *result=new int[n];
    bool *contact=new bool[n];
    result=vertex[s];
    contact[s]=1;
    for(int i=0; i<n-2; i++){
        int min=999, temp;
        for(int j=0; j<n; j++)
            if(!contact[j]&&result[j]<min){
                min=result[j];
                temp=j;
            }
        contact[temp]=1;
        for(int k=0; k<n; k++)
            if(result[k]>(result[temp]+vertex[temp][k]))
                result[k]=(result[temp]+vertex[temp][k]);
    }
    for(int i=0; i<n; i++)
        std::cout<<result[i]<<"\n";
}