cmake_minimum_required(VERSION 3.24)
project(DesignPattern)

set(CMAKE_CXX_STANDARD 17)

add_executable(design_pattern main.cpp)

add_executable(template template/template.cpp)

add_executable(strategy strategy/strategy.cpp)

add_library(observer observer/first_observer.cpp observer/second_observer.cpp)
add_executable(observer_app observer/app.cpp)
target_link_libraries(observer_app observer)

add_executable(decorator decorator/decorator.cpp)

add_executable(bridge bridge/bridge.cpp)

add_library(factory factory/file_factory.cpp factory/abstract_factory.cpp)
add_executable(factory_app factory/factory_app.cpp)
target_link_libraries(factory_app factory)


add_executable(builder builder/builder.cpp)
add_executable(builder2 builder/builder2.cpp)

add_executable(prototype prototype/prototype.cpp)

add_executable(singleton singleton/singleton.cpp)

add_executable(flyweight flyweight/flyweight.cpp)

add_executable(adapter adapter/adapter.cpp)

add_executable(state state/state.cpp)

add_executable(memento memento/memento.cpp)

add_executable(composite composite/composite.cpp)

add_executable(chain_of_responsibility chain_of_responsibility/responsibility.cpp)

add_executable(command command/command.cpp)

add_executable(visitor visitor/visitor.cpp)

add_executable(interpreter interpreter/interpreter.cpp)