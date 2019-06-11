package com.unitfactory;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static com.unitfactory.EquationSolver.ANSI_RED;
import static com.unitfactory.EquationSolver.ANSI_RESET;


public class Main {

    public static void main(String[] args)
    {
        Parser parser;
        EquationSolver solver;


        if (args.length > 0 && !args[0].isEmpty())
        {
            if (args[0].contains("="))
            {
                if (validate(args[0]))
                {
                    parser = new Parser(args[0]);
                    solver = new EquationSolver(parser.getTerms());
                }
                else
                {
                    System.out.println(ANSI_RED + "Not valid input.\n" + ANSI_RESET + "Example:");
                    forExample();
                }

            }
            else
            {
                System.out.println(ANSI_RED + "Hey! where is \"=\"? You really want me to solve this equation? Give me normal one!\n" + ANSI_RESET + "For example:");
                forExample();
            }
        }
        else
        {
            System.out.println(ANSI_RED + "Give me the real equation!\n" + ANSI_RESET + "For example:");
            forExample();
        }


    }

    static private boolean validate(String str)
    {
        Pattern p;
        Matcher m;
        String regex;

        regex = "([xX\\d\\s*+\\-.,^]*)[xX0-9]+([xX\\d\\s*+\\-.,^]*)=([xX\\d\\s*+\\-.,^]*)";
        p = Pattern.compile(regex);
        m = p.matcher(str);
        return (m.matches());
    }

    static private void forExample()
    {
        System.out.println("\"x^1000 + 5x -1 = x^1000\"");
        System.out.println("\"x^2 + 3x -4 = 0\"");
        System.out.println("\"x^2 + 3x + 4 = 0\"");
        System.out.println("\"8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0\"");
        System.out.println("\"5 * X^0 + 4 * X^1 = 4 * X^0\"");
        System.out.println("\"5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0\"");
        System.out.println("\"x - x + 3 = 0\"");
        System.out.println("\"x - x = 0\"");
        System.out.println("\"5x - x - 5 = 0\"");
        System.out.println("\"5x^2- 5 = 0\"");
        System.out.println("\"5x^2+5 = 0\"");
        System.out.println("\"5x = 0\"");
        System.out.println("\"5x^2 - 3x = 0\"");
    }


}
