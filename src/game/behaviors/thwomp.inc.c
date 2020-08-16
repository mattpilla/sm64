// thwomp.c.inc

void grindel_thwomp_act_4(void) {
    if (o->oTimer == 0)
        o->oThwompRandomTimer = 0.0f;
    if (o->oTimer > o->oThwompRandomTimer)
        o->oAction = 0;
}

void grindel_thwomp_act_2(void) {
    o->oVelY += -44.0f;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY) {
        o->oPosY = o->oHomeY;
        o->oVelY = 0;
        o->oAction = 3;
    }
}

void grindel_thwomp_act_3(void) {
    if (o->oTimer == 0)
        if (o->oDistanceToMario < 3500.0f) {
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        }
    if (o->oTimer > 9)
        o->oAction = 4;
}

void grindel_thwomp_act_1(void) {
    if (o->oTimer == 0)
        o->oThwompRandomTimer = 0.0f;
    if (o->oTimer > o->oThwompRandomTimer)
        o->oAction = 2;
}

void grindel_thwomp_act_0(void) {
    if (o->oBehParams2ndByte < o->oTimer) {
        o->oAction = 1;
        o->oPosY += 255.0f;
    } else
        o->oPosY += 250.0f;
}

void (*sGrindelThwompActions[])(void) = { grindel_thwomp_act_0, grindel_thwomp_act_1,
                                          grindel_thwomp_act_2, grindel_thwomp_act_3,
                                          grindel_thwomp_act_4 };

void bhv_grindel_thwomp_loop(void) {
    cur_obj_call_action_function(sGrindelThwompActions);
}
