#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

/*
 *
 *  1 Introduction

void function_1(){
    std::cout << "----Beauty is only skin-deep----" << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::thread t1(function_1); // t1 starts running
//    t1.join(); // main thread waits for t1 to finish
    t1.detach(); // t1 will freely on its own, daemon process

    if ( t1.joinable())
        t1.join();
    return 0;
}

 -----

void function_1(){
    std::cout << "----Beauty is only skin-deep----" << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::thread t1(function_1); // t1 starts running

    try {
        for (int i = 0; i < 100; ++i) {
            cout << "From main: " << i << endl;
        }
    } catch (...){
        t1.join();
        throw ;
    }

    t1.join();

    return 0;
}


 -----

class Fctor {
public:
    void operator()(){
        for (int i = 0; i > -100; --i) {
            cout << "From t1: " << i << endl;
        }
    }
};

void function_1(){
    std::cout << "----Beauty is only skin-deep----" << std::endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    Fctor fct;
    thread t1((Fctor()));
//    thread t1(fct); // t1 starts running

    try {
        for (int i = 0; i < 100; ++i) {
            cout << "From main: " << i << endl;
        }
    } catch (...){
        t1.join();
        throw ;
    }

    t1.join();

    return 0;
}

 -----

class Fctor {
public:
    void operator()(string& msg){
            cout << "From t1: " << msg << endl;
            msg = "Trust is the mother of deceit";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "Love Yao";
    thread t1((Fctor()), ref(s)); // use std::ref to pass reference to thread
    t1.join();
    cout << "From main: " << s << endl;
    return 0;
}

 -----

class Fctor {
public:
    void operator()(string& msg){
        cout << "From t1: " << msg << endl;
        msg = "Trust is the mother of deceit";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    string s = "Love Yao";

    cout << std::this_thread::get_id() << endl;
    thread t1((Fctor()), ref(s)); // use std::move
    cout << t1.get_id() << endl;

    thread t2 = move(t1);
    t2.join();
    cout << "From main: " << s << endl;
    return 0;
}

-----

 Race condition, if don't use mutex, we the output from main function and function_1 is mess because of these two threads are racing the
 cout


std::mutex mu;

void shard_print(string msg, int id){
    std::lock_guard<std::mutex> guard(mu);

    // Problem here is if inside the mu lock, there is exception, then then lock will never be unlocked, thus we have to use lock_guard to
//    mu.lock();
    cout << msg << "  " << id << endl;
//    mu.unlock();
}

void function_1(){
    for (int i = 0; i > -100; --i) {
        shard_print(string("From t1: "), i);
    }
}

int main() {
    cout << " Hello World!" << endl;
    thread t1(function_1);

    for (int i = 0; i < 100; ++i) {
        shard_print(string("From main: "), i);
    }

    t1.join();
    return 0;
}



class LogFile{
    std::mutex m_mutex;
    ofstream f;
public:
    LogFile(){
        f.open("log.txt");
    }

    void shared_print(string id, int value){
        std::lock_guard<mutex> locker(m_mutex);
        f << "From" << id << ": " << value << endl;
    };
};

void function_1(LogFile& log){
    for (int i = 0; i < -100; ++i) {
        log.shared_print(string("From t1: "), i);
    }
}


int main(){
    LogFile log;

    std::thread t1(function_1, ref(log));

    for (int i = 0; i < 100; ++i) {
        log.shared_print(string("From main: "), i);
    }
    t1.join();
    return 0;
}
 -----

 Avoid Data Race:

 1. Use mutex to syncrhonize data access
 2. Never leak a handle of data to outside.
 3. Design interface appropriately.

class stack{
    int *_data;
    std::mutex _mu;
public:
    void pop();
    int& top();
};



void function_1(stack& st){
    int v = st.top();
    st.pop();
    process(v);
}


 Deadlock

 1. Prefer locking single mutex.
 2. Avoid locking a mutex and then calling a user provided function.
 3. Use std::lock() to lock more than one mutex.
 4. Lock the mutex in same order
*/

class LogFile {
    std::mutex _mu;
};

















