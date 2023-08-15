#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_new_file_triggered()
{
    m_currentFile.clear();
    ui->textEdit->clear();
}


void MainWindow::on_action_underline_triggered(bool _checked)
{
    ui->textEdit->setFontUnderline(_checked);
}


void MainWindow::on_action_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件");
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "警告", "无法打开该文件：" + file.errorString());
        return;
    }
    m_currentFile = fileName;
    this->setWindowTitle(fileName);

    QTextStream ts(&file);
    QString text = ts.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_action_save_file_triggered()
{
    QString fileName;
    if(m_currentFile.isEmpty()) {
        fileName = QFileDialog::getSaveFileName(this, "保存文件");
        m_currentFile = fileName;
    }else
        fileName = m_currentFile;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }
    this->setWindowTitle(fileName);
    QTextStream ts(&file);
    auto text = ui->textEdit->toHtml();
    ts << text;
    file.close();
}


void MainWindow::on_action_save_to_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "另存为");

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }
    this->setWindowTitle(fileName);
    QTextStream ts(&file);
    auto text = ui->textEdit->toHtml();
    ts << text;
    file.close();
}


void MainWindow::on_action_copy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_action_cut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_action_paste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_action_bold_triggered(bool _checked)
{
    ui->textEdit->setFontWeight(_checked ? QFont::Bold : QFont::Normal);
}


void MainWindow::on_action_italic_triggered(bool _checked)
{
    ui->textEdit->setFontItalic(_checked);
}


void MainWindow::on_action_redo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_action_undo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_action_font_triggered()
{
    bool isFontSelected;
    QFont font = QFontDialog::getFont(&isFontSelected, this);
    if(isFontSelected)
        ui->textEdit->setFont(font);
}


void MainWindow::on_action_quit_triggered()
{
    QCoreApplication::exit();
}


void MainWindow::on_action_about_triggered()
{
    QMessageBox::about(this, "MyNotePad", "这是MyNotePad");
}

