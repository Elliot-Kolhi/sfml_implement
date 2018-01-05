#ifndef QLEARNING_HPP
#define QLEARNING_HPP

#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>

class QLearning
{
    
public:
    // Function descriptions can be found at qlearning.cpp
    QLearning(int x_width, int y_width, int nActions, float learningRate, float discountFactor, float epsilon);
    QLearning();

    void initRewardFunction(float majorReward, float minorReward, float penalty);
    void initQMatrix(void);

    float getQvalue(int state, int action);
    float getReward(int state);

    int chooseAction (int state);
    bool yesOrNo(float probabilityOfYes);
    void printQMatrix(std::vector<std::vector<float>> qmatrix);
    void printRewardFunction(std::vector<float> rewardFunction);
    int getOptAction (std::vector<float> actions);
    void updateQMatrix(int action, int oldState, int currentState);
    const std::vector<std::vector<float>>& getQMatrix(void) const;
    std::vector<float> getRewardFunction(void);
    void exponentialDecay (float parameter, float decayConstant);
    
	float getEpsilon(void);
	float getLearningRate(void);

private:
    int batSize;
    int yWidth;
    int nStates;
    int nActions;
    float learningRate;
    float discountFactor;
    float epsilon;
    std::vector<float> rewardFunction; // contains a reward value for each state.
    std::vector<std::vector<float>> QMatrix; // contains a Q-value for each (S,A)-pair.
};

#endif // QLEARNING_HPP
