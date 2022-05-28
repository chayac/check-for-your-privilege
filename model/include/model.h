#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class Model {
    public:
        struct Sample {
            bool male = false;
            bool age_25_to_34 = false;
            bool white = false;
            // bool bipoc;
            bool highest_income = false;
            bool below_poverty = false;
            bool nonfamily_household = false;
            bool bach_degree_or_higher = false;
            bool rent_burdened = false;
            static bool deepEquals(const Model::Sample* lhs, const Model::Sample *rhs);
            bool deepEquals(const Model::Sample *rhs) const;
        };
    protected:
        const int DEFAULT_NUM_SAMPLES = 1000;
        int numSamples;
        vector<Sample*> samples;
        vector<Sample*> samples_highest_income;
        vector<Sample*> samples_below_poverty;
        vector<Sample*> samples_rent_burdened;
        default_random_engine generator;
        Sample* highestIncomeTemplate;
        Sample* belowPovertyTemplate;
        Sample* rentBurdenedTemplate;
        vector<Sample> altSample;
        void createSampleTemplates();
        void initialize();
    public:
        Model();
        Model(int n);
        ~Model();
        bool bernoulli(const float p);
        float p_male() const {
            return 0.5;
        };
        float p_25_to_34() const {
            return 0.5;
        };
        float p_white() const {
            return 0.5;
        };
        float p_bipoc() const {
            return 0.5;
        };
        float p_highest_income() const {
            return 0.5;
        };
        float p_below_poverty() const {
            return 0.5;
        };
        float p_nonfamily_households() const {
            return 0.5;
        };
        float p_bach_degree_or_higher() const {
            return 0.5;
        };
        float p_rent_burdened() const {
            return 0.5;
        };
        Sample* genSample();
        void genSamples();
        void genAltSamples();
        vector<Sample*>& getSamples();
        vector<Sample>& getAltSamples() {
            return altSample;
        }
        Sample* genSampleHighestIncome();
        Sample* genSampleBelowPoverty();
        Sample* genSampleRentBurdened();
        vector<Sample*>& getSamplesHighestIncome();
        vector<Sample*>& getSamplesBelowPoverty();
        vector<Sample*>& getSamplesRentBurdened();
        int getCountHighestIncome(const Sample* comparison) const;
        int getCountBelowPoverty(const Sample* comparison) const;
        int getCountRentBurdened(const Sample* comparison) const;
        float getProbHighestIncome(const Sample* comparison) const;
        float getProbBelowPoverty(const Sample* comparison) const;
        float getProbRentBurdened(const Sample* comparison) const;
        void setSampleDemographics(Sample* sample, bool male, bool age_25_to_34, bool white, bool nonfamily_household, bool bach_degree_or_higher);
        
};