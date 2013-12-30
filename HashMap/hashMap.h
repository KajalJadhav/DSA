#include "include/arrayList.h"
#include "../iterator.h"

typedef int Comparator(void* element1,void* element2);
typedef int HashCodeGenerator(void* element);

typedef struct{
	ArrayList bucket;
	Comparator *compare;
	HashCodeGenerator *hashCodeGenerator;
	void* keys;
} Hashmap;
 
Hashmap createHashmap(Comparator *compare,HashCodeGenerator *generator);
int putValue(Hashmap* hash,void* key,void* value);
void* getValue(Hashmap* hash,void* key);
int removeFromHashMap(Hashmap *hash,void* key);
Iterator keys(Hashmap *hash);
void disposeHashmap(Hashmap *hash);