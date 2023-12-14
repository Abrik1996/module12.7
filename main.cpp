#include <iostream>
#include <string>
int CheckRepeat(std::string A, std::string B) //ïðîâåðÿåò êîëëè÷åñòâî âõîæäåíèÿ ïîäñòðîêè A â ñòðîêó B
{
	int sum = 0;
	int tmp;
	int last = static_cast<int>(B.length() - A.length())+1;
	//std::cout << "last index= " << B.length() << std::endl; // èñïîëüçîâàëîñü äëÿ òåñòèðîâàíèÿ
	if (last < 0) return 0;
	for (int i = 0; i < last; i++)
	{
	//	std::cout << "current index= " << i << std::endl; // èñïîëüçîâàëîñü äëÿ òåñòèðîâàíèÿ
		tmp = i;
		for (int k = 0; k < A.length(); k++)
		{
			if (A[k] != B[tmp]) break;
			tmp++;
			if (k == (A.length() - 1))
			{
				sum++;
				i += A.length()-1;
			}
		}
	}
	return sum;
}
std::string Maxrepeat(std::string A,int& x) // âû÷èñëÿåò ìàêñèìàëüíî äëèííóþ ïîâòîðÿþùóþñÿ ñòðîêó è êîëëè÷åñòâî å¸ âõîæäåíèé 
{
    int max = 0; 
    std::string B;
	std::string C="";
    for (int i = 1; i <= A.length()/2; i++)
    {
        B.clear();
        B.append(A, 0, i);// - äîáàâëÿåò â êîíåö ñòðîêè B ñèìâîëû ñòðîêè A íà÷èíàÿ ñ ñèìâîëà ñ íà÷àëà êîëè÷åñòâîì i.
		if (CheckRepeat(B, C)) break;
		std::cout << "\nchecking string: " << B << std::endl;
		if (CheckRepeat(B, A) >= max && B.length() > 1) { max = CheckRepeat(B, A); std::cout << std::endl << "repeated string is: " << B << "\nrepeated count : " << max; if (B.length() > C.length()) { C.clear(); C = B; } }
    }
	for (int i = A.length()/2; i >= 0; i--)
	{
		B.clear();
		B.append(A,A.length()-i, i);// - äîáàâëÿåò â êîíåö ñòðîêè B ñèìâîëû ñòðîêè A íà÷èíàÿ ñ ñèìâîëà ñ íà÷àëà êîëè÷åñòâîì i.
		if (CheckRepeat(B, C)) break;
		std::cout << "\nchecking string: " << B << std::endl;
		if (CheckRepeat(B, A) >= max && B.length()>1) { max = CheckRepeat(B, A); std::cout << std::endl << "repeated string is: " << B << "\nrepeated count : " << max; if (B.length() > C.length()) { C.clear(); C = B; }
		}
	}
	std::cout << "\nfound substring: " << C << std::endl;
	x = max;
    return C;
}
int main()
{
	std::string A;
	int x = 0;
	std::cout << "Input string for check:\n";
	std::cin >> A;
	std::string B = Maxrepeat(A, x);
	if (A.size() == B.length()*x) std::cout << "\nRepeated string: "<< B  <<" K = " << x;
	else std::cout << "\nNone repeated string";
	return 0;
}
