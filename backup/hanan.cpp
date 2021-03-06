#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>
#include <stdio.h>

using namespace std;


/*
yang kurang, 
mencari data/elemen dalam list ,hanan
* 
mengubah elemen/data dalam list ,tb
* 
sorting data(metode bebas) ,dwi
* 
hardcode(DONE)
* input nama kepala keluara dan pekerjaannya pake string
*/
int pil; void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();
void datahardcode();
void ubahdata();
void menuubahdata();
void tampilsatuan();
void cari();
int isEmpty();




struct node
{
	string kepalakeluarga;
	string pekerjaankepalakeluarga;
	string NIKkepalakeluarga;
	string NIKkartukeluarga;
	int banyakanggotakeluarga;
	char BLOK;
	int norumah;
	int luasrumah;
	node *prev, *next;
};

node *baru,*head=NULL,*tail=NULL,*hapus,*bantu;

int isEmpty()
{
  if (head==NULL)
    return 1;
    else
    return 0;
}

//main program
int main()
{
	
	datahardcode();
	do
	{
		system("cls");
		cout<<"MENU DOUBLE LINKEDLIST"<<endl;
		cout<<"1. Tambah Depan"<<endl;
		cout<<"2. Tambah Belakang"<<endl;
		cout<<"3. Hapus Depan"<<endl;
		cout<<"4. Hapus Belakang"<<endl;
		cout<<"5. Tampilkan"<<endl;
		cout<<"6. Ubah Data"<<endl;
		cout<<"7. Cari Data"<<endl;
		cout<<"8. Selesai"<<endl;
		cout<<"Pilihan Anda : "<<endl;
		cin>>pil;
		getchar();
		pilih();
	}
	while(pil!=8);
	
	return 0;
}

//inputan hardcode


//prosedur pilih
void pilih()
{
	if(pil==1)
		tambah_depan();
	else if(pil==2)
		tambah_belakang();
	else if(pil==3)
		hapus_depan();
	else if(pil==4)
		hapus_belakang();
	else if(pil==5)
		tampil();
	else if(pil==6)
		menuubahdata();
	else if(pil==7)
		cari();
	else
		cout<<"selesai";
}

//membuat simpul baru
void buat_baru()
{
	baru= new(node);
	cout<<"input nama kepala keluarga\t:";			getline(cin, baru->kepalakeluarga);
	cout<<"input pekerjaan kepala keluarga\t:";		getline(cin, baru->pekerjaankepalakeluarga);
	cout<<"input NIK Kepala Keluarga\t:";			getline(cin, baru->NIKkepalakeluarga);
	cout<<"input NIK Kartu keluarga\t:";			getline(cin, baru->NIKkartukeluarga);
	cout<<"input jumlah anggota keluarga\t:";		cin>>baru->banyakanggotakeluarga;
	cout<<"input blok\t\t\t:";						cin>>baru->BLOK;
	cout<<"input no rumah\t\t\t:";					cin>>baru->norumah;
	cout<<"input luas Rumah(meter persegi)\t:";		cin>>baru->luasrumah;
	baru->prev=NULL;
	baru->next=NULL;
}

//menambah simpul di awal
void tambah_depan()
{
	buat_baru();
	if(head==NULL)
	{
		head=baru;
		tail=baru;
	}
	else
	{
		baru->next=head;
		head->prev=baru;
		head=baru;
	}
	
	
	cout<<endl<<endl;
	cout<<endl<<"\t\t\t DATA BERHASIL DIMASUKKAN"<<endl;
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}

//menambah simpul di belakang
void tambah_belakang()
{
	buat_baru();
	if(head==NULL)
	{
		head=baru;
		tail=baru;
	}
	else
	{
		tail->next=baru;
		baru->prev=tail;
		tail=baru;
	}
	cout<<endl<<endl;
	cout<<endl<<"\t\t\t DATA BERHASIL DIMASUKKAN"<<endl;
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}

//menghapus simpul di awal
void hapus_depan()
{
	if(head==NULL)
	cout<<"Kosong";
	else if(head->next==NULL)
	{
		hapus=head;
		head=NULL;
		tail=NULL;
		delete hapus;
	}
	else
	{
		hapus=head;
		head=hapus->next;
		head->prev=NULL;
		delete hapus;
	}
	cout<<endl<<endl;
	cout<<"\t\t\t DATA BERHASIL DIHAPUS\n";
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}

//menghapus simpul dibelakang
void hapus_belakang()
{
	if(head==NULL)
		cout<<"Kosong";
		else if(head->next==NULL)
		{
			hapus=head;
			head=NULL;
			tail=NULL;
			delete hapus;
		}
		else
		{
			hapus=tail;
			tail=hapus->prev;
			tail->next=NULL;
			delete hapus;
		}
		cout<<endl<<endl;
		cout<<"\t\t\t DATA BERHASIL DIHAPUS\n";
		cout<<"tekan ENTER untuk melanjutkan"<<endl;
		getch();
}

