#include "dock_guider.h"
#include <QtGui>



#define ICON_SIZE 30

namespace
{
    class DrawDatas
    {
    private:
        DrawDatas()
        {
            QPixmap pixmap(":/resources/images/guiders.png");
            mGuider = pixmap.copy(30, 30, 30, 30);
            lGuiders[0] = pixmap.copy(0, 30, 30, 30);
            lGuiders[1] = pixmap.copy(0, 0, 30, 30);
            tGuiders[0] = pixmap.copy(30, 0, 30, 30);
            tGuiders[1] = pixmap.copy(60, 0, 30, 30);
            rGuiders[0] = pixmap.copy(60, 30, 30, 30);
            rGuiders[1] = pixmap.copy(60, 60, 30, 30);
            bGuiders[0] = pixmap.copy(30, 60, 30, 30);
            bGuiders[1] = pixmap.copy(0, 60, 30, 30);
            edges[0].resize(17);
            edges[0].setPoint(0, 41, 84);
            edges[0].setPoint(1, 77, 84);
            edges[0].setPoint(2, 84, 77);
            edges[0].setPoint(3, 84, 41);
            edges[0].setPoint(4, 126, 41);
            edges[0].setPoint(5, 126, 77);
            edges[0].setPoint(6, 133, 84);
            edges[0].setPoint(7, 168, 84);
            edges[0].setPoint(8, 168, 126);
            edges[0].setPoint(9, 133, 126);
            edges[0].setPoint(10, 126, 133);
            edges[0].setPoint(11, 126, 167);
            edges[0].setPoint(12, 84, 167);
            edges[0].setPoint(13, 84, 133);
            edges[0].setPoint(14, 77, 126);
            edges[0].setPoint(15, 41, 126);
            edges[0].setPoint(16, 41, 84);
            guidersBoundingRect[0] = edges[0].boundingRect();
            edges[1].resize(17);
            edges[1].setPoint(0, 0, 84);
            edges[1].setPoint(1, 77, 84);
            edges[1].setPoint(2, 84, 77);
            edges[1].setPoint(3, 84, 0);
            edges[1].setPoint(4, 126, 0);
            edges[1].setPoint(5, 126, 77);
            edges[1].setPoint(6, 133, 84);
            edges[1].setPoint(7, 210, 84);
            edges[1].setPoint(8, 210, 126);
            edges[1].setPoint(9, 133, 126);
            edges[1].setPoint(10, 126, 133);
            edges[1].setPoint(11, 126, 210);
            edges[1].setPoint(12, 84, 210);
            edges[1].setPoint(13, 84, 133);
            edges[1].setPoint(14, 77, 126);
            edges[1].setPoint(15, 0, 126);
            edges[1].setPoint(16, 0, 84);
            guidersBoundingRect[1] = edges[1].boundingRect();
        }

    public:
        static const DrawDatas& drawData() { static DrawDatas icons; return icons; }

    public:
        QPixmap lGuiders[2];
        QPixmap tGuiders[2];
        QPixmap rGuiders[2];
        QPixmap bGuiders[2];
        QPixmap mGuider; //中心图标
        QPolygon edges[2]; //中心边
		QRect guidersBoundingRect[2];
    };
}

