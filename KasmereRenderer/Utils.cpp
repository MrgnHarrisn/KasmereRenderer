#include "Utils.h"

void Utils::load_map(std::vector<Sector>& sectors)
{


    nfdchar_t* path;

    nfdresult_t result = NFD_OpenDialog("rcf", NULL, &path);

    switch (result) {
    case NFD_ERROR:
        printf("Error: %s\n", NFD_GetError());
        return;
    case NFD_CANCEL:
        printf("User pressed Cancel");
        return;
    case NFD_OKAY:
        puts(path);
        break;
    }

    std::ifstream file(path);
    if (!file.is_open()) {
        printf("Error reading file\n");
        return;
    }

    /* Clear the sectors */
    sectors.clear();

    size_t int_temp;
    int r, g, b;
    std::stringstream data;
    data << file.rdbuf();
    std::string line;
    while (data >> r) {

        Sector sector;
        sector.ID = r;
        dbg("Sector ID:");
        dbg(sector.ID);
        data >> sector.floor_height >> sector.ceiling_height;
        
        /* Wall colors */
        data >> r >> g >> b;
        sector.floor_color = sf::Color(r, g, b);
        data >> r >> g >> b;
        sector.ceiling_color = sf::Color(r, g, b);
        data >> r >> g >> b;
        sector.wall_color = sf::Color(r, g, b);
        data >> int_temp;
        
        std::vector<sf::Vector2f> points;

        /* Walls */
        for (size_t i = 0; i < int_temp; ++i) {
            sf::Vector2f vec;
            data >> vec.x >> vec.y;
            points.push_back(vec);
        }

        for (int i = 0; i < points.size(); ++i) {

            int prev = i - 1;
            if (prev < 0) prev = points.size() - 1;

            Wall w;
            w.color = sector.wall_color;
            w.roof_height = sector.ceiling_height;
            w.floor_height = sector.floor_height;
            w.start = points[prev];
            w.end = points[i];

            sector.m_walls.push_back(w);

        }

        /* Add sector */
        sectors.push_back(sector);
    }

    for (Sector& s : sectors) {
        // dbg(s.to_str());
    }

    file.close();
    free(path);

}