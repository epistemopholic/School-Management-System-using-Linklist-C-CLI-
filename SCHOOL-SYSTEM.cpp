// SCHOOL-SYSTEM.cpp : Defines the entry point for the console application.//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
int counter = 0;
using namespace std;

struct student {
	string first_name;
	string last_name;
	string father_name;
	string address;
	int reg_num;
	int class_name;
	student *next;
};
struct teacher {
	string first_name;
	string last_name;
	string addres;
	string main_subject;
	int contact_num;
	int grade_num;
	teacher *next;
};

class school {
	student *s_cur, *s_start, *s_temp;
	teacher *t_cur, *t_start, *t_temp;
public:
	school() {
		s_start = NULL;
		t_start = NULL;
	}															// STUDENT PORTAL //
	void insert_student() {
		string f_name, l_name, ft_name, addr;
		int c_name, r_num;
		cout << "Enter STUDENT INFO - FIRST NAME" << endl;
		cin >> f_name;
		cout << "Enter STUDENT INFO - LAST NAME" << endl;
		cin >> l_name;
		cout << "Enter STUDENT INFO - FATHER  NAME : " << endl;
		cin >> ft_name;
		cout << "Enter STUDENT INFO - COMPLETE ADDRESS : " << endl;
		cin >> addr;
		cout << "Enter STUDENT INFO - REGISTRATION NUMBER : " << endl;
		cin >> r_num;
		cout << "Enter STUDENT INFO - SELECT A CLASS" << endl;
	c_menu:
		cout << "(1) CLASS ONE" << endl;
		cout << "(2) CLASS TWO" << endl;
		cout << "(3) CLASS THREE" << endl;
		cout << "(4) CLASS FOUR" << endl;
		cout << "(5) CLASS FIVE" << endl;
		cin >> c_name;
		switch (c_name) {
		case 1:
			cout << "MONTHLY FEES IS: 500.RS" << endl;
			cout << "SUCESSFULLY ADDED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 2:
			cout << "MONTHLY FEES IS: 1000.RS" << endl;
			cout << "SUCESSFULLY ADDED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 3:
			cout << "MONTHLY FEES IS: 1500.RS" << endl;
			cout << "SUCESSFULLY ADDED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 4:
			cout << "MONTHLY FEES IS: 2000.RS" << endl;
			cout << "SUCESSFULLY ADDED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 5:
			cout << "MONTHLY FEES IS: 2500.RS" << endl;
			cout << "SUCESSFULLY ADDED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		default:
			cout << "INVALID SELECTION, RETURNING TO MENU AND SELECT AGAIN" << endl;
			cout << endl;
			goto c_menu;
		}

		if (s_start == NULL) {
			s_start = new student;
			s_start->first_name = f_name;
			s_start->last_name = l_name;
			s_start->father_name = ft_name;
			s_start->address = addr;
			s_start->reg_num = r_num;
			s_start->class_name = c_name;

			s_start->next = NULL;
			counter++;
		}
		else
		{
			s_cur = s_start;
			while (s_cur->next != NULL)
			{
				s_cur = s_cur->next;
			}
			s_temp = new student;
			s_temp->first_name = f_name;
			s_temp->last_name = l_name;
			s_start->father_name = ft_name;
			s_start->address = addr;
			s_temp->reg_num = r_num;
			s_temp->class_name = c_name;

			s_temp->next = NULL;
			s_cur->next = s_temp;
		}
	}

	void delete_student() {
		int regis_num;
		s_temp = s_cur = s_start;
		cout << "ENTER STUDENT INFO - REGISTRATION NUM : " << endl;
		cin >> regis_num;
		//FOR FIRST TIME ONLY
		if (s_cur->next == NULL)
		{
			if (s_cur->reg_num == regis_num)
			{

				delete s_cur;
				cout << "*******************************************************************" << endl;
				cout << "RECORD HAS BEEN REMOVED, RETURING TO MENU " << endl;
				cout << "*******************************************************************" << endl;
				s_start = NULL;
			}

			else {
				cout << "RECORD NOT FOUND !, RETURNING TO MENU" << endl;
				cout << endl;
			}
		}
		// CHECK THIS CODE....//
		else {
			while (s_cur->next != NULL) {
				if (s_cur->reg_num == regis_num)
				{
					s_temp = s_cur->next;
					delete s_cur;
					cout << "*******************************************************************" << endl;
					cout << "RECORD HAS BEEN REMOVED, RETURING TO MENU " << endl;
					cout << "*******************************************************************" << endl;
					break;
				}
				else
				{
					s_temp = s_cur;
					s_cur = s_cur->next;
				}
			}
		}

}


