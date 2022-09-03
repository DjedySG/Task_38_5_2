#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget mainWindow;

    auto* htmlText = new QTextEdit(&mainWindow);
    htmlText->setReadOnly(false);
    htmlText->setPlainText("<HTML>"
        "<BODY BGCOLOR=GREY>"
        "<H2><CENTER>Skillbox Task 38_5_2 </CENTER></H2>"

        "<FONT COLOR=WHITE>"
        "<P ALIGN=\"center\">"
        "<I>"
        "CPP and How I destroy my life<BR>"
        "Can Ichoose another language?<BR>"
        "Why I choose that language?<BR>"
        "I will go in QA<BR><BR>"
        "</I>"
        "</P>"
        "</FONT>"
        "</BODY>"
        "</HTML>"
    );

    auto* simpleText = new QTextEdit(&mainWindow);
    simpleText->setHtml(htmlText->toPlainText());

    auto* hBox = new QHBoxLayout(&mainWindow);
    hBox->addWidget(htmlText);
    hBox->addWidget(simpleText);

    QObject::connect(htmlText, &QTextEdit::textChanged, [&htmlText, &simpleText]() {
        simpleText->setHtml(htmlText->toPlainText());
        });

    mainWindow.resize(800, 400);
    mainWindow.show();

    return a.exec();
}
