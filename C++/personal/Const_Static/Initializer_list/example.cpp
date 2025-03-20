#include <string.h>
#include <iostream>

class Marine{
private:
    int hp;
    int x, y;
    bool is_dead;
    const int default_damage;

public:
    Marine();
    Marine(int _x, int _y);
    Marine(int _x, int _y, int default_damage);
    int attack();
    void be_attacked(int damage_earn);
    void move(int _x, int _y);

    void show_status();
};

Marine::Marine() 
    : hp(50), x(0), y(0), default_damage(5), is_dead(false) { }
Marine::Marine(int _x, int _y) 
    : x(_x), y(_y), hp(50), default_damage(5), is_dead(false) { }
Marine::Marine(int _x, int _y, int default_damage) 
    : x(_x), y(_y), hp(50), default_damage(default_damage), is_dead(false) { }

void Marine::move(int _x, int _y){
    x = _x;
    y = _y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn){
    hp -= damage_earn;
    if(hp <= 0){
        is_dead = true;
    }
}
void Marine::show_status(){
    std::cout << " *** Marine : " << " ***" << std::endl;
    std::cout << " Location : ( " << x << " , " << y << " ) " << std::endl;
    std::cout << " HP : " << hp << std::endl;
}

int main(){
    Marine marine1(2, 3, 10);
    Marine marine2(3, 5, 10);
  
    marine1.show_status();
    marine2.show_status();

    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    marine2.be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();

    return 0;
}