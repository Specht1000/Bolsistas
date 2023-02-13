#include "Aplicacao.hpp"

int main() {
	Aplicacao *app;
	app = new Aplicacao();
    app->inicializarMenu();
	delete app;
    return 0;
}

