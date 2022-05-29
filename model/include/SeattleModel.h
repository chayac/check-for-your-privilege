#pragma once

#include "model.h"

using namespace std;

class SeattleModel : public Model {
    public:
        float p_male() const {
            // ACS 2020 5Y DP05: total population, male 18 years and older
            return 0.506;
        };
        float p_25_to_34() const {
            // ACS 2020 5Y DP05: total population, age 25-34
            return 0.247;
        };
        float p_white() const {
            // ACS 2020 5Y DP05: total population, one race, white
            return 0.713;
        };
        float p_highest_income() const {
            // ACS 2020 5Y DP03: household income and benefits over $200k
            return 0.196;
        };
        float p_below_poverty() const {
            // ACS 2020 5Y DP03: people over 18, income in last 12 months is below poverty line
            return 0.103;
        };
        float p_nonfamily_households() const {
            // ACSDT5Y2020	B11016  HOUSEHOLD TYPE BY HOUSEHOLD SIZE
            return 0.557;
        };
        float p_bach_degree_or_higher() const {
            // ACSDP5Y2020 DP02 Bachelor's degree or higher, population 25 years and over
            return 0.65;
        };
        float p_rent_burdened() const {
            // ACSDP5Y2020	DP04 GROSS RENT AS A PERCENTAGE OF HOUSEHOLD INCOME (GRAPI) 35% or more
            return 0.339;
        };
};