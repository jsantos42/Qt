#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit); //this makes it fill the entire area!
    setWindowTitle("Untitled");
    connect(this->ui->actionNew, &QAction::triggered, this, &MainWindow::on_actionNew);
    connect(this->ui->actionOpen, &QAction::triggered, this, &MainWindow::on_actionOpen);
    connect(this->ui->actionSave_as, &QAction::triggered, this, &MainWindow::on_actionSaveAs);
    connect(this->ui->actionPrint, &QAction::triggered, this, &MainWindow::on_actionPrint);
    connect(this->ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit);
    connect(this->ui->actionCopy, &QAction::triggered, this, &MainWindow::on_actionCopy);
    connect(this->ui->actionPaste, &QAction::triggered, this, &MainWindow::on_actionPaste);
    connect(this->ui->actionCut, &QAction::triggered, this, &MainWindow::on_actionCut);
    connect(this->ui->actionUndo, &QAction::triggered, this, &MainWindow::on_actionUndo);
    connect(this->ui->actionRedo, &QAction::triggered, this, &MainWindow::on_actionRedo);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew()
{
    currentFile.clear();
    ui->plainTextEdit->setPlainText(QString());
}


void MainWindow::on_actionOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open");
    QFile	file(fileName);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return ;
    }
    QTextStream	istream(&file);
    ui->plainTextEdit->setPlainText(istream.readAll());
    file.close();
    currentFile = fileName;
    setWindowTitle(fileName.sliced(fileName.lastIndexOf('/') + 1));
}

void MainWindow::on_actionSaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile	file(fileName);

    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
        return ;
    }
    QTextStream	ostream(&file);
    ostream << ui->plainTextEdit->toPlainText();
    file.close();
    currentFile = fileName;
    setWindowTitle(fileName.sliced(fileName.lastIndexOf('/') + 1));


}

void MainWindow::on_actionPrint()
{
    QPrinter		printer;
    QPrintDialog	pDialog(&printer, this);

    printer.setPrinterName("Printer Name");
    if (pDialog.exec() == QDialog::Rejected) {
        QMessageBox::warning(this, "Warning", "Cannot access the specified printer");
        return ;
    }
    ui->plainTextEdit->print(&printer);
}


void MainWindow::on_actionExit()
{
    QMessageBox::information(this, "", "Closing now");
    QApplication::quit();
}

void MainWindow::on_actionCopy()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionPaste()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionCut()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionUndo()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRedo()
{
    ui->plainTextEdit->redo();
}
