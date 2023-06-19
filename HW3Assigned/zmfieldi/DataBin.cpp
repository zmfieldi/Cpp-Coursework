#include <iostream>

#include "DataBin.h"

DataBin::DataBin(int _datum) {
   datum = new int(_datum);
}

int DataBin::getDatum( ) {
   return *datum;
}

DataBin::~DataBin() {
   std::cout << "deleting DataBin " << *datum << std::endl;
   delete datum;
}
