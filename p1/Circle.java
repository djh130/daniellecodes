+/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author danielleHughes
 */
public class Circle extends Shape
{
    private double area;
    private double perim;
    private double radius;
    private double pi = 3.14;
    
    public Circle(ShapeDescription a)
    {
       super(a);
       radius = a.getDoubles().get(0);
    }
    
    public double getArea()
    {
        area = pi*Math.pow(radius, 2);
        return area;
    }
    
    public double getPerimeter()
    {
        perim = 2*pi*radius;
        return perim;
    }
    
    
    
   
}