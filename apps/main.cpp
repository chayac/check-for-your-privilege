#include <iostream>
#include "model.h"
#include "SeattleModel.h"

using namespace std;

void genBaseModel() {
    Model model(100000);
    model.genSamples();
    auto sInc = model.getSamplesHighestIncome();
    auto sPov = model.getSamplesBelowPoverty();
    auto sRent = model.getSamplesRentBurdened();
    int nInc = sInc.size();
    int nPov = sPov.size();
    int nRent = sRent.size();
    float nMaleInc = 0;
    float nNonmaleInc = 0;
    float nWhiteMaleInc = 0;
    float nNonwhiteNonmaleInc = 0;
    float nWhiteNonmaleInc = 0;
    for (auto s : sInc) {
        if (s->male) {
            nMaleInc++;
            if (s->white) {
                nWhiteMaleInc++;
            }
            continue;
        }
        nNonmaleInc++;
        if (s->white) {
            nWhiteNonmaleInc++;
        } else {
            nNonwhiteNonmaleInc++;
        }
    }
    // note that these don't equal 0.5!
    cout << "male: " << nMaleInc/nInc << endl;
    cout << "nonmale: " << nNonmaleInc/nInc << endl;
    cout << "white male: " << nWhiteMaleInc/nInc << endl;
    cout << "nonwhite nonmale: " << nNonwhiteNonmaleInc/nInc << endl;
    cout << "white nonmale: " << nWhiteMaleInc/nInc << endl;
}

void genSeattleModel() {
    SeattleModel model(100000);
    model.genSamples();
    auto sInc = model.getSamplesHighestIncome();
    auto sPov = model.getSamplesBelowPoverty();
    auto sRent = model.getSamplesRentBurdened();
    int nInc = sInc.size();
    int nPov = sPov.size();
    int nRent = sRent.size();
    float nMaleInc = 0;
    float nNonmaleInc = 0;
    float nWhiteMaleInc = 0;
    float nNonwhiteNonmaleInc = 0;
    float nWhiteNonmaleInc = 0;
    for (auto s : sInc) {
        if (s->male) {
            nMaleInc++;
            if (s->white) {
                nWhiteMaleInc++;
            }
            continue;
        }
        nNonmaleInc++;
        if (s->white) {
            nWhiteNonmaleInc++;
        } else {
            nNonwhiteNonmaleInc++;
        }
    }
    float pMaleInc = nMaleInc/nInc;
    float pNonmaleInc = nNonmaleInc/nInc;
    float pWhiteMaleInc = nWhiteMaleInc/nInc;
    float pNonwhiteNonmaleInc = nNonwhiteNonmaleInc/nInc;
    float pWhiteNonmaleInc = nWhiteNonmaleInc/nInc;
    cout << "male: " << nMaleInc/nInc << endl;
    cout << "nonmale: " << nNonmaleInc/nInc << endl;
    cout << "white male: " << nWhiteMaleInc/nInc << endl;
    cout << "nonwhite nonmale: " << nNonwhiteNonmaleInc/nInc << endl;
    cout << "white nonmale: " << nWhiteMaleInc/nInc << endl;
    cout << "male vs. nonmale: " << pMaleInc/pNonmaleInc << endl;
    cout << "whitemale vs male: " << pWhiteMaleInc/pMaleInc << endl;

    // fairness through awareness: probability of outcome conditioned on demographic
    // should be equal to outcome conditioned on another demographic
    // P(R=1|A=a) = P(R=1|A=b
    cout << 
}

int main(int, char**) {
    genBaseModel();
    genSeattleModel();

    return 0;
}