#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool file_exists(const char filename[]);

void open_fileRW(fstream& f, const char filename[]) throw(char*);
void open_fileW(fstream& f, const char filename[]);


class Record{
public:
    Record(){
        record[0] = NULL;
        recno = -1;
    }

    Record(char str[]){
        strcpy(record, str);
        cout<<"1"<<endl;
    }
    long write(fstream& outs);
    long read(fstream& ins, long recno);


    friend ostream& operator<<(ostream& outs,
                               const Record& r);
private:
    static const int MAX = 10;
    int recno;
    char record[MAX];
};
long Record::write(fstream &outs){
    //write to the end of the file.
    long pos = outs.tellp();

    //outs.write(&record[0], sizeof(record));
    outs.write(record, sizeof(record));

    return pos;
}
long Record::read(fstream &ins, long recno){
    long pos= recno * sizeof(record);
    ins.seekg(pos, ios_base::beg);


    ins.read(record, sizeof(record));
    return ins.gcount();

}
ostream& operator<<(ostream& outs,
                    const Record& r){
    outs<<r.record;
    return outs;
}

//-------------------------------------------------
bool file_exists(const char filename[]){
    const bool debug = false;
    fstream ff;
    ff.open (filename,
        std::fstream::in | std::fstream::binary );
    if (ff.fail()){
        if (debug) cout<<"file_exists(): File does NOT exist: "<<filename<<endl;
        return false;
    }
    if (debug) cout<<"file_exists(): File DOES exist: "<<filename<<endl;
    ff.close();
    return true;
}

void open_fileRW(fstream& f, const char filename[]) throw(char*){
    const bool debug = false;
    //openning a nonexistent file for in|out|app causes a fail()
    //  so, if the file does not exist, create it by openning it for
    //  output:
    if (!file_exists(filename)){
        f.open(filename, std::fstream::out|std::fstream::binary);
        if (f.fail()){
            cout<<"file open (RW) failed: with out|"<<filename<<"]"<<endl;
            throw("file RW failed  ");
        }
        else{
            if (debug) cout<<"open_fileRW: file created successfully: "<<filename<<endl;
        }
    }
    else{
        f.open (filename,
            std::fstream::in | std::fstream::out| std::fstream::binary );
        if (f.fail()){
            cout<<"file open (RW) failed. ["<<filename<<"]"<<endl;
            throw("file failed to open.");
        }
    }

}
void open_fileW(fstream& f, const char filename[]){
    f.open (filename,
            std::fstream::out| std::fstream::binary );
    if (f.fail()){
        cout<<"file open failed: "<<filename<<endl;
        throw("file failed to open.");
    }

}
void save_list(Record list[], int count){
    fstream f;
    open_fileW(f, "record_list.bin");
    for (int i= 0; i<count; i++){
        list[i].write(f);
    }
    f.close();

}

int main(int argc, char *argv[])
{
    cout <<endl<<endl<<endl<< "================================" << endl;
//    Record list[10] = {"zero",
//                       "one",
//                       "two",
//                       "three",
//                       "four",
//                       "five",
//                       "six",
//                       "seven",
//                       "eight",
//                       "nine"};
//    for (int i = 0; i< 10; i++){
//        cout<<list[i]<<endl;
//    }
//    save_list(list, 10);


//    Record r;
//    fstream f;
//    open_fileRW(f, "record_list.bin" );
//    r.read(f, 3);
//    cout<<"record 3: "<<r<<endl;
//    r.read(f, 6);
//    cout<<"record 6: "<<r<<endl;

//    cout <<endl<<endl<<endl<< "================================" << endl;
    vector<string> v1;
    v1.push_back("123");
    v1.push_back("abc");
    char a[10][10];
   // cout<<a[0];
    strcpy(a[0],v1[0].c_str());
    strcpy(a[1],v1[1].c_str());
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<a[i][j]<<"|";
        }
        cout<<endl;
    }
    return 0;
}
