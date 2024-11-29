/*
* date: 11/2024
* auth: ahmed abelrazik
* obje: QT manger
* docu: handle all qt feature
*/

#ifndef QTMANGER_H
#define QTMANGER_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLine>
#include <QVBoxLayout>
#include <memory>
#include "sonnen_bs.h"
#include "common_definition.h"
//#include "data_manger.h"

class QtManger : public QWidget
{

public:
	/*
	* initialization
	*/
	QtManger();
	void connect_all_signals();
	void start_ui();

	/*
	* buttons clicked
	*/
	void status_pressed();
	void save_pressed();
	void load_pressed();

	/*
	* setup windows
	*/
	void setup_first_windows();
	void setup_second_windows();

	/*
	* helper functions
	*/
	void initial_members();
	void label_setup_first_window();
	void add_layout(int spacing, QLineEdit* box, QLabel* label, int index);
	bool validate_all_input();

private:
	/*
	* layout
	*/
	std::unique_ptr <QVBoxLayout> mainLayout;
	std::vector<std::unique_ptr<QHBoxLayout>> rowLayout;

	/*
	* labels
	* p -> power
	* v -> voltage
	* f -> frequency
	* i -> Current
	*/
	std::unique_ptr<QLabel> panel_P_label;
	std::unique_ptr<QLabel> home_P_label;
	std::unique_ptr<QLabel> home_id_label;
	std::unique_ptr<QLabel> setup_type_label;
	std::unique_ptr<QLabel> pv_power_production_label;
	std::unique_ptr<QLabel> recommended_setup_label;
	std::unique_ptr<QLabel> batteries_status_label;
	std::unique_ptr<QLabel> grid_power_label;

	/*
	* mangers
	*/
	std::shared_ptr<SonnenBS> system_manger;
	std::shared_ptr<SonnenBS> data_manger;

	/*
	* boxes
	*/
	std::unique_ptr<QLineEdit> panel_P_box;
	std::unique_ptr<QLineEdit> home_P_box;
	std::unique_ptr<QLineEdit> home_id_box;
	std::unique_ptr<QLineEdit> setup_type_box;
	std::unique_ptr<QLineEdit> pv_power_production_box;
	std::unique_ptr<QLineEdit> recommended_setup_box;
	std::unique_ptr<QLineEdit> batteries_status_box;
	std::unique_ptr<QLineEdit> grid_power_box;

	/*
	* buttons
	*/
	std::unique_ptr<QPushButton> status;
	std::unique_ptr<QPushButton> save;
	std::unique_ptr<QPushButton> load;

	/*
	* check box
	*/
	std::unique_ptr<QCheckBox> basic;
	std::unique_ptr<QCheckBox> stander;
	std::unique_ptr<QCheckBox> pro;


	/*
	* windows
	*/
	std::unique_ptr<QWidget> firstWindows;
	std::unique_ptr<QWidget> secondWindows;

	/*
	* sonnen system
	*/
	std::unique_ptr<SonnenBS> sonnenSystem;
};
#endif //QTMANGER_H