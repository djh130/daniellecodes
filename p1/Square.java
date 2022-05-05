+/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author danielleHughes
 */
public class Square extends Shape {
    private double area;
    private double perim;
    private double sideLength;
    
    public Square(ShapeDescription a)
    {
       super(a);
       sideLength = a.getDoubles().get(0);
    }
    
    public double getArea()
    {
        area = Math.pow(sideLength,2);
        return area;
    }
    
    public double getPerimeter()
    {
        perim = 4*sideLength;
        return perim;
    }
    
}