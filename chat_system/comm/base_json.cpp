
#include "base_json.h"

void serialize(Json::Value &val, std::string &outString)
{
#ifdef _STYLED_
	Json::StyledWriter w;
#else
	Json::FastWriter w;
#endif
	outString = w.write(val);
}

void unserialize(std::string &inString, Json::Value &outVal)
{
	Json::Reader r;
	r.parse(inString, outVal, false);
}
