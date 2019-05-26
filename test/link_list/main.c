#include <assert.h>
#include "link_list.h"

int main()
{
	uint32_t size = 0, index = 0;
	uint8_t words[] = {"Hello World"};

	link_list_t* plist = NULL;
	list_iterator_t list_it;

	size = get_list_size(plist);
	assert(0 == size);

	plist = create_list();
	assert(NULL != plist);

	for(index = 0; index < sizeof(words)-1; ++index)
	{
		add_list(plist, words+index);
	}
	size = get_list_size(plist);
	assert((sizeof(words)-1) == size);

	list_it = get_list_iterator(plist);
	for(index = 0; index < size; ++index)
	{
		printf("%c", *(uint8_t*)get_node_data(list_it));
		list_it = get_next_iterator(list_it);
	}
	printf("\n");
	assert(list_it.pnode == NULL);

	free_link_list(&plist);
	assert(NULL == plist);
	return 0;
}
