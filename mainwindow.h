#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QPixmap>
#include <QMainWindow>
#include <QString>
#include <no.h>
#include "llse.h"


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
    void on_btn_inserir_clicked();

    void on_btn_retirar_clicked();

    void on_btn_acessar_clicked();

    void on_btn_inserir_fim_clicked();

    void on_btn_acessar_fim_clicked();

    void on_btn_retirar_fim_clicked();

    void on_btn_acessar_posicao_clicked();

    void on_btn_inserir_posicao_clicked();

    void on_btn_retirar_posicao_clicked();

    void on_btn_insere_ordenado_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
