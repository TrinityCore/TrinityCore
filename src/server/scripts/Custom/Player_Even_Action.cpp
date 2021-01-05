//###################################################################################################################################################################
// Stitch Decembre 2020 - Player_Even_Action_handler - version 1.0 , wow 9.0.2.36949 
// Action (Apprentissage, ajout d'item,etc) suite a un événement Joueur (connexion,levelup,zone, création) suivant la classe ou la race
//###################################################################################################################################################################

//#include "Config.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "Map.h"
#include "WorldSession.h"
#include "GameEventMgr.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "ChatTextBuilder.h"
#include "Config.h"
#include "Unit.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Guild.h"
#include "GuildFinderMgr.h"
#include "GuildMgr.h"
#include "DatabaseEnv.h"




namespace {

class Player_Even_Action_handler : public PlayerScript {

public:
    Player_Even_Action_handler() : PlayerScript("Player_Even_Action_handler") {}

    // Routines de test d"evenements ##################################################################################

    // Connexion d'un joueur ou 1ere connexion joueur
    void OnLogin(Player* player, bool firstLogin) override
    {
        Apprentissage_Ou_Additem_Suivant_classes_races(player);

        // 1ere connexion joueur
        if (firstLogin)
        {
        Guilde_Par_Defaut_Pour_Tous(player);
        }
	}

    // Au level up
    virtual void OnLevelChanged(Player* player, uint8 /*oldLevel*/) 
    {
        Apprentissage_Ou_Additem_Suivant_classes_races(player);
    }




    // Sans action pour le moment
    void OnPlayerEnterZone(Player* player, uint32 newZone, uint32 newArea)
    {
    }
    void OnPlayerCreate(Player* player)
    {
    }

    ////// TMP a voir/vérifier : public: /* CreatureScript */
    // void OnAccountLogin(uint32 /*accountId*/) {}
    // void OnPlayerEnter(map, player) {}
    // void OnPlayerSpellCast(Player* player, Spell* spell, bool skipCheck) {}
    // void OnPlayerLogin(Player* player, bool firstLogin) {}
    // void OnPlayerRepop(Player* player) {}
    // void OnPlayerRepop(Player* player) {}
    // void OnPlayerKilledByCreature(Creature* /*killer*/, Player* /*killed*/) { }
    // void OnCreatureKill(Player* /*killer*/, Creature* /*killed*/) { }
    // void OnLogout(Player* /*player*/) { }
    // void OnCreate(Player* /*player*/) { }
    // void OnMapChanged(Player* /*player*/) { }
    //  void OnPlayerUpdate     Player->has     Player->is
    // void Player::Update(uint32 p_time)
    // void Player::KillPlayer()
    // void UpdateAI(uint32 diff) override ---> if (CanSpawn)



    // Routines d'actions suite a un évènement ########################################################################

