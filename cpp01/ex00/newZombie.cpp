#include "Zombie.hpp"

//newはmallocしつつコンストラクタを走らせられるみたいなもの、関数ではなく演算子らしい、後ろに型名+コンストラクタに渡す引数で動的にオブジェクトを作成できる
Zombie* newZombie(std::string name) {
    Zombie* z = new Zombie(name);
    return (z);
}