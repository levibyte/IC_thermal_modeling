#include "application_ribbon_gui.hpp"

#include "icons.hpp"

// qt Ribbon 
#include <qribbon.hpp>
#include <qribbongroup.hpp>
#include <qribbonwidget.hpp>
#include <qribbonbutton.hpp>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QLayout>
#include <QSignalMapper>
#include <QLabel>
#include <QComboBox>
#include <QFileDialog>

const QSize globalSize(22, 22);
const QStringList Shapes {"Line", "Rectangle", "Ellipse", "Polygon"};

///////////////////////////////////////////////////////////////////////////////
//
// implementation create_shape_gui
//
ApplicationRibbonGui::ApplicationRibbonGui(QWidget* p)
	: QWidget(p)
{
	m_dialog = new QFileDialog(this);
	m_dialog->setFileMode(QFileDialog::AnyFile);
	m_dialog->setVisible(false);

	QRibbonWidget* ribbonWidget = new QRibbonWidget(this);
	buildHomePage(ribbonWidget);

	QRibbon* ribbon = new QRibbon(this);
	ribbon->addTab(ribbonWidget, "Home");

	QRibbonWidget* ribbonWidgetTemp = new QRibbonWidget(this);
	ribbon->addTab(ribbonWidgetTemp, "Other");

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(ribbon);

	layout->setSpacing(0);
	layout->setMargin(0);

	setLayout(layout);
}

void ApplicationRibbonGui::buildHomePage(QRibbonWidget* ribbonWidget)
{
	QRibbonGroup* group = new QRibbonGroup(this);
	group->setTitle("Design");

	QRibbonButton* open = new QRibbonButton(this, "Open", getIconDir() + "open.svg");
	connect(open, SIGNAL(clicked()), this, SLOT(openFileDialog()));
	QRibbonButton* calculate = new QRibbonButton(this, "Calculate", getIconDir() + "calculate.svg");
	connect(calculate, SIGNAL(clicked()), this, SIGNAL(calculate()));
	QRibbonButton* clear = new QRibbonButton(this, "Clear", getIconDir() + "close.svg");
	connect(clear, SIGNAL(clicked()), this, SIGNAL(clear()));
	group->addRibbonButton(open);
	group->addRibbonButton(calculate);
	group->addRibbonButton(clear);
	ribbonWidget->addGroup(group);
}

void ApplicationRibbonGui::openFileDialog()
{
	m_dialog->setVisible(true);
	if (m_dialog->exec())
	{
		QStringList selectedFiles = m_dialog->selectedFiles();
		emit openFile(selectedFiles[0]);
	}
}


