
#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <iomanip>
#include <sstream>


struct UUID 
{
	unsigned Node;//16 bits
	unsigned long long TimeEpoch; //52 bits
	unsigned long long RandomNumber; //60 bits
};

class UUIDGenerator
{
public:
	UUIDGenerator() 
	{
	}

	void SetTimeEpoch()
	{
		//Get the current epoch in nanoseconds from January 1 1970
		std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch());
		uuid.TimeEpoch = ns.count() & 0xFFFFFFFFFFFFF;
	}
	
	void SetRandomNumber(std::mt19937& PRNG)
	{
		std::uniform_int_distribution<uint32_t> uint_dist_long(1, UINT32_MAX);
		uuid.RandomNumber =  uint_dist_long(PRNG);
		uuid.RandomNumber <<= 32;
		uuid.RandomNumber |= uint_dist_long(PRNG);
		uuid.RandomNumber &= 0xFFFFFFFFFFFFFFF ;
	}

	void SetNodeNumber(std::mt19937& PRNG)
	{
		/*This number is currently being randomly generated. In a distributed environment this would be known before-hand */
		std::uniform_int_distribution<unsigned> uint_dist_long(1,65536);
		uuid.Node = uint_dist_long(PRNG) & 0xFFFF;
	}

	std::string GenerateUUID()
	{
		 
		std::random_device seed;
		std::mt19937 PRNG(seed());
		
		//Initialize various fields of UUID structure
		SetRandomNumber(PRNG);
		SetTimeEpoch();
		SetNodeNumber(PRNG);

		std::stringstream ssUUID;
		ssUUID << std::hex << std::setfill('0');
		
		ssUUID << std::setw(15) << uuid.RandomNumber; // 15 hex digits = 60 bit binary number
		ssUUID << std::setw(13) << uuid.TimeEpoch;
		ssUUID << std::setw(4) << uuid.Node;

		return ssUUID.str();
	}

	~UUIDGenerator()
	{
	}

private:
	UUID uuid;
};


int main()
{
	
	UUIDGenerator uuid;
	std::cout << uuid.GenerateUUID();

	return 0;
}
