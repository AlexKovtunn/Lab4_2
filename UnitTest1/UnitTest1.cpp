#include "pch.h"
#include "CppUnitTest.h"
#include "../lab2/HaffmanTree.h"
#include "../lab2/list.h"
#include "../lab2/queue.h"
#include "../lab2/RBTree.h"
#include "../lab2/lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(RLK_Test_plus_toRbTree_Test)
		{
			string input = "abcaba";
			list<HaffmanTree*> listOfHaffmanTrees;
			RBTree<char, int> rbtree;
			int tempVal;
			for (int i = 0; i < input.length(); i++) {
				if (rbtree.find(input[i]) == 0) {
					rbtree.insert(input[i], 1);
				}
				else {
					tempVal = rbtree.find(input[i]);
					rbtree.remove(input[i]);
					rbtree.insert(input[i], tempVal + 1);
				}
			}
			RBTree<char, int>::iterator it(&rbtree);
			++it;
			for (int i = 0; i < rbtree.getSize(); i++) {
				listOfHaffmanTrees.push(new HaffmanTree(*it, it.getValue()));
				++it;
			}
			while (listOfHaffmanTrees.getSize() != 1) {
				listOfHaffmanTrees.sort();
				listOfHaffmanTrees.push(new HaffmanTree(listOfHaffmanTrees.pop(0), listOfHaffmanTrees.pop(1)));
			}

			HaffmanTree* haffmanTree = listOfHaffmanTrees.pop(0);


			haffmanTree->RLK(haffmanTree->getRoot());

			RBTree<char, string> haffmanTable;
			haffmanTree->toRbTree(&haffmanTable, haffmanTree->getRoot());

			Assert::IsTrue(haffmanTable.find('a') == "0" && haffmanTable.find('b') == "11" && haffmanTable.find('c') == "10");
		}
		TEST_METHOD(decode_Test)
		{
			string input = "abcaba";
			list<HaffmanTree*> listOfHaffmanTrees;
			RBTree<char, int> rbtree;
			int tempVal;
			for (int i = 0; i < input.length(); i++) {
				if (rbtree.find(input[i]) == 0) {
					rbtree.insert(input[i], 1);
				}
				else {
					tempVal = rbtree.find(input[i]);
					rbtree.remove(input[i]);
					rbtree.insert(input[i], tempVal + 1);
				}
			}
			RBTree<char, int>::iterator it(&rbtree);
			++it;
			for (int i = 0; i < rbtree.getSize(); i++) {
				listOfHaffmanTrees.push(new HaffmanTree(*it, it.getValue()));
				++it;
			}
			while (listOfHaffmanTrees.getSize() != 1) {
				listOfHaffmanTrees.sort();
				listOfHaffmanTrees.push(new HaffmanTree(listOfHaffmanTrees.pop(0), listOfHaffmanTrees.pop(1)));
			}

			HaffmanTree* haffmanTree = listOfHaffmanTrees.pop(0);


			haffmanTree->RLK(haffmanTree->getRoot());

			RBTree<char, string> haffmanTable;
			haffmanTree->toRbTree(&haffmanTable, haffmanTree->getRoot());

			string encodeInput = "";
			for (int i = 0; i < input.length(); i++) {
				encodeInput += haffmanTable.find(input[i]);
			}

			Assert::IsTrue(haffmanTree->decode(encodeInput) == "abcaba");
		}
	};
}