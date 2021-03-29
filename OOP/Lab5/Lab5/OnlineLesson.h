#pragma once

#include <string>
#include "Request.h"

class OnlineLesson : public Request {
public:
    OnlineLesson() :Request() {
        this->m_time = 0;
        this->m_url = "no url";
    }
    OnlineLesson(char* subj, Date dd, float price, int time, std::string url) : Request(subj, dd, price) {

        this->m_time = time;
        this->m_url = url;

    }

    int getTime() { return this->m_time; }
    void setTime(int t) { this->m_time = t; }

    string getUrl() { return this->m_url; }
    void setUrl(string url) { this->m_url = url; }
    
    friend ostream& operator<<(ostream& os, OnlineLesson&);
    friend istream& operator>>(istream& is, OnlineLesson&);

private:
   
    int m_time;
    std::string m_url; // ! nu mai trebuie Rule of three
};
