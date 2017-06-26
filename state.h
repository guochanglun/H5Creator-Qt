#ifndef STATE_H
#define STATE_H

#include "QList"
#include "page.h"

class State
{

public:
    State();

    QList<Page> *getPageList() const;

    bool getIsMusic() const;
    void setIsMusic(bool value);

    Page getCurrentPage() const;

    QString jsonData() const;

    void appendPage(const Page page);
    void deletePage();

    bool hasNext();
    bool hasPre();

    Page nextPage();
    Page prePage();

    void goNextPage();
    void goPrePage();

    void refreshAllPages();
    bool getIsMusicAutoPlay() const;
    void setIsMusicAutoPlay(bool value);

    QString getBgm() const;
    void setBgm(const QString &value);

private:
    QList<Page> *pageList;
    bool isMusicAutoPlay = true;
    QString bgm;
    int currentPageIndex;
};

#endif // STATE_H
