package com.unitfactory;

import java.util.ArrayList;

import static java.lang.System.exit;

public class EquationSolver
{
    ArrayList<Term> terms;
    float a,b,c;
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";

    private static final String redForm = ANSI_CYAN + "Reduced form: " + ANSI_RESET;

    public EquationSolver(ArrayList<Term> _terms)
    {
        terms = _terms;

        float maxPow = 0;
        int i = 0;
        a = 0;
        b = 0;
        c = 0;
        for (Term term : terms)
        {
            term.findCoefficient();
            if (term.coefficient == 0)
            {
               // terms.remove(term);
            }
            else
            {
                if (term.pow == 0)
                {
                    c = term.coefficient;
                }
                else if (term.pow == 1)
                    b = term.coefficient;
                else if (term.pow == 2)
                    a = term.coefficient;
                maxPow = (maxPow < term.pow) ? term.pow : maxPow;
            }

        }
        System.out.println(ANSI_CYAN + "Polynomial degree: "+ ANSI_RESET + maxPow );
        if (maxPow > 2)
            toBigPow();
        if (a != 0 && b != 0 && c != 0)
            solveABC();
        else if (a == 0 && b != 0 && c != 0)
            solveBC();
        else if (a != 0 && b == 0 && c != 0)
            solveAC();
        else if (a == 0 && b != 0 && c == 0)
            solveB();
        else if (a != 0 && b != 0 && c == 0)
            solveAB();
        else
            infinity();
    }

    private void solveBC()
    {
        float x;
        String s = "";
        s += ((b > 0) ? "" + b: " - " + (-b)) + "x";
        s += ((c > 0) ? " + " + c: " - " + (-c)) + " = 0";
        System.out.println(redForm + s);

        x = - c / b;
        printAnswer("x: " + x);
    }

    private void solveAC()
    {
        float x1, x2;
        String s = a + "x^2";
        s += ((c > 0) ? " + " + c: " - " + (-c)) + " = 0";
        System.out.println(redForm + s);

        if ((c < 0 && a > 0)|| (a < 0 && c > 0))
        {
            x1 = mysqrt(-c / a);
            x2 = -mysqrt(-c / a);

            printAnswer("x1: " + x1 + ", x2: " + x2);
        }
        else
        {
            float imValue = mysqrt(c / a);
            printAnswer("x1: " + imValue + "i, x2: " + (-imValue) + "i");
        }
    }

    private void solveAB()
    {
        float x1, x2;
        String s = a + "x^2";
        s += ((b > 0) ? " + " + b: " - " + (-b)) + "x = 0";
        System.out.println(redForm + s);


        x1 = 0;
        x2 = - b / a;

        printAnswer("x1: " + x1 + ", x2: " + x2);
    }

    private void solveB()
    {
        String s = "";
        s += ((b > 0) ? " + " + b: " - " + (-b)) + "x = 0";
        System.out.println(redForm + s);

        printAnswer("x = 0");
    }

    private void solveABC()
    {
        float d, x1, x2, x;

        if (a < 0)
        {
            a *= -1;
            b *= -1;
            c *= -1;
        }
        String s = a + "x^2";
        s += ((b > 0) ? " + " + b: " - " + (-b)) + "x";
        s += ((c > 0) ? " + " + c: " - " + (-c)) + " = 0";
        System.out.println(redForm + s);
        d = discriminant();
        System.out.println(ANSI_CYAN + "Discriminant: "+ ANSI_RESET  + d);


        if (d > 0f)
        {
            x1 = (-b + mysqrt(d)) / (2 * a);
            x2 = (-b - mysqrt(d)) / (2 * a);

           // System.out.println("x1: " + x1 + ", x2: " + x2);
            printAnswer("x1: " + x1 + ", x2: " + x2);
        }
        else if (d == 0)
        {
            x = -b / (2 * a);
           // System.out.println("x: " + x);
            printAnswer("x: " + x);
        }
        else
        {
            float imValue = mysqrt(-d) / (2 * a);
            float reValue = -b / (2 * a);
            imValue = abs(imValue);
           // System.out.println(ANSI_GREEN + "x1: " + reValue  + " + " + imValue + "i, x2: "  + reValue  + " - " + imValue + "i" + ANSI_RESET);
            printAnswer("x1: " + reValue  + " + " + imValue + "i, x2: "  + reValue  + " - " + imValue + "i");
        }

    }

    private void infinity()
    {
        if (c != 0)
        {
            System.out.println(redForm + "0 * x + " + c + " = 0");
            printAnswer("empty set. Empty like my soul.");
        }
        else
        {
            System.out.println(redForm + "0 * x + = 0");
            printAnswer("All real number are solution");
        }
    }

    private void toBigPow()
    {
        System.out.println(ANSI_YELLOW + "The polynomial degree is stricly greater than 2, I can't solve." + ANSI_RESET);
        exit(0);
    }

    private float discriminant()
    {
        return (b * b - 4 * a * c);
    }

    private float abs(float a)
    {
        return ((a < 0) ? -a : a);
    }

    private float mysqrt(float a)
    {
        float epsilon = 0.0001f;
        float guess = a / 2;
        while (abs(guess * guess - a) > epsilon)
        {
            float r = a / guess;
            guess = (guess + r) / 2;
        }
        return guess;
    }

    private void printAnswer(String str)
    {
        System.out.println(ANSI_CYAN + "The solution is: "+ ANSI_RESET  + ANSI_GREEN + str + ANSI_RESET);
    }

}
