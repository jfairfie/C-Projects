#include "Sequence.h"
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
    typedef double value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    size_type used;
    size_type current_index;
    value_type data[CAPACITY];

    Sequence::Sequence()
    {
        used = 0;
        current_index = 0;
        for (size_type i = 0; i < CAPACITY; i++) {
            data[i] = NULL;
        }
    }

    void Sequence::start() {
        current_index = 0;
    }

    void Sequence::advance() {
        if (is_item()) {
            current_index++;
        } else {
            current_index = NULL;
        }
    }

    void Sequence::insert(const value_type& entry) {
        if (used < size()) {
            if (current_index != NULL) {
                for (size_type i = used; i > current_index; i--) {
                    data[i] = data[i - 1];
                }
                data[current_index - 1] = entry;
            } else {
                value_type temp[CAPACITY];
                for (size_type i = used; i > 0; i--) {
                    data[i] = data[i - 1];
                }
                data[0] = entry;
            }
        }

        used++;
    }

    void Sequence::attach(const value_type& entry) {
        if (size() < CAPACITY) {
            if (current_index != NULL) {
                for (size_type i = used; i > current_index + 1; i--) {
                    data[i] = data[i - 1];
                }
                data[current_index + 1] = entry;
            } else {
                data[used] = entry;
            }
        }
        used++;
    }

    size_type Sequence::size() const {
        return used;
    }

    void Sequence::remove_current() {
        for (size_type i = current_index; i < used - 1; i++) {
            data[i] = data[i+1];
        }

        data[used - 1] = NULL;
        used--;
    }

    bool Sequence::is_item() const {
        if (data[current_index + 1] != NULL) {
            return true;
        } else {
            return false;
        }
    }

    Sequence::value_type Sequence::current() const {
        if (is_item()) {
            return current_index;
        }
    }
