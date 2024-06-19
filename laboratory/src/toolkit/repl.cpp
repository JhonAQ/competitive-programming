#include <iostream>
#include <vector>
#include <signal.h>
#include <stdio.h>
#include <fstream>
#include "../core/core.h"

using namespace std;

const int startTemplateInsertIndex = 13; // 12 is index of the middle in parenthness
const string startTemplate = "int main() {  }";

const string internalCommandsPrefix = ".";

string createInternCommand(string name)
{
    return internalCommandsPrefix + name;
}

const string quitCommandName = "quit";
const string helpCommandName = "help";
const string clearCommandName = "clear";
const string includeCommandName = "include";
const string runCommandName = "run";

const string helpCommand = createInternCommand(helpCommandName);
const string quitCommand = createInternCommand(quitCommandName);
const string clearCommand = createInternCommand(clearCommandName);
const string includeCommand = createInternCommand(includeCommandName);
const string runCommand = createInternCommand(runCommandName);

const string temporaryCpp = "./temp.cpp";
const string outputFile = "./.a.out";
const string macOsCompilerConfig = "g++ -std=c++17 -o " + outputFile;

string content;
vector<string> currentHeaders = {
    "#include <iostream>",
    "#include <cmath>"};
bool replRunning = false;
int currentWriteIndex;

string getHeadersAsString()
{
    string headers = "";
    for (int i = 0; i < currentHeaders.size(); i++)
    {
        headers += currentHeaders[i] + "\n";
    }

    return headers;
}

string startContent()
{
    return startTemplate;
}

bool prefixesWith(string str, string prefix)
{
    return str.substr(0, prefix.size()) == prefix;
}

int runCommands(string &command)
{
    bool executedAny = false;

    if (command == quitCommand)
        executedAny = true;
    else if (command == helpCommand)
    {
        cout << "To run cpp code just type it.\n"
             << "They will get compiled and output will be presented"
             << "\n";
        executedAny = true;
    }
    else if (command == clearCommand)
    {
        content = startContent();
        currentWriteIndex = startTemplateInsertIndex;

        executedAny = true;
    }
    else if (command == runCommand)
    {
        command = "";
        executedAny = false;
    }
    else if (prefixesWith(command, includeCommand + " "))
    {
        string directive = command.substr(includeCommand.size() + 1, command.size());
        currentHeaders.push_back(directive);

        executedAny = true;
    }

    return executedAny;
}

void updateContent(ofstream &file, string newContent, string path)
{
    file.open(path);
    file << newContent;
    file.close();
}

string compileCommand(ofstream &file,
                      string currentHeaders,
                      string currentContent,
                      string currentCommand,
                      int writeIndex)
{

    string newContent = currentContent;
    newContent.insert(writeIndex, "\n" + currentCommand);

    string validContent = currentHeaders + newContent;
    updateContent(file, validContent, temporaryCpp);

    string compileString = macOsCompilerConfig + " " + temporaryCpp;

    ofstream ff;
    updateContent(ff, "", outputFile);

    int statusCode = executeWithCode(compileString.c_str());
    if (statusCode != true)
    {
        cout << "Error: Compiling does not success"
             << "\n";
        return "";
    }

    bool runStatus = liveLog(outputFile.c_str());
    if (!runStatus)
    {
        cout << "Critical error: Failed to execute the file (bin stream failed!)";
        return "";
    }

    return newContent;
}

void replStart()
{
    cout << "CLT C++ LCR Live Compile REpl.\n";
}

void newCommandType()
{
    cout << "\ncpp >> ";
}

void removeTempFiles() {
    // removing temporary files
    remove(temporaryCpp.c_str());
    remove(outputFile.c_str());
}

void sigintHandler(int s) {
    removeTempFiles();
    exit(2);
}

int main()
{
    ofstream temporaryCompileFile;

    content = startContent();
    replRunning = true;

    string command;

    updateContent(temporaryCompileFile, content, temporaryCpp);
    currentWriteIndex = startTemplateInsertIndex;

    replStart();

    signal(SIGINT,sigintHandler);
    signal(EOF, sigintHandler);

    while (command != quitCommand && replRunning)
    {
        newCommandType();

        string currentCommand = "";
        getline(cin, currentCommand);

        if (currentCommand == "")
            continue;
        if (runCommands(currentCommand) == true)
            continue;

        string newContent =
            compileCommand(temporaryCompileFile, getHeadersAsString(), content, currentCommand, currentWriteIndex);

        if (newContent != "")
        {
            content = newContent;
            // + 1 is for the \n character
            currentWriteIndex += currentCommand.length() + 1;
        }

        command = currentCommand;
    }

    temporaryCompileFile.close();
    removeTempFiles();
}