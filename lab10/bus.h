
#ifndef BUS_H
#define BUS_H

#include <cstddef>
#include <string>


class Bus
{
public:
	size_t busNumber;
	size_t routeNumber;
	std::string driverName;
	
	
	Bus();
	Bus(const size_t);
	Bus(const size_t, const size_t, const std::string);
	
	
	std::string toString() const;
	
	
	Bus& operator=(const Bus&);
	bool operator==(const Bus&) const;
	bool operator!=(const Bus&) const;
};


#endif
