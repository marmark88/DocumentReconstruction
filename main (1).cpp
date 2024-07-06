// Mark Cubi
// April 26, 2024
// C++ code to test document reconstruction functions

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "docrec.h"

using namespace std;

int main()
{
	// variable declaration
	string document;
	vector<string> fixedDoc; 
	bool canFix;
	
	// Test case #1
	cout << "Dictionary words = {it, was, the, best, of, times, a, i, to, be, me}" << endl;
	cout << "Test case #1: document = itwasthebestoftimesthetimesofbestitwas" << endl; 
	document = "itwasthebestoftimesthetimesofbestitwas";

	fixedDoc = reconstructDoc(document, canFix); // fixes corrupted document

	for(int i = 0; i < fixedDoc.size(); i++) // outputs words
	{
		cout << fixedDoc[i] << " ";
	} 
	cout << endl;

	if(canFix) // determines if the document was completely fixed
		cout << "We have successfully reconstructed your document!" << endl;
	else
		cout << "We could not fully reconstruct your document!" << endl;
	
	// repeat same process for Test case #2
	cout << "Test case #2: document = waswastheittimes" << endl;
	document = "waswastheittimes";
	
	fixedDoc = reconstructDoc(document, canFix);

	for(int i = 0; i < fixedDoc.size(); i++)
	{
		cout << fixedDoc[i] << " ";
	} 
	cout << endl;

	if(canFix)
		cout << "We have successfully reconstructed your document!" << endl;
	else
		cout << "We could not fully reconstruct your document!" << endl;

	// repeat same process for Test case #3
	cout << "Test case #3: document = itwasthetimesbestinnewyork" << endl;
	document = "itwasthetimesbestinnewyork";

	fixedDoc = reconstructDoc(document, canFix);

	for(int i = 0; i < fixedDoc.size(); i++)
	{
		cout << fixedDoc[i] << " ";
	} 
	cout << endl;

	if(canFix)
		cout << "We have successfully reconstructed your document!" << endl;
	else
		cout << "We could not fully reconstruct your document!" << endl;
	return 0;
	
}
