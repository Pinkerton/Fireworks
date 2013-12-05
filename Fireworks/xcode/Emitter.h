//
//  Emitter.h
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/4/13.
//
//

#ifndef __Fireworks__Emitter__
#define __Fireworks__Emitter__

#include <iostream>

#include "Particle.h"

class Emitter {
public:
    Emitter(ci::Vec2f pos);
    void draw();
    void update();
    bool isDone();
    
    
private:
    ci::Vec3f randHSV();
    ci::Color hsvToRGB(ci::Vec3f hsv);
    float rgbToOGL(float value);
    float goldenRatio(float value);
    
    std::list<Particle> mParticles;
    ci::Vec2f mLoc;
    
    int NUM_PARTICLES = 100;
};

#endif /* defined(__Fireworks__Emitter__) */
