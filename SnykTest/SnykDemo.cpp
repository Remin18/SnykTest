#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

// 1. バッファオーバーフロー
void VulnerableBuffer(const char* input) {
    char buffer[8];
    // バッファサイズをチェックせずコピー（バッファオーバーフロー）
    strcpy(buffer, input); // 警告が出ますが脆弱性デモのためOK
    std::cout << "Buffer: " << buffer << std::endl;
}

// 2. パストラバーサル
void SaveData(const std::string& filename, const std::string& data) {
    // 入力値をそのままファイル名に使用（パストラバーサル脆弱性）
    std::ofstream ofs(filename);
    ofs << data;
    ofs.close();
    std::cout << "Saved data to " << filename << std::endl;
}

// 3. コマンドインジェクション
void RunCommand(const std::string& userInput) {
    // 入力値をそのままコマンドに（コマンドインジェクション）
    std::string cmd = "echo " + userInput;
    system(cmd.c_str());
}


int main() {
    std::cout << "脆弱性デモ開始\n";

    // 1. バッファオーバーフロー
    std::cout << "[1] バッファオーバーフローの例\n";
    char userInput[256];
    std::cout << "何か入力してください（長い文字列を入力すると危険！）: ";
    std::cin.getline(userInput, 256);
    VulnerableBuffer(userInput);

    // 2. パストラバーサル
    std::cout << "\n[2] ファイル保存の例（パストラバーサル脆弱性）\n";
    std::string filename;
    std::cout << "保存するファイル名を入力してください: ";
    std::getline(std::cin, filename);
    SaveData(filename, "これはテストデータです");

    // 3. コマンドインジェクション
    std::cout << "\n[3] コマンド実行の例（コマンドインジェクション）\n";
    std::string cmdInput;
    std::cout << "コマンドに渡す文字列を入力してください: ";
    std::getline(std::cin, cmdInput);
    RunCommand(cmdInput);

    std::cout << "\n脆弱性デモ終了\n";
    return 0;
}