//mencetak list
void tampil()
{
	if(head==NULL)
	{
		cout<<"Data Kosong";
		
	}
	else
	{
		bantu=head;
		while(bantu!=NULL)
		{
		cout<<"nama kepala keluarga\t\t:"<<bantu->kepalakeluarga<<endl;
		cout<<"pekerjaan kepala keluarga\t:"<<bantu->pekerjaankepalakeluarga<<endl;
		cout<<"NIK Kepala Keluarga\t\t:"<<bantu->NIKkepalakeluarga<<endl;
		cout<<"NIK Kartu keluarga\t\t:"<<bantu->NIKkartukeluarga<<endl;
		cout<<"anggota keluarga\t\t:"<<bantu->banyakanggotakeluarga<<endl;
		cout<<"blok\t\t\t\t:"<<bantu->BLOK<<endl;
		cout<<"no rumah\t\t\t:"<<bantu->norumah<<endl;
		cout<<"luas Rumah\t\t\t:"<<bantu->luasrumah<<endl;
		bantu=bantu->next;
		cout<<"==================================\n";
		}
	}
	cout<<endl;
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}

void inputhardcode(string a,string b,string c,string d,int e,char f,int g,int h)
{
	baru= new(node);
	//input data hardcode
	//input hardcode
	baru->kepalakeluarga=a;
	baru->pekerjaankepalakeluarga=b;
	baru->NIKkepalakeluarga=c;
	baru->NIKkartukeluarga=d;
	baru->banyakanggotakeluarga=e;
	baru->BLOK=f;
	baru->norumah=g;
	baru->luasrumah=h;
	
	baru->prev=NULL;
	baru->next=NULL;
	
	if(head==NULL)
	{
		head=baru;
		tail=baru;
	}
	else
	{
		tail->next=baru;
		baru->prev=tail;
		tail=baru;
	}
	
}

