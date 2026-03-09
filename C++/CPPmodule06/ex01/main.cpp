#include "Serializer.hpp"


int main() {
    //create a data obj
    Data originalData;
    originalData.name = "subject_00";
    originalData.value = 42;
    originalData.price = 99.99;

    std::cout << "==> original data <==" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "Name: " << originalData.name << std::endl;
    std::cout << "Value: " << originalData.value << std::endl;
    std::cout << "Price: " << originalData.price << std::endl;
    std::cout << std::endl;

    //Serialize (convert ptr to int)
    uintptr_t serialized = Serialization::serialize(&originalData);
    std::cout << "==> Serialized <==" << std::endl;
    std::cout << "int representation: " << serialized << std::endl;
    std::cout << std::endl;
    //Deserialize (convert int back to ptr)
    Data* deserialized = Serialization::deserialize(serialized);
    std::cout << "==> Deserialized <==" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << " Value: " << deserialized->value << std::endl;
    std::cout << "Price: " << deserialized->price << std::endl;
    std::cout << std::endl;
    //verify if they are the same
    std::cout << "==> Verification <==" << std::endl;
    if (&originalData == deserialized) {
        std::cout << "Pointers match, success!" << std::endl;
        std::cout << "Original address: " << &originalData << std::endl;
        std::cout << "Deserialized address: " << deserialized << std::endl;
    } else {
        std::cout << "Pointers do not match, error!" << std::endl;
    }
    return 0;
}