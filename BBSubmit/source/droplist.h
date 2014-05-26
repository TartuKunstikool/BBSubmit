#ifndef DROPLIST_H
#define DROPLIST_H

#include <QTableWidget>

QT_BEGIN_NAMESPACE
class QMimeData;
QT_END_NAMESPACE

class DropList : public QTableWidget
{
    Q_OBJECT

public:
    DropList(QWidget *parent = 0);

signals:
    void changed(const QMimeData *mimeData = 0);
    void fileDropped(const QString filePath = "");

public slots:
    void clear();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);

private:

};

#endif // DROPLIST_H
