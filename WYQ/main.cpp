#include "WYQ.h"
#include <QtWidgets/QApplication>
#include <QtDataVisualization>
#include <qmessagebox.h>
#include "SphereProducer.h"

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    //创建一个三维坐标系
    Q3DScatter* graph = new Q3DScatter();
    graph->setFlags(graph->flags() ^ Qt::FramelessWindowHint);
    //设置相机的位置
    graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetBehindLow);
    //设置阴影显示
    graph->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    ////设置坐标轴的范围
    graph->axisX()->setRange(0, 50);
    graph->axisY()->setRange(0, 50);
    graph->axisZ()->setRange(0, 50);
    graph->axisX()->segmentCountChanged(100);
    ////设置坐标轴的数量
    //graph->axisX()->setSegmentCount(int(480 / 20));
    //graph->axisY()->setSegmentCount(int(480 / 20));
    //graph->axisZ()->setSegmentCount(int(480 / 20));
    //设置整体坐标系的主题
    graph->activeTheme()->setType(Q3DTheme::ThemeQt);
    graph->resize(800, 800);


    //graph->axisX()->setLabelFormat("X");
    //graph->axisY()->setLabelFormat("Y");
    //graph->axisZ()->setLabelFormat("Z");

    //点
    QScatter3DSeries* series = new QScatter3DSeries;
    //点，大小
    series->setItemSize(500);
    //点，坐标
    QScatterDataArray data;

    //判断是否graph(opengl)初始化
    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();
    }

    SphereProducer producer;
    bool b = producer.produce();
    if (b)
    {
        for (auto p : producer.centers)
        {
            data.append(QVector3D(p[0], 0, p[1]));
        }
    }

    series->dataProxy()->addItems(data);
    graph->addSeries(series);
    graph->show();

	return app.exec();
}
