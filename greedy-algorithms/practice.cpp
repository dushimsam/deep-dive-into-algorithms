#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Huffman_Codes
{
	struct New_Node
	{
		char data;
		size_t freq;
		New_Node* left;
		New_Node* right;

		New_Node(char data, size_t freq) : data(data),
			freq(freq),
			left(NULL),
			right(NULL)
		{}
		~New_Node()
		{
			delete left;
			delete right;
		}
	};

	struct compare
	{
		bool operator()(New_Node* l, New_Node* r)
		{
			return (l->freq > r->freq);
		}
	};

	New_Node* top;

	void print_Code(New_Node* root, string str)
	{
		if (root == NULL)
			return;

		if (root->data != '$')
		{
			cout << root->data << " : " << str << "\n";
		}

		print_Code(root->left, str + "0");
		print_Code(root->right, str + "1");
	}

public:
	Huffman_Codes() {};
	~Huffman_Codes()
	{
		delete top;
	}
	void Generate_Huffman_tree(vector<char>& data, vector<size_t>& freq, size_t size)
	{
		New_Node* left;
		New_Node* right;
		priority_queue<New_Node*, vector<New_Node*>, compare > minHeap;

		for (size_t i = 0; i < size; ++i)
		{
			minHeap.push(new New_Node(data[i], freq[i]));
		}

		while (minHeap.size() != 1)
		{
			left = minHeap.top();
			minHeap.pop();

			right = minHeap.top();
			minHeap.pop();

			top = new New_Node('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			minHeap.push(top);
		}
		print_Code(minHeap.top(), "");
	}
};

int main()
{
  vector<int> arr ={4,5,6,7,8};
  arr.erase(arr.begin(),arr.begin()+1);
  for(int i = 0; i < arr.size(); ++i)
     cout<<"\n"<<arr[i]<<endl;

	return 0;
}
