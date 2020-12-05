#include "queue.h"

size_t get_num() {
  size_t num;

  std::cin >> num;

  return num;
}

int main() {
  Queue<int> queue;

  std::initializer_list<float> flist = {1,   1.1, 1.2, 1.3, 1.4, 1.5, 1.6,
                                        1.7, 1.8, 1.9, 2,   2.1, 2.2, 2.3,
                                        2.4, 2.5, 2.6, 2.7, 2.8, 2.9};

  try {
    Queue<float> fqueue(flist);

    fqueue.display();

    for (int i = 0; i < 10; i++) {
      fqueue.pop_front();
    }

    for (int i = 0; i < 20; i++) {
      fqueue.push_back(static_cast<float>(i * 0.1));
    }

    fqueue.display();

    fqueue.push_back(111);
  } catch (Queue<float>::Out_of_range) {
    std::cerr << "Out_of_range error\n";
  } catch (Queue<float>::Is_empty) {
    std::cerr << "Is_empty error\n";
  }

  try {
    Queue<float> fqueue(flist);

    std::cout << "element at 4th position: " << fqueue[4] << "\n";

    fqueue[55];
  } catch (Queue<float>::Out_of_range) {
    std::cerr << "Out_of_range error\n";
  }

  try {
    std::cout << "Enter size of queue(with max size = 30): ";
    auto size = get_num();

    queue.fill(size);

    queue.display();
  } catch (Queue<int>::Out_of_range) {

    std::cerr << "Out_of_range error, try again\n";
    std::cout << "Enter size of queue(with max size = 30): ";

    auto size = get_num();

    queue.fill(size);

    queue.display();
  }
  try {
    std::cout << "Enter number of elements to pop: ";
    auto num = get_num();

    for (int i = 0; i < num; i++) {
      queue.pop_front();
    }
    queue.display();
  } catch (Queue<int>::Is_empty) {
    std::cerr << "Is_empty error, try again\n";
    std::cout << "Enter num of elements to pop\n";

    auto num = get_num();

    for (int i = 0; i < num; i++) {
      queue.pop_front();
    }
    queue.display();
  }

  return 0;
}