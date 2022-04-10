class Rectangle{
    private:
        int width, height;
    public:
        Rectangle(){
            width=0;
            height=0;
        }
        Rectangle(int w, int h){
            width=w<0?0:w;
            height=h<0?0:h;
        }
        int area();
        int perimeter();
};