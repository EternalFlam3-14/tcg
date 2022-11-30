#include <string>
#include <sstream>

struct Terminal_C
{
public:
//                                     PUBLIC

//                                  Terminal Input
    void In();
//                                  Terminal Input Data
    const int Get_Word_Count() const { return Words; };
    const std::string Get_Input() const { return Input; };

//                                  Terminal Output
    void Say(std::string output);



private:
//                                     PRIVATE
    //                              Input Data
    std::string Input;                                          // The entire input line
    int Words;                                                  // Number of words minus keyword

    //                              Terminal Setters
    void Set_Words();
};