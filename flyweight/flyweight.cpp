/**
 * @author: hong
 * @date: 2022/8/25 07:59
 * @description:
 */

#include <iostream>
#include <string>
#include <map>

class Font{
private:
    std::string key;
public:
    Font(const std::string& key){
        std::cout << "New Font" << std::endl;
        this->key = key;
    }

    void operation(){
        std::cout << key << ": " << this << std::endl;
    }
};


class FontFactory{
private:
    std::map<std::string, Font*> pool;
public:
    Font* getFont(const std::string& key){
        if (pool.find(key) == pool.end()){
            pool.insert(std::pair<std::string, Font*>(key, new Font(key)));
        }
        return pool.find(key)->second;
    }
};

int main(){
    FontFactory factory;
    factory.getFont("yellow Font")->operation();
    factory.getFont("yellow Font")->operation();
}