	void student_class () {
		int choice;
		do {
			cout << "(1) CLASS ONE " << endl;
			cout << "(2) CLASS TWO " << endl;
			cout << "(3) CLASS THREE " << endl;
			cout << "(4) CLASS FOUR " << endl;
			cout << "(5) CLASS FIVE " << endl;
		} while (choice != 0);
	}

	void display_student() {

		if (s_start == NULL) {
			cout << "NO RECORD'S FOUND!!!" << endl;
			cout << endl;
			return;
		}
		s_cur = s_start;
		int count=0;
		while (s_cur->next != NULL) {
			count++;
			cout << "STUDENT # " << count << endl;
			cout << "STUDENT INFO - FIRST NAME : " << s_cur->first_name<< endl;
			cout << "STUDENT INFO - LAST NAME : " << s_cur->last_name<<endl;
			cout << "STUDENT INFO - FATHER NAME : " << s_cur->father_name << endl;
			cout << "STUDENT INFO - ADDRESS : " << s_cur->address << endl;
			cout << "STUDENT INFO - REGISTRATION NUM : " << s_cur->reg_num<< endl;
			cout << "STUDENT INFO - CLASS NAME : " << s_cur->class_name<< endl;
			
			cout << endl;
			s_cur = s_cur->next;
		}
			count++;
			cout << "STUDENT # " << count << endl;
			cout << "STUDENT INFO - FIRST NAME : " << s_cur->first_name<< endl;
			cout << "STUDENT INFO - FATHER NAME : " << s_cur->father_name << endl;
			cout << "STUDENT INFO - ADDRESS : " << s_cur->address << endl;
			cout << "STUDENT INFO - LAST NAME : " << s_cur->last_name<< endl;
			cout << "STUDENT INFO - REGISTRATION NUM : " << s_cur->reg_num<< endl;
			cout << "STUDENT INFO - CLASS NAME : " << s_cur->class_name<< endl;
	
			cout << endl;
	}


																// TEACHER PORTAL //

	void insert_teacher() {
		string f_name, l_name, s_name,addr;
		int c_num, g_num;
		cout << "Enter TEACHER INFO - FIRST NAME" << endl;
		cin >> f_name;
		cout << "Enter TEACHER INFO - LAST NAME" << endl;
		cin >> l_name;
		cout << "Enter TEACHER INFO - MAIN SUBJECT" << endl;
		cin >> s_name;
		cout << "Enter TEACHER INFO - CONTACT" << endl;
		cin >> c_num;
		cout << "Enter TEACHER INFO - ADDRESS" << endl;
		cin >> addr;
		g_menu:
		cout << "ENTER TEACHE INFO - GRADE (14-18)" << endl;
		cout << "(1) GRADE - 14" << endl;
		cout << "(2) GRADE - 15" << endl;
		cout << "(3) GRADE - 16" << endl;
		cout << "(4) GRADE - 17" << endl;
		cout << "(5) GRADE - 18" << endl;
		cin >> g_num;
		switch (g_num)
		{
		case 1:
			cout << "MONTHLY PAY is 30,000.Rs" << endl;
			cout << "SUCCESSFULLY APPOINTED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 2:
			cout << "MONTHLY PAY is 40,000.Rs" << endl;
			cout << "SUCCESSFULLY APPOINTED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 3:
			cout << "MONTHLY PAY is 50,000.Rs" << endl;
			cout << "SUCCESSFULLY APPOINTED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 4:
			cout << "MONTHLY PAY is 60,000.Rs" << endl;
			cout << "SUCCESSFULLY APPOINTED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		case 5:
			cout << "MONTHLY PAY is 70,000.Rs" << endl;
			cout << "SUCCESSFULLY APPOINTED, RETURNING TO MENU" << endl;
			cout << endl;
			break;
		default:
			cout << "INVALIED SELECTION, ENTER AGAIN " << endl;
			goto g_menu;
			break;
		}

		if (t_start == NULL) {
			t_start = new teacher;
			t_start->first_name = f_name;
			t_start->last_name = l_name;
			t_start->main_subject = s_name;
			t_start->addres = addr;
			t_start->contact_num = c_num;
			t_start->grade_num = g_num;
			t_start->next = NULL;
			
		}
		else
		{
			t_cur = t_start;
			while (t_cur->next != NULL)
			{
				t_cur = t_cur->next;
			}
			t_temp = new teacher;
			t_temp->first_name = f_name;
			t_temp->last_name = l_name;
			t_temp->main_subject = s_name;
			t_start->addres = addr;
			t_temp->contact_num = c_num;
			t_start->grade_num = g_num;
			t_temp->next = NULL;
			t_cur->next = t_temp;
		}
	}
	void display_teacher() {
		int count=0;
		if (t_start == NULL) {
			cout << "NO RECORD'S FOUND!!!" << endl;
				cout << endl;
			return;
		}
		t_cur = t_start;
		while (t_cur->next != NULL) {
			count++;
			cout << "TEACHER # " << count << endl;
			cout <<"TEACHER INFO - FIRST NAME : " << t_cur->first_name<< endl;
			cout << "TEACHER INFO - LAST NAME : " << t_cur->last_name<<endl;
			cout << "TEACHER INFO - SUBJECT : " << t_cur->main_subject<<endl;
			cout << "TEACHER INFO - CONTACT : " << t_cur->addres << endl;
			cout << "TEACHER INFO - CONTACT : " << t_cur->contact_num<< endl;
			cout << "TEACHER INFO - CONTACT : " << t_cur->grade_num << endl;
			cout << endl;
		
			t_cur = t_cur->next;
		}
		count++;
		cout << "TEACHER # " << count << endl;
		cout << "TEACHER INFO - FIRST NAME : " << t_cur->first_name << endl;
		cout << "TEACHER INFO - LAST NAME : " << t_cur->last_name << endl;
		cout << "TEACHER INFO - MAIN SUBJECT: " << t_cur->main_subject << endl;
		cout << "TEACHER INFO - ADDRESS : " << t_cur->addres << endl;
		cout << "TEACHER INFO - CONTACT NUM : " << t_cur->contact_num << endl;
		cout << "TEACHER INFO - GRADE : " << t_cur->grade_num << endl;
		cout << endl;

	}
};

