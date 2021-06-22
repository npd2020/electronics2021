#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

#include "./pnm/pnm.hpp"

using namespace std;

#ifdef __GNUC__
#define DATA_FOLDER "./data/BadApple"
#define OUT_FOLDER "./out"
#endif

void print(PNM::Info const &info)
{
  if (true == info.valid())
  {
    std::cout << "width   = " << info.width() << std::endl;
    std::cout << "height  = " << info.height() << std::endl;
    std::cout << "max     = " << info.max() << std::endl;
    std::cout << "channel = " << info.channel() << std::endl;
    std::cout << "type    = " << (int)info.type() << std::endl;
  }
  else
  {
    std::cout << "Error type" << std::endl;
  }
}

int main(int argc, char *argv[])
{
  ifstream fin;
  ofstream fout;
  fout.open("data.h");
  //fout<<"#include \"binary.h\"\n";
  std::vector<std::uint8_t> data;
  PNM::Info info;
  string inputFile, outputFile;
  char peek;
  for (int i = 1; i <= 6572; i++)
  {
    if (i < 10)
    {
      inputFile = std::string() + DATA_FOLDER "/000" + to_string(i) + ".pbm";
    }
    else if (i < 100)
    {
      inputFile = std::string() + DATA_FOLDER "/00" + to_string(i) + ".pbm";
    }
    else if (i < 1000)
    {
      inputFile = std::string() + DATA_FOLDER "/0" + to_string(i) + ".pbm";
    }
    else if (i < 10000)
    {
      inputFile = std::string() + DATA_FOLDER "/" + to_string(i) + ".pbm";
    }
    outputFile = std::string() + OUT_FOLDER "/BadApple-P1-tmp.pbm";
    //cout << inputFile << endl;
    //cout << outputFile << endl;
    // --- load file  ---
    std::ifstream ifs(inputFile, ios::binary);
    ifs >> PNM::load(data, info);
    //print(info);
    // --- save as P1 ---
    info.type() = PNM::P1;
    std::ofstream ofs;
    ofs.open(outputFile, ios::binary);
    ofs << PNM::save(data, info);
    ofs.close();

    if (i == 1)
      fout << "const uint8_t IMAGES_1[][8] = {\n";
    else if (i == 1000)
      fout << "};\nconst int IMAGES_1_LEN = sizeof(IMAGES_1)/8;\nconst uint8_t IMAGES_2[][8] = {\n";
    else if (i == 2000)
      fout << "};\nconst int IMAGES_2_LEN = sizeof(IMAGES_2)/8;\nconst uint8_t IMAGES_3[][8] = {\n";
    else if (i == 3000)
      fout << "};\nconst int IMAGES_3_LEN = sizeof(IMAGES_3)/8;\nconst uint8_t IMAGES_4[][8] = {\n";
    else if (i == 4000)
      fout << "};\nconst int IMAGES_4_LEN = sizeof(IMAGES_4)/8;\nconst uint8_t IMAGES_5[][8] = {\n";
    else if (i == 5000)
      fout << "};\nconst int IMAGES_5_LEN = sizeof(IMAGES_5)/8;\nconst uint8_t IMAGES_6[][8] = {\n";
    else if (i == 6000)
      fout << "};\nconst int IMAGES_6_LEN = sizeof(IMAGES_6)/8;\nconst uint8_t IMAGES_7[][8] = {\n";

    fin.open(OUT_FOLDER "/BadApple-P1-tmp.pbm");
    fin.seekg(5);

    while (fin.get(peek))
    {
      if (fin.tellg() == 143)
      {
        fout << "},\n";
        break;
      }
      if (fin.tellg() == 6)
        fout << "{\nB";
      else if (fin.tellg() != 7 && peek == '\n')
      {
        fout << ",\nB";
      }
      else if (peek == '1' || peek == '0')
      {
        fout << peek;
      }
    }
    fin.close();
  }
  fout << "};\nconst int IMAGES_7_LEN = sizeof(IMAGES_7)/8;";

  fout.close();
  return EXIT_SUCCESS;
}
