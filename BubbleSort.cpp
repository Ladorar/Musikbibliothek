#include "BubbleSort.h"
#include <algorithm>

using namespace std;



std::string lowerCase(std::string sourceString) {
    std::string destinationString;
    destinationString.resize(sourceString.size());
    std::transform(sourceString.begin(), sourceString.end(), destinationString.begin(), ::tolower);
    return destinationString;
}



void bubblesort (DynArray& v) {
   

   for (int j = v.size(); j > 1; j--) {
        for (int i = 0; i < (j-1); i++ ) {      
            if (lowerCase(v.at(i).getTitle()) > lowerCase(v.at(i+1).getTitle())) {
            std::swap (v.at(i), v.at(i+1));
            }
        }
    }
}