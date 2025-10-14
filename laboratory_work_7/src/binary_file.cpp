#include "binary_file.h"

BinaryFile::BinaryFile() : name(NAME_FILE) {}

BinaryFile::BinaryFile(const std::string name) : name(name) {}

BinaryFile::~BinaryFile()
{
    file.close();
}

bool BinaryFile::open()
{
    if (file.is_open())
        file.close();
    file.open(name, std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
    return (file.is_open());
}
void BinaryFile::close()
{
    file.close();
}
bool BinaryFile::is_open()
{
    return file.is_open();
}
bool BinaryFile::is_empty()
{
    char symbol = '$';
    file.seekg(0, std::ios::beg);
    file.read(reinterpret_cast<char *>(&symbol), sizeof(char));
    file.seekg(0, std::ios::beg);

    if (symbol == '$')
        return true;
    return false;
}

void BinaryFile::show()
{
    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    file.seekg(0, std::ios::beg);
    Car car;
    std::cout << C_YELLOW << "\tContent File\n" << C_WHITE;
    while (length != file.tellg())
    {
        file >> car;
        std::cout << car;
    }
}
void BinaryFile::write_object(Car &car)
{
    file << car;
}
void BinaryFile::read_object(Car &car)
{
    file >> car;
}

int BinaryFile::find_car_by_real_year(int year)
{
    Car car;
    int quantity = 0;

    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    file.seekg(0, std::ios::beg);

    while (length != file.tellg())
    {
        file >> car;
        if (car.get_year_of_release() == year)
            quantity++;
    }
    return quantity;
}
