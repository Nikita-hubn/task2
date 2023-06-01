#ifndef INSECTS_H
#define INSECTS_H

#include "base_insect.h"

namespace task2
{
    /**
     * ������������, ������� ��������� ��� �������, � ������� ����������� �������
     */
    enum class INSECT_TYPE
    {
        WORKER = 0,
        POLICE = 1,
        SOLDIER = 2
    };

    /**
     * ����� ������� �������
     */
    class Larva : public BaseInsect
    {
    protected:
        int meal_count;
    public:
        Larva();
        Larva(int meal);
        INSECT_TYPE reborn();
    };

    /**
     * ����� ������� - ��������
     */
    class Worker : public BaseInsect
    {
    private:
        int meal_extracted;
    public:
        Worker();
        Worker(int meal, int extracted);
        int get_meal_extracted();
        void set_meal_extracted(int extracted);
        void extract(int& all_meal);
    };

    /*
     * ����� ������� - ������������
     */
    class Police : public BaseInsect
    {
    private:
        int meal_percent;
    public:
        Police();
        Police(int meal, int percent);
        int get_meal_percent();
        void set_meal_percent(int percent);
        void increase(int& all_meal);
    };

    /**
     * ����� ������� - �������
     */
    class Soldier : public BaseInsect
    {
    private:
        int pest_destroyed_count;
    public:
        Soldier();
        Soldier(int meal, int count);
        int get_pest_count();
        void set_pest_count(int count);
        void destroy(int& all_pests);
    };

    /**
     * ����� ������� - �����
     */
    class Mother : public BaseInsect
    {
    private:
        int new_larvas_count;
    public:
        Mother();
        Mother(int meal, int count);
        int get_larvas_count();
        void set_larvas_count(int count);
    };
};

#endif
