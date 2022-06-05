#include <string>

class Graph{
    private:
        int n;
        int **vertex;
    public:
        void LoadMatrix(std::string &filename);
        void PrintMatrix();
        int GetSize();
        void PrintShortestPathWeight(int s);
        void PrintShortestPath(int s);
};