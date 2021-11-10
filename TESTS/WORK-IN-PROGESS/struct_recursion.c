
struct A {
	int x;
	int y;
	int z;
	struct B *b;
};

struct B {
	int x;
	int y;
	int z;
	struct A *a;
};


int main() {
	struct A a;
}
