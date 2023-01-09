#include <iostream>
#include "RingStructure.h"
using namespace std;

int main()
{
	RingStructure rs;

	char* buffer0 = new char[3];
	char* buffer1 = new char[3];
	char* buffer2 = new char[3];
	char* buffer3 = new char[10];

	//char* readBuffer = new char[1];
	string readBuffer = "";

	buffer1[0] = 'a';
	buffer1[1] = 'b';
	buffer1[2] = 'c';


	rs.write(buffer1, 3);

	buffer2[0] = 'A';
	buffer2[1] = 'B';
	buffer2[2] = 'C';

	rs.write(buffer2, 3);


	buffer3[0] = '0';
	buffer3[1] = '1';
	buffer3[2] = '2';
	buffer3[3] = '3';
	buffer3[4] = '4';
	buffer3[5] = '5';
	buffer3[6] = '6';
	buffer3[7] = '7';
	buffer3[8] = '8';
	buffer3[9] = '9';

	rs.write(buffer3, 10);
	rs.read((char*)readBuffer.c_str(), 7);
	rs.GetPos();
	rs.PrintDependPos();
	cout << "READ BUFFER : " << readBuffer.c_str() << endl;
	
	buffer0[0] = 'x';
	buffer0[1] = 'y';
	buffer0[2] = 'z';
	rs.PrintDependPos();

	rs.write(buffer0, 3);

	rs.read((char*)readBuffer.c_str(), 6);
	rs.GetPos();
	rs.PrintDependPos();
	cout << "READ BUFFER : " << readBuffer.c_str() << endl;
	//cout << "READ BUFFER : " << readBuffer << endl;

	return 0;
}