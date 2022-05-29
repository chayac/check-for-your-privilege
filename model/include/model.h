#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Sample.h"

using namespace std;

class Model {
    protected:
        int numSamples;
        vector<shared_ptr<Sample>> samples;
        vector<shared_ptr<Sample>> samples_highest_income;
        vector<shared_ptr<Sample>> samples_below_poverty;
        vector<shared_ptr<Sample>> samples_rent_burdened;
        default_random_engine generator;
    public:
        Model(int n);
        bool bernoulli(const float p);
        virtual float p_male() const {
            return 0.5;
        };
        virtual float p_25_to_34() const {
            return 0.5;
        };
        virtual float p_white() const {
            return 0.5;
        };
        virtual float p_bipoc() const {
            return 0.5;
        };
        virtual float p_highest_income() const {
            return 0.5;
        };
        virtual float p_below_poverty() const {
            return 0.5;
        };
        virtual float p_nonfamily_households() const {
            return 0.5;
        };
        virtual float p_bach_degree_or_higher() const {
            return 0.5;
        };
        virtual float p_rent_burdened() const {
            return 0.5;
        };
        virtual void genSamples();
        vector<shared_ptr<Sample>> getSamples() {
            return samples;
        };
        vector<shared_ptr<Sample>> getSamplesHighestIncome() {
            return samples_highest_income;
        };
        vector<shared_ptr<Sample>> getSamplesBelowPoverty() {
            return samples_below_poverty;
        };
        vector<shared_ptr<Sample>> getSamplesRentBurdened() {
            return samples_rent_burdened;
        };
};