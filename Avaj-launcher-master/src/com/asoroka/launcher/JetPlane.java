package com.asoroka.launcher;

import com.asoroka.launcher.utils.OutputWriter;

public class JetPlane extends Aircraft implements Flyable
{
	private WeatherTower weatherTower;

	JetPlane(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public void updateConditions()
	{
		reactToChange(weatherTower.getWeather(this.coordinates));
	}

	public String getData()
	{
		return ("JetPlane " + name + " (" + id + ")");
	}

	@Override
	protected void sunWeather()
	{
		String msg = getSongLine() + "~";
		int h = coordinates.getHeight() + 2;
		h = (h > 100) ? 100 : h;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude() + 10, h);
		OutputWriter.Instance.addLine("JetPlane#" + name + "(" + id + ") : " + msg);
	}
	@Override
	protected void showWeather()
	{
		String msg = "s_n_o_w";
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude() + 5, coordinates.getHeight());
		OutputWriter.Instance.addLine("JetPlane#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void rainWeather()
	{
		String msg = "r_a_i_n";
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude() + 1, coordinates.getHeight());
		OutputWriter.Instance.addLine("JetPlane#" + name + "(" + id + ") : " + msg + coordinates.toString());
	}
	@Override
	protected void fogWeather()
	{
		String msg = "f_o_g";
		int h = coordinates.getHeight() - 7;
		coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), h);
		if (h <= 0)
		{
			coordinates = new Coordinates(coordinates.getLongitude(), coordinates.getLatitude(), 0);
			landing();
			return;
		}
		OutputWriter.Instance.addLine("JetPlane#" + name + "(" + id + ") : " + msg + coordinates.toString());
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