package com.asoroka.launcher;

class WeatherTower extends Tower
{
	private WeatherProvider weatherProvider;
	private int numberOfSimulations;

	 WeatherTower(int _numberOfSimulations)
	{
		numberOfSimulations = _numberOfSimulations;
	}

	public String getWeather(Coordinates coordinates)
	{
		if (weatherProvider == null)
			weatherProvider = WeatherProvider.getProvider();
		return (weatherProvider.getCurrentWeather(coordinates));
	}

	void changeWeather()
	{
		this.conditionsChanged();
	}

	void runSimulation()
	{
		while (numberOfSimulations-- > 0)
		{
			changeWeather();
		}
	}

}