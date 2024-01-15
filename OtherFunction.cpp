#include <iostream>
#include <windows.h>
#include "AutoClicker.cpp"

//ces fonctions m'ont sauvées mais je sais pas trop comment 

void RightClick(int a[], int b[])
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =a[clicker.x]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =b[clicker.x]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++clicker.x;
    std::cout<<input.mi.dx<<input.mi.dy<<std::endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));

}

void LeftClick(int d[], int e[])
{
    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
    input.mi.dwExtraInfo = 0;
    input.mi.mouseData = 0;
    input.mi.dx =d[clicker.x]*(65535.0f/ GetSystemMetrics(SM_CXSCREEN));
    input.mi.dy =e[clicker.x]*(65535.0f/ GetSystemMetrics(SM_CYSCREEN));
    input.mi.time = 0;
    ++v.c;
    std::cout<<input.mi.dx<<input.mi.dy<<std::endl;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    ZeroMemory(&input,sizeof(INPUT));
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &input, sizeof(INPUT));

}