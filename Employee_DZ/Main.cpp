#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>

struct Employee {
	int id;
	std::string name;
	bool isDayShift;
	double salary;
};

void printEmployee(const Employee& emp) {
	std::cout <<"ID: " << std::setw(2) << emp.id  <<" |Name: " << std::setw(15) << emp.name<<
		" |Shift:  " <<(emp.isDayShift ? " Day " : "Night") << std::setw(5) << "|Salaty " << 
		std::setw(5) <<emp.salary << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	const int N = 10;		//колличество сотрудников
	std::vector<Employee>emploees;

	//Генерация случайных данных о сотрудниках
	for (int i = 0; i < N; i++){
		Employee emp;
		emp.id = i + 1;
		emp.name = "Сотрудник " + std::to_string(emp.id);
		emp.isDayShift = rand() % 2 == 0;
		emp.salary = rand() % 30000 + 90000;

		emploees.push_back(emp);
	}

	//Вывод информации о всех сотрудниках
	for (const auto& emp : emploees) {
		printEmployee(emp);
	}
	std::cout << std::endl;
	//Разделение на ночных и дневных сотрудников
	std::vector<Employee>dayShiftEmployees;
	std::vector<Employee>nightShiftEmployees;

	for (const auto emp : emploees) {
		if (emp.isDayShift) {
			dayShiftEmployees.push_back(emp);
		}
		else
		{
			nightShiftEmployees.push_back(emp);
		}
	}

	//Вывод информации о дневных сотрудниках
	std::cout << "Сотрудники работающие в дневную смену:\n";
	for (const auto& emp : dayShiftEmployees) {
		printEmployee(emp);
	}
	std::cout << std::endl;

	//Вывод информации о ночных сотрудниках
	std::cout << "Сотрудники работающие в ночную смену:\n";
	for (const auto& emp : nightShiftEmployees) {
		printEmployee(emp);
	}

	std::cout << std::endl;

	//Сортируем всех сотрудников по зп(с добавлением лямбда функции)
	std::sort(emploees.begin(), emploees.end(), [](const Employee& a, const Employee b)
		{ return a.salary > b.salary; });

	//Сортируем дневных сотрудников по зп(с добавлением лямбда функции)
	std::sort(dayShiftEmployees.begin(), dayShiftEmployees.end(), [](const Employee& a, const Employee b)
		{ return a.salary > b.salary; });

	//Сортируем ночных сотрудников по зп(с добавлением лямбда функции)
	std::sort(nightShiftEmployees.begin(), nightShiftEmployees.end(), [](const Employee& a, const Employee b)
		{ return a.salary > b.salary; });

	//Выводим 3х дневных сотрудников с самой высокой зарплатой
	std::cout << "ТОП 3 дневных сотрудника с самой высокой зп:\n";
	for (int i = 0; i < 3; i++)
	{
		printEmployee(dayShiftEmployees[i]);
	}

	std::cout << std::endl;

	//Выводим 3х ночных сотрудников с самой высокой зарплатой
	std::cout << "ТОП 3 ночных сотрудника с самой высокой зп:\n";
	for (int i = 0; i < 3; i++)
	{
		printEmployee(nightShiftEmployees[i]);
	}
	std::cout << std::endl;

	//Выводим 3х сотрудников с самой высокой зарплатой
	std::cout << "ТОП 3 сотрудника с самой высокой зп:\n";
	for (int i = 0; i < 3; i++)
	{
		printEmployee(emploees[i]);
	}

	std::cout << std::endl;

	//Записывае информацию о сотрудниках в файл.
	std::ofstream file("Employees_info.txt");
	if (!file.is_open()) {
		std::cerr << "Error is opening file";
	}
	else {
		file << "ТОП 3 дневных сотрудника с самой высокой зп:\n";
		for (int i = 0; i < 3; i++)
		{
			file << "ID: " << dayShiftEmployees[i].id << " | Name: " <<
				dayShiftEmployees[i].name << " | Salary: " <<
				dayShiftEmployees[i].salary << std::endl;
		}
		file << "--------------------------------------------\n";
		file << "ТОП 3 ночных сотрудника с самой высокой зп:\n";
		for (int i = 0; i < 3; i++)
		{
			file << "ID: " << nightShiftEmployees[i].id << " | Name: " <<
				nightShiftEmployees[i].name << " | Salary: " <<
				nightShiftEmployees[i].salary << std::endl;
		}
		file << "--------------------------------------------\n";
		file << "ТОП 3 сотрудника с самой высокой зп:\n";
		for (int i = 0; i < 3; i++)
		{
			file << "ID: " << emploees[i].id << " | Name: " <<
				emploees[i].name << " | Salary: " <<
				emploees[i].salary << std::endl;
		}
		file << "--------------------------------------------\n";
	}
		file.close();

		std::cout << std::endl;

		//Выводим трех дневных сотрудников с самой низкой зп
		std::cout << "ТОП 3 дневных сотрудника с самой низкой зп:\n";
		for (int i = dayShiftEmployees.size() - 3; i < dayShiftEmployees.size() ; ++i)
		{
			printEmployee(dayShiftEmployees[i]);
		}

		std::cout << std::endl;
		//Выводим трех ночных сотрудников с самой низкой зп
		std::cout << "ТОП 3 ночных сотрудника с самой низкой зп:\n";
		for (int i = nightShiftEmployees.size() - 3; i < nightShiftEmployees.size(); ++i)
		{
			printEmployee(nightShiftEmployees[i]);
		}

		std::cout << std::endl;
		//Выводим трех сотрудников с самой низкой зп
		std::cout << "ТОП 3 сотрудника с самой низкой зп:\n";
		for (int i = emploees.size() - 3; i < emploees.size(); ++i)
		{
			printEmployee(emploees[i]);
		}

		//Дозаписываем информацию в файл

		std::ofstream file1("Employees_info.txt",std::ios_base::app);
		if (!file1.is_open()) {
			std::cerr << "Error is opening file";
		}
		else {
			file1 << "ТОП 3 дневных сотрудника с самой низкой зп:\n";
			for (int i = dayShiftEmployees.size() - 3; i < dayShiftEmployees.size(); i++)
			{
				file1 << "ID: " << dayShiftEmployees[i].id << " | Name: " <<
					dayShiftEmployees[i].name << " | Salary: " <<
					dayShiftEmployees[i].salary << std::endl;
			}
			file1 << "--------------------------------------------\n";
			file1 << "ТОП 3 ночных сотрудника с самой низкой зп:\n";
			for (int i = nightShiftEmployees.size() - 3; i < nightShiftEmployees.size(); i++)
			{
				file1 << "ID: " << nightShiftEmployees[i].id << " | Name: " <<
					nightShiftEmployees[i].name << " | Salary: " <<
					nightShiftEmployees[i].salary << std::endl;
			}
			file1 << "--------------------------------------------\n";
			file1 << "ТОП 3 сотрудника с самой низкой зп:\n";
			for (int i = emploees.size() - 3; i < emploees.size(); i++)
			{
				file1 << "ID: " << emploees[i].id << " | Name: " <<
					emploees[i].name << " | Salary: " <<
					emploees[i].salary << std::endl;
			}
		}
		file1.close();

		//Считываем данные из файла и используем коллекцию set чтобы удалить дубликаты

		std::set<Employee>uniqueEmployees;
		std::ifstream file3("Employees_info.txt");
		if (!file3.is_open()) {
			std::cerr << "Error opening file";
		}
		
			Employee emp;

			while (file3 >> emp.id >> emp.name >> emp.isDayShift >> emp.salary) {
				uniqueEmployees.insert(emp);
			}

			std::cout << "Уникальные сотрудники:\n";
			for (const auto& emp : uniqueEmployees) {
				printEmployee(emp);
			}
			
		

		

	return 0;

}