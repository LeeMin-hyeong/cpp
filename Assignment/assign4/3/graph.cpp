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

void Graph::PrintShortestPath(int s){
    int *result=new int[n];
    bool *contact=new bool[n];

    //초기 경로 설정
    int **path=new int*[n];
    for(int i=0; i<n; i++)
        path[i]=new int[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            path[i][j]=-1;
    }
    for(int i=0; i<n; i++)
        path[i][0]=s;
    for(int i=0; i<n; i++){
        path[i][1]=(vertex[0][i]==999?-1:i);
    }
    

    result=vertex[s];
    contact[s]=1;

    for(int i=2; i<n; i++){
        int min=999, temp;
        for(int j=0; j<n; j++){
            if(!contact[j]&&result[j]<min){
                min=result[j];
                temp=j;
            }
        }
        contact[temp]=1;
        for(int k=0; k<n; k++){
            if(result[k]>(result[temp]+vertex[temp][k])){
                result[k]=(result[temp]+vertex[temp][k]);
                if(k==s) continue;
                for(int l=0; l<n; l++)
                    path[k][l]=path[temp][l]; //result[temp] 경로 불러오기
                for(int l=0; l<n; l++){
                    if(path[k][l]==-1){
                        path[k][l]=k;
                        break;
                    }
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        if(i==s) continue;
        for(int j=0; j<n; j++){
            if(path[i][j]==-1) break;
            std::cout<<path[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}