DockUI::DockGuider::DockGuider(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
	, m_drawButtons(GuiderButton::AllButtons)
	, m_drawMode(GuiderMode::NoGuider)
	, m_hoverButton(GuiderButton::NoButton)
{
	setMouseTracking(true);
}

DockUI::DockGuider::~DockGuider()
{
}

void DockUI::DockGuider::setDrawMode(GuiderMode val)
{
	m_drawMode = val;

	updateButtonRects();

	update();
}

void DockUI::DockGuider::paintEvent(QPaintEvent*)
{
    if (drawMode() == GuiderMode::NoGuider)
    {
        return;
    }

	//
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	
	//
	QPoint drawPoint(width() / 2 - DrawDatas::drawData().guidersBoundingRect[1].width() / 2,
		height() / 2 - DrawDatas::drawData().guidersBoundingRect[1].height() / 2);
	painter.save();
	painter.setBrush(QBrush(QColor("#FFFFFF")));
	painter.setOpacity(0.75);
	painter.translate(drawPoint);
	//绘制中区域的边
	if (drawMode() == GuiderMode::CenterFullGuider)
	{
		painter.drawPolygon(DrawDatas::drawData().edges[1]);
	}
	else if (drawMode() == GuiderMode::CenterSimpleGuider)
	{
		painter.drawPolygon(DrawDatas::drawData().edges[0]);
	}
	painter.restore();

	QColor background(0, 122, 204, 120);

	if (drawButtons().testFlag(GuiderButton::MainLeftButton))
	{
		if (m_hoverButton == GuiderButton::MainLeftButton) {
			painter.fillRect(m_buttonRect[GuiderButton::MainLeftButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::MainLeftButton], DrawDatas::drawData().lGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::CenterButton))
	{
		if (m_hoverButton == GuiderButton::CenterButton) {
			painter.fillRect(m_buttonRect[GuiderButton::CenterButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::CenterButton], DrawDatas::drawData().mGuider);
	}
	if (drawButtons().testFlag(GuiderButton::MainBottomButton))
	{
		if (m_hoverButton == GuiderButton::MainBottomButton) {
			painter.fillRect(m_buttonRect[GuiderButton::MainBottomButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::MainBottomButton], DrawDatas::drawData().bGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::MainRightButton))
	{
		if (m_hoverButton == GuiderButton::MainRightButton) {
			painter.fillRect(m_buttonRect[GuiderButton::MainRightButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::MainRightButton], DrawDatas::drawData().rGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::MainTopButton))
	{
		if (m_hoverButton == GuiderButton::MainTopButton) {
			painter.fillRect(m_buttonRect[GuiderButton::MainTopButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::MainTopButton], DrawDatas::drawData().tGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::BottomButton))
	{
		if (m_hoverButton == GuiderButton::BottomButton) {
			painter.fillRect(m_buttonRect[GuiderButton::BottomButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::BottomButton], DrawDatas::drawData().bGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::LeftButton))
	{
		if (m_hoverButton == GuiderButton::LeftButton) {
			painter.fillRect(m_buttonRect[GuiderButton::LeftButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::LeftButton], DrawDatas::drawData().lGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::RightButton))
	{
		if (m_hoverButton == GuiderButton::RightButton) {
			painter.fillRect(m_buttonRect[GuiderButton::RightButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::RightButton], DrawDatas::drawData().rGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::TopButton))
	{
		if (m_hoverButton == GuiderButton::TopButton) {
			painter.fillRect(m_buttonRect[GuiderButton::TopButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::TopButton], DrawDatas::drawData().tGuiders[1]);
	}
	if (drawButtons().testFlag(GuiderButton::SplitTopButton))
	{
		if (m_hoverButton == GuiderButton::SplitTopButton) {
			painter.fillRect(m_buttonRect[GuiderButton::SplitTopButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::SplitTopButton], DrawDatas::drawData().tGuiders[0]);
	}
	if (drawButtons().testFlag(GuiderButton::SplitLeftButton))
	{
		if (m_hoverButton == GuiderButton::SplitLeftButton) {
			painter.fillRect(m_buttonRect[GuiderButton::SplitLeftButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::SplitLeftButton], DrawDatas::drawData().lGuiders[0]);
	}
	if (drawButtons().testFlag(GuiderButton::SplitRightButton))
	{
		if (m_hoverButton == GuiderButton::SplitRightButton) {
			painter.fillRect(m_buttonRect[GuiderButton::SplitRightButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::SplitRightButton], DrawDatas::drawData().rGuiders[0]);
	}
	if (drawButtons().testFlag(GuiderButton::SplitBottomButton))
	{
		if (m_hoverButton == GuiderButton::SplitBottomButton) {
			painter.fillRect(m_buttonRect[GuiderButton::SplitBottomButton], background);
		}
		painter.drawPixmap(m_buttonRect[GuiderButton::SplitBottomButton], DrawDatas::drawData().bGuiders[0]);
	}
}

void DockUI::DockGuider::resizeEvent(QResizeEvent *event)
{
	updateButtonRects();
	update();
}


void DockUI::DockGuider::mouseMoveEvent(QMouseEvent *event)
{
	ButtonRects::const_iterator rectItor = m_buttonRect.begin();
	for (rectItor; m_buttonRect.end() != rectItor; rectItor++)
	{
		//qDebug() << rectItor.value() << " " << event->pos();
		if (rectItor.value().contains(event->pos()))
		{
			m_hoverButton = rectItor.key();
			update();
			return;
		}
	}

	m_hoverButton = GuiderButton::NoButton;
	update();
}

void DockUI::DockGuider::updateButtonRects()
{
	const int w = width();
	const int h = height();
	const static int kOffset = 86;

	m_buttonRect[GuiderButton::MainLeftButton] = QRect(0, height() / 2 - ICON_SIZE / 2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::MainRightButton] = QRect(width() - ICON_SIZE, height() / 2 - ICON_SIZE / 2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::MainTopButton] = QRect(width()/2-ICON_SIZE/2, 0, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::MainBottomButton] = QRect(width() / 2 - ICON_SIZE / 2, height() - ICON_SIZE, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::LeftButton] = QRect(width() / 2 - ICON_SIZE / 2 - kOffset, height()/2-ICON_SIZE/2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::RightButton] = QRect(width() / 2 - ICON_SIZE / 2 + kOffset, height() / 2 - ICON_SIZE / 2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::TopButton] = QRect(width()/2 - ICON_SIZE / 2, height()/2 - ICON_SIZE / 2 - kOffset, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::BottomButton] = QRect(width() / 2 - ICON_SIZE/2, height() / 2 - ICON_SIZE / 2 + kOffset, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::SplitLeftButton] = QRect(width() / 2 - ICON_SIZE / 2 - kOffset/2, height() / 2 - ICON_SIZE / 2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::SplitTopButton] = QRect(width() / 2 - ICON_SIZE / 2, height() / 2 - ICON_SIZE / 2 - kOffset/2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::SplitRightButton] = QRect(width() / 2 - ICON_SIZE / 2 + kOffset/2, height() / 2  - ICON_SIZE / 2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::SplitBottomButton] = QRect(width() / 2 - ICON_SIZE / 2, height() / 2 - ICON_SIZE / 2 + kOffset/2, ICON_SIZE, ICON_SIZE);
	m_buttonRect[GuiderButton::CenterButton] = QRect(w/2-ICON_SIZE/2, h / 2 - ICON_SIZE/2, ICON_SIZE, ICON_SIZE);
}

void DockUI::DockGuider::setDrawButtons(GuiderButtons val)
{
	m_drawButtons = val;

	update();
}

void DockUI::DockGuider::setButtonVisible(GuiderButton button, bool visible)
{
	m_drawButtons.setFlag(button, visible);
}

