#include "io_handler.hpp"

int main(int argc, char* argv[]) {
    try
    {
        IOHandler handler(argv[1], argv[2]);
        handler.check_user();
        
    } 
    catch (const NotFound& e) 
    {
        cout << e.what() << endl;
    } catch (const Empty& e) 
    {
        cout << e.what() << endl;
    }
    catch (const BadRequest& e) {
        cout << e.what() << endl;
    }
    return 0;
}
