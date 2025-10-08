#pragma once
#include <Siv3D.hpp>

class TextLoader
{
private:
	Array<String> m_lines;
	String m_filepath;
	bool m_isLoaded;

public:
	// コンストラクタ
	explicit TextLoader(const FilePath& filepath=U"");

	// テキストファイルを読み込む
	bool Load(const FilePath& filepath);

	//すべての行を取得
	const Array<String>& GetAllLines() const;

	//正常に読み込まれたか
	bool IsLoaded() const;

	//読み込まれたファイルパスを取得
	const String& GetFilePath() const;

	//すべての行をコンソールに出力
	void PrintAllLines() const;
};
