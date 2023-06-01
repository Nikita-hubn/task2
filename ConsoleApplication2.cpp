#include <iostream>
#include <ostream>
#include "anthill.h"

void print_menu();
void set_exctracted(task2::Anthill&);
void set_percent(task2::Anthill&);
void set_destroyed_pests(task2::Anthill&);
void extract_meal(task2::Anthill&);
void eat(task2::Anthill&);
void increase(task2::Anthill&);
void destroy(task2::Anthill&);
void add_pests(task2::Anthill&);

int main(int argc, char* argv[])
{
    std::cout << "Welcome to muraveinic" << std::endl;
    std::cout << "Enter your data" << std::endl;
    int larvas_start_count, workers_start_count, police_start_count, soldiers_start_count, pests, meal, larvas_create_count;
    std::cout << "Initial number of larvae-> ";
    std::cin >> larvas_start_count;
    std::cout << "Initial number of workers -> ";
    std::cin >> workers_start_count;
    std::cout << "Initial number of police officers -> ";
    std::cin >> police_start_count;
    std::cout << "Initial number of soldiers-> ";
    std::cin >> soldiers_start_count;
    std::cout << "Initial number of pests -> ";
    std::cin >> pests;
    std::cout << "Initial amount of food -> ";
    std::cin >> meal;
    std::cout << "Number of larvae born by one uterus -> ";
    std::cin >> larvas_create_count;

    task2::Anthill anthill{ larvas_start_count,
        workers_start_count,
        police_start_count,
        soldiers_start_count,
        pests,
        meal,
        larvas_create_count };

    bool end = false;
    while (!end)
    {
        print_menu();
        int number = 0;
        std::cout << std::endl;
        std::cout << "Enter the action number: ";
        std::cin >> number;
        switch (number)
        {
        case 1:
            set_exctracted(anthill);
            break;
        case 2:
            set_percent(anthill);
            break;
        case 3:
            set_destroyed_pests(anthill);
            break;
        case 4:
            anthill.print_anthill_info();
            break;
        case 5:
            extract_meal(anthill);
            break;
        case 6:
            eat(anthill);
            break;
        case 7:
            increase(anthill);
            break;
        case 8:
            destroy(anthill);
            break;
        case 9:
            add_pests(anthill);
            break;
        case 10:
            anthill.reborn_last_larva();
            std::cout << "The last larva was successfully reborn" << std::endl;
            break;
        case 11:
            anthill.create_new_larvas();
            std::cout << "In the anthill appeared " << anthill.get_mother().get_larvas_count() << "new larvae" << std::endl;
            break;
        case 12:
            end = true;
            break;
        default:
            std::cerr << "Invalid action number entered" << std::endl;
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}


void print_menu()
{
    std::cout << "Proposed actions:" << std::endl;
    std::cout << "1. Set the values of extracted food for workers;" << std::endl;
    std::cout << "2. Set the percentage of food increase for police officers;" << std::endl;
    std::cout << "3. Set the value of the number of pests destroyed for soldiers;" << std::endl;
    std::cout << "4. Get information about the anthill;" << std::endl;
    std::cout << "5. Get food;" << std::endl;
    std::cout << "6. Eat for everyone;" << std::endl;
    std::cout << "7. Increase the total amount of food;" << std::endl;
    std::cout << "8. Destroy the number of pests;" << std::endl;
    std::cout << "9. Add the number of pests;" << std::endl;
    std::cout << "10. Translate the last larva;" << std::endl;
    std::cout << "11. Force the uterus to give birth to new larvae;" << std::endl;
    std::cout << "12. Get out of the anthill;" << std::endl;
}

void set_exctracted(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the amount of food produced: ";
    std::cin >> count;
    ant.set_extracted_for_workers(count);
    std::cout << "Successfully" << std::endl;
}

void set_percent(task2::Anthill& ant)
{
    int percent = 0;
    std::cout << "Enter the percentage of food increase: ";
    std::cin >> percent;
    ant.set_percents_for_policemans(percent);
    std::cout << "Successfully" << std::endl;
}

void set_destroyed_pests(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the number of pests to be destroyed: ";
    std::cin >> count;
    ant.set_pests_for_soldiers(count);
    std::cout << "Successfully" << std::endl;
}

void extract_meal(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the number of workers who will get food to the anthill: ";
    std::cin >> count;
    try
    {
        ant.extract_meal(count);
        std::cout << "The food was obtained successfully" << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << "error " << msg << std::endl;
    }
}

void eat(task2::Anthill& ant)
{
    try
    {
        ant.eat_together();
        std::cout << "The eating process was successful. Food balance: " << ant.get_meal() << std::endl;
    }
    catch (const char* msg)
    {
        std::cout << msg << std::endl;
    }
}

void increase(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the number of police officers who will increase the amount of food as a percentage in the anthill:";
    std::cin >> count;
    try
    {
        ant.increase_meal(count);
        std::cout << "The food was increased successfully. Current amount of food:" << ant.get_meal() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << "Ошибка: " << msg << std::endl;
    }
}

void destroy(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the number of soldiers who destroy the pests: ";
    std::cin >> count;
    try
    {
        ant.destroy_pests(count);
        std::cout << "The pests were destroyed successfully. There are no pests left: " << ant.get_pests() << std::endl;
    }
    catch (const char* msg)
    {
        std::cerr << "eror: " << msg << std::endl;
    }
}

void add_pests(task2::Anthill& ant)
{
    int count = 0;
    std::cout << "Enter the number of pests: ";
    std::cin >> count;
    ant.create_pests(count);
    std::cout << "The pests were added successfully. There are no pests left: " << ant.get_pests() << std::endl;
}

