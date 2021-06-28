#include <iostream>
#include <cstring>
#include "Product.h"
#include "ProductStore.h"
using namespace std;

int main()
{
	//проверка класса коллекции
	ProductStore collection(3);

	collection.SetCurCollection("1", "1", 1, 1, 1);
	collection.SetCurCollection("2", "2", 2, 2, 2);

	collection.AddItem();

	collection.PrintAllCollection();

	collection.RemoveItem(4);
	collection.RemoveItem(3);

	cout << "\n\n\n";

	collection.PrintAllCollection();

	cout << "\n\n\n";

	collection.PrintSearchResult(collection["2"]);

	cout << "\n\n\n";

	collection.PrintSearchResult(collection["key"]);

}