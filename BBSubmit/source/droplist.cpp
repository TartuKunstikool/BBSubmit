#include "droplist.h"

#include <QDragEnterEvent>
#include <QTableWidgetItem>
#include <QMouseEvent>
#include <QMimeData>

DropList::DropList(QWidget *parent)
    : QTableWidget(parent)
{
    setMinimumSize(200, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setAcceptDrops(true);
    setAutoFillBackground(true);
    setColumnCount(4);
    setColumnWidth(0, 300);
    clear();
}


void DropList::dragEnterEvent(QDragEnterEvent *event)
{

    setBackgroundRole(QPalette::Highlight);

    event->acceptProposedAction();
    emit changed(event->mimeData());
}


void DropList::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


void DropList::dropEvent(QDropEvent *event)
{
    const QMimeData *mimeData = event->mimeData();

    if (mimeData -> hasText())
    {
        emit fileDropped(mimeData->text());
    }

    setBackgroundRole(QPalette::Dark);
    event->acceptProposedAction();
}


void DropList::dragLeaveEvent(QDragLeaveEvent *event)
{
    clear();
    event->accept();
}


void DropList::clear()
{
    while (rowCount() > 0)
    {
        removeRow(0);
    }
    emit changed();
}

