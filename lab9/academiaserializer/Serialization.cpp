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

    Building::Building(int id, string name, initializer_list<Room> rooms) {
        id_ = id;
        name_ = name;
        for (const auto &v : rooms) {
            room_.push_back(v);
        }
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


    void Room::Serialize(XmlSerializer *xml) const {
        xml->Header("room");
        xml->IntegerField("id", id_);
        xml->StringField("name", name_);
        xml->StringField("type", TypeToString(type_));
        xml->Footer("room");
    }


    void Building::Serialize(XmlSerializer *xml) const {
        xml->Header("building");
        xml->IntegerField("id", id_);
        xml->StringField("name", name_);
        xml->Header("rooms");
        for (auto &v : room_) {
            v.Serialize(xml);
        }
        xml->Footer("rooms");
        xml->Footer("building");
    }
}