#include "base_insect.h"
using namespace task2;

BaseInsect::BaseInsect() {}

BaseInsect::BaseInsect(int meal) : meal_count(meal) {}

int BaseInsect::get_meal_count()
{
    return meal_count;
}

void BaseInsect::set_meal_count(int count)
{
    meal_count = count;
}

void BaseInsect::eat(int& all_meat)
{
    if (all_meat - meal_count < 0)
    {
        throw "The food ran out in the anthill. Now the ant has problems...";
    }
    all_meat -= meal_count;
}