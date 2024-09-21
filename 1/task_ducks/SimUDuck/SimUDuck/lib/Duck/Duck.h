#ifndef DUCK_H
#define DUCK_H

#include "Fly/IFlyBehavior.h"
#include "Quack/IQuakBehavior.h"
#include "Dance/IDanceBehavior.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include <optional>


//объявить шаблоны типов для стратегий

class Duck
{
public:
	Duck(std::function<std::optional<std::function<int()>>()> flyBehavior,
		std::function<void()>&& quackBehavior,
		std::function<void()>&& danceBehavior)
		: m_quackBehavior(std::move(quackBehavior))
		, m_danceBehavior(std::move(danceBehavior))
	{
		assert(m_quackBehavior);
		SetFlyBehavior(std::move(flyBehavior));
	}

	void Quack() const
	{
		m_quackBehavior();
	}

	void Swim()
	{
		std::cout << "I'm swimming\n";
	}

	void Fly()
	{
		auto flight = m_flyBehavior();
		if (flight.has_value())
		{
			auto flightCount = flight.value()();
			if (flightCount != 0 && flightCount % 2 == 0)
			{
				m_quackBehavior();
			}
		}
		//узнать может ли утка летать до того, добавить 2 функции: могу ли полетать и полелеть
	}

	//протестировать метод Dance. создать моковый объект, проверить есть метод dance
	 void Dance()
	{
		m_danceBehavior();
	}

	void SetFlyBehavior(std::function<std::optional<std::function<int()>>()> flyBehavior)
	{
		assert(flyBehavior);
		m_flyBehavior = std::move(flyBehavior);
	}

	virtual void Display() const = 0;
	virtual ~Duck() = default;

private:
	std::function<std::optional<std::function<int()>>()> m_flyBehavior;
	std::function<void()> m_quackBehavior;
	std::function<void()> m_danceBehavior;
};

#endif

