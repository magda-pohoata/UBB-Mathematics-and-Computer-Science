#pragma once
#include <string>
#include "Request.h"

class OfflineLesson : public Request {
public:

    OfflineLesson():Request()
    {
        this->m_url = "no url";
    }
    OfflineLesson(int id, Date dd, float price, char* subj, std::string url) : Request(subj, dd, price) {
        
        this->m_url = url;
    }

    friend ostream& operator<<(ostream& os, OfflineLesson&);
    friend istream& operator>>(istream& is, OfflineLesson&);


private:
    std::string m_url; // ! nu mai trebuie Rule of three
};
