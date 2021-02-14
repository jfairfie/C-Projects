#include "sequence.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
using namespace main_savitch_4;

const sequence::size_type sequence::DEFAULT_CAPACITY;

    sequence::sequence(size_type initial_capacity)
    {
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
        current_index = 0;
    }

    sequence::sequence(const sequence& source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        std::copy(source.data, source.data + used, data);
        current_index = source.current_index;
    }

    sequence::~sequence()
    {
        delete [] data;
    }

    void sequence::start()
    {
        current_index = 0;
    }

    void sequence::advance()
    {
        if (is_item()) {
            current_index+=1;
        }
    }

    bool sequence::is_item() const
    {
        //returns a bool to indicate whether there actually is another item for current to provide
        if(current_index < used){
            return true;
        } else {
            return false;
        }
    }
    sequence::size_type sequence::size()const
    {
        return used;
    }

    sequence::value_type sequence::current()const
    {
        assert(is_item());
        return data[current_index];
    }

    void sequence::insert(const value_type& entry)
    {
        if(used >= capacity)
        {
            resize((capacity + 2));
        }

        if(is_item() == false)
        {
            current_index = 0;
        }

        if(used > 0)
        {
             for(int i = used - 1; i>=(int)current_index; --i)
            {
                data[i+1]=data[i];
            }
        }
        data[current_index] = entry;
        used += 1;
    }


    void sequence::attach(const value_type& entry)
    {
        if (used >= capacity) {
            resize(capacity + 2);
        }

        if (current_index == used) {
            current_index = used - 1;
        }

        assert(used < capacity);
        if (used > 0) {
            for (size_type i = used + 1; i > current_index + 1; i--) {
                data[i] = data[i - 1];
            }

            data[current_index + 1] = entry;
            current_index++;
        } else {
            start();
            data[current_index] = entry;
            current_index = 0;
        }

        used++;
    }

    void sequence::resize(size_type new_capacity)
    {
        value_type *tempData;

        if(new_capacity == capacity) {
            return;
        }

        if(new_capacity < used) {
            new_capacity = used;
        }

        tempData = new value_type[new_capacity];
        std::copy(data, data+used, tempData);
        delete [ ] data;
        data = tempData;
        capacity = new_capacity;
    }

    void sequence::remove_current()
    {
        assert(size() > 0);
        for(size_type i = current_index+1; i<used; i++) {
            data[i-1]=data[i];
        }
        used-=1;
    }

    void sequence::operator =(const sequence& source)
    {
        value_type *new_data;

        if(this == &source)
            return;
        if(capacity != source.capacity) {
            new_data = new value_type[source.capacity];
            delete [] data;
            data = new_data;
            capacity = source.capacity;
        }
        used = source.used;
        current_index = source.current_index;
        std::copy(source.data, source.data+used, data);
    }
