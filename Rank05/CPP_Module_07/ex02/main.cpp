#include "Array.hpp"


int main() {

    // Test 1: Default constructor (empty array)
    Array<int> emptyArray;
    std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

    // Test 2: Array of 5 integers (initialized to 0)
    Array<int> intArray(5);
    std::cout << "Size of intArray: " << intArray.size() << std::endl;
    for (unsigned int i = 0; i < intArray.size(); i++) {
        std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // Test 3: Array of 3 floats (initialized to 0.0)
    Array<float> floatArray(3);
    std::cout << "Size of floatArray: " << floatArray.size() << std::endl;
    for (unsigned int i = 0; i < floatArray.size(); i++) {
        std::cout << "floatArray[" << i << "] = " << floatArray[i] << std::endl;
    }

    // Test 4: Copy constructor
    Array<int> copyArray = intArray;
    std::cout << "Size of copyArray (copy of intArray): " << copyArray.size() << std::endl;
    for (unsigned int i = 0; i < copyArray.size(); i++) {
        std::cout << "copyArray[" << i << "] = " << copyArray[i] << std::endl;
    }

    // Modify copyArray and check if intArray remains unchanged
    copyArray[0] = 42;
    std::cout << "After modifying copyArray[0] = 42" << std::endl;
    std::cout << "intArray[0] = " << intArray[0] << std::endl;
    std::cout << "copyArray[0] = " << copyArray[0] << std::endl;

    // Test 5: Assignment operator
    Array<int> assignedArray(2);
    assignedArray = intArray;
    std::cout << "Size of assignedArray (assigned from intArray): " << assignedArray.size() << std::endl;

    // Test 6: Out-of-bounds access
    try {
        std::cout << "Accessing out-of-bounds element: " << intArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}