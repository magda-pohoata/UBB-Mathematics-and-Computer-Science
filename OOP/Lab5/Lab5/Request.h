#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <string>

#include <iostream>

using namespace std;

struct Date {
    int day, month, year;
    friend ostream& operator<<(ostream& os, Date&);
    friend istream& operator>>(istream& is, Date&);
};

typedef enum { // tip enumerare
    UNPAYED,
    PENDING_COMPLETION,
    COMPLETED
} Status;


class Request {
public:
    Request(){
        char empty[] = "no subject";
        this->m_id = 0;
        this->m_subject = new char[20];
        memcpy(this->m_subject, empty, strlen(empty) + 1);
        this->m_dueDate.day = 0;
        this->m_dueDate.month = 0;
        this->m_dueDate.year = 0;
        this->m_status = UNPAYED;
        this->m_price = 0;
    }
    Request(char* subj, Date dd, float price) {

        this->m_id = 0;
        this->m_subject = new char[20];
        memcpy(this->m_subject, subj, strlen(subj) + 1);
        this->m_dueDate.day = dd.day;
        this->m_dueDate.month = dd.month;
        this->m_dueDate.year = dd.year;
        this->m_status = UNPAYED;
        this->m_price = price;
    }


    int getId() { return this->m_id; }
    void setId(int id) { this->m_id = id; }
    
    string getSubject() { return this->m_subject; }
    void setSubject(char* s) { this->m_subject = s; }

    Date getDate() { return this->m_dueDate; }
    void setDate(Date d) { this->m_dueDate = d; }

    int getStatus() { return this->m_status; }
    void setStatus(Status s) { this->m_status = s; }

    float getPrice() { return this->m_price; }
    void setPrice(float p) { this->m_price = p; }

    Request(const Request& other);      //copy constructor
    Request& operator=(const Request& other);    //operator de asignare
    ~Request();                                 // deconstructor
    
    friend ostream& operator<<(ostream& os, Date&);
    friend ostream& operator<<(ostream& os, const Request&);
    friend istream& operator>>(istream& is, Date&);
    friend istream& operator>>(istream& is, Request&);
    
protected:
    Date m_dueDate;
    float m_price;
    char* m_subject; // clasa cu date alocate dinamic: RULE OF THREE: constructor de copiere, destructor si operator=
    Status m_status; // 0 - unpayed, 1 - pending completion, 2 - completed

private:
    int m_id;

    static int idGenerator;
};
