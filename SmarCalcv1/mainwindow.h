#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

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
}
#endif

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QVector<double> x, y;

 private slots:
  void print();
  //  void clear_result_show();
  void on_pushButton_dot_clicked();
  void operations_sign();
  void clear_window();
  void print_trigonometry();

  void on_pushButton_equals_clicked();
  void on_pushButton_plot_clicked();
};
#endif  // MAINWINDOW_H
