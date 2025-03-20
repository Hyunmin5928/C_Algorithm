#include <string.h>
#include <iostream>

class Photon_Cannon {
private:
    int hp, shield;
    int x, y;
    int damage;
    char *name;
public:
    Photon_Cannon(int _x, int _y);
    Photon_Cannon(int _x, int _y, const char *cannon_name);
    Photon_Cannon(const Photon_Cannon &pc);
    ~Photon_Cannon();

    void show_status();
};

Photon_Cannon::Photon_Cannon(int _x, int _y){
    std::cout << "생성자 호출!" << std::endl;
    hp = shield = 100;
    x = _x;
    y = _y;
    damage = 20;
}
Photon_Cannon::Photon_Cannon(int _x, int _y, const char *cannon_name){
    std::cout << "생성자 호출!(+name)" << std::endl;
    hp = shield = 100;
    x = _x;
    y = _y;
    damage = 20;
    name = new char[strlen(cannon_name) + 1];
    strcpy(name, cannon_name);
}
Photon_Cannon::Photon_Cannon(const Photon_Cannon &pc){
    std::cout << "복사 생성자 호출! " << std::endl;
    hp = pc.hp;
    shield = pc.shield;
    x = pc.x;
    y = pc.y;
    damage = pc.damage;
  
    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
}
Photon_Cannon::~Photon_Cannon(){
    std::cout << "소멸자 호출!" << name << std::endl;
    // 0 이 아닌 값은 if 문에서 true 로 처리되므로
    // 0 인가 아닌가를 비교할 때 그냥 if(name) 하면
    // if(name != 0) 과 동일한 의미를 가질 수 있다.

    // 참고로 if 문 다음에 문장이 1 개만 온다면
    // 중괄호를 생략 가능하다.
    if(name) delete[] name;
}
void Photon_Cannon::show_status(){
    std::cout << "Photon Cannon" << name << std::endl;
    std::cout << "Location : ( " << x << " , " << y << " ) " << std::endl;
    std::cout << "HP : " << hp << std::endl;
}

int main(){
    Photon_Cannon pc1(3, 3, "Cannon");
    Photon_Cannon pc2 = pc1;
 
    pc1.show_status();
    pc2.show_status();

    return 0;
}