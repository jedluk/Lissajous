//
// Created by jedrzej on 2018-02-20.
//

#ifndef LISSAJOUS_ISCENEOBSERVER_H
#define LISSAJOUS_ISCENEOBSERVER_H

class ISceneObserver {
public:
    virtual void handleSaveBitmapEvent() = 0;
    virtual void handleRefreshParamsEvent() = 0;
};
#endif //LISSAJOUS_ISCENEOBSERVER_H
