#pragma once
#include <iostream>
using namespace std;
const int tablesize = 20;
class Node
{
public:
	int key;
	int value;
	Node* next;
	Node()
	{
		key = -1;
		value = -1;
		next = nullptr;
	}
	Node(int k, int val)
	{
		key = k;
		value = val;
		next = nullptr;
	}
};

class HashMap
{
public:
	int num_of_elements;
	int capacity;
	Node** arr;
	HashMap()
	{
		capacity = tablesize;
		num_of_elements = 0;	//current index/ number of elements currently present
		arr = new Node*[capacity];
		for (int i = 0; i < capacity; i++)
		{
			arr[i] = new Node();
		
		}
		
	}
	int hash_function(int k)
	{
		int index = k % capacity;
		return index;
	}
	void insert(int k, int val)
	{
		num_of_elements++;
		int hindex = hash_function(k);
		if (arr[hindex]->value==-1)
		{
			arr[hindex]->key = k;
			arr[hindex]->value = val;
		}
		else
		{
			if (arr[hindex]->next == nullptr)
				arr[hindex]->next = new Node(k,val);
			else
			{
				Node* nnode = new Node(k, val);
				nnode->next = arr[hindex];
				arr[hindex] = nnode;
			}

		}
	}
	int search(int k)
	{
		int hindex = hash_function(k);
		if (arr[hindex] == nullptr)
			return -1;
		if (arr[hindex]->next == nullptr)
		{
			//cout << arr[hindex]->value << endl;
			return arr[hindex]->value;
		}
		else
		{
			Node* temp=arr[hindex];
			while (temp != nullptr)
			{
				if (temp->key == k)
					return temp->value;
				temp = temp->next;
			}
			return -1;
		}
	}
	void remove(int key)
	{
		num_of_elements--;
		int index = hash_function(key);
		Node* temp = arr[index];
		Node* prev = nullptr;
		while (temp != nullptr)
		{
			if (temp->key == key)
				break;
			prev = temp;
			temp = temp->next;
		}
		if (temp != nullptr && arr[index] == temp)
		{
			arr[index] = temp->next;
			delete temp;
		}
		else
			return;
	}
	int findMajorityElement()
	{
		int count = 0;
		int final = 0;
		int f_val = -1;
	
		for (int i = 0; i < capacity; i++)
		{
			int v=arr[hash_function(i)]->value;
			if (v == -1)
				continue;
			count = 0;
			for (int j = i; j < capacity; j++)
			{
				if (arr[hash_function(j)]->value == -1)
					continue;
				if (arr[hash_function(j)]->value == v)
				{
					count++;
				}
				if(arr[hash_function(j)]->value != v)
				{
					//checck fo rlinked list
					if (arr[hash_function(j)]->next != nullptr)
					{
						Node* temp = arr[hash_function(j)];
						while (temp->next != nullptr)
						{
							temp = temp->next;
							if (temp->value == v)
								count++;
						}
					}
					continue;
				}
			}
			if (final < count)
			{
				final = count;
				f_val = v;
			}
		}
		cout << final << endl;
		return f_val;
	}

	~HashMap()
	{
		delete[]arr;
	}
};
