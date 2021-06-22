#ifndef WIDGET_H
#define WIDGET_H

#include <QScrollArea>
#include <QMetaType>
#include <QSpinBox>
#include <QCheckBox>
#include <QComboBox>
#include <QLabel>
#include <QPushButton>

enum PlayerClass {
    NO_TYPES = 0,
    WEAPON = 1,
    CHARACTER = 2
};

struct S_P2D_Coord {
    Q_GADGET
    Q_PROPERTY(float x MEMBER x)
    Q_PROPERTY(float y MEMBER y)

public:
    float x;
    float y;
};

struct Player {
    Q_GADGET
    Q_PROPERTY(PlayerClass playerClass MEMBER playerClass)
    Q_PROPERTY(float speed MEMBER speed)
    Q_PROPERTY(unsigned short ammo MEMBER ammo)
    Q_PROPERTY(bool is_active MEMBER is_active)
    Q_PROPERTY(unsigned char numberAccumulationOfCoord MEMBER numberAccumulationOfCoord)
    Q_PROPERTY(S_P2D_Coord* S_P2D_Coord MEMBER pP2DCoord)

public:
    PlayerClass playerClass;
    float speed;
    unsigned short ammo;
    bool is_active;
    unsigned char numberAccumulationOfCoord;
    S_P2D_Coord* pP2DCoord;
};
Q_DECLARE_METATYPE(Player)

class Widget : public QScrollArea
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QComboBox* m_PlayerClassItemSelected;
    QDoubleSpinBox* m_SpeedSpinBox;
    QSpinBox* m_AmmoSpinBox;
    QCheckBox* m_ActivatedCheckBox;
    QSpinBox* m_CoordnatesSpinBox;
    QDoubleSpinBox* m_ArrayGeneratorX;
    QDoubleSpinBox* m_ArrayGeneratorY;
    QPushButton* arraysButtonsClosed;
};
#endif // WIDGET_H
