
#include "bus.h"


Bus::Bus()
{
	this->busNumber = 0;
	this->routeNumber = 0;
	this->driverName = "";
}

Bus::Bus(const size_t busNumber)
{
	this->busNumber = busNumber;
	this->routeNumber = 0;
	this->driverName = "";
}

Bus::Bus(const size_t busNumber, const size_t routeNumber, const std::string driverName)
{
	this->busNumber = busNumber;
	this->routeNumber = routeNumber;
	this->driverName = driverName;
}


std::string Bus::toString() const
{
	return "{ Bus " + std::to_string(busNumber) + ", route " + std::to_string(routeNumber) + ", driver " + driverName + " }";
}


Bus& Bus::operator=(const Bus& other)
{
	if(this == &other)
		return *this;
	
	this->busNumber = other.busNumber;
	this->routeNumber = other.routeNumber;
	this->driverName = other.driverName;
	
	return *this;
}

bool Bus::operator==(const Bus& other) const
{
	if(this == &other)
		return true;
	
	return this->busNumber == other.busNumber;// && this->routeNumber == other.routeNumber && this->driverName == other.driverName;
}

bool Bus::operator!=(const Bus& other) const
{
	return !(*this == other);
}
