/**CS515 Assignment 7
   File: mapTest.cpp
   Name: Ajesh Vijay Vijayaragavan
   Section: 01
   Date: 03/30/2017
   Collaboration Declaration: Assistance received from TA, PAC and Online resources.
*/  

/* These are test for map inerface methods using Google Test */
#include "map.h"
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

//The constructor should create a map with zero size
TEST(MapTest, constructorCreatesZeroSizeMap)
{
Map mapT;
EXPECT_EQ(0, mapT.size());
}

//Inserting into an empty map should return true and result in a size of one
TEST(MapTest, insertWhileEmptyReturnsTrueAndMapSizeIsOne)
{
 Map mapT;
 EXPECT_TRUE(mapT.insert("ab","abc"));
 EXPECT_EQ(1, mapT.size()); 
}

//Inserting a key that already exists should fail and not change the map size
TEST(MapTest, insertOfSameKeyReturnsFalseAndMapSizeRemainsSame)
{
 Map mapT;
 mapT.insert("ab", "abc");
 EXPECT_FALSE(mapT.insert("ab", "abc")); 
// EXPECT_FALSE(mapT.insert("ab", "abcd"));
 EXPECT_EQ(1, mapT.size()); 
}

//Accessing an existing item using [] should return correct value and not
//change the map size
TEST(MapTest, indexOperatorOfExistingKeyReturnsProperValueAndSizeIsSame)
{
  Map mapT;
  mapT.insert("ab", "abc");
//  EXPECT_EQ(mapT["ab"], "abc");
  EXPECT_EQ("abc", mapT["ab"]);
  EXPECT_EQ(1, mapT.size());
}
    
//Using [] to set an item in an empty map should add the item with an
//appropriate value and increase the map size to one
TEST(MapTest, indexOperatorOnEmptyMapProperlySetsValueAndSizeIsOne)
{
  Map mapT;
  EXPECT_EQ(0, mapT.size());
  mapT["ab"] = "abc";
  EXPECT_EQ("abc", mapT["ab"]);
  EXPECT_EQ(1, mapT.size());
}

//Using [] to set an item in a map that already contains other items
//inserts and updates the size appropriately
TEST(MapTest, indexOperatorOnMissingKeyProperlySetsValueAndIncrementsSize)
{ 
  Map mapT;
  mapT.insert("1", "ab");
  mapT.insert("3", "cd");
  EXPECT_EQ(2, mapT.size());
  mapT["2"] = "ef";
  EXPECT_EQ("ef", mapT["2"]);
  EXPECT_EQ(3, mapT.size());
}

//Test for find()
TEST(MapTest, returniteratortotheelementortotheend)
{
 Map mapT;
 mapT.insert("1", "ab");
 mapT.insert("2", "cd");
// EXPECT_EQ("ab", mapT.find("1"));
}

//Test for begin() and end()
TEST(MapTest, beginandend)
{
 Map mapT;
 mapT.insert("1", "ab");
 mapT.insert("2", "cd");
}

//Test for iterator operators
TEST(MapTest, iteratoroperators)
{
}	


//Erasing a key that exists in the map succeeds and decrements the map size
TEST(MapTest, eraseOfExistingKeyReturnsTrueAndDecrementsSize)
{
  Map mapT;
  mapT.insert("1", "ab");
  mapT.insert("2", "cd");
  mapT.insert("3", "ef");
  EXPECT_EQ(3, mapT.size());
  EXPECT_TRUE(mapT.erase("3"));
  EXPECT_EQ(2, mapT.size());
  EXPECT_TRUE(mapT.erase("2"));
  EXPECT_EQ(1, mapT.size());
  //EXPECT_TRUE(mapT.erase("1"));
  //EXPECT_EQ(0, mapT.size());
}

//Erase on an empty map fails and keeps the map size at zero
TEST(MapTest, eraseOnEmptyMapReturnsFalseAndSizeRemainsZero)
{
 Map mapT;
 //EXPECT_EQ(0, mapT.size());
 EXPECT_FALSE(mapT.erase("1"));
 EXPECT_EQ(0, mapT.size()); 
}

//Erase of a non-existant key fails and does not change the map size
TEST(MapTest, eraseOfMissingKeyReturnsFalseAndSizeRemainsSame)
{ 
 Map mapT;
 mapT.insert("1", "a");
 mapT.insert("2", "b");
 mapT.insert("3", "c");
 EXPECT_EQ(3, mapT.size());
 EXPECT_FALSE(mapT.erase("4"));
 EXPECT_EQ(3, mapT.size());
}


//Using the copy constructor results in two maps of the same, correct size
TEST(MapTest, copyConstructorMakesCorrectSize)
{
 Map mapT;
 mapT.insert("1", "a");
 mapT.insert("2", "b");
 mapT.insert("3", "c");
 int k = mapT.size();
 Map c(mapT);
 int csize = c.size();
 EXPECT_EQ(k, csize);
 EXPECT_EQ(mapT.size(),c.size());
 EXPECT_EQ(3, mapT.size());
 EXPECT_EQ(3, c.size());
}

//Using the copy constructor with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, copyConstructorMakesSeparateCopy)
{
 Map mapT;
 mapT.insert("1", "a");
 mapT.insert("2", "b");
 mapT.insert("3", "c");
 Map q(mapT);
 q["1"] = "hi";
 EXPECT_EQ("a", mapT["1"]);
 q.insert("4", "d");
 EXPECT_EQ(3, mapT.size());
 q.erase("4");
 EXPECT_EQ(3, mapT.size());
 mapT.insert("4", "d");
 EXPECT_EQ(3, q.size());
 mapT.erase("4");
 EXPECT_EQ(3, q.size());
}

//Using the assignment operator results in two maps of the same, correct size
TEST(MapTest, assignmentOperatorMakesCorrectSize)
{
 Map mapT, s;
 Map copy = mapT;
 EXPECT_EQ(mapT.size(), copy.size());

 mapT.insert("1", "a");
 mapT.insert("2", "b");
 mapT.insert("3", "c");
 s = mapT;
 EXPECT_EQ(s.size(), mapT.size());
}


//Using the assignment operator with an existing map makes its own
//copy, such that if the value associated with a key is changed
//in the copy it does not change the associated value in the
//original, and inserts/erases on either won't affect the other.
TEST(MapTest, assignmentMakesSeparateCopy)
{
   Map mapT;
   mapT.insert("1", "a");
   mapT.insert("2", "b");
   mapT.insert("3", "c");
   Map q = mapT;
   q["1"] = "hi";
   EXPECT_EQ("a", mapT["1"]);
   q.insert("4", "d");
   EXPECT_EQ(3, mapT.size());
   q.erase("4");
   EXPECT_EQ(3, mapT.size());
   mapT.insert("4", "d");
   EXPECT_EQ(3, q.size());
   mapT.erase("4");
   EXPECT_EQ(3, q.size());		       
}


//Using the assignment operator with an existing map with over 1000 items
//makes a copy that has correct keys/values at a couple of places deep within
//the map (values that aren't at either end of the range of keys used).
TEST(MapTest, assignmentWithManyItemsHasCorrectValues)
{
 Map mapT, z;
 for (int i=0; i<1000; i++)
 {
  string a = to_string(i);
  string b = to_string(i);
  mapT.insert(a,b);
 }
 EXPECT_EQ(mapT.size(),1000);
 z = mapT;
 EXPECT_EQ(z.size(),1000);
 for (int i=0; i<10; i++)
 {
  string c = to_string(i);
  EXPECT_EQ(z[c],c);
  EXPECT_EQ(z[c],mapT[c]); 
 }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
