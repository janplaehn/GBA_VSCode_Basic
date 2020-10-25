#include "gba_collision.h"

bool IsColliding(Ball* a_ball, Paddle* a_paddle) {
    s32 top1, left1, bottom1, right1;
    s32 top2, left2, bottom2, right2;

    left1 = a_ball->x;
    right1 = a_ball->x + a_ball->size;
    top1 = a_ball->y;
    bottom1 = a_ball->y + a_ball->size/2;

    left2 = a_paddle->x;
    right2 = a_paddle->x + a_paddle->width;
    top2 = a_paddle->y;
    bottom2 = a_paddle->y + a_paddle->height;

    if (left1 < right2 &&
        right1 > left2 &&
        top1 < bottom2 &&
        bottom1 > top2)
    {
        return true;
    }
    else {
            return false;
    }
}