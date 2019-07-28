#include "brainfuck.h"

BrainFuck::BrainFuck() {
    index = 0;
    data = vector<char>();
    labels = vector<int>();
    program = "";
}

BrainFuck::~BrainFuck() {}

void BrainFuck::read() {
    data[index] = ib_counter < input_buffer.length() ? input_buffer[ib_counter] : 0;
}

void BrainFuck::print() {
    output_buffer[ob_counter++] = data[index];
}

void BrainFuck::loop_end() {
    if (labels.empty()) throw string("Runtime error: Loop is not opened");

    if (data[index] == 0)
        labels.pop_back();
    else
        cap = labels[labels.size() - 1];
}

void BrainFuck::setDataSegment() {
    if (program.length() < data_max_size) data_size = program.length();
        else data_size = data_max_size;
    data = vector<char>(data_size, 0);
    ib_counter = 0;
    ob_counter = 0;
}

string BrainFuck::getFileContent(string filename) {
    ifstream in(filename);
    if (!in.is_open()) throw string("Application error: Failed to open program file");
    string content = "", line;
    while (!in.eof())
    {
        in >> line;
        content += line;
    }
    return content;
}

void BrainFuck::interpritate() {
    setDataSegment();

    cap = 0;
    while (cap < program.length())
    {
        switch(program[cap])
        {
            case '>':
                next();
                break;
            case '<':
                prev();
                break;
            case '+':
                inc();
                break;
            case '-':
                dec();
                break;
            case '.':
                print();
                break;
            case ',':
                read();
                break;
            case '[':
                loop_start();
                break;
            case ']':
                loop_end();
                break;
            default:
                throw string("Syntax error: Invalid symbol");
        }
        cap++;
    }
    if (!labels.empty()) throw string("Runtime error: Loops not closed");
}

void BrainFuck::compliteProgram(string text) {
    program = text;
    interpritate();
}


void BrainFuck::compliteFile(string filename) {
    program = getFileContent(filename);
    interpritate();
}

