gi// pk3_21_lab04_kontenery.cpp : 
// Autor: dr in¿. Jolanta Kawulok
// ver 2

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include <deque>
#include <forward_list>
#include <chrono>       // std::chrono::system_clock
#include <ctime>

#include <stack>
#include <queue>
#include <set>

////
using namespace std;

void showstack(stack <int> s)
{
	while (!s.empty())
	{
		cout << '\t' << s.top();
		s.pop();
	}
	cout << '\n';
}
void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << '\t' << g.front();
		g.pop();
	}
	cout << '\n';
}
void showpq(priority_queue <int> gp)
{
	priority_queue<int> g = gp;
	while (!g.empty())
	{
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}
int main()
{
	/* Mierzenie czasu na podstawie
	https://bulldogjob.pl/news/1474-jak-mierzyc-czas-wykonania-programu-w-c-c  	*/

	int Uruchomzad = 1; // nr zad 1-4 do uruchomienia
	

		// OPIS DOSTEPNYCH KONTENEROW:
		// https://en.cppreference.com/w/cpp/container
		// https://www.cplusplus.com/reference/stl/

	if (Uruchomzad == 1) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 1 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++	Porówywanie czasu wstawiania do kontenerów oraz dostepu do danych	++++++++++++++++++++++
		+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

		int poj = 1000;
		int a = 800, b = 900; // dane do spr zawartosci kontenerow
		//int a = 8, b = 9; // prosze spr dla dwoch zestawów



		/* W æwiczeniu bêdziemy tworzyæ tablicê wielkoœci poj x poj, zawieraj¹c¹ tabliczkê mno¿enia.
		W tym celu nale¿y wykorzystaæ 4 rodzaje kontnerów:
		a) wektor wektorow typu int
		b) deque deque typu int
		c) liste list typu int
		d) forward_list  forward_list   typu int    */


		/* 1.1 Proszê zmierzyc czas tworzenia wyzej wymienionych obiektow.
		a) Czy jest roznica w czasie tworzenia kontenra,
		jesli dla vector i deque bedziemy wykorzystywac push_back,
		a jesli z góry ustalon¹ wartoœæ ? */




		/* ===============================================================================================
		===========================  vector =============================================================
		=================================================================================================== */
		auto begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie wektora\n";
		vector <vector <int>> tab;
		vector <int> TEMPtab;
		// ....
		for (int i = 0; i < poj; i++)
		{
			for (int j = 0; j < poj;j++)
			{
				TEMPtab.push_back(i * j);
			}
			tab.push_back(TEMPtab);
			TEMPtab.clear();
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do wektora: %.3f s.\n", elapsed.count() * 1e-9);



		/* ================================================================================================
		===========================  DEQUE ================================================================
		=================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie deque\n";
		deque<deque <int>> que;
		deque<int> TEMPque;

		// ....
		for (int i = 0; i < poj; i++)
		{
			for (int j = 0; j < poj; j++)
			{
				TEMPque.push_back(i * j);
			}
			que.push_back(TEMPque);
			TEMPque.clear();
		}

		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do deque: %.3f s.\n", elapsed.count() * 1e-9);


		/*   ================================================================================================
			===========================  list ================================================================
			================================================================================================= */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie LIST\n";
		list<list <int>> lista1;
		list<int>TEMPlist;

		// ....

		for (int i = 0; i < poj; i++)
		{
			for (int j = 0; j < poj; j++)
			{
				TEMPlist.push_back(i * j);
			}
			lista1.push_back(TEMPlist);
			TEMPlist.clear();
		}
		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do list: %.3f s.\n", elapsed.count() * 1e-9);






		/*   ==============================================================================================
		===========================  forward_list =========================================================
		==================================================================================================== */
		begin = std::chrono::high_resolution_clock::now();
		cout << "\nTworzenie forward_list\n";
		forward_list<forward_list<int>> flista;
		forward_list<int> TEMPlista;

		
		// ....
		for (int i = 0; i < poj; i++)
		{
			for (int j = 0; j < poj; j++)
			{
				TEMPlista.push_front(i * j);
			}
			flista.push_front(TEMPlista);
			TEMPlista.clear();

		}
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("Czas wstawiania do forward_list: %.3f s.\n", elapsed.count() * 1e-9);



		/*   =============================================================================================
		1.2 Proszê odczytac wartosci z tabeli dla par a i b (czyli wynikiem jest a*b)
		Dla list i forward_list prosze dodatkowo zmierzyc czas.
		Proszê zwróciæ uwagê na ró¿nice czasowe przy wykorzystaniu innych wartoœci a i b
		(zdefiniowanych na pocz¹tku zad 1).
		 ================================================================================================= */
		cout << "\n\n\tOdczyt z kontenerow: \n";
		cout << "\nVEC: "; // ...
		cout << "\nDEQ: "; // ...


		/*   ============================================================================================
		===========================  list ===============================================================
		==============================================================================================*/
		begin = std::chrono::high_resolution_clock::now();





		cout << "\nlist: "; // ...

		// Stop measuring time and calculate the elapsed time
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z list: %.3f s.\n", elapsed.count() * 1e-9);


		/*   ============================================================================================
		===========================  forward_list =======================================================
		=============================================================================================== */
		begin = std::chrono::high_resolution_clock::now();

		cout << "\nforward: "; // ...
		end = std::chrono::high_resolution_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
		printf("\nCzas odczytu z forward_list: %.3f s.\n", elapsed.count() * 1e-9);


	}






	if (Uruchomzad == 2) {
		/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++ zad 2 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
			++++++++++++++++++++++++++++++++ ADAPTORY ++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

			/* Prosze stworzyc 3 rodzaje adaptorów typu int:
			stack, queue, priority_queue
			do których prosze dodawac pokolei dane z myvec
			(dla priority_queue definicja prorytetu nie ma znaczenia).
			A nastêpnie prosze wyswietlic zawartosci tych obiektów      */


		vector<int> myvec = { 1 ,10 ,2 ,20, 3, 30 };

		stack <int> stos;
		for (int i = 0; i < myvec.size(); i++)
		{
			stos.push(myvec[i]);
		}
		queue <int> kolejka;
		for (int i = 0; i < myvec.size(); i++)
		{
			kolejka.push(myvec[i]);
		}
		priority_queue <int> kolejka_pro;
		for (int i = 0; i < myvec.size(); i++)
		{
			kolejka_pro.push(myvec[i]);
		}
		cout << "Wyswietlanie stosu \n";
		showstack(stos);
		cout << endl;

		cout << "Wyswietlanie kolejki \n";
		showq(kolejka);
		cout << endl;

		cout << "Wyswietlanie kolejki priorytetowej \n";
		showpq(kolejka_pro);
		cout << endl;
	}









	if (Uruchomzad == 3) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ Kontenery asocjacyjne  ++++++++++++++++++++++++++++++++++++++++ */

		vector<int> vec3 = { 1,2,3,4,5,5,4,3,2,1,0,10,11,12,13,14,15,-1,-2,-3,-4,-5,15,14,13,12,11,10 };

		/* zad 3.1 Proszê stworzyc obiekt typu set, multiset, map oraz multimap typu int,
		a nastêpnie (dla dwóch pierwszych) dodaæ do nich zawartoœæ wektora vec3.
		Dla map proszê wstawiaæ rowniez zawartoœæ wektora, przy czym kluczem niech bêdzie wartoœæ
		bewzglêdna danego elmentu (mozna wykorzystaæ abs i pair).
		Dodawanie do 4 kontenetow mo¿na wykonac w 1 pêtli.		*/


		/* Nastepnie proszê wyswietlic zawartosc tych 4 obiektow.*/
		set <int> val;
		multiset<int> val1;
		for (int i = 0; i < vec3.size(); i++)
		{
			val.insert(vec3[i]);
			val1.insert(vec3[i]);
		}





		cout << "\nZAWARTOSC set\n";
		for (auto it = val.begin(); it != val.end(); ++it)
		{
			cout << ' ' << *it;
		}
			

		cout << "\n\nZAWARTOSC multiset\n";
		for (auto it = val1.begin(); it != val1.end(); ++it)
		{
			cout << ' ' << *it;
		}

		cout << "\n\nZAWARTOSC map\n";


		cout << "\n\nZAWARTOSC multimap\n";






		/* =====================================================================
		===================== zad 3.1 ==========================================
		Dla MULTIMAP proszê usun¹æ WSZYSTKIE elementy gdzie klucz wynosi 2     */



		cout << "\n\nZAD 3.1 multimap po usunieciu 2\n";




		/* =====================================================================
		===================== zad 3.2 ==========================================
			 Proszê swtorzyæ inn¹ zwyk³¹ mapê (nie multi),
			 a nastêpnie przepisaæ z wyzej stworzonej multimapy zawartoœæ tak, aby:
			 klucze by³y niemniejsze ni¿ 10 oraz
			 klucze byly mniejsze od 14.
			 Wykorzystaj do samego przepisania TYLKO 1 liniê kodu
			 (BEZ PETLI).


			 Natêpnie prosze wyswietlic tê now¹ mapê. */

		cout << "\n\nZAD 3.2 Nowa mapa na podstawie multimapy \n";

	}


	if (Uruchomzad == 4) {
		/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		 ++++++++++++++++++++ zad 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++++++ unordered_map  +++++++++++++++++++++++++++++++++++++++++++++++ */

		/* Stworz unordered_map<string, string>, a nastepnie wstaw do niego dowolne pary wyrazow.
		Nastepnie sprawdz, co pod dwoma wybranymi kluczami sie znajduje.
		Niech jeden z kluczy rzeczywiscie znajduje sie w bazie
		(wtedy prosze wyswietlic ten element),
		a niech drugiego klucza nie ma
		(wtedy prosze wyswietlic informacje, ze nie znaleziono danego klucza w mapie). */




	}

}