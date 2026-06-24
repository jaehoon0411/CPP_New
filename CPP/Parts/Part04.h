#pragma once

namespace Part04_Inheritance
{
	class Base
	{
	public:
		Base(int num, float fltNum);
		~Base();

		void PrintInfo() const;

	// 접근제어중 상속관계에서는 접근을 허용함, 나로인해 파생된 애한테는 허용
	protected:
		int num = 0;
		float fltNum = 0.0f;
	};

	// 싱속 접근제어 - 
	// public - 그대로 가지고옴
	// protecred - 가지고 올때 public이 protected로 바뀜
	// private - public과 protected가 다 
	class Derived : public Base
	{
	public:
		Derived();
		Derived(int num, float fltNum, const char* string);
		~Derived();

		void PrintInfo() const;

	private:
		char string[100] = "";
	};
}

class Part04
{
public:
	Part04();

private:
	void Inheritance();
};