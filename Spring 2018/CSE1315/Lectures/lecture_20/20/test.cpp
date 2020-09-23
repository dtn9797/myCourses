#include "vector.h"
#include "scoop.h"
#include <iostream>

int main() {
    vector<int> vi{10};
    for (int i=0; i<10; ++i)
        vi.set(i, i*i);

    for (int i=9; i>=0; --i) {
        if (vi.get(i) != i*i) {
            std::cerr << "Fail: stored " << vi.get(i)
                      << " instead of " << i*i << std::endl;
        }
    }

    vector<Scoop> vs{4};
    vs.set(2,
        Scoop{"Chocolate", "Brown cocoa goodness", 0.25, 0.75}
          );

    if (  vs.get(2).name()        != "Chocolate"
       || vs.get(2).description() !="Brown cocoa goodness"
       || vs.get(2).cost()        != 0.25
       || vs.get(2).price()       != 0.75) {
         std::cerr << "Fail: Scoop" << std::endl;
    }

}
