/*
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#include "lcf/rpg/movecommand.h"
#include "reader_struct.h"
#include <iostream>

namespace lcf {

template <>
struct RawStruct<rpg::MoveCommand> {
	static void ReadLcf(rpg::MoveCommand& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const rpg::MoveCommand& ref, LcfWriter& stream);
	static int LcfSize(const rpg::MoveCommand& ref, LcfWriter& stream);
	static void WriteXml(const rpg::MoveCommand& ref, XmlWriter& stream);
	static void BeginXml(rpg::MoveCommand& ref, XmlReader& stream);
	static InspectResult Inspect(const rpg::MoveCommand& ref, InspectPath& path);
#ifdef LCF_DEBUG_TRACE_INSPECT
	static std::vector<std::string> TracePath(const rpg::MoveCommand& ref, InspectPath& path);
#endif
};

template <>
struct RawStruct<std::vector<rpg::MoveCommand> > {
	static void ReadLcf(std::vector<rpg::MoveCommand>& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const std::vector<rpg::MoveCommand>& ref, LcfWriter& stream);
	static int LcfSize(const std::vector<rpg::MoveCommand>& ref, LcfWriter& stream);
	static void WriteXml(const std::vector<rpg::MoveCommand>& ref, XmlWriter& stream);
	static void BeginXml(std::vector<rpg::MoveCommand>& ref, XmlReader& stream);
	static InspectResult Inspect(const std::vector<rpg::MoveCommand>& ref, InspectPath& path);
#ifdef LCF_DEBUG_TRACE_INSPECT
	static std::vector<std::string> TracePath(const std::vector<rpg::MoveCommand>& ref, InspectPath& path);
#endif
};

/**
 * Reads Move Command.
 */
