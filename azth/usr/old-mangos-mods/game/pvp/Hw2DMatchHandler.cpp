#include "Hw2SystemMgr.h"
#include "SharedDefines.h"
#include "Pet.h"
#include "Player.h"
#include "Creature.h"
#include "Bag.h"
#include "Chat.h"
#include "Config.h"
#include "World.h"
#include "Hw2ChatHandler.h"
#include "Opcodes.h"

//
//  Azeroth TOURNAMENT FUNZIONI
//

void Hw2Class::DmSvuotaBorse(Player* plTarget) {
    bool update = true;
    bool unequip_check = false;
    Item *pItem;
    //    ItemPrototype const *pProto;
    uint32 remcount = 0;

    // in inventory
    for (int i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; i++) {
        pItem = plTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem && pItem->GetEntry() != 800002 && pItem->GetEntry() != 6948) {
            plTarget->DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
        }
    }
    for (int i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; i++) {
        pItem = plTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem) {
            plTarget->DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
            /*pProto = pItem->GetProto();
            ItemRemovedQuestCheck( pItem->GetEntry(), 0);
            pItem->SetCount(0);
            if( IsInWorld() & update )
                    pItem->SendUpdateToPlayer( this );
            pItem->SetState(ITEM_CHANGED, this);*/
        }
    }

    // in inventory bags
    Bag *pBag;
    ItemTemplate const *pBagProto;
    for (int i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; i++) {
        pBag = (Bag*) plTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pBag) {
            pBagProto = pBag->GetTemplate();
            if (pBagProto) {
                for (uint32 j = 0; j < pBagProto->ContainerSlots; j++) {
                    pItem = pBag->GetItemByPos(j);
                    if (pItem && pItem->GetEntry() != 800002 && pItem->GetEntry() != 6948) {
                        plTarget->DestroyItem(i, j, update);
                    }
                }
            }
        }
    }

    // in equipment and bag list
    for (int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_BAG_END; i++) {
        pItem = plTarget->GetItemByPos(INVENTORY_SLOT_BAG_0, i);
        if (pItem) {
            if (!unequip_check || plTarget->CanUnequipItem(INVENTORY_SLOT_BAG_0 << 8 | i, false) == EQUIP_ERR_OK) {
                plTarget->DestroyItem(INVENTORY_SLOT_BAG_0, i, update);
            }
        }
    }
}

void Hw2Class::DmCreaPet(Player *pl, Creature *creature) {

    if (pl->GetPetGUID())
        return;

    if (!creature)
        return;

    Creature* creatureTarget = creature;

    if (creatureTarget->IsPet())
        return;

    Pet* pet = new Pet(pl,HUNTER_PET);
    if (!pet->CreateBaseAtCreature(creatureTarget)) {
        delete pet;
        return;
    }

    // kill original creature
    creatureTarget->setDeathState(JUST_DIED);
    creatureTarget->RemoveCorpse();
    creatureTarget->SetHealth(0); // just for nice GM-mode view

    uint32 level = (creatureTarget->getLevel() < (pl->getLevel() - 5)) ? (pl->getLevel() - 5) : creatureTarget->getLevel();

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);
    pet->GetMap()->AddToActive((Creature*) pet);
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

    if (pl->GetTypeId() == TYPEID_PLAYER) {
        pet->SetFreeTalentPoints(16); // 350 nella 2.4.3 - 16 nella 3.0 
        pl->SetPetGUID(pet->GetGUID());
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        pl->PetSpellInitialize();
    }

}

void Hw2Class::DmAddItemSet(Player* plTarget, uint32 itemsetId) {

    // prevent generation all items with itemset field value '0'
    if (itemsetId == 0) return;

    QueryResult result = Hw2Database.PQuery("SELECT `item_id`,`stack` FROM `a_tournament_item_sets` WHERE `item_set` = %u", itemsetId);

    if (!result) {
        return;
    }

    do {
        Field *fields = result->Fetch();
        uint32 itemId = fields[0].GetUInt32();
        uint32 stack = fields[1].GetUInt32();

        //Adding items
        uint32 noSpaceForCount = 0;

        ItemPosCountVec dest;

        uint8 msg = plTarget->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, stack);
        if (msg == EQUIP_ERR_OK) {
            Item* item = plTarget->StoreNewItem(dest, itemId, true);
            if (stack > 0 && item)
                plTarget->SendNewItem(item, stack, true, false);

        }

    } while (result->NextRow());

    return;
}

