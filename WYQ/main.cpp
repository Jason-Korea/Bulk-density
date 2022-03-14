#include "WYQ.h"
#include <QtWidgets/QApplication>
#include <QtDataVisualization>
#include <qmessagebox.h>
#include "SphereProducer.h"

using namespace QtDataVisualization;

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

    //����һ����ά����ϵ
    Q3DScatter* graph = new Q3DScatter();
    graph->setFlags(graph->flags() ^ Qt::FramelessWindowHint);
    //���������λ��
    graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetBehindLow);
    //������Ӱ��ʾ
    graph->setShadowQuality(QAbstract3DGraph::ShadowQualityNone);
    ////����������ķ�Χ
    graph->axisX()->setRange(0, 50);
    graph->axisY()->setRange(0, 50);
    graph->axisZ()->setRange(0, 50);
    graph->axisX()->segmentCountChanged(100);
    ////���������������
    //graph->axisX()->setSegmentCount(int(480 / 20));
    //graph->axisY()->setSegmentCount(int(480 / 20));
    //graph->axisZ()->setSegmentCount(int(480 / 20));
    //������������ϵ������
    graph->activeTheme()->setType(Q3DTheme::ThemeQt);
    graph->resize(800, 800);


    //graph->axisX()->setLabelFormat("X");
    //graph->axisY()->setLabelFormat("Y");
    //graph->axisZ()->setLabelFormat("Z");

    //��
    QScatter3DSeries* series = new QScatter3DSeries;
    //�㣬��С
    series->setItemSize(500);
    //�㣬����
    QScatterDataArray data;

    //�ж��Ƿ�graph(opengl)��ʼ��
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
