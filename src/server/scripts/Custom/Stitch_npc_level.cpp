//########################################################################################################################
//Stitch Decembre 2020 - npc_level - version 1.1 , wow 9.0.2.36949 
// PNJ 15000386 : Choix au level 1 : Lieux de depart chez une race allié avec réputation & equipements ou instant level 10
//########################################################################################################################

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "WorldSession.h"
#include "GameEventMgr.h"

class npc_level : public CreatureScript
{
public:
	npc_level() : CreatureScript("npc_level") {}
    struct npc_levelAI : public ScriptedAI
    {
        npc_levelAI(Creature* creature) : ScriptedAI(creature) { }

        bool GossipHello(Player* player) override
	{
        ClearGossipMenuFor(player);//////
		TeamId team = player->GetTeamId();
		uint8 _level = player->getLevel();
		uint8 _race = player->getRace();
		uint8 _class = player->getClass();

		if (_level == 1 && _race != RACE_PANDAREN_NEUTRAL)
		{
            AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Commencer level 10 (TP Capitale)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
           // AddGossipItemFor(player, GOSSIP_ICON_TAXI, "Commencer level 10 (TP Outreterre", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
           }

		if (_level == 1 || (_class == CLASS_DEATH_KNIGHT && _race != RACE_PANDAREN_NEUTRAL))
		{
            /*
            if (_level < 30)
              //  AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Commencer level 10 (TP Norfendre)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);

			if (_level < 35)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Commencer level 10 (TP Pandarie)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);

			if (_level < 40)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Commencer level 10 (Avec TP Draenor)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);

			if (_level < 45)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Commencer level 10 (Avec TP Légion)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);

			if (_level < 50)
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Commencer level 10 (Avec TP BFA)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
			// a voir
           // AddGossipItemFor(player, GOSSIP_ICON_CHAT, "  ", GOSSIP_SENDER_MAIN, -1);
                */
		}

		if (_level == 1 && _race != RACE_PANDAREN_NEUTRAL)
		{
			if (team == TEAM_ALLIANCE)
			{
				if (_race != RACE_HUMAN)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Humains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);			    // Humain
				if (_race != RACE_DWARF)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Nains", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);				// Nain
				if (_race != RACE_NIGHTELF)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Elfes de la nuit", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);	// Elfe de la nuit
				if (_race != RACE_GNOME)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Gnomes", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);			    // Gnome
				if (_race != RACE_DRAENEI)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Draeneis", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);			// Draenei
			}

			if (team == TEAM_HORDE)
			{
				if (_race != RACE_ORC)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Orcs", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);			    // Orc
				if (_race != RACE_UNDEAD_PLAYER)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Mort Vivant", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 8);	        // Mort Vivant
				if (_race != RACE_TAUREN)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Taurens", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 9);      		// Tauren
				if (_race != RACE_TROLL)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Trolls", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 10);		        // Troll
				if (_race != RACE_BLOODELF)
                AddGossipItemFor(player, GOSSIP_ICON_TABARD, "Commencer chez les Elfes de sang", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
			}

            //AddGossipItemFor(player, 9, "  ", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF -1);

		}

        SendGossipMenuFor(player, player->GetGossipTextId(me), me->GetGUID()); // NPC_txt pointant sur BroadcastText
  		return true;
	}

