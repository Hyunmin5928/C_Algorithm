#include <string.h>
#include <iostream>

class Photon_Cannon {
private:
    int hp, shield;
    int x, y;
    int damage;

public:
    Photon_Cannon(int _x, int _y);
    Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
    std::cout << "복사 생성자 호출!" << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    x = pc.x;
    y = pc.y;
    damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int _x, int _y){
    std::cout << "생성자 호출!" << std::endl;
    hp = shield = 100;
    x = _x;
    y = _y;
    damage = 20;
}
void Photon_Cannon::show_status(){
    std::cout << "Photon Cannon" << std::endl;
    std::cout << "Location : ( " << x << " , " << y << " ) " << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3);
    Photon_Cannon pc2(pc1);
    Photon_Cannon pc3 = pc2;

    pc1.show_status();
    pc2.show_status();
    pc3.show_status();

    return 0;
}