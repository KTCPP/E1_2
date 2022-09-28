#include <iostream>

using std::ostream;

struct Basis {
    int virtual wert() const { return 0; }
    ostream& drucken(ostream& os) {
        return os << wert() << "\n";
    }
    ostream& operator<<(ostream& left) {
        std::cout << "inside" << std::endl;
        return this->drucken(left);
    }
};

ostream& operator<<(ostream& left, Basis& right) {
    std::cout << "outside" << std::endl;
    return right.drucken(left);
}
struct Wert : public Basis {
    // Überschreibt wert() der Oberklasse Basis
    int wert() const override { return 10; }
};

int main() {
    Basis basis{};
    Wert kind{};
    std::cout << basis;
    std::cout << kind;
    // in der Klasse definierte Funktion erzeugt ungewohnte Syntax
    basis << std::cout;
    kind << std::cout;
}