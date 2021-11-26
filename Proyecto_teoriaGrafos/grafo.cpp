#include "grafo.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "circulo.h"
#include <sstream>
#include <string>

using namespace std;

grafo::grafo(Cset vr, Cset er) : stv(vr), ste(er)
{
    //Este es pos 0 no lo tomo en cuenta
    vertices.push_back(new arista(2, new circulo(2)));

    vertices.push_back(new arista(2, new circulo(2)));
    arista *tmp = new arista(1, new circulo(3));
    vertices[1]->next = tmp;
    vertices.push_back(new arista(1, new circulo(4)));
    vertices.push_back(new arista(3, new circulo(4)));
    vertices[3]->next = new arista(4, new circulo(5));
    vertices.push_back(new arista(2, new circulo(6)));
    vertices.push_back(new arista(2, new circulo(6)));
    e.distancia = 0;
    d.distancia = 0;
}

grafo::~grafo()
{
    //dtor
}

void grafo::graf()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Grafo Visual");
    sf::Texture txtFondo;
    sf::Sprite spFondo;

    //Hago mi objeto fuente
    sf::Font fuente;
    fuente.loadFromFile("arial.ttf");
    //Hago las TextPosition

    sf::Text txtPosicion;
    txtPosicion.setCharacterSize(50);
    txtPosicion.setFont(fuente);
    txtPosicion.setColor(sf::Color::White);
    txtPosicion.setStyle(sf::Text::Bold);
    txtPosicion.setString("1");

    sf::Text txtPosicion2;
    txtPosicion2.setCharacterSize(50);
    txtPosicion2.setFont(fuente);
    txtPosicion2.setColor(sf::Color::White);
    txtPosicion2.setStyle(sf::Text::Bold);
    txtPosicion2.setString("2");

    sf::Text txtPosicion3;
    txtPosicion3.setCharacterSize(50);
    txtPosicion3.setFont(fuente);
    txtPosicion3.setColor(sf::Color::White);
    txtPosicion3.setStyle(sf::Text::Bold);
    txtPosicion3.setString("4");

    sf::Text txtPosicion4;
    txtPosicion4.setCharacterSize(50);
    txtPosicion4.setFont(fuente);
    txtPosicion4.setColor(sf::Color::White);
    txtPosicion4.setStyle(sf::Text::Bold);
    txtPosicion4.setString("6");

    sf::Text txtPosicion5;
    txtPosicion5.setCharacterSize(50);
    txtPosicion5.setFont(fuente);
    txtPosicion5.setColor(sf::Color::White);
    txtPosicion5.setStyle(sf::Text::Bold);
    txtPosicion5.setString("3");

    sf::Text txtPosicion6;
    txtPosicion6.setCharacterSize(50);
    txtPosicion6.setFont(fuente);
    txtPosicion6.setColor(sf::Color::White);
    txtPosicion6.setStyle(sf::Text::Bold);
    txtPosicion6.setString("5");

    //Hago mi fondo blanco
    txtFondo.loadFromFile("fondo.jpg");
    spFondo.setTexture(txtFondo);

    //Creo los vertices visuales
    sf::CircleShape shape(70.f);
    shape.setFillColor(sf::Color::Black);
    shape.setPosition(300, 380);
    txtPosicion.setPosition(300 + 50, 380 + 40);
    //Creacion de arista
    sf::RectangleShape rectangulo1(sf::Vector2f(350, 10));
    rectangulo1.rotate(-40);
    rectangulo1.setPosition(420, 420);
    rectangulo1.setFillColor(sf::Color::Black);

    sf::Text txtPeso1;
    txtPeso1.setCharacterSize(50);
    txtPeso1.setFont(fuente);
    txtPeso1.setColor(sf::Color::Black);
    txtPeso1.setStyle(sf::Text::Bold);
    txtPeso1.setString("2");
    txtPeso1.rotate(-40);
    txtPeso1.setPosition(480, 260);

    sf::RectangleShape rectangulo4(sf::Vector2f(310, 10));
    rectangulo4.rotate(60);
    rectangulo4.setPosition(420, 420);
    rectangulo4.setFillColor(sf::Color::Black);

    sf::Text txtPeso2;
    txtPeso2.setCharacterSize(50);
    txtPeso2.setFont(fuente);
    txtPeso2.setColor(sf::Color::Black);
    txtPeso2.setStyle(sf::Text::Bold);
    txtPeso2.setString("1");
    txtPeso2.rotate(rectangulo4.getRotation());
    txtPeso2.setPosition(570, 510);

    //Verice 2
    sf::CircleShape shape2(70.f);
    shape2.setFillColor(sf::Color::Black);
    shape2.setPosition(700, 100);
    txtPosicion2.setPosition(700 + 50, 100 + 40);
    //Aristas
    sf::RectangleShape rectangulo2(sf::Vector2f(300, 10));
    rectangulo2.rotate(10);
    rectangulo2.setPosition(800, 140);
    rectangulo2.setFillColor(sf::Color::Black);

    sf::Text txtPeso3;
    txtPeso3.setCharacterSize(50);
    txtPeso3.setFont(fuente);
    txtPeso3.setColor(sf::Color::Black);
    txtPeso3.setStyle(sf::Text::Bold);
    txtPeso3.setString("1");
    txtPeso3.rotate(rectangulo2.getRotation());
    txtPeso3.setPosition(950, 110);

    //Vertice 4
    sf::CircleShape shape3(70.f);
    shape3.setFillColor(sf::Color::Black);
    shape3.setPosition(1100, 150);
    txtPosicion3.setPosition(1100 + 50, 150 + 40);
    //Aristas
    sf::RectangleShape rectangulo3(sf::Vector2f(440, 10));
    rectangulo3.rotate(38);
    rectangulo3.setPosition(1180, 180);
    rectangulo3.setFillColor(sf::Color::Black);

    sf::Text txtPeso4;
    txtPeso4.setCharacterSize(50);
    txtPeso4.setFont(fuente);
    txtPeso4.setColor(sf::Color::Black);
    txtPeso4.setStyle(sf::Text::Bold);
    txtPeso4.setString("2");
    txtPeso4.rotate(rectangulo3.getRotation());
    txtPeso4.setPosition(1400, 240);

    //Vertice 6 el cual no tiene arista
    sf::CircleShape shape4(70.f);
    shape4.setFillColor(sf::Color::Black);
    shape4.setPosition(1500, 450);
    txtPosicion4.setPosition(1500 + 50, 450 + 40);
    //Arista

    //vERTICE 3
    sf::CircleShape shape5(70.f);
    shape5.setFillColor(sf::Color::Black);
    shape5.setPosition(500, 700);
    txtPosicion5.setPosition(500 + 50, 700 + 40);

    //AriSTA
    sf::RectangleShape rectangulo5(sf::Vector2f(680, 10));
    rectangulo5.rotate(-43);
    rectangulo5.setPosition(620, 740);
    rectangulo5.setFillColor(sf::Color::Black);

    sf::Text txtPeso5;
    txtPeso5.setCharacterSize(50);
    txtPeso5.setFont(fuente);
    txtPeso5.setColor(sf::Color::Black);
    txtPeso5.setStyle(sf::Text::Bold);
    txtPeso5.setString("4");
    txtPeso5.setPosition(770, 660);

    sf::RectangleShape rectangulo6(sf::Vector2f(360, 10));
    rectangulo6.rotate(-6);
    rectangulo6.setPosition(620, 740);
    rectangulo6.setFillColor(sf::Color::Black);

    sf::Text txtPeso7;
    txtPeso7.setCharacterSize(50);
    txtPeso7.setFont(fuente);
    txtPeso7.setColor(sf::Color::Black);
    txtPeso7.setStyle(sf::Text::Bold);
    txtPeso7.setString("3");
    txtPeso7.setPosition(850, 400);

    //Vertice 5
    sf::CircleShape shape6(70.f);
    shape6.setFillColor(sf::Color::Black);
    shape6.setPosition(1000, 650);
    txtPosicion6.setPosition(1000 + 50, 650 + 40);

    sf::RectangleShape rectangulo7(sf::Vector2f(450, 10));
    rectangulo7.rotate(-17);
    rectangulo7.setPosition(1070, 690);
    rectangulo7.setFillColor(sf::Color::Black);

    sf::Text txtPeso6;
    txtPeso6.setCharacterSize(50);
    txtPeso6.setFont(fuente);
    txtPeso6.setColor(sf::Color::Black);
    txtPeso6.setStyle(sf::Text::Bold);
    txtPeso6.setString("2");
    txtPeso6.rotate(rectangulo7.getRotation());
    txtPeso6.setPosition(1270, 570);

    sf::Text txt;
    txt.setCharacterSize(50);
    txt.setFont(fuente);
    txt.setColor(sf::Color::Black);
    txt.setStyle(sf::Text::Bold);
    txt.setPosition(650, 810);

    string p = "";
    string mayor2 = "";
    string menor = "";
    int m=0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                int num1, num2;

                num1 = 1;
                num2 = 5;

                dijkstra(num1, num2);
                stringstream stream;
                string cadena = "";
                stream << d.ruta[0];
                cadena = stream.str();
                stringstream stream1;
                string cadena1 = "";
                stream1 << d.ruta[1];
                cadena1 = stream1.str();
                stringstream stream2;
                string cadena2 = "";
                stream2 << d.ruta[2];
                cadena2 = stream2.str();

                p = "Ruta mas corta  del nodo 1 al nodo 6" + cadena + "-" + cadena1 + "-" + cadena2;
                mayor2 = to_string(mayor());

            }
        }
        txt.setString("El vertice mayor es:"+ mayor2);
        txt.setString(p);
        window.clear();
        window.draw(spFondo);
        window.draw(shape);
        window.draw(rectangulo1);
        window.draw(txt);
        window.draw(txtPeso1);
        window.draw(txtPeso2);
        window.draw(txtPeso3);
        window.draw(txtPeso4);
        window.draw(txtPeso5);
        window.draw(txtPeso6);
        window.draw(txtPeso7);
        window.draw(rectangulo2);
        window.draw(rectangulo3);
        window.draw(rectangulo4);
        window.draw(rectangulo5);
        window.draw(rectangulo6);
        window.draw(rectangulo7);
        window.draw(shape2);
        window.draw(shape3);
        window.draw(shape4);
        window.draw(shape5);
        window.draw(shape6);
        window.draw(txtPosicion);
        window.draw(txtPosicion2);
        window.draw(txtPosicion3);
        window.draw(txtPosicion4);
        window.draw(txtPosicion5);
        window.draw(txtPosicion6);
        // window.draw(posicion);
        window.display();
    }
}

