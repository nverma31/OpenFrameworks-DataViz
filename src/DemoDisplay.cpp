//
//  DemoDisplay.cpp
//  OpenFrameworks-DataViz
//
//  Created by Neeraj Verma on 22/05/17.
//
//

#include "DemoDisplay.h"
#include "DemoElement.h"
#include <vector>

class DemoDisplay {
    
    
public:
    
    DemoDisplay(){};
    DemoDisplay(int startNumber);
    void update();
    void display();
    
private:
    
    float elementCount;
    std::vector<DemoElement> demoelements;
};
