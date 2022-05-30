#include <iostream>
#include "model.h"
#include "SeattleModel.h"
#include "FirstHillModel.h"
#include "CentralAreaModel.h"
#include <cassert>

using namespace std;

void genSeparateModels() {
    int n = 1000000;
    CentralAreaModel model(n);
    // SeattleModel model(n);
    model.genSamples();
    model.genSamplesHighestIncome();
    model.genSamplesBelowPoverty();
    model.genSamplesRentBurdened();

    auto sInc = model.getSamplesHighestIncome();
    auto sPov = model.getSamplesBelowPoverty();
    auto sRent = model.getSamplesRentBurdened();

    assert(sInc.size() == n);

    // fairness through awareness: probability of outcome conditioned on demographic
    // should be equal to outcome conditioned on another demographic
    // P(R=1|A=a) = P(R=1|A=b)

    // Income

    float nPriv = 0.0;
    float nOutPriv = 0.0;
    float nNonPriv = 0.0;
    float nOutNonPriv = 0.0;

    for (auto s : sInc) {
        if (s->white) {
            nPriv++;
            if (s->highest_income) {
                nOutPriv++;
            }
        } else if (s->bipoc) {
            nNonPriv++;
            if (s->highest_income) {
                nOutNonPriv++;
            }
        }
    }
    cout << "High income: " << endl;
    cout << "P(outcome | priv): " << nOutPriv/nPriv << endl;
    cout << "P(outcome | nonpriv): " << nOutNonPriv/nNonPriv << endl;
    cout << "Ratio nonpriv to priv: " << (nOutNonPriv/nNonPriv) / (nOutPriv/nPriv) << endl;


    // Poverty
    
    nPriv = 0.0;
    nOutPriv = 0.0;
    nNonPriv = 0.0;
    nOutNonPriv = 0.0;

    for (auto s : sPov) {
        if (s->white) {
            nPriv++;
            if (s->below_poverty) {
                nOutPriv++;
            }
        } else if (s->bipoc) {
            nNonPriv++;
            if (s->below_poverty) {
                nOutNonPriv++;
            }
        }
    }
    cout << "Below poverty: " << endl;
    cout << "P(outcome | priv): " << nOutPriv/nPriv << endl;
    cout << "P(outcome | nonpriv): " << nOutNonPriv/nNonPriv << endl;
    cout << "Ratio nonpriv to priv: " << (nOutNonPriv/nNonPriv) / (nOutPriv/nPriv) << endl;


    // Rent burdened

    nPriv = 0.0;
    nOutPriv = 0.0;
    nNonPriv = 0.0;
    nOutNonPriv = 0.0;

    for (auto s : sRent) {
        if (s->white) {
            nPriv++;
            if (s->rent_burdened) {
                nOutPriv++;
            }
        } else if (s->bipoc) {
            nNonPriv++;
            if (s->rent_burdened) {
                nOutNonPriv++;
            }
        }
    }
    cout << "Rent burdened: " << endl;
    cout << "P(outcome | priv): " << nOutPriv/nPriv << endl;
    cout << "P(outcome | nonpriv): " << nOutNonPriv/nNonPriv << endl;
    cout << "Ratio nonpriv to priv: " << (nOutNonPriv/nNonPriv) / (nOutPriv/nPriv) << endl;

}


int main(int, char**) {
    genSeparateModels();
    string filePath = "/Users/chaya/workplace/check-for-your-privilege/samples.json";
    return 0;
}