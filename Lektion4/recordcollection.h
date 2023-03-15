#ifndef RECORDCOLLECTION_H
#define RECORDCOLLECTION_H

/*Class declaration */ 
class RecordCollection{
  public:
    RecordCollection();
    RecordCollection(std::string title);
    int tracksInCollection();
    void addAlbum();
  private: 
    std::string title;
    std::vector<Album> albums;
}

#endif