void Hw2Class::DmAddSpell(Player *pl, bool tutte, uint32 npclista) {
    if (!tutte) {
        QueryResult result = Hw2Database.PQuery("SELECT `spell` FROM `a_tournament_class_spells` WHERE `class` = %u", pl->getClass());

        if (!result) return;
        do {
            Field *fields = result->Fetch();
            uint32 spell = fields[0].GetUInt32();

            /*  if(sSpellStore.LookupEntry(spell)->powerType == POWER_FOCUS)
              {
                    addSpell(spell,4);                       // active = 4 for spell book of hunter's pet
                    return;
              } */

            if (pl->HasSpell(spell))
                continue;

            pl->learnSpell(spell, false);

        } while (result->NextRow());

        return;
    } else {

        QueryResult result = WorldDatabase.PQuery("SELECT `spell` FROM `npc_trainer` WHERE `entry` = %u", npclista);

        if (!result) return;
        do {
            Field *fields = result->Fetch();
            uint32 spell = fields[0].GetUInt32();

            if (pl->HasSpell(spell))
                continue;

            pl->learnSpell(spell, false);


        } while (result->NextRow());

        return;
    }


}

bool Hw2Class::DmCheckTournament(Player *pl, bool tele, uint32 mapid) {
    if (!TrMod[0]) {

        uint32 plMap = tele ? mapid : pl->GetMapId();

        if (plMap == 44) return true;

        uint32 ZoneTr[2] = {616, 2317}; // ,2177 l'arena nn e' inclusa perche' non deve avere il respawn immediato
        for (uint8 I = 0; I < 2; I++)
            if (pl->GetAreaId() == ZoneTr[I]) return true;
    } else return true;

    return false;
}

void Hw2Class::DmPlayerInfo(Player *pl) {
    if (!pl)
        return;

    // stampa modalit� attivate
    char const* stringa = "";
    char const* stringa2 = " ";
    if (TrMod[0]) stringa = "on";
    else stringa = "off";
    ChatHandler(pl->GetSession()).PSendSysMessage("o==============================================================");
    ChatHandler(pl->GetSession()).PSendSysMessage("| [ Extended DeathMatch ][ DeathMatch esteso ]:  %s ", stringa);
    if (TrMod[1]) stringa = "on";
    else stringa = "off";
    ChatHandler(pl->GetSession()).PSendSysMessage("| [ Points InGroup ][ Punti in Gruppo ]:  %s ", stringa);
    if (TrMod[2]) {
        stringa = "on";
        if (TrMod[3]) stringa2 = "( con raid )( raid enabled )";
        else stringa2 = "( senza raid )( raid disabled )";
    } else {
        stringa = "off";
        stringa2 = " ";
    }
    ChatHandler(pl->GetSession()).PSendSysMessage("|             [ Group ][ Gruppo ]:         %s %s ", stringa, stringa2);
    if (TrMod[4]) stringa = "on";
    else stringa = "off";
    ChatHandler(pl->GetSession()).PSendSysMessage("|               [ Duel ][ Duello ]:         %s ", stringa);
    if (TrMod[5] || pl->GetZoneId() != 616) stringa = "Deathmatch";
    else stringa = "Faction War"; // se non si e' sull'hyjal e' sempre deathmatch
    ChatHandler(pl->GetSession()).PSendSysMessage("|    [Type of Battle][Tipo battaglia]: %s ", stringa);
    ChatHandler(pl->GetSession()).PSendSysMessage("|");
    //stampa punti
    ChatHandler(pl->GetSession()).PSendSysMessage("o=== [Total Points][Totale Accumulato]: %d ", pl->hw2Player->Totale);
    ChatHandler(pl->GetSession()).PSendSysMessage("|   [Kills][Uccisioni]: %u | [Deads][Morti]: %u | [Suicides][Suicidi]: %u ", pl->hw2Player->Uccisioni, pl->hw2Player->Morti, pl->hw2Player->Suicidi);
    ChatHandler(pl->GetSession()).PSendSysMessage("|   [Credits][Crediti]: %d | [Frenzy][Frenesia]: -%u points ", pl->hw2Player->Crediti, (FRENESIA_MAX + 1) - pl->hw2Player->FrenzyCount);
    ChatHandler(pl->GetSession()).PSendSysMessage("o===============================================================");
}

