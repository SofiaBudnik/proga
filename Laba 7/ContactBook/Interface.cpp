#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <time.h>
#include <iostream>

#include "Interface.h"
#include "Outlook.h"
#include "DataBase.h"

void Init(std::string inputFileName, std::string outputFileName)
{
	Outlook outlook;
	Setup(outlook, inputFileName);
	MainMenu(outlook);
	RecordData(outlook, outputFileName);
}

void PrintMainInfo(Outlook outlook)
{
	Initials myIn;
	myIn = outlook.GetMyInitials();
	myIn.GetInfo();
	std::cout << outlook.GetMyWorkPlace() << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	std::cout << "1 - ��������" << std::endl;
	std::cout << "2 - ������ ���������" << std::endl;
	std::cout << "3 - ����" << std::endl;
	std::cout << "4 - �����������" << std::endl;
	std::cout << "5 - ����� �����������" << std::endl;
	std::cout << "Esc - ����� �� ���������" << std::endl;
	std::cout << "������� ����������� �������...";
}

void PrintContactsInfo(Outlook outlook)
{
	std::cout << "��������: " << std::endl;
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetContact(i + 1).GetInfo();
	}
	std::cout << "1.1 - �������� ����� �������" << std::endl;
	std::cout << "1.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � ������� ����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void MainMenu(Outlook& outlook)
{
	PrintMainInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				ContactsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 50:
				ContactsGroupsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 51:
				AffairsMenu(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 52:
				GetReminders(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 53:
				FindEvents(outlook);
				system("cls");
				PrintMainInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void ContactsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintContactsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "������� ��� ������ ��������: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "������� ���� �������� ������ ��������: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "������� ����� �������� ������ ��������: ";
				std::cin >> con.phone;
				try
				{
					outlook.AddContact(con);
				}
				catch (std::domain_error ex)
				{
					system("cls");
					std::cout << "������ ������� ��� ����������� � ����� ���������� �����!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintContactsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������� ������� ��������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintContactsInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveContact(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������� ������� �����!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintContactsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void ContactsGroupsMenu(Outlook& outlook)
{
	system("cls");
	PrintContactsGroupsInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				FriendsMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 50:
				ColleaguesMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 51:
				RelativesMenu(outlook);
				system("cls");
				PrintContactsGroupsInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintContactsGroupsInfo(Outlook outlook)
{
	std::cout << "������: " << std::endl;
	std::cout << "2.1 - ������" << std::endl;
	std::cout << "2.2 - �������" << std::endl;
	std::cout << "2.3 - ������������" << std::endl;
	std::cout << "Esc - ��������� � ������� ����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void FriendsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintFriendsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "������� ��� ������ ��������: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "������� ���� �������� ������ ��������: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "������� ����� �������� ������ ��������: ";
				std::cin >> con.phone;
				try {
					outlook.AddFriend(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ����������� � ����� ���������� �����!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintFriendsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������� ������� ��������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintFriendsInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveFriend(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������� ������� �����!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintFriendsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintFriendsInfo(Outlook outlook)
{
	std::cout << "������: " << std::endl;
	for (int i = 0; i < outlook.GetFriendsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetFriend(i + 1).GetInfo();
	}
	std::cout << "2.1.1 - �������� ����� �������" << std::endl;
	std::cout << "2.1.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �������" << std::endl;
	std::cout << "������� ����������� �������...";
}

void ColleaguesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintColleaguesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "������� ��� ������ ��������: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "������� ���� �������� ������ ��������: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "������� ����� �������� ������ ��������: ";
				std::cin >> con.phone;
				try {
					outlook.AddColleague(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ����������� � ����� ���������� �����!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintColleaguesInfo(outlook);
					break;
				}
				std::cout << "������� ������� ��������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintColleaguesInfo(outlook);
				break;
			}
			case 50: {  //2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveColleague(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������� ������� �����!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintColleaguesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintColleaguesInfo(Outlook outlook)
{
	std::cout << "�������: " << std::endl;
	for (int i = 0; i < outlook.GetColleaguesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetColleague(i + 1).GetInfo();
	}
	std::cout << "2.2.1 - �������� ����� �������" << std::endl;
	std::cout << "2.2.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �������" << std::endl;
	std::cout << "������� ����������� �������...";
}

void RelativesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintRelativesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Contact con;
				int day, month, year;
				std::cout << "������� ��� ������ ��������: ";
				std::cin >> con.surname >> con.name >> con.patronymic;
				std::cout << "������� ���� �������� ������ ��������: ";
				std::cin >> day >> month >> year;
				con.date.tm_mday = day;
				con.date.tm_mon = month - 1;
				con.date.tm_year = year - 1900;
				std::cout << "������� ����� �������� ������ ��������: ";
				std::cin >> con.phone;
				try {
					outlook.AddRelative(con);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ����������� � ����� ���������� �����!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintRelativesInfo(outlook);
					break;
				}
				std::cout << "������� ������� ��������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintRelativesInfo(outlook);
				break;
			}
			case 50: {  // 2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveRelative(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������� ������� �����!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintRelativesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintRelativesInfo(Outlook outlook)
{
	std::cout << "������������: " << std::endl;
	for (int i = 0; i < outlook.GetRelativesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetRelative(i + 1).GetInfo();
	}
	std::cout << "2.3.1 - �������� ����� �������" << std::endl;
	std::cout << "2.3.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �������" << std::endl;
	std::cout << "������� ����������� �������...";
}

void AffairsMenu(Outlook& outlook)
{
	system("cls");
	PrintAffairsInfo(outlook);
	bool isBreak = true;
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49:
				CallsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 50:
				MeetingsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 51:
				AssignmentsMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 52:
				NotesMenu(outlook);
				system("cls");
				PrintAffairsInfo(outlook);
				break;
			case 27:
				isBreak = false;
				break;
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintAffairsInfo(Outlook outlook)
{
	std::cout << "����: " << std::endl;
	std::cout << "3.1 - ������" << std::endl;
	std::cout << "3.2 - �������" << std::endl;
	std::cout << "3.3 - �������" << std::endl;
	std::cout << "3.4 - �������" << std::endl;
	std::cout << "Esc - ��������� � ������� ����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void CallsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintCallsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Call call;
				Initials in;
				Contact con;
				int day, month, year;
				std::cout << "������� ���� ������: ";
				std::cin.ignore(); // ����������� � CIN.IGNORE
				std::getline(std::cin, call.affair);
				std::cout << "������� ����, �� ������� ����� ��������� ������: ";
				std::cin >> day >> month >> year;
				call.date.tm_mday = day;
				call.date.tm_mon = month - 1;
				call.date.tm_year = year - 1900;
				std::cout << "������� �����, ����� ���������� ���������: ";
				std::cin >> call.date.tm_hour >> call.date.tm_min;
				std::cout << "������� ��� ��������, �������� ���������� ���������: ";
				std::cin >> in.surname >> in.name >> in.patronymic;
				try {
					con = outlook.FindContact(in);
				}
				catch (std::domain_error ex) {
					std::cout << "������� �������� ��� � ����� ���������� �����, ������ ��� ��������?" << std::endl;
					std::cout << "1 - ��" << std::endl;
					std::cout << "2 - ���" << std::endl;
					std::cout << "������� ����������� �������...";
					bool isBreak = true;
					while (isBreak) {
						if (_kbhit()) {
							switch (_getch()) {
							case 49:
								int bDay, bMonth, bYear, phone;
								std::cout << "\n������� ���� �������� ������ ��������: ";
								std::cin >> bDay >> bMonth >> bYear;
								std::cout << "������� ����� �������� ������ ��������: ";
								std::cin >> phone;
								con = Contact(in.surname, in.name, in.patronymic, bDay, bMonth, bYear, phone);
								outlook.AddContact(con);
								std::cout << "������� ������� ��������!" << std::endl;
								Sleep(1000);
								isBreak = false;
								break;
							case 50:
								con = Contact(in.surname, in.name, in.patronymic, 1, 1, 1900, 1111111);
								isBreak = false;
								break;
							default:
								std::cout << "\n�������� ����, ��������� ������: ";
								break;
							}
						}
					}
				}
				call.contact = con;
				try {
					outlook.AddCall(call);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������ ��� �������!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintCallsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������ ������� ��������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintCallsInfo(outlook);
				break;
			}
			case 50: {  // 2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� ������: ";
				std::cin >> index;
				try {
					outlook.RemoveCall(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������ ������� �����!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintCallsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintCallsInfo(Outlook outlook)
{
	std::cout << "������: " << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetCall(i + 1).GetInfo();
	}
	std::cout << "3.1.1 - �������� ����� ������" << std::endl;
	std::cout << "3.1.2 - ������� ������" << std::endl;
	std::cout << "Esc - ��������� � �����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void MeetingsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintMeetingsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Meeting meeting;
				int day, month, year;
				std::cout << "������� ���� �������: ";
				std::cin.ignore(1);
				std::getline(std::cin, meeting.affair);
				std::cout << "������� ����, ����� ���������� �����������: ";
				std::cin >> day >> month >> year;
				meeting.date.tm_mday = day;
				meeting.date.tm_mon = month - 1;
				meeting.date.tm_year = year - 1900;
				std::cout << "������� �����, ����� ���������� �����������: ";
				std::cin >> meeting.date.tm_hour >> meeting.date.tm_min;
				std::cout << "������� ����� �������: ";
				std::cin.ignore(1);
				std::getline(std::cin, meeting.location);
				std::cout << "������� ����������������� ����������������� �������: ";
				std::cin >> meeting.duration;
				try {
					outlook.AddMeeting(meeting);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ��������!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintMeetingsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������� ������� ���������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintMeetingsInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveMeeting(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: " << std::endl;
					break;
				}
				system("cls");
				std::cout << "������� ������� ������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintMeetingsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintMeetingsInfo(Outlook outlook)
{
	std::cout << "�������: " << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetMeeting(i + 1).GetInfo();
	}
	std::cout << "3.2.1 - �������� ����� �������" << std::endl;
	std::cout << "3.2.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void AssignmentsMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintAssigmentsInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Assignment assignment;
				int day, month, year;
				std::cout << "������� �������: ";
				std::cin.ignore(1);
				std::getline(std::cin, assignment.affair);
				std::cout << "������� ����, ����� ���������� ��������� �������: ";
				std::cin >> day >> month >> year;
				assignment.date.tm_mday = day;
				assignment.date.tm_mon = month - 1;
				assignment.date.tm_year = year - 1900;
				std::cout << "������� ����������������� ����������������� �������: ";
				std::cin >> assignment.duration;
				try {
					outlook.AddAssignment(assignment);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ��������!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintAssigmentsInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������� ������� ���������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintAssigmentsInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveAssignment(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: ";
					break;
				}
				system("cls");
				std::cout << "������� ������� ������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintAssigmentsInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintAssigmentsInfo(Outlook outlook)
{
	std::cout << "�������: " << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetAssignment(i + 1).GetInfo();
	}
	std::cout << "3.3.1 - �������� ����� �������" << std::endl;
	std::cout << "3.3.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void NotesMenu(Outlook& outlook)
{
	system("cls");
	bool isBreak = true;
	PrintNotesInfo(outlook);
	while (isBreak) {
		if (_kbhit()) {
			switch (_getch()) {
			case 49: { // 1
				system("cls");
				Note note;
				int day, month, year;
				std::cout << "������� �������� �������: ";
				std::cin.ignore(1);
				std::getline(std::cin, note.affair);
				std::cout << "������� ����, ����� ���������� ��������� � �������: ";
				std::cin >> day >> month >> year;
				note.date.tm_mday = day;
				note.date.tm_mon = month - 1;
				note.date.tm_year = year - 1900;
				try {
					outlook.AddNote(note);
				}
				catch (std::domain_error ex) {
					system("cls");
					std::cout << "������ ������� ��� ��������!" << std::endl;
					Sleep(1000);
					system("cls");
					PrintNotesInfo(outlook);
					break;
				}
				system("cls");
				std::cout << "������� ������� ���������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintNotesInfo(outlook);
				break;
			}
			case 50: { // 2
				int index;
				std::cout << "\n������� �����, �������� ������������ ��������� �������: ";
				std::cin >> index;
				try {
					outlook.RemoveNote(index);
				}
				catch (std::invalid_argument ex) {
					std::cout << "�� ����� �������� �����, ���������� ��� ���: ";
					break;
				}
				system("cls");
				std::cout << "������� ������� ������!" << std::endl;
				Sleep(1000);
				system("cls");
				PrintNotesInfo(outlook);
				break;
			}
			case 27: {
				isBreak = false;
				break;
			}
			default:
				std::cout << "\n�������� ����, ��������� ������: ";
				break;
			}
		}
	}
}

void PrintNotesInfo(Outlook outlook)
{
	std::cout << "�������: " << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		std::cout << i + 1 << ".";
		outlook.GetNote(i + 1).GetInfo();
	}
	std::cout << "3.4.1 - �������� ����� �������" << std::endl;
	std::cout << "3.4.2 - ������� �������" << std::endl;
	std::cout << "Esc - ��������� � �����" << std::endl;
	std::cout << "������� ����������� �������...";
}

void GetReminders(Outlook outlook)
{
	system("cls");
	std::time_t t = std::time(0);
	tm* local = std::localtime(&t);
	Contact con;
	Call call;
	Meeting meeting;
	Assignment assignment;
	Note note;
	std::cout << "������� ���������� ���������� � ��� �������� ��������� ����� �� ����� ���������� �����: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetContactsSize(); ++i) {
		con = outlook.GetContact(i + 1);
		if (con.date.tm_mon == (*local).tm_mon
			&& con.date.tm_mday == (*local).tm_mday)
			con.GetInfo();
	}
	std::cout << "������� ���������� ��������� ��������� ������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		call = outlook.GetCall(i + 1);
		if (call.date.tm_year == (*local).tm_year
			&& call.date.tm_mon == (*local).tm_mon
			&& call.date.tm_mday == (*local).tm_mday)
			call.GetInfo();
	}
	std::cout << "������� ��� ������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		meeting = outlook.GetMeeting(i + 1);
		if (meeting.date.tm_year == (*local).tm_year
			&& meeting.date.tm_mon == (*local).tm_mon
			&& meeting.date.tm_mday == (*local).tm_mday)
			meeting.GetInfo();
	}
	std::cout << "������� ��������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		assignment = outlook.GetAssignment(i + 1);
		if (assignment.date.tm_year == (*local).tm_year
			&& assignment.date.tm_mon == (*local).tm_mon
			&& assignment.date.tm_mday == (*local).tm_mday)
			assignment.GetInfo();
	}
	std::cout << "������� ��������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		note = outlook.GetNote(i + 1);
		if (note.date.tm_year == (*local).tm_year
			&& note.date.tm_mon == (*local).tm_mon
			&& note.date.tm_mday == (*local).tm_mday)
			note.GetInfo();
	}
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
}

void FindEvents(Outlook outlook)
{
	system("cls");
	tm local = { 0 };
	Call call;
	Meeting meeting;
	Assignment assignment;
	Note note;
	int day, month, year;
	std::cout << "������� ����, �� ������� ������ ����������� �����������: ";
	std::cin >> day >> month >> year;
	local.tm_mday = day;
	local.tm_mon = month - 1;
	local.tm_year = year - 1900;
	system("cls");
	std::cout << "�� �������� ���� ������������� ��������� �����������: " << std::endl << std::endl;
	std::cout << "���������� ��������� ��������� ������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetCallsSize(); ++i) {
		call = outlook.GetCall(i + 1);
		if (call.date.tm_year == local.tm_year
			&& call.date.tm_mon == local.tm_mon
			&& call.date.tm_mday == local.tm_mday)
			call.GetInfo();
	}
	std::cout << "��� ������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetMeetingsSize(); ++i) {
		meeting = outlook.GetMeeting(i + 1);
		if (meeting.date.tm_year == local.tm_year
			&& meeting.date.tm_mon == local.tm_mon
			&& meeting.date.tm_mday == local.tm_mday)
			meeting.GetInfo();
	}
	std::cout << "��������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetAssignmentsSize(); ++i) {
		assignment = outlook.GetAssignment(i + 1);
		if (assignment.date.tm_year == local.tm_year
			&& assignment.date.tm_mon == local.tm_mon
			&& assignment.date.tm_mday == local.tm_mday)
			assignment.GetInfo();
	}
	std::cout << "��������� ��������� �������: " << std::endl;
	std::cout << "_______________________________________________________" << std::endl;
	for (int i = 0; i < outlook.GetNotesSize(); ++i) {
		note = outlook.GetNote(i + 1);
		if (note.date.tm_year == local.tm_year
			&& note.date.tm_mon == local.tm_mon
			&& note.date.tm_mday == local.tm_mday)
			note.GetInfo();
	}
	std::cout << "������� ����� ������� ��� �����������...";
	_getch();
}