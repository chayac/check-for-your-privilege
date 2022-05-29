#include "gtest/gtest.h"
#include "model.h"
#include "SeattleModel.h"
#include <algorithm>
#include <random>

TEST(ModelTests, testDefaultConstructor) {
    Model model;
    Model::Sample* sample = model.genSample();
    model.genSamples();
    vector<Model::Sample*> samples = model.getSamples();
    EXPECT_EQ(samples.size(), 1000);
}

bool IsMale(Model::Sample* i) {
    return i->male;
}

TEST(ModelTests, testSamples) {
    Model model;
    model.genSamples();
    Model::Sample* sample = model.genSample();
    vector<Model::Sample*> samples = model.getSamples();
    int male_cnt = count_if(samples.begin(), samples.end(), IsMale);
    cout << "Male count: " << male_cnt << endl;
    ASSERT_NE(male_cnt, 0);
}

// bool IsMaleAlt(Model::Sample i) {
//     return i.male;
// }

// TEST(ModelTests, testAltSamples) {
//     Model model;
//     model.genAltSamples();
//     vector<Model::Sample> samples = model.getAltSamples();
//     int male_cnt = count_if(samples.begin(), samples.end(), IsMaleAlt);
//     cout << "Male count: " << male_cnt << endl;
//     ASSERT_NE(male_cnt, 0);
// }

TEST(ModelTests, testProbHighestIncome) {
    Model model;
    model.genSamples();
    Model::Sample* sample = new Model::Sample();
    sample->highest_income=true;
    sample->male=true;
    float p = model.getProbHighestIncome(sample);
    cout << "p male highest income: " << p << endl;
    ASSERT_GT(p, 0);
    sample->male=false;
    p = model.getProbHighestIncome(sample);
    cout << "p nonmale highest income: " << p << endl;
    ASSERT_GT(p, 0);
}

TEST(ModelTests, testProbBelowPoverty) {
    Model model;
    model.genSamples();
    Model::Sample* sample = new Model::Sample();
    sample->below_poverty=true;
    sample->male=true;
    float p = model.getProbBelowPoverty(sample);
    cout << "p male below poverty: " << p << endl;
    ASSERT_GT(p, 0);
    sample->male=false;
    p = model.getProbBelowPoverty(sample);
    cout << "p nonmale below poverty: " << p << endl;
    ASSERT_GT(p, 0);
}

TEST(ModelTests, testProbRentBurdened) {
    Model model;
    model.genSamples();
    Model::Sample* sample = new Model::Sample();
    sample->rent_burdened=true;
    sample->male=true;
    float p = model.getProbRentBurdened(sample);
    cout << "p male rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
    sample->male=false;
    p = model.getProbRentBurdened(sample);
    cout << "p nonmale rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
}

TEST(ModelTests, testProbRentBurdenedSeattle) {
    Model model;
    model.genSamples();
    Model::Sample* sample = new Model::Sample();
    sample->rent_burdened=true;
    sample->male=true;
    float p = model.getProbRentBurdened(sample);
    cout << "p male rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
    sample->male=false;
    p = model.getProbRentBurdened(sample);
    cout << "p nonmale rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
    SeattleModel seattle_model;
    seattle_model.genSamples();
    Model::Sample* seattle_sample = new Model::Sample();
    seattle_sample->rent_burdened=true;
    seattle_sample->male=true;
    p = seattle_model.getProbRentBurdened(sample);
    cout << "seattle p male rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
    seattle_sample->male=false;
    p = seattle_model.getProbRentBurdened(sample);
    cout << "seattle p nonmale rent burdened: " << p << endl;
    ASSERT_GT(p, 0);
}

TEST(ModelTests, testProbBelowPovertySeattle) {
    Model model;
    model.genSamples();
    Model::Sample* sample = new Model::Sample();
    sample->below_poverty=true;
    sample->male=true;
    float p = model.getProbBelowPoverty(sample);
    cout << "p male below poverty: " << p << endl;
    ASSERT_GT(p, 0);
    sample->male=false;
    p = model.getProbBelowPoverty(sample);
    cout << "p nonmale below poverty: " << p << endl;
    ASSERT_GT(p, 0);
    SeattleModel seattle_model;
    seattle_model.genSamples();
    Model::Sample* seattle_sample = new Model::Sample();
    seattle_sample->below_poverty=true;
    seattle_sample->male=true;
    p = seattle_model.getProbBelowPoverty(sample);
    cout << "seattle p male below poverty: " << p << endl;
    ASSERT_GT(p, 0);
    seattle_sample->male=false;
    p = seattle_model.getProbBelowPoverty(sample);
    cout << "seattle p nonmale below poverty: " << p << endl;
    ASSERT_GT(p, 0);
}