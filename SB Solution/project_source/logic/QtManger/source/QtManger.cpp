#include "QtManger.h"

QtManger::QtManger()
{
	initial_members();
	setup_first_windows();
	connect_all_signals();
}

void QtManger::connect_all_signals()
{
	QWidget::connect(save.get(), &QPushButton::clicked, this, &QtManger::save_pressed);
	QWidget::connect(status.get(), &QPushButton::clicked, this, &QtManger::status_pressed);
}

void QtManger::setup_first_windows()
{
	firstWindows = std::make_unique<QWidget>(nullptr);
	firstWindows->setWindowTitle("Sonnen Battary System");
	firstWindows->setFixedSize(500, 800);
	firstWindows->setLayout(mainLayout.get());
	label_setup_first_window();
	//  save button and status button setup
	rowLayout[cButtonLayoutId]->addWidget(status.get());
	rowLayout[cButtonLayoutId]->addWidget(save.get());
	mainLayout->addLayout(rowLayout[cButtonLayoutId].get());
}

void QtManger::setup_second_windows()
{
	// TODO: 
}

void QtManger::initial_members()
{
	for (int i = 0; i < _MAX_LAYOUT_NUMB; ++i)
	{
		rowLayout.push_back(std::make_unique<QHBoxLayout>());
	}
	mainLayout = std::make_unique<QVBoxLayout>();

	home_P_box = std::make_unique<QLineEdit>();
	panel_P_box = std::make_unique<QLineEdit>();
	home_id_box = std::make_unique<QLineEdit>();
	pv_power_production_box = std::make_unique<QLineEdit>();
	recommended_setup_box = std::make_unique<QLineEdit>();
	batteries_status_box = std::make_unique<QLineEdit>();
	grid_power_box = std::make_unique<QLineEdit>();

	home_P_label = std::make_unique<QLabel>("home power        : ");
	panel_P_label = std::make_unique<QLabel>("panel power       : ");
	home_id_label = std::make_unique<QLabel>("home id           : ");
	setup_type_label = std::make_unique<QLabel>("setup type        : ");
	pv_power_production_label = std::make_unique<QLabel>("pv power          : ");
	recommended_setup_label = std::make_unique<QLabel>("recommended setup : ");
	batteries_status_label = std::make_unique<QLabel>("batteries status  : ");
	grid_power_label = std::make_unique<QLabel>("grid power       : ");

	basic = std::make_unique<QCheckBox>("basic",firstWindows.get());
	stander = std::make_unique<QCheckBox>("stander",firstWindows.get());
	pro = std::make_unique<QCheckBox>("pro",firstWindows.get());

	status = std::make_unique<QPushButton>("status");
	save = std::make_unique<QPushButton>("save");

}

void QtManger::label_setup_first_window()
{
	add_layout(50, home_id_box.get(), home_id_label.get(), 0);
	add_layout(50, home_P_box.get(), home_P_label.get(), 1);
	add_layout(50, panel_P_box.get(), panel_P_label.get(), 2);


	rowLayout[3]->setSpacing(50);
	rowLayout[3]->addWidget(setup_type_label.get());
	rowLayout[3]->addWidget(basic.get());
	rowLayout[3]->addWidget(stander.get());
	rowLayout[3]->addWidget(pro.get());
	mainLayout->addLayout(rowLayout[3].get());

	add_layout(50, pv_power_production_box.get(), pv_power_production_label.get(), 4);
	add_layout(50, recommended_setup_box.get(), recommended_setup_label.get(), 5);
	add_layout(50, batteries_status_box.get(), batteries_status_label.get(), 6);
	add_layout(50, grid_power_box.get(), grid_power_label.get(), 7);
}

void QtManger::add_layout(int spacing, QLineEdit* box, QLabel* label, int index)
{
	rowLayout[index]->setSpacing(spacing);
	rowLayout[index]->addWidget(label);
	rowLayout[index]->addWidget(box);
	mainLayout->addLayout(rowLayout[index].get());
}

bool QtManger::validate_all_input()
{
	int numberOfCheckedBoxes = 0;

	if (basic->isChecked())numberOfCheckedBoxes++;
	if (stander->isChecked())numberOfCheckedBoxes++;
	if (pro->isChecked())numberOfCheckedBoxes++;

	if(home_P_box->text().isEmpty() ||panel_P_box->text().isEmpty() || 
		home_id_box->text().isEmpty() || numberOfCheckedBoxes != 1)
	{
		auto ret = QMessageBox::critical(firstWindows.get(), "Error",
			"some labels is still empty.",QMessageBox::Cancel);
		return false;
	}
	return true;
}

void QtManger::status_pressed()
{
	auto flag = validate_all_input();
	if (!flag)
		return;
	/*
	* calculate number_of_batteries
	*/
	float home_power;
	float panel_power;
	int number_of_batteries;
	if (basic->isChecked())number_of_batteries=2;
	if (stander->isChecked())number_of_batteries=3;
	if (pro->isChecked())number_of_batteries=5;

	/**/
	home_power = home_P_box->text().toInt();
	panel_power = panel_P_box->text().toInt();
	sonnenSystem = std::make_unique<SonnenBS>(home_power,panel_power,number_of_batteries);
	
	/**/
	pv_power_production_box->setText(sonnenSystem->GetPVPowerProduction());
	recommended_setup_box->setText(sonnenSystem->GetSonnenSystemRecommendedType());
	grid_power_box->setText(sonnenSystem->GetGridPower());
	batteries_status_box->setText(sonnenSystem->GetStorageState());


}

void QtManger::save_pressed()
{
	validate_all_input();
}

void QtManger::start_ui()
{
	firstWindows->show();
}

void QtManger::load_pressed()
{
	// TODO:
}