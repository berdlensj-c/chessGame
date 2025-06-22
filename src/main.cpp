#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    std::cout << "Creating window..." << std::endl;
    std::flush(std::cout);

    sf::RenderWindow window(sf::VideoMode(1250, 800), "SFML Chess Window");

    if (!window.isOpen()) {
        std::cout << "Failed to create window!" << std::endl;
        std::flush(std::cout);
        std::cin.get();
        return -1;
    }

    std::cout << "Window created successfully. Starting main loop..." << std::endl;
    std::flush(std::cout);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({100.f, 100.f});

    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            std::cout << "Event received" << std::endl;

            if (event.type == sf::Event::Closed) {
                std::cout << "Close event received" << std::endl;
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }

    std::cout << "Window closed. Exiting..." << std::endl;
    return 0;
}
