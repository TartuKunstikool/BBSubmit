
#include <QtWidgets>

#include "bbsubmitwindow.h"
#include "droplist.h"
#include "optionlist.h"

/*!
 * \brief Main GUI window.
 *
 * Contains files table and argument lists.
 */
BBSubmitWindow::BBSubmitWindow()
{
    abstractLabel = new QLabel(tr("Drag and drop files for Backburner submission"));
    abstractLabel->setWordWrap(true);
    abstractLabel->adjustSize();

    QStringList labels, optionLabels;
    labels << tr("File Path") << tr("Frame Range") << tr("Subtasks") << tr("Priority");
    optionLabels << tr("Key") << tr("Value");

    filesTable = new DropList;
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setStretchLastSection(true);

    optionsTable = new OptionList;
    optionsTable->setHorizontalHeaderLabels(optionLabels);

    clearButton = new QPushButton(tr("Clear"));
    quitButton = new QPushButton(tr("Submit"));

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(clearButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    connect(quitButton, SIGNAL(pressed()), this, SLOT(close()));
    connect(clearButton, SIGNAL(pressed()), filesTable, SLOT(clear()));
    connect(filesTable, SIGNAL(fileDropped(QString)), this, SLOT(updateFilesTable(QString)));
    connect(filesTable, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(updateOptionsTable(QTableWidgetItem*)));

    horizontalGroupBox = new QGroupBox(tr("File list"));
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(filesTable);
    hLayout->addWidget(optionsTable);
    horizontalGroupBox->setLayout(hLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(abstractLabel);
    mainLayout->addWidget(horizontalGroupBox);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("BBsubmit"));
    setMinimumSize(800, 500);
}


/*!
 * \brief Update table of files.
 *
 * Accepts drag&drop events with multiple files.
 * \param filePath Concatenated paths of dropped files as QString
 */
void BBSubmitWindow::updateFilesTable(const QString filePath)
{
    QStringList fileList;
    fileList = filePath.split("file:///");
    foreach(QString s, fileList)
    {
        if (s.length() > 1 )
        {
            int row = filesTable->rowCount();
            filesTable->insertRow(row);
            filesTable->setItem(row, 0, new QTableWidgetItem(s.simplified()));
            filesTable->setItem(row, 1, new QTableWidgetItem("0-100"));
            filesTable->setItem(row, 2, new QTableWidgetItem("1"));
            filesTable->setItem(row, 3, new QTableWidgetItem("50"));

            appendToFileList(row, s.simplified());
        }
    }
    filesTable->resizeRowsToContents();
    filesTable->setCurrentCell(filesTable->rowCount()-1, 0);
    updateOptionsTable(filesTable->currentItem());
}


/*!
 * \brief Update options table based on selected file in table of files.
 * \param item Selected item in files table as QTableWidgetItem
 */
void BBSubmitWindow::updateOptionsTable(QTableWidgetItem *item)
{
    optionsTable->clear();
    int row = item->row();
    int c = 0;
    foreach(QString s, fileList.at(row))
    {
        int row = optionsTable->rowCount();
        if (c % 2)
        {
            optionsTable->setItem(row - 1, 1, new QTableWidgetItem(s));
        } else {
            optionsTable->insertRow(row);
            optionsTable->setItem(row, 0, new QTableWidgetItem(s));
        }
        c++;
    }
    optionsTable->resizeRowsToContents();
}

/*!
 * \brief Appends full default command string for new added file to fileList QStringList
 * \param row
 * \param filePath Full directory path of file.
 */
void BBSubmitWindow::appendToFileList(int row, QString filePath)
{
    QStringList keyString;
    keyString.append("executable");
    keyString.append("blender");
    keyString.append("path");
    keyString.append(filePath);
    keyString.append("frames");
    keyString.append("1-100");
    keyString.append("subtasks");
    keyString.append("1");
    keyString.append("priority");
    keyString.append("50");
    keyString.append("jobname");
    keyString.append("Renderjob 01");
    fileList.append(keyString);
}


/*!
 * \brief Clear table of files.
 */
void BBSubmitWindow::clearFileList()
{
    fileList.clear();
}
