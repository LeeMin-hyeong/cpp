class Polynomial
{
private:
    int n;
    int **arr;
public:
    Polynomial(){
        n=0;
    }
    void LoadPolynomial(std::string &filename);
    void PrintPolynomial();
    void add(Polynomial a, Polynomial b);
};