#include "model.h"
#include <random>

using namespace std;

bool Model::Sample::deepEquals(const Model::Sample* lhs, const Model::Sample *rhs) {
    if (lhs->male != rhs->male || lhs->age_25_to_34 != rhs->age_25_to_34 || lhs->white != rhs->white || lhs->highest_income != rhs->highest_income || lhs->below_poverty != rhs->below_poverty || lhs->nonfamily_household != rhs->nonfamily_household || lhs->bach_degree_or_higher != rhs->bach_degree_or_higher || lhs->rent_burdened != rhs->rent_burdened ) {
        return false;
    } else {
        return true;
    }
}

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
    // sample->bipoc = bernoulli(p_bipoc());
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

Model::Sample* Model::genSampleHighestIncome() {
    Model::Sample* sample = new Model::Sample();
    sample->male = bernoulli(p_male());
    sample->age_25_to_34 = bernoulli(p_25_to_34());
    sample->white = bernoulli(p_white());
    // sample->bipoc = bernoulli(p_bipoc());
    sample->highest_income = bernoulli(p_highest_income());
    sample->nonfamily_household = bernoulli(p_nonfamily_households());
    sample->bach_degree_or_higher = bernoulli(p_bach_degree_or_higher());
    sample->below_poverty = false;
    sample->rent_burdened = false;
    return sample;
}

Model::Sample* Model::genSampleBelowPoverty() {
    Model::Sample* sample = new Model::Sample();
    sample->male = bernoulli(p_male());
    sample->age_25_to_34 = bernoulli(p_25_to_34());
    sample->white = bernoulli(p_white());
    // sample->bipoc = bernoulli(p_bipoc());
    sample->below_poverty = bernoulli(p_below_poverty());
    sample->nonfamily_household = bernoulli(p_nonfamily_households());
    sample->bach_degree_or_higher = bernoulli(p_bach_degree_or_higher());
    sample->highest_income = false;
    sample->rent_burdened = false;
    return sample;
}

Model::Sample* Model::genSampleRentBurdened() {
    Model::Sample* sample = new Model::Sample();
    sample->male = bernoulli(p_male());
    sample->age_25_to_34 = bernoulli(p_25_to_34());
    sample->white = bernoulli(p_white());
    // sample->bipoc = bernoulli(p_bipoc());
    sample->nonfamily_household = bernoulli(p_nonfamily_households());
    sample->bach_degree_or_higher = bernoulli(p_bach_degree_or_higher());
    sample->rent_burdened = bernoulli(p_rent_burdened());
    sample->highest_income = false;
    sample->rent_burdened = false;
    return sample;
}

void Model::genSamples() {
    for (int i = 0; i < numSamples; i++) {
        samples.push_back(genSample());
    }
    cout << "number of samples: " << samples.size() << endl;
}

vector<Model::Sample*>& Model::getSamples() {
    if (samples.size() < numSamples) {
        genSamples();
    }
    return samples;
}

vector<Model::Sample*>& Model::getSamplesHighestIncome() {
    if (samples_highest_income.size() < numSamples) {
        for (int i = 0; i < numSamples; i++) {
            samples_highest_income.push_back(genSampleHighestIncome());
        }
    }
    return samples_highest_income;
}

vector<Model::Sample*>& Model::getSamplesBelowPoverty() {
    if (samples_below_poverty.size() < numSamples) {
        for (int i = 0; i < numSamples; i++) {
            samples_below_poverty.push_back(genSampleBelowPoverty());
        }
    }
    return samples_below_poverty;
}

vector<Model::Sample*>& Model::getSamplesRentBurdened() {
    if (samples_rent_burdened.size() < numSamples) {
        for (int i = 0; i < numSamples; i++) {
            samples_rent_burdened.push_back(genSampleRentBurdened());
        }
    }
    return samples_rent_burdened;
}

int Model::getCountHighestIncome(Model::Sample* comparison) {
    int count = 0;
    for (const auto samp : samples_highest_income) {
        if (Model::Sample::deepEquals(samp, comparison)) {
            count++;
        }
    }
    return count;
}
int Model::getCountBelowPoverty(Model::Sample* comparison) {
    return 0;
}
int Model::getCountRentBurdened(Model::Sample* comparison) {
    return 0;
}