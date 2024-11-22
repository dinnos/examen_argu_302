#include <iostream>

#define GRAVITY 9.81

int calculate_radius(const int min_radius, const int max_radius) {
    return static_cast<int>(random()) %(max_radius-min_radius+1)+min_radius;
}

/**
 *
 * @param friction Coeficiente de fricción
 * @param radius Radio de la curva
 * @return Velocidad maxima a la que se puede tomar la curva
 */
double calculate_max_speed(const double friction, const double radius) {
    return sqrt(friction * GRAVITY * radius);
}

int main() {
    std::cout << "Bienvenido al juego de derrape    s!" << std::endl;
    std::cout << "En este juego tomaras el papel de un piloto de F1 que debe decidir a que velocidad entrar a una curva en este caso te enfrentaras a curvas con un radio entre 50-100 metros, en el caso de fallar 3 veces perderas por el contrario si consigues superar 10 curvas abras ganado" << std::endl;
    std::cout << "Vale comencemos" << std::endl;

    constexpr auto MIN_FRICTION = 0.2;
    constexpr auto MAX_FRICTION = 0.6;

    auto fail_count = 0;
    auto success_count = 0;
    const auto friction = (MIN_FRICTION + 1) + (static_cast<double>(random()) / static_cast<double>(RAND_MAX)) * (MAX_FRICTION - (MIN_FRICTION + 1));

    double speed;

    do {
        const auto radius = calculate_radius(50, 100);

        std::cout << "Configuración de la curva: " << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Coeficiente de fricción: " << friction << std::endl;

        std::cout << "A qué velocidad quieres intentar la curva: ";
        std::cin >> speed;

        const auto max_speed = calculate_max_speed(friction, radius);

        std::cout << "Speed: " << speed << std::endl;
        std::cout << "Max speed: " << max_speed << std::endl;

        if (speed <= max_speed) {
            success_count++;

            std::cout << "Haz tomado la curva a una velocidad de: " << speed << std::endl;
        } else {
            fail_count++;

            std::cout << "Fallaste al tomar la curva a una velocidad de: " << speed << std::endl;
        }
    } while (fail_count != 3 && success_count != 10);

    if (fail_count == 3) {
        std::cout << "GAME OVER" << std::endl;

        return -1;
    }

    std::cout << "Felicidades!!! Haz logrado completar el reto" << std::endl;

    return 0;
}
