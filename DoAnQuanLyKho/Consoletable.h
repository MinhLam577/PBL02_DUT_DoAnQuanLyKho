#ifndef CONSOLETABLE_CONSOLETABLE_H
#define CONSOLETABLE_CONSOLETABLE_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class ConsoleTable {
public:
    ConsoleTable() {};
    typedef vector<string> Headers;
    typedef vector<vector<string>> Rows;
    typedef vector<size_t> Widths;
    ConsoleTable(initializer_list<string> headers);
    void setPadding(unsigned int n);
    void setStyle(int n);
    bool sort(bool ascending);
    bool addRow(initializer_list<string> row);
    ConsoleTable& operator+=(initializer_list<string> row);
private:

    /// Holds all header strings of the table
    Headers headers;


    /// Holds all rows of the table
    Rows rows;


    /// Holds the size of widest string of each column of the table
    Widths widths;

    /// Defines row type
    struct RowType {
        string left;
        string intersect;
        string right;
    };

    /// Defines table style rows (top, middle, bottom etc)
    struct TableStyle {
        string horizontal;
        string vertical;
        RowType top;
        RowType middle;
        RowType bottom;
    };


    /// Basic style - works on all systems, used as default style
    TableStyle BasicStyle = { "-", "|", {"+", "+", "+"}, {"+", "+", "+"}, {"+", "+", "+"} };

    TableStyle InvisibleStyle = { " ", " ", {" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "} };
    /// Current table style
    TableStyle style = BasicStyle;

    /// Space character constant
    const string SPACE_CHARACTER = " ";


    /// The distance between the cell text and the cell border
    unsigned int padding = 1;


    /// Returns a formatted horizontal separation line for the table
    /// \param rowType The type of the row (top, middle, bottom)
    /// \return The formatted row string
    string getLine(RowType rowType) const;


    /// Returns a formatted header string
    /// \param headers The Headers-object that holds the header strings
    /// \return The formatted header string
    string getHeaders(Headers headers) const;


    /// Returns a formmatted row string
    /// \param rows The Rows-object that holds all rows of the table
    /// \return A formatted string of all rows in the table
    string getRows(Rows rows) const;


    /// Writes the entire table with all its contents in the output stream
    /// This can be used to display the table using the cout function
    /// \param out The output stream the table should be written to
    /// \param consoleTable The ConsoleTable-object
    /// \return Output stream with the formatted table string
    friend ostream& operator<<(ostream& out, const ConsoleTable& consoleTable);

};

/// Repeats a given string n times
/// \param other The string to repeat
/// \param repeats The amount the string should be repeated
/// \return The repeated string
string operator*(const string& other, int repeats);

#endif