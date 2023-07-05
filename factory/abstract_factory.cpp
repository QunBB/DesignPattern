/**
 * @author: hong
 * @date: 2022/8/12 07:30
 * @description:
 */

#include "abstract_factory.h"

#include <iostream>

using namespace std;

void SQLConnect::connect(string host, int port) {
    cout << "connect SQL Server: " << host << ":" << port << endl;
}

void SQLCommand::sql(string text) {
    cout << "sql: " << text << endl;
}


void SQLExecutor::run() {
    cout << "exec SQL Server sql" << endl;
}


Connect *SQLFactory::createConnect() {
    SQLConnect *conn = new SQLConnect();
    return conn;
}

Command *SQLFactory::createCommand() {
    SQLCommand *command = new SQLCommand();
    return command;
}

Executor *SQLFactory::createExecutor() {
    SQLExecutor *executor = new SQLExecutor();
    return executor;
}

