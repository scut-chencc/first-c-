#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Word
{
	std::string word;
	int freq;
};

class WordStatic
{
	public:
		void read_file(const std::string& filename);
		void write_file(const std::string& filename);
	private:
		std::vector<struct Word> word_vector;
};

void WordStatic::read_file(const std::string& filename)
{
	std::ifstream ifs(filename.c_str());
	if(ifs.good()==0)
	{
		std::cout<<"open readfile failed"<<std::endl;
		return;
	}
	std::string str;
	std::vector<struct Word>::iterator it;
	while(ifs>>str)
	{
		for(it==word_vector.begin();it!=word_vector.end();++it)
		{
			//if(str.compare((*it).word)==0)
			if(str==(*it).word)
			{
				++((*it).freq);
				break;
			}
		}
		if(it==word_vector.end())
		{
			struct Word new_word;
			new_word.word=str.c_str();
			new_word.freq=1;
			word_vector.push_back(new_word);
		}
	}
	for(it==word_vector.begin();it!=word_vector.end();++it)
	{
		std::cout<<"word is "<<(*it).word<<",freq is"<<(*it).freq<<std::endl;
	}
}

void WordStatic::write_file(const std::string& filename)
{
	int a=2;
}

int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		std::cout<<"error args!"<<std::endl;
	}
	WordStatic ws;
	ws.read_file(argv[1]);
	return 0;
}
