#include <QtWidgets>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QWidget wgt;
   wgt.setWindowTitle("Hello world");
 
   wgt.show();
   return app.exec();
}

