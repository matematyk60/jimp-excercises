//
// Created by janek on 09.05.17.
//

#include "Serialization.h"

namespace academia {
    Serializer::Serializer(ostream *out) {
        out_ = out;
    }

    Room::Room(int id, const string &name, Room::Type type) {
        id_ = id;
        name_ = name;
        type_ = type;
    }

    string Room::TypeToString(Room::Type type) const {
        switch (type) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->Header("room");
        serializer->Footer("room");
        serializer->StringField("type", TypeToString(type_));
    }


    string Building::TypeToString(Building::Type type) const {
        switch (type) {
            case Type::COMPUTER_LAB:
                return "COMPUTER_LAB";
            case Type::CLASSROOM:
                return "CLASSROOM";
            case Type::LECTURE_HALL:
                return "LECTURE_HALL";
        }
    }

    Building::Building(int id, const string &name, Building::Type type) {
        id_ = id;
        name_ = name;
        type_ = type;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->IntegerField("id", id_);
        serializer->StringField("name", name_);
        serializer->Header("room");
        serializer->Footer("room");
        serializer->StringField("type", TypeToString(type_));
    }
}