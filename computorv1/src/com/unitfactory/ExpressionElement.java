package com.unitfactory;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static com.unitfactory.EquationSolver.ANSI_RED;
import static com.unitfactory.EquationSolver.ANSI_RESET;
import static com.unitfactory.EquationSolver.ANSI_YELLOW;
import static java.lang.System.exit;

public class ExpressionElement
{
    public enum PartOfExpression {RIGHT, LEFT}

    private float pow;
    private float coefficient;

    public ExpressionElement(String exprStrnig, PartOfExpression partOfExpression)
    {
        Pattern p;
        Matcher m;
        String[] temp;

        if (exprStrnig.equals("x"))
        {
            pow = 1;
            coefficient = 1;
            return;
        }
        temp = exprStrnig.split("([xX])");

        if (temp.length == 2)
        {
            if ((temp[1].substring(temp[1].indexOf('^') + 1)).length() < 10)
                pow = Integer.parseInt(temp[1].substring(temp[1].indexOf('^') + 1));
            else
                tooBig();
        }

        else
            if (exprStrnig.contains("x") || exprStrnig.contains("X"))
                pow = 1;
            else
                pow = 0;
       // System.out.println("pow :" + pow);

        p = Pattern.compile("[0-9]+([.,])?[0-9]*");
        if (temp[0] == null)
            return;
        m = p.matcher(temp[0]);
        if (m.find())
        {
            coefficient = Float.parseFloat(m.group());
            if (coefficient > Float.MAX_VALUE)
                tooBig();
            else if (coefficient < -Float.MIN_VALUE)
                tooSmall();
        }
        else
            coefficient = 1;

        if (temp[0].contains("-"))
        {
            coefficient *= (-1);
        }

        if (partOfExpression == PartOfExpression.RIGHT)
        {
            coefficient *= (-1);
        }

       // System.out.println("coefficient: " + coefficient);
    }

    public float getPow()
    {
        return pow;
    }

    public float getCoefficient()
    {
        return coefficient;
    }

    void tooBig()
    {
        System.out.println(ANSI_RED + "Too big number" + ANSI_RESET);
        exit(0);

    }

    void tooSmall()
    {
        System.out.println(ANSI_RED + "Too small number" + ANSI_RESET);
        exit(0);

    }

}
