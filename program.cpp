// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "btree.h"

bool checkVectorOfEntriesInNode(NodeOfBTree* node, std::vector<int> vec)
{
	if (node->getVectorOfEntries().size() != vec.size())
		return false;
	
	for (int index = 0; index < vec.size(); ++index)
	{
		if (node->getVectorOfEntries().at(index) != vec.at(index))
			return false;
	}
	
	return true;
}

bool checkCountOfChilds(NodeOfBTree* node, int count)
{
	return node->getVectorOfPointers().size() == count;
}

TEST_CASE( "Testing the insert call in the btree", "[single-file]" )
{
	BTree b (5);
	b.insert(50);
	
	NodeOfBTree* root = b.getRoot();
	
	REQUIRE( root != nullptr);
	REQUIRE( checkVectorOfEntriesInNode(root, {50}));
	
	b.insert(40);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {40,50}));
	
	b.insert(60);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {40,50,60}));
	
	b.insert(70);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {40,50,60,70}));
	
	b.insert(80);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {60}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,50}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,80}));
	
	b.insert(90);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {60}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,50}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,80,90}));
	
	b.insert(45);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {60}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,45,50}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,80,90}));
	
	b.insert(55);
	
	REQUIRE( checkVectorOfEntriesInNode(root, {60}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,45,50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,80,90}));
	
	b.insert(85);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{60}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,45,50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,80,85,90}));
	
	b.insert(75);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,45,50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {85,90}));
	
	b.insert(65);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {40,45,50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {85,90}));
	
	b.insert(35);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {85,90}));
	
	b.insert(30);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {30,35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {85,90}));
	
	b.insert(20);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,30,35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {85,90}));
	
	b.insert(21);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{30,45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {85,90}));
	
	b.insert(22);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{30,45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,21,22}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {85,90}));
	
	b.insert(23);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{30,45,60,80}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,21,22,23}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {85,90}));
	
	b.insert(25);
	root = b.getRoot();
	NodeOfBTree* leftChild = root->pointerByIndex(0);
	NodeOfBTree* rightChild = root->pointerByIndex(1);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45}));
	
	REQUIRE(checkVectorOfEntriesInNode(leftChild,{22,30}));
	
	REQUIRE(checkVectorOfEntriesInNode(rightChild,{60,80}));
	
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(1), {23,25}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(2), {35,40}));
	
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(0), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(1), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(2), {85,90}));
}

TEST_CASE( "Testing the remove call in the btree", "[single-file]" )
{
	BTree b (5);
	
	b.insert(50);
	b.insert(40);
	b.insert(60);
	b.insert(70);
	b.insert(80);
	b.insert(90);
	b.insert(45);
	b.insert(55);
	b.insert(85);
	b.insert(75);
	b.insert(65);
	b.insert(35);
	b.insert(30);
	b.insert(20);
	b.insert(21);
	b.insert(22);
	b.insert(23);
	b.insert(25);
	
	NodeOfBTree* root = b.getRoot();
	
	NodeOfBTree* leftChild = root->pointerByIndex(0);
	NodeOfBTree* rightChild = root->pointerByIndex(1);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45}));
	
	REQUIRE(checkVectorOfEntriesInNode(leftChild,{22,30}));
	
	REQUIRE(checkVectorOfEntriesInNode(rightChild,{60,80}));
	
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(1), {23,25}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(2), {35,40}));
	
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(0), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(1), {65,70,75}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(2), {85,90}));
	
	//This is the initial state
	
	//1 st remove
	b.remove(90);
	
	root = b.getRoot();
	
	leftChild = root->pointerByIndex(0);
	rightChild = root->pointerByIndex(1);
	
	REQUIRE(checkVectorOfEntriesInNode(root,{45}));
	
	REQUIRE(checkVectorOfEntriesInNode(leftChild,{22,30}));
	
	REQUIRE(checkVectorOfEntriesInNode(rightChild,{60,75}));
	
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(1), {23,25}));
	REQUIRE( checkVectorOfEntriesInNode(leftChild->pointerByIndex(2), {35,40}));
	
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(0), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(1), {65,70}));
	REQUIRE( checkVectorOfEntriesInNode(rightChild->pointerByIndex(2), {80,85}));
	
	//2 nd remove
	b.remove(85); //aqui
	
	root = b.getRoot();
	
	REQUIRE(checkVectorOfEntriesInNode(root,{22,30, 45, 60}));
	
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {23,25}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {65,70,75,80}));
	
	//insert
	b.insert(26);
	
	root = b.getRoot();
	
	REQUIRE(checkVectorOfEntriesInNode(root,{22,30, 45, 60}));
	
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,21}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {23,25,26}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {65,70,75,80}));
	
	//3 rd remove
	b.remove(21);
	
	root = b.getRoot();
	
	REQUIRE(checkVectorOfEntriesInNode(root,{23,30,45,60}));
	
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,22}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {25,26}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {65,70,75,80}));
	
	//insert
	b.insert(56);
	
	root = b.getRoot();
	
	REQUIRE(checkVectorOfEntriesInNode(root,{23,30,45,60}));
	
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,22}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {25,26}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {50,55,56}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {65,70,75,80}));
	
	//remove no leaf
	b.remove(60);
	
	root = b.getRoot();
	
	REQUIRE(checkVectorOfEntriesInNode(root,{23,30,45,56}));
	
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(0), {20,22}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(1), {25,26}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(2), {35,40}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(3), {50,55}));
	REQUIRE( checkVectorOfEntriesInNode(root->pointerByIndex(4), {65,70,75,80}));
}

TEST_CASE( "Testing the search call in the btree", "[single-file]" )
{
	BTree b (5);
	
	std::vector<int> toInsert = 
	{50,40,60,70,80,90,45,55,85,75,65,35,30,20,21,22,23,25};
	
	for (auto number: toInsert)
		b.insert(number);
	
	for (auto number: toInsert)
		REQUIRE(b.search(number) != nullptr);
}

TEST_CASE( "Testing the search call in the btree, second way", "[single-file]" )
{
	BTree b (5);
	
	std::vector<int> toInsert = 
	{50,40,60,70,80,90,45,55,85,75,65,35,30,20,21,22,23,25};
	
	for (auto number: toInsert)
		b.insert(number);

	std::vector<int> toRemove = 
	{90,85,21,60};
	
	for (auto number: toRemove)
		b.remove(number);
	
	for (auto number: toRemove)
		REQUIRE(b.search(number) == nullptr);
}

TEST_CASE( "Testing the insertion call of duplicated entries in the btree", "[single-file]" )
{
	BTree b (5);
	
	REQUIRE(b.insert(50));
	REQUIRE(b.insert(40));
	REQUIRE(b.insert(60));
	REQUIRE(b.insert(70));
	
	REQUIRE(!b.insert(50));
	REQUIRE(!b.insert(40));
	REQUIRE(!b.insert(60));
	REQUIRE(!b.insert(70));
	
}