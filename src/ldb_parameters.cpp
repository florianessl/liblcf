/*
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#include "lcf/ldb/reader.h"
#include "lcf/ldb/chunks.h"
#include "reader_struct.h"

namespace lcf {

template <>
struct RawStruct<rpg::Parameters> {
	static void ReadLcf(rpg::Parameters& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const rpg::Parameters& ref, LcfWriter& stream);
	static int LcfSize(const rpg::Parameters& ref, LcfWriter& stream);
	static void WriteXml(const rpg::Parameters& ref, XmlWriter& stream);
	static void BeginXml(rpg::Parameters& ref, XmlReader& stream);
	static InspectResult Inspect(const rpg::Parameters& ref, InspectPath& path);
#ifdef LCF_DEBUG_TRACE_INSPECT
	static std::vector<std::string> TracePath(const rpg::Parameters& ref, InspectPath& path);
#endif
};

/**
 * Reads Parameters.
 */
void RawStruct<rpg::Parameters>::ReadLcf(rpg::Parameters& ref, LcfReader& stream, uint32_t length) {
	int n = length / 6;
	stream.Read(ref.maxhp, n);
	stream.Read(ref.maxsp, n);
	stream.Read(ref.attack, n);
	stream.Read(ref.defense, n);
	stream.Read(ref.spirit, n);
	stream.Read(ref.agility, n);
}

void RawStruct<rpg::Parameters>::WriteLcf(const rpg::Parameters& ref, LcfWriter& stream) {
	stream.Write(ref.maxhp);
	stream.Write(ref.maxsp);
	stream.Write(ref.attack);
	stream.Write(ref.defense);
	stream.Write(ref.spirit);
	stream.Write(ref.agility);
}

int RawStruct<rpg::Parameters>::LcfSize(const rpg::Parameters& ref, LcfWriter& /* stream */) {
	return ref.maxhp.size() * 2 * 6;
}

void RawStruct<rpg::Parameters>::WriteXml(const rpg::Parameters& ref, XmlWriter& stream) {
	stream.BeginElement("Parameters");
	stream.WriteNode<std::vector<int16_t> >("maxhp", ref.maxhp);
	stream.WriteNode<std::vector<int16_t> >("maxsp", ref.maxsp);
	stream.WriteNode<std::vector<int16_t> >("attack", ref.attack);
	stream.WriteNode<std::vector<int16_t> >("defense", ref.defense);
	stream.WriteNode<std::vector<int16_t> >("spirit", ref.spirit);
	stream.WriteNode<std::vector<int16_t> >("agility", ref.agility);
	stream.EndElement("Parameters");
}

class ParametersXmlHandler : public XmlHandler {
private:
	rpg::Parameters& ref;
	std::vector<int16_t>* field;
public:
	ParametersXmlHandler(rpg::Parameters& ref) : ref(ref), field(NULL) {}
	void StartElement(XmlReader& /* stream */, const char* name, const char** /* atts */) {
		if (strcmp(name, "maxhp") == 0)
			field = &ref.maxhp;
		else if (strcmp(name, "maxsp") == 0)
			field = &ref.maxsp;
		else if (strcmp(name, "attack") == 0)
			field = &ref.attack;
		else if (strcmp(name, "defense") == 0)
			field = &ref.defense;
		else if (strcmp(name, "spirit") == 0)
			field = &ref.spirit;
		else if (strcmp(name, "agility") == 0)
			field = &ref.agility;
		else {
			Log::Error("XML: Unrecognized field '%s'", name);
			field = NULL;
		}
	}
	void EndElement(XmlReader& /* stream */, const char* /* name */) {
		field = NULL;
	}
	void CharacterData(XmlReader& /* stream */, const std::string& data) {
		if (field != NULL)
			XmlReader::Read<std::vector<int16_t> >(*field, data);
	}
};

void RawStruct<rpg::Parameters>::BeginXml(rpg::Parameters& ref, XmlReader& stream) {
	stream.SetHandler(new WrapperXmlHandler("Parameters", new ParametersXmlHandler(ref)));
}

constexpr std::array<std::pair<const char*, int>, 6> tags_to_id = {{
	{ "maxhp", 0},
	{ "maxsp", 1},
	{ "attack", 2},
	{ "defense", 3},
	{ "spirit", 4},
	{ "agility", 5}
}};

InspectResult RawStruct<rpg::Parameters>::Inspect(const rpg::Parameters& ref, InspectPath& path) {
	auto handle_field_id = [&](int field_id) {
		switch (field_id) {
			case 0:
				return Primitive<std::vector<int16_t>>::Inspect(ref.maxhp, path);
			case 1:
				return Primitive<std::vector<int16_t>>::Inspect(ref.maxsp, path);
			case 2:
				return Primitive<std::vector<int16_t>>::Inspect(ref.attack, path);
			case 3:
				return Primitive<std::vector<int16_t>>::Inspect(ref.defense, path);
			case 4:
				return Primitive<std::vector<int16_t>>::Inspect(ref.spirit, path);
			case 5:
				return Primitive<std::vector<int16_t>>::Inspect(ref.agility, path);
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

#ifdef LCF_DEBUG_TRACE_INSPECT
std::vector<std::string> RawStruct<rpg::Parameters>::TracePath(const rpg::Parameters& ref, InspectPath& path) {
	return std::vector<std::string> { "<not-traced>" };
}
#endif

} //namespace lcf
