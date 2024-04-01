#include "double_step_qsv_jpeg_dec.hpp"
#include <omp.h>
#include <queue>
#include <filesystem>
#include <cerrno>

using namespace std;
namespace fs = filesystem;

char ERROR_BUF[200];

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: "s + argv[0] + " <filepath>" << endl;
        return -1;
    }
    fs::path root_path(argv[1]);
    if (!is_directory(root_path)) {
        cerr << root_path << " is not directory." << endl;
        return -1;
    }

    queue<decodeInput> decodeDataQueue;

    for (auto &members_dir: fs::directory_iterator(root_path)) {
        cout << members_dir << endl;
        for (auto &pic_file: fs::directory_iterator(members_dir)) {
            cout << pic_file << endl;
            const auto file_size = pic_file.file_size();
            auto file_buf = static_cast<uint8_t *>(malloc(sizeof(uint8_t) * file_size));
            if (file_buf == nullptr) {
                cerr << "failed to allocate memory: " << pic_file.path() << endl;
            }
            FILE *fp;
            if (fopen_s(&fp, pic_file.path().string().c_str(), "rb") != 0) {
                cerr << "failed to open file: " << pic_file.path() << endl;
                return -1;
            }
            fread(file_buf, file_size, 1, fp);
            fclose(fp);
            decodeInput input{file_size, file_buf, nullptr};
            auto resp = decodeStream(input);
            free(resp.data);
//            free(file_buf);
        }
    }
}