void datahardcode()
{
	//inisialisasi variable pemabantu
	cout<<"memproses data hardcode\n";
	string a;
	string b;
	string c;
	string d;
	int e;
	char f;
	int g;
	int h;
	
	//input data hardcode
	
	//data 1
	a="deo haganta";
	b="1";
	c="d643534423";
	d="sdadasda";
	e=4;
	f='A';
	g=6;
	h=7;
	inputhardcode(a,b,c,d,e,f,g,h);
	
	//data 2
	a="100";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=6;		//int
	f='B';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
	
	//data 3
	a="100";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=6;		//int
	f='C';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
		
	//data 4
	a="22";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=6;		//int
	f='D';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
	
	
		//data 5
	a="4";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=6;		//int
	f='E';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
	
	
		//data 6
	a="5";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=8;		//int
	f='F';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
	
	
		//data 7
	a="9";		//string
	b="2";		//string
	c="3";		//string
	d="4";		//string
	e=7;		//int
	f='G';		//char
	g=7;		//int
	h=8;		//int
	inputhardcode(a,b,c,d,e,f,g,h);
	
	
	cout<<"hardcode selesai diproses";
	cout<<endl;
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}
void tampilsatuan()
{
	cout<<endl;
	cout<<"nama kepala keluarga\t\t:"<<bantu->kepalakeluarga<<endl;
	cout<<"pekerjaan kepala keluarga\t:"<<bantu->pekerjaankepalakeluarga<<endl;
	cout<<"NIK Kepala Keluarga\t\t:"<<bantu->NIKkepalakeluarga<<endl;
	cout<<"NIK Kartu keluarga\t\t:"<<bantu->NIKkartukeluarga<<endl;
	cout<<"anggota keluarga\t\t:"<<bantu->banyakanggotakeluarga<<endl;
	cout<<"blok\t\t\t\t:"<<bantu->BLOK<<endl;
	cout<<"no rumah\t\t\t:"<<bantu->norumah<<endl;
	cout<<"luas Rumah\t\t\t:"<<bantu->luasrumah<<endl;
}
void ubahdata(int t)
{
	system("cls");
	string a1,a2;
	string b1,b2;
	string c1,c2;
	string d1,d2;
	int e1,e2;
	char f1,f2;
	int g1,g2;
	int h1,h2;
	
	int x=0;
	char y;
	//counter t
	int z=1;
	
	cout<<"masukkan data yang ingin diubah:";
	
	if(head==NULL)
	{
		cout<<"Data Kosong";
		
	}
	else
	{
		
		bantu=head;
		while(bantu!=NULL)
		{
			if(x==1) break;
			
			switch (t)
			{
				y='x';
				
				//kepalakeluarga
				case 1:
				{
					if(z==1) getline(cin, a1);
					z++;
					if(a1==bantu->kepalakeluarga) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>a2; 
							bantu->kepalakeluarga=a2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				
				//pekerjaankepalakeluarga
				case 2:
				{
					if(z==1) getline(cin, b1); 
					z++;
					if(b1==bantu->pekerjaankepalakeluarga) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>b2; 
							bantu->pekerjaankepalakeluarga=b2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				
				//NIKkepalakeluarga
				case 3:
				{
					if(z==1) getline(cin, c1); 
					z++;
					if(c1==bantu->NIKkepalakeluarga) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>c2; 
							bantu->pekerjaankepalakeluarga=c2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
				break;
				}
			
			//NIKkartukeluarga
				case 4:
				{
					if(z==1) getline(cin, d1);
					z++;
					if(d1==bantu->NIKkartukeluarga) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>d2; 
							bantu->pekerjaankepalakeluarga=d2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				
				//banyakanggotakeluarga
				case 5:
				{
					if(z==1)	cin>>e1;
					z++;
					//cout<<bantu->banyakanggotakeluarga<<" "<<e1;
					if(e1==bantu->banyakanggotakeluarga) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>e2; 
							bantu->banyakanggotakeluarga=e2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}	
				
				//BLOK
				case 6:
				{
					if(z==1)	cin>>f1;
					z++;
					if(f1==bantu->BLOK) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>f2; 
							bantu->BLOK=f2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				
				//norumah
				case 7:
				{
					if(z==1)	cin>>g1;
					z++;
					if(g1==bantu->norumah) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>g2; 
							bantu->norumah=g2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				case 9:
				{
					if(z==1)	cin>>h1;
					z++;
					if(h1==bantu->luasrumah) 
					{
						tampilsatuan();
						cout<<"apakah data ini yang ingin diubah?(y/n)?";
						cin>>y;
						if(y=='y' || y=='Y')	
						{
							cout<<"masukkan data pengganti:";
							cin>>h2; 
							bantu->norumah=h2;
							x=1; z=0;
							tampilsatuan();
							cout<<"\ndata berhasil diubah";
							break;
						}
						else if((y=='n') || (y=='N'))	
						{
							z++;
							break;
						}
						else 
						{
							cout<<"input error, mengulang program";
							x=1;
							break;
						}
					}
					break;
				}
				default: cout<<"input error";x=1; break;
			}//switch case
		//cout<<"data ke \n";
		bantu=bantu->next;
		}
	}
	cout<<endl;
	cout<<"tekan ENTER untuk melanjutkan"<<endl;
	getch();
}
void menuubahdata()
{
	int t;

	cout<<"\t\tdata yang bisa diubah\n";
	cout<<"1.nama kepala keluarga\n";
	cout<<"2.pekerjaan kepala keluarga\n";
	cout<<"3.NIK Kepala Keluarga\n";
	cout<<"4.NIK Kartu keluarga\n";
	cout<<"5.anggota keluarga\n";
	cout<<"6.blok\n";
	cout<<"7.no rumah\n";
	cout<<"8.luas Rumah\n";
	cout<<"masukkan data nomor berapa yang ingin diubah:";
	cin>>t;
	ubahdata(t);
}

void cari()
{
    node *bantu ;
    bantu=head;
    string caridata;
    cout<<"\n------------------------------------";
    cout<<"\nNama Kepala Keluarga Yang Dicari  : ";
    getline(cin, caridata);
    //cin>>caridata;
    int ketemu=0;
    if (isEmpty()==0)
    {
        while (bantu!=NULL)
        {
          if(caridata==bantu->kepalakeluarga)
          {
              cout<<"\n\n>>> Data Yang Anda Cari Ditemukan <<<"<<endl;
              cout<<"nama kepala keluarga\t\t:"<<bantu->kepalakeluarga<<endl;
              cout<<"pekerjaan kepala keluarga\t:"<<bantu->pekerjaankepalakeluarga<<endl;
              cout<<"NIK Kepala Keluarga\t\t:"<<bantu->NIKkepalakeluarga<<endl;
              cout<<"NIK Kartu keluarga\t\t:"<<bantu->NIKkartukeluarga<<endl;
              cout<<"anggota keluarga\t\t:"<<bantu->banyakanggotakeluarga<<endl;
              cout<<"blok\t\t\t\t:"<<bantu->BLOK<<endl;
              cout<<"no rumah\t\t\t:"<<bantu->norumah<<endl;
              cout<<"luas Rumah\t\t\t:"<<bantu->luasrumah<<endl;
              cout<<"\n\n";
              ketemu=1;
          }
          bantu=bantu->next;
        }
        if (ketemu==0)
        {
          cout<<"Data Tidak Ditemukan\n";
        }
    }
    else cout<<"Data Masih Kosong\n";

    getch();
}

