import java.util.Random;


class Shape{
    void draw(){}
    void erase(){}
}

class Circle extends Shape{
    void draw(){
        System.out.println("Circle.draw()");
    }
}

class Square extends Shape{
    void draw(){
        System.out.println("Square.draw()");
    }
}

class Triangle extends Shape{
    void draw(){
        System.out.println("Triangle.draw()");
    }
}

class RandomShape{
    private Random r=new Random();
    public Shape next(){
        switch(r.nextInt(3)){
            default:
            case 0: return new Circle();
            case 1: return new Square();
            case 2: return new Triangle();
        }
    }
}

public class Shapes {
    private static RandomShape gen=new RandomShape();
    public static void main(String[] args){
        Shape[] s= new Shape[9];
        for (int i=0; i<s.length; i++){
            s[i]=gen.next();
        }
        for (int i=0;i<s.length;i++){
            s[i].draw();
        }
    }
}