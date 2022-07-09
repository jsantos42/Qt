#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void	on_actionNew();
    void	on_actionOpen();
    void	on_actionSaveAs();
    void	on_actionPrint();
    void	on_actionExit();
    void	on_actionCopy();
    void	on_actionPaste();
    void	on_actionCut();
    void	on_actionUndo();
    void	on_actionRedo();

private:
    Ui::MainWindow	*ui;
    QString			currentFile = "";
};

#endif // MAINWINDOW_H
