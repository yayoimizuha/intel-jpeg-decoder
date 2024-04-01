#include <vpl/mfx.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "double_step_qsv_jpeg_dec.hpp"
using namespace std;
namespace fs = filesystem;



int main() {
//    string PATH = R"(C:\Users\tomokazu\friends-4385686.jpg)";
    auto *session = createSession();
    auto queue = createSYCLQueue();

    auto dir_iterator = fs::directory_iterator(R"(C:\Users\tomokazu\CLionProjects\intel-jpeg-decoder\test_files)");
    for (auto &path: dir_iterator) {
        cout << path.path().string() << endl;

        ifstream input_file(path.path().string(), ios::binary | ios::in);
        if (!input_file) {
            cerr << "failed to open file" << endl;
        }
        vector<mfxU8> data{istreambuf_iterator<char>(input_file), istreambuf_iterator<char>()};
        try {
            decodeInput input{data.size(), data.data()};
            auto out = decodeStream(input);
            free(out.data);
        } catch (exception &e) {
            cout << "failed to decode :" << path.path().string() << "by" << e.what() << endl;
        }

    }


    free(session);
}