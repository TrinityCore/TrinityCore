/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ProtobufJSON.h"
#include "Errors.h"
#include "Log.h"
#include "StringFormat.h"
#include <google/protobuf/message.h>
#include <rapidjson/writer.h>
#include <rapidjson/reader.h>
#include <rapidjson/stringbuffer.h>
#include <stack>

class Serializer
{
public:
    Serializer() : _writer(_buffer) { }

    void WriteInt32(int32 value) { _writer.Int(value); }
    void WriteInt64(int64 value) { _writer.Int64(value); }
    void WriteUInt32(uint32 value) { _writer.Uint(value); }
    void WriteUInt64(uint64 value) { _writer.Uint64(value); }
    void WriteDouble(double value) { _writer.Double(value); }
    void WriteFloat(float value) { _writer.Double(value); }
    void WriteBool(bool value) { _writer.Bool(value); }
    void WriteEnum(google::protobuf::EnumValueDescriptor const* value) { _writer.String(value->name()); }
    void WriteString(std::string const& value) { _writer.String(value); }
    void WriteMessage(google::protobuf::Message const& value);

    std::string GetString() const { return std::string(_buffer.GetString(), _buffer.GetSize()); }

private:
    void WriteMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field);
    void WriteSimpleMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field);
    void WriteRepeatedMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field);

    rapidjson::StringBuffer _buffer;
    rapidjson::Writer<rapidjson::StringBuffer> _writer;
};

void Serializer::WriteMessage(google::protobuf::Message const& value)
{
    google::protobuf::Reflection const* reflection = value.GetReflection();
    std::vector<google::protobuf::FieldDescriptor const*> fields;
    reflection->ListFields(value, &fields);

    _writer.StartObject();
    for (std::size_t i = 0; i < fields.size(); ++i)
        WriteMessageField(value, fields[i]);

    _writer.EndObject();
}

void Serializer::WriteMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field)
{
    _writer.Key(field->name().c_str());
    if (field->is_repeated())
    {
        _writer.StartArray();
        WriteRepeatedMessageField(value, field);
        _writer.EndArray();
    }
    else
        WriteSimpleMessageField(value, field);
}

