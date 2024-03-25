#include "coder.h"
using namespace std;



int main()
{
    /*ifstream myfile("exel.xlsx", ios::binary | ios::ate);

    int size = myfile.tellg();
    myfile.seekg(0, ios::beg);
    char* buffer = new char[size];


    myfile.read(buffer, size);

    for (int i =0; i<size;i++)
    {
        cout << buffer[i];
    }
    int size_min = SIZE_MINI;
    int iter = size / size_min;
    char** buffers = new char*[iter + 1];
    for (int i = 0; i <= iter; i++)
    {
        buffers[i] = new char[size_min];
        for (int j = 0; j < size_min; j++)
        {
            if (i * size_min + j < size)
                buffers[i][j] = buffer[i * size_min + j];
            else buffers[i][j]=0;
        }
            
    }
    cout << "\n\n\n\n\n\n\n";
    


    char** send_buffers = new char* [iter + 1];
    for (int i = 0; i <= iter; i++)
    {
        send_buffers[i] = new char[size_min + to_string(iter).length()];
        for (int j = 0; j < size_min + to_string(iter).length(); j++)
            if (j < size_min)
                send_buffers[i][j] = buffers[i][j];
            else
            {
                if (j - size_min < to_string(iter).length())
                    send_buffers[i][j] = to_string(i)[j - size_min];
                else
                    send_buffers[i][j] = '0';
            }
    }



    char** get_buffer = new char* [iter + 1];

    for (int i = 0; i <= iter; i++) {
        get_buffer[get_numerico(send_buffers[i], iter)] = new char[size_min]; 
        get_buffer[get_numerico(send_buffers[i], iter)] =  send_buffers[i];
    }


    for (int i = 0; i <= iter; i++)
        for (int j = 0; j < size_min; j++)
            cout << get_buffer[i][j];
    myfile.close();
     cout << "\n\n\n\n\n\n\n";
    ofstream print("example.xlsx", ios::binary);
    char* rezult = new char[size];



    for (int i = 0; i <= iter; i++)
        for (int j = 0; j < size_min; j++)
            if(i * size_min + j<size)
                rezult[i*size_min+j] = get_buffer[i][j];



    for (int i = 0; i <= size; i++)
        cout << rezult[i];


    print.write(rezult, size);
    print.close();
    delete[] rezult, get_buffer, send_buffers, buffers, buffer;
    return 0;*/
    coder* cod = new coder();
    cod->start();
}





/*todo
        class mai
        zad123
        
        logs
        random
        review
        
*/


