#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#define cls system("cls");

using namespace std;

// GitHub

class Honda // �������� ������ Honda
{
public:
	
	string model; // ������ ����������
	int EngineCapacity; // ����� ���������
	int LoadCapacity; // ����������������
	string GasType; // ��� �������
	int maxSpeed; // ������������ ��������
	int Price; // ����
	char color; // ����
	int whsize; // ������ ����
	int checkwhmodel = 0; // �������� ���������� ���
	string whmodel; // ������ ����

	void Print() // �����, ���������� �� ����� ������ � ����������
	{
		cout << "\t\t\t\t\t\tHonda " << model << endl;
		cout << "\t\t\t\t\t\t����� ���������: " << EngineCapacity << "�3" << endl;
		cout << "\t\t\t\t\t\t����������������: " << LoadCapacity << "��" << endl;
		cout << "\t\t\t\t\t\t��� �������: " << GasType << endl;
		cout << "\t\t\t\t\t\t������������ ��������: " << maxSpeed << " ��/�" << endl;
		if (checkwhmodel == 0)
		{
			cout << "\t\t\t\t\t\t����: " << Price << "���." << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t����: " << Price + 17000 << "���." << endl;
		}
		
		if (color == '1') // �������� �����
		{
			cout << "\t\t\t\t\t\t����: ׸����" << endl;
		}
		if (color == '2')
		{
			cout << "\t\t\t\t\t\t����: �����" << endl;
		}
		if (color == '3')
		{
			cout << "\t\t\t\t\t\t����: �������" << endl;
		}
		if (checkwhmodel == 0)
		{
			cout << "\t\t\t\t\t\t����: ��������" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t����: " << whmodel << endl;
		}
		system("pause");
	}  // ����� ���������� �� �����
	void buyCar() 
	{
		cout << "\t\t\t\t\t\t�� �������, ��� ������ ���������� ������ ������?\ny/n\n\n\n\n";
		switch (_getch())
		{
		case 'y':
			if (checkwhmodel == 0)
			{
				cout << "������ " << model << " ���� ������� ������� �� " << Price << " ������!\n\n\n\n\n\n";
				exit(0);
			}
			else
			{
				cout << "������ " << model << " ���� ������� ������� �� " << Price + 17000 << " ������! (� ��������� �������� ������ �� ��������� ���).\n\n\n\n\n\n";
				exit(0);
			}
			break;
		default:
			break;
		}
	} // // �����, ���������� �� ������� ������. ���� ������������ ����� ������, ��������� ��������� ��� ��������
	void AddWheels()
	{
	linkaddwh: cls;
		if (checkwhmodel == 0)
		{
			cout << "������ �� ��������� ���������������� ��� ���������� � ��������� ����������. ��������� ������: 17.000������.\n�������� ��������:\n";
			cout << "1)�������� ����\n2)��������� � ������ ��������\n";
			switch (_getch())
			{
			case '1':
				cout << "������� �������� ���:" << endl;
				cin >> whmodel;
				checkwhmodel = 1;
				system("pause");
				break;
			case '2':
				break;
			default:
				goto linkaddwh;
				break;
			}
		}
		else
		{
			cout << "������� �������� ���:" << endl;
			cin >> whmodel;
			checkwhmodel = 1;
			system("pause");
		}
	}
	void DeleteWheels()
	{
		cout << "�� �������, ��� ������ ������� ����? y/n\n";
		switch (_getch())
		{
		case 'y':
			checkwhmodel = 0;
			cout << "���� ���� �������� �� �����������.\n";
			system("pause");
			break;
		case 'n':
			break;
		default:
			break;
		}
	}

};
class Wheel : public Honda
{
public:
	
	Wheel(int wsize)
	{
		whsize = wsize;
	}
	
	int size;
	
