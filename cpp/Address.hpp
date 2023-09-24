#ifndef ADDRESS_HPP
#define ADDRESS_HPP

class Address{
private:
public:
    int column; //アラビア数字の方
    int row; //漢数字の方
    Address(){
        column = 0;
        row = 0;
    }
    Address(int c, int r){
        column = c;
        row = r;
    }
    Address(int index){
        column = index % 11;
        row = index / 11;
    }
    Address(char* str){
        column = str[0] - 48;
        row = str[1] - 96;
    }
    int toIndex(){
        return row * 11 + column;
    }
    char* toString(){
        char* result = new char[2];
        sprintf(result, "%d%d", column, row);
        return result;
    }

    static Address indexToAddress(int index){
        return Address(index % 11, index / 11);
    }
    static int addressToIndex(Address address){
        return address.row * 11 + address.column;
    }

    static int indexToRow(int index){
        return index / 11;
    }
    static int indexToColumn(int index){
        return index % 11;
    }
};

#endif