#include <filesystem>
#include <iostream>
#include "double_step_qsv_jpeg_dec.hpp"

using namespace std;
namespace fs = filesystem;

int main(int argc, char *argv[]) {
    fs::directory_entry pic_file(R"(C:\Users\tomokazu\aaa.jpg)");

    cout << pic_file << endl;

    for (int i = 0; i < 10; ++i) {
        auto file_buf = static_cast<uint8_t *>(calloc(sizeof(uint8_t), BITSTREAM_BUFFER_SIZE));
        if (file_buf == nullptr) {
            cerr << "failed to allocate memory: " << pic_file.path() << endl;
            return 5;
        }
        FILE *fp;
        if (fopen_s(&fp, pic_file.path().string().c_str(), "rb") != 0) {
            cerr << "failed to open file: " << pic_file.path() << endl;
            return 4;
        }
        const auto file_size = fread(file_buf, 1, BITSTREAM_BUFFER_SIZE, fp);
        fclose(fp);
        decodeInput input{file_size, file_buf, nullptr};
        auto resp = decodeStream(input);
        free(resp.data);
    }
//            free(file_buf);
}
//    }