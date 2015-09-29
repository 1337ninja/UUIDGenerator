# UUIDGenerator
A simple UUID generator using C++11.

  This program is a simple **128 bit** UUID generator using C++11. Please note that this is **not an RFC4122 compliant** UUID. For more information on the RFC4122 compliant UUID, please refer https://www.ietf.org/rfc/rfc4122.txt. If you are looking for an RFC4122 compliant UUID , try Boost http://www.boost.org/doc/libs/1_59_0/libs/uuid/uuid.html.
  
  The structure of this UUID generator is quite simple. It comprises of 3 parts,
  
     Random Number     |   Time Epoch    |   Node 
  -------------------- | --------------- | ---------
     60 bits           |   52 bits       |  16 bits
     
  
  The Random Number is generated using C++11's **Mersenne Twister** algorithm.  
  The Time Epoch or the number of ticks since Jan 1 1970 is generated using C++11's **time_since_epoch** method.  
  Node value is currently randomly generated. In a distributed environment, this value would be known beforehand.
  
  **Compiling and running**
  
  The only requisite for compiling and running this program is to have an IDE/compiler that has C++11 support. I've tested this on VS2012 and gcc 4.8.2. It's a nobrainer running on VS2012. On Linux you have to mention the -std=c++11 flag.
  
  **g++ -std=c++11 UUIDGenerator.cpp -o uuid <br/>
  ./uuid <br/>**
  
  **54b26f6142518200ca6dd0a872874f5e (Sample Output)**
