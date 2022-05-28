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

bool Model::bernoulli(const float p) {
    bernoulli_distribution distribution(0.5);
    return distribution(generator);
}

void Model::createSampleTemplates() {
    highestIncomeTemplate = new Model::Sample();
    highestIncomeTemplate->highest_income = true;

    belowPovertyTemplate = new Model::Sample();
    belowPovertyTemplate->below_poverty = true;

    rentBurdenedTemplate = new Model::Sample();
    rentBurdenedTemplate->rent_burdened = true;
}

Model::Model() {
    cout << "Create model" << endl;
    numSamples = DEFAULT_NUM_SAMPLES;
    genSamples();
    initialize();
}

void Model::initialize() {
    createSampleTemplates();
    for (int i = 0; i < numSamples; i++) {
        samples_highest_income.push_back(genSampleHighestIncome());
        samples_below_poverty.push_back(genSampleBelowPoverty());
        samples_rent_burdened.push_back(genSampleRentBurdened());
    }
}

Model::Model(int n) {
    cout << "Create model with n samples" << endl;
    numSamples = n;
    genSamples();
    initialize();
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

void Model::genAltSamples() {
    for (int i = 0; i < numSamples; i++) {
        Model::Sample sample;
    sample.male = bernoulli(p_male());
    sample.age_25_to_34 = bernoulli(p_25_to_34());
    sample.white = bernoulli(p_white());
    // sample->bipoc = bernoulli(p_bipoc());
    sample.highest_income = bernoulli(p_highest_income());
    // if (sample.highest_income) {
    //     sample.below_poverty = false;
    // } else {
        sample.below_poverty = bernoulli(p_below_poverty());
    // }
    sample.nonfamily_household = bernoulli(p_nonfamily_households());
    sample.bach_degree_or_higher = bernoulli(p_bach_degree_or_higher());
    sample.rent_burdened = bernoulli(p_rent_burdened());
    }
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

int Model::getCountHighestIncome(const Model::Sample* comparison) const {
    int count = 0;
    for (const auto samp : samples_highest_income) {
        if (Model::Sample::deepEquals(samp, comparison)) {
            count++;
        }
    }
    return count;
}
int Model::getCountBelowPoverty(const Model::Sample* comparison) const {
    int count = 0;
    for (const auto samp : samples_below_poverty) {
        if (Model::Sample::deepEquals(samp, comparison)) {
            count++;
        }
    }
    return count;
}
int Model::getCountRentBurdened(const Model::Sample* comparison) const {
    int count = 0;
    for (const auto samp : samples_rent_burdened) {
        if (Model::Sample::deepEquals(samp, comparison)) {
            count++;
        }
    }
    return count;
}

void Model::setSampleDemographics(Sample* sample, bool male, bool age_25_to_34, bool white, bool nonfamily_household, bool bach_degree_or_higher) {
    sample->male = male;
    sample->age_25_to_34 = age_25_to_34;
    sample->white = white;
    sample->nonfamily_household = nonfamily_household;
    sample->bach_degree_or_higher = bach_degree_or_higher;
}

float Model::getProbHighestIncome(const Model::Sample* comparison) const {
    int count = 0;
    int condParticles = 0;
    for (const auto samp : samples) {
    // for (const auto samp : samples_below_poverty) {
        if (samp->highest_income) {
            condParticles++;
            if (Model::Sample::deepEquals(samp, comparison)) {
                count++;
            }
        }
    }
    return 1.0 * count / condParticles;
}
float Model::getProbBelowPoverty(const Model::Sample* comparison) const {
    int count = 0;
    int condParticles = 0;
    for (const auto samp : samples) {
    // for (const auto samp : samples_below_poverty) {
        if (samp->below_poverty) {
            condParticles++;
            if (Model::Sample::deepEquals(samp, comparison)) {
                count++;
            }
        }
    }
    return 1.0 * count / condParticles;
}
float Model::getProbRentBurdened(const Model::Sample* comparison) const {
    int count = 0;
    int condParticles = 0;
    for (const auto samp : samples) {
    // for (const auto samp : samples_below_poverty) {
        if (samp->rent_burdened) {
            condParticles++;
            if (Model::Sample::deepEquals(samp, comparison)) {
                count++;
            }
        }
    }
    return 1.0 * count / condParticles;
}