//
// Created by s30460 on 2024-05-28.
//

#ifndef PJCPROJ_GAMEEVENT_H
#define PJCPROJ_GAMEEVENT_H

#include <string>

class GameEvent {
public:
    enum EventType {
        NewGame,
        GameOver,
        // Add other events as needed
    };

    GameEvent(EventType type, const std::string& message);
    EventType getType() const;
    const std::string& getMessage() const;

private:
    EventType type;
    std::string message;
};


#endif //PJCPROJ_GAMEEVENT_H
