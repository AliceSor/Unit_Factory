package com.asoroka.launcher;

import java.io.*;
import com.asoroka.launcher.utils.OutputWriter;
import com.asoroka.launcher.utils.Parser;
import com.asoroka.launcher.utils.Validator;
import java.io.IOException;

import static java.lang.System.exit;

public class Launcher
{
	public static void main(String[] args)
	{
		String fileContent;
		WeatherTower weatherTower;
		Flyable flyable;
		Parser parser;


		if (args.length != 1)
		{
			System.out.println("Pass file name as argument");
			return;
		}
		try
		{
			fileContent = getFileContent(args[0]);
			OutputWriter outputWriter = new OutputWriter("simulation.txt");


			if (!Validator.checkBuffer(fileContent))
			{
				System.out.println("Not Valid\n");
				return;
			}

			parser = new Parser(fileContent);
			weatherTower = new WeatherTower(parser.numberOfSimulations);
			while (!parser.endOfFile)
			{
				flyable = AircraftFactory.newAircraft(parser.type, parser.name, parser.longitude, parser.latitude, parser.height);
				flyable.registerTower(weatherTower);

				parser.nextLine();
			}

			weatherTower.runSimulation();

			outputWriter.close();
		}
		catch (IOException e) {
			System.out.println("FileNotFoundException");
			exit(-1);
		}
	}

	private static String getFileContent(String fileName) throws IOException
	{
		File file = new File(fileName);
		FileReader fileReader = new FileReader(file);
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		StringBuilder stringBuffer = new StringBuilder();
		String line;

		while ((line = bufferedReader.readLine()) != null)
		{
			stringBuffer.append(line);
			stringBuffer.append("\n");

		}
		fileReader.close();
		return (stringBuffer.toString());
	}
}