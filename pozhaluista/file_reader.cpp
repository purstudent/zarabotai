#include "file_reader.h"
#include "constants.h"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>

wastedtime convert(char* str)
{
    wastedtime result;
    char* context = NULL;
    char* str_number;
    str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minute = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.second = atoi(str_number);
    return result;
}

void read(const char* file_name, ethernet_protocole* array[], int& size)
{
    std::ifstream file;
    file.open(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            ethernet_protocole* item = new ethernet_protocole;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->end = convert(tmp_buffer);
            file >> item->received.number;
            file >> item->dispatched.number;
            file >> tmp_buffer;
            file.getline(item->path, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}