package com.unitfactory;

import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Parser
{
    private ArrayList<Term> terms;
    private ArrayList<Float> pows;

    public Parser(String equation)
    {
        String[] left0right1;

        terms = new ArrayList<Term>();
        pows = new ArrayList<Float>();
        left0right1 = equation.split("=");
        if (left0right1.length  == 2)
        {
            parsePart(left0right1[0], ExpressionElement.PartOfExpression.LEFT);
            parsePart(left0right1[1], ExpressionElement.PartOfExpression.RIGHT);
        }
        else
            parsePart(left0right1[0], ExpressionElement.PartOfExpression.LEFT);
        // System.out.println(left0right1.length);


    }

    private void parsePart(String equation, ExpressionElement.PartOfExpression leftORright)
    {
        Pattern p;
        Matcher m;
        String regex;
        ExpressionElement e;

        regex = "([+\\-]\\s?)?([0-9]*([.,])?[0-9]*)\\s?\\*?\\s?([Xx])(\\^)?[0-9]*";
        p = Pattern.compile(regex);
        m = p.matcher(equation);
        while (m.find())
        {
          //  System.out.println("__________\n" + m.group() + ":");
            e = new ExpressionElement(m.group(), leftORright);
            addToTerms(e);
        }

        equation = equation.replaceAll(regex, "");
        regex = "([+\\-]\\s?)?[0-9]+([.,])?[0-9]*";
        p = Pattern.compile(regex);
        m = p.matcher(equation);
        while (m.find())
        {
          //  System.out.println("__________\n" + m.group() + ":");
            e = new ExpressionElement(m.group(), leftORright);
            addToTerms(e);
        }
    }

    private void addToTerms(ExpressionElement e)
    {
        if (pows.contains(e.getPow()))
        {
            terms.get(pows.indexOf(e.getPow())).add(e);
        }
        else
        {
            ArrayList<ExpressionElement> arrayList = new ArrayList<ExpressionElement>();
            arrayList.add(e);
            Term term = new Term(e.getPow(), arrayList);
            terms.add(term);
            pows.add(e.getPow());
        }
    }

    public ArrayList<Term> getTerms() {
        return terms;
    }
}
