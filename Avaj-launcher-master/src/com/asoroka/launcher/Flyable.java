package com.asoroka.launcher;

public interface Flyable
{
	 public void updateConditions();
	 public void registerTower(WeatherTower weatherTower);
	 public String getData();
}
