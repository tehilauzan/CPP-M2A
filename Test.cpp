#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace family;

TEST_CASE("Test functions-A,B.C tree") {
    family::Tree T3 ("A");
    T3.addFather("A", "B")
            .addMother("A", "C")
            .addFather("C", "D")
            .addMother("C", "E")
            .addMother("E", "F")
            .addFather("E", "G")
            .addFather("G", "H");
    //test realation function
            CHECK( T3.relation("B") ==string("Father"));
            CHECK( T3.relation("C") ==string("Mother"));
            CHECK( T3.relation("D") ==string("grandfather"));
            CHECK( T3.relation("E") ==string("grandmother"));
            CHECK( T3.relation("G") ==string("great-grandfather"));
            CHECK( T3.relation("F") ==string("great-grandmother"));
            CHECK( T3.relation("H") ==string("great-great-grandfather"));
            CHECK( T3.relation("xyt") ==string("unrelated"));
            CHECK( T3.relation("xsdsd") ==string("unrelated"));
            CHECK( T3.relation("xytsdadsc") ==string("unrelated"));
            CHECK( T3.relation("xytasdsad") ==string("unrelated"));
            CHECK( T3.relation("xytasdas") ==string("unrelated"));
            CHECK( T3.relation("xytasdasdas") ==string("unrelated"));
            CHECK( T3.relation("xytasdasd") ==string("unrelated"));
            CHECK( T3.relation("xytcascsc") ==string("unrelated"));
            CHECK( T3.relation("xyascsacsat") ==string("unrelated"));
            CHECK( T3.relation("xyzxczxczxt") ==string("unrelated"));
            CHECK( T3.relation("xzxcxzcyt") ==string("unrelated"));
            CHECK( T3.relation("xytzxczxczx") ==string("unrelated"));
            CHECK( T3.relation("xyzxczxct") ==string("unrelated"));
            CHECK( T3.relation("xyzxczxct") ==string("unrelated"));
            CHECK( T3.relation("xyczxxczt") ==string("unrelated"));
            CHECK( T3.relation("xytzxczxc") ==string("unrelated"));
            CHECK( T3.relation("xytxzcxzcz") ==string("unrelated"));
            CHECK( T3.relation("xyzxcxzct") ==string("unrelated"));
            CHECK(T3.relation("A")==string("me"));
    //test find function
            CHECK(T3.find("mother")==string("C"));
            CHECK(T3.find("father")==string("B"));
            CHECK(T3.find("grandmother")==string("E"));
            CHECK(T3.find("grandfather")==string("D"));
            CHECK(T3.find("me")==string("A"));
            CHECK(T3.find("great-grandmother")==string("F"));
            CHECK(T3.find("great-grandfather")==string("G"));
            CHECK(T3.find("great-great-grandfather")==string("H"));
    T3.remove("E");
    ////exception relation afret remove 'E' in Tree
            cout<<T3.relation("E");
            CHECK_THROWS(T3.relation("E"));
            CHECK_THROWS(T3.relation("G"));
            CHECK_THROWS(T3.relation("H"));
            CHECK_THROWS(T3.relation("F"));
    ///exception find after remove 'E' in Tree
         //   CHECK_THROWS(T2.find("grandmother");
//            CHECK_THROWS(T3.find("great-grandfather"));
//            CHECK_THROWS(T3.find("great-great-grandfather"));
//            CHECK_THROWS(T3.find("great-grandmother"));
    //remove the root in the Tree
     CHECK_THROWS(T3.remove("A"));


}
TEST_CASE("test all functions in yosef tree") {
    family::Tree T("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov") == string("father"));
            CHECK(T.relation("Rachel") == string("mother"));
            CHECK(T.relation("Rivka") == string("grandmother"));
            CHECK(T.relation("Avraham") == string("great-grandfather"));
            CHECK(T.relation("Terah") == string("great-great-grandfather"));
            CHECK(T.relation("xyz") == string("unrelated"));
            CHECK(T.relation("sdsd") == string("unrelated"));
            CHECK(T.relation("xDsd") == string("unrelated"));
            CHECK(T.relation("xXDF") == string("unrelated"));
            CHECK(T.relation("DDD") == string("unrelated"));
            CHECK(T.relation("fF") == string("unrelated"));
            CHECK(T.relation("vVV") == string("unrelated"));
            CHECK(T.relation("FFV") == string("unrelated"));
            CHECK(T.relation("VVVVVC") == string("unrelated"));
            CHECK(T.relation("CVVVC") == string("unrelated"));
            CHECK(T.relation("VXV") == string("unrelated"));
            CHECK(T.relation("FDFD") == string("unrelated"));
            CHECK(T.relation("dfdfs") == string("unrelated"));
            CHECK(T.relation("asdsad") == string("unrelated"));
            CHECK(T.relation("pop") == string("unrelated"));
            CHECK(T.relation("poop") == string("unrelated"));
            CHECK(T.relation("Yosef") == string("me"));
    //test find function
            CHECK(T.find("mother") == string("Rachel"));
            CHECK(T.find("father") == string("Yaakov"));
            CHECK(T.find("grandmother") == string("Rivka"));
            CHECK(T.find("grandfather") == string("Isaac"));
            CHECK(T.find("me") == string("Yosef"));
            CHECK(T.find("great-grandmother") == string("Sarah"));
            CHECK(T.find("great-grandfather") == string("Avraham"));
            CHECK(T.find("great-great-grandfather") == string("Terah"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham") == string("unrelated"));
            CHECK(T.relation("Terah") == string("unrelated"));
            CHECK(T.relation("Yaakov") == string("father"));
    T.addFather("Yaakov", "Isaac");
            CHECK(T.relation("Isaac") == string("grandfather"));
    //remove the root in the Tree
            CHECK_THROWS(T.remove("Yosef"));
}
TEST_CASE("test tree"){
    family::Tree T("david"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("david", "asher")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("david", "dalia")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("asher", "david")
            .addMother("asher", "zina")
            .addFather("dalia", "haim")
            .addMother("dalia", "frida");
    //test relation functions
            CHECK(T.relation("asher") == string("father"));
            CHECK(T.relation("dalia") == string("mother"));
            CHECK(T.relation("zina") == string("grandmother"));
            CHECK(T.relation("xyzz") == string("unrelated"));
            CHECK(T.relation("xyzzzz") == string("unrelated"));
            CHECK(T.relation("xyzxx") == string("unrelated"));
            CHECK(T.relation("xyzccc") == string("unrelated"));
            CHECK(T.relation("xyzdd") == string("unrelated"));
            CHECK(T.relation("xyzff") == string("unrelated"));
            CHECK(T.relation("xyzdfd") == string("unrelated"));
            CHECK(T.relation("xyzdfd") == string("unrelated"));
            CHECK(T.relation("xyzfdf") == string("unrelated"));
            CHECK(T.relation("Yosefdffd") == string("unrelated"));
            CHECK(T.relation("Yosefdffddf") == string("unrelated"));
            CHECK(T.relation("Yosefdffddfd") == string("unrelated"));
            CHECK(T.relation("Yosefdffdfdf") == string("unrelated"));
            CHECK(T.relation("Yosefdffddfd") == string("unrelated"));
            CHECK(T.relation("Yosefdffdfdf") == string("unrelated"));
            CHECK(T.relation("Yosefdffddfdf") == string("unrelated"));
            CHECK(T.relation("Yosefdffddff") == string("unrelated"));
    //test find function
            CHECK(T.find("mother") == string("dalia"));
            CHECK(T.find("father") == string("asher"));
            CHECK(T.find("grandmother") == string("frida"));
            CHECK(T.find("grandfather") == string("david"));
            CHECK(T.find("me") == string("david"));


    //remove the root in the Tree
            CHECK_THROWS(T.remove("Yosef"));
}


