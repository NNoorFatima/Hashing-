#pragma once
#include <iostream>
#include <time.h>
using namespace std;
const int tablesize = 10;
#define wait 99999999
class HashEntry
{
public:
	int key;
	int value;
	HashEntry(int k, int v)
	{
		key = k;
		value = v;
	}
	HashEntry()
	{
		key = 0;
		value = 0;
	}
};

class HashMap
{

public:
	HashEntry* arr;

	HashMap()
	{
		arr = nullptr;
		arr = new HashEntry[tablesize];
		for (int i = 0; i < tablesize; i++)
			arr[i].key = -1;
	}
	int HashFucntion(int k)
	{
		int index = k % tablesize;
		return index;
	}
	void insert1(int k, int value)
	{
		int hindex = HashFucntion(k);
		bool found = false;
		
		while (arr[hindex].key != -1 && found!=1)
		{	
			if (arr[hindex].key == k)
			{
				found = 1;
			}
			else
			{
				hindex = (hindex + 1) % tablesize;
			}
			
		}
		if (found)
		{
			throw std::runtime_error("Duplicate items are not allowed\n");
		}
		else
		{
			HashEntry n_node(k, value);
			arr[hindex] = n_node;
			
		}
	
		
	}
	void insert2(int k, int value)
	{
		int hindex = HashFucntion(k);
		bool found = false;
		srand(time(0));
		/*int random = rand() % tablesize*/;

		while (arr[hindex].key != -1 && found != 1)
		{
			if (arr[hindex].key == k)
			{
				found = 1;
			}
			else
			{
				int random = rand() % tablesize;
				hindex = (hindex + random) % tablesize;
			}

		}
		if (found)
		{
			throw std::runtime_error("Duplicate items are not allowed\n");
		}
		else
		{
			HashEntry n_node(k, value);
			arr[hindex] = n_node;

		}

	}
	void insert3(int k, int value)
	{
		int hindex = HashFucntion(k);
		bool found = false;
		int count = 1;
		while (arr[hindex].key != -1 && found != 1)
		{
			if (arr[hindex].key == k)
			{
				found = 1;
			}
			else
			{
				hindex = (hindex + count*count) % tablesize;
				count++;
			}

		}
		if (found)
		{
			throw std::runtime_error("Duplicate items are not allowed\n");
		}
		else
		{
			HashEntry n_node(k, value);
			arr[hindex] = n_node;

		}

	}
	bool search1(int key)
	{
		int hindex = HashFucntion(key);
		bool found = false;

		while (arr[hindex].key != -1 && found != 1)
		{
			if (arr[hindex].key == key)
			{
				found = 1;
			}
			else
			{
				hindex = (hindex + 1) % tablesize;
			}

		}
		if (found)
		{
			return 1;
		}
		else
			return 0;
		
	}
	bool search3(int key)
	{
		int count = 1;
		int hindex = HashFucntion(key);
		bool found = false;

		while (arr[hindex].key != -1 && found != 1)
		{
			if (arr[hindex].key == key)
			{
				found = 1;
			}
			else
			{
				hindex = (hindex + count*count) % tablesize;
				count++;
			}

		}
		if (found)
		{
			return 1;
		}
		else
			return 0;
	}
	~HashMap()
	{
		delete[]arr;
	}
};