int grafo::mayor()
{

    int arreglo[6] = {1,2,3,4,5,6};
    int temp = arreglo[0];

    for (int i = 0; i < 6; i++)
    {

        if (arreglo[i] > temp)
        {
            temp = arreglo[i];
        }
    }

    return temp;
}

void grafo::dijkstra(int actual, int dest)
{
    d.distancia = 0;
    d.ruta.clear();
    int tam = 0;
    for (int x = 0; x < vertices.size(); x++)
    {
        if (vertices[x]->next != 0)
            tam += 2;
        else
            tam++;
    }
    etiqueta arreglo[tam];

    auxiliar(0, arreglo, 0, 0, 0, actual, dest);
}

int grafo::verificar(etiqueta arreglo[], int no)
{
    int p;
    int m = 0;
    for (int c = 0; c < no; c++)
    {
        if (c == 0)
        {
            m = arreglo[c].distancia;
            p = c;
        }
        else if (m > arreglo[c].distancia)
        {
            m = arreglo[c].distancia;
            p = c;
        }
    }
    return p;
}

void grafo::auxiliar(int c, etiqueta arreglo[], int no, int ant, int peso, int actual, int dest)
{
    cout << "destino" << dest << endl;
    cout << "actual" << actual << endl;
    cout << "anterior" << ant << endl;
    cout << "peso" << peso << endl;
    cout << "c" << c << endl;
    cout << "no" << no << endl;
    if (actual == dest)
    {
        d.distancia = d.distancia;
        d.ruta.push_back(actual);
        return;
    }
    if (actual == 1)
    {
        //Creo la etiqueta
        arreglo[0].destin = vertices[actual]->destino->pos;
        arreglo[0].distancia = vertices[actual]->peso;
        arreglo[0].origen = 1;

        d.distancia = vertices[actual]->next->peso;
        d.ruta.push_back(vertices[actual]->next->destino->pos);
        auxiliar(c + 1, arreglo, no + 1, actual, vertices[actual]->next->peso, vertices[actual]->next->destino->pos, dest);
    }
    else
    {
        if (vertices[actual]->next != 0)
        {
            //Creo las etiquetas
            arreglo[c].destin = vertices[actual]->destino->pos;
            arreglo[c].distancia = vertices[actual]->peso + peso;
            arreglo[c].origen = actual;
            c++;
            no++;
            arreglo[c].destin = vertices[actual]->next->destino->pos;
            arreglo[c].distancia = vertices[actual]->next->peso + peso;
            arreglo[c].origen = actual;
            no++;
            //En esta posicion debo moverme

            int posicion = verificar(arreglo, no);
            cout << posicion;
            vector<int> tmp;
            for (int v = 0; v < d.ruta.size(); v++)
            {
                if (d.ruta[v] != actual)
                    tmp.push_back(d.ruta[v]);
            }
            d.ruta.clear();
            d.ruta = tmp;
            d.ruta.push_back(arreglo[posicion].destin);
            d.distancia = d.distancia + arreglo[posicion].distancia;
            cout << arreglo[posicion].distancia;
            auxiliar(posicion, arreglo, no, arreglo[posicion].origen, d.distancia, vertices[arreglo[posicion].destin]->destino->pos, dest);
        }
        else
        {

            //Creo las etiquetas
            arreglo[c].destin = vertices[actual]->destino->pos;
            arreglo[c].distancia = vertices[actual]->peso + peso;
            arreglo[c].origen = actual;
            c++;
            no++;
            int posicion = verificar(arreglo, no);
            vector<int> tmp;
            for (int v = 0; v < d.ruta.size(); v++)
            {
                if (d.ruta[v] != actual)
                    tmp.push_back(d.ruta[v]);
            }
            d.ruta.clear();
            d.ruta = tmp;
            d.ruta.push_back(arreglo[posicion].destin);
            d.distancia = d.distancia - peso + arreglo[posicion].distancia;
            auxiliar(posicion, arreglo, no, arreglo[posicion].origen, d.distancia, vertices[arreglo[posicion].destin]->destino->pos, dest);
        }
    }
}

int grafo::dibujar()
{
    graf();
    return 0;
}
