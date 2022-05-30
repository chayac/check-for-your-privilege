#include "gtest/gtest.h"
#include "model.h"
#include "SeattleModel.h"
#include "Sample.h"
#include <algorithm>
#include <random>


TEST(ModelTests, testBernoulli) {
    Model model(1);
    int it = 1000;
    float p = 0.1;
    int count = 0;
    while (p < 0.9) {
        p += 0.1;
        count = 0;
        for (int i = 0; i < it; i++) {
            if (model.bernoulli(p)) {
                count++;
            }
        }
        cout << "p " << p << ": " << 1.0*count/it << endl;
    }
    
    ASSERT_NEAR(1.0*count/it, p, 0.1);
}

TEST(SeattleModelTests, testBernoulli) {
    SeattleModel model(1);
    int it = 1000;
    float p = 0.1;
    int count = 0;
    while (p < 0.9) {
        p += 0.1;
        count = 0;
        for (int i = 0; i < it; i++) {
            if (model.bernoulli(p)) {
                count++;
            }
        }
        cout << "p " << p << ": " << 1.0*count/it << endl;
    }
    
    ASSERT_NEAR(1.0*count/it, p, 0.1);
}

bool IsMale(shared_ptr<Sample> i) {
    return i->male;
}

TEST(ModelTests, testSamplesBase) {
    Model model(10000);
    model.genSamples();
    model.genSamplesHighestIncome();
    model.genSamplesBelowPoverty();
    model.genSamplesRentBurdened();
    auto samples = model.getSamples();
    auto s_inc = model.getSamplesHighestIncome();
    auto s_pov = model.getSamplesBelowPoverty();
    auto s_rent = model.getSamplesRentBurdened();
    ASSERT_NE(samples.size(), 0);
    ASSERT_NE(s_inc.size(), 0);
    ASSERT_NE(s_pov.size(), 0);
    ASSERT_NE(s_rent.size(), 0);
    cout << "Samples base: all: " << samples.size() <<
    ", inc: " << s_inc.size() <<
    ", pov: " << s_pov.size() <<
    ", rent: " << s_rent.size() << endl;
    int male_cnt = count_if(samples.begin(), samples.end(), IsMale);
    cout << "Male count: " << male_cnt << endl;
    ASSERT_NE(male_cnt, 0);
}

TEST(SeattleModelTests, testSamplesSeattle) {
    SeattleModel model(10000);
    model.genSamples();
    model.genSamplesHighestIncome();
    model.genSamplesBelowPoverty();
    model.genSamplesRentBurdened();
    auto samples = model.getSamples();
    auto s_inc = model.getSamplesHighestIncome();
    auto s_pov = model.getSamplesBelowPoverty();
    auto s_rent = model.getSamplesRentBurdened();
    ASSERT_NE(samples.size(), 0);
    ASSERT_NE(s_inc.size(), 0);
    ASSERT_NE(s_pov.size(), 0);
    ASSERT_NE(s_rent.size(), 0);
    cout << "Samples Seattle: all: " << samples.size() <<
    ", inc: " << s_inc.size() <<
    ", pov: " << s_pov.size() <<
    ", rent: " << s_rent.size() << endl;
    int male_cnt = count_if(samples.begin(), samples.end(), IsMale);
    cout << "Male count: " << male_cnt << endl;
    ASSERT_NE(male_cnt, 0);
}

TEST(ModelTests, testCalcRentBurdenedBase) {
    Model model(10000);
    model.genSamplesRentBurdened();
    auto samples = model.getSamplesRentBurdened();
    int particles = samples.size();
    int nMale = 0;
    int nNonmale = 0;
    for (const auto s : samples) {
        if (s->male) {
            nMale++;
        } else {
            nNonmale++;
        }
    }
    ASSERT_GT(1.0*nMale/particles, 0);
    ASSERT_GT(1.0*nNonmale/particles, 0);
    cout << "base rent burdened: " << 1.0*nMale/particles << ", " << 1.0*nNonmale/particles << endl;
}

TEST(SeattleModelTests, testCalcRentBurdenedSeattle) {
    SeattleModel model(10000);
    model.genSamplesRentBurdened();
    auto samples = model.getSamplesRentBurdened();
    int particles = samples.size();
    int nMale = 0;
    int nNonmale = 0;
    for (const auto s : samples) {
        if (s->male) {
            nMale++;
        } else {
            nNonmale++;
        }
    }
    ASSERT_GT(1.0*nMale/particles, 0);
    ASSERT_GT(1.0*nNonmale/particles, 0);
    cout << "Seattle rent burdened: " << 1.0*nMale/particles << ", " << 1.0*nNonmale/particles << endl;
}

TEST(ModelTests, testJsonExport) {
    Model model(10);
    model.genSamples();
    model.exportSamplesJson("");
}