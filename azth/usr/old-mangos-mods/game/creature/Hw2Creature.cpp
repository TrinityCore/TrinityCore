#include "Hw2Creature.h"
#include "Hw2SystemMgr.h"
#include "ObjectMgr.h"
#include "Creature.h"
#include "Player.h"

Hw2Creature::Hw2Creature(Creature *cr) {
    creature = cr;
    react_timer=1000; 
    walk_timer=0; 
    customScriptID = 0;
    saved_target= 0;
    azGuard = false;
}

void Hw2Creature::AzerothRpgFunctions(uint8 tipo, uint32 diff) {

    Player *target = NULL;
    int parlato = 70; // un numero qualsiasi tranne che 0

    target = sObjectMgr->GetPlayerByLowGUID(GUID_LOPART(saved_target));
    if (walk_timer != 0)
        if (walk_timer < diff) {
            walk_timer = 0;
        } else {
            if (target && creature->GetDistance(target) <= 1.5f) {
                creature->StopMoving();
                target->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
                target->PrepareGossipMenu(creature,creature->GetCreatureTemplate()->GossipMenuId,true);
                target->SendPreparedGossip(creature);
                walk_timer = 0;
                return;
            }
        }


    switch (tipo) {

        case 1:
            if (!creature->IsServiceProvider())
                return;

            if (react_timer < diff) {
                react_timer = 0;
                if (creature->IsInCombat()) // ritorna se e' in combattimento
                    return;

                target = (Player*) sHw2->AzerothSelectNearbyFrTarget(creature);

                if (!target || target->GetGUID() == saved_target)
                    return;

                if (creature->isInFrontInMap(target, ATTACK_DISTANCE + 2.0f, 4)) {

                    if (creature->IsGuard()) {
                        parlato = sHw2->ProcessList(1, target, creature);
                        if (parlato == 0) react_timer = 50000;
                    }
                    else if (creature->IsQuestGiver()) {
                        parlato = sHw2->ProcessList(3, target, creature);
                        if (parlato == 0) react_timer = 150000;
                    }
                    else if (creature->IsArmorer()) {
                        parlato = sHw2->ProcessList(4, target, creature);
                        if (parlato == 0) react_timer = 70000;
                    }
                    else if (creature->IsBanker()) {
                        parlato = sHw2->ProcessList(5, target, creature);
                        if (parlato == 0) react_timer = 50000;
                    }
                    else if (creature->IsBattleMaster()) {
                        parlato = sHw2->ProcessList(7, target, creature);
                        if (parlato == 0) react_timer = 120000;
                    }
                    else if (creature->IsInnkeeper()) {
                        parlato = sHw2->ProcessList(8, target, creature);
                        if (parlato == 0) react_timer = 70000;
                    }
                    else if (creature->IsTrainer()) {
                        parlato = sHw2->ProcessList(9, target, creature);
                        if (parlato == 0) react_timer = 120000;
                    }
                    else if (creature->IsAuctioner()) {
                        parlato = sHw2->ProcessList(10, target, creature);
                        if (parlato == 0) react_timer = 80000;
                    }
                    else if (creature->IsTaxi()) {
                        parlato = sHw2->ProcessList(11, target, creature);
                        if (parlato == 0) react_timer = 120000;
                    } else if (creature->IsVendor()) {
                        parlato = sHw2->ProcessList(2, target, creature);
                        if (parlato == 0) react_timer = 110000;
                    }
                    else if (creature->IsCivilian()) {
                        parlato = sHw2->ProcessList(6, target, creature);
                        if (parlato == 0) react_timer = 120000;
                    }

                    // if ( parlato==0) 
                    saved_target = target->GetGUID(); //salva anche se non ha parlato , cosi' evita di salutare dopo tanto tempo
                }

            } else react_timer -= diff;

            break;
    }

    return;
}
