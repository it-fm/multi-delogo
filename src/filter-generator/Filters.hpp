#ifndef FILTERS_H
#define FILTERS_H

#include <string>
#include <ostream>

namespace fg {
  enum class FilterType
  {
    NO_OP,
    DELOGO,
    DRAWBOX
  };


  class Filter
  {
  public:
    virtual ~Filter();

    virtual FilterType type() const = 0;
    virtual std::string save_str() const = 0;
    virtual std::string ffmpeg_str(const std::string& between_expr) const = 0;
  };


  class NullFilter : public Filter
  {
  public:
    static NullFilter* load(const std::string& parameters);

    virtual FilterType type() const;
    virtual std::string save_str() const;
    virtual std::string ffmpeg_str(const std::string& between_expr) const;
  };


  class RectangularFilter : public Filter
  {
  protected:
    RectangularFilter(int x, int y, int width, int height);

  public:
    int x() const;
    int y() const;
    int width() const;
    int height() const;

  protected:
    std::string rectangle_save_str() const;
    std::string rectangle_ffmpeg_str() const;

  private:
    int x_;
    int y_;
    int width_;
    int height_;
  };


  class DelogoFilter : public RectangularFilter
  {
  public:
    DelogoFilter(int x, int y, int width, int height);

    virtual FilterType type() const;
    virtual std::string save_str() const;
    virtual std::string ffmpeg_str(const std::string& between_expr) const;
  };


  class DrawboxFilter : public RectangularFilter
  {
  public:
    DrawboxFilter(int x, int y, int width, int height);

    virtual FilterType type() const;
    virtual std::string save_str() const;
    virtual std::string ffmpeg_str(const std::string& between_expr) const;
  };
}

#endif // FILTERS_H
