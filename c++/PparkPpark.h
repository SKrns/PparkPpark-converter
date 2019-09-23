#pragma once

#include <string>
#include <sstream>

namespace
{
	std::string Encode(std::string word)
	{
		std::stringstream stream;
		for (auto c : word)
		{
			for (int i = 0; i < 8; i++)
			{
				if (c & (1 << (7 - i)))
					stream << "–Ù";
				else
					stream << "ºý";
			}
			stream << std::endl;
		}
		return stream.str();
	}

	std::string Decode(std::string word, char delimiter = '\n')
	{
		std::string result;
		std::stringstream stream(word);
		while (std::getline(stream, word, delimiter))
		{
			char character = 0;
			for (int i = 0; i < 8; i++)
			{
				if (word[i * 2] == "–Ù"[0]/* && word[i * 2 + 1] == "–Ù"[1]*/)
					character |= 1 << (7 - i);
			}
			result.push_back(character);
		}
		return result;
	}
}