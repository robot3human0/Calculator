#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->doubleSpinBox->clear();
  ui->x_min_box->clear();
  ui->x_max_box->clear();
  ui->y_min_box->clear();
  ui->y_max_box->clear();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_one_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "1");
}

void MainWindow::on_two_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "2");
}

void MainWindow::on_three_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "3");
}

void MainWindow::on_four_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "4");
}

void MainWindow::on_five_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "5");
}

void MainWindow::on_six_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "6");
}

void MainWindow::on_seven_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "7");
}

void MainWindow::on_eight_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "8");
}

void MainWindow::on_nine_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "9");
}

void MainWindow::on_zero_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "0");
}

void MainWindow::on_plus_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " + ");
}

void MainWindow::on_minus_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " - ");
}

void MainWindow::on_multiple_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " * ");
}

void MainWindow::on_divide_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " / ");
}

void MainWindow::on_pow_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " ^ ");
}

void MainWindow::on_sqrt_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " SQRT(");
}

void MainWindow::on_dot_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + ".");
}

void MainWindow::on_left_bracket_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "(");
}

void MainWindow::on_right_bracket_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + ") ");
}

void MainWindow::on_ln_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " LN(");
}

void MainWindow::on_log_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " LOG(");
}

void MainWindow::on_mod_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " MOD ");
}

void MainWindow::on_asin_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " ASIN(");
}

void MainWindow::on_sin_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " SIN(");
}

void MainWindow::on_acos_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " ACOS(");
}

void MainWindow::on_cos_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " COS(");
}

void MainWindow::on_atan_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " ATAN(");
}

void MainWindow::on_tan_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + " TAN(");
}

void MainWindow::on_x_button_clicked() {
  ui->InputLine->setText(ui->InputLine->text() + "X");
}

void MainWindow::on_backspace_clicked() { ui->InputLine->backspace(); }

void MainWindow::on_allClear_clicked() {
  ui->InputLine->clear();
  ui->doubleSpinBox->clear();
}

void MainWindow::on_equal_clicked() {
  QByteArray input_string = ui->InputLine->text().toLocal8Bit();
  double x = ui->doubleSpinBox->value();
  double result = 0;
  int code = 0;
  char *str = input_string.data();

  if (calculate(str, x, &result))
    code = 1;
  else
    code = 0;

  if (code) {
    ui->InputLine->setText(QString::number(result, 'f', 6));
  } else {
    ui->InputLine->setText("ERROR CALCULATION");
  }
}

void MainWindow::on_draw_clicked() {
  double res_Y;
  h = 0.01;
  x_min = ui->x_min_box->value();
  x_max = ui->x_max_box->value();
  y_min = ui->y_min_box->value();
  y_max = ui->y_max_box->value();

  QByteArray input_string = ui->InputLine->text().toLocal8Bit();
  char *str = input_string.data();
  char res[MAX_LEN];
  Stack_t *polka = NULL;
  Double_stack *nums = NULL;
  to_lower_case_without_spaces(str);
  make_it_shorter(str);
  to_polka(str, res, &polka);

  for (X = x_min; X <= x_max; X += h) {
    true_calc(res, &res_Y, &nums, X);
    x.push_back(X);
    y.push_back(res_Y);
  }

  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->yAxis->setRange(y_min, y_max);

  ui->widget->clearGraphs();
  ui->widget->addGraph();

  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssCircle, 5));

  ui->widget->graph(0)->addData(x, y);

  ui->widget->replot();
  ui->widget->setInteraction(QCP::iRangeZoom, true);
  ui->widget->setInteraction(QCP::iRangeDrag, true);
  x.clear();
  y.clear();
}
