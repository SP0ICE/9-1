#include <QApplication>
#include <QMainWindow>
#include <QTimer>
#include <QVBoxLayout>
#include <QLabel>

class TimerWindow : public QMainWindow {
public:
    TimerWindow(QWidget *parent = nullptr)
        : QMainWindow(parent), m_seconds(0)
    {
        setWindowTitle("Timer Example");

        QWidget *centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);

        QVBoxLayout *layout = new QVBoxLayout(centralWidget);

        QLabel *label = new QLabel("Elapsed Time:", centralWidget);
        layout->addWidget(label);

        m_timeLabel = new QLabel("0", centralWidget);
        m_timeLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        layout->addWidget(m_timeLabel);

        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &TimerWindow::updateTimer);
        timer->start(1000); // 1 second interval
    }

private:
    QLabel *m_timeLabel;
    int m_seconds;

    void updateTimer() {
        m_seconds++;
        m_timeLabel->setText(QString::number(m_seconds));
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TimerWindow window;
    window.show();

    return app.exec();
}
