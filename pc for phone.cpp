#include<iostream>
#include<windows.h>
using namespace std;
long long all=63;
string d[63][3];
int debug=0;
int programs() {
	int t;
	cout<<"输入序号"<<endl<<"0.返回"<<endl;
	while (cin>>t) {
		if (t==0) {
			return 0;
		}
		cout<<"输入序号"<<endl<<"0.返回"<<endl;
	}
	return 0;
}
int settings() {
	int t;
	cout<<"输入序号"<<endl<<"0.返回 1.切换主题"<<endl;
	while (cin>>t) {
		if (t==1) {
			cout<<"警告:切换主题会清除屏幕"<<endl;
			cout<<"选择主题"<<endl<<"1.黑 2.白 3.绿 4.蓝 5.灰 6.自定义(实验性)";
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
				cout<<"请输入1或2个十六进制数字"<<endl;
				cout<<"颜色属性由两个十六进制数字指定 -- 第一个对应于背景，第二个对应于前景。每个数字可以为以下任何值:"<<endl;
				cout<<"    0 = 黑色       8 = 灰色"<<endl;
				cout<<"    1 = 蓝色       9 = 淡蓝色"<<endl;
				cout<<"    2 = 绿色       A = 淡绿色"<<endl;
				cout<<"    3 = 浅绿色     B = 淡浅绿色"<<endl;
				cout<<"    4 = 红色       C = 淡红色"<<endl;
				cout<<"    5 = 紫色       D = 淡紫色"<<endl;
				cout<<"    6 = 黄色       E = 淡黄色"<<endl;
				cout<<"    7 = 白色       F = 亮白色"<<endl;
				string a;
				cin>>a;
				a="color "+a;
				system(a.c_str());
			}
			system("cls");
			cout<<"成功"<<endl;
		} else if (t==0) {
			return 0;
		}
		cout<<"输入序号"<<endl<<"0.返回 1.切换主题"<<endl;
	}
	return 0;
}
int dir() {
	if (debug==1) {
		cout<<endl<<"位置"<<" "<<"名称"<<" "<<"内容"<<endl;
		for (int i=0; i<=all; i++) {
			cout<<i<<" "<<d[i][1]<<" "<<d[i][2]<<endl;
		}
	} else {
		for (int i=0; i<=all; i++) {
			if (d[i][0]=="1") {
				cout<<d[i][1]<<endl;
			}
		}
	}
	return 0;
}
int poen(string t) {
	int q=0;
	for (int i=0; i<=all; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			cout<<"打开成功"<<endl<<d[i][2]<<endl;
			q=1;
			break;
		}
	}
	if (q==0) {
		cout<<"打开失败"<<endl;
		return 1;
	}
	return 0;
}
int findd(string t) {
	int q=0;
	for (int i=0; i<=all; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			q=1;
			return 0;
			break;
		}
	}
	if (q==0) {
		return 1;
	}
	return 0;
}
int newe(string t) {
	if (findd(t)==0) {
		cout<<"失败:文件名重复"<<endl;
	} else {
		int q=0;
		for (int i=0; i<=all; i++) {
			if (d[i][0]=="0") {
				d[i][0]="1";
				d[i][1]=t;
				q=1;
				cout<<"创建成功"<<endl;
				break;
			}
		}
		if (q==0) {
			cout<<"创建失败"<<endl;
			return 1;
		}
	}
	return 0;
}
int rename(string t,string tt) {
	if (findd(tt)==0) {
		cout<<"失败:文件名重复"<<endl;
	} else {
		int q=0;
		for (int i=0; i<=all; i++) {
			if (d[i][0]=="1"&&d[i][1]==t) {
				d[i][1]==tt;
				q=1;
				cout<<"重命名成功"<<endl;
				break;
			}
		}
		if (q==0) {
			cout<<"重命名失败"<<endl;
			return 1;
		}
	}
	return 0;
}
int edit(string t) {
	for (int i=0; i<=all; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			cout<<"正在编辑"<<endl;
			cin>>d[i][2];
			cout<<"已保存"<<endl;
			break;
		}
	}
	return 0;
}
int del(string t) {
	int q=0;
	for (int i=0; i<=all; i++) {
		if (d[i][0]=="1"&&d[i][1]==t) {
			d[i][0]="0";
			d[i][1]="";
			d[i][2]="";
			q=1;
			cout<<"删除成功"<<endl;
			break;
		}
	}
	if (q==0) {
		cout<<"删除失败"<<endl;
		return 1;
	}
	return 0;
}
int help() {
	cout<<"提示：输入文件名可快速打开"<<endl;
	cout<<"提示：可以输入首字母执行命令"<<endl;
	cout<<endl;
	cout<<"\033[4mp\033[0mrograms\t\t\t\t打开程序列表。"<<endl;
	cout<<"\033[4ms\033[0mettings\t\t\t\t打开设置。"<<endl;
	cout<<"\033[4mh\033[0melp\t\t\t\t\t提供命令的帮助信息。"<<endl;
	cout<<"cmd\t\t\t\t\t接入命令提示符。"<<endl;
	cout<<"cls\t\t\t\t\t清除屏幕。"<<endl;
	cout<<endl;
	cout<<"\033[4md\033[0mir\t\t\t\t\t显示所有文件。"<<endl;
	cout<<"\033[4mo\033[0mpen <文件名>\t\t\t\t打开文件。"<<endl;
	cout<<"\033[4mn\033[0mew <文件名>\t\t\t\t新建文件。"<<endl;
	cout<<"\033[4me\033[0mdit <文件名>\t\t\t\t编辑文件。"<<endl;
	cout<<"\033[4mr\033[0mename <文件名> <新文件名>\t\t重命名文件。"<<endl;
	cout<<"del <文件名>\t\t\t\t删除文件。"<<endl;
	return 0;
}
int main() {
	printf("\rLaoding");
	for (int i=0; i<=all; i++) {
		if (i<=2) {
			d[i][0]="1";
		} else {
			d[i][0]="0";
		}
	}
	d[0][1]="欢迎";
	d[0][2]="欢迎使用本系统！本系统致力于为您提供高效、稳定的非图形化操作体验，助力工作更便捷。感谢您的选择与信任！";
	d[1][1]="入门";
	d[1][2]="*你入门了*";
	d[2][1]="教程";
	d[2][2]="*请自己输一下help来获得教程*";
	Sleep(500);
	cout<<"\r"<<"欢迎使用本系统"<<endl;
	cout<<"输入 \033[4mh\033[0melp 或 h 来取得帮助(区分大小写)"<<endl;
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
		} else if (s=="debug") {
			debug=1;
		} 
		} else {
			int q=poen(s);
			if (q==1) {
				cout<<"'"<<s<<"' 不是内部或外部命令，也不是可运行的程序或批处理文件。";
			}
		}
		cout<<endl<<"A:/>";
	}
	return 0;
}
