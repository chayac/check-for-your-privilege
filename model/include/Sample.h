#pragma once
#include "json.hpp"

using json = nlohmann::json;

struct Sample {
    bool male = false;
    bool age_25_to_34 = false;
    bool white = false;
    bool bipoc = false;
    bool highest_income = false;
    bool below_poverty = false;
    bool nonfamily_household = false;
    bool bach_degree_or_higher = false;
    bool rent_burdened = false;
    static bool deepEquals(const Sample* lhs, const Sample* rhs) {
        if (lhs->male != rhs->male || lhs->age_25_to_34 != rhs->age_25_to_34 || lhs->white != rhs->white || lhs->highest_income != rhs->highest_income || lhs->below_poverty != rhs->below_poverty || lhs->nonfamily_household != rhs->nonfamily_household || lhs->bach_degree_or_higher != rhs->bach_degree_or_higher || lhs->rent_burdened != rhs->rent_burdened ) {
            return false;
        } else {
            return true;
        }
    }
};