#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstring>
#include <cerrno>

using namespace std;



FILE *cpp_fopen(char *filename, char *mode)
{
    if (filename == NULL || mode == NULL)
        throw invalid_argument("no file-name or no mode specification");
        
    FILE *f = fopen(filename, mode);

    if (f == NULL)
        throw invalid_argument(strerror(errno));
}

void cpp_fclose(FILE *fp)
{
    fclose(fp);
}

size_t cpp_fwrite(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t ret = fwrite(ptr, size, nmemb, fp);
    if (ret < nmemb)
        throw logic_error(strerror(errno));
    else
        return ret;
}

size_t cpp_fread(void *ptr, size_t size, size_t nmemb, FILE *fp)
{
    size_t ret = fread(ptr, size, nmemb, fp);
    if (ret < nmemb)
        throw logic_error(strerror(errno));
    else
        return ret;
}

// FILE * pFile;
//   pFile = fopen ("myfile.txt","w");
//   if (pFile!=NULL)
//   {
//     fputs ("fopen example",pFile);
//     fclose (pFile);
//   }


int main(void)
{
    try
    {
        cpp_fopen("asdf", "r");
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        char buf[100];
        FILE *fp = cpp_fopen("5.cpp", "r");
        cpp_fread(buf, sizeof(char), 50, fp);
        buf[50] = 0;
        cout << buf << endl;
        cpp_fclose(fp);
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    

}