void Hw2Class::DmGestionePunti(Player *pl, bool SalvaSulDb, bool HonorKill, Player *soggetto, bool suicidio) {

    if (!pl->hw2Player->IsTourn)
        return;

    if (SalvaSulDb) {
        pl->UpdateHonorFields();
        QueryResult result = Hw2Database.PQuery("SELECT * FROM `a_tournament_punti` WHERE `guid`= %u", pl->GetGUIDLow());
        if (!result) {
            Hw2Database.PQuery("INSERT INTO `a_tournament_punti` VALUES ('%u','%u','%u','%u','%d','%d')", pl->GetGUIDLow(), pl->hw2Player->Uccisioni, pl->hw2Player->Morti, pl->hw2Player->Suicidi, pl->hw2Player->Crediti, pl->hw2Player->Totale);
            return;
        }
        Hw2Database.PQuery("UPDATE `a_tournament_punti` SET `uccisioni` ='%u' , `morti` ='%u' , `suicidi` = '%u' , `crediti` ='%d', `totale` ='%d' WHERE `guid`='%u'", pl->hw2Player->Uccisioni, pl->hw2Player->Morti, pl->hw2Player->Suicidi, pl->hw2Player->Crediti, pl->hw2Player->Totale, pl->GetGUIDLow());
        return;
    }

    uint32 suono;
    uint32 LostExp = 0, temp = 0;

    if (pl->IsGameMaster() || (soggetto && soggetto->IsGameMaster()))
        return;

    if (!suicidio && (pl->GetTotalPlayedTime() < 1200 || pl->GetAura(2479, SpellEffIndex(0)) || (soggetto && (soggetto->GetAura(2479, SpellEffIndex(0)) || soggetto->GetTotalPlayedTime() < 1200)))) {
        ChatHandler(pl->GetSession()).PSendSysMessage("Non e' avvenuta nessuna modifica ai tuoi punti!");
        ChatHandler(pl->GetSession()).PSendSysMessage("There was no change to your points!");
        return; // honorless aura
    }

    if (HonorKill) {
        if (!TrMod[1] && pl->GetGroup() != NULL) // se l'opzione di guadagno in gruppo e' disattivata e si e' in gruppo, non si guadagna
            return;

        ++pl->hw2Player->Uccisioni;
        if (!pl->hw2Player->Frenesia) {
            if (pl->hw2Player->FrenzyCount < FRENESIA_MAX) ++pl->hw2Player->FrenzyCount;
            else {
                Hw2World *world=new Hw2World(sWorld);
                world->AzerothExtra(pl->GetName().c_str(), 0); // guarda procedura
                pl->GetSession()->SendAreaTriggerMessage("Sei in frenesia! POTENZA MASSIMA RAGGIUNTA");
                pl->GetSession()->SendAreaTriggerMessage("You are in frenzy! MAXIMUM POWER UP");
                pl->hw2Player->Frenesia = true;
                pl->hw2Player->FrenzyCount = 0;
                uint32 spellId[4] = {DEMONIC_FRENZY, SPELL_DAMAGE, AURA_FRENESIA, ELECTROMEDAL};
                for (uint8 I = 0; I < 4; I++)
                    pl->CastSpell(pl, spellId[I], true);
            }
        }

        uint32 lvlexp = 0;
        uint32 honor = pl->hw2Player->Totale < 0 ? 0 : pl->hw2Player->Totale;
        uint32 Shonor = soggetto->hw2Player->Totale < 0 ? 0 : soggetto->hw2Player->Totale;
        ; // cambiato GetHonorPoints() con totale


        if (honor == 0 || Shonor >= (2 * honor)) temp = 10; // divisione per zero (NO) 0 diviso qualcosa (SI)
        else temp = ((10 * Shonor) / (2 * honor)); // honor superiore stessa cosa ma all'inverso
        pl->hw2Player->Crediti += temp * sWorld->getRate(RATE_HONOR);
        pl->hw2Player->Totale += temp * sWorld->getRate(RATE_HONOR);

        if (pl->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) && soggetto->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL)) {
            lvlexp = (urand(998, 1013) * temp) * sWorld->getRate(RATE_XP_KILL); //* (soggetto->getLevel() - getLevel());  ( soggetto->getLevel() + (soggetto->getLevel() - getLevel()))
            pl->GiveXP(lvlexp, soggetto);
        }

        ChatHandler(pl->GetSession()).PSendSysMessage("Hai ucciso %s guadagnando 1 punto uccisione , %u punti credito e %u + rested esperienza!", soggetto->GetName().c_str(), temp, lvlexp);
        ChatHandler(pl->GetSession()).PSendSysMessage("You have killed %s gaining 1 killing point , %u credit points e %u + rested experience!", soggetto->GetName().c_str(), temp, lvlexp);
        pl->GetSession()->SendAreaTriggerMessage("UCCISIONE!");
        pl->GetSession()->SendAreaTriggerMessage("KILL!");
        srand(time(NULL));
        switch (rand() % 13) {
            case 0: suono = 11215;
                break;
            case 1: suono = 11217;
                break;
            case 2: suono = 10564;
                break;
            case 3: suono = 10565;
                break;
            case 4: suono = 11472;
                break;
            case 5: suono = 10282;
                break;
            case 6: suono = 9169;
                break;
            case 7: suono = 11541;
                break;
            case 8: suono = 8293;
                break;
            default: suono = 11215;
                break;
        }
        DmGestioneMusica(pl, suono);
        return;

    } else {

        pl->hw2Player->FrenzyCount = 0;
        pl->hw2Player->Frenesia = false;
        uint32 spellId[4] = {DEMONIC_FRENZY, SPELL_DAMAGE, AURA_FRENESIA, ELECTROMEDAL};
        for (uint8 i = 0; i < 4; i++)
            pl->RemoveAurasDueToSpell(spellId[i]); // rimuove tutte le auree morendo e azzera la frenesia
        // se non si suicidia e muore da un pvp allora:	
        if (!suicidio) {

            if (!TrMod[1] && soggetto->GetGroup() != NULL) // se l'opzione di guadagno in gruppo e' disattivata e si e' in gruppo, non si guadagna
                return;

            uint16 pMorte = 0;
            pMorte = P_UCCISIONE * sWorld->getRate(RATE_HONOR);
            pl->hw2Player->Crediti -= pMorte;
            pl->hw2Player->Totale -= pMorte;

            temp = (urand(998, 1013) * pMorte) * sWorld->getRate(RATE_XP_KILL);
            if (pl->GetUInt32Value(PLAYER_XP) > temp) LostExp = pl->GetUInt32Value(PLAYER_XP) - temp;
            else LostExp = 0;
            if (pl->GetUInt32Value(PLAYER_XP) > 0) pl->SetUInt32Value(PLAYER_XP, LostExp);

            ++pl->hw2Player->Morti;
            ChatHandler(pl->GetSession()).PSendSysMessage("Sei stato ucciso da %s e ti sono stati assegnati + 1 punti morte , - %u crediti e hai perso %u esperienza!", soggetto->GetName().c_str(), pMorte, LostExp);
            ChatHandler(pl->GetSession()).PSendSysMessage("You have been killed by %s and you have gained + 1 death points , - %u credit point and you have lost %u experience!", soggetto->GetName().c_str(), pMorte, LostExp);
            pl->GetSession()->SendAreaTriggerMessage("MORTE!");
            pl->GetSession()->SendAreaTriggerMessage("DEAD!");
        }// altrimenti	
        else {
            uint16 pSuicidio = 0;
            pSuicidio = P_SUICIDIO * sWorld->getRate(RATE_HONOR);
            pl->hw2Player->Crediti -= pSuicidio;
            pl->hw2Player->Totale -= pSuicidio;

            temp = (urand(998, 1013) * pSuicidio) * sWorld->getRate(RATE_XP_KILL);
            if (pl->GetUInt32Value(PLAYER_XP) > temp) LostExp = pl->GetUInt32Value(PLAYER_XP) - temp;
            else LostExp = 0;
            if (pl->GetUInt32Value(PLAYER_XP) > 0) soggetto->SetUInt32Value(PLAYER_XP, LostExp);

            ++pl->hw2Player->Suicidi;
            ChatHandler(pl->GetSession()).PSendSysMessage("Ti sei suicidato! ti sono stati assegnati + 1 punti suicidio, - %u crediti e hai perso %u esperienza!", pSuicidio, LostExp);
            ChatHandler(pl->GetSession()).PSendSysMessage("You have committed suicide! you have gained + 1 suicide point, - %u credit points and you have lost %u experience!", pSuicidio, LostExp);
            pl->GetSession()->SendAreaTriggerMessage("SUICIDIO!");
            pl->GetSession()->SendAreaTriggerMessage("SUICIDE!");
        }

        Hw2Database.PQuery("UPDATE `a_tournament_punti` SET `crediti` ='%d',`totale` ='%d' WHERE `guid`=%u", pl->hw2Player->Crediti, pl->hw2Player->Totale, pl->GetGUIDLow()); // le morti vengono salvate ogni volta <ANTI LAMER>
        srand(time(NULL));
        switch (rand() % 3) {
            case 0: suono = 10566;
                break;
            case 1: suono = 10284;
                break;
            case 2: suono = 8622;
                break;
        }
        DmGestioneMusica(pl, suono);
        return;
    }
    return;
}

