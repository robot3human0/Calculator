#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QIcon>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>

extern "C" {
#include "../back/polka.h"
#include "../back/stack.h"
}

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

 private slots:

  void on_one_clicked();

  void on_two_clicked();

  void on_three_clicked();

  void on_four_clicked();

  void on_five_clicked();

  void on_six_clicked();

  void on_seven_clicked();

  void on_eight_clicked();

  void on_nine_clicked();

  void on_zero_clicked();

  void on_plus_clicked();

  void on_minus_clicked();

  void on_multiple_clicked();

  void on_divide_clicked();

  void on_pow_clicked();

  void on_sqrt_clicked();

  void on_dot_clicked();

  void on_left_bracket_clicked();

  void on_right_bracket_clicked();

  void on_ln_clicked();

  void on_log_clicked();

  void on_mod_clicked();

  void on_asin_clicked();

  void on_sin_clicked();

  void on_acos_clicked();

  void on_cos_clicked();

  void on_atan_clicked();

  void on_tan_clicked();

  void on_x_button_clicked();

  void on_backspace_clicked();

  void on_allClear_clicked();

  void on_equal_clicked();

  //    void on_widget_customContextMenuRequested(const QPoint &pos);

  void on_draw_clicked();

 private:
  Ui::MainWindow *ui;
  double x_min, x_max, y_min, y_max, X, h;
  QVector<double> x, y;
};
#endif  // MAINWINDOW_H
