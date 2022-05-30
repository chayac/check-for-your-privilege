#pragma once

#include "model.h"

using namespace std;

// ACS 2020 5Y for Seattle city
class SeattleModel : public Model {
    public:
        SeattleModel(int n) : Model{n} {};
        float p_male() const {
            // DP05: total population, male 18 years and older
            return 0.506;
        };
        float p_25_to_34() const {
            // DP05: total population, age 25-34
            return 0.247;
        };
        float p_white() const {
            // DP05: total population, one race, white
            return 0.713;
        };
        float p_bipoc() const {
            // DP05: total population, race alone or in combination with others
            return 0.118;
        };
        float p_highest_income() const {
            // DP03: household income and benefits over $200k
            return 0.196;
        };
        float p_below_poverty() const {
            // DP03: people over 18, income in last 12 months is below poverty line
            return 0.103;
        };
        float p_nonfamily_households() const {
            // DT B11016  HOUSEHOLD TYPE BY HOUSEHOLD SIZE
            return 0.557;
        };
        float p_bach_degree_or_higher() const {
            // DP02: Bachelor's degree or higher, population 25 years and over
            return 0.65;
        };
        float p_rent_burdened() const {
            // DP04: GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI) 35% or more
            return 0.339;
        };
};