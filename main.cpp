#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <iostream>
#include <QGridLayout>
#include <QLinearGradient>
#include <QPalette>
#include <QtGui>
using namespace std;
QGridLayout* layout = new QGridLayout;
class Window : public QWidget
{

	public:
	//QGridLayout* layout = new QGridLayout;
	Window(QWidget* parent = nullptr) : QWidget(parent)
	{

		for(int i = 0; i < 8; ++i)
		{
			for(int j = 0; j < 8; ++j)
			{

				if(i == 0 && j == 4)
				{
					button = new QPushButton(" rn", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : black; font : bold 15px; color : white;");
				}
				else if(i == 2 && j == 3)
				{
					button = new QPushButton("cn", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : white; font : bold 15px; color : white;");
				}
				else if(i == 3 && j == 3)
				{
					button = new QPushButton("fn", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : black; font : bold 15px; color : white;");
				}
				else if(i == 7 && j == 2)
				{
					button = new QPushButton("rb", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : white; font : bold 15px; color : white;");
				}
				else if(i == 6 && j == 6)
				{
					button = new QPushButton("fb", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : black; font : bold 15px; color : white;");
				}
				else if(i == 5 && j == 4)
				{
					button = new QPushButton("cb", this);
					button->move(100 * i, j * 100);
					const QSize button_size = QSize(100, 100);
					button->resize(button_size);
					button->setStyleSheet("background : white; font : bold 15px; color : white;");
				}
				else if((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
				{
					button = new QPushButton("", this);
					button->move(100 * i, j * 100);
					const QSize BUTTON_SIZE = QSize(100, 100);
					button->resize(BUTTON_SIZE);
					button->setStyleSheet("background : black; font : bold 15px; color : white;");
					connect(button, &QPushButton::clicked,this,&Window::ButtonCL);
				}


				else
				{
					button = new QPushButton("", this);
					button->move(100 * i, j * 100);
					const QSize BUTTON_SIZE = QSize(100, 100);
					button->resize(BUTTON_SIZE);
					button->setStyleSheet("background : white; font : bold 15px; color : white;");

				}


			}

			//connect(button, &QPushButton::clicked, this, &Window::buttonpressed);
		}
	}
	void ButtonCL(int x, int y)
	{
		cout<<"button clicked : "<<x,y<<'\n';
	}
	//void EnterPressed()
	//{
	//	QMessageBox msg;
	//	msg.setText(name_edit->text());
	//	msg.exec();

	//}

	//void buttonpressed()
	//{
	//	cout<<("hellooo ");
	//}

	private:
	//QLabel* name;
	QPushButton* button;
};


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Window window;
	window.show();
	return app.exec();
}