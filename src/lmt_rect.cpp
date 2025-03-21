/*
 * This file is part of liblcf. Copyright (c) liblcf authors.
 * https://github.com/EasyRPG/liblcf - https://easyrpg.org
 *
 * liblcf is Free/Libre Open Source Software, released under the MIT License.
 * For the full copyright and license information, please view the COPYING
 * file that was distributed with this source code.
 */

#include "lcf/lmt/reader.h"
#include "lcf/lmt/chunks.h"
#include "reader_struct.h"

namespace lcf {

template <>
struct RawStruct<rpg::Rect> {
	static void ReadLcf(rpg::Rect& ref, LcfReader& stream, uint32_t length);
	static void WriteLcf(const rpg::Rect& ref, LcfWriter& stream);
	static int LcfSize(const rpg::Rect& ref, LcfWriter& stream);
	static void WriteXml(const rpg::Rect& ref, XmlWriter& stream);
	static void BeginXml(rpg::Rect& ref, XmlReader& stream);
	static InspectResult Inspect(const rpg::Rect& ref, InspectPath& path);
#ifdef LCF_DEBUG_TRACE_INSPECT
	static std::vector<std::string> TracePath(const rpg::Rect& ref, InspectPath& path);
#endif
};

/**
 * Reads MapInfo Rect.
 */
void RawStruct<rpg::Rect>::ReadLcf(rpg::Rect& ref, LcfReader& stream, uint32_t length) {
	assert(length == 16);
	(void)length;
	stream.Read(ref.l);
	stream.Read(ref.t);
	stream.Read(ref.r);
	stream.Read(ref.b);
}

void RawStruct<rpg::Rect>::WriteLcf(const rpg::Rect& ref, LcfWriter& stream) {
	stream.Write(ref.l);
	stream.Write(ref.t);
	stream.Write(ref.r);
	stream.Write(ref.b);
}

int RawStruct<rpg::Rect>::LcfSize(const rpg::Rect& /* ref */, LcfWriter& /* stream */) {
	return 4 * 4;
}

void RawStruct<rpg::Rect>::WriteXml(const rpg::Rect& ref, XmlWriter& stream) {
	stream.BeginElement("Rect");
	stream.WriteNode<int32_t>("l", ref.l);
	stream.WriteNode<int32_t>("t", ref.t);
	stream.WriteNode<int32_t>("r", ref.r);
	stream.WriteNode<int32_t>("b", ref.b);
	stream.EndElement("Rect");
}

class RectXmlHandler : public XmlHandler {
private:
	rpg::Rect& ref;
	uint32_t* field;
public:
	RectXmlHandler(rpg::Rect& ref) : ref(ref), field(NULL) {}
	void StartElement(XmlReader& /* stream */, const char* name, const char** /* atts */) {
		if (strcmp(name, "l") == 0)
			field = &ref.l;
		else if (strcmp(name, "t") == 0)
			field = &ref.t;
		else if (strcmp(name, "r") == 0)
			field = &ref.r;
		else if (strcmp(name, "b") == 0)
			field = &ref.b;
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
			XmlReader::Read(*field, data);
	}
};

void RawStruct<rpg::Rect>::BeginXml(rpg::Rect& ref, XmlReader& stream) {
	stream.SetHandler(new WrapperXmlHandler("Rect", new RectXmlHandler(ref)));
}

constexpr std::array<std::pair<const char*, int>, 4> tags_to_id = {{
	{ "l", 0},
	{ "t", 1},
	{ "r", 2},
	{ "b", 3}
}};

InspectResult RawStruct<rpg::Rect>::Inspect(const rpg::Rect& obj, InspectPath& path) {
	auto handle_field_id = [&](int field_id) {
		switch (field_id) {
			case 0:
				return Primitive<int32_t>::Inspect(obj.l, path);
			case 1:
				return Primitive<int32_t>::Inspect(obj.t, path);
			case 2:
				return Primitive<int32_t>::Inspect(obj.r, path);
			case 3:
				return Primitive<int32_t>::Inspect(obj.b, path);
		}
		return InspectResult();
	};

	if (path.UseTags()) {
		return path.HandleContainer([&](std::string_view field_tag) {
			auto it = std::find_if(tags_to_id.begin(), tags_to_id.end(), [&field_tag](auto& p) { return field_tag == p.first; });
			if (it != tags_to_id.end()) {
				return handle_field_id(it->second);
			}
			return InspectResult();
		});
	}
	return path.HandleContainer(handle_field_id);
}

#ifdef LCF_DEBUG_TRACE_INSPECT
std::vector<std::string> RawStruct<rpg::Rect>::TracePath(const rpg::Rect& ref, InspectPath& path) {
	return std::vector<std::string> { "<not-traced>" };
}
#endif

} //namespace lcf
