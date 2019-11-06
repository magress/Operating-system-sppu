#define TEXT_SZ 2048
typedef struct shared_use_st
{
	int written_by_you;				// Flag 0 or 1
	char some_text[TEXT_SZ];		// Buffer

}shared_use_st;
