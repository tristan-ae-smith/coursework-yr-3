/* inherits UIFrame */

#include <algorithm>
#include <stdio.h>
#include "GameFrame.h"
#include "TODOsphere.h"
#include "TODOtri.h"
#include "planets.h"

// struct planets {
// 	int parent; //index to
// 	float size;	//uh...
// 	float angle;	//ditto
// 	float orbit;	//1 unit = 10% AU
// 	float omega;	//speed
// 	float inc;		//polar inlination
// 	float rot;		//rotational speed
// 	const char* vert;
// 	const char* frag;
// 	const char* geom;
// } pdat[] =
// {//	parent	size	angle	orbit 	omega		inc 	rot 	vert 	frag 	geom
// 	{0, 	2.f, 	0.f, 	0.f, 	0.f, 		0.f,	0.f,	"",		"",		""},//sun
// //	{0, 	.24f, 	0.f, 	3.8f,	1./.24f,	7.f,	0.f,	"",		"",		""},//mercury
// //	{0, 	.60f, 	0.f, 	7.2f,	1./.62f,	3.4f,	0.f,	"",		"",		""},//venus
// //	{0, 	.63f, 	0.f, 	10.f,	1.f,		0.f,	0.f,	"",		"",		""},//earth
// //	{0, 	.33f, 	0.f, 	15.2f,	1./1.8f,	0.f,	0.f,	"",		"",		""},//mars
// };


gameFrame::gameFrame(abstractObject* parent) : UIFrame(parent) {
	// Testing objects
	// planet* sun = new planet(NULL, 1.f);
	// cam = new camera(sun);
	// items.push_back(cam);
	// items.push_back(sun);


	staticBehaviour* sun = new staticBehaviour(NULL, glm::vec3(0.f));
 	cam = new camera(sun);
 	items.push_back(cam);
 	items.push_back(sun);
	items.push_back(new planet(sun, 2.5f));






	// planet* all_p[3];
	// planet* one_p;
	// for (int p = 0; p < 1; p++) {
	// 	one_p = new planet(sun, pdat[p].size);
	// 	one_p->setBehaviour(new orbitBehaviour(one_p, one_p, pdat[p].angle, pdat[p].orbit, pdat[p].omega));
	// 	items.push_back(one_p);
	// }

	// for (int p = 0; p < 1; p++) {
		// one_p = new planet(sun, 2.f);
		// one_p->setBehaviour(new orbitBehaviour(one_p, one_p, 0.f, 0.f, 0.f));
		// items.push_back(one_p);
	// }

	// planet* jupiter = new planet(sun, 2.5f);
	// jupiter->setBehaviour(new orbitBehaviour(jupiter, sun, 0.f, 5.f, 5.f));
	// items.push_back(jupiter);
	// items.push_back(new planet(sun, 1.f));
	// TODOsphere* earth = new TODOsphere(sun, 4.4f);
	// items.push_back(earth);
	// TODOsphere* moon = new TODOsphere(earth, -1.5f);
	// items.push_back(moon);

	// V = glm::mat4(1.);
	// V = glm::translate(V, glm::vec3(0.f, 0.f, -15.0f));
//	 V = glm::rotate(V, 45.f, glm::vec3(1.f, 0.f, 0.f));
	// glm::mat4 Projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
	// VP = Projection * V;
	// gameObject::setVP(&VP);
}

gameFrame::~gameFrame() {
	items.clear();
}

void gameFrame::update(double delta) {
    for (vector<abstractObject*>::iterator item = items.begin();
                           item != items.end();
                           ++item) {
    	(*item)->update(delta);
    }

}

void gameFrame::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (vector<abstractObject*>::iterator item = items.begin();
                           item != items.end();
                           ++item) {
    	(*item)->render();
    }
    // for (vector<abstractObject*>::iterator item = items.begin();
    //                        item != items.end();
    //                        ++item) {
    // 	(*item)->debug();
    // }
}