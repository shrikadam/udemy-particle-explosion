#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace cst;

int main(int argv, char** args)
{
	
    srand(time(NULL));
    
    Screen scr;

    if(!scr.init()) {
		SDL_GetError();
	}

    Swarm swm;
    
    while(true){

        int elapsed = SDL_GetTicks();

        swm.update(elapsed);

        unsigned char red = (unsigned char)((1+sin(elapsed*0.001))*128);
        unsigned char green = (unsigned char)((1+sin(elapsed*0.002))*128);
        unsigned char blue = (unsigned char)((1+sin(elapsed*0.003))*128);

        const Particle* const pParticles = swm.getParticles();

        for(int i=0; i<Swarm::NPARTICLES; i++){
            Particle particle = pParticles[i];

            int x = (particle.m_x + 1)*Screen::SCREEN_WIDTH/2;
			int y = particle.m_y*Screen::SCREEN_WIDTH/2+Screen::SCREEN_HEIGHT/2;

            scr.setPixel(x, y, red, green, blue);
        }

        scr.boxBlur();

        scr.update();

        if(!scr.processEvents())
            break; 

    }

    scr.close();   

	return 0;
}