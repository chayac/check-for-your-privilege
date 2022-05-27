#include "gtest/gtest.h"
#include "model.h"
#include <algorithm>
#include <random>

TEST(ModelTests, testModel) {
    ASSERT_STREQ("Hello Jim", generateHelloString("Jim").c_str());
}

TEST(ModelTests, testDefaultConstructor) {
    Model model;
    Model::Sample* sample = model.genSample();
    vector<Model::Sample*>* samples = model.getSamples();
    EXPECT_EQ(samples->size(), 1000);
}

bool IsMale(Model::Sample* i) {
    return i->male;
}

TEST(ModelTests, testSamples) {
    Model model;
    Model::Sample* sample = model.genSample();
    vector<Model::Sample*>* samples = model.getSamples();
    int male_cnt = count_if(samples->begin(), samples->end(), IsMale);
    cout << "Male count: " << male_cnt << endl;
    ASSERT_NE(male_cnt, 0);
}