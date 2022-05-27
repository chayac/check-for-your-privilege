#include "model.h"
#include <random>

using namespace std;

bool Model::bernoulli(float p) {
    bernoulli_distribution distribution(0.5);
    return distribution(generator);
}

Model::Model() {
    cout << "Create model" << endl;
    numSamples = 1000;
    genSamples();
}

Model::Model(int n) {
    cout << "Create model with n samples" << endl;
    numSamples = n;
    genSamples();
}

Model::~Model() {
    while(!samples.empty()) {
        delete samples.back();
        samples.pop_back();
    }
}

Model::Sample* Model::genSample() {
    Model::Sample* sample = new Model::Sample();
    sample->male = bernoulli(p_male());
    sample->age_25_to_34 = bernoulli(p_25_to_34());
    sample->white = bernoulli(p_white());
    sample->bipoc = bernoulli(p_bipoc());
    sample->highest_income = bernoulli(p_highest_income());
    if (sample->highest_income) {
        sample->below_poverty = false;
    } else {
        sample->below_poverty = bernoulli(p_below_poverty());
    }
    sample->nonfamily_household = bernoulli(p_nonfamily_households());
    sample->bach_degree_or_higher = bernoulli(p_bach_degree_or_higher());
    sample->rent_burdened = bernoulli(p_rent_burdened());
    return sample;
}

void Model::genSamples() {
    for (int i = 0; i < numSamples; i++) {
        samples.push_back(genSample());
    }
    cout << "number of samples: " << samples.size() << endl;
}

vector<Model::Sample*>* Model::getSamples() {
    if (samples.size() < numSamples) {
        genSamples();
    }
    return &samples;
}