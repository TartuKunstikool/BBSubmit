#include "droplist.h"

#include <QDragEnterEvent>
#include <QTableWidgetItem>
#include <QMouseEvent>
#include <QMimeData>

/*!
 * \brief New DropList instance.
 *
 * DropList contains scene/project files that will be rendered. Accepts drag&drop of multiple files.
 */
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

/*!
 * \brief Mouse drag&drop enter event.
 *
 * Emits changed event with mimeData from dragged object.
 * \param event
 */
void DropList::dragEnterEvent(QDragEnterEvent *event)
{

    setBackgroundRole(QPalette::Highlight);

    event->acceptProposedAction();
    emit changed(event->mimeData());
}

/*!
 * \brief Mouse drag&drop move event.
 *
 * Does nothing special at the moment.
 * \param event
 */
void DropList::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


/*!
 * \brief Mouse drop event.
 *
 * Processes mimeData of dropped files and emits fileDropped event.
 * \param event
 */
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


/*!
 * \brief Mouse drag&drop leave event.
 *
 * Does nothing special.
 * \param event
 */
void DropList::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}


/*!
 * \brief Clear list.
 */
void DropList::clear()
{
    while (rowCount() > 0)
    {
        removeRow(0);
    }
    emit changed();
}

