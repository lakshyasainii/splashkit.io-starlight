#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

// for generating a random color
sf::Color generate_random_color()
{
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;
    return sf::Color(red, green, blue);
}

int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // for creating window
    sf::RenderWindow render_window(sf::VideoMode(800, 600), "Triangle Display - Beyond SplashKit");

    std::vector<sf::ConvexShape> triangle_list;

    for (int index = 0; index < 20; ++index)
    {
        float offset_x = index * 40.f;

        sf::ConvexShape triangle_shape;
        triangle_shape.setPointCount(3);
        triangle_shape.setPoint(0, sf::Vector2f(offset_x, 0));
        triangle_shape.setPoint(1, sf::Vector2f(offset_x + 20, 40));
        triangle_shape.setPoint(2, sf::Vector2f(offset_x + 40, 0));
        triangle_shape.setFillColor(generate_random_color());

        triangle_list.push_back(triangle_shape);
    }

    // for drawing everything one time
    render_window.clear(sf::Color::White);
    for (const auto& shape : triangle_list)
    {
        render_window.draw(shape);
    }
    render_window.display();

    sf::sleep(sf::seconds(6));

    return 0;
}
