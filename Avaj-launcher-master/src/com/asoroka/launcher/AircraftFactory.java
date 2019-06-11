package com.asoroka.launcher;


public class AircraftFactory
{
	public static Flyable newAircraft(String type, String name, int longitude, int latitude, int height)
	{
		Flyable 		flyable;
		Coordinates     coordinates;

		coordinates = new Coordinates(longitude, latitude, height);
		if (type.equals("Baloon"))
		{
			flyable = new Baloon(name, coordinates);
			return (flyable);
		}
		else if (type.equals("JetPlane"))
		{
			flyable = new JetPlane(name, coordinates);
			return (flyable);
		}
		flyable = new Helicopter(name, coordinates);
		return (flyable);
	}
}