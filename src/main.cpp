
#include <sifon/Publisher.hpp>

int main()
{

	sifon::Publisher pub{"log"};

	int i = 123;
	pub<<i;
	return 0;
}
