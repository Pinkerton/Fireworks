//
//  ParticleSystem.cpp
//  Fireworks
//
//  Created by Stephen Pinkerton on 12/5/13.
//
//

#include <thread>
#include "cinder/audio/Output.h"
#include "cinder/audio/Io.h"
#include "ParticleSystem.h"
#include "Emitter.h"
#include "Resources.h"

using namespace ci;
using namespace ci::app;
using namespace std;

std::list<Emitter> ParticleSystem::emitters = std::list<Emitter>();
//std::list<thread> ParticleSystem::threads = std::list<thread>();
//audio::SourceRef ParticleSystem::mAudioSource = audio::load(loadResource(RES_BOOMWAV));

void ParticleSystem::mouseDown(MouseEvent event) {
    addEmitter(event.getPos());
}

void ParticleSystem::mouseDrag(MouseEvent event) {
    mouseDown(event);
}

void ParticleSystem::update() {
    for (auto e = emitters.begin(); e != emitters.end(); ++e) {
        e->update();
        if (e->isDone()) {
            // this is causing sluggishness for some reason
            //if (e->shouldRespawn()) addEmitter(e->getLoc());
            e = emitters.erase(e);
        }
    }
}

void ParticleSystem::draw() {
	gl::clear(Color(0, 0, 0));
    for (auto e = emitters.begin(); e != emitters.end(); ++e) {
        e->draw();
    }
}

void ParticleSystem::addEmitter(Vec2f loc) {
    //audio::Output::play(mAudioSource);
    emitters.push_back(Emitter(loc, false));
    //thread emitterThread();
}
