// Name: Ali Bayati 
// sequence template class


#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include<iostream>
#include<string>
#include<cassert>
#include <cstdlib>  


using namespace std;
namespace main_savitch_3
{
	template<typename T>
	class  sequence
	{
	public:
		// TYPEDEFS and MEMBER CONSTANTS
		
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;
		// CONSTRUCTOR
		sequence(T=T());
		
	
		// MODIFICATION MEMBER FUNCTIONS
		void start();
		void advance();
		void insert(const T& entry);
		void attach(const T& entry);
		void remove_current();

		void print();
		
		size_type size() const;
		bool is_item() const;
		T current() const;
	private:
		T data[CAPACITY];
		size_type used;
		size_type current_index;
	};

	//		void remove_current()
	//     Precondition: is_item returns true.
	//     Postcondition: The current item has been removed from the sequence, and the
	//     item after this (if there is one) is now the new current item.
	

	
	
	template<typename T>
	sequence<T>::sequence(T value)
	{
		
		used = 0;
		current_index = 0;
		data[current_index] = value;
		used++;
		
		}
	
	template<typename T>
	void sequence<T>::remove_current()
	{
		if (is_item())
		{
			for (size_t i = current_index; i < used; i++)
				data[i] = data[i + 1];
		}
		used--;
	}



	//     Precondition: is_item returns true.
	//     Postcondition: If the current item was already the last item in the
	//     sequence, then there is no longer any current item. Otherwise, the new
	//     current item is the item immediately after the original current item.

	template<typename T>
	void sequence<T>::advance()
	{

		if (is_item() && (current_index<CAPACITY))
		{

			current_index++;

		}
	}


	//   bool is_item( ) const
	//     Postcondition: A true return value indicates that there is a valid
	//     "current" item that may be retrieved by activating the current
	//     member function (listed below). A false return value indicates that
	//     there is no valid current item.
	template<typename T>
	bool sequence<T>::is_item() const
	{
			
		if (data[current_index] !=data[used])
			return true;
		return false ;
	}

	//   value_type current( ) const
	//     Precondition: is_item( ) returns true.
	//     Postcondition: The item returned is the current item in the sequence.
	template<typename T>
	T sequence<T>::current() const
	{
		if (is_item())
			return data[current_index];
		else
			return 0;
	}



	//         size_type size() const
	//     Postcondition: The return value is the number of items in the sequence.
	template<typename T>
	size_t sequence<T>::size() const
	{
		return used;
	}


	//     Postcondition: The first item on the sequence becomes the current item
	//     (but if the sequence is empty, then there is no current item).
	//
	template<typename T>
	void sequence<T>::start()
	{
		current_index = 0;
	}


	//   
	//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence
	//     before the current item. If there was no current item, then the new entry 
	//     has been inserted at the front of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.
	template<typename T>
	void sequence<T>::insert(const T& entry)
	{
		
		assert(size() < CAPACITY);
		if (is_item())
		{
			for (size_t i = used; i > current_index; i--)
			{
				data[i] = data[i - 1];
			}

			data[current_index] = entry;
			used++;
		}
		else if (!(is_item()) && used != 0)
		{
			current_index = 0;
			for (size_t i = used; i > current_index; i--)
			{
				data[i] = data[i - 1];
			}
			used++;

			data[current_index] = entry;

		}
		else
		{

			data[current_index] = entry;
			used++;

		}
	}

//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence after
	//     the current item. If there was no current item, then the new entry has 
	//     been attached to the end of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.

	template<typename T>
	void sequence<T>::attach(const T& entry)
	{
		assert(size() < CAPACITY);

		if (is_item())
		{
			for (size_t i = used; i > current_index; i--)
			{
				data[i] = data[i - 1];
			}

			data[current_index + 1] = entry;
			used++;
			current_index++;
		}
		else
		{
			data[current_index] = entry;
			used++;

		}

	}
	template<typename T>
	void sequence<T>::print()
	{
		cout << "{";
		for (size_t i = 0; i < used; i++)
		{
			cout << data[i];
			if (i != used-1)
				cout << ", ";
		}
		cout << "}\n";

	}



}
#endif
