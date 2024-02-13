/*

    Utility for randomly picking lines out of a file

*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include <utility>

std::string_view    trimmed(std::string_view sv)
{
    if(sv.empty())
        return std::string_view();

    const char* s   = nullptr;
    const char* e   = nullptr;

    for(const char& ch : sv){
        if(!isspace(ch)){
            if(!s)
                s   = &ch;
            e       = &ch;
        }
    }
    
    if(s && e){
        return std::string_view(s, (e-s)+1);
    } else
        return std::string_view();
}


void append(std::vector<std::string>& data, std::istream& in)
{
    static constexpr size_t N = 1024;
    char    buffer[N];
    while(in.good()){
        buffer[0]   = '\0';
        in.getline(buffer, N);
        buffer[N-1] = '\0';
        
        auto sv = trimmed(buffer);
        if(sv.empty())
            continue;
        data.push_back(std::string(sv));
    }
}

int main(int argc, char* argv[])
{
    //  How many?  Default is one (only useful with standard input)
    int     desiredCount    = 1;
    if(argc>1){
        desiredCount        = atoi(argv[1]);
        if(desiredCount < 1){
            std::cerr << "Usage: picklist [number] file1...N\nNumber must be a positive integer!";
            return 0;
        }
    }

    std::vector<std::string>        options;
    if(argc>2){
        for(int n=2;n<argc;++n){
            std::ifstream   fin(argv[n]);
            append(options, fin);
            fin.close();
        }
    } else 
        append(options, std::cin);
        
	std::mt19937_64	engine(std::chrono::high_resolution_clock::now().time_since_epoch().count());

		//	do it once to prime
	engine();
	std::uniform_int_distribution<size_t>		gen(0, options.size() - 1);
    
    
	for(int n=0;n<desiredCount;++n){
		size_t j	= gen(engine);
		std::cout << options[j] << "\n";
	}

    return 0;
   
}

