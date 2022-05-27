#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

const std::string generateHelloString(const std::string & personName);

class Model {
    public:
        struct Sample {
            bool male;
            bool age_25_to_34;
            bool white;
            bool bipoc;
            bool highest_income;
            bool below_poverty;
            bool nonfamily_household;
            bool bach_degree_or_higher;
            bool rent_burdened;
        };
    protected:
        int numSamples;
        vector<Sample*> samples;
        default_random_engine generator;
    public:
        Model();
        Model(int n);
        ~Model();
        bool bernoulli(float p);
        float p_male() {
            return 0.5;
        };
        float p_25_to_34() {
            return 0.5;
        };
        float p_white() {
            return 0.5;
        };
        float p_bipoc() {
            return 0.5;
        };
        float p_highest_income() {
            return 0.5;
        };
        float p_below_poverty() {
            return 0.5;
        };
        float p_nonfamily_households() {
            return 0.5;
        };
        float p_bach_degree_or_higher() {
            return 0.5;
        };
        float p_rent_burdened() {
            return 0.5;
        };
        Sample* genSample();
        void genSamples();
        vector<Sample*>* getSamples();
        
};