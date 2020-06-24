#ifndef __BASE_SEARCH_H__
#define __BASE_SEARCH_H__

class BaseSearch {
public:
    BaseSearch(){};
    ~BaseSearch(){};

    virtual void search (void)=0;
private:
};

#endif