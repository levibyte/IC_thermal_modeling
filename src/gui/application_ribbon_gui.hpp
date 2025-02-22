#ifndef APPLICATION_RIBBON_GUI_HPP 
#define APPLICATION_RIBBON_GUI_HPP

///////////////////////////////////////////////////////////////////////////////
//
// Includes
//
// Qt
class QVBoxLayout;
class QRadioButton;
class QPushButton;
class QFileDialog;

#include <QWidget>

class QRibbonWidget;

///////////////////////////////////////////////////////////////////////////////
//
// @class ApplicationRibbonGui : Assistant for creating objects 
//
class ApplicationRibbonGui : public QWidget
{
	Q_OBJECT

public:
	ApplicationRibbonGui(QWidget* = 0);

signals:
	void calculate();
	void openFile(const QString&);
	void clear();

private slots:
	void openFileDialog();

private:
	void buildHomePage(QRibbonWidget*);

private:
	QFileDialog* m_dialog;
};

#endif
