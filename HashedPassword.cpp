
#include "HashedPassword.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

using namespace std;

string hash_password(const std::string &input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(input.c_str()), input.size(), hash);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss<<hex<<setw(2)<<setfill('0')<<(int)hash[i];
    }
    return ss.str();
}
