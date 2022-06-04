#pragma once

#include "model.h"

using namespace std;

// UVDA Central Area
// AC5Y2017 UVDA Profile
class CentralAreaModel : public Model {
    public:
        CentralAreaModel(int n) : Model{n} {};

        // using values from Seattle model
        float p_male() const { return 0.506; };
        float p_25_to_34() const { return 0.247; };

        float p_white() const {
            // PCT_NOTHISP_WHITE_ONE
            return 0.603;
        };
        float p_bipoc() const {
            // PCT_NOTHISP_BLACK_ONE
            // PCT_NOTHISP_AMIAK_ONE
            // PCT_NOTHISP_PI_ONE
            return 0.165;
        };
        float p_highest_income() const {
            // HH_INCOME_200_000_OR_MORE
            return 0.14;
        };
        float p_below_poverty() const {
            // PCT_POPULATION_UNDER_POVERTY
            return 0.136;
        };
        float p_nonfamily_households() const {
            // PCT_NON_FAM_HH
            return 0.605;
        };
        float p_bach_degree_or_higher() const {
            // PCT_BACHELOR_DEGREE_OR_HIGHER
            return 0.637;
        };
        float p_rent_burdened() const {
            // PERCENT_GRAPI_35_OR_MORE
            return 0.339;
        };
};