#pragma once

#include "KeyValues.h"

#include <cstdint>
#include <string>
#include <unordered_map>

class CModule;

class CGameConfig
{
public:
	CGameConfig(const std::string& gameDir, const std::string& path);
	~CGameConfig();

	bool Init(IFileSystem *filesystem, char *conf_error, int conf_error_size);
	const std::string GetPath();
	const char *GetLibrary(const std::string& name);
	const char *GetSignature(const std::string& name);
	const char* GetSymbol(const char *name);
	int GetOffset(const std::string& name);
	CModule **GetModule(const char *name);
	bool IsSymbol(const char *name);
	void *ResolveSignature(const char *name);
	static std::string GetDirectoryName(const std::string &directoryPathInput);
	static int HexStringToUint8Array(const char* hexString, uint8_t* byteArray, size_t maxBytes);
	static byte *HexToByte(const char *src, size_t &length);

private:
	std::string m_szGameDir;
	std::string m_szPath;
	KeyValues* m_pKeyValues;
	std::unordered_map<std::string, int> m_umOffsets;
	std::unordered_map<std::string, std::string> m_umSignatures;
	std::unordered_map<std::string, std::string> m_umLibraries;
};