void RawStruct<rpg::MoveCommand>::ReadLcf(rpg::MoveCommand& ref, LcfReader& stream, uint32_t /* length */) {
	ref.command_id = stream.ReadInt();
	const auto cmd = static_cast<rpg::MoveCommand::Code>(ref.command_id);
	switch (cmd) {
		case rpg::MoveCommand::Code::switch_on:
			stream.Read(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::switch_off:
			stream.Read(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::change_graphic:
			stream.ReadString(ref.parameter_string, stream.ReadInt());
			stream.Read(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::play_sound_effect:
			stream.ReadString(ref.parameter_string, stream.ReadInt());
			stream.Read(ref.parameter_a);
			stream.Read(ref.parameter_b);
			stream.Read(ref.parameter_c);
			break;
		default: break;
	}
}

void RawStruct<rpg::MoveCommand>::WriteLcf(const rpg::MoveCommand& ref, LcfWriter& stream) {
	stream.WriteInt(ref.command_id);
	const auto cmd = static_cast<rpg::MoveCommand::Code>(ref.command_id);
	switch (cmd) {
		case rpg::MoveCommand::Code::switch_on:
			stream.Write(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::switch_off:
			stream.Write(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::change_graphic:
			stream.WriteInt(stream.Decode(ref.parameter_string).size());
			stream.Write(ref.parameter_string);
			stream.Write(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::play_sound_effect:
			stream.WriteInt(stream.Decode(ref.parameter_string).size());
			stream.Write(ref.parameter_string);
			stream.Write(ref.parameter_a);
			stream.Write(ref.parameter_b);
			stream.Write(ref.parameter_c);
			break;
		default: break;
	}
}

int RawStruct<rpg::MoveCommand>::LcfSize(const rpg::MoveCommand& ref, LcfWriter& stream) {
	int result = 0;
	result += LcfReader::IntSize(ref.command_id);
	const auto cmd = static_cast<rpg::MoveCommand::Code>(ref.command_id);
	switch (cmd) {
		case rpg::MoveCommand::Code::switch_on:
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::switch_off:
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::change_graphic:
			result += LcfReader::IntSize(stream.Decode(ref.parameter_string).size());
			result += stream.Decode(ref.parameter_string).size();
			result += LcfReader::IntSize(ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::play_sound_effect:
			result += LcfReader::IntSize(stream.Decode(ref.parameter_string).size());
			result += stream.Decode(ref.parameter_string).size();
			result += LcfReader::IntSize(ref.parameter_a);
			result += LcfReader::IntSize(ref.parameter_b);
			result += LcfReader::IntSize(ref.parameter_c);
			break;
		default: break;
	}
	return result;
}

void RawStruct<rpg::MoveCommand>::WriteXml(const rpg::MoveCommand& ref, XmlWriter& stream) {
	stream.BeginElement("MoveCommand");
	stream.WriteNode("command_id", ref.command_id);
	const auto cmd = static_cast<rpg::MoveCommand::Code>(ref.command_id);
	switch (cmd) {
		case rpg::MoveCommand::Code::switch_on:
			stream.WriteNode("parameter_a", ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::switch_off:
			stream.WriteNode("parameter_a", ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::change_graphic:
			stream.WriteNode("parameter_string", ref.parameter_string);
			stream.WriteNode("parameter_a", ref.parameter_a);
			break;
		case rpg::MoveCommand::Code::play_sound_effect:
			stream.WriteNode("parameter_string", ref.parameter_string);
			stream.WriteNode("parameter_a", ref.parameter_a);
			stream.WriteNode("parameter_b", ref.parameter_b);
			stream.WriteNode("parameter_c", ref.parameter_c);
			break;
		default: break;
	}
	stream.EndElement("MoveCommand");
}

class MoveCommandXmlHandler : public XmlHandler {
private:
	rpg::MoveCommand& ref;
	int32_t* field;
	bool parameter_string;
public:
	MoveCommandXmlHandler(rpg::MoveCommand& ref) :
		ref(ref), field(NULL), parameter_string(false) {}
	void StartElement(XmlReader& /* stream */, const char* name, const char** /* atts */) {
		if (strcmp(name, "command_id") == 0)
			field = &ref.command_id;
		else if (strcmp(name, "parameter_a") == 0)
			field = &ref.parameter_a;
		else if (strcmp(name, "parameter_b") == 0)
			field = &ref.parameter_b;
		else if (strcmp(name, "parameter_c") == 0)
			field = &ref.parameter_c;
		else if (strcmp(name, "parameter_string") == 0)
			parameter_string = true;
		else {
			Log::Error("XML: Unrecognized field '%s'", name);
			field = NULL;
			parameter_string = false;
		}
	}
	void EndElement(XmlReader& /* stream */, const char* /* name */) {
		field = NULL;
		parameter_string = false;
	}
	void CharacterData(XmlReader& /* stream */, const std::string& data) {
		if (field != NULL)
			XmlReader::Read(*field, data);
		else if (parameter_string)
			XmlReader::Read(ref.parameter_string, data);
	}
};

void RawStruct<rpg::MoveCommand>::BeginXml(rpg::MoveCommand& ref, XmlReader& stream) {
	stream.SetHandler(new WrapperXmlHandler("MoveCommand", new MoveCommandXmlHandler(ref)));
}

/**
 * Reads Move Commands.
 */
void RawStruct<std::vector<rpg::MoveCommand> >::ReadLcf(std::vector<rpg::MoveCommand>& ref, LcfReader& stream, uint32_t length) {
	unsigned long startpos = stream.Tell();
	unsigned long endpos = startpos + length;
	while (stream.Tell() != endpos) {
		rpg::MoveCommand command;
		RawStruct<rpg::MoveCommand>::ReadLcf(command, stream, 0);
		ref.push_back(command);
	}
}

void RawStruct<std::vector<rpg::MoveCommand> >::WriteLcf(const std::vector<rpg::MoveCommand>& ref, LcfWriter& stream) {
	std::vector<rpg::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		RawStruct<rpg::MoveCommand>::WriteLcf(*it, stream);
}

int RawStruct<std::vector<rpg::MoveCommand> >::LcfSize(const std::vector<rpg::MoveCommand>& ref, LcfWriter& stream) {
	int result = 0;
	std::vector<rpg::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		result += RawStruct<rpg::MoveCommand>::LcfSize(*it, stream);
	return result;
}

void RawStruct<std::vector<rpg::MoveCommand> >::WriteXml(const std::vector<rpg::MoveCommand>& ref, XmlWriter& stream) {
	std::vector<rpg::MoveCommand>::const_iterator it;
	for (it = ref.begin(); it != ref.end(); it++)
		RawStruct<rpg::MoveCommand>::WriteXml(*it, stream);
}

class MoveCommandVectorXmlHandler : public XmlHandler {
public:
	MoveCommandVectorXmlHandler(std::vector<rpg::MoveCommand>& ref) : ref(ref) {}

	void StartElement(XmlReader& stream, const char* name, const char** /* atts */) {
		if (strcmp(name, "MoveCommand") != 0)
			Log::Error("XML: Expecting %s but got %s", "MoveCommand", name);
		ref.resize(ref.size() + 1);
		rpg::MoveCommand& obj = ref.back();
		stream.SetHandler(new MoveCommandXmlHandler(obj));
	}
private:
	std::vector<rpg::MoveCommand>& ref;
};

void RawStruct<std::vector<rpg::MoveCommand> >::BeginXml(std::vector<rpg::MoveCommand>& obj, XmlReader& stream) {
	stream.SetHandler(new MoveCommandVectorXmlHandler(obj));
}

constexpr std::array<std::pair<const char*, int>, 5> tags_to_id = {{
	{ "command_id", 0},
	{ "parameter_a", 1},
	{ "parameter_b", 2},
	{ "parameter_c", 3},
	{ "parameter_string", 4}
}};

InspectResult RawStruct<rpg::MoveCommand>::Inspect(const rpg::MoveCommand& ref, InspectPath& path) {
	auto handle_field_id = [&](int field_id) {
		switch (field_id) {
			case 0:
				return Primitive<int32_t>::Inspect(ref.command_id, path);
			case 1:
				return Primitive<int32_t>::Inspect(ref.parameter_a, path);
			case 2:
				return Primitive<int32_t>::Inspect(ref.parameter_b, path);
			case 3:
				return Primitive<int32_t>::Inspect(ref.parameter_c, path);
			case 4:
				return Primitive<std::string>::Inspect(ToString(ref.parameter_string), path);
		}
		return InspectResult();
	};

	if (path.UseTags()) {
		return path.InspectContainer([&](std::string_view field_tag) {
			auto it = std::find_if(tags_to_id.begin(), tags_to_id.end(), [&field_tag](auto& p) { return field_tag == p.first; });
			if (it != tags_to_id.end()) {
				return handle_field_id(it->second);
			}
			return InspectResult();
		});
	}
	return path.InspectContainer(handle_field_id);
}

InspectResult RawStruct<std::vector<rpg::MoveCommand> >::Inspect(const std::vector<rpg::MoveCommand>& ref, InspectPath& path) {
	return path.InspectVector(ref.size(), [&](int idx) {
		return RawStruct<rpg::MoveCommand>::Inspect(ref[idx], path);
	});
}

#ifdef LCF_DEBUG_TRACE_INSPECT
std::vector<std::string> RawStruct<rpg::MoveCommand>::TracePath(const rpg::MoveCommand& ref, InspectPath& path) {
	return std::vector<std::string> { "<not-traced>" };
}

std::vector<std::string> RawStruct<std::vector<rpg::MoveCommand>>::TracePath(const std::vector<rpg::MoveCommand>& ref, InspectPath& path) {
	std::vector<std::string> result;
	for (auto element : ref) {
		result.push_back(RawStruct<rpg::MoveCommand>::TracePath(element, path)[0]);
	}
	return result;
}
#endif

} //namspace lcf
