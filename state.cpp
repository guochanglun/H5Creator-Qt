#include "state.h"
#include "QList"
#include "page.h"
#include "QDebug"
#include "QWidget"
#include "QFile"
#include "QTextStream"

State::State()
{
    this->pageList = new QList<Page>();
    this->currentPageIndex = 0;
}

QList<Page> *State::getPageList() const
{
    return pageList;
}

Page State::getCurrentPage() const
{
    return this->pageList->at(this->currentPageIndex);
}

QString State::jsonData() const
{
    QString data = "var data = {";
    data += "\"bgm\":\"" + this->bgm + "\",";
    if(this->isMusicAutoPlay){
        data += "\"autoplay\": true,";
    }else{
        data += "\"autoplay\": false,";
    }

    data += "pages: [";
    for(int i = 0; i<this->pageList->size(); i++){
        data += this->pageList->at(i).getJson() + ",";
    }
    data += "]}";

    return data;
}

void State::appendPage(const Page page){
    this->pageList->append(page);
    this->currentPageIndex += 1;
}

void State::deletePage(){

    this->pageList->removeAt(this->currentPageIndex);

    if(this->currentPageIndex == 0){
        Page page;
        this->pageList->append(page);
        return;
    }

    if(this->hasNext()){
        this->goNextPage();
    }else if(this->hasPre()){
        this->goPrePage();
    }
}

bool State::hasNext(){
    if(this->currentPageIndex < this->pageList->size() - 1){
        return true;
    }
    return false;
}

bool State::hasPre(){
    if(this->currentPageIndex > 0){
        return true;
    }
    return false;
}

Page State::nextPage(){
    return this->pageList->at(this->currentPageIndex + 1);
}

Page State::prePage(){
    return this->pageList->at(this->currentPageIndex - 1);
}

void State::goNextPage(){
    this->currentPageIndex ++;
}

void State::goPrePage(){
    this->currentPageIndex -- ;
}

void State::refreshAllPages()
{
//    for(int i = 0, size = this->pageList->size(); i < size; i++){
//        Page page = this->pageList->at(i);
//        QList<Object*> lists = page.getElementMap()->values();
//        for(int j = 0, count = lists.size(); j < count; j++){
//            int left = this-> * Const::PHONE_WIDTH / 100 + Const::PHONE_X;
//            int top = this->attr->getTop().toInt() * Const::PHONE_HEIGHT / 100 + Const::PHONE_Y;

//            static_cast<QWidget*>(lists.at(i))->move(left, top);
//        }
//    }
}

bool State::getIsMusicAutoPlay() const
{
    return isMusicAutoPlay;
}

void State::setIsMusicAutoPlay(bool value)
{
    isMusicAutoPlay = value;
}

QString State::getBgm() const
{
    return bgm;
}

void State::setBgm(const QString &value)
{
    bgm = value;
}