bool Hw2Class::ImpostaGiocatore(Player *pl) {

    //AZEROTH COMPLETA QUEST
    Hw2ChatHandler(pl->GetSession()).AzerothQuest(pl);

    if (!pl->hw2Player->IsTourn)
        RpgFunzioneIniziale(pl);
    else {
        if (pl->GetSession()->GetSecurity() <= 0) {
            Hw2World *world=new Hw2World(sWorld);
            world->AzerothExtra(pl->GetName().c_str(), 1); // avverte tutti tranne per i gamemaster
            if (pl->getLevel() < 89) pl->SetLevel(89);
        }

        pl->GetSession()->SendAreaTriggerMessage("WELCOME TO THE DEATHMATCH!");


        if (!pl->getCinematic()) // esegue l'algoritmo solo alla creazione del pg
        {
            pl->setCinematic(1);
            DmSetTournament(pl);
        } else {
            DmGestioneMusica(pl, 8280);
            uint32 spellId[4] = {DEMONIC_FRENZY, SPELL_DAMAGE, AURA_FRENESIA, ELECTROMEDAL};
            for (uint8 i = 0; i < 4; i++)
                pl->RemoveAurasDueToSpell(spellId[i]); // toglie le auree frenesia se le hai 
            QueryResult result2 = Hw2Database.PQuery("SELECT * FROM `a_tournament_punti` WHERE `guid`= %u", pl->GetGUIDLow());
            if (result2) {
                Field *fields = result2->Fetch();
                pl->hw2Player->Uccisioni = fields[1].GetUInt32(); // 0 � uguale al guid
                pl->hw2Player->Morti = fields[2].GetUInt32();
                pl->hw2Player->Suicidi = fields[3].GetUInt32();
                pl->hw2Player->Crediti = fields[4].GetInt32();
                pl->hw2Player->Totale = fields[5].GetInt32();
            }
        }
    }

    // out of date ma da riscrivere
    if (pl->hw2Player->IsTourn) {
        QueryResult result = Hw2Database.PQuery("SELECT `gm_tournament` FROM `a_permessi_comandi` WHERE `AccID`= %u", pl->GetSession()->GetAccountId());
        if (result) {
            Field *fields2 = result->Fetch();
            pl->GetSession()->SetSecurity(AccountTypes(fields2[0].GetUInt32()));
        }
    }

    //INIZIALIZZAZIONE LIVELLO AZ COMANDI
    pl->hw2Player->AccLvl[0] = 0; //inizializzazione
    pl->hw2Player->AccLvl[1] = 0;

    pl->hw2Player->AccLvl[0] = CheckAcc(pl, 1);
    pl->hw2Player->AccLvl[1] = CheckAcc(pl, 2);

    return true;
}

