#include "model.h"
#include <random>

using namespace std;

bool Model::bernoulli(const float p) {
    bernoulli_distribution distribution(0.5);
    return distribution(generator);
}

Model::Model() {
    cout << "Create model" << endl;
    numSamples = DEFAULT_NUM_SAMPLES;
    generator.seed(random_device{}());
}

Model::Model(int n) {
    cout << "Create model with n samples" << endl;
    numSamples = n;
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
    // cout << "p_rent_burdened: " << p_rent << endl;
    
    for (int i = 0; i < numSamples; i++) {
        // samples.push_back(genSample());
        // Sample* sample = new Sample();
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
    // cout << "number of samples: " << samples.size() << endl;

    // for (const auto s : samples) {
    //     if (s->highest_income && !s->below_poverty) {
    //         samples_highest_income.push_back(s);
    //     }
    //     if (!s->highest_income && s->below_poverty) {
    //         samples_below_poverty.push_back(s);
    //     }
    //     if (s->rent_burdened) {
    //         samples_rent_burdened.push_back(s);
    //     }
    // }
    cout << "samples: all: " << samples.size() << 
    ", highest income: " << samples_highest_income.size() <<
    ", below poverty: " << samples_below_poverty.size() <<
    ", rent burdened: " << samples_rent_burdened.size() << endl;
}
