+/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author danielleHughes
 */
public class FunWithShapes extends ShapeHandler {
    
 public FunWithShapes() throws ShapeException
 {
     super();
     
 }
    public void convertDescriptionsToShapes()
    {
       for(int i =0; i<shapeDescriptions.size(); i++)
       {
           if(shapeDescriptions.get(i).getShapeType()
                   .equals(ShapeDescription.ShapeTypes.CIRCLE))
           {
               
               Circle a = new Circle(shapeDescriptions.get(i));
               shapes.add(a);
           }
            if(shapeDescriptions.get(i).getShapeType()
                    .equals(ShapeDescription.ShapeTypes.SQUARE))
           {
               Square b = new Square(shapeDescriptions.get(i));
               shapes.add(b);
           }
             if(shapeDescriptions.get(i).getShapeType()
                     .equals(ShapeDescription.ShapeTypes.RECTANGLE))
           {
               Rectangle c = new Rectangle(shapeDescriptions.get(i));
               shapes.add(c);
           }
              if(shapeDescriptions.get(i).getShapeType()
                      .equals(ShapeDescription.ShapeTypes.TRIANGLE))
           {
               Triangle d = new Triangle(shapeDescriptions.get(i));
               shapes.add(d);
           }
       }
       
      
    }
    
    public double sumOverAreas()
    {
      double sumOfA = 0.0;
       
       for(int i =0; i<shapes.size(); i++)
       {
           sumOfA = sumOfA + shapes.get(i).getArea();
       }
       
       return sumOfA;
    }
    
    public double sumOverPerimeters()
    {
       double sumOfP = 0.0;
       
       for(int i =0; i<shapes.size(); i++)
       {

           sumOfP = sumOfP + shapes.get(i).getPerimeter();
       }
       
       return sumOfP;
    }
    
    
    public static void main(String[] args) throws Exception
    {
        
        FunWithShapes obj = new FunWithShapes();
        System.out.println(obj.sumOverAreas());
        System.out.println(obj.sumOverPerimeters());
       
        
    }
    
}