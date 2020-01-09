#include <cinttypes>
#include <iostream>
#include <sstream>

enum PixelType {
  Full = '\xDB',
  LHalf = '\xDC',
  UHalf = '\xDF'
}

struct Color {
  std::uint8_t r;
  std::uint8_t g;
  std::uint8_t b;

  Color(std::uint8_t, std::uint8_t, std::uint8_t);
}

struct Pixel {
  Color fg;
  Color bg;

  Pixel(Color, Color);
}

class QyloEngine {

private:
  Pixel[25][80] _pdata;

public:
  Pixel SetPixel(PixelType, Pixel, std::uint32_t, std::uint32_t);
  Pixel GetPixel(std::uint32_t, std::uint32_t);

public:
  virtual void Update();
  virtual void Setup();

private:
  void Draw();

public:
  void Start();
};

