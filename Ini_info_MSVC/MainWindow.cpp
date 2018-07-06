#include "MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <qtreewidget.h>
#include <qtabwidget.h>
#include <qdebug.h>
#include <qsplitter.h>
#include <qlineedit.h>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), drow_finished(0)
{
	ui.setupUi(this);

	connect(ui.tree_sect, &QTreeWidget::itemClicked, this, &MainWindow::on_tree_sect_itemClicked);
	connect(ui.tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tablewidget_itemChanged);
	connect(ui.tableWidget, &QTableWidget::cellClicked, this, &MainWindow::on_tablewidget_cellClicked);
	connect(ui.but_add, &QPushButton::clicked, this, &MainWindow::on_button_add_clicked);
	connect(ui.but_add_s, &QPushButton::clicked, this, &MainWindow::on_button_add_s_clicked);
	connect(ui.line_add_new_param, &QLineEdit::editingFinished, this, &MainWindow::on_line_add_edit);
	connect(ui.line_add_new_sect, &QLineEdit::editingFinished, this, &MainWindow::on_line_add_s_edit);

	connect(ui.but_del, &QPushButton::clicked, this, &MainWindow::on_button_del_clicked);
	connect(ui.but_del_s, &QPushButton::clicked, this, &MainWindow::on_button_del_sec_clicked);
	
	ui.tableWidget->setColumnCount(3);
	// Разрешаем выделение только одного элемента	
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
	ui.tableWidget->setColumnWidth(1, 15);
	ui.tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

	// Растягиваем последнюю колонку на всё доступное пространство
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);

	ui.splitter->setStretchFactor(0, 0);
	ui.splitter->setStretchFactor(1, 1);;
}

void MainWindow::on_actionLoad_File_triggered()
{
	ini_obj.clear();
	//on_actionClear_triggered();

	QString str = QFileDialog::getOpenFileName(this, tr("Load File"), "", tr("INI files (*.ini);;Text Files (*.txt)"));
	if (str != "") {
		QFile file(str);
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		else {
			file.close();
			if (!ini_obj.load(str.toStdString().c_str())) {
				QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			}
			else {
				drow_section_field();
			}
		}
	}
}

void MainWindow::drow_section_field() {	
	drow_finished = 0;

	ui.tableWidget->setRowCount(0);
	ui.but_del->setEnabled(0);
	ui.but_add->setEnabled(0);
	ui.tree_sect->clear();
	auto list = ini_obj.get_list();
	Sector_st *sec = list.head;
	while (sec != NULL) {
		QTreeWidgetItem *t = new QTreeWidgetItem;
		t->setText(0, QString::fromStdString(sec->name));
		t->setExpanded(true);
		ui.tree_sect->addTopLevelItem(t);

		sec = sec->next;
	}
	ui.but_add_s->setEnabled(1);

	drow_finished = 1;

}

void MainWindow::on_tree_sect_itemClicked(QTreeWidgetItem *item, int column)
{
	drow_finished = 0;
	
	ui.tableWidget->setRowCount(0);

	auto tt = item->text(0).toStdString();
	const char *ch = tt.c_str();

	auto list = ini_obj.get_list();
	auto *sec = list.search(ch);
	if (sec != NULL) {
		Param_st *p = sec->Param.head;
		while (p != NULL) {
			if (p->value[0] != '\0') {//param
				ui.tableWidget->insertRow(ui.tableWidget->rowCount());
				ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(p->name)));
				ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 0)->setFlags(item->flags() &  ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
				ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem("="));
				ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 1)->setFlags(item->flags() &  ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
				ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 1)->setTextColor(Qt::red);

				ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(p->value)));
			}
			else //string or comment
				if (p->name[0] != '\0') {
					ui.tableWidget->insertRow(ui.tableWidget->rowCount());
					ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(p->name)));

					ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 1, new QTableWidgetItem(""));
					ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, 2, new QTableWidgetItem("/*string or comment*/"));
					ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 2)->setTextColor(Qt::darkGreen);
					ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 1)->setFlags(item->flags() &  ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
					ui.tableWidget->item(ui.tableWidget->rowCount() - 1, 2)->setFlags(item->flags() &  ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
				}
			p = p->next;
			ui.tableWidget->resizeColumnToContents(0);			
		}
		drow_finished = 1;
	}

	ui.but_del->setEnabled(0);
	ui.but_del_s->setEnabled(1);
	ui.but_add->setEnabled(1);
}

void MainWindow::on_tablewidget_cellClicked(int row, int column) {
	ui.but_del->setEnabled(1);
}