	void SizeTest()
	{
		cout << "������� ������ ����: ";
		cin >> size;
		if (size > whsize)
		{
			cout << "\t\t\t\t\t\t���� ������ ������� �� ��������!" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\t���� ������ ������� ��������!" << endl;
			cout << "������� ���� ��� ��� ������� ����������: " << Price << " ������." << endl;
		}
		system("pause");
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//____________________________������ � Honda CRV2020______________________________________________________________
	Honda CRV2020;
	CRV2020.model = "CR-V 2020";
	CRV2020.EngineCapacity = 2356;
	CRV2020.LoadCapacity = 544;
	CRV2020.GasType = "��92";
	CRV2020.maxSpeed = 190;
	CRV2020.Price = 2939900;
	CRV2020.color = '1';
	CRV2020.whsize = 235;
	CRV2020.whmodel;
	//____________________________������ � Honda Pilot 2020______________________________________________________________
	Honda Pilot;
	Pilot.model = "Pilot 2020";
	Pilot.EngineCapacity = 2997;
	Pilot.LoadCapacity = 642;
	Pilot.GasType = "��92";
	Pilot.maxSpeed = 192;
	Pilot.Price = 3849900;
	Pilot.color = '1';
	Pilot.whsize = 250;
	Pilot.whmodel;
	//____________________________________________������ � ����� ��� �����_____________________________________________
	Wheel Wheel1(CRV2020.whsize);
	Wheel1.Price = 10000;
	Wheel Wheel2(Pilot.whsize);
	Wheel2.Price = 15000;
	//_________________________________________________________________________________________________________________
link:	cls;
	cout << "�������� �������� ������ ���������� Honda ��� �������\n1)" << CRV2020.model << endl << "2)" << Pilot.model << endl; // ������ ����
	switch (_getch())
	{
	case '1': // ���� ������� honda crv
	link2:	cls;
		cout << "\t\t\t\t\t\tHonda CR-V 2020\n";
		cout << "�������� ��������:" << endl << "1) ������� ����" << endl << "2) �������� ������" << endl << "3) ������ ������" << endl << "4) ��������� ����" << endl << "5) �������� ����" << endl <<"6) ��������� � ������ �����" << endl;
		switch (_getch())
		{
		case '1': // ����� �����
				link4: cout << "\t\t\t\t\t\t�������� ����:\n1)׸����\n2)�����\n3)�������\n";
				CRV2020.color = _getch();
				if (CRV2020.color != '1' && CRV2020.color != '3' && CRV2020.color != '2')
				{
					cout << "\t\t\t\t\t\t������� ���������� ����!\n" << endl;
					goto link4;
				}
				cout << "\t\t\t\t\t\t���� ������.\n" << endl;
				system("pause");
				goto link2;
				break;
		case '2': // ����������� ������
				CRV2020.Print();
				goto link2;
				break;
		case '3': // ����� ������� ������
			CRV2020.buyCar();
			goto link2;
			break;
		case '4': // �������� ���
			Wheel1.SizeTest();
			goto link2;
			break;
		case '5':
			if (CRV2020.checkwhmodel == 0)
			{
				CRV2020.AddWheels();
				goto link2;
				break;
			}
			else
			{
				cout << "�������� ��������: \n1)�������� ����\n2)������� ����\n";
				switch (_getch())
				{
				case '1':
					CRV2020.AddWheels();
					goto link2;
					break;
				case '2':
					CRV2020.DeleteWheels();
					goto link2;
					break;
				}
			}
		case '6': // ����������� � ������ ����
			cout << endl;
			goto link;
			break;
		default: // ���� ������������ ������ ������������ ��������
				goto link2;
				break;
		}
		break;
	case '2': // ���� ������� honda pilot
		link3:	cls;
		cout << "\t\t\t\t\t\tHonda Pilot\n";
		cout << "�������� ��������:" << endl << "1) ������� ����" << endl << "2) �������� ������" << endl <<"3) ������ ������" << endl << "4) ��������� ����" << endl << "5) �������� ����" << endl << "6) ��������� � ������ �����" << endl;
		
		switch (_getch())
		{
		case '1': // ����� �����
				link5: cout << "\t\t\t\t\t\t�������� ����:\n1)׸����\n2)�����\n3)�������\n";
				Pilot.color = _getch();
				if (Pilot.color != '1' && Pilot.color != '2' && Pilot.color != '3')
				{
					cout << "\t\t\t\t\t\t������� ���������� ����!\n" << endl;
					goto link5;
				}
				cout << "\t\t\t\t\t\t���� ������.\n" << endl;
				system("pause");
				goto link3;
				break;
		case '2': // ����� ������
				Pilot.Print();
				goto link3;
				break;
		case '3': // ������� ������
			Pilot.buyCar();
			goto link3;
		case '4':
			Wheel2.SizeTest();
			goto link3;
			break;
		case '6': // ����������� � ������
			cout << endl;
			goto link;
			break;
		case '5':
			if (Pilot.checkwhmodel == 0)
			{
				Pilot.AddWheels();
				goto link3;
				break;
			}
			else
			{
				cout << "�������� ��������: \n1)�������� ����\n2)������� ����\n";
				switch (_getch())
				{
				case '1':
					Pilot.AddWheels();
					goto link3;
					break;
				case '2':
					Pilot.DeleteWheels();
					goto link3;
					break;
				}
			}
		default: // ���� ������������ ������ ������������ ��������
				goto link3;
				break;
		}
		break;
	default: // ���� ������������ ������ ������������ ��������
		goto link;
		break;
	}
}