void Hw2Class::DmSetTournament(Player *pl) {
    //inizio operazioni sul player
    //TeleportTo(1, 4700.22f, -3747.74f, 948.00f, 1.7f);   // teleport sull'hyjal
    //InnEnter(time(0),1,4700.22f,-3747.74f,948.00f);          // imposta coordinate per l'innkeeper
    //AzerothSvuotaBorse(this);
    DmAddItemSet(pl, 36); // aggiunta AzerothTournament item
    // player->DestroyItemCount(6948, 1, true);  // distrugge la hearthstone
    // aggiunge tutte le spell, guardare procedura.

    DmAddSpell(pl); //aggiunta delle spell speciali
    Hw2ChatHandler(pl->GetSession()).AzerothSelezionaHandler(1, ""); //insegna tutti i talenti , per poi resettarli.
    uint32 trainerid = 0;
    switch (pl->getClass()) {
        case CLASS_WARRIOR: trainerid = 914;
            break;
        case CLASS_PALADIN: trainerid = 928;
            break;
        case CLASS_HUNTER: trainerid = 5115;
            break;
        case CLASS_ROGUE: trainerid = 13283;
            break;
        case CLASS_PRIEST: trainerid = 376;
            break;
        case CLASS_SHAMAN: trainerid = 17204;
            break;
        case CLASS_MAGE: trainerid = 5146;
            break;
        case CLASS_WARLOCK: trainerid = 461;
            break;
        case CLASS_DRUID: trainerid = 4217;
            break;
        default:
            return;
    }
    DmAddSpell(pl, true, trainerid); // aggiunge tutte le spell del trainer 

    Hw2ChatHandler(pl->GetSession()).AzerothSelezionaHandler(2, (char*) pl->GetName().c_str()); // resetta tutti i talents e le relative spells
    pl->SetSkill(129, 375, 375, 375); //skill riding
    pl->UpdateSkillsToMaxSkillsForLevel(); // max skill

    DmAddItemSet(pl, 35); // borse faretre e ammo poutch

    //mounts
    if (pl->GetTeam() == ALLIANCE)
        DmAddItemSet(pl, 33);
    else if (pl->GetTeam() == HORDE)
        DmAddItemSet(pl, 34);
    // salvataggio
    pl->SaveToDB();

    // musica iniziale
    srand(time(NULL));
    switch (rand() % 2) {
        case 0:
            DmGestioneMusica(pl, 9872); // Moment - Corrupt Intro
            break;
        case 1:
            DmGestioneMusica(pl, 9801); // Moment-SilvermoonIntro
            break;
        default:
            break;
    }
}

