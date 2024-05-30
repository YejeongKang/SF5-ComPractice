#pragma once

#include <iostream>
#include <string>

using namespace std;

class Calculate {
public:
    Calculate() {}

    static float num1;
    float num2;
    string oper;

    virtual float cal() = 0;
};

class Addition : public Calculate {
public:
    Addition(float n1, float n2) {
        oper = "+";
        num1 = n1;
        num2 = n2;
    }
    float cal() override {
        return num1 + num2;
    }
};

class Subtraction : public Calculate {
public:
    Subtraction(float n1, float n2) {
        oper = "-";
        num1 = n1;
        num2 = n2;
    }
    float cal() override {
        return num1 - num2;
    }
};

class Multiplication : public Calculate {
public:
    Multiplication(float n1, float n2) {
        oper = "*";
        num1 = n1;
        num2 = n2;
    }
    float cal() override {
        return num1 * num2;
    }
};

class Division : public Calculate {
public:
    Division(float n1, float n2) {
        oper = "/";
        num1 = n1;
        num2 = n2;
    }
    float cal() override {
        return num1 / num2;
    }
};