    // 
    void Apprentissage_Ou_Additem_Suivant_classes_races(Player* player)
    {
    uint8 _team = player->GetTeamId();      // TeamId team
    uint8 _class = player->getClass();
    uint8 _level = player->getLevel();
    uint8 _race = player->getRace();
    uint8 _GenderID = player->GetNativeSex();

    switch (_class)
{

case CLASS_WARRIOR:
    break;
case CLASS_PALADIN:
    break;
case CLASS_HUNTER:
    if (_level >= 5)
    {
        player->LearnSpell(883, true);      // Appel du familier 1
        player->LearnSpell(2641, true);     // Renvoyer le familier
        player->LearnSpell(9321, true);     // Contrôle du familier
        player->LearnSpell(6991, true);     // Nourrir le familier
        player->LearnSpell(136, true);      // Guérison du familier - ne s'apprend pas ?!
        player->LearnSpell(33976, true);    // Guérison du familier : temporaire : parce que 136 ne veux pas s'apprendre seul
        player->LearnSpell(982, true);      // Ressusciter le familier
        player->LearnSpell(1515, true);     // Apprivoiser une bête
        player->LearnSpell(1462, true);     // Connaissance des bêtes
        player->GetSession()->SendNotification("|cffffffff[Vous avez appris de nouvelles competances]:|r");
    }
    if (_level >= 10)
    {
        player->LearnSpell(83242, true);      // Appel du familier 2
    }
    if (_level >= 17)
    {
        player->LearnSpell(83243, true);      // Appel du familier 3
    }
    if (_level >= 41)
    {
        player->LearnSpell(83244, true);      // Appel du familier 4
    }
    if (_level >= 48)
    {
        player->LearnSpell(83245, true);      // Appel du familier 5
    }
    break;
case CLASS_ROGUE:
    break;
case CLASS_PRIEST:
    break;
case CLASS_DEATH_KNIGHT:
    if (_level >= 6)
    {
        player->LearnSpell(53428, true); // Runeforge
    }
    if (_level >= 10)
    {
        player->LearnSpell(50977, true); // Porte de la mort
        player->LearnSpell(53428, true); // Destrier de la mort cramoisi
    }
    break;
case CLASS_SHAMAN:
    break;
case CLASS_MAGE:
    break;
case CLASS_WARLOCK:
    break;
case CLASS_MONK:
    break;
case CLASS_DRUID:
    break;
case CLASS_DEMON_HUNTER:
    break;
}

    switch (_race)
{
case RACE_HUMAN:
    break;
case RACE_ORC:
    break;
case RACE_DWARF:
    break;
case RACE_NIGHTELF:
    break;
case RACE_UNDEAD_PLAYER:
    break;
case RACE_TAUREN:
    break;
case RACE_GNOME:
    break;
case RACE_TROLL:
    break;
case RACE_GOBLIN:
    break;
case RACE_BLOODELF:
    break;
case RACE_DRAENEI:
    break;
case RACE_WORGEN:
    player->LearnSpell(68996, true); // Deux formes
    player->LearnSpell(94293, true); // Forme modifiée
    player->LearnSpell(68992, true); // Sombre course
    player->LearnSpell(68978, true); // Ecorcheur
    player->LearnSpell(69270, true); // Langue (gilnéen)
    player->LearnSpell(68976, true); // Aberration
    player->LearnSpell(68975, true); // Acharnement
    break;
case RACE_PANDAREN_NEUTRAL:
    break;
case RACE_PANDAREN_ALLIANCE:
    break;
case RACE_PANDAREN_HORDE:
    break;
case RACE_NIGHTBORNE:               // Sacrenuit h2
    break;
case RACE_HIGHMOUNTAIN_TAUREN:      // Tauren de Haut - Roc h2
    break;
case RACE_VOID_ELF:                 // Elfe du Vide a2
    break;
case RACE_LIGHTFORGED_DRAENEI:      // Draenei sancteforge a2
    break;
case RACE_ZANDALARI_TROLL:          // Troll Zandalari  h2
    break;
case RACE_KUL_TIRAN:                // Kultirassien a2 
    break;
case RACE_DARK_IRON_DWARF:          // Nain sombrefer a2
    break;
case RACE_VULPERA:                  // Vulpérins h2
    break;
case RACE_MAGHAR_ORC:               // Orc Mag'har h2 
    break;
case RACE_MECHAGNOME:               // Mécagnome a2
    break;

}
    }
    void Guilde_Par_Defaut_Pour_Tous(Player* player)
        // Voir la table characters-guild->guildid pour l'id de guilde
    {
    uint32 guildID;
    if (player->GetTeam() == HORDE)
    {
        guildID = sConfigMgr->GetIntDefault("Guilde_Par_Defaut_Horde", 0);
        ChatHandler(player->GetSession()).SendSysMessage("|cffffffff> Vous avez rejoint la guilde par defaut de la Horde. '/gquit' pour la quiter <");
    }
    else
    {
        guildID = sConfigMgr->GetIntDefault("Guilde_Par_Defaut_Alliance", 0);
        ChatHandler(player->GetSession()).SendSysMessage("|cffffffff> Vous avez rejoint la guilde par defaut de l'Alliance. '/gquit' pour la quiter <");
    }

    if (!guildID) return;

    Guild* targetGuild = sGuildMgr->GetGuildById(guildID);
    if (targetGuild)
    {
        ObjectGuid playerGuid = player->GetGUID();
        CharacterDatabaseTransaction trans(nullptr);
        targetGuild->AddMember(trans, player->GetGUID());
    }
    }



private:
	std::map<ObjectGuid, int> _unitDifficulty;
};

}

void AddSC_Player_Even_Action() {
	new Player_Even_Action_handler();
}
