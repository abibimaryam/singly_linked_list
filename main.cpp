#include <iostream>
#include "Container.h"
#include "GroupContainer.h"
#include "Grouplist.h"
#include "ListAbstract.h"
#include "MemoryManager.h"
#include "Mem.h"
#include "list.h"
#include <chrono>

void test(int n) {
	Mem mem(n);
	List list(mem);

	/*for (int i = 0; i < 10; i ++) {
	list.push_front(&i, sizeof(int));
	}


	List::Iterator *it1 = list.newIterator();
	for (int i = 0; i < 10; i++) {
	size_t size;
	void* data = it1->getElement(size);
	cout << size << " " << *(reinterpret_cast<int*>(data)) << endl;
	it1->goToNext();
	}
	cout << endl;
	List::Iterator *iter = list.newIterator();



	/*for (int i = 0; i < 2; i ++) {
	iter->goToNext();
	}

	size_t size;
	void* data = iter->getElement(size);
	cout << size << endl;
	cout << *(reinterpret_cast<int*>(data)) << endl;


	//list.remove(iter);

	for (int i = 0; i < 5; i++) {
	list.remove(iter);
	iter->goToNext();
	}

	List::Iterator *iterator = list.newIterator();
	for (int i = 0; i < 5; i++) {
	size_t size;
	void* data = iterator->getElement(size);
	cout << size<<" "<< *(reinterpret_cast<int*>(data)) << endl;
	iterator->goToNext();
	}
	cout << endl;

	int data1 = 10;
	List::Iterator* it2 = list.newIterator();
	it2->goToNext();
	it2->goToNext();
	list.insert(it2, &data1, 4);
	/*
	if (iter->hasNext()) {
	cout << "has next" << endl;
	}
	else
	cout << "has not next" << endl;

	iter->goToNext();

	data = iter->getElement(size);
	cout << size << endl;
	cout << *(reinterpret_cast<int*>(data)) << endl;


	it2 = list.newIterator();
	for (int i = 0; i < 10; i++) {
	size_t size;
	void* data = it2->getElement(size);
	cout << size << " " << *(reinterpret_cast<int*>(data)) << endl;
	it2->goToNext();
	}


	List::Iterator* it3 = list.newIterator();
	it3->goToNext();
	List::Iterator* it4 = list.newIterator();
	cout<<it4->equals(it3)<<endl;

	//cout << list.empty() << endl;
	//list.clear();
	/*size_t i = 0;

	List::Iterator iter ((Node*)list.front(i));

	int ii = 0;
	memcpy(&ii, iter.getElement(i),i);
	cout << ii << endl;

	list.front(i);
	for (int i = 0; i < 10; i++) {
	list.pop_front();
	}
	//cout << list.empty() << endl;

	int data2 = 10;
	List::Iterator* it5=list.find(&data2, 4);
	size_t size;
	void* data = it5->getElement(size);
	cout << size << " " << *(reinterpret_cast<int*>(data)) << endl;
	*/
	/*try { list.pop_front(); }
	catch (List::Error e) {
	cout << e.msg << endl;
	}*/
	//замер времени
	// печатать время и запустить с разными n пол мл и мл 
	// find до корня из n
	try {
		for (int i = 1; i < n; i++) {
			list.push_front(&i, sizeof(int));
		}
		cout << n << endl;
		//cout << list.size() << endl;

		List::Iterator *it1 = list.newIterator();
		for (int i = list.size(); i > 0; i--) {
			size_t size;
			void* data = it1->getElement(size);
			if (*(int*)data != i) {
				throw List::Error("Error");
			}
			if (it1->hasNext()) {
				it1->goToNext();
			}
		}



		cout << "Correct" << endl;

		List::Iterator *it2 = list.newIterator();
		int cou = list.size();
		size_t size;
		void* data;
		for (int i = 1; i <= cou; i++) {
			data = it2->getElement(size);
			if (*(reinterpret_cast<int*>(data)) % 2 == 1) {
				list.remove(it2);
				//cou--;
			}

			else {
				if (it2->hasNext()) {
					it2->goToNext();
				}
			}
		}

		int val = 1;
		it1 = list.newIterator();
		for (int i = list.size(); i > 0; i--) {
			size_t size;
			void* data = it1->getElement(size);
			if (*(int*)data == val) {	//проверять что это число конкретное
				throw List::Error("not all even");
			}
			if (it1->hasNext()) {
				it1->goToNext();
			}
			val = val + 2;
		}


		cout << "all even" << endl;


		/*
		//цикл find
		val = 2;
		List::Iterator *it3 = list.newIterator();
		for (int i = 2; i < 1000; i += 2) {
		it3 = list.find(&i, sizeof(i));
		void* data = it3->getElement(size);
		if (*(reinterpret_cast<int*>(data)) != val) {
		throw List::Error("find not correct");
		}
		val = val + 2;
		/*size_t size;
		void* data = it3->getElement(size);
		cout << size << " " << *(reinterpret_cast<int*>(data)) << endl;

		}
		*/
		//цикл find
		//не должен найти не четное ошибка если нашел нечетное
		//отдельный тест для млн пробегает итератор.
		//удалить итератор
		List::Iterator *it3 = list.newIterator();
		for (int i = 1; i < 1000; i++) {
			it3 = list.find(&i, sizeof(i));
			if (it3 != NULL) {
				void* data = it3->getElement(size);
				if (*(reinterpret_cast<int*>(data)) % 2 == 1) {
					throw List::Error("find find odd");

				}
				delete it3;
			}
		}

		val = 999998;
		it3 = list.newIterator();
		for (int i = val; i > 0; i -= 2) {
			void* data = it3->getElement(size);
			if (*(reinterpret_cast<int*>(data)) != val) {
				throw List::Error("even not found");
			}
			val = val - 2;
			it3->goToNext();
		}

		delete it3;
		cout << "find correct" << endl;
	}
	catch (List::Error e) {
		cout << e.msg << endl;
	}

}

int main() {
	auto begin = std::chrono::steady_clock::now();
	int n = 1000000;
	test(n);
	auto end = std::chrono::steady_clock::now();

	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "The time: " << elapsed_ms.count() << " ms\n";

	system("pause");
}