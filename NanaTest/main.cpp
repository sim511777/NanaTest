#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>

using namespace nana;
class MyForm : public form {
private:
    label lab;
    button btn;
    void InitializeComponents() {
        lab.create(*this);
        lab.caption("Hello, <bold blue size=16>Nana C++ Library</>");
        lab.format(true);

        btn.create(*this);
        btn.caption("Quit");
        btn.events().click([this] {
            this->close();
            });

        this->div("vert <><<><weight=80% text><>><><weight=24<><button><>><>");
        (*this)["text"] << lab;
        (*this)["button"] << btn;
        this->collocate();
    }
public:
    MyForm() {
        InitializeComponents();
    }
};

int main() {
    MyForm fm;
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();
}