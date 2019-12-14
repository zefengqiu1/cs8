#ifndef BPTABLE_H
#define BPTABLE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "record.h"
#include "../B+_tree/map.h"
#include "../B+_tree/mmap.h"

//#include "../../Includes/BPTree/record.h"
//#include "../../Includes/BPTree/bpmmap.h"
//#include "../../Includes/BPTree/bpmap.h"

using namespace std;

//typedef my_vector<string> vectorstr;

//static long serial_num = 1;


class BPTable
{
public:
    BPTable(string filename, vectorstr fields);
    BPTable(string filename);
//    ~BPTable() {
//    }

    void insert_into(vectorstr v);
    void set_fields(vectorstr fields);
    vectorstr get_fields();
    void write_info();
    void print(ostream& outs) const;
    void print_inices(ostream& outs=cout) const ;

   // BPTable select(vectorstr field_vector, vectorstr condition);
    BPTable select_all();
    //bool empty() {};
    friend ostream& operator<<(ostream& outs, const BPTable& print_me){
        print_me.print(outs);
        return outs;
    }
private:
    string postfix = "_fields.txt";
    string binary_postfix = ".bin";

    string field_fname;
    string binary_fname;
    vectorstr field_v;
    vector<MMap<string, long> > indices;
    Map<string, long> field_map;

    long last_record_number;
};


BPTable::BPTable(string filename, vectorstr fields) {
    fstream _f;

  //  string postfix = "_fields.txt";
  //  string field_postfix = ".bin";

    // set file names
    field_fname = filename + postfix ;
    binary_fname = filename + binary_postfix ;

    // create binary file
    open_fileW(_f, binary_fname.c_str());
    _f.close();

    set_fields(fields);
    write_info();
    last_record_number = 0;
}

BPTable::BPTable(string filename) {
    fstream _f;
    // create binary file
    field_fname = filename + postfix ;
    binary_fname = filename + binary_postfix ;
    //field_v = get_fields();


    open_fileRW(_f, binary_fname.c_str());
    _f.close();

      set_fields(get_fields());
//    Record r;
//    long index = 0;
//    long end_no = r.read(_f, index)/5000;

//    while(end_no > 0) {
//        vectorstr value = r.get_fields_value();
//        cout<<value<<endl;
//        for(int i=0;i<value.size();i++)
//        {
//             indices[i][value[i]]+=index;
//           // indices[i][value[i]].push_back(index);
//            //indices[i].insert(value[i],index);
//           // indices[i][value[i]].push_back(index);
//                 //   +=index;//pos always next record
//        }
//        last_record_number++;
//        index ++ ;
//        end_no = r.read(_f, index);
//    }
//    _f.close();

    /*

    while (pos>0) {
       vectorstr value=r.get_fields_value();
       for(int i=0;i<value.size();i++)
       {
           indices[i][value[i]]+=pos-1;//pos always next record
       }
       last_record_number++;
       pos=r.read(f,pos);
    }

*/



}


void BPTable::insert_into(vectorstr v) {
    fstream f;
    open_fileRW(f, binary_fname.c_str());
    Record  r(v);
    // get recno
    long no = r.write(f)/5000;
    f.close();

    for(int i = 0 ; i < v.size() ; i ++ ) {
        indices[i][v[i]].push_back(no);
        vector<int> v;
        v.push_back(no);
    }

    last_record_number++;
}


//BPTable BPTable::select(vectorstr field_vector, vectorstr condition) {
//    fstream _f;
//    char* temp_name = "temp_student.tbl";
//    BPTable t(temp_name, field_vector);
//    long index = field_map[condition[0]];
//    vector<long> v = indices[index][condition[2]];
//    open_fileRW(_f, binary_fname.c_str());
//    for(int i = 0; i < v.size(); i ++ ) {
//        Record r;
//        r.read(_f, v[i]);
//        cout << "record" << v[i] <<": " << r <<endl;

//        vectorstr temp = r.get_fields_value();
//        vectorstr temp2;
//        // insert field value for field in vector
//        for(int i = 0 ; i < field_vector.size(); i ++ ) {
//            int j = field_map[field_vector[i]];
//            temp2.push_back(temp[j]);
//        }
//        cout << temp2 << endl;
//        t.insert_into(temp2);
//    }
//    _f.close();
//    return t;
//}


BPTable BPTable::select_all() {
    fstream _f;
    string temp_name = "temp_student";
    Record r;
    BPTable t(temp_name, field_v);
    open_fileRW(_f, binary_fname.c_str());
    long index = 0;
    long end_no = r.read(_f, index)/5000;

    while(end_no > 0) {
        vectorstr v = r.get_fields_value();
        t.insert_into(v);
        index ++ ;
        end_no = r.read(_f, index);
    }
    _f.close();
    return t;
}


void BPTable::set_fields(vectorstr fields) {
    // push index into indeces
    for(int i = 0 ; i < fields.size(); i ++ ){
        indices.push_back(MMap<string,long > ());
    }
    // push name into field_map
    for(long i = 0 ; i < fields.size(); i ++) {
       // cout << "fields: " << fields[i] << " index: " << i <<endl;
        field_map.insert(fields[i], i);
    }
    field_v = fields;
}


void BPTable::write_info() { //write to field name.txt
    // write the field name into txt file
    ofstream _ff = ofstream(field_fname);
    for(int i = 0 ; i < field_v.size(); i ++) {
        _ff << field_v[i] << " ";
    }
    _ff.close();
}

vectorstr BPTable::get_fields() {
    vectorstr v;
     ifstream _ff = ifstream(field_fname);
     while(!_ff.eof()) {
         string s;
         _ff >> s;
         v.push_back(s);
        // cout << "get_fields: " << s <<endl;
     }
     _ff.close();
     return v;
}


void BPTable::print(ostream& outs) const {
    fstream _f;
    cout << setw << field_v <<endl;
    open_fileRW(_f, binary_fname.c_str());
    Record r;
    long index = 0;
    long end_no = r.read(_f, index)/5000;

    while(end_no > 0) {
        vectorstr v = r.get_fields_value();
        cout << v <<endl;
        index ++ ;
        end_no = r.read(_f, index);
    }
    _f.close();
}


void BPTable::print_inices(ostream &outs) const {
    for(int i = 0 ; i < field_v.size(); i ++) {
        cout << indices[i] <<endl;
    }
}

#endif // BPTABLE_H
