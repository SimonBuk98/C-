#ifndef ALBUM_H
#define ALBUM_H

/*Class declaration */ 
class Album{
  public:
  Album();
  Album(std::string title, Artist artist);
  std::string getTitle();
  int getCount();
  Artist getArtist();
  void addTrack(Track);
  int getTotalLength();
  private:
  std::string title;
  Artist artist;
  std::vector<Track> tracks;
  int count;
};
#endif
