#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "ini_file.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;
	bool drow_finished;

	ini_file ini_obj;

private slots:
	void on_actionLoad_File_triggered();

	void drow_section_field();

	void on_tree_sect_itemClicked(QTreeWidgetItem * item, int column);

	void on_tablewidget_cellClicked(int row, int column);

	void on_tablewidget_itemChanged(int row, int column);

	void on_button_add_clicked(bool b);

	void on_button_add_s_clicked(bool b);

	void on_button_del_clicked(bool b);

	void on_button_del_sec_clicked(bool b);

	void on_line_add_s_edit();

	void on_line_add_edit();

	void on_actionSave_file_triggered();

	void on_actionClear_triggered();

};