void MainWindow::on_tablewidget_itemChanged(int row, int column)
{
	if (drow_finished && column!=1) {
		string text_sec = ui.tree_sect->currentItem()->text(0).toStdString();

		auto list = ini_obj.get_list();
		Sector_st *sec = list.search(text_sec.c_str());
		if (sec != NULL) {
			if (column == 0) {//string or commit
				string text_param = ui.tableWidget->item(row, 0)->text().toStdString();// .toStdString;
				const char *ch_p = text_param.c_str();
				Param_st *param = sec->Param.head;
				for (int i(0); i < row; i++)
					param = param->next;
				if (strlen(ch_p) == 0 || ch_p == " ") { //protect
					on_tree_sect_itemClicked(ui.tree_sect->currentItem(), 0);
					return;
				}
				sec->Param.edit_comp(*param, ch_p, NULL);
			}
			else {
				string text_param = ui.tableWidget->item(row, 0)->text().toStdString();// .toStdString;
				string text_value = ui.tableWidget->item(row, 2)->text().toStdString();// .toStdString;

				ini_obj.set_param(text_sec.c_str(), text_param.c_str(), text_value.c_str());
			}
		}
		on_tree_sect_itemClicked(ui.tree_sect->currentItem(), 0);
	}
}

void MainWindow::on_button_add_clicked(bool b) {
	ui.line_add_new_param->setEnabled(1);
	ui.label_add_new_param->setEnabled(1);
	ui.but_add->setEnabled(0);
	ui.line_add_new_param->setFocus();
}

void MainWindow::on_button_add_s_clicked(bool b) {
	ui.line_add_new_sect->setEnabled(1);
	ui.label_add_new_sect->setEnabled(1);
	ui.but_add_s->setEnabled(0);
	ui.line_add_new_sect->setFocus();
}

void MainWindow::on_button_del_clicked(bool b) {
	string text_sec = ui.tree_sect->currentItem()->text(0).toStdString();
	string text_param = ui.tableWidget->item(ui.tableWidget->currentRow(), 0)->text().toStdString();
	ini_obj.delete_param(text_sec.c_str(), text_param.c_str());
	on_tree_sect_itemClicked(ui.tree_sect->currentItem(), 0);
}

void MainWindow::on_button_del_sec_clicked(bool b) {
	string text_sec = ui.tree_sect->currentItem()->text(0).toStdString();
	ini_obj.delete_section(text_sec.c_str());
	drow_section_field();
}

void MainWindow::on_line_add_s_edit() {
	drow_finished = 0;
	auto text_sec = ui.line_add_new_sect->text().toStdString();

	ini_obj.set_param(text_sec.c_str(),NULL,NULL);
	drow_section_field();

	ui.line_add_new_sect->setEnabled(0);
	ui.line_add_new_sect->setText("[ ]");
	
	ui.label_add_new_sect->setEnabled(0);
	ui.but_add_s->setEnabled(1);
	drow_finished = 1;
}



void MainWindow::on_line_add_edit() {
	drow_finished = 0;
	auto text_sec = ui.tree_sect->currentItem()->text(0).toStdString();

	Param_st param;
	auto t = ui.line_add_new_param->text().toStdString();
	int i = 0, j = 0;
	while (i < t.length() && t[i] != '=') {
		param.name[j] = t[i];
		i++; j++;
	}
	param.name[j] = '\0';
	i++; j = 0;
	while (i < t.length()) {
		param.value[j] = t[i];
		i++; j++;
	}
	param.value[j] = '\0';

	ini_obj.set_param(text_sec.c_str(), (char*)&param.name, (char*)&param.value);

	on_tree_sect_itemClicked(ui.tree_sect->currentItem(), 0);	

	ui.line_add_new_param->clear();
	ui.line_add_new_param->setEnabled(0);
	ui.label_add_new_param->setEnabled(0);
	ui.but_add->setEnabled(1);
	drow_finished = 1;
}

void MainWindow::on_actionSave_file_triggered()
{
	QString str = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("INI files (*.ini);;Text Files (*.txt)"));
	if (str != "") {
		QFile file(str);
		if (!file.open(QIODevice::WriteOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		else {
			file.close();
			if (!ini_obj.store(str.toStdString().c_str())) {
				QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			}
		}
	}
}

void MainWindow::on_actionClear_triggered()
{
	ini_obj.clear();
	drow_section_field();
	ui.but_add_s->setEnabled(0);
	ui.but_del_s->setEnabled(0);
}