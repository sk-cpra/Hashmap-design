// CPP program to implement hashing technique
#include<bits/stdc++.h>
using namespace std;
/*************************************SEPARATE CHAINING********************************************************/
class Hash_chain
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<int> *table;
public:
	Hash_chain(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash_chain::Hash_chain(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash_chain::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash_chain::deleteItem(int key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (inex)th list
list <int> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == key)
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash_chain::displayHash() {
 for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
 }
}
void chaining(){
   
    Hash_chain h(7); // 7 is count of buckets in hash table
    cout<<"1.Insert element into the table"<<endl;
    cout<<"2.Delete element at a key"<<endl;
    cout<<"3.Display the hash Table"<<endl;
    cout<<"4.Exit"<<endl;
    // insert the keys into the hash table
    int choice;
    while(1){
      cout<<"enter the operation ";
      cin>>choice;
      int num;
      switch(choice) {
         case 1:
            cout<<"enter the key to insert : ";
            cin>>num;
            h.insertItem(num);
          break;
         case 2:
            cout<<"enter the key to be deleted: ";
            cin>>num;
            h.deleteItem(num);
          break;
         case 3:
            h.displayHash();
          break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
    }

}
/******************************LINEAR PROBING****************************************************/
class Hash_linear{
	 
     int BUCKET; // No. of buckets

	// array containing buckets
	vector<int> table;
public:
	Hash_linear(int V,vector<int> v); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		  return (x % BUCKET);
	}

	void displayHash();
};
Hash_linear::Hash_linear (int b,vector<int> v){
        this->BUCKET = b;
        table=v; 
}
void Hash_linear::insertItem(int x){
    // Computing the hash value
     int hv = hashFunction(x);
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1)
            table[hv] = x;
        else
        {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            int flag=0;
            for (int j = 0; j < BUCKET; j++)
            {
                // Computing the new hash value
                int t = hashFunction(hv + j);
                if (table[t] == -1)
                {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = x;
                    flag=1;
                    break;
                }
            }
            if(!flag)cout<<"can't be inserted"<<endl;
        }
}
void Hash_linear::deleteItem(int x){
     
     for(int i=0;i<BUCKET;i++){
         int hv=hashFunction(x+i);
         // if found then delete
         if(table[hv]==x)
         {   
             table[hv]=-1;
             return ;
         }
         else if(table[hv]==-1)// not found
         {   
             cout<<"!ELEMENT NOT FOUND"<<endl;
             return;
         }
     }
     
      cout<<"!ELEMENT NOT FOUND"<<endl;
}
void Hash_linear::displayHash()
{
    // Iterating and printing the array
    cout<<"INDEX"<< "  "<<"KEY"<<endl;
    for (int i = 0; i <BUCKET; i++)
    {     if(table[i]!=-1)
        cout <<i<<"    "<<table[i] <<endl;
        else
        cout<<i<<endl;

    }
}
void linear(){
    vector<int>v(7,-1);
    Hash_linear h(7,v); // 7 is count of buckets in hash table
    cout<<"1.Insert element into the table"<<endl;
    cout<<"2.Delete element at a key"<<endl;
    cout<<"3.Display the hash Table"<<endl;
    cout<<"4.Exit"<<endl;
    int choice;
    while(1){
      cout<<"enter the operation ";
      cin>>choice;
      int num;
      switch(choice) {
         case 1:
            cout<<"enter the key to insert : ";
            cin>>num;
            h.insertItem(num);
          break;
         case 2:
            cout<<"enter the key to be deleted: ";
            cin>>num;
            h.deleteItem(num);
          break;
         case 3:
            h.displayHash();
          break;
         case 4:
           cout<<"HASHED SUCCESSFUL!";
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
    }

}
/*-----------------------------QUADRATIC PROBING------------------------------------------------------------*/
class Hash_quad{
	 
     int BUCKET; // No. of buckets

	// array containing buckets
	vector<int> table;
public:
	Hash_quad(int V,vector<int> v); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};
Hash_quad::Hash_quad (int b,vector<int> v){
        this->BUCKET = b;
        table=v; 
}
void Hash_quad::insertItem(int x){
    // Computing the hash value
     int hv = hashFunction(x);
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1)
            table[hv] = x;
        else
        {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            int flag=0;
            for (int j = 0; j < BUCKET; j++)
            {
                // Computing the new hash value
                int t = hashFunction(hv + j * j);
                if (table[t] == -1)
                {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = x;
                    flag=1;
                    break;
                }
            }
            if(!flag)cout<<"!Table Is Full"<<endl;
        }
}
void Hash_quad::deleteItem(int x){
     
     for(int i=0;i<BUCKET;i++){
         int hv=hashFunction(x+i*i);
         // if found then delete
         if(table[hv]==x)
         {   
             table[hv]=-1;
             return ;
         }
         else if(table[hv]==-1)// not found
         {   
             cout<<"!ELEMENT NOT FOUND"<<endl;
             return;
         }
     }

      cout<<"!ELEMENT NOT FOUND"<<endl;
}
void Hash_quad::displayHash()
{
    // Iterating and printing the array
    cout<<"INDEX"<< "  "<<"KEY"<<endl;
    for (int i = 0; i <BUCKET; i++)
    {     if(table[i]!=-1)
        cout <<i<<"  "<<table[i] <<endl;
        else
        cout<<i<<endl;
    }
}
void quadratic(){
    vector<int>v(7,-1);
    Hash_quad h(7,v); // 7 is count of buckets in hash table
    cout<<"1.Insert element into the table"<<endl;
    cout<<"2.Delete element at a key"<<endl;
    cout<<"3.Display the hash Table"<<endl;
    cout<<"4.Exit"<<endl;
    int choice;
    while(1){
      cout<<"enter the operation ";
      cin>>choice;
      int num;
      switch(choice) {
         case 1:
            cout<<"enter the key to insert : ";
            cin>>num;
            h.insertItem(num);
          break;
         case 2:
            cout<<"enter the key to be deleted ";
            cin>>num;
            h.deleteItem(num);
          break;
         case 3:
            h.displayHash();
          break;
         case 4:
           cout<<"HASHED SUCCESSFUL!";
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
    }

}
/*---------------------------------------------------------------------------------------------------------*/

// Driver program
int main()
{
    int choice;
      cout<<" HASHING TECHNIQUE "<<endl;
      cout<<"1.Separate chaining"<<endl;
      cout<<"2.Linear probing "<<endl;
      cout<<"3.Quadratic probing "<<endl;
      cout<<" Enter your choice : ";
      cin>>choice;
      switch(choice) {
         case 1:
            chaining();
         break;
         case 2:
            linear();
         break;
         case 3:
            quadratic();
         break;
        
         default:
            cout<<"\n Enter correct option\n";
      }
    return 0;
}
// by Ram kumar singh