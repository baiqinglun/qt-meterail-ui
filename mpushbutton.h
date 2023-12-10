#ifndef MPUSHBUTTON_H
#define MPUSHBUTTON_H
#include <QPushButton>
#include <QFile>
#include <QMap>
#include <QDebug>
#include <QFontDatabase>

enum class BtnType
{
    text,
    fill,
    hollow
};

class MPushButton : public QPushButton
{
    Q_OBJECT
public:
    MPushButton(const BtnType btnType,const QString &text, QWidget *parent = nullptr);
    MPushButton(const BtnType btnType,const QString &text,const QString size = "small",const QString bg_color = "red",QWidget *parent = nullptr);
    void setSheet();
    void readFontFamily();
    void setColor(const QString &color,const QString &hover_color,const QString &pressed_bg_color);
    void setColor(const QString &color);
    QString getColorOrDefault(const QString &color, const QMap<QString, QString> &colorMap, const QString &defaultColor) const;

private:
    BtnType btnType_ = BtnType::fill;
    int height_ = 30;
    QString bg_color_ = "#1976d2";
    QString text_color_ = "#ffffff";
    QString hover_bg_color_ = "#1565c0";
    QString pressed_bg_color_ = "#b4d2f0";
    QString main_color_ = "#1976d2";
    QString main_hover_color_ = "#1565c0";
    QString main_pressed_color_ = "#b4d2f0";

    QMap<QString, QString> bg_colors {
        {"red", "#d63e3e"},
        {"green", "#2e7d32"},
        {"purple", "#a438b6"},
        {"blue", "#1976d2"}
    };
    QMap<QString, QString> hover_bg_colors {
        {"red", "#d32f2f"},
        {"green", "#1b5e20"},
        {"purple", "#7b1fa2"},
        {"blue", "#1565c0"}
    };
    QMap<QString, QString> pressed_bg_colors {
        {"red", "#f0baba"},
        {"green", "#608f63"},
        {"purple", "#deb8e5"},
        {"blue", "#b4d2f0"}
    };
    QMap<QString,int> sizes{
        {"small",30},
        {"medium",35},
        {"big",40},
    };
};

#endif // MPUSHBUTTON_H
