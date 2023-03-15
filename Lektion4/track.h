#ifndef TRACK_H
#define TRACK_H

/*Class declaration */ 
class Track{
  public:
    Track();
    Track(std::string title, int length);
    std::string getTitle();
    int getLength();
  private: 
    std::string title;
    int length;
}

#endif
