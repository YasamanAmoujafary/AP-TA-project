#include "io_handler.hpp"

int main(int argc, char* argv[]) {
    try
    {
        IOHandler handler(argv[1], argv[2]);
        handler.runCommandLoop();
        
    } 
   catch (const exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
