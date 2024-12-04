#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    std::string group = validator.group();
    std::string words[7] = {"social", "history", "language", "literacy", "bigdata", "public", "society"};

    if (group == "subtask_1") {
        std::string title = inf.readLine();
        bool wordcheck = false;
        for(int i=0 ; i<7 ; i++) {
            if(title == words[i]) wordcheck = true;
        }
        ensuref(wordcheck, "Word not in list");
        
    } else if (group == "subtask_2") {
        std::string title = inf.readLine();
        bool wordcheck = false;
        for(int i=0 ; i<7 ; i++) {
            if(title.find(words[i]) != std::string::npos) wordcheck = true;
        }
        ensuref(wordcheck, "Word not in list");
    } 

    inf.readEof();
}
