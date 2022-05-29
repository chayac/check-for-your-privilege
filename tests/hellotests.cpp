#include "gtest/gtest.h"
#include "model.h"
#include "SeattleModel.h"
#include "Sample.h"
#include <algorithm>
#include <random>

// TEST(ModelTests, testDefaultConstructor) {
//     Model model;
//     model.genSamples();
//     auto samples = model.getSamples();
//     EXPECT_EQ(samples.size(), 10000);
// }

bool IsMale(shared_ptr<Sample> i) {
    return i->male;
}

TEST(ModelTests, testSamplesBase) {
    Model model;
    model.genSamples();
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
    SeattleModel model;
    model.genSamples();
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

// bool IsMaleAlt(Sample i) {
//     return i.male;
// }

// TEST(ModelTests, testAltSamples) {
//     Model model;
//     model.genAltSamples();
//     vector<Sample> samples = model.getAltSamples();
//     int male_cnt = count_if(samples.begin(), samples.end(), IsMaleAlt);
//     cout << "Male count: " << male_cnt << endl;
//     ASSERT_NE(male_cnt, 0);
// }

// TEST(ModelTests, testProbHighestIncome) {
//     Model model;
//     model.genSamples();
//     Sample* sample = new Sample();
//     sample->highest_income=true;
//     sample->male=true;
//     float p = model.getProbHighestIncome(sample);
//     cout << "p male highest income: " << p << endl;
//     ASSERT_GT(p, 0);
//     sample->male=false;
//     p = model.getProbHighestIncome(sample);
//     cout << "p nonmale highest income: " << p << endl;
//     ASSERT_GT(p, 0);
// }

// TEST(ModelTests, testProbBelowPoverty) {
//     Model model;
//     model.genSamples();
//     Sample* sample = new Sample();
//     sample->below_poverty=true;
//     sample->male=true;
//     float p = model.getProbBelowPoverty(sample);
//     cout << "p male below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
//     sample->male=false;
//     p = model.getProbBelowPoverty(sample);
//     cout << "p nonmale below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
// }

// TEST(ModelTests, testProbRentBurdened) {
//     Model model;
//     model.genSamples();
//     Sample* sample = new Sample();
//     sample->rent_burdened=true;
//     sample->male=true;
//     float p = model.getProbRentBurdened(sample);
//     cout << "p male rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
//     sample->male=false;
//     p = model.getProbRentBurdened(sample);
//     cout << "p nonmale rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
// }

// TEST(ModelTests, testProbRentBurdenedSeattle) {
//     Model model;
//     model.genSamples();
//     Sample* sample = new Sample();
//     sample->rent_burdened=true;
//     sample->male=true;
//     float p = model.getProbRentBurdened(sample);
//     cout << "p male rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
//     sample->male=false;
//     p = model.getProbRentBurdened(sample);
//     cout << "p nonmale rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
//     SeattleModel seattle_model;
//     seattle_model.genSamples();
//     Sample* seattle_sample = new Sample();
//     seattle_sample->rent_burdened=true;
//     seattle_sample->male=true;
//     p = seattle_model.getProbRentBurdened(sample);
//     cout << "seattle p male rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
//     seattle_sample->male=false;
//     p = seattle_model.getProbRentBurdened(sample);
//     cout << "seattle p nonmale rent burdened: " << p << endl;
//     ASSERT_GT(p, 0);
// }

// TEST(ModelTests, testProbBelowPovertySeattle) {
//     Model model;
//     model.genSamples();
//     Sample* sample = new Sample();
//     sample->below_poverty=true;
//     sample->male=true;
//     float p = model.getProbBelowPoverty(sample);
//     cout << "p male below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
//     sample->male=false;
//     p = model.getProbBelowPoverty(sample);
//     cout << "p nonmale below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
//     SeattleModel seattle_model;
//     seattle_model.genSamples();
//     Sample* seattle_sample = new Sample();
//     seattle_sample->below_poverty=true;
//     seattle_sample->male=true;
//     p = seattle_model.getProbBelowPoverty(sample);
//     cout << "seattle p male below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
//     seattle_sample->male=false;
//     p = seattle_model.getProbBelowPoverty(sample);
//     cout << "seattle p nonmale below poverty: " << p << endl;
//     ASSERT_GT(p, 0);
// }

TEST(ModelTests, testCalcRentBurdenedBase) {
    Model model;
    model.genSamples();
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
    SeattleModel model;
    model.genSamples();
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