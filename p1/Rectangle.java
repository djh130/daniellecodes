+/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author danielleHughes
 */
public class Rectangle extends Shape{
    
    private double area;
    private double perim;
    private double height;
    private double width;
    
    public Rectangle (ShapeDescription a)
    {
       super(a);
       height = a.getDoubles().get(0);
       width  = a.getDoubles().get(1);
    }
    
    public double getArea()
    {
        area = height*width;
        return area;
    }
    
    public double getPerimeter()
    {
        perim = 2*height + 2*width;
        return perim;
    }
    
}