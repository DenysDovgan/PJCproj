//
// Created by s30460 on 2024-05-28.
//

#include "../headers/GameEvent.h"

GameEvent::GameEvent(EventType type, const std::string& message) : type(type), message(message) {}

auto GameEvent::getType() const -> GameEvent::EventType {
    return type;
}

const std::string& GameEvent::getMessage() const {
    return message;
}
