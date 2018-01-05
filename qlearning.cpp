#include "qlearning.hpp"
#include <algorithm>

// QLearning(): the constructor

QLearning::QLearning (int batSize, int yWidth, int nActions, float learningRate, float discountFactor, float epsilon)
: batSize(batSize), yWidth(yWidth), nActions(nActions), nStates(yWidth*(yWidth-batSize+1)), learningRate(learningRate), discountFactor(discountFactor), epsilon(epsilon)
{
	srand (time(NULL));
}

QLearning::QLearning(){	srand (time(NULL)); }

// initRewardFunction: initializes the rewardFunction with majorReward (M), minorReward (m) or penalty (p) for each state.
void QLearning::initRewardFunction(float majorReward, float minorReward, float penalty)
{
    std::vector<float> temp(nStates);
    for (int i = 0; i < nStates; i++) {
        // if y_bat == y_ball
        if ( i%(yWidth-batSize+1) == i/(yWidth-batSize+1) ) {
            temp[i] = majorReward;
            // if y_bat != y_ball
        } else {
            temp[i] = penalty;
        }
    }
    rewardFunction = temp;
}

// initQMatrix sets Q to a (nStates)x(nActions) zero-matrix.
void QLearning::initQMatrix(void)
{
    std::vector<std::vector<float>> temp(nStates, std::vector<float>(nActions));
    for (int i = 0; i < nStates; i++) {
        for (int j = 0; j < nActions; j++) {
            temp[i][j] = 0;//(((rand() % 1000) / 1000.f)-0.5f)*50.f;
        }
    }
    QMatrix = temp;
}

//returns the Q matrix
const std::vector<std::vector<float>>& QLearning::getQMatrix(void) const
{
    return QMatrix;
}

//returns the reward function
std::vector<float> QLearning::getRewardFunction(void)
{
    return rewardFunction;
}

// returns the Q-value of a given (S,A)-pair.
float QLearning::getQvalue(int state, int action)
{
    if (QMatrix.size() == 0) {
        std::cout << "QMatrix not initialized." << std::endl;
        return -1;
    } else {
        return QMatrix[state][action];
    }
}

// returns the reward-value of a given state.
float QLearning::getReward(int state)
{
    if (rewardFunction.size() == 0) {
        std::cout << "Rewardfunction not initialized." << std::endl;
        return -1;
    } else {
        return rewardFunction[state];
    }
}
// prints the given rewardFunction to standard output.
void QLearning::printRewardFunction(std::vector<float> rewardFunction)
{
    if (rewardFunction.size() == 0) {
        std::cout << "Rewardfunction not initialized." << std::endl;
    } else {
        std::cout << "Rewardfunction is:" << std::endl;
        for (int i = 0; i < nStates; i++) {
            std::cout << rewardFunction[i] << " ";
        }
        std::cout << std::endl;
    }
}

// prints the given Q matrix to standard output.
void QLearning::printQMatrix (std::vector<std::vector<float>> qmatrix)
{
    if (qmatrix.size() == 0) {
        std::cout << "Q matrix not initialized." << std::endl;
    } else {
        std::cout << "Q-matrix is: " << std::endl;
        for (int i = 0; i < nStates; i++) {
            for (int j = 0; j < nActions; j++) {
                std::cout << qmatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

//returns an action chosen with epsilon-greedy algorithm: with probability 1-epsilon, the best action for the given state is returned, else with probability epsilon any action is given with uniform probability.
int QLearning::chooseAction (int state)
{
    bool chooseBest = yesOrNo(1-epsilon);
    if (chooseBest) {
        int optAction = getOptAction(QMatrix[state]);
        return optAction;
    } else {
        bool chooseFirst = yesOrNo(0.33);
        if (chooseFirst) {
            return 0;
        } else {
            bool chooseSecond = yesOrNo(0.50);
            if (chooseSecond) {
                return 1;
            } else {
                return 2;
            }
        }
    }
}

// updates the Q matrix with the Q algorithm.
void QLearning::updateQMatrix(int action, int oldState, int currentState)
{
    float oldQvalue = QMatrix[oldState][action];
    int optAction = getOptAction(QMatrix[currentState]);
    float maxQvalue = QMatrix[currentState][optAction];
    float newQvalue = (1-learningRate) * oldQvalue + learningRate * (rewardFunction[currentState] + discountFactor * maxQvalue);
    QMatrix[oldState][action] = newQvalue;
}

// returns true with probability probabilityOfYes, otherwise false.
bool QLearning::yesOrNo(float probabilityOfYes)
{	
	return (float)(std::rand()%1000) < (probabilityOfYes * 1000.f);
}

// gives the optimal action with the highest Qvalue.
int QLearning::getOptAction(std::vector<float> actions)
{
    if (actions[0] >= actions[1] && actions[0] >= actions[2]) {
        return 0;
    } else if (actions[1] >= actions[2]) {
        return 1;
    } else {
        return 2;
    }
}

// decreases the value of the given parameter (0=epsilon, 1=learningRate) by the factor decayConstant.
void QLearning::exponentialDecay (float parameter, float decayConstant)
{
    if (parameter == 0) {
        epsilon = epsilon * decayConstant;
    } else {
        learningRate = learningRate * decayConstant;
    }
}

float QLearning::getEpsilon(void) {
	return epsilon;
}

float QLearning::getLearningRate(void) {
	return learningRate;
}

