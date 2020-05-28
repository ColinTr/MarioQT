#include "leveleditorview.h"

#include "leveleditorengine.h"

void LevelEditorView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        levelEditorEngine->setMouseState(LEFTCLICKPRESSED);
    }
    if (event->button() == Qt::RightButton) {
        levelEditorEngine->setMouseState(RIGHTCLICKPRESSED);
    }
}

void LevelEditorView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton) {
        levelEditorEngine->setMouseState(NOTPRESSED);
    }
}

LevelEditorView::LevelEditorView()
{
    showLevelGrid = false;
    windowSize = QSize(1280,720);
    levelSize = QSize(2*windowSize.width(),windowSize.height());
    resize(windowSize);
    backgroundColor = QColor(100,175,255);
    palette.setColor(QPalette::Background, backgroundColor);
    setAutoFillBackground(true);
    setPalette(palette);
}

void LevelEditorView::paintEvent(QPaintEvent *event)
{
    if(showLevelGrid){
        QPainter painter(this);
        painter.setPen(QColor(0,0,0));

        int block_size = 32;

        for(int i=0; i < windowSize.width(); i += block_size){
            painter.drawLine(i,0,i,windowSize.height());
        }

        for(int i=0; i < windowSize.height (); i += block_size){
            painter.drawLine(0,i,windowSize.width(),i);
        }
    }

    GraphicVisitor graphicVisitor(this); // possède un QPainter
    levelEditorEngine->update(graphicVisitor);
    graphicVisitor.paint();

    cameraPosition = graphicVisitor.getPosition();
}
