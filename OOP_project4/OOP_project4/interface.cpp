#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <Windows.h>

#include "numPuzzle.h"
#include "history.h"
using namespace std;

// �� �Լ� ����ؼ� ������ ������ּ���!
void writeHistory(string game, string name, int score) {
	ofstream ofile; ofile.open("file.txt", ios::app);
	ofile << game + "/" + name + "/" + to_string(score) + "\n"; 
	ofile.close();
}

int main() {
	char input[250];

	while (1) {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n");
		printf("%35s", " "); cout << "---------------OOP_MINI_GAMES---------------\n\n";
		printf("%35s", " "); cout << "               0. ���\n";
		printf("%35s", " "); cout << "               1. ��ǳ�ģ����/�������\n";
		printf("%35s", " "); cout << "               2. ���� ����\n";
		printf("%35s", " "); cout << "               3. ���� �߱�/�ؽ�Ʈ ��Ŀ\n";
		printf("%35s", " "); cout << "               4. ��ī��\n";
		printf("%35s", " "); cout << "               end. ����\n\n";
		printf("%35s", " "); cout << "--------------------------------------------\n";
		printf("%35s", " "); cout << ": ";  cin >> input;



		// ��� ���๮ _ ������
		int sort_opt = 1;
		if (!strcmp(input, "0")) {
			int searchNum;
			History hist("file.txt");
			hist.sorting(sort_opt);

			while (1)
			{
				system("cls");
				cout << "--------------------���--------------------\n\n";
				cout << "               1. Search\n";
				cout << "               2. Sortin Option\n";
				cout << "               3. ����\n\n";
				cout << "--------------------------------------------\n";
				cout << ": ";  cin >> searchNum;
				

				// 1��
				if (searchNum == 1) {
					while (1) {
						int select;
						string keyword;
						cout << "\n\n- Search -\n";
						cout << "1. Search by game\n";
						cout << "2. Search by name\n";
						cout << "3. List All\n";
						cin >> select;
						if (select == 1) { 
							cout << "game keyword? "; cin >> keyword; hist.print(select, keyword); 
							cout << "\n\n����ϽǷ��� �ƹ� ������ ���� ENTER�� �����ּ���."; cin >> keyword; break; 
						}
						else if (select == 2) { 
							cout << "name keyword? "; cin >> keyword; hist.print(select, keyword);
							cout << "\n\n����ϽǷ��� �ƹ� �ܾ��� ���� ENTER�� �����ּ���."; cin >> keyword; break;
						}
						else if (select == 3) { 
							hist.print(select, keyword); 
							cout << "\n\n����ϽǷ��� �ƹ� �ܾ��� ���� ENTER�� �����ּ���."; cin >> keyword; break;
						}
						else { cout << "1~3�� �� �ϳ��� �����Ͻÿ�\n\n"; }
						
					}
				}

				// 2��
				else if (searchNum == 2) {
					while (1)
					{
						int select;
						cout << "\n\n- Sorting Option -\n";
						cout << "1. Sort by game\n";
						cout << "2. Sort by name\n";
						cout << "3. Sort by score\n";
						cin >> select;
						if (select > 0 && select < 4) { sort_opt = select; hist.sorting(sort_opt); break; }
						else { cout << "1~3 �� �� �ϳ��� �����Ͻÿ�\n\n"; }
					}

				}

				//3��
				else if (searchNum == 3) {
					cout << "���α׷��� ����˴ϴ�.\n"; break;
				}

				// �߸��� �Է�
				else {
					cout << "�߸��� �Է��Դϴ�.\n";
				}
			}

		}


		// ��ǳ�ģ����/������� ���๮ _ ��ȿ��
		else if (!strcmp(input, "1")) { 
			system("cls");

		}


		// ���� ���� ���๮ _ ������
		else if (!strcmp(input, "2")) {
			char select[250];
			string player;
			bool isRank = false;
			int selHist;
			numBox *puzzle;

			while (1) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				printf("%35s", " "); cout << "--------------------------------------------\n";
				printf("%35s", " "); cout << "               1. 3 X 3\n";
				printf("%35s", " "); cout << "               2. 4 X 4\n";
				printf("%35s", " "); cout << "               3. 5 X 5\n\n";
				printf("%35s", " "); cout << "     **5 X 5�� ������ ����� �� �����ϴ�**\n";
				printf("%35s", " "); cout << "--------------------------------------------\n";
				printf("%35s", " "); cout << ": ";  cin >> select;

				if (!strcmp(select, "1")) { numBox puzz = numBox(3, 3); puzzle = &puzz; isRank = true; break; }
				else if (!strcmp(select, "2")) { numBox puzz = numBox(4, 4); puzzle = &puzz; isRank = true; break;}
				else if (!strcmp(select, "3")) { numBox puzz = numBox(5, 5); puzzle = &puzz; break;}
				else printf("%35s", " "); cout << "- ��Ͽ� �����ϴ� ���� �Է����ּ���\n\n.";
			}
			puzzle->shuffle();

			while (!puzzle->isComplete()) {
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n");
				puzzle->print();
				printf("\n%35s", " "); printf("������ Ƚ��: %d\n", puzzle->count);
				printf("\n%35s", " "); printf("�����ϰ� �����ôٸ� end�� �Է����ּ���", puzzle->count);
				printf("\n%35s", " "); cout << "�� ��° ĭ�� �����̽� �ǰ���?: ";  cin >> select;

				if (!strcmp(select, "end")) { isRank = false; break;}
				if (!atoi(select) | atoi(select) > puzzle->getSize()) { printf("\n%28s", " "); cout << "�ùٸ� ���ڸ� �Է��� �ּ���!"; Sleep(1000); }
				else if (puzzle->go(atoi(select) - 1)) puzzle->count++;
				else { printf("\n%35s", " "); cout << "�ش���ġ�� �̵��� �� �����ϴ�!"; Sleep(1000); }

				if(puzzle->isComplete()) { printf("\n%28s", " "); printf("�� %d �� ������ �ϼ��߽��ϴ�.", puzzle->count); Sleep(3000); }
			}
			
			if (isRank) {
				printf("\n%28s", " "); printf("���� ������ ����Ͻðڽ��ϱ�? 1. ��   2. �ƴϿ� :"); cin >> selHist;
				if (selHist == 1) {
					printf("\n%28s", " "); cout << "����� �̸��� �����ּ��� : "; cin >> player;
					writeHistory("NumPuzzle", player, puzzle->count);
				}

			}
		}


		// ���� �߱�/�ؽ�Ʈ ��Ŀ ���๮ _ �����
		else if (!strcmp(input, "3")) {
			system("cls");


		}


		// ��ī�� ���๮ _ �Ӱ�
		else if (!strcmp(input, "4")) {
			system("cls");


		}


		// ����
		else if (!strcmp(input, "end")) {
		printf("%35s", " "); cout << "- ���α׷��� �����ϰڽ��ϴ�.\n";
			return 0;
		}
		// �߸��� ��
		else {
			printf("%35s", " "); cout << "- ��Ͽ� �����ϴ� ���� �Է����ּ���\n\n.";
			Sleep(1000);
		}


	}

}