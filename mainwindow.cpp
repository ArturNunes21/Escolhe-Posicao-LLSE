#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

Artur::LLSE lista;

void MainWindow::on_btn_inserir_clicked()
{
    try{
        int dado=0;
        dado=ui->lineEditValor->text().toInt();
        lista.inserirInicio(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }

    ui->lineEditValor->clear();
    ui->lineEditValor->setFocus();


}
void MainWindow::on_btn_retirar_clicked(){
    try{
        QString saida = "";
        int valor;
        //lista.printLLSE();  // DEBUG
        valor = lista.retirarInicio();
        //lista.printLLSE();  // DEBUG
        saida += "Valor | "+ QString::number(valor)+ " | retirado. \n";
        ui->textEditSaida->setText(saida + lista.obterDadosLLSE());
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}
void MainWindow::on_btn_acessar_clicked(){
    try{
        QString saida = "";
        saida += "| " + QString::number(lista.acessarInicio())+ " |";
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}


void MainWindow::on_btn_inserir_fim_clicked()
{
    try{
        int dado=0;
        dado=ui->lineEditValor->text().toInt();
        lista.inserirFim(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }

    ui->lineEditValor->clear();
    ui->lineEditValor->setFocus();
}


void MainWindow::on_btn_acessar_fim_clicked()
{
    try{
        QString saida = "";
        saida += "| " + QString::number(lista.acessarFim())+ " |";
        ui->lineEditValor->setText(saida);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}


void MainWindow::on_btn_retirar_fim_clicked()
{
    try{
        QString saida = "";
        saida += "Valor | "+ QString::number(lista.retirarFim())+ " | retirado. \n";
        ui->textEditSaida->setText(saida + lista.obterDadosLLSE());
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}


void MainWindow::on_btn_acessar_posicao_clicked()
{
    try{
        int posicao=ui->lineEdit_acessar_posicao->text().toInt();
        QString saida = "";
        if(posicao==0){
            saida += "| " + QString::number(lista.acessarInicio())+ " |";
            ui->lineEditValor->setText(saida);
        }
        else{
            saida += "| " + QString::number(lista.acessarPosicao(posicao))+ " |";
            ui->lineEditValor->setText(saida);
        }
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);

}
}

void MainWindow::on_btn_inserir_posicao_clicked()
{
    {
        try{
            int dado=0;
            int posicao=0;
            int elementos=lista.getQuantidadeElementos();
            dado=ui->lineEditValor->text().toInt();
            posicao=ui->lineEdit_inserir_posicao->text().toInt();
            if(posicao==0){
                lista.inserirInicio(dado);
            }
            else if(posicao==elementos){
                lista.inserirFim(dado);
            }
            else{
                lista.inserirPosicao(dado, posicao);
            }
                ui->textEditSaida->setText((lista.obterDadosLLSE()));
                QString num = QString::number(lista.getQuantidadeElementos());
                ui->textEditQuantidade->setText(num);
            }
        catch (QString &erro){
            QMessageBox::critical(this,"",erro);
        }

        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();


    }
}

void MainWindow::on_btn_retirar_posicao_clicked()
{
    try{
        QString saida = "";
        int valor;
        int posicao=ui->lineEdit_retirar_posicao->text().toInt();
        valor=lista.retirarPosicao(posicao);
        saida += "Valor | "+ QString::number(valor)+ " | retirado. \n";
        ui->textEditSaida->setText(saida + lista.obterDadosLLSE());
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}



void MainWindow::on_btn_insere_ordenado_clicked()
{
    try{
        int dado=ui->lineEditValor->text().toInt();
        lista.inserirOrdenado(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);
    }
    catch (QString erro){
        QMessageBox::critical(this,"",erro);
    }
    catch (std::exception &erro){
        QMessageBox::critical(this,"",erro.what());
    }


    ui->lineEditValor->clear();
    ui->lineEditValor->setFocus();
}

