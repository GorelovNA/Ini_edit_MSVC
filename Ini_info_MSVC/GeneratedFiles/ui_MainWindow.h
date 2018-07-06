/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionSave_file;
    QAction *actionLoad_File;
    QAction *actionClear;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *tree_sect;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *line_add_new_sect;
    QLabel *label_add_new_sect;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *but_add_s;
    QPushButton *but_del_s;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *line_add_new_param;
    QLabel *label_add_new_param;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *but_add;
    QPushButton *but_del;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(1000, 679);
        MainWindowClass->setMinimumSize(QSize(1000, 500));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/img/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowClass->setWindowIcon(icon);
        actionSave_file = new QAction(MainWindowClass);
        actionSave_file->setObjectName(QStringLiteral("actionSave_file"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_file->setIcon(icon1);
        actionLoad_File = new QAction(MainWindowClass);
        actionLoad_File->setObjectName(QStringLiteral("actionLoad_File"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/img/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_File->setIcon(icon2);
        actionClear = new QAction(MainWindowClass);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/img/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tree_sect = new QTreeWidget(layoutWidget);
        tree_sect->setObjectName(QStringLiteral("tree_sect"));

        verticalLayout_3->addWidget(tree_sect);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        line_add_new_sect = new QLineEdit(layoutWidget);
        line_add_new_sect->setObjectName(QStringLiteral("line_add_new_sect"));
        line_add_new_sect->setEnabled(false);

        horizontalLayout_2->addWidget(line_add_new_sect);

        label_add_new_sect = new QLabel(layoutWidget);
        label_add_new_sect->setObjectName(QStringLiteral("label_add_new_sect"));
        label_add_new_sect->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_add_new_sect->sizePolicy().hasHeightForWidth());
        label_add_new_sect->setSizePolicy(sizePolicy);
        label_add_new_sect->setMaximumSize(QSize(90, 13));

        horizontalLayout_2->addWidget(label_add_new_sect);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        but_add_s = new QPushButton(layoutWidget);
        but_add_s->setObjectName(QStringLiteral("but_add_s"));
        but_add_s->setEnabled(false);

        horizontalLayout_4->addWidget(but_add_s);

        but_del_s = new QPushButton(layoutWidget);
        but_del_s->setObjectName(QStringLiteral("but_del_s"));
        but_del_s->setEnabled(false);

        horizontalLayout_4->addWidget(but_del_s);


        verticalLayout_3->addLayout(horizontalLayout_4);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget = new QTableWidget(layoutWidget1);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::AnyKeyPressed|QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::DotLine);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        line_add_new_param = new QLineEdit(layoutWidget1);
        line_add_new_param->setObjectName(QStringLiteral("line_add_new_param"));
        line_add_new_param->setEnabled(false);

        horizontalLayout->addWidget(line_add_new_param);

        label_add_new_param = new QLabel(layoutWidget1);
        label_add_new_param->setObjectName(QStringLiteral("label_add_new_param"));
        label_add_new_param->setEnabled(false);
        sizePolicy.setHeightForWidth(label_add_new_param->sizePolicy().hasHeightForWidth());
        label_add_new_param->setSizePolicy(sizePolicy);
        label_add_new_param->setMaximumSize(QSize(79, 13));

        horizontalLayout->addWidget(label_add_new_param);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        but_add = new QPushButton(layoutWidget1);
        but_add->setObjectName(QStringLiteral("but_add"));
        but_add->setEnabled(false);

        horizontalLayout_3->addWidget(but_add);

        but_del = new QPushButton(layoutWidget1);
        but_del->setObjectName(QStringLiteral("but_del"));
        but_del->setEnabled(false);

        horizontalLayout_3->addWidget(but_del);


        verticalLayout->addLayout(horizontalLayout_3);

        splitter->addWidget(layoutWidget1);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionLoad_File);
        menuMenu->addAction(actionSave_file);
        menuMenu->addAction(actionClear);
        mainToolBar->addAction(actionLoad_File);
        mainToolBar->addAction(actionSave_file);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "INI editor", nullptr));
        actionSave_file->setText(QApplication::translate("MainWindowClass", "Save File", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave_file->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionLoad_File->setText(QApplication::translate("MainWindowClass", "Open File", nullptr));
#ifndef QT_NO_SHORTCUT
        actionLoad_File->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+L", nullptr));
#endif // QT_NO_SHORTCUT
        actionClear->setText(QApplication::translate("MainWindowClass", "Clear", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree_sect->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowClass", "Section name", nullptr));
        line_add_new_sect->setText(QApplication::translate("MainWindowClass", "[ ]", nullptr));
        label_add_new_sect->setText(QApplication::translate("MainWindowClass", "Enter new section", nullptr));
        but_add_s->setText(QApplication::translate("MainWindowClass", "New", nullptr));
        but_del_s->setText(QApplication::translate("MainWindowClass", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindowClass", "Param", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindowClass", "Value", nullptr));
        label_add_new_param->setText(QApplication::translate("MainWindowClass", "Enter new string", nullptr));
        but_add->setText(QApplication::translate("MainWindowClass", "New", nullptr));
        but_del->setText(QApplication::translate("MainWindowClass", "Delete", nullptr));
        menuMenu->setTitle(QApplication::translate("MainWindowClass", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
