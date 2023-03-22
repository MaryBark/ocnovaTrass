#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    ConnectDB::Ptr db = ConnectDB::instance(DRIVER_SQLITE, &a);

//    if(IS_NULL(db))
//    {
//        QMessageBox::critical(nullptr, MBCW_TITLE,
//                              QS("Драйвер БД %1 не найден в системе!")
//                              .arg(DRIVER_SQLITE));

//        return -1;
//    }


    // Create a Marble QWidget without a parent
//        MarbleWidget *mapWidget = new MarbleWidget();

        // Load the OpenStreetMap map
//        mapWidget->setMapThemeId("earth/srtm/srtm.dgml");

    MainWindow *mapWidget = new MainWindow;
       //mapWidget->setMapThemeId("earth/openstreetmap/openstreetmap.dgml");
     //mapWidget->setMapThemeId("earth/plain/plain.dgml");
    mapWidget->setMapThemeId("earth/srtm/srtm.dgml");
    //mapWidget->setMapThemeId("earth/bluemarble/bluemarble.dgml");
    mapWidget->setProjection(Marble::Mercator);

        mapWidget->show();

//    MainWindow w;
//    w.show();
    return a.exec();
}
