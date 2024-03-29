#ifndef _CAMERA_H_
#define _CAMERA_H_ 

#include "gameObject.h"
#include "behaviours.h"

class camera : public gameObject
{
	protected:
		behaviour* loc;

	public:
		camera(abstractObject* parent);
		virtual ~camera() {};
		virtual void update(double delta);
		virtual void render() {};
		virtual void debug() {};
		virtual void setBehaviour(behaviour* loc);
		virtual behaviour* getBehaviour() {return loc;};

		/* data */
};
#endif /* #ifndef _CAMERA_H_ */