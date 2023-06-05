#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public: 
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\"ada\n";
	}
	~pengarang() {
		cout << "pengarang \"" << nama << "\"ada\n";
	}
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
	void cetakbuku();
};

class penerbit {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "penerbit \"" <<nama<<"\"ada\n";
	}
	~penerbit() {
		cout << "penerbit\"" << nama << "\"ada\n";
	}

	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

void penerbit::tambahpengarang(pengarang* ppengarang) {
	daftar_pengarang.push_back(ppengarang);
}
void  penerbit::cetakpengarang() {
	cout << "daftar pengarang\"" << this->nama<<"\":\n;";
		for (auto& a : daftar_pengarang) {
			cout << a->nama << "\n";
		}
		cout << endl;
}
void pengarang::tambahpenerbit(penerbit* ppenerbit) {
	daftar_penerbit.push_back(ppenerbit);
	ppenerbit->tambahpengarang(this);
}
void pengarang::cetakpenerbit() {
	cout << "daftar penerbit\"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
}

int main() {
	pengarang* varpengarang1 = new pengarang("Joko");
	pengarang* varpengarang2 = new pengarang("Lia");
	pengarang* varpengarang3 = new pengarang("Giga");


	return 0;

}
