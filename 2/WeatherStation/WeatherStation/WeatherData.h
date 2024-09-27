#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include "Observer.h"

struct SWeatherInfo
{
	double temperature = 0;
	double humidity = 0;
	double pressure = 0;
};

class CStatsData 
{
public:
	CStatsData(const std::string& name) : name(name) {}

	void UpdateData(double newData)
	{
		if (m_min > newData)
		{
			m_min = newData;
		}
		if (m_max < newData)
		{
			m_max = newData;
		}
		m_acc += newData;
		++m_countAcc;

		std::cout << "Max " << name << " " << m_max << std::endl;
		std::cout << "Min " << name << " " << m_min << std::endl;
		std::cout << "Average " << name << " " << (m_acc / m_countAcc) << std::endl;
	}
private:
	std::string name;
	double m_min = std::numeric_limits<double>::infinity();
	double m_max = -std::numeric_limits<double>::infinity();
	double m_acc = 0;
	unsigned m_countAcc = 0;
};

class CDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую.
		Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
		остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		std::cout << "Current Temp " << data.temperature << std::endl;
		std::cout << "Current Hum " << data.humidity << std::endl;
		std::cout << "Current Pressure " << data.pressure << std::endl;
		std::cout << "----------------" << std::endl;
	}
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	//вынести в отдельный класс, у него будет свой метод update

	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую.
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override
	{
		m_tempStats->UpdateData(data.temperature);
		std::cout << "---" << std::endl;
		m_humidityStats->UpdateData(data.humidity);
		std::cout << "---" << std::endl;
		m_pressureStats->UpdateData(data.pressure);
		std::cout << "----------------" << std::endl;
	}

	std::unique_ptr<CStatsData> m_tempStats = std::make_unique<CStatsData>("Temp");
	std::unique_ptr<CStatsData> m_humidityStats = std::make_unique<CStatsData>("Hum");
	std::unique_ptr<CStatsData> m_pressureStats = std::make_unique<CStatsData>("Pressure");
};

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	double GetTemperature()const
	{
		return m_temperature;
	}
	// Относительная влажность (0...100)
	double GetHumidity()const
	{
		return m_humidity;
	}
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const
	{
		return m_pressure;
	}

	void MeasurementsChanged()
	{
		NotifyObservers();
	}

	void SetMeasurements(double temp, double humidity, double pressure)
	{
		m_humidity = humidity;
		m_temperature = temp;
		m_pressure = pressure;

		MeasurementsChanged();
	}
protected:
	SWeatherInfo GetChangedData()const override
	{
		SWeatherInfo info;
		info.temperature = GetTemperature();
		info.humidity = GetHumidity();
		info.pressure = GetPressure();
		return info;
	}
private:
	double m_temperature = 0.0;
	double m_humidity = 0.0;
	double m_pressure = 760.0;
};