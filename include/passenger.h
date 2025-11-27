#pragma once
#include <string>

typedef struct {
    int userID;
    std::string nama;
} userData;

typedef struct usrElement *usrAddress;

struct usrElement {
    userData info;
    usrAddress next;
    usrAddress prev;
};

typedef struct {
    usrAddress first;
    usrAddress last;
} usrList;