#include "optionlist.h"

/*!
 * \brief New OptionList instance. Key-value pairs of command line arguments.
 */
OptionList::OptionList(QWidget *parent) :
    QTableWidget(parent)
{
    setMaximumWidth(180);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAutoFillBackground(true);
    setColumnCount(2);
    setColumnWidth(0, 80);
    setColumnWidth(1, 80);

    clear();
}


/*!
 * \brief Clear table
 */
void OptionList::clear()
{
    while (rowCount() > 0)
    {
       removeRow(0);
    }
}
