#include <iostream>
#include <vector>
using namespace std;

class team;
class sponsor {
public:
    string nama;
    vector<team*> daftar_team;
    sponsor(string pNama) :nama(pNama) 
    {
        cout << "sponsor \"" << nama << "\ ada\n";
    }
    ~sponsor() 
    {
        cout << "sponsor \"" << nama << "\ tidak ada\n";
    }

    void tambahTeam(team*);
    void cetakTeam();
};


class Team {
public:
    string nama;
    vector<sponsor*> daftar_sponsor;

    Team(string pNama) :nama(pNama) 
    {
        cout << "Team \"" << nama << "\" ada\n";
    }
    ~Team() 
    {
        cout << "Team \"" << nama << "\" tidak ada\n";
    }

    void tambahSponsor(sponsor*);
    void cetakSponsor();
};

void sponsor::tambahTeam(team* pTeam) 
{
    daftar_team.push_back(pTeam);
}

void sponsor::cetakTeam() 
{
    cout << "Daftar Team yang bekerja sama sponsor \"" << this->nama << "\":\n";
    for (auto& a : daftar_team) 
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

void Team::tambahSponsor(sponsor* pSponsor) 
{
    daftar_sponsor.push_back(pSponsor);
    pSponsor->cetakTeam();
}

void Team::cetakSponsor() 
{
    cout << "Daftar Sponsor dari team \"" << this->nama << "\":\n";
    for (auto& a : daftar_sponsor) 
    {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {

    Team* varTeam1 = new Team("Onic Esport");
    Team* varTeam2 = new Team("Evos Esport");
    sponsor* varSponsor1 = new sponsor("Leica");
    sponsor* varSponsor2 = new sponsor("Nike");
    sponsor* varSponsor3 = new sponsor("Samsung");

    varTeam1->tambahSponsor(varSponsor1);
    varTeam1->tambahSponsor(varSponsor2);
    varTeam1->tambahSponsor(varSponsor3);
    varTeam2->tambahSponsor(varSponsor1);
    varTeam2->tambahSponsor(varSponsor3);

    varTeam1->cetakSponsor();
    varTeam2->cetakSponsor();
    varSponsor1->cetakTeam();
    varSponsor2->cetakTeam();

    delete varSponsor1;
    delete varSponsor2;
    delete varSponsor3;
    delete varSponsor2;

    return 0;
}