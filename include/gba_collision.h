#ifndef __GBA_COLLISION_H__
#define __GBA_COLLISION_H__

#include "gba_types.h"
#include "ball.h"
#include "paddle.h"

extern bool IsColliding(Ball* a_ball, Paddle* a_paddle);

#endif //__GBA_COLLISION_H__