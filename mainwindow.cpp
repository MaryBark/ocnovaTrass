#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : MarbleWidget(parent)
    , ui(new Ui::MainWindow)
{
//    ui->setupUi(this);

    coord = MapMarbleTrassa::buildingRouteKA();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::customPaint(GeoPainter *painter)
{
    GeoDataCoordinates Kavkaz(43.113234, 45.0156, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(Kavkaz, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    QFont font("times", 13);
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(Kavkaz, QString("Kavkaz"));

    GeoDataCoordinates Yamal(68.18674, 70.4245745, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(Yamal, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(Yamal, QString("Yamal"));

    GeoDataCoordinates Ural(70.70457, 59.5934674, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(Ural, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(Ural, QString("Ural"));

    GeoDataCoordinates zab(111.8854, 54.074674, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(zab, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(zab, QString("Zabaikalie"));

    GeoDataCoordinates Altai(89.08854, 51.5274, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(Altai, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(Altai, QString("Altai"));

    GeoDataCoordinates BCpr(98.358854, 73.53464, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(BCpr, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(BCpr, QString("Vost_Sib_Polar"));

    GeoDataCoordinates Vost(138.268854, 66.43744, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(Vost, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(Vost, QString("Vostoch_Sibir"));

    GeoDataCoordinates daln(143.548854, 72.0243744, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(daln, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(daln, QString("Dalnevostochniy"));

    GeoDataCoordinates chuk(177.558854, 67.42744, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(chuk, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(chuk, QString("Chukotka"));

    GeoDataCoordinates kam(158.438854, 54.49744, 0.0, GeoDataCoordinates::Degree  );
    //painter->setPen(Qt::red);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 0, 0)), 5.0, Qt::SolidLine,Qt::RoundCap ));
    painter->drawEllipse(kam, 7,7);
    painter->setPen(QPen(QBrush(QColor::fromRgb(255, 255, 255)), 1.5, Qt::SolidLine,Qt::RoundCap ));
    painter->drawText(kam, QString("Kamchatka"));


    // отрисовка трассы
    painter->setPen( Qt::red );


    GeoDataLineString shapeLatitudeCircle(RespectLatitudeCircle | Tessellate);
    for(int k = 0; k < coord.size(); k++)
    {
//        shapeLatitudeCircle.clear();
//        for(int i = 0; i < vecSchir[0].count(); i++)
//        {
            //GeoDataCoordinates trass( dol1[i], schir1[i], 0.0, GeoDataCoordinates::Degree );
            GeoDataCoordinates trass( coord[k].b, coord[k].l, 0.0, GeoDataCoordinates::Degree );
            //painter->drawLine(trass);
            shapeLatitudeCircle << trass;
            //painter->drawPolyline(GeoDataLineString() << trass);
//        }

        painter->drawPolyline(shapeLatitudeCircle);
    }

}

void MainWindow::trass()
{

}

