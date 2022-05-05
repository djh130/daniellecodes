+/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author danielleHughes
 */
public class Triangle extends Shape
{
    private double area;
    private double perim;
    private double sideA;
    private double sideB;
    private double sideC;
    private double semiP;
    
    public Triangle(ShapeDescription a)
    {
       super(a);
       sideA = a.getDoubles().get(0);
       sideB = a.getDoubles().get(1);
       sideC = a.getDoubles().get(2);
       
       semiP= (sideA+sideB+sideC)/2;
       
    }
    
    public double getArea()
    {
        area = Math.sqrt(semiP*(semiP-sideA)*(semiP-sideB)*(semiP-sideC));
        return area;
    }
    
    public double getPerimeter()
    {
        perim = sideA +sideB + sideC;
        return perim;
    }
}