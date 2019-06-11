package com.asoroka.launcher;

import com.asoroka.launcher.utils.OutputWriter;

import java.util.ArrayList;
import java.util.List;

public class Tower
{
	private List<Flyable> observers;

	public Tower()
	{
		this.observers = new ArrayList<Flyable>();
	}

	public void register(Flyable flyable)
	{
		OutputWriter.Instance.addLine("Tower: Registered " + flyable.getData());
		if (this.observers.contains(flyable))
			return;
		this.observers.add(flyable);
	}

	public void unregister(Flyable flyable)
	{
		OutputWriter.Instance.addLine("Tower: " + flyable.getData() + " landed");
		this.observers.remove(flyable);
	}

	protected void conditionsChanged()
	{
		for (int i = 0; i < this.observers.size(); i++)
		{
			this.observers.get(i).updateConditions();
		}
	}
}
