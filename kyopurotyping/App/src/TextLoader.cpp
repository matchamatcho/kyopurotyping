#include "TextLoader.h"

TextLoader::TextLoader(const FilePath& filePath)
	:m_filepath(filePath), m_isLoaded(false)
{
	if (not filePath.isEmpty())
	{
		Load(filePath);
	}
}

bool TextLoader::Load(const FilePath& filePath)
{
	m_filepath = filePath;
	m_lines.clear();
	m_isLoaded = false;

	TextReader reader{ filePath };
	if (not reader)
	{
		Print << U"ファイルを開けませんでした:" << filePath;
		return false;
	}

	String line;
	while (reader.readLine(line))
	{
		line = line.trim();
		if (not line.isEmpty())
		{
			m_lines << line;
		}
	}

	m_isLoaded = (not m_lines.isEmpty());
	if (m_isLoaded)
	{
		Print << U"読み込み完了:" << filePath;
	}
	else
	{
		Print << U"行が見つからない：" << filePath;

	}
	return m_isLoaded;
}


const Array<String>& TextLoader::GetAllLines() const
{
	return m_lines;
}
bool TextLoader::IsLoaded() const
{
	return m_isLoaded;
}

const String& TextLoader::GetFilePath() const
{
	return m_filepath;
}
void TextLoader::PrintAllLines() const
{
	Print << U"---" << m_filepath << U"の内容---";
	for (auto& line : m_lines)
	{
		Print << line;
	}
	Print << U"---以上---";
}



