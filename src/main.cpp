#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //constants for the board to be able to easily change the size and placement
    const int squareX = 350;
    const int squareY = 50;
    const int squareSize = 80;
    int boardx=squareX;
    int boardy=squareY;
    sf::RectangleShape board [8][8];


    sf::RenderWindow window(sf::VideoMode(1250, 800), "SFML Chess Window");
    

    if (!window.isOpen()) {
        std::cout << "Failed to create window!" << std::endl;
        std::cin.get();
        return -1;
    }

    std::cout << "Window created successfully. Starting main loop..." << std::endl;
    


    sf::Event event;
    while (window.isOpen())
    {
        //where all events will take place 
        while (window.pollEvent(event))
        {
          
            if (event.type == sf::Event::Closed) {
                std::cout << "Close event received" << std::endl;
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        
        //making and drawing the board 
        for(int i =0; i<8; i++){
            boardx = squareX;
            boardy = squareY + i * squareSize;
            for(int j=0; j<8; j++){
                board[i][j].setSize(sf::Vector2f(squareSize,squareSize));
                board[i][j].setPosition(boardx,boardy);

                if(i%2==0){    
                    if(j%2==0){
                        board[i][j].setFillColor(sf::Color::Green);            
                    }
                }else{
                    if(!(j%2==0)){
                        board[i][j].setFillColor(sf::Color::Green);            
                    }
                }

                boardx += squareSize;
                window.draw(board[i][j]);
            }
            
        }

        
        window.display();
    }

    std::cout << "Window closed. Exiting..." << std::endl;
    return 0;
}
