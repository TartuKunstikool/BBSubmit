#ifndef OPTIONLIST_H
#define OPTIONLIST_H

#include <QTableWidget>

/*!
 * \brief Table class for command line options table.
 *
 * Inherits QTableWidget.
 */
class OptionList : public QTableWidget
{
    Q_OBJECT

public:
    OptionList(QWidget *parent = 0);

    
signals:
    
public slots:
    void clear();

    
};

#endif // OPTIONLIST_H
