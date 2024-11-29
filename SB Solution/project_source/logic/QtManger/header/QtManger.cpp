#include "QtManger.h"

QtManger::QtManger()
{
	setup_first_windows();
}
void QtManger::connect_all_signals()
{
	QWidget::connect(status, &QPushButton::clicked, this, &QtManger::status_pressed);
	QWidget::connect(save, &QPushButton::clicked, this, &QtManger::save_pressed);
}
void QtManger::setup_first_windows()
{
	initial_members();
	
	firstWindows->setWindowTitle("Sonnen Battary system");
	firstWindows->setFixedSize(300, 700);
	firstWindows->setLayout(mainLayout);
	
	label_setup_first_window();
	
	rowLayout[8]->addStretch();
	rowLayout[8]->addWidget(status);
	rowLayout[8]->addWidget(save);
	mainLayout->addLayout(rowLayout[8].get());

	connect_all_signals();
}

void QtManger::setup_second_windows()
{
}

void QtManger::initial_members()
{
	for (int i = 0; i < 100; ++i) {
		rowLayout.push_back(std::make_unique<QHBoxLayout>());
	}
	firstWindows = new QWidget(nullptr);
	mainLayout = new QVBoxLayout();
	grid_P_box = new QLineEdit();
	grid_V_box = new QLineEdit();
	grid_F_box = new QLineEdit();
	panel_P_box = new QLineEdit();
	panel_V_box = new QLineEdit();
	panel_I_box = new QLineEdit();
	home_P_box = new QLineEdit();
	home_id_box = new QLineEdit();

	grid_P_label = new QLabel("grid power : ");
	grid_V_label = new QLabel("grid voltage : ");
	grid_F_label = new QLabel("grid frequency : ");
	panel_P_label = new QLabel("panel power : ");
	panel_V_label = new QLabel("panel voltage : ");
	panel_I_label = new QLabel("panel current : ");
	home_P_label = new QLabel("home power : ");
	home_id_label = new QLabel("house id : ");

	status = new QPushButton("status");
	save = new QPushButton("save");
}

void QtManger::label_setup_first_window()
{
	add_layout(50, grid_P_box, grid_P_label, 0);
	add_layout(50, grid_V_box, grid_V_label, 1);
	add_layout(50, grid_F_box, grid_F_label, 2);
	add_layout(50, panel_P_box, panel_P_label, 3);
	add_layout(50, panel_V_box, panel_V_label, 4);
	add_layout(50, panel_I_box, panel_I_label, 5);
	add_layout(50, home_P_box, home_P_label, 6);
	add_layout(50, home_id_box, home_id_label, 7);
}

void QtManger::add_layout(int spacing, QLineEdit* box, QLabel* label,int index)
{
	rowLayout[index]->setSpacing(50);
	rowLayout[index]->addWidget(label);
	rowLayout[index]->addWidget(box);
	mainLayout->addLayout(rowLayout[index].get());
}

bool QtManger::validate_all_input()
{
	return false;
}

void QtManger::start_ui()
{
	firstWindows->show();
}

void QtManger::status_pressed()
{
	printf("Logged in %s \n", grid_P_box->text().toStdString().c_str());
	printf("Password  %s \n", grid_V_box->text().toStdString().c_str());
}

void QtManger::save_pressed()
{
	auto ret = QMessageBox::critical(firstWindows, "Error", "the document is modified \n do you want to save ? ");
}

void QtManger::load_pressed()
{
}
