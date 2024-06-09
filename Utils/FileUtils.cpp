//
// Created by Hypericats on 6/8/2024.
//

#include "FileUtils.hpp"

std::string FileUtils::getClipboardText() {
    if (! OpenClipboard(nullptr))
        return "";

    HANDLE hData = GetClipboardData(CF_TEXT);
    if (hData == nullptr)
    return "";


    char * pszText = static_cast<char*>( GlobalLock(hData) );
    if (pszText == nullptr)
        return "";

    std::string text( pszText );
    GlobalUnlock( hData );
    CloseClipboard();
    return text;
}

void FileUtils::listFiles(const std::string& path, std::vector<std::string>& v) {
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if (std::filesystem::is_regular_file(entry.status())) {
                v.push_back(entry.path().string());
            }
        }
    }
}

void FileUtils::listDirs(const std::string& path, std::vector<std::string>& v) {
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        for (const auto& entry : std::filesystem::directory_iterator(path)) {
            if (std::filesystem::is_directory(entry.status())) {
                v.push_back(entry.path().string());
            }
        }
    }
}

