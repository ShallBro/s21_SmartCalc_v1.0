#include "mainwindow.h"

#include <clocale>
#include <iostream>

#include "ui_mainwindow.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "../s21_SmartCalculator.h"
int validator(char *input_str, int res);
int check_math_operations(int i, char *input_str, int res, int *check_dot,
                          bool flag_breckets);
int check_brackets(int i, char *input_str, int res, bool this_func);
double s21_calculator(char *input_str, char *output_res, double x);
#ifdef __cplusplus
}  // extern "C"
#endif
// check
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_left, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_right, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(print()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(print_trigonometry()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this,
          SLOT(on_pushButton_dot_clicked()));
  connect(ui->pushButton_sign, SIGNAL(clicked()), this,
          SLOT(operations_sign()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(clear_window()));
  // connect(ui->pushButton_AC,SIGNAL(clicked()),this,SLOT(clear_result_show()));
  // connect(ui->pushButton_equals,SIGNAL(clicked()),this,SLOT(on_pushButton_equals_clicked()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::print() {
  if (ui->result_show->text() == '0') {
    ui->result_show->setText("");
  }
  QPushButton *number = (QPushButton *)sender();
  QString new_result_show = number->text();
  ui->result_show->setText(ui->result_show->text() += new_result_show);
}

void MainWindow::print_trigonometry() {
  if (ui->result_show->text() == '0') {
    ui->result_show->setText("");
  }
  QPushButton *number = (QPushButton *)sender();
  char symbol = '(';
  QString new_result_show = number->text() + symbol;
  ui->result_show->setText(ui->result_show->text() += new_result_show);
}

void MainWindow::on_pushButton_dot_clicked() {
  if (!(ui->result_show->text().contains('.')))
    ui->result_show->setText(ui->result_show->text() + '.');
}

void MainWindow::operations_sign() {
  char new_result_show = '-';
  if (!(ui->result_show->text().contains('-'))) {
    ui->result_show->setText(ui->result_show->text() = new_result_show);
  }
  //    double x = 0.
  //            x.toStdString
}

void MainWindow::clear_window() { ui->result_show->setText("0"); }

void MainWindow::on_pushButton_equals_clicked() {
  double result = 0.0;
  QString _stringBack = ui->result_show->text();
  QByteArray str_bit = _stringBack.toLocal8Bit();
  QString _stringX = ui->lineEdit_X->text();
  double x = _stringX.toDouble();
  char *input_str = str_bit.data();
  int n_str = strlen(input_str) * 2;
  char *output = (char *)malloc(sizeof(char) * n_str);
  if (output != NULL) {
    output[n_str] = '\0';
  }
  result = s21_calculator(input_str, output, x);
  if (strlen(output) != 0) {
    ui->result_show->setText(output);
  } else {
    QString resultStr = QString::number(result, 'f', 7);
    ui->result_show->setText(resultStr);
  }
  free(output);
}

void MainWindow::on_pushButton_plot_clicked() {
  int maxX = ui->max_X->text().toInt();
  int minX = ui->min_X->text().toInt();
  int maxY = ui->max_Y->text().toInt();
  int minY = ui->min_Y->text().toInt();
  // bool check = false;
  double step = (maxX - minX) / 1024.0;
  char string[1024] = {0};
  char *result = (char *)calloc(1024, sizeof(char));
  QByteArray input = ui->result_show->text().toLocal8Bit();
  QVector<double> x(1024), y(1024);
  QPen bluePen;
  double tempResult = 0.0;
  memcpy(string, input, ui->result_show->text().length() + 1);
  for (int i = 0; i < 1024; ++i) {
    memset(result, '\0', 1024);
    x[i] = minX + step * i;
    tempResult = s21_calculator(string, result, x[i]);
    if (!strcmp(result, "INF")) {
      y[i] = INFINITY;
    } else if (!strcmp(result, "NAN")) {
      y[i] = NAN;
    } else if (!strcmp(result, "INVALID INPUT")) {
      y[i] = strtod(result, NULL);
    } else
      y[i] = tempResult;
  }
  ui->Grafic->addGraph();
  bluePen.setColor(QColor(30, 40, 255, 255));
  bluePen.setStyle(Qt::SolidLine);
  bluePen.setWidthF(0.5);
  ui->Grafic->graph(0)->setPen(bluePen);
  ui->Grafic->graph(0)->setData(x, y);
  ui->Grafic->xAxis->setLabel("x");
  ui->Grafic->yAxis->setLabel("y");
  ui->Grafic->xAxis->setRange(minX, maxX);
  ui->Grafic->yAxis->setRange(minY, maxY);
  ui->Grafic->setInteraction(QCP::iRangeZoom, true);
  ui->Grafic->setInteraction(QCP::iRangeDrag, true);
  ui->Grafic->replot();
  free(result);
}
