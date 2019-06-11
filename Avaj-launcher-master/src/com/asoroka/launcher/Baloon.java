package com.asoroka.launcher;

import com.asoroka.launcher.utils.OutputWriter;

public class Baloon extends Aircraft implements Flyable
{
	private WeatherTower weatherTower;

	Baloon(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	 public void updateConditions()
	{
		reactToChange(weatherTower.getWeather(this.coordinates));
	}
	public String getData()
	{
		return ("Baloon " + name + " (" + id + ")");
	}

	@Override
	protected void sunWeather()
	{
		String msg = getSongLine() + "~";
		int h = coordinates.getHeight() + 4;
		h = (h > 100) ? 100 : h;
		coordinates = new Coordinates(coordinates.getLongitude() + 2, coordinates.getLatitude(), h);
		OutputWriter.Instance.addLine("Baloon#" + name + "(" + id + ") : " + msg);
	}
	@Override
	protected void showWeather()
	{
		String msg = "snow";
		int h = coordinates.getHeight() - 15;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), h);

		if (h <= 0)
		{
			coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), 0);
			landing();
			return;
		}
		OutputWriter.Instance.addLine("Baloon#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void rainWeather()
	{
		String msg = "rain";
		int h = coordinates.getHeight() - 5;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), h);
		if (h <= 0)
		{
			coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), 0);
			landing();
			return;
		}

		OutputWriter.Instance.addLine("Baloon#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void fogWeather()
	{
		String msg = "fog";
		int h = coordinates.getHeight() - 3;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), h);

		if (h <= 0)
		{
			coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), 0);
			landing();
			return;
		}
		OutputWriter.Instance.addLine("Baloon#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}

	private void landing()
	{
		this.weatherTower.unregister(this);
	}

	public void registerTower(WeatherTower weatherTower)
	{
		this.weatherTower = weatherTower;
		this.weatherTower.register(this);
	}


}