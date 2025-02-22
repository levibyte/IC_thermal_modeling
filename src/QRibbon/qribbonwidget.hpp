#ifndef Q_RIBBON_WIDGET_H
#define Q_RIBBON_WIDGET_H

#include "qribbon_lib.hpp"

#include <QWidget>
#include <QVector>

class QRibbonGroup;
class QHBoxLayout;

//	@class QRibbonWidget
//	represents the widget in the one tab
class QRIBBON_EXPORT QRibbonWidget : public QWidget
{
	Q_OBJECT

public:
	//	Constructor
	explicit QRibbonWidget(QWidget* = 0);

	//	Destructor
	virtual ~QRibbonWidget();

public:

	//	@brief Adds group
	void addGroup(QRibbonGroup*);

	// @brief Returns group count
	int count() const;

	// @brief Removes group with given index
	void removeGroup(int);

	// @brief Inserts group with the given index
	void insertGroup(int, QRibbonGroup*);

	void addStretch(int);

private:
	QVector<QRibbonGroup*> m_groups;
	QHBoxLayout* m_groupLayout;
};

#endif