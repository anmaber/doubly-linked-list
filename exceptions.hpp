#pragma once

#include <iostream>
#include <exception>

using namespace std;

struct EmptyListError : runtime_error
{
    EmptyListError() : runtime_error("List is empty") {}
};

struct NotFoundError : runtime_error
{
    NotFoundError() : runtime_error("Not found") {}
};
