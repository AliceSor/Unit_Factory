package com.asoroka.launcher.utils;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import static java.lang.System.exit;

public class OutputWriter
{
    public static OutputWriter Instance = null;

    private BufferedWriter writer;

    public OutputWriter(String fileName) throws IOException
    {
        writer = new BufferedWriter(new FileWriter(fileName));
        if (Instance == null)
            Instance = this;
    }

    public void addLine(String str)
    {
        try {
            writer.write(str + "\n");
        } catch (IOException e)
        {
            System.out.println(e.getMessage());
            exit(-1);
        }
    }

    protected void finalize ( )
    {
        try
        {
            close();
        }
        catch (IOException e)
        {
            System.out.println(e.getMessage());
            exit(-1);

        }

    }

    public void close() throws IOException
    {
        writer.close();
    }
}
