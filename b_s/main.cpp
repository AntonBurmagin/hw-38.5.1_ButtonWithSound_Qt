#include "mainwindow.h"
#include <QPushButton>
#include <QSlider>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QApplication>
#include <QMediaPlayer>

class MyButton : public QPushButton {
    Q_OBJECT
private:
    QPixmap currentMyButton;
    QPixmap upMyButton;
    QPixmap downMyButton;
    bool isUp = true;
    QMediaPlayer playerPushDown;
    QMediaPlayer playerPushUp;
public:
    void paintEvent (QPaintEvent *e) override {
            QPainter p(this);
            p.drawPixmap(e->rect(), currentMyButton);
        };
    MyButton() = default;
    MyButton(QWidget *parent) {
        setParent(parent);
        upMyButton = QPixmap("..\\button_up.png");
        downMyButton = QPixmap("..\\button_down.png");
        currentMyButton = upMyButton;
        setGeometry(currentMyButton.rect());
        playerPushDown.setMedia(QUrl::fromLocalFile("..\\golos-knopka.mp3"));
        playerPushUp.setMedia(QUrl::fromLocalFile("..\\tel.mp3"));
        connect(this, &QPushButton::clicked, this,[this]() {
            playerPushDown.stop();
            playerPushUp.stop();
            if(isUp) {
                currentMyButton = downMyButton;
                isUp=false;
                playerPushDown.play();
            } else {
                currentMyButton = upMyButton;
                isUp=true;
                playerPushUp.play();
            }
        });
    };


};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyButton button (nullptr);
    button.move(500, 200);
    button.resize(300, 300);
    button.show();
    return a.exec();
}

#include "main.moc"
