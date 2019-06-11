package com.asoroka.launcher;

import com.asoroka.launcher.utils.OutputWriter;

public class Helicopter extends Aircraft implements Flyable 
{
	private WeatherTower weatherTower;

	Helicopter(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public void updateConditions()
	{
		reactToChange(weatherTower.getWeather(this.coordinates));
	}

	public String getData()
	{
		return ("Helicopter " + name + " (" + id + ")");
	}

	@Override
	protected void sunWeather()
	{
		String msg = getSongLine() + "~";
		int h = coordinates.getHeight() + 2;
		h = (h > 100) ? 100 : h;
		coordinates = new Coordinates(coordinates.getLongitude() + 10, coordinates.getLatitude(), h);
		OutputWriter.Instance.addLine("Helicopter#" + name + "(" + id + ") : "+ msg );
	}
	@Override
	protected void showWeather()
	{
		String msg = "s n o w";
		int h = coordinates.getHeight() - 12;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), h);
		if (h <= 0)
		{
			coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), 0);
			landing();
			return;
		}
		OutputWriter.Instance.addLine("Helicopter#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void rainWeather()
	{
		String msg = "r a i n";
		coordinates = new Coordinates(coordinates.getLongitude() + 5, coordinates.getLatitude(), coordinates.getHeight());
		OutputWriter.Instance.addLine("Helicopter#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void fogWeather()
	{
		String msg = "f o g";
		coordinates = new Coordinates(coordinates.getLongitude() + 1, coordinates.getLatitude(), coordinates.getHeight());
		OutputWriter.Instance.addLine("Helicopter#" + name + "(" + id + ") : " + msg + coordinates.toString());
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