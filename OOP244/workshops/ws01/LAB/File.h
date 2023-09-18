#ifndef FILE_H
#define FILE_H
#include "ShoppingList.h"
#include "ShoppingRec.h"

namespace sdds {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif // !FILE_H

