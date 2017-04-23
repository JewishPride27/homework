#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>

struct node
{
int frequency;
char symbol;
node *left;
node *right;

node()
{
left = NULL;
right = NULL;
symbol = 0;

}

node(node *l, node *r)
{
left = l;
right = r;
frequency = l->frequency + r->frequency;
}
};

struct my_compare
{
bool operator()(node* l, node* r) const
{
return l->frequency < r->frequency;
}
};

std::vector<bool> code;
std::map<char,std::vector<bool>> table;

void build_table(node *root)
{
if(root->left != NULL)
{
code.push_back(0);
build_table(root->left);
}

if(root->right != NULL)
{
code.push_back(1);
build_table(root->right);
}

if(root->symbol)
{
table[root->symbol] = code;

if(code.size())
{
code.pop_back();
}
}

node* Huffman()
{

std::string file_name;
std::string str;

std::cout << "Enter file path: ";
std::cin >> file_name;

std::ifstream file(file_name);

while(file)
{
getline(file,str);
}

std::cout << str << std::endl;
std::map <char,int> _map;

for(int i = 0; i < str.length();i++)
{
char symbol = str[i];
_map[symbol]++;
}

std::map <char,int>::iterator i1;
for(i1 = _map.begin(); i1 !=_map.end(); ++i1)
{
std::cout << i1->first << ":" << i1->second << std::endl;
}

std::list<node*> t;

std::map <char,int>::iterator i2;
for(i2 = _map.begin(); i2 !=_map.end(); ++i2)
{
node *p = new node;
p->symbol = i2->first;
p->frequency = i2->second;
t.push_back(p);
}

while(t.size() != 1)
{
t.sort(my_compare());

node *left_son = t.front();
t.pop_front();
node *right_son = t.front();
t.pop_front();

node *parent = new node(left_son, right_son);
t.push_front(parent);
}

node *root = t.front();
build_table(root);
file.clear();
file.seekg(0);

std::ofstream fout;
fout.open("output.bin");

int counter = 0;
char buf = 0;

while(!file.eof())
{
char c = file.get();
std::vector<bool> x = table[c];

for(int n = 0; n < x.size(); n++)
{
buf = buf | x[n]<<(7-counter);
counter++;
if (counter==8)
{
counter=0;
fout << buf;
buf=0;
}
}
}

file.close();
fout.close();

std::ifstream fin("output.bin");

node *p = root;
counter = 0;
char byte;
byte = fin.get();

while(!fin.eof())
{
bool b = byte & (1 << (7-counter));

if(b)
{
p=p->right;
}
else
{
p=p->left;
}
if(p->left==NULL && p->right==NULL)
{
std::cout << p->symbol;
p = root;
}
counter++;
if (counter == 8)
{
counter = 0;
byte = fin.get();
}
}

fin.close();
}

int main()
{
Huffman();


return 0;
}
