#include<iostream>
#include<windows.h>
using namespace std;
string d[63][3];
int programs() {
	int t;
	cout<<"�������"<<endl<<"0.����"<<endl;
	while (cin>>t) {
		if (t==0) {
			return 0;
		}
		cout<<"�������"<<endl<<"0.���� 1.������"<<endl;
	}
	return 0;
}
int settings() {
	int t;
	cout<<"�������"<<endl<<"0.���� 1.�л�����"<<endl;
	while (cin>>t) {
		if (t==1) {
			cout<<"����:�л�����������Ļ"<<endl;
			cout<<"ѡ������"<<endl<<"1.�� 2.�� 3.�� 4.�� 5.�� 6.�Զ���(ʵ����)";
			int n;
			cin>>n;
			if (n==1) {
				system("color 07");
			} else if (n==2) {
				system("color 70");
			} else if (n==3) {
				system("color 02");
			} else if (n==4) {
				system("color 17");
			} else if (n==5) {
				system("color 87");
			} else if (n==6) {
				cout<<"������1��2��ʮ����������"<<endl;
				cout<<"��ɫ����������ʮ����������ָ�� -- ��һ����Ӧ�ڱ������ڶ�����Ӧ��ǰ����ÿ�����ֿ���Ϊ�����κ�ֵ:"<<endl;
				cout<<"    0 = ��ɫ       8 = ��ɫ"<<endl;
				cout<<"    1 = ��ɫ       9 = ����ɫ"<<endl;
				cout<<"    2 = ��ɫ       A = ����ɫ"<<endl;
				cout<<"    3 = ǳ��ɫ     B = ��ǳ��ɫ"<<endl;
				cout<<"    4 = ��ɫ       C = ����ɫ"<<endl;
				cout<<"    5 = ��ɫ       D = ����ɫ"<<endl;
				cout<<"    6 = ��ɫ       E = ����ɫ"<<endl;
				cout<<"    7 = ��ɫ       F = ����ɫ"<<endl;
				string a;
				cin>>a;
				a="color "+a;
				system(a.c_str());
			}
			system("cls");
			cout<<"�ɹ�"<<endl;
		} else if (t==0) {
			return 0;
		}
		cout<<"�������"<<endl<<"0.���� 1.�л�����"<<endl;
	}
	return 0;
}
int dir() {
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="1") {
			cout<<d[i][1]<<endl;
		}
	}
	return 0;
}
int poen(string t) {
	int q=0;
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			cout<<"�򿪳ɹ�"<<endl<<d[i][2]<<endl;
			q=1;
			break;
		}
	}
	if (q==0) {
		cout<<"��ʧ��"<<endl;
		return 1;
	}
	return 0;
}
int newe(string t) {
	int q=0;
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="0") {
			d[i][1]=t;
			q=1;
			cout<<"�����ɹ�"<<endl;
			break;
		}
	}
	if (q==1) {
		cout<<"����ʧ��"<<endl;
		return 1;
	}
	return 0;
}
int rename(string t,string tt) {
	int q=0;
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="0"&&d[i][1]==t) {
			d[i][1]==tt;
			q=1;
			cout<<"�������ɹ�"<<endl;
			break;
		}
	}
	if (q==1) {
		cout<<"������ʧ��"<<endl;
		return 1;
	}
	return 0;
}
int edit(string t) {
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			cout<<"���ڱ༭"<<endl;
			cin>>d[i][2];
			cout<<"�ѱ���"<<endl;
			break;
		}
	}
	return 0;
}
int del(string t) {
	int q=0;
	for (int i=0; i<=63; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			d[i][0]="0";
			d[i][1]="";
			d[i][2]="";
			q=1;
			cout<<"ɾ���ɹ�"<<endl;
			break;
		}
	}
	if (q==1) {
		cout<<"ɾ��ʧ��"<<endl;
		return 1;
	}
	return 0;
}
int help() {
	cout<<"��ʾ�������ļ����ɿ��ٴ�"<<endl;
	cout<<"��ʾ��������������ĸִ������"<<endl;
	cout<<endl;
	cout<<"\033[4mp\033[0mrograms\t\t\t\t�򿪳����б�"<<endl;
	cout<<"\033[4ms\033[0mettings\t\t\t\t�����á�"<<endl;
	cout<<"\033[4mh\033[0melp\t\t\t\t\t�ṩ����İ�����Ϣ��"<<endl;
	cout<<"cls\t\t\t\t\t�����Ļ��"<<endl;
	cout<<endl;
	cout<<"\033[4md\033[0mir\t\t\t\t\t��ʾ�����ļ���"<<endl;
	cout<<"\033[4mo\033[0mpen <�ļ���>\t\t\t\t���ļ���"<<endl;
	cout<<"\033[4mn\033[0mew <�ļ���>\t\t\t\t�½��ļ���"<<endl;
	cout<<"\033[4me\033[0mdit <�ļ���>\t\t\t\t�༭�ļ���"<<endl;
	cout<<"\033[4mr\033[0mename <�ļ���> <���ļ���>\t\t�������ļ���"<<endl;
	cout<<"del <�ļ���>\t\t\t\tɾ���ļ���"<<endl;
	return 0;
}
int main() {
	printf("\rLaoding");
	for (int i=0; i<=63; i++) {
		if (i<=3) {
			d[i][0]="1";
		} else {
			d[i][0]="0";
		}
	}
	d[0][1]="��ӭ";
	d[0][2]="��ӭʹ�ñ�ϵͳ����ϵͳ������Ϊ���ṩ��Ч���ȶ��ķ�ͼ�λ��������飬������������ݡ���л����ѡ�������Σ�";
	d[1][1]="����";
	d[1][2]="*��������*";
	d[2][1]="�̳�";
	d[2][2]="*���Լ���һ��help����ý̳�*";
	Sleep(500);
	cout<<"\r"<<"��ӭʹ�ñ�ϵͳ"<<endl;
	cout<<"���� \033[4mh\033[0melp �� h ��ȡ�ð���(���ִ�Сд)"<<endl;
	string s,t,tt;
	cout<<"A:/>";
	while (cin>>s) {
		if (s=="programs" || s=="p") {
			programs();
		} else if (s=="settings" || s=="s") {
			settings();
		} else if (s=="help" || s=="h") {
			help();
		} else if (s=="dir" || s=="d") {
			dir();
		} else if (s=="open" || s=="o") {
			cin>>t;
			poen(t);
		} else if (s=="new" || s=="n") {
			cin>>t;
			newe(t);
		} else if (s=="edit" || s=="e") {
			cin>>t;
			edit(t);
		} else if (s=="rename" || s=="r") {
			cin>>t>>tt;
			rename(t,tt);
		} else if (s=="del") {
			cin>>t;
			del(t);
		} else if (s=="cls") {
			system("cls");
		} else if (s=="cmd") {
			string a;
			while (cin>>a) {
				if (a=="0") {
					break;
				}
				system(a.c_str());
			}
		} else {
			int q=poen(s);
			if (q==1) {
				cout<<"'"<<s<<"' �����ڲ����ⲿ���Ҳ���ǿ����еĳ�����������ļ���";
			}
		}
		cout<<endl<<"A:/>";
	}
	return 0;
}
