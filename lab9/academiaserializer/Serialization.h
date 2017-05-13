//
// Created by janek on 09.05.17.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <vector>
#include <functional>
#include <ostream>

using namespace std;
using namespace std::literals;

namespace academia {

    class Serializer;

    class XmlSerializer;

    class JsonSerializer;


    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) const = 0;

        virtual void Serialize(XmlSerializer *xml) const = 0;

        //virtual void Serialize(JsonSerializer *json) const = 0;
    };


    class Serializer {
    public:
        Serializer(ostream *out);

        virtual void IntegerField(const std::string &field_name, int value) = 0;

        virtual void DoubleField(const std::string &field_name, double value) = 0;

        virtual void StringField(const std::string &field_name, const std::string &value) = 0;

        virtual void BooleanField(const std::string &field_name, bool value) = 0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) = 0;

        virtual void ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) = 0;

        virtual void Header(const std::string &object_name) = 0;

        virtual void Footer(const std::string &object_name) = 0;

    protected:
        ostream *out_;
    };


    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(std::ostream *out) : Serializer(out) {}

        void IntegerField(const std::string &field_name, int value) override {
            *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
        }

        void DoubleField(const std::string &field_name, double value) override {
            *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
        }

        void StringField(const std::string &field_name, const std::string &value) override {
            *out_ << "<" + field_name + ">" + value + "<\\" + field_name + ">";
        }

        void BooleanField(const std::string &field_name, bool value) override {
            *out_ << "<" + field_name + ">" + to_string(value) + "<\\" + field_name + ">";
        }

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override {
            *out_ << "<" + field_name + ">";
            value.Serialize(this);
            *out_ << "<\\" + field_name + ">";
        }

        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override {

            Header(field_name);
            for (const Serializable &n : value)
                n.Serialize(this);
            Footer(field_name);
        }

        void Header(const std::string &object_name) override {
            *out_ << "<" + object_name + ">";
        }

        void Footer(const std::string &object_name) override {
            *out_ << "<\\" + object_name + ">";
        }

    };


    class Room : public Serializable {
    public:

        enum Type {
            COMPUTER_LAB,
            CLASSROOM,
            LECTURE_HALL
        };

        string TypeToString(Type type) const;

        Room(int id, const string &name, Type type);

        void Serialize(Serializer *serializer) const override;

        void Serialize(XmlSerializer *xml) const override;

        //void Serialize(JsonSerializer *json) override;

    private:
        int id_;
        string name_;
        Type type_;
    };


    class Building : public Serializable {
    public:

        Building(int id, string name, std::initializer_list<Room> rooms);

        void Serialize(Serializer *serializer) const override {}

        void Serialize(XmlSerializer *xml) const override;

        //void Serialize(JsonSerializer *json) override;


    private:
        int id_;
        string name_;
        vector<Room> room_;
    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_Hz