#include "head.hpp"

vector<bool> ProVis;                //  ��ǰ�����Ƿ��Ѿ���ȫ����
vector<string> ID;                  //  ÿ�����̵�����
vector<vector<int> > Max;           //  ÿ�����̶�ÿ����Դ������
vector<vector<int> > Allocation;    //  ÿ�������Ѿ������ÿ����Դ
vector<vector<int> > Need;          //  ���̻���Ҫ��Դ
vector<int> Request;                //  ����������Դ��
vector<int> SafeOrder;              //  ��ȫִ�е�˳��
vector<int> Available;              //  ϵͳ�ɷ�����Դ
int idx;                            //  ����Ľ��̱��
int NoAllocCnt;                     //  ��ǰû�з�����ȫ�Ľ�����

// ��ʼ��
void init() {
	ID = { "P0", "P1", "P2", "P3", "P4" };
	Available = { 3, 3, 2 };
	Max = { { 7, 5, 3 }, { 3, 2, 2 }, { 9, 0, 2 }, { 2, 2, 2 }, { 4, 3, 3 } };
	Allocation = { { 0, 1, 0 }, { 2, 0, 0 }, { 3, 0, 2 }, { 2, 1, 1 }, { 0, 0, 2 } };
	Need = { { 7, 4, 3 }, { 1, 2, 2 }, { 6, 0, 0 }, { 0, 1, 1 }, { 4, 3, 1 } };

	idx = -1;
	NoAllocCnt = PROCESSCNT;
	ProVis.resize(PROCESSCNT, false);
	Request.resize(RESOURCECNT);
	//SafeOrder.resize(PROCESSCNT,-1);
	for (int i = 0; i < PROCESSCNT; i++) SafeOrder.push_back(i);
}


// ��ʾϵͳ��Դ��δ�����Ľ���ռ����Դ���                            
void display() {
	printf("\n\n\n-----------------------------------------\n");
	printf("��ǰϵͳ������Դ: \n");
	for (int i = 0; i < RESOURCECNT; i++) printf("\t%c", 'A' + i);
	printf("\n");
	for (int i = 0; i < RESOURCECNT; i++) printf("\t%d", Available[i]);
	printf("\n\n");

	printf("����ִ�н��̵���Դ��������� \n");
	printf("ID \tMAX \t Allocation \t Need \n");
	for (int i = 0; i < NoAllocCnt; i++) {
		int p = SafeOrder[i];
		cout << ID[p] << "\t";
		for (int j = 0; j < RESOURCECNT; j++) cout << Max[p][j] << " ";
		cout << " \t    ";

		for (int j = 0; j < RESOURCECNT; j++) cout << Allocation[p][j] << " ";
		cout << " \t";

		for (int j = 0; j < RESOURCECNT; j++) cout << Need[p][j] << " ";
		cout << "\n";
	}

	cout << "\n ��ȫ��������У� ";
	for (int i = 0; i < NoAllocCnt; i++){
		cout << SafeOrder[i];
		if (i != NoAllocCnt - 1) cout << " -> ";
	}
	cout << "\n\n";
}

// �õ���һ�������ͷŵĽ��̺ţ�û�з���-1
int GetFirst(vector<int>& t, vector<bool>& vis) {

	for (int i = 0; i < PROCESSCNT; i++) {
		if (vis[i]) continue;
		int j = 0;
		for (; j < RESOURCECNT; j++) {
			if (Need[i][j] > t[j]) break;
		}
		if (j == RESOURCECNT) return i;
	}

	return -1;
}

void check() {
	if (idx == -1) return;
	bool flag = true;
	for (int i = 0; i < RESOURCECNT; i++) {
		Allocation[idx][i] += Request[i];
		Need[idx][i] -= Request[i];
		Available[i] -= Request[i];
		if (Need[idx][i] != 0) flag = false;
	}

	// �����ͷ�
	if (flag) {
		ProVis[idx] = true;
		for (int i = 0; i < NoAllocCnt; i++)
		if (SafeOrder[i] == idx){
			NoAllocCnt--;
			SafeOrder.erase(SafeOrder.begin() + i);
			ProVis[idx] = true;
			for (int j = 0; j < RESOURCECNT; j++)
				Available[j] += Max[idx][j];
			break;
		}
	}
}

// ִ�����м��㷨            
bool banker() {
	vector<int> t = Available;          // ��ǰϵͳ��Դ�ĸ���
	vector<bool> vis = ProVis;          // ��ǰ�ɷ�����Դ�ĸ���
	vector<int> newOrder = SafeOrder;   // ��ȫ���еĸ���
	vector<int> tIdx;                   // ���������̵�Need�ĸ���

	if (idx != -1) {
		tIdx = Need[idx];
		// ��ȥ����������Դ
		for (int i = 0; i < RESOURCECNT; i++) {
			t[i] -= Request[i];
			Need[idx][i] -= Request[i];
		}
	}

	for (int i = 0; i < NoAllocCnt; i++) {
		int index = GetFirst(t, vis);
		// cout << index << " ";
		if (index == -1) {
			if (idx != -1) Need[idx] = tIdx;
			cout << "\n ��ǰ��Դ�޷����� ~~~~~~~~~ " << endl;
			return false; // �����޷�������Դ�Ľ���
		}

		for (int j = 0; j < RESOURCECNT; j++) {
			t[j] += Allocation[index][j];           // ��ǰ���̽����󣬿��Ի�������ϵͳ����Դ��
			if (index == idx) t[j] += Request[j];   // ������������Դ
		}
		newOrder[i] = index;
		vis[index] = true;
	}

	SafeOrder = newOrder;
	if (idx != -1) Need[idx] = tIdx;
	// ���Գɹ����䣬���idx�Ƿ�����ͷ�
	check();

	idx = -1;
	return true;
}

// ���������Դ
bool input() {
	printf("\n\n=========================================\n\n");
	printf("��������Ҫ������Դ�Ľ��̺ţ����� P0 : 0  -> ");
	fflush(stdout);
	cin >> idx;
	// cout <<" ------" <<  idx << endl;
	if (idx < 0 || idx >= PROCESSCNT || ProVis[idx]) {
		cout << " ������̺Ų��Ϸ� ~~~~~~" << endl;
		return false;
	}

	bool flag = true;
	for (int i = 0; i < RESOURCECNT; i++) {
		printf(" ����� [%d] �Ž��� [%c] ��Դ������Ϊ -> ", idx, (char)('A' + i));
		cin >> Request[i];
		if (Request[i] > Need[idx][i] || Available[i] < Request[i]) flag = false;
		cout << endl;
	}
	if (!flag) cout << " ��ǰ��Դ���䲻����(��������������߳��������Դ)�����ܷ��� ~~~~~~~~" << endl;
	return flag;
}

// ���н����Ƿ񶼵õ�����Դ                    
bool isExit() {
	return NoAllocCnt == 0;
}

