#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>

class Address {
public:
   Address(std::string* _street, std::string* _city, std::string* _state, int _zip);

   int getZipCode( );
   std::string getAddress( );

private:
   std::string* street;
   std::string* city;
   std::string* state;
   int zip;
};
#endif /* ADDRESS_H_ */
