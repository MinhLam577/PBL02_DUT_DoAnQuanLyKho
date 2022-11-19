#include "ConsoleTable.h"
ConsoleTable::ConsoleTable(initializer_list<string> headers) : headers{ headers } {
    for (const auto& column : headers) {
        widths.push_back(column.length());
    }
}
void ConsoleTable::setPadding(unsigned int n) {
    padding = n;
}
void ConsoleTable::setStyle(int n)
{
    if (n == 0)
    {
        style = ConsoleTable::BasicStyle;
    }
    else style = ConsoleTable::InvisibleStyle;

}
bool ConsoleTable::addRow(initializer_list<string> row) {
    if (row.size() > widths.size()) {
        throw invalid_argument{ "Appended row size must be same as header size" };
    }

    auto r = vector<string>{ row };
    rows.push_back(r);
    for (unsigned int i = 0; i < r.size(); ++i) {
        widths[i] = max(r[i].size(), widths[i]);
    }
    return true;
}
ConsoleTable& ConsoleTable::operator+=(initializer_list<string> row) {
    if (row.size() > widths.size()) {
        throw invalid_argument{ "Appended row size must be same as header size" };
    }

    addRow(row);
    return *this;
}
string ConsoleTable::getLine(RowType rowType) const {
    stringstream line;
    line << rowType.left;
    for (unsigned int i = 0; i < widths.size(); ++i) {
        for (unsigned int j = 0; j < (widths[i] + padding + padding); ++j) {
            line << style.horizontal;
        }
        line << (i == widths.size() - 1 ? rowType.right : rowType.intersect);
    }
    return line.str() + "\n";
}
string ConsoleTable::getHeaders(Headers headers) const {
    stringstream line;
    line << style.vertical;
    for (unsigned int i = 0; i < headers.size(); ++i) {
        string text = headers[i];
        line << SPACE_CHARACTER * padding + text + SPACE_CHARACTER * (widths[i] - text.length()) + SPACE_CHARACTER * padding;
        line << style.vertical;
    }
    line << "\n";
    return line.str();
}
string ConsoleTable::getRows(Rows rows) const {
    stringstream line;
    for (auto& row : rows) {
        line << style.vertical;
        for (unsigned int j = 0; j < row.size(); ++j) {
            string text = row[j];
            line << SPACE_CHARACTER * padding + text + SPACE_CHARACTER * (widths[j] - text.length()) + SPACE_CHARACTER * padding;
            line << style.vertical;
        }
        line << "\n";
    }

    return line.str();
}
ostream& operator<<(ostream& out, const ConsoleTable& consoleTable) {
    out << consoleTable.getLine(consoleTable.style.top);
    out << consoleTable.getHeaders(consoleTable.headers);
    out << consoleTable.getLine(consoleTable.style.middle);
    out << consoleTable.getRows(consoleTable.rows);
    out << consoleTable.getLine(consoleTable.style.bottom);
    return out;
}
bool ConsoleTable::sort(bool ascending) {
    if (ascending)
        std::sort(rows.begin(), rows.end(), less<vector<string>>());
    else
        std::sort(rows.begin(), rows.end(), greater<vector<string>>());
    return true;
}
string operator*(const string& other, int repeats) {
    string ret;
    ret.reserve(other.size() * repeats);
    for (; repeats; --repeats)
        ret.append(other);
    return ret;
}