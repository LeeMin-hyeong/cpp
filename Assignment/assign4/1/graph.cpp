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
}

void Graph::PrintMatrix(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            std::cout<<vertex[i][j]<<" ";
        std::cout<<"\n";
    }
}