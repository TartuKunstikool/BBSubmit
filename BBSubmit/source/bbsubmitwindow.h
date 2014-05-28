
#ifndef DROPSITEWINDOW_H
#define DROPSITEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QMimeData;
class QPushButton;
class QTableWidget;
class QGroupBox;
class QTableWidgetItem;
QT_END_NAMESPACE
class OptionList;


/*!
 * \brief Main GUI.
 *
 * Contains table of files to be submitted and table of attributes for each file.
 */
class BBSubmitWindow : public QWidget
{
    Q_OBJECT

public:
    BBSubmitWindow();
    void appendToFileList(int row, QString filePath);
    void clearFileList();
    QStringList createTasks(QString framerange, int numTasks);
    QString createCommand(int file);
    void submitCommand(QString command);

public slots:
    void updateFilesTable(const QString filePath);
    void updateOptionsTable(QTableWidgetItem* item);

private:
    QLabel *abstractLabel;
    QGroupBox *horizontalGroupBox;
    QTableWidget *filesTable;
    OptionList *optionsTable;

    QPushButton *clearButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;

    QList<QStringList> fileList;
    QList<QHash<QString, QString> > *fileHash;

};

#endif // DROPSITEWINDOW_H