int main()
{
	system("Color 2F");
	cout << "				################ SCHOOL SYSTEM ################				" << endl;
	cout << "				########## BY HAMZA (024) & ZIA (048) #########			" << endl;

	school data;
	int choice;
	do {
	main_menu:
		cout << "(1) - STUDENT PORTAL" << endl;
		cout << "(2) - TEACHER PORTAL" << endl;
		cout << "(0) - EXIT" << endl;
		cout << endl;
		cout << "SELECT A OPTION : ";
		cin >> choice;
		cout << endl;
		cout << endl;

		switch (choice)
		{
		case 1:
			student_menu:
			cout << "(1) REGISTER NEW STUDENT" << endl;
			cout << "(2) SHOW ALL STUDENT'S DATA" << endl;
			cout << "(3) DELETE A STUDENT'S DATA (via Reg. NUM)" << endl;
			cout << "(4) RETURN TO MENU" << endl;
			cout << endl;
			cout << "SELECT A OPTION : ";
			cin >> choice;
			cout << endl;
			cout << endl;
				switch (choice) {
				case 1:
					data.insert_student();
					goto student_menu;
					break;
				case 2:
					data.display_student();
					goto student_menu;
					break;
				case 3:
					data.delete_student();
					goto student_menu;
					break;
				case 4:
					goto main_menu;
					break;
				default:
					cout << "INVALID SELECTION, RETURNED TO MENU" << endl;
					goto student_menu;
			}
				break;
		case 2:
			teacher_menu:
				cout << "(1) HIRE NEW TEACHER" << endl;
				cout << "(2) SHOW ALL TEACHER'S DATA" << endl;
				cout << "(3) RETURN TO MENU" << endl;
				cout << endl;
				cout << "SELECT A OPTION : ";
				cout << endl;
				cout << endl;
				cin >> choice;
				switch (choice) {
				case 1:
					data.insert_teacher();
					goto teacher_menu;
					break;
				case 2:
					data.display_teacher();
					goto teacher_menu;
					break;
				case 3:
					goto main_menu;
					break;
				default:
					cout << "INVALID SELECTION, RETURNED TO MENU " << endl;
					goto teacher_menu;
				}
				break;
			case 0:
				return 0;
				break;
			default:
				cout << "INVALID SELECTION, RETURNED TO MENU " << endl;
			}
		
	} while (choice!=0);
	
    return 0;
}