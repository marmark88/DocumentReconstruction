// Mark Cubi
// April 26, 2024
// C++ code to implement document reconstruction functions

#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* find whether a given word can be found in a list of words in the dictionary
@param word: word to be checked
@pre-condition: word is not empty
@post-condition: return true or false based on if the word can be found in the word list defined in the function
*/
bool dict(string word)
{
	// predefined list of words 
	unordered_set<string> wordList = {"it", "was", "the", "best", "of", "times", "a", "i", "to", "be", "me"};
	
	if(wordList.find(word) != wordList.end()) // if set does not return iterator to end of
		return true;			  // wordList, then it found the word
	else
		return false;			  // otherwise, it did not find the word
}

/* reconstruct a text document given by a string of n characters s[1...n] to restore proper spacing by separating words
@param doc: text document to be fixed
@param canReconstruct: keeps track if document can be fully reconstructed
@pre-condition: doc is not empty
@post-condition: return corresponding sequence of words in doc, also canReconstruct is set to true or false based on if
		 the document's words could be fully reconstructed
*/
vector<string> reconstructDoc(string doc, bool& canReconstruct)
{
	int docSize = doc.length();
	vector<int> firstIndex(docSize+1, -1);   // stores where word begins in document
	vector<string> stringSequence; // keeps track of sequence of words in document
	vector<bool> dp(docSize+1, false); // make dp table the size of whole string including empty space for when the document is empty
					 // and initalizing all elements to false to keep track of index of valid words
	
	dp[0] = true; // when string is empty it is true, no words needed to separate

	for(int i = 1; i <= docSize; i++) // check document for possible words
	{
		for(int j = i - 1; j >= 0; j--)
		{
			string testString = doc.substr(j, i - j);
			if(dp[j] && dict(testString)) // if substring of document contains a word, and there is a word before its first character
			{			      // then the word preserves the sequence
				dp[i] = true;
				firstIndex[i] = j;
				break;
			}
		}
	}

	if(dp[docSize]) // if dp of the end of document is true, then the whole document has been separted into a sequence of words
		canReconstruct = true;
	else
		canReconstruct = false;
	
	string fixedString;
	int index = docSize;
	while (index > 0)
	{
		if(dp[index] == true && dp[firstIndex[index]] == true) // finds path where word at end of document is preceeded by another valid word
		{						       // allowing the correct word sequence to be chosen that satisifes whole document
			fixedString = doc.substr(firstIndex[index], index - firstIndex[index]);
			stringSequence.push_back(fixedString);
			index = firstIndex[index]; // skips to next valid word once current one is added
		}	
		else
			index--; // if not vaid word was at index, decrement till one is found
	}

	reverse(stringSequence.begin(),stringSequence.end()); // reverse sequence so it appears as progressing from front...end of document
	return stringSequence;
}