void Serializer::WriteSimpleMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field)
{
    google::protobuf::Reflection const* reflection = value.GetReflection();
    switch (field->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
            WriteInt32(reflection->GetInt32(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
            WriteInt64(reflection->GetInt64(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            WriteUInt32(reflection->GetUInt32(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
            WriteUInt64(reflection->GetUInt64(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
            WriteDouble(reflection->GetDouble(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
            WriteFloat(reflection->GetFloat(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
            WriteBool(reflection->GetBool(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
            WriteEnum(reflection->GetEnum(value, field));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            std::string strValue = reflection->GetString(value, field);
            if (field->type() == google::protobuf::FieldDescriptor::TYPE_STRING)
                WriteString(strValue);
            else
            {
                _writer.StartArray();
                for (std::size_t i = 0; i < strValue.length(); ++i)
                    WriteUInt32(uint32(strValue[i]));
                _writer.EndArray();
            }
            break;
        }
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
            WriteMessage(reflection->GetMessage(value, field));
            break;
        default:
            break;
    }
}

void Serializer::WriteRepeatedMessageField(google::protobuf::Message const& value, google::protobuf::FieldDescriptor const* field)
{
    google::protobuf::Reflection const* reflection = value.GetReflection();
    for (int32 i = 0; i < reflection->FieldSize(value, field); ++i)
    {
        switch (field->cpp_type())
        {
            case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                WriteInt32(reflection->GetRepeatedInt32(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                WriteInt64(reflection->GetRepeatedInt64(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
                WriteUInt32(reflection->GetRepeatedUInt32(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
                WriteUInt64(reflection->GetRepeatedUInt64(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                WriteDouble(reflection->GetRepeatedDouble(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                WriteFloat(reflection->GetRepeatedFloat(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                WriteBool(reflection->GetRepeatedBool(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
                WriteEnum(reflection->GetRepeatedEnum(value, field, i));
                break;
            case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
            {
                std::string strValue = reflection->GetRepeatedString(value, field, i);
                if (field->type() == google::protobuf::FieldDescriptor::TYPE_STRING)
                    WriteString(strValue);
                else
                {
                    _writer.StartArray();
                    for (std::size_t j = 0; j < strValue.length(); ++j)
                        WriteUInt32(uint32(strValue[j]));
                    _writer.EndArray();
                }
                break;
            }
            case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                WriteMessage(reflection->GetRepeatedMessage(value, field, i));
                break;
            default:
                break;
        }
    }
}

class Deserializer : public rapidjson::BaseReaderHandler<rapidjson::UTF8<>, Deserializer>
{
public:
    bool ReadMessage(std::string const& json, google::protobuf::Message* message);

    bool Key(const Ch* str, rapidjson::SizeType length, bool copy);
    bool Null();
    bool Bool(bool b);
    bool Int(int32 i);
    bool Uint(uint32 i);
    bool Int64(int64 i);
    bool Uint64(uint64 i);
    bool Double(double d);
    bool String(const Ch* str, rapidjson::SizeType length, bool copy);
    bool StartObject();
    bool EndObject(rapidjson::SizeType memberCount);
    bool StartArray();
    bool EndArray(rapidjson::SizeType memberCount);

    std::vector<std::string> const& GetErrors() const { return _errors; }

private:
    bool CheckType(google::protobuf::FieldDescriptor::CppType expectedType);

    rapidjson::Reader _reader;
    std::stack<google::protobuf::FieldDescriptor const*> _state;
    std::stack<google::protobuf::Message*> _objectState;
    std::vector<std::string> _errors;
};

bool Deserializer::ReadMessage(std::string const& json, google::protobuf::Message* message)
{
    rapidjson::StringStream ss(json.c_str());

    _objectState.push(message);

    rapidjson::ParseResult result = _reader.Parse(ss, *this);

    ASSERT(result.IsError() || (_objectState.empty() && _state.empty()));

    return !result.IsError() && _errors.empty();
}

bool Deserializer::Key(const Ch* str, rapidjson::SizeType /*length*/, bool /*copy*/)
{
    google::protobuf::FieldDescriptor const* field = _objectState.top()->GetDescriptor()->FindFieldByName(str);
    if (!field)
    {
        _errors.push_back(Trinity::StringFormat("Message %s has no field %s.", _objectState.top()->GetTypeName().c_str(), str));
        return false;
    }

    _state.push(field);
    return true;
}

bool Deserializer::Null()
{
    _state.pop();
    return true;
}

#define SET_FIELD(message, field, Type, val) do { \
    if (!field->is_repeated()) \
        message->GetReflection()->Set ## Type(message, field, val); \
    else \
        message->GetReflection()->Add ## Type(message, field, val); \
    _state.pop(); \
    } while (0)

bool Deserializer::Bool(bool b)
{
    if (!CheckType(google::protobuf::FieldDescriptor::CPPTYPE_BOOL))
        return false;

    SET_FIELD(_objectState.top(), _state.top(), Bool, b);
    return true;
}

bool Deserializer::Int(int32 i)
{
    if (!CheckType(google::protobuf::FieldDescriptor::CPPTYPE_INT32))
        return false;

    SET_FIELD(_objectState.top(), _state.top(), Int32, i);
    return true;
}

bool Deserializer::Uint(uint32 i)
{
    google::protobuf::FieldDescriptor const* field = _state.top();
    google::protobuf::Message* message = _objectState.top();
    switch (field->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
            SET_FIELD(message, field, UInt32, i);
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            if (field->type() != google::protobuf::FieldDescriptor::TYPE_BYTES)
            {
                _errors.emplace_back("Expected field type to be bytes but got string instead.");
                return false;
            }
            std::string currentValue = message->GetReflection()->GetString(*message, field);
            currentValue.append(1, (char)i);
            message->GetReflection()->SetString(message, field, currentValue);
            break;
        }
        default:
            _errors.push_back(Trinity::StringFormat("Expected field type to be uint32 or string but got %s instead.", _state.top()->cpp_type_name()));
            return false;
    }

    return true;
}

bool Deserializer::Int64(int64 i)
{
    if (!CheckType(google::protobuf::FieldDescriptor::CPPTYPE_INT64))
        return false;

    SET_FIELD(_objectState.top(), _state.top(), Int64, i);
    return true;
}

bool Deserializer::Uint64(uint64 i)
{
    if (!CheckType(google::protobuf::FieldDescriptor::CPPTYPE_UINT64))
        return false;

    SET_FIELD(_objectState.top(), _state.top(), UInt64, i);
    return true;
}

bool Deserializer::Double(double d)
{
    google::protobuf::FieldDescriptor const* field = _state.top();
    google::protobuf::Message* message = _objectState.top();
    switch (field->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
            SET_FIELD(message, field, Float, float(d));
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
            SET_FIELD(message, field, Double, d);
            break;
        default:
            _errors.push_back(Trinity::StringFormat("Expected field type to be float or double but got %s instead.", _state.top()->cpp_type_name()));
            return false;
    }

    return true;
}

bool Deserializer::String(const Ch* str, rapidjson::SizeType /*length*/, bool /*copy*/)
{
    google::protobuf::FieldDescriptor const* field = _state.top();
    google::protobuf::Message* message = _objectState.top();
    switch (field->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            google::protobuf::EnumValueDescriptor const* enumValue = field->enum_type()->FindValueByName(str);
            if (!enumValue)
            {
                _errors.push_back(Trinity::StringFormat("Field %s enum %s does not have a value named %s.", field->full_name().c_str(), field->enum_type()->full_name().c_str(), str));
                return false;
            }

            SET_FIELD(message, field, Enum, enumValue);
            break;
        }
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
            SET_FIELD(message, field, String, str);
            break;
        default:
            _errors.push_back(Trinity::StringFormat("Expected field type to be string or enum but got %s instead.", _state.top()->cpp_type_name()));
            return false;
    }

    return true;
}

bool Deserializer::StartObject()
{
    // not a root object
    if (!_state.empty())
    {
        if (_state.top()->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
        {
            _errors.push_back(Trinity::StringFormat("Expected field %s to be a message but got %s instead.", _state.top()->cpp_type_name()));
            return false;
        }

        google::protobuf::Message* containingMessage = _objectState.top();
        if (!_state.top()->is_repeated())
            _objectState.push(containingMessage->GetReflection()->MutableMessage(containingMessage, _state.top()));
        else
            _objectState.push(containingMessage->GetReflection()->AddMessage(containingMessage, _state.top()));
    }
    else if (_objectState.size() != 1)
        return false;

    return true;
}

bool Deserializer::EndObject(rapidjson::SizeType /*memberCount*/)
{
    if (!_state.empty() && !_state.top()->is_repeated())
        _state.pop();

    _objectState.pop();
    return true;
}

bool Deserializer::StartArray()
{
    if (_state.empty())
    {
        _errors.emplace_back("Root cannot be an array.");
        return false;
    }

    if (_state.top()->is_repeated() ^ (_state.top()->type() != google::protobuf::FieldDescriptor::TYPE_BYTES))
    {
        _errors.push_back(Trinity::StringFormat("Expected field %s type to be exactly an array OR bytes but it was both or none.", _state.top()->full_name().c_str()));
        return false;
    }

    return true;
}

bool Deserializer::CheckType(google::protobuf::FieldDescriptor::CppType expectedType)
{
    if (_state.top()->cpp_type() != expectedType)
    {
        _errors.push_back(Trinity::StringFormat("Expected field %s type to be %s but got %s instead.",
            _state.top()->full_name().c_str(), google::protobuf::FieldDescriptor::CppTypeName(expectedType), _state.top()->cpp_type_name()));
        return false;
    }

    return true;
}

bool Deserializer::EndArray(rapidjson::SizeType /*memberCount*/)
{
    _state.pop();
    return true;
}

#undef SET_FIELD

std::string JSON::Serialize(google::protobuf::Message const& message)
{
    Serializer serializer;
    serializer.WriteMessage(message);
    return serializer.GetString();
}

bool JSON::Deserialize(std::string const& json, google::protobuf::Message* message)
{
    Deserializer deserializer;
    if (!deserializer.ReadMessage(json, message))
    {
        for (std::size_t i = 0; i < deserializer.GetErrors().size(); ++i)
            TC_LOG_ERROR("json", "%s", deserializer.GetErrors()[i].c_str());
        return false;
    }

    return true;
}
