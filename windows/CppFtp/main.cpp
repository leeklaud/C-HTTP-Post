#include <windows.h>
#include <wininet.h>
#include <atlstr.h>
#include <iostream>
#pragma comment(lib, "wininet")

int main() {
    CString ip = L"";
    CString id = L"";
    CString pw = L"";

    CString src_path = L"C:\\Temp\\input2.txt"; // �����ϰ��� �ϴ� ������ ���
    CString dest_fname = L"MyFtpTest.txt";      // ������ ����� ���� �̸�

    HINTERNET hInternet;
    HINTERNET hFtpSession;
    hInternet = InternetOpen(NULL, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    hFtpSession = InternetConnect(hInternet, ip, INTERNET_DEFAULT_FTP_PORT, id, pw, INTERNET_SERVICE_FTP, 0, 0);
    if (hFtpSession) {
        if (FtpPutFile(hFtpSession, src_path, dest_fname, FTP_TRANSFER_TYPE_BINARY, 0)) {
            std::cout << "���������� ���ε� �Ϸ��" << std::endl;
        }
        else {
            std::cout << "���ε� ����" << std::endl;
        }
    }
    InternetCloseHandle(hFtpSession);
    InternetCloseHandle(hInternet);

    return 0;
}