#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#define cls system("cls");

using namespace std;

// GitHub

class Honda // Создание класса Honda
{
public:
	
	string model; // Модель автомобиля
	int EngineCapacity; // Объём двигателя
	int LoadCapacity; // Грузоподъёмность
	string GasType; // Тип бензина
	int maxSpeed; // Максимальная скорость
	int Price; // Цена
	char color; // Цвет
	int whsize; // Размер колёс
	int checkwhmodel = 0; // Проверка добавления шин
	string whmodel; // Модель шины

	void Print() // Метод, отвечающий за вывод данных о автомобиле
	{
		cout << "\t\t\t\t\t\tHonda " << model << endl;
		cout << "\t\t\t\t\t\tОбъём двигателя: " << EngineCapacity << "м3" << endl;
		cout << "\t\t\t\t\t\tГрузоподъёмность: " << LoadCapacity << "кг" << endl;
		cout << "\t\t\t\t\t\tТип бензина: " << GasType << endl;
		cout << "\t\t\t\t\t\tМаксимальная скорость: " << maxSpeed << " км/ч" << endl;
		if (checkwhmodel == 0)
		{
			cout << "\t\t\t\t\t\tЦена: " << Price << "руб." << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\tЦена: " << Price + 17000 << "руб." << endl;
		}
		
		if (color == '1') // Проверка цвета
		{
			cout << "\t\t\t\t\t\tЦвет: Чёрный" << endl;
		}
		if (color == '2')
		{
			cout << "\t\t\t\t\t\tЦвет: Белый" << endl;
		}
		if (color == '3')
		{
			cout << "\t\t\t\t\t\tЦвет: Красный" << endl;
		}
		if (checkwhmodel == 0)
		{
			cout << "\t\t\t\t\t\tШины: Стандарт" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\tШины: " << whmodel << endl;
		}
		system("pause");
	}  // Вывод информации на экран
	void buyCar() 
	{
		cout << "\t\t\t\t\t\tВы уверены, что хотите приобрести данную машину?\ny/n\n\n\n\n";
		switch (_getch())
		{
		case 'y':
			if (checkwhmodel == 0)
			{
				cout << "Машина " << model << " была успешно куплена за " << Price << " рублей!\n\n\n\n\n\n";
				exit(0);
			}
			else
			{
				cout << "Машина " << model << " была успешно куплена за " << Price + 17000 << " рублей! (В стоимость включена услуга по установке шин).\n\n\n\n\n\n";
				exit(0);
			}
			break;
		default:
			break;
		}
	} // // Метод, отвечающий за покупку машины. Если пользователь купит машину, программа прекратит своё действие
	void AddWheels()
	{
	linkaddwh: cls;
		if (checkwhmodel == 0)
		{
			cout << "Услуга по установке пользовательских шин включается в стоимость автомобиля. Стоимость услуги: 17.000рублей.\nВыберите действие:\n";
			cout << "1)Добавить шины\n2)Вернуться к списку действий\n";
			switch (_getch())
			{
			case '1':
				cout << "Введите название шин:" << endl;
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
			cout << "Введите название шин:" << endl;
			cin >> whmodel;
			checkwhmodel = 1;
			system("pause");
		}
	}
	void DeleteWheels()
	{
		cout << "Вы уверены, что хотите удалить шины? y/n\n";
		switch (_getch())
		{
		case 'y':
			checkwhmodel = 0;
			cout << "Шины были заменены на стандартные.\n";
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
		cout << "Введите размер шины: ";
		cin >> size;
		if (size > whsize)
		{
			cout << "\t\t\t\t\t\tШины такого размера не подойдут!" << endl;
		}
		else
		{
			cout << "\t\t\t\t\t\tШины такого размера подойдут!" << endl;
			cout << "Средняя цена шин для данного автомобиля: " << Price << " рублей." << endl;
		}
		system("pause");
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//____________________________Данные о Honda CRV2020______________________________________________________________
	Honda CRV2020;
	CRV2020.model = "CR-V 2020";
	CRV2020.EngineCapacity = 2356;
	CRV2020.LoadCapacity = 544;
	CRV2020.GasType = "АИ92";
	CRV2020.maxSpeed = 190;
	CRV2020.Price = 2939900;
	CRV2020.color = '1';
	CRV2020.whsize = 235;
	CRV2020.whmodel;
	//____________________________Данные о Honda Pilot 2020______________________________________________________________
	Honda Pilot;
	Pilot.model = "Pilot 2020";
	Pilot.EngineCapacity = 2997;
	Pilot.LoadCapacity = 642;
	Pilot.GasType = "АИ92";
	Pilot.maxSpeed = 192;
	Pilot.Price = 3849900;
	Pilot.color = '1';
	Pilot.whsize = 250;
	Pilot.whmodel;
	//____________________________________________Данные о шинах для машин_____________________________________________
	Wheel Wheel1(CRV2020.whsize);
	Wheel1.Price = 10000;
	Wheel Wheel2(Pilot.whsize);
	Wheel2.Price = 15000;
	//_________________________________________________________________________________________________________________
link:	cls;
	cout << "Выберите желаемую модель автомобиля Honda для покупки\n1)" << CRV2020.model << endl << "2)" << Pilot.model << endl; // начало меню
	switch (_getch())
	{
	case '1': // Была выбрана honda crv
	link2:	cls;
		cout << "\t\t\t\t\t\tHonda CR-V 2020\n";
		cout << "Выберите действие:" << endl << "1) Сменить цвет" << endl << "2) Показать данные" << endl << "3) Купить машину" << endl << "4) Проверить шины" << endl << "5) Добавить шины" << endl <<"6) Вернуться к списку машин" << endl;
		switch (_getch())
		{
		case '1': // смена цвета
				link4: cout << "\t\t\t\t\t\tВыберите цвет:\n1)Чёрный\n2)Белый\n3)Красный\n";
				CRV2020.color = _getch();
				if (CRV2020.color != '1' && CRV2020.color != '3' && CRV2020.color != '2')
				{
					cout << "\t\t\t\t\t\tВведите корректный цвет!\n" << endl;
					goto link4;
				}
				cout << "\t\t\t\t\t\tЦвет изменён.\n" << endl;
				system("pause");
				goto link2;
				break;
		case '2': // отображение данных
				CRV2020.Print();
				goto link2;
				break;
		case '3': // вызов покупки машины
			CRV2020.buyCar();
			goto link2;
			break;
		case '4': // проверка шин
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
				cout << "Выберите действие: \n1)Изменить шины\n2)Удалить шины\n";
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
		case '6': // возвращение в начало меню
			cout << endl;
			goto link;
			break;
		default: // если пользователь выбрал некорректное действие
				goto link2;
				break;
		}
		break;
	case '2': // была выбрана honda pilot
		link3:	cls;
		cout << "\t\t\t\t\t\tHonda Pilot\n";
		cout << "Выберите действие:" << endl << "1) Сменить цвет" << endl << "2) Показать данные" << endl <<"3) Купить машину" << endl << "4) Проверить шины" << endl << "5) Добавить шины" << endl << "6) Вернуться к списку машин" << endl;
		
		switch (_getch())
		{
		case '1': // смена цвета
				link5: cout << "\t\t\t\t\t\tВыберите цвет:\n1)Чёрный\n2)Белый\n3)Красный\n";
				Pilot.color = _getch();
				if (Pilot.color != '1' && Pilot.color != '2' && Pilot.color != '3')
				{
					cout << "\t\t\t\t\t\tВведите корректный цвет!\n" << endl;
					goto link5;
				}
				cout << "\t\t\t\t\t\tЦвет изменён.\n" << endl;
				system("pause");
				goto link3;
				break;
		case '2': // вывод данных
				Pilot.Print();
				goto link3;
				break;
		case '3': // покупка машины
			Pilot.buyCar();
			goto link3;
		case '4':
			Wheel2.SizeTest();
			goto link3;
			break;
		case '6': // возвращение в начало
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
				cout << "Выберите действие: \n1)Изменить шины\n2)Удалить шины\n";
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
		default: // если пользователь выбрал некорректное действие
				goto link3;
				break;
		}
		break;
	default: // если пользователь выбрал некорректное действие
		goto link;
		break;
	}
}