#include <filesystem>
#include <iostream>
#include "double_step_qsv_jpeg_dec.hpp"

using namespace std;
namespace fs = filesystem;

int main(int argc, char *argv[]) {
    fs::directory_entry pic_file(R"(C:\Users\tomokazu\friends-4385686.jpg)");

    cout << pic_file << endl;
    const auto file_size = pic_file.file_size();
    cout << file_size << endl;
    auto file_buf = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * file_size));
    if (file_buf == nullptr) {
        cerr << "failed to allocate memory: " << pic_file.path() << endl;
        return 5;
    }
    FILE *fp;
    if (fopen_s(&fp, pic_file.path().string().c_str(), "r") != 0) {
        cerr << "failed to open file: " << pic_file.path() << endl;
        return 4;
    }
    fread(file_buf, file_size, 1, fp);
    fclose(fp);
    decodeInput input{file_size, file_buf, nullptr};
    auto resp = decodeStream(input);
    free(resp.data);
//            free(file_buf);
}
//    }