bool Hw2Class::DmGestioneMusica(Player *pl, uint32 suono) {
    if (suono >= 0) {
        WorldPacket data(SMSG_PLAY_OBJECT_SOUND, 4 + 8);
        data << suono << pl->GetGUIDLow();
        pl->GetSession()->SendPacket(&data);
        return true;
    }
    return false;
}

void Hw2Class::DmGestioneSpawning(Player *pl, uint32 zona) {

    srand(time(NULL));
    time_t basetime = time(NULL);
    switch (zona) {
            //hyjal
        case 616:
            if (localtime(&basetime)->tm_min <= 29) {
                switch (rand() % 5) {
                    case 0:
                        pl->TeleportTo(1, 5390.15, -2434.85, 1478.11, 6.15058); // respawn a sud 1
                        break;
                    case 1:
                        pl->TeleportTo(1, 5024.23, -2033.16, 1367.56, 5.39973); // respawn a sud 2
                        break;
                    case 2:
                        pl->TeleportTo(1, 5262.54, -2163.45, 1259.48, 3.44645); // respawn a sud 3
                        break;
                    case 3:
                        pl->TeleportTo(1, 5390.15, -2434.85, 1478.11, 6.15058); // respawn a sud 1
                        break;
                    case 4:
                        pl->TeleportTo(1, 4425.89, -1944.96, 1234.55, 5.66173); // respawn a nord 4
                        break;
                }
                ChatHandler(pl->GetSession()).PSendSysMessage("Respawned near Hyjal Ruins, Respawn to the next area between %d min.", 30 - localtime(&basetime)->tm_min);
            } else {
                switch (rand() % 5) {
                    case 0:
                        pl->TeleportTo(1, 4432.64, -2056.72, 1150.93, 5.2238); // respawn a nord 1
                        break;
                    case 1:
                        pl->TeleportTo(1, 4689.84, -2984.1, 1079.88, 4.12031); // respawn a nord 2
                        break;
                    case 2:
                        pl->TeleportTo(1, 4547.23, -3324.28, 992.743, 2.98424); // respawn a nord 3
                        break;
                    case 3:
                        pl->TeleportTo(1, 4425.89, -1944.96, 1234.55, 5.66173); // respawn a nord 4
                        break;
                    case 4:
                        pl->TeleportTo(1, 5262.54, -2163.45, 1259.48, 3.44645); // respawn a sud 3
                        break;
                }
                ChatHandler(pl->GetSession()).PSendSysMessage("Respawned near Hyjal Cave, Respawn to the next area between %d min.", 60 - localtime(&basetime)->tm_min);
            }
            return;
            break;
            //monastero  UNUSED
            /* case 44:
                   switch(rand()%7)
                                       { case 0:
                                       TeleportTo(44,194.161,26.605,30.8391,GetOrientation()); 
                           break;
                                 case 1:   
                                               TeleportTo(44,297.349,-9.147,34.830,GetOrientation());	   
                                         break;
                                             case 2:   
                                               TeleportTo(44,62.548,-12.73,19.677,GetOrientation());	   
                                         break;
                                             case 3:   
                                               TeleportTo(44,187.136,-73.82,19.677,GetOrientation());	   
                                         break;
                                             case 4:   
                                               TeleportTo(44,299.20,-111.56,31.82,GetOrientation());	   
                                         break;
                                             case 5:   
                                               TeleportTo(44,330.42,-105.30,31.82,GetOrientation());	   
                                         break;
                                             case 6:   
                                               TeleportTo(44,417.38,-115.85,33.07,GetOrientation());	   
                                         break;
                                       }
            return;
                    break; */
            // isole
        case 2317:
            switch (rand() % 7) {
                case 0:
                    pl->TeleportTo(1, -11379, -4725.6, 7.0, pl->GetOrientation());
                    break;
                case 1:
                    pl->TeleportTo(1, -11830.9345, -4764.660, 7.80, pl->GetOrientation());
                    break;
                case 2:
                    pl->TeleportTo(1, -11852.059, -4769.70, 6.80, pl->GetOrientation());
                    break;
                case 3:
                    pl->TeleportTo(1, -11908.099, -4576.495, 1.55, pl->GetOrientation());
                    break;
                case 4:
                    pl->TeleportTo(1, -11645.314, -4695.935, 24.95, pl->GetOrientation());
                    break;
                case 5:
                    pl->TeleportTo(1, -11636.442, -4694.920, 11.95, pl->GetOrientation());
                    break;
                case 6:
                    pl->TeleportTo(1, -11378.042, -4800.407, 7.30, 2.35);
                    break;
            }
            return;
            break;

        case 2177:
            pl->TeleportTo(0, -13228.86, 227.076752, 32.86, 1.052);
            return;
            break;
    }
    return;
}
