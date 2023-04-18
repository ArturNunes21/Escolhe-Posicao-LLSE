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
        int aux=lista.getAux();
        QString texto=ui->lineEditValor->text();
        if(texto==nullptr || texto.length()<1)
            throw QString ("Nenhum valor inserido - on_btn_inserir_clicked");
        int dado=texto.toInt();
        lista.inserirInicio(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);

        if(aux==0){
            lista.setPrimeiro(dado);
            lista.setAux(1);
        }
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
        int aux=lista.getAux();
        QString texto=ui->lineEditValor->text();
        if(texto==nullptr || texto.length()<1)
            throw QString ("Nenhum valor inserido - on_btn_inserir_fim_clicked");
        int dado=texto.toInt();
        lista.inserirFim(dado);
        ui->textEditSaida->setText((lista.obterDadosLLSE()));
        QString num = QString::number(lista.getQuantidadeElementos());
        ui->textEditQuantidade->setText(num);

        if(aux==0){
            lista.setPrimeiro(dado);
            lista.setAux(1);
        }
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
            int aux=lista.getAux();
            QString texto=ui->lineEditValor->text();
            if(texto==nullptr || texto.length()<1)
                throw QString ("Nenhum valor inserido - on_btn_inserir_posicao_clicked");
            int dado=texto.toInt();
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

                if(aux==0){
                    lista.setPrimeiro(dado);
                    lista.setAux(1);
                }
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


void MainWindow::on_btn_maior_menor_clicked()
{
    try{
        int qtde=lista.getQuantidadeElementos();
        if(qtde==1){
            QMessageBox::about(this,"","A lista só possui um elemento");
        }
        ui->textEdit_maior_menor->setText(lista.obterMaiorEMenor());
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}



void MainWindow::on_btn_primeiro_valor_clicked()
{
    try{
        ui->textEdit_primeiro_valor->setText(QString::number(lista.getPrimeiro()));
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}


void MainWindow::on_btn_mmc_clicked()
{
    try{
        ui->textEdit_mmc->setText(QString::number(lista.calcularMmcLLSE()));
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}


void MainWindow::on_btn_procurar_posicao_clicked()
{
    try{
        QString texto=ui->lineEdit_procurar_posicao->text();
        if(texto==nullptr || texto.length()<1)
            throw QString ("Nenhum valor inserido - on_btn_inserir_posicao_clicked");
        int dado=texto.toInt();
        ui->textEdit_procurar_posicao->setText(lista.obterPosicoes(dado));
    }
    catch (QString &erro){
        QMessageBox::critical(this,"",erro);
    }
}

