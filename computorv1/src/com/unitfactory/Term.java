package com.unitfactory;

import java.util.ArrayList;

public class Term
{
    float pow;
    float coefficient;
    ArrayList<ExpressionElement> parts;

    public Term(float _pow, ArrayList<ExpressionElement> _parts)
    {
        coefficient = 0;
        pow = _pow;
        parts = _parts;
      //  findCoefficient();
    }

    public void findCoefficient()
    {
        for (ExpressionElement el : parts)
        {
            coefficient += el.getCoefficient();
        }
    }

    public void add(ExpressionElement e)
    {
        parts.add(e);
    }
}
