#include <SFML/Graphics.hpp>



int main() {
    sf::RenderWindow window(sf::VideoMode(1300, 1000), "Shooter Tycoon");
    sf::Texture background;
    sf::Sprite applybg;
	sf::Texture button;
	sf::Sprite buttonapply;
    sf::Font font;
    sf::Text gametext;
	sf::Vector2u buttonsize = button.getSize();
    bool PlayButtonNotPressed = true;
	bool isButtonHovered = false;
    
	
    gametext.setFont(font);
    gametext.setString("Shooter Tycoon");
    gametext.setCharacterSize(70);
    gametext.setFillColor(sf::Color::White);
    gametext.setPosition(150, 250);
	font.loadFromFile("C:/Users/YourUsername/source/repos/Project3/x64/Debug/PressStart2P-Regular.ttf");
    background.loadFromFile("C:/Users/YourUsername/source/repos/Project3/x64/Debug/background.jpg");
    button.loadFromFile("C:/Users/YourUsername/source/repos/Project3/x64/Debug/button.jpg");
    buttonapply.setScale(0.5f, 0.5f);
      // makes it twice as big
	buttonapply.setTexture(button);
	buttonapply.setPosition(500, 500);
    
    
    applybg.setTexture(background);
    applybg.setScale(
        window.getSize().x / static_cast<float>(background.getSize().x),
        window.getSize().y / static_cast<float>(background.getSize().y)
    );
    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        // Reset hover every frame
        isButtonHovered = false;

        if (buttonapply.getGlobalBounds().contains(mousePos.x, mousePos.y))
            isButtonHovered = true;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left)
            {
                if (isButtonHovered)
                    PlayButtonNotPressed = false;
            }
        }

        window.clear();

        window.draw(applybg);

        if (PlayButtonNotPressed) {
            window.draw(gametext);
            window.draw(buttonapply);
        }

        window.display();
    }

    return 0;
}
