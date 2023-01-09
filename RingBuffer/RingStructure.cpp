#include "RingStructure.h"
#include <iostream>
using namespace std;

RingStructure::RingStructure()
{
	count = 0;
	size = 16;
	offset = 1;
	wPos = 0;
	rPos = 0;
	buffer = new char[size];
	memset(buffer, '|', size);
}

RingStructure::~RingStructure()
{
	wPos = 0;
	rPos = 0;
	delete[] buffer;
}

void RingStructure::Clear()
{
}

bool RingStructure::IsEmpty()
{
	return false;
}

bool RingStructure::IsFull()
{
	return false;
}

int RingStructure::Count()
{
	return count;
}

void RingStructure::GetPos()
{
	cout << "wPosition : " << wPos << " / rPosition : " << rPos << endl;
}

int RingStructure::write(char* src, int writeCount)
{
	writibleSize = size - count;
	int restCount = 0;
	if (writibleSize < writeCount)
	{
		restCount = writeCount - writibleSize;

		if (wPos < rPos)
		{
			int writeToReadPosGap = abs(rPos - wPos);
			if (wPos + writeToReadPosGap > size)
			{
				int rearCount = abs(size - wPos);
				int frontCount = abs(writeToReadPosGap - rearCount);
				memcpy(buffer + wPos, src, sizeof(char) * rearCount);
				memcpy(buffer, src, sizeof(char) * frontCount);
				wPos = abs(size - (wPos + writeToReadPosGap));
				count += writeToReadPosGap;
			}
			else
			{
				memcpy(buffer + wPos, src, sizeof(char) * writeToReadPosGap);
				wPos += writeToReadPosGap;
				count += writeToReadPosGap;
			}
		}
		else
		{
			if (wPos + writibleSize > size)
			{
				int rearCount = abs(size - wPos);
				int frontCount = abs(writibleSize - rearCount);
				memcpy(buffer + wPos, src, sizeof(char) * rearCount);
				memcpy(buffer, src, sizeof(char) * frontCount);
				wPos = abs(size - (wPos + writibleSize));
				count += writibleSize;
			}
			else
			{
				memcpy(buffer + wPos, src, sizeof(char) * writibleSize);
				wPos += writibleSize;
				count += writibleSize;
			}
		}

	}
	else
	{
		if (wPos < rPos)
		{
			int writeToReadPosGap = abs(rPos - wPos);
			if (wPos + writeToReadPosGap > size)
			{
				int rearCount = abs(size - wPos);
				int frontCount = abs(writeToReadPosGap - rearCount);
				memcpy(buffer + wPos, src, sizeof(char) * rearCount);
				memcpy(buffer, src, sizeof(char) * frontCount);
				wPos = abs(size - (wPos + writeToReadPosGap));
				count += writeToReadPosGap;
			}
			else
			{
				memcpy(buffer + wPos, src, sizeof(char) * writeToReadPosGap);
				wPos += writeToReadPosGap;
				count += writeToReadPosGap;
			}
		}
		else
		{
			if (wPos + writeCount > size)
			{
				int rearCount = abs(size - wPos);
				int frontCount = abs(writeCount - rearCount);
				memcpy(buffer + wPos, src, sizeof(char) * rearCount);
				memcpy(buffer, src, sizeof(char) * frontCount);
				wPos = abs(size - (wPos + writeCount));
				count += writeCount;
			}
			else
			{
				memcpy(buffer + wPos, src, sizeof(char) * writeCount);
				wPos += writeCount;
				count += writeCount;
			}
		}
	}
	return restCount;
}

int RingStructure::read(char* readBuffer, int readCount)
{
	int restCount = 0;
	if (IsEmpty()) {
		return 0;
	}
	else
	{
		readibleSize = abs(abs(wPos - rPos) - 1);
		int restCount = 0;
		if(readibleSize < readCount)
		{
			restCount = readCount - readibleSize;
			if (rPos + restCount > size)
			{
				int tailCount = size - rPos;
				int headCount = readibleSize - tailCount;
				memcpy(readBuffer, buffer + rPos, sizeof(char) * tailCount);
				memcpy(readBuffer + tailCount, buffer, sizeof(char) * headCount);
				rPos = abs(size - (rPos + restCount));
				count -= (tailCount+ headCount);
			}
			else
			{
				memcpy(readBuffer + rPos, buffer, sizeof(char) * readibleSize);
				rPos += readibleSize;
				count -= readibleSize;
			}
		}
		else
		{
			if (rPos + readCount > size)
			{
				int tailCount = size - rPos;
				int headCount = readCount - tailCount;
				memcpy(readBuffer, buffer + rPos, sizeof(char) * tailCount);
				memcpy(readBuffer + tailCount, buffer, sizeof(char) * headCount);
				rPos = abs(size - (rPos + readCount));
				count -= (tailCount + headCount);
			}
			else
			{
				memcpy(readBuffer + rPos, buffer, sizeof(char) * readCount);
				rPos += readCount;
				count -= readCount;
			}
		}
		return restCount;
	}
}

char& RingStructure::operator[](int pos)
{
	return buffer[pos];
}

void RingStructure::PrintAll()
{
	cout << "[ " ;
	for (int i=0; i<count; i++)
	{
		cout << buffer[i] << " ";
	}
	cout << "] - Count : "<< count << endl;
}

void RingStructure::PrintDependPos()
{
	cout << "[ ";

	if (wPos < rPos) {
		for (int i = wPos; i < rPos; i++)
		{
			cout << buffer[i] << " ";
		}
		for (int i = rPos; i < size; i++)
		{
			cout << buffer[i] << " ";
		}
	}
	else
	{
		for (int i = rPos; i < wPos; i++)
		{
			cout << buffer[i] << " ";
		}
	}
	cout << "] - Count : " << count << endl;
}
