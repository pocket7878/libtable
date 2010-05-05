#ifndef _TABLE_H_
#define _TABLE_H_
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Table
{
	private:
		vector<T> vec1;
		vector<T> vec2;
		int width;
		int height;
		// true: use vec1,  false: use vec2;
		// default: use vec1
		bool flag;
	public:
		Table() {
			flag = true;
		}
		Table(int x, int y) {
			vec1.resize(x * y);
			vec2.resize(x * y);
			width = x;
			height = y;
			flag = true;
		}
		
		void xor_swap(int *x, int *y)
		{
			if(x != y) {
				*x ^= *y;
				*y ^= *x;
				*x ^= *y;
			}
		}
		//keep data when resizing
		void resize(int x, int y) {
			//change width data
			width = x;
			height = y;
			//loop flag
			int i;
			//when using vec1
			if(flag == true) {
				//change flag
				flag = false;
				//clear vec2
				vec2.clear();
				//resize vec2
				vec2.resize(x * y - 1);
				//and copy data from vec1
				for(i = 0; i < vec1.size(); i++) {
					vec2[i] = vec1[i];
				}
			}
			//when using vec2
			else {
				//change flag
				flag = true;
				//clear vec2
				vec1.clear();
				//resize vec2
				vec1.resize(x * y - 1);
				//and copy data from vec1
				for(i = 0; i < vec2.size(); i++) {
					vec1[i] = vec2[i];
				}
			}
		}

		void setCell(int x, int y, T data) {
			if(flag == true) {
				if(vec1.capacity() < x * y) {
					cerr << "ERROR: Table over flow!!" << endl;
				}
				else {
					vec1[width * (y - 1) + (x - 1)] = data;
				}
			}
			else {
				if(vec2.capacity() < x * y) {
					cerr << "ERROR: Table over flow!!" << endl;
				}
				else {
					vec2[width * (y - 1) + (x - 1)] = data;
				}
			}
		}

		T getCell(int x, int y) {
			if(flag == true) {
				return vec1[width * (y - 1) + (x - 1)];
			}
			else {
				return vec2[width * (y - 1) + (x - 1)];
			}
		}

		void turnRight() {
			//loop 
			int i;
			//present direction
			int x,y;
			//feature direction
			int new_x, new_y;

			if(flag == true) {
				//clear vec2
				vec2.clear();
				//resize vec2
				vec2.resize(height * width);
				//copy data from vec1
				for(i = 0; i < vec1.size(); i++) {
					x = i % width;
					y = i / height;
					//set feature direction
					new_x = (width - 1 - y);
					new_y = x;
					vec2[new_x + new_y * height] = vec1[i];
				}
				//change flag
				flag = false;
			}
			else {
				//clear vec2
				vec1.clear();
				//resize vec2
				vec1.resize(height * width);
				//copy data from vec1
				for(i = 0; i < vec2.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = (width - 1 - y);
					new_y = x;
					vec1[new_x + new_y * height] = vec2[i];
				}
				//change flag
				flag = true;
			}
			//change parameter;
			xor_swap(&width,&height);
		}

		void turnLeft() {
			//loop 
			int i;
			int x,y;
			int new_x, new_y;
			if(flag == true) {
				//clear vec2
				vec2.clear();
				//resize vec2
				vec2.resize(height * width);
				//copy data from vec1
				for(i = 0; i < vec1.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = y;
					new_y = (height - 1 - x);
					vec2[new_x + new_y * height] = vec1[i];
				}
				//change flag
				flag = false;
			}
			else {
				//clear vec2
				vec1.clear();
				//resize vec2
				vec1.resize(height * width);
				//copy data from vec1
				for(i = 0; i < vec2.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = y;
					new_y = (height - 1 - x);
					vec1[new_x + new_y * height] = vec2[i];
				}
				//change flag
				flag = true;
			}
			//change parameter;
			xor_swap(&width,&height);
		}

		//horizontal flip
		void hflip() {
			int i;
			int x, y;
			int new_x, new_y;
			if(flag == true) {
				//clear vec2
				vec2.clear();
				//resize vec2 
				vec2.resize(width * height);
				//copy data from vec1
				for(i = 0; i < vec1.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = (width - 1 - x);
					new_y = y;
					vec2[new_x + new_y * width] = vec1[i];
				}
				flag = false;
			}
			else {
				//clear vec1
				vec1.clear();
				//resize vec1 
				vec1.resize(width * height);
				//copy data from vec1
				for(i = 0; i < vec2.size(); i++) {
					x = i % width;
					y = i / height;
					//set  new direction
					new_x = (width - 1 - x);
					new_y = y;
					vec1[new_x + new_y * width] = vec2[i];
				}
				flag = true;
			}
		}
		//vertical flip
		void vflip() {
			int i;
			int x, y;
			int new_x, new_y;
			if(flag == true) {
				//clear vec2
				vec2.clear();
				//resize vec2 
				vec2.resize(width * height);
				//copy data from vec1
				for(i = 0; i < vec1.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = x;
					new_y = (height - 1 - y);
					vec2[new_x + new_y * width] = vec1[i];
				}
				flag = false;
			}
			else {
				//clear vec1
				vec1.clear();
				//resize vec1 
				vec1.resize(width * height);
				//copy data from vec1
				for(i = 0; i < vec2.size(); i++) {
					x = i % width;
					y = i / height;
					//set new direction
					new_x = x;
					new_y = (height - 1 - y);
					vec1[new_x + new_y * width] = vec2[i];
				}
				flag = true;
			}
		}

		void dump_table() {
			int i;
			if(flag == true) {
				//dump vec1
				cout << "vec1" << endl;
				for(i = 0; i < vec1.size(); i++) {
					cout << vec1[i];
					if(((i + 1) % width) == 0) {
						cout << "\n";
					}
				}

			}
			else {
				cout << "vec2" << endl;
				//dump vec2
				for(i = 0; i < vec2.size(); i++) {
					cout << vec2[i];
					if(((i + 1) % width) == 0) {
						cout << "\n";
					}
				}
			}
		}
};

#endif
