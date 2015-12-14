#include <QApplication>
#include <QFrame>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QDial>



int main( int argc, char ** argv)
{
  // Creem tots els components
  QApplication app(argc, argv);
  QFrame *w=new QFrame();
  QVBoxLayout *mainLayout=new QVBoxLayout(w);          //layout vertical, principal!
  QLabel *label_hour = new QLabel("Hours");            //etiqueta horas
  QLabel *label_minutes = new QLabel("Minutes");       //etiqueta minutas
  QHBoxLayout *layHoriz  = new QHBoxLayout();          //Layout Horizontal labels
  QLCDNumber *lcd_hour = new QLCDNumber();             //LCDNumber
  QLCDNumber *lcd_minutes = new QLCDNumber();          //LCDNumber
  QHBoxLayout *layHoriz2  = new QHBoxLayout();         //Layout Horizontal lcd
  QDial *dial_hour = new QDial();                      //DIAL
  QDial *dial_minutes = new QDial();                   //Dial
  QHBoxLayout *layHoriz3  = new QHBoxLayout();         //Layout Horizontal dial
  QPushButton *quitButton = new QPushButton("&Exit", w); //l'and estableix una crida ràpida fent alt+q a la funcionalitat del botó
  QHBoxLayout *qButtonLayout = new QHBoxLayout();

  //insertem els labels
  layHoriz->addWidget(label_hour);
  layHoriz->addWidget(label_minutes);

  //insertem els lcd
  layHoriz2->addWidget(lcd_hour);
  layHoriz2->addWidget(lcd_minutes);

  //insertem els dials
  layHoriz3->addWidget(dial_hour);
  layHoriz3->addWidget(dial_minutes);

  //insertem botó tancar
  qButtonLayout->addItem(new QSpacerItem(30,10,QSizePolicy::Expanding,QSizePolicy::Minimum));
  qButtonLayout->addWidget(quitButton);

  //afegim tot al layout principal
  mainLayout->addLayout(layHoriz);
  mainLayout->addLayout(layHoriz2);
  mainLayout->addLayout(layHoriz3);
  mainLayout->addLayout(qButtonLayout);

  //Establim signals i comportament
  app.connect(quitButton, SIGNAL(clicked()), w, SLOT(close()));
  app.connect(dial_hour,SIGNAL(dialMoved(const int&)),lcd_hour,SLOT (display(const int&)));
  app.connect(dial_minutes,SIGNAL(dialMoved(const int&)),lcd_minutes,SLOT (display(const int&)));

  w->show();
  return app.exec();
}
