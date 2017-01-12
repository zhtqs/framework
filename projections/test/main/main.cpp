#include <iostream>

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
#ifdef FRAMEWORK_LIBRARY
    printf_s("FRAMEWORK_LIBRARY definetion is valid, now running in API DEVELOPMENT environment. \n");
#else
    printf_s("FRAMEWORK_LIBRARY definetion is invalid, now running in SDK environment. \n");
#endif
    system("pause");
    return 0;
}