       bool GossipSelect(Player * player, uint32 /*menuId*/, uint32 gossipListId) override
        {
           uint32 const action = player->PlayerTalkClass->GetGossipOptionAction(gossipListId);
           ClearGossipMenuFor(player);

            TeamId team = player->GetTeamId();
            uint8 _class = player->getClass();
            uint8 _level = player->getLevel();
            uint8 _race = player->getRace();

            switch (action)
            {

            case GOSSIP_ACTION_INFO_DEF + 1: // level 10

                player->SetLevel(10);
                player->AddItem(1710, 1);               // Potion de soin
                player->SetSkill(906, 0, 300, 300);     //
                player->LearnSpell(33388, true);        // Apprenti cavalier lvl 10
                //player->LearnSpell(49322, true);        // Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK) || (_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Cuir
                {
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Maille
                {
                }

                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f); // tp Hurlevent 
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f); // tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 2: // level 58

                player->SetLevel(58);
                player->AddItem(22829, 1);			// Potion de soin
                player->SetSkill(906, 0, 300, 300); //
                player->LearnSpell(33388, true);	// Apprenti cavalier lvl 20
                player->LearnSpell(33391, true);	// Compagnon cavalier lvl 40
                //player->LearnSpell(49322, true);	// Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                    player->AddItem(25494, 1); // Baton
                    player->AddItem(14326, 1); // Torse
                    player->AddItem(14334, 1); // Jambe
                    player->AddItem(10247, 1); // Pied
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK) || (_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Cuir
                {

                    player->AddItem(25494, 1); // baton
                    player->AddItem(25101, 2); // dague x2
                    player->AddItem(15285, 1); // arc
                    player->AddItem(24703, 1); // Torse
                    player->AddItem(29939, 1); // Jambe
                    player->AddItem(24702, 1); // Pied

                    if ((_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Cuir
                    {
                        player->SetSkill(413, 0, 300, 300); // Maille
                    }
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Maille
                {
                    player->SetSkill(293, 0, 300, 300);	// Plate
                    player->AddItem(25157, 1);	// epee 2 mains
                    player->AddItem(14751, 1);	// Torse
                    player->AddItem(6386, 1);	// Jambe
                    player->AddItem(4076, 1);	// Pied
                }

                SetSkill_Death_Knight(player, _class);
                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f); // tp Hurlevent 
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f); // tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 3: // level 68

                player->SetLevel(68);
                player->AddItem(39671, 1); // Potion de soin
                player->LearnSpell(33388, true); // Apprenti cavalier lvl 20
                player->LearnSpell(33391, true); // Compagnon cavalier lvl 40
                player->LearnSpell(34090, true); // Expert cavalier 60
                player->LearnSpell(54197, true); // Vol par temps froid lvl 68 
                player->LearnSpell(90267, true); // Licence de maître de vol lvl 60 - Kalimdor et Tréfonds
                //player->LearnSpell(49322, true); // Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                    player->AddItem(29910, 1); // Baton
                    player->AddItem(35965, 1); // Torse
                    player->AddItem(24666, 1); // Jambe
                    player->AddItem(41520, 1); // Pied
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK))	// Cuir
                {
                    player->AddItem(29910, 1); // Baton
                    player->AddItem(29909, 1); // Dague
                    player->AddItem(24743, 1); // Torse
                    player->AddItem(24730, 1); // Jambe
                    player->AddItem(24726, 1); // Pied
                }
                if ((_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Maille
                {
                    player->SetSkill(413, 0, 300, 300); // Maille
                    player->AddItem(29910, 1); // Baton
                    player->AddItem(25247, 1); // arc
                    player->AddItem(24896, 1); // Torse
                    player->AddItem(29968, 1); // Jambe
                    player->AddItem(30004, 1); // Pied
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Plaque
                {
                    player->SetSkill(293, 0, 300, 300); // Plate
                    player->AddItem(36529, 1); // epee 2 mains
                    player->AddItem(25008, 1); // Torse
                    player->AddItem(41763, 1); // Jambe
                    player->AddItem(24983, 1); // Pied
                }

                SetSkill_Death_Knight(player, _class);
                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f); // tp Hurlevent 
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f); // tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 4: // level 80

                player->SetLevel(80);
                player->AddItem(76097, 1); // Potion de soin
                player->LearnSpell(33388, true); // Apprenti cavalier lvl 20
                player->LearnSpell(33391, true); // Compagnon cavalier lvl 40
                player->LearnSpell(34090, true); // Expert cavalier 60
                player->LearnSpell(34091, true); // Artisan cavalier lvl 70 
                player->LearnSpell(90265, true); // Maître cavalier lvl 80 
                player->LearnSpell(54197, true); // Vol par temps froid lvl 68 
                player->LearnSpell(90267, true); // Licence de maître de vol lvl 60 - Kalimdor et Tréfonds
                //player->LearnSpell(49322, true); // Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(80704, 1); // Torse
                    player->AddItem(80713, 1); // Jambe
                    player->AddItem(80722, 1); // Pied
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK))	// Cuir
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(84259, 1); // dague
                    player->AddItem(57318, 1); // Torse
                    player->AddItem(36168, 1); // Jambe
                    player->AddItem(59796, 1); // Pied
                }
                if ((_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Maille
                {
                    player->SetSkill(413, 0, 300, 300); // Maille
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(36614, 1); // arc
                    player->AddItem(25657, 1); // Torse
                    player->AddItem(24867, 1); // Jambe
                    player->AddItem(24903, 1); // Pied
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Plaque
                {
                    player->SetSkill(293, 0, 300, 300); // Plate
                    player->AddItem(25169, 1); // epee 2 mains
                    player->AddItem(80707, 1); // Torse
                    player->AddItem(80721, 1); // Jambe
                    player->AddItem(80730, 1); // Pied
                }

                SetSkill_Death_Knight(player, _class);
                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f); // tp Hurlevent 
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f); // tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;
            case GOSSIP_ACTION_INFO_DEF + 5: // level 85

                player->SetLevel(85);
                player->AddItem(76097, 1); // Potion de soin
                player->LearnSpell(33388, true); // Apprenti cavalier lvl 20
                player->LearnSpell(33391, true); // Compagnon cavalier lvl 40
                player->LearnSpell(34090, true); // Expert cavalier 60
                player->LearnSpell(34091, true); // Artisan cavalier lvl 70 
                player->LearnSpell(90265, true); // Maître cavalier lvl 80 
                player->LearnSpell(54197, true); // Vol par temps froid lvl 68 
                player->LearnSpell(90267, true); // Licence de maître de vol lvl 60 - Kalimdor et Tréfonds
                //player->LearnSpell(49322, true); // Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(80704, 1); // Torse
                    player->AddItem(80713, 1); // Jambe
                    player->AddItem(80722, 1); // Pied
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK))	// Cuir
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(84259, 1); // dague
                    player->AddItem(57318, 1); // Torse
                    player->AddItem(36168, 1); // Jambe
                    player->AddItem(59796, 1); // Pied
                }
                if ((_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	//Mail
                {
                    player->SetSkill(413, 0, 300, 300); // Maille
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(36614, 1); // arc
                    player->AddItem(25657, 1); // Torse
                    player->AddItem(24867, 1); // Jambe
                    player->AddItem(24903, 1); // Pied
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Plaque
                {
                    player->SetSkill(293, 0, 300, 300); // Plate
                    player->AddItem(25169, 1); // epee 2 mains
                    player->AddItem(80707, 1); // Torce
                    player->AddItem(80721, 1); // Jambe
                    player->AddItem(80730, 1); // Pied
                }

                SetSkill_Death_Knight(player, _class);
                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f); // tp Hurlevent 
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f); // tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 6: // level 90

                player->SetLevel(90);
                player->AddItem(109226, 1); // Potion de soin
                player->LearnSpell(33388, true); // Apprenti cavalier lvl 20
                player->LearnSpell(33391, true); // Compagnon cavalier lvl 40
                player->LearnSpell(34090, true); // Expert cavalier 60
                player->LearnSpell(34091, true); // Artisan cavalier lvl 70 
                player->LearnSpell(90265, true); // Maître cavalier lvl 80 
                player->LearnSpell(54197, true); // Vol par temps froid lvl 68 
                player->LearnSpell(90267, true); // Licence de maître de vol lvl 60 - Kalimdor et Tréfonds
                //player->LearnSpell(49322, true); // Zhévra rapide

                SetSkill_Worgen(player, _race);

                if ((_class == CLASS_PRIEST) || (_class == CLASS_MAGE) || (_class == CLASS_WARLOCK))	// Tissu
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(80704, 1); // Torse
                    player->AddItem(80713, 1); // Jambe
                    player->AddItem(80722, 1); // Pied
                }
                if ((_class == CLASS_DRUID) || (_class == CLASS_ROGUE) || (_class == CLASS_MONK))	// Cuir
                {
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(84259, 1); // dague
                    player->AddItem(57318, 1); // Torse
                    player->AddItem(36168, 1); // Jambe
                    player->AddItem(59796, 1); // Pied
                }
                if ((_class == CLASS_HUNTER) || (_class == CLASS_SHAMAN))	// Maille
                {
                    player->SetSkill(413, 0, 300, 300); // Maille
                    player->AddItem(25177, 1); // Baton
                    player->AddItem(36614, 1); // arc
                    player->AddItem(25657, 1); // Torse
                    player->AddItem(24867, 1); // Jambe
                    player->AddItem(24903, 1); // Pied
                }
                if ((_class == CLASS_WARRIOR) || (_class == CLASS_PALADIN) || (_class == CLASS_DEATH_KNIGHT))	// Plaque
                {
                    player->SetSkill(293, 0, 300, 300); // Plate
                    player->AddItem(25169, 1); // epee 2 mains
                    player->AddItem(80707, 1); // Torse
                    player->AddItem(80721, 1); // Jambe
                    player->AddItem(80730, 1); // Pied
                }

                SetSkill_Death_Knight(player, _class);
                // Teleportation
                if (team == TEAM_ALLIANCE)
                    player->TeleportTo(0, -8867.68f, 673.373f, 97.9034f, 0.0f);	// tp Hurlevent 		
                else
                    player->TeleportTo(1, 1633.33f, -4439.11f, 17.7588f, 0.0f);	// tp Orgrimmar 
                Retire_Aura_Defaut(player);
                break;

                // Choix du lieu de depart
            case GOSSIP_ACTION_INFO_DEF + 7:
                SetSkill_Death_Knight(player, _class);

                if (team == TEAM_ALLIANCE)
                {
                    SetSkill_Worgen(player, _race);
                    // Teleportation
                    player->TeleportTo(0, -8914.57f, -133.909f, 80.5378f, 5.13806f);		// Humain
                }
                else
                    // Teleportation
                    player->TeleportTo(1, -618.518f, -4251.67f, 38.718f, 4.72222f);			// Orc	
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 8:
                SetSkill_Death_Knight(player, _class);

                if (team == TEAM_ALLIANCE)
                {
                    if (_race == RACE_WORGEN)
                    {
                        player->LearnSpell(68996, true); // Deux formes
                        player->LearnSpell(94293, true); // Forme modifiée
                        player->LearnSpell(68992, true); // Sombre course
                        player->LearnSpell(68978, true); // Ecorcheur
                        player->LearnSpell(69270, true); // Langue (gilnéen)
                        player->LearnSpell(68976, true); // Aberration
                        player->LearnSpell(68975, true); // Acharnement
                    }
                    // Teleportation
                    player->TeleportTo(0, -6230.42f, 330.232f, 383.105f, 6.17716f);			// Nain
                }
                else
                    // Teleportation
                    player->TeleportTo(0, 1699.85f, 1706.56f, 135.928f, 4.88839f);			// Mort Vivant	
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 9:
                SetSkill_Death_Knight(player, _class);

                if (team == TEAM_ALLIANCE)
                {
                    SetSkill_Worgen(player, _race);
                    // Teleportation
                    player->TeleportTo(1, 10311.3f, 831.463f, 1326.57f, 5.69632f);			// Elfe de la nuit
                }
                else
                    // Teleportation
                    player->TeleportTo(1, -2915.55f, -257.347f, 59.2693f, 0.302378f);		// Tauren	
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 10:
                if (team == TEAM_ALLIANCE)
                {
                    SetSkill_Worgen(player, _race);
                    // Teleportation
                    player->TeleportTo(0, -4983.42f, 877.7f, 274.31f, 3.06393f);			// Gnome
                }
                else
                    // Teleportation
                    player->TeleportTo(1, -1171.45f, -5263.65f, 0.847728f, 5.78945f);		// Troll	
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 11:
                SetSkill_Death_Knight(player, _class);

                if (team == TEAM_ALLIANCE)
                {
                    SetSkill_Worgen(player, _race);
                    // Teleportation
                    player->TeleportTo(530, -3961.64f, -13931.2f, 100.615f, 2.08364f);		// Draenei
                }
                else
                    // Teleportation
                    player->TeleportTo(530, 10349.6f, -6357.29f, 33.4026f, 5.31605f);		// Elfe de Sang	
                Retire_Aura_Defaut(player);
                break;

            case GOSSIP_ACTION_INFO_DEF + 12:
                if (team == TEAM_HORDE)
                {
                    Retire_Aura_Defaut(player);
                }
                break;

            case 13:
                uint8 reputworgendesneiges = 0;

                if (player->GetReputation(942) != reputworgendesneiges) { player->SetReputation(942, reputworgendesneiges); }	// Expédition cénarienne
                if (player->GetReputation(935) != reputworgendesneiges) { player->SetReputation(935, reputworgendesneiges); }	// Les Sha'tar
                if (player->GetReputation(936) != reputworgendesneiges) { player->SetReputation(936, reputworgendesneiges); }	// Shattrath
                if (player->GetReputation(1011) != reputworgendesneiges) { player->SetReputation(1011, reputworgendesneiges); } // Ville basse
                if (player->GetReputation(970) != reputworgendesneiges) { player->SetReputation(970, reputworgendesneiges); }	// Sporeggar
                if (player->GetReputation(967) != reputworgendesneiges) { player->SetReputation(967, reputworgendesneiges); }	// L'Oil pourpre
                if (player->GetReputation(989) != reputworgendesneiges) { player->SetReputation(989, reputworgendesneiges); }	// Gardiens du Temps
                if (player->GetReputation(932) != reputworgendesneiges) { player->SetReputation(932, reputworgendesneiges); }	// L'Aldor
                if (player->GetReputation(934) != reputworgendesneiges) { player->SetReputation(934, reputworgendesneiges); }	// Les Clairvoyants
                if (player->GetReputation(1038) != reputworgendesneiges) { player->SetReputation(1038, reputworgendesneiges); } // Ogri'la
                if (player->GetReputation(1077) != reputworgendesneiges) { player->SetReputation(1077, reputworgendesneiges); } // Opération Soleil brisé

                // ALLIANCE 
                if (player->GetReputation(72) != reputworgendesneiges) { player->SetReputation(72, reputworgendesneiges); }		// Hurlevent
                if (player->GetReputation(47) != reputworgendesneiges) { player->SetReputation(47, reputworgendesneiges); }		// Forgefer		
                if (player->GetReputation(69) != reputworgendesneiges) { player->SetReputation(69, reputworgendesneiges); }		// Darnassus
                if (player->GetReputation(930) != reputworgendesneiges) { player->SetReputation(930, reputworgendesneiges); }	// Exodar
                if (player->GetReputation(730) != reputworgendesneiges) { player->SetReputation(730, reputworgendesneiges); }	// Garde Foudrepique
                if (player->GetReputation(978) != reputworgendesneiges) { player->SetReputation(978, reputworgendesneiges); }	// Kurenaï
                if (player->GetReputation(54) != reputworgendesneiges) { player->SetReputation(54, reputworgendesneiges); }		// Gnomeregan
                if (player->GetReputation(946) != reputworgendesneiges) { player->SetReputation(946, reputworgendesneiges); }	// Bastion de l'Honneur

                // HORDE
                if (player->GetReputation(76) != reputworgendesneiges) { player->SetReputation(76, reputworgendesneiges); }		// Orgrimmar
                if (player->GetReputation(68) != reputworgendesneiges) { player->SetReputation(68, reputworgendesneiges); }		// Fossoyeuse
                if (player->GetReputation(81) != reputworgendesneiges) { player->SetReputation(81, reputworgendesneiges); }		// Les Pitons-du-Tonnerre
                if (player->GetReputation(911) != reputworgendesneiges) { player->SetReputation(911, reputworgendesneiges); }	// Lune-d'Argent
                if (player->GetReputation(729) != reputworgendesneiges) { player->SetReputation(729, reputworgendesneiges); }	// Clan Loup-de-givre
                if (player->GetReputation(941) != reputworgendesneiges) { player->SetReputation(941, reputworgendesneiges); }	// Mag'har
                if (player->GetReputation(530) != reputworgendesneiges) { player->SetReputation(530, reputworgendesneiges); }	// Trolls sombrelances
                if (player->GetReputation(947) != reputworgendesneiges) { player->SetReputation(947, reputworgendesneiges); }	// Thrallmar

                player->LearnSpell(300172, true); // Worgen des neiges
                Retire_Aura_Defaut(player);
                break;

            }

            CloseGossipMenuFor(player); 
            player->SaveToDB();
            return true;
        }

	void SetSkill_Worgen(Player* player, uint8 _race)
	{
		if (!player)
			return;

		if (_race == RACE_WORGEN)	// Worgen
		{
			player->LearnSpell(68996, true); // Deux formes
			player->LearnSpell(94293, true); // Forme modifiée
			player->LearnSpell(68992, true); // Sombre course
			player->LearnSpell(68978, true); // Ecorcheur
			player->LearnSpell(69270, true); // Langue (gilnéen)
			player->LearnSpell(68976, true); // Aberration
			player->LearnSpell(68975, true); // Acharnement
		}
	}
	void SetSkill_Death_Knight(Player* player, uint8 _class)
	{
		if (!player)
			return;

		if (_class == CLASS_DEATH_KNIGHT)
		{
            player->LearnSpell(53428, true); // Runeforge lvl 6
            player->LearnSpell(50977, true); // Porte de la mort lvl 10
            player->LearnSpell(53428, true); // Destrier de la mort cramoisi lvl 10
        }
	}
    void Retire_Aura_Defaut(Player* player)
    {
        // Retire certaines auras appliquées par defaut
        player->RemoveAurasDueToSpell(80653);         // Gnome : Irradié 80653
        player->RemoveAurasDueToSpell(71033);         // Troll : Calme du novice 71033
        player->RemoveAurasDueToSpell(107027);        // Pandaren - See Quest Invis 20 107027
    }
};

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_levelAI(creature);
    }
};
void AddSC_npc_levels()
{
	new npc_level();
}
