#ifndef GLOBALUI_H
#define GLOBALUI_H

#include <QLabel>


class QDoubleClickebleLabel : public QLabel
{
    Q_OBJECT
public:
    QDoubleClickebleLabel(QWidget* parent=  nullptr);
protected:
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
public:
signals:
    void sig_labelDoubleClicked();
};

#endif // GLOBALUI_H
