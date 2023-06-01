#ifndef ANTHILL_H
#define ANTHILL_H

#include <vector>
#include "insects.h"

namespace task2
{
    class Anthill
    {
    private:
        // ��������� ������� � �����������
        std::vector<Larva> larvas;

        // ��������� ������� � �����������
        std::vector<Worker> workers;

        // ��������� ����������� � �����������
        std::vector<Police> policemans;

        // ��������� ������ � �����������
        std::vector<Soldier> soldiers;

        // �����
        Mother mother;
        // ���������� ���
        int meal;
        // ���������� ����������
        int pests;

        // ����, ������������ ������� ������� � �������� ��������
        bool meal_error_flag = false;
        // ��������� ������� ��� ����������� �������� �������� ������������� ���� ��������
        template<typename T> void eat_larva_childs(std::vector<T> insects);
    public:
        const static int larva_meal = 1;
        const static int worker_meal = 3;
        const static int police_meal = 5;
        const static int soldier_meal = 8;
        const static int mother_meal = 10;

        Anthill();
        Anthill(int larvas_start_count,
            int workers_start_count,
            int police_start_count,
            int soldiers_start_count,
            int pests,
            int meal,
            int larvas_create_count);

        void print_anthill_info();

        int get_meal();
        int get_pests();
        Mother get_mother();

        void set_extracted_for_workers(int extracted);
        void set_percents_for_policemans(int percent);
        void set_pests_for_soldiers(int count);

        std::vector<Larva>& get_larvas();
        std::vector<Worker>& get_workers();
        std::vector<Police>& get_policemans();
        std::vector<Soldier>& get_soldiers();

        /**
         * ������ ��� ������������ ����������� �������
         */
        void extract_meal(int workers_count);

        /**
         * �������� ����
         */
        void eat_together();

        /**
         * ��������� ����� ���
         */
        void increase_meal(int police_count);

        /**
         * ���������� ������������ ���������� ����������
         */
        void destroy_pests(int soldier_count);

        /**
         * �������� ����� ����������
         */
        void create_pests(int pests_count);

        /**
         * ��������� ��������� ������� ������������
         */
        void reborn_last_larva();

        /**
         * ��������� ����� ��������� ����� �������
         */
        void create_new_larvas();
    };
};
#endif
