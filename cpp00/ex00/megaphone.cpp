#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return (1);
    }
    int i = 1;
    while (argv[i])
    {
        int j = 0;
        while (argv[i][j])
        {
            argv[i][j]  = std::toupper(argv[i][j]);
            std::cout << argv[i][j];
            j++;
        }
        std::cout << ' ';
        i++;
    }
    std::cout << '\n';
    return (0);
}