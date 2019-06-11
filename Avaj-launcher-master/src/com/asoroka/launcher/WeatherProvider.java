package com.asoroka.launcher;

import java.util.Random;


public class WeatherProvider
{
	private static WeatherProvider weatherProvider;
	private String[] weather = {"RAIN", "FOG", "SUN", "SNOW"};
	private Random random;

	private WeatherProvider()
	{
		random = new Random(System.currentTimeMillis());
	}

	public static WeatherProvider getProvider()
	{
		if (weatherProvider == null)
			weatherProvider = new WeatherProvider();
		return weatherProvider;
	}

	public String getCurrentWeather(Coordinates coordinates)
	{
		int sum;
		int index;

		sum = coordinates.getHeight() * random.nextInt(11) + coordinates.getLatitude() * random.nextInt(11) + coordinates.getLongitude() * random.nextInt(11);
		index = sum% 4;
		return weather[index];
	}
}