//
//  movieContainer.hpp
//  videoKeyboard64
//
//  Created by Gnlc Elia on 24/11/2018.
//

#ifndef movieContainer_hpp
#define movieContainer_hpp

#include <stdio.h>
#include "ofxHapPlayer.h"
#include "fontPlayer.hpp"
#include "imagePlayer.hpp"




enum class MovieType {
    not_loaded,
    hap,
    txt,
    image,
    capture
};

class MovieContainer {
    
    ofxHapPlayer *hapMovie;
    MultiFontPlayer *fontPlayer;
    //FontPlayer *fontPlayer;
    ImagePlayer *imagePlayer;

    
    public:
    
        MovieType contentType;

    
        bool load(std::string name);
        void capture(int deviceId);
        virtual ofTexture *         getTexture();
        virtual float               getWidth() const;
        virtual float               getHeight() const;
    
        virtual float               getPosition() const;
        virtual void                setPosition(float pct);
        virtual float               getDuration() const;
    
        virtual void                setLoopState(ofLoopType state);
        virtual ofLoopType          getLoopState() const;

        virtual bool                isPlaying() const;
        virtual void                setSpeed(float speed);
        virtual void                setVolume(float volume); // 0..1

        virtual void                play();
        virtual void                stop();
        virtual void                nextFrame();
        virtual void                update();
    
    virtual void                    setColor(ofColor col);
    
    void                        setFontScale(float scale);
    void                        setImageNegative(bool negative);
    
    ofTexture getFontTexture();

    
        /*
        virtual void                draw(float x, float y);
        virtual void                draw(float x, float y, float width, float height);*/
    
    
};

#endif /* movieContainer_hpp */
