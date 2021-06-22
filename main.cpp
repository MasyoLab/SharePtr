//==========================================================================
// �g���� [main.cpp]
// author : MasyoLab
//==========================================================================
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define _GLIBCXX_DEBUG

#include "SharePtr.h"

class MyClass {
public:
	MyClass() :m_value(0) {}
	MyClass(int value) :
		m_value(value) {}
	void func() {}
private:
	int m_value;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �J�X�^���f���[�^���w��
	SharePtr<MyClass> SharePtr1(new MyClass(500),
		[](MyClass* p) {delete p; });

	// ����
	SharePtr<MyClass> SharePtr2(new MyClass(1000));

	// �K��
	SharePtr<MyClass> SharePtr3;
	SharePtr<MyClass> SharePtr4();
	SharePtr<MyClass> SharePtr5(nullptr);
	SharePtr<MyClass> SharePtr6(nullptr, [](MyClass*) {});
	MyClass SharePtr7;
	MyClass* SharePtr8 = nullptr;

	SharePtr1 = SharePtr1;
	SharePtr2 = SharePtr2;
	SharePtr1 = SharePtr2;

	SharePtr1->func();
	SharePtr2->func();

	(*SharePtr1).func();
	(*SharePtr2).func();

	auto &data = (*SharePtr2);
	data.func();

	if (SharePtr1) {}
	if (!SharePtr1) {}
	if (SharePtr1 == SharePtr1) {}
	if (SharePtr1 == SharePtr2) {}
	if (SharePtr1 != SharePtr1) {}
	if (SharePtr1 != SharePtr2) {}
	if (SharePtr1 == nullptr) {}
	if (SharePtr1 != nullptr) {}
	if (SharePtr1 != SharePtr7) {}
	if (SharePtr1 == SharePtr7) {}
	if (SharePtr1 != SharePtr8) {}
	if (SharePtr1 == SharePtr8) {}

	SharePtr1.check();
	SharePtr1.use_count();
	SharePtr1.clear();
	SharePtr1.destroy();

	SharePtr1 = nullptr;

	return std::system("PAUSE");
}