#include <QApplication>
#include "bbsubmitwindow.h"


/*!
 * \brief BBSubmit main
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    BBSubmitWindow window;
    window.show();
    return app.exec();
}

