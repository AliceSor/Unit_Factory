package com.asoroka.launcher.utils;

public class Parser
{
    public String name;
    public String type;

    public int longitude;
    public int latitude;
    public int height;
    public int numberOfSimulations;

    public boolean endOfFile;

    private String[] lines;

    private int currentLine;
    private int numberOfLines;

    public Parser(String buffer)
    {
        endOfFile = false;
        currentLine = 0;
        lines = buffer.split("\n");
        numberOfLines = lines.length;
        numberOfSimulations = Integer.parseInt(lines[0]);
        currentLine = 1;
        nextLine();
    }

    public void nextLine()
    {
        if (currentLine < numberOfLines)
        {
            String[] temp = lines[currentLine].split(" ");

            type = temp[0];
            name = temp[1];

            longitude = Integer.parseInt(temp[2]);
            latitude = Integer.parseInt(temp[3]);
            height = Integer.parseInt(temp[4]);
            if (height > 100)
                height = 100;

            currentLine++;
            if (currentLine + 1 == numberOfLines)
                endOfFile = true;
        }
    }
}