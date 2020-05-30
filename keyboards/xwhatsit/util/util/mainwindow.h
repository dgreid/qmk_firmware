#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "monitorwindow.h"
#include "communication.h"
#include "hidthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Communication &comm, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_updateScannedDevices(std::vector<std::string> devices);
    void on_reportError(std::string error_message);
    void on_listWidget_itemSelectionChanged();
    void on_enterBootloaderPushbutton_clicked();
    void on_keypressMinotorPushButton_clicked();

    void on_autoEnterModeCheckBox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Communication &comm;
    HidThread thread;
};

#endif // MAINWINDOW_H
