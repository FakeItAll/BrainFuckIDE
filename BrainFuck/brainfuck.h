#ifndef BRAINFUCK_H
#define BRAINFUCK_H

#include <fstream>
#include <string>
#include <vector>

using namespace std;

class BrainFuck
{
    private:
        static const unsigned int data_max_size = 10000;
        unsigned int index, cap, data_size, ib_counter, ob_counter;
        vector<int> labels;
        vector<char> data;
        string program, input_buffer, output_buffer;

        inline void next() { if (index < data_size) index++; }
        inline void prev() { if (index > 0) index--; }
        inline void inc() { data[index]++; }
        inline void dec() { data[index]--; }
        void read();
        void print();
        inline void loop_start() { labels.push_back(cap); }
        void loop_end();

        void setDataSegment();

        string getFileContent(string filename);

        void interpritate();

    public:
        BrainFuck();
        ~BrainFuck();

        void compliteFile(string filename);
        void compliteProgram(string text);
        inline string getProgram() { return program; }

        inline void setInputBuffer(string data) {input_buffer = data; }
        inline string getOutputBuffer() { return output_buffer; }
};

#endif // BRAINFUCK_H
