#include "model.h"
#include <random>
#include <cassert>

using namespace std;

bool Model::bernoulli(const float p) {
    bernoulli_distribution distribution(p);
    return distribution(generator);
}

Model::Model(int n) {
    numSamples = n;
    generator.seed(random_device{}());
}

void Model::genSamples() {
    float p_m = p_male();
    float p_age = p_25_to_34();
    float p_w = p_white();
    float p_inc = p_highest_income();
    float p_nf = p_nonfamily_households();
    float p_deg = p_bach_degree_or_higher();
    float p_rent = p_rent_burdened();
    float p_pov = p_below_poverty();
    
    for (int i = 0; i < numSamples; i++) {
        auto sample = make_shared<Sample>();
        sample->male = bernoulli(p_m);
        sample->age_25_to_34 = bernoulli(p_age);
        sample->white = bernoulli(p_w);
        sample->highest_income = bernoulli(p_inc);
        sample->below_poverty = bernoulli(p_pov);
        sample->nonfamily_household = bernoulli(p_nf);
        sample->bach_degree_or_higher = bernoulli(p_deg);
        sample->rent_burdened = bernoulli(p_rent);
        samples.push_back(sample);
        if (sample->highest_income && !sample->below_poverty) {
            samples_highest_income.push_back(sample);
        }
        if (!sample->highest_income && sample->below_poverty) {
            samples_below_poverty.push_back(sample);
        }
        if (sample->rent_burdened) {
            samples_rent_burdened.push_back(sample);
        }
    }
}
