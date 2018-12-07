#include<iostream>
#include<string>
using namespace std;

#define HASH_LENGTH 50               //��ϣ��ĳ���         
#define M 47                         //�����
#define NAME_NO 30                   //�����ĸ���        

typedef struct
{
	char *py;    //���ֵ�ƴ��
	int k;       //ƴ������Ӧ������
}NAME;

NAME NameList[HASH_LENGTH];    //ȫ�ֱ���NAME       

typedef struct    //��ϣ��
{
	char *py;   //���ֵ�ƴ��
	int k;      //ƴ������Ӧ������
	int si;     //���ҳ���
}HASH;

HASH HashList[HASH_LENGTH];        //ȫ�ֱ���HASH                     

void InitNameList() //�������ṹ�����飩��ʼ��          
{
	char *f;
	int r, s0, i;
	for (i = 0; i < HASH_LENGTH; i++)
	{
		NameList[i].py = new char[64];
		NameList[i].py[0] = 0;
	}
	strcpy(NameList[0].py, "baojie");
	strcpy(NameList[1].py, "chengaoyang");
	strcpy(NameList[2].py, "chenguangzhong");
	strcpy(NameList[3].py, "chenliangliang");
	strcpy(NameList[4].py, "chenyongzhou");
	strcpy(NameList[5].py, "fengchao");
	strcpy(NameList[6].py, "gexiangfeng");
	strcpy(NameList[7].py, "huting");
	strcpy(NameList[8].py, "huangpinjin");
	strcpy(NameList[9].py, "jiangxiaojia");
	strcpy(NameList[10].py, "laidongjie");
	strcpy(NameList[11].py, "liyexiao");
	strcpy(NameList[12].py, "lidaohui");
	strcpy(NameList[13].py, "lijue");
	strcpy(NameList[14].py, "lizhuoqun");
	strcpy(NameList[15].py, "linfujun");
	strcpy(NameList[16].py, "luobin");
	strcpy(NameList[17].py, "luokeqing");
	strcpy(NameList[18].py, "nichao");
	strcpy(NameList[19].py, "panhuafeng");
	strcpy(NameList[20].py, "sijun");
	strcpy(NameList[21].py, "songzhanhui"); 
	strcpy(NameList[22].py, "sunzhengqing");
	strcpy(NameList[23].py, "wanghaofeng");
	strcpy(NameList[24].py, "wangjunshuai");
	strcpy(NameList[25].py, "wangqinde");
	strcpy(NameList[26].py, "wangzejun");
	strcpy(NameList[27].py, "wangkeke");
	strcpy(NameList[28].py, "weixing");
	strcpy(NameList[29].py, "wurenke");

	for (i = 0; i < NAME_NO; i++)
	{
		s0 = 0;
		f = NameList[i].py;
		for (r = 0; *(f + r) != '\0'; r++)//���������ַ����ĸ����ַ�����Ӧ��
			//ASCII����ӣ����õ�������Ϊ��ϣ��Ĺؼ���
			s0 = *(f + r) + s0;
		NameList[i].k = s0;
	}
}
void CreateHashList() //������ϣ��   
{
	int i;
	for (i = 0; i < HASH_LENGTH; i++)
	{
		HashList[i].py = new char[64];
		HashList[i].py[0] = 0; 
		HashList[i].k = 0;
		HashList[i].si = 0;
	}
	for (i = 0; i < HASH_LENGTH; i++)
	{
		int sum = 0;
		int adr = (NameList[i].k) % M;
		//��ϣ����
		int d = adr;
		if (HashList[adr].si == 0)     //�������ͻ
		{
			HashList[adr].k = NameList[i].k;
			HashList[adr].py = NameList[i].py;
			HashList[adr].si = 1;
		}
		else   //��ͻ 
		{
			while (HashList[d].k != 0)
			{
				d = (d + NameList[i].k % 10 + 1) % M;   //α���̽����ɢ�з������ͻ    
				sum = sum + 1;                    //���Ҵ�����1    
			};
			HashList[d].k = NameList[i].k;
			HashList[d].py = NameList[i].py;
			HashList[d].si = sum + 1;
		}
	}
}
void FindList() //����    
{
	string name;
	int s0 = 0, r, sum = 1, adr, d;
	cout << "������������ƴ��:" << endl;
	cin >> name;;
	for (r = 0; r < 20; r++)   //���������ƴ������Ӧ������(�ؼ���)
		s0 += name[r];
	adr = s0%M;   //ʹ�ù�ϣ����
	d = adr;
	if (HashList[adr].k == s0)          //��3����������ж�
		cout << "����:" << HashList[d].py << " " << "�ؼ���:" << s0 << " " << "���ҳ���Ϊ: 1" << endl;
	else if (HashList[adr].k == 0)
		cout << "�޴˼�¼!" << endl;
	else
	{
		int g = 0;
		while (g == 0)
		{
			d = (d + s0 % 10 + 1) % M;       //α���̽����ɢ�з������ͻ                     
			sum = sum + 1;
			if (HashList[d].k == 0)
			{
				cout << "�޴˼�¼!" << endl;
				g = 1;
			}
			if (HashList[d].k == s0)
			{
				cout << "����:" << HashList[d].py << " " << "�ؼ���:" << s0 << " " << "���ҳ���Ϊ:" << sum << endl;
				g = 1;
			}
		};
	}
}
void   Display() // ��ʾ��ϣ��       
{
	int i;
	float average = 0;

	cout << "\n��ַ\t�ؼ���\t\t��������\tH(key)\t ����\n"; //��ʾ�ĸ�ʽ
	for (i = 0; i < 50; i++)
	{
		cout << i << " ";
		cout << "\t" << HashList[i].k << " ";
		cout << "\t\t" << HashList[i].si << " ";
		cout << "\t\t" << (HashList[i].k%M) << " ";
		cout << "\t " << HashList[i].py << " ";
		cout << "\n";
	}
	for (i = 0; i < HASH_LENGTH; i++)
		average += HashList[i].si;
	average /= NAME_NO;
	cout << "ƽ�����ҳ��ȣ�ASL(" << NAME_NO << ")=" << average << endl;

}
int main()
{
	char x;
	InitNameList();
	CreateHashList();
	cout << "d. ��ʾ��ϣ�� f. ���� ������˳�   ��ѡ��" << endl;
	while (cin >> x)
	{
		if (x == 'd')
		{
			Display();
			cout << endl;
		}
		else if (x == 'f')
		{
			FindList();
			cout << endl;
		}
		else break;
	}
	for (int i = 0; i < HASH_LENGTH; i++)
	{
		free(NameList[i].py);
		free(HashList[i].py);
	}
	return 0;
}