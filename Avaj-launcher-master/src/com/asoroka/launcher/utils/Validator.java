package com.asoroka.launcher.utils;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Validator
{
    public static boolean checkBuffer(String buffer)
    {
        Pattern p;
        Matcher m;
        String[] lines;
        int len;
        int i = 0;

        lines = buffer.split("\n");
        len = lines.length;

        if (len < 2)
        {
            return false;
        }
        else if (!isPositiveInteger(lines[0]))
        {
            return false;
        }

        p = Pattern.compile("^(Baloon|JetPlane|Helicopter)\\s\\S+\\s[0-9]{1,3}\\s[0-9]{1,3}\\s[0-9]{1,3}$");
        while (++i < len)
        {
            m = p.matcher(lines[i]);
            if (!m.matches())
                return false;
            else if (!isValidCoordinats(lines[i]))
                return false;
        }

        return true;
    }

    private static boolean isInt(String str)
    {
        Pattern p = Pattern.compile("^[0-9]+$");
        Matcher m = p.matcher(str);
        return m.matches();
       // return false;
    }

    private static boolean isPositiveInteger(String str)
    {
        if (isInt(str))
        {
            if(Float.parseFloat(str) > 0 && Float.parseFloat(str) <= Integer.MAX_VALUE)
                return true;
        }
        return false;
    }

    private static boolean isValidCoordinats(String str)
    {
        String[] temp;

        temp = str.split(" ");
       // System.out.println("CHECK " + temp[2] + " " + temp[3] + " " + temp[4]);

        if (!isPositiveInteger(temp[2]) || !isPositiveInteger(temp[3]) || !isPositiveInteger(temp[4]) )
            return false;

        return true;
    }
}
