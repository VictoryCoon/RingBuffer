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

	// write�� �� ��ġ�� ���Ѵ�.
	// read�� �� ��ġ�� ���Ѵ�.

	int write(char* src, int writeCount);
	int read(char* readBuffer, int readCount);

	char& operator[](int pos);

	void PrintAll();
	void PrintDependPos();

public:
	char* buffer;
};