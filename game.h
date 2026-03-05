#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QMap>

namespace core {

    class Game
    {
        QString _nameId;
    public:
        explicit Game(QString nameId);
        virtual ~Game() = default;

        QString nameId() {
            return _nameId;
        };
        virtual void continueGame() = 0;
        virtual void startGame() = 0;
        virtual void updateGame() = 0;
        virtual void handleInput() = 0;
    };

    QMap<QString,QString> loadGameScoresTable(QString gameNameId);
}

#endif // GAME_H
