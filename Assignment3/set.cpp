#include "set.h"
#include <cassert>
typedef int value_type;
typedef std::size_t size_type;
value_type* data;
size_type used;
size_type capacity;
#include <sstream>
#include <iostream>
using namespace std;


// postcondition: empty set with initial_capacity has been created
set::set(size_type initial_capacity) {
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;

    for (size_type i = 0; i < capacity; i++) {
        data[i] = NULL;
    }
}

// postcondition: all dynamically allocated memory has been deallocated
set::~set() {
    delete [ ] data;
}


// copy of s has been created;
set::set(const set& s) {
    data = new value_type[s.capacity];
    capacity = s.capacity;
    used = s.used;
    copy(s.data, s.data + used, data);
}

// postcondition: exact copy of s has been assigned to the current set object
set & set::operator= (const set& s){
    value_type *new_data;
    new_data = new value_type[s.capacity];
    data = new_data;
    capacity = s.capacity;
    used = s.used;
	copy(s.data, s.data + used, data);
}

// postcondition: returned true if target was removed from set otherwise false if target was not in the set
bool set::erase(const value_type& target){
    if (capacity == 0) {
        return false;
    }

    for (size_type i = capacity - 1; i >= 0; i--) {
        if (data[i] == target) {
            data[i] = NULL;
            for (size_type j = i; j < capacity; j++) {
                data[j] = data[j + 1];
                if (j + 1 == capacity - 1) {
                    data[used] = NULL;
                }
                used = used - 1;
            }
            return true;
        }
    }

    return false;
}

// postcondition: if 'entry' was not in the set(return true), then entry has been added otherwise if 'entry' was in the set nothing was done (return false)
bool set::insert(const value_type& entry){
    for (size_type i = 0; i < capacity; i++) {
        if (data[i] == entry) {
            return false;
        }
    }

    data[used] = entry;
    used = used + 1;
    return true;
}

 // postcondition: non-duplicating elements from addend have been added to the set
void set::operator+=(const set& addend){
    for (size_type i = 0; i < addend.size(); i++) {
        if (contains(addend.data[i]) == false) {
            reserve(capacity + 1);
            data[used] = addend.data[i];
            used = used + 1;
        }
    }


}

// postcondition: number of elements in the set has been returned
set::size_type set::size() const {
    return used;
}

// postcondition: returned whether target is in the set
bool set::contains(const value_type& target) const {
    for (size_type i = 0; i < capacity; i++) {
        if (data[i] == target) {
            return true;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream& output, const set& s) {
    stringstream ss;
    int size = s.size();

    std::ostringstream os;
    for (size_type i = 0; i < size; i++) {
        os << s.data[i];
        os << " ";
    }

    std::string str(os.str());

    return output << str;
}

void set::reserve (size_type new_capacity) {
    value_type* temp = new value_type[new_capacity];
    copy(data, data + used, temp);
    delete [ ] data;
    capacity = new_capacity;
    data = temp;
}
