package com.asoroka.launcher;

public class Aircraft
{
	protected long id;
	protected String name;
	protected Coordinates coordinates;
	private static long idCounter = 0;

	protected static int lineOfSong = -1;
	private static String[] sunnyBoneyM = new String[]
			{
					"Sunny, yesterday my life was filled with rain",
					"Sunny, you smiled at me and really eased the pain",
					"The dark days are gone, and the bright days are here,",
					"My Sunny one shines so sincere",
					"Sunny one so true, I love you"
			};

	protected Aircraft (String name, Coordinates coordinates)
	{
		this.name = name;
		this.coordinates = coordinates;
		this.id = this.nextId();
		//System.out.println(this.id);
	}

	private static long nextId()
	{
		return (idCounter++);
	}

	protected void reactToChange(String weather)
	{
		switch (weather)
		{
			case "SUN":
			{
				sunWeather();
				break;
			}
			case "RAIN":
			{
				rainWeather();
				break;
			}
			case "FOG":
			{
				fogWeather();
				break;
			}
			case "SNOW":
			{
				showWeather();
				break;
			}
		}
	}

	protected static String getSongLine()
	{
		lineOfSong++;
		if (lineOfSong > 4)
			lineOfSong = 0;
		return sunnyBoneyM[lineOfSong];
	}

	void sunWeather(){}
	void rainWeather(){}
	void fogWeather(){}
	void showWeather(){}
}
