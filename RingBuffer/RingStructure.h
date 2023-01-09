#pragma once
class RingStructure
{
private:
	int count;
	int size;
	int offset;
	int wPos;
	int rPos;
	int readibleSize;
	int writibleSize;
public:

	RingStructure();
	~RingStructure();

	void Clear();
	bool IsEmpty();
	bool IsFull();
	int Count();

	void GetPos();

	// write도 쓸 위치를 정한다.
	// read도 쓸 위치를 정한다.

	int write(char* src, int writeCount);
	int read(char* readBuffer, int readCount);

	char& operator[](int pos);

	void PrintAll();
	void PrintDependPos();

public:
	char* buffer;
};