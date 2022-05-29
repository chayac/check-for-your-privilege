#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Sample.h"

using namespace std;

class Model {
    protected:
        const int DEFAULT_NUM_SAMPLES = 10000;
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
        virtual float p_rent_burdened() const {
            cout << "model rent burdened" << endl;
            return 0.5;
        };
        Sample* genSample();
        virtual void genSamples();
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
        virtual float getProbHighestIncome(const Sample* comparison) const;
        virtual float getProbBelowPoverty(const Sample* comparison) const;
        virtual float getProbRentBurdened(const Sample* comparison) const;
        void setSampleDemographics(Sample* sample, bool male, bool age_25_to_34, bool white, bool nonfamily_household, bool bach_degree_or_higher);
    private:
        Model(const Model&);
        Model& operator=(const Model&);
};