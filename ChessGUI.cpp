#include <QApplication>
#include <QPushButton>
#include <QtGui>
#include<Qwidget>
//int main(int argc, char* argv[])
//{
//    QApplication app(argc, argv);
//
//    QPushButton hello("Hello world!");
//
//    hello.show();
//    return app.exec();
//    
//}



class MyWidget : public QWidget
{
    public:
    MyWidget();

    protected:
    void paintEvent(QPaintEvent*);
};

MyWidget::MyWidget()
{
    QPalette palette(MyWidget::palette());
    palette.setColor(backgroundRole(), Qt::darkGray);
    setPalette(palette);
}

void MyWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::darkGreen);
    painter.drawRect(2, 8, 6, 4);

    painter.setPen(Qt::darkGray);
    painter.drawLine(2, 8, 6, 2);
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MyWidget widget;
    widget.show();
    return app.exec();
}
