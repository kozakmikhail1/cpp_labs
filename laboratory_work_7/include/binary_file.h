#include "car.h"

class BinaryFile
{
    std::string name;
    std::fstream file;

  public:
    BinaryFile();
    explicit BinaryFile(std::string name);
    ~BinaryFile();

    bool open();
    bool is_open();
    bool is_empty();
    void close();

    void show();
    void write_object(Car &car);
    void read_object(Car &car);
    int find_car_by_real_year(int year);
};
