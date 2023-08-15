#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_new_file_triggered();

    void on_action_underline_triggered(bool checked);

    void on_action_open_file_triggered();

    void on_action_save_file_triggered();

    void on_action_save_to_triggered();

    void on_action_copy_triggered();

    void on_action_cut_triggered();

    void on_action_paste_triggered();

    void on_action_bold_triggered(bool checked);

    void on_action_italic_triggered(bool checked);

    void on_action_redo_triggered();

    void on_action_undo_triggered();

    void on_action_font_triggered();

    void on_action_quit_triggered();

    void on_action_about_triggered();

private:
    Ui::MainWindow *ui;
    QString m_currentFile;
};
#endif // MAINWINDOW_H
