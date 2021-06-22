#include "widget.h"

#include <QFormLayout>
#include <QString>

Widget::Widget(QWidget *parent)
    : QScrollArea(parent)
{
    qRegisterMetaType<Player>();

    m_PlayerClassItemSelected = new QComboBox(this);
    m_PlayerClassItemSelected->addItem(tr("No Class"));
    m_PlayerClassItemSelected->addItem(tr("Weapon Class"));
    m_PlayerClassItemSelected->addItem(tr("Character Class"));
    m_PlayerClassItemSelected->addItem(tr("Vehicle Class"));

    m_SpeedSpinBox = new QDoubleSpinBox(this);
    m_SpeedSpinBox->setMinimum(0.0);
    m_SpeedSpinBox->setMaximum(100.0);
    m_SpeedSpinBox->setRange(m_SpeedSpinBox->minimum(), m_SpeedSpinBox->maximum());
    m_SpeedSpinBox->setValue(5);

    m_AmmoSpinBox = new QSpinBox(this);
    m_AmmoSpinBox->setMinimum(0);
    m_AmmoSpinBox->setMaximum(255);
    m_AmmoSpinBox->setRange(m_AmmoSpinBox->minimum(), m_AmmoSpinBox->maximum());
    m_AmmoSpinBox->setValue(10);

    m_ActivatedCheckBox = new QCheckBox(this);
    m_ActivatedCheckBox->setCheckable(true);
    m_ActivatedCheckBox->setChecked(true);

    m_CoordnatesSpinBox = new QSpinBox(this);
    m_CoordnatesSpinBox->setMinimum(0);
    m_CoordnatesSpinBox->setMaximum(10);
    m_CoordnatesSpinBox->setRange(m_CoordnatesSpinBox->minimum(), m_CoordnatesSpinBox->maximum());

    QFormLayout* form_layout = new QFormLayout;
    form_layout->addRow(tr("Player Classes"), m_PlayerClassItemSelected);
    form_layout->addRow(tr("Speed Object"), m_SpeedSpinBox);
    form_layout->addRow(tr("Ammo count"), m_AmmoSpinBox);
    form_layout->addRow(tr("Is active ?"), m_ActivatedCheckBox);
    form_layout->addRow(tr("Counter number of arrays"), m_CoordnatesSpinBox);

    connect(m_CoordnatesSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [=](int d) {

        for(int it=0; it < m_CoordnatesSpinBox->value(); it++) {
            QFormLayout* arrays_xy = new QFormLayout;
            QFormLayout* from_arrays = new QFormLayout;

            m_ArrayGeneratorX = new QDoubleSpinBox(this);
            m_ArrayGeneratorY = new QDoubleSpinBox(this);
            arraysButtonsClosed = new QPushButton(this);
            arraysButtonsClosed->setText("X");

            if(~m_CoordnatesSpinBox->value()) {
                connect(arraysButtonsClosed, &QPushButton::clicked, this, [=]() {
                    from_arrays->removeRow(arrays_xy);
                    form_layout->removeRow(from_arrays);
                });
            }

            arrays_xy->addRow(tr("X"), m_ArrayGeneratorX);
            arrays_xy->addRow(tr("Y"), m_ArrayGeneratorY);
            arrays_xy->addRow(tr("Close"), arraysButtonsClosed);

            from_arrays->addRow(tr("Coordinate"), arrays_xy);
            form_layout->addRow(tr("Number coordinates arrays"), from_arrays);
        }
    });

    setWindowTitle(tr("Qmob Solution - Test for position application - By Diogo Rodrigues Roessler"));
    setGeometry(0, 0, 500, 600);
    setLayout(form_layout);
}

Widget::~Widget()
{
}
