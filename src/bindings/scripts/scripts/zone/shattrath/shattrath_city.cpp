/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Shattrath_City
SD%Complete: 100
SDComment: Quest support: 10004, 10009, 10211. Flask vendors, Teleport to Caverns of Time
SDCategory: Shattrath City
EndScriptData */

/* ContentData
npc_raliq_the_drunk
npc_salsalabim
npc_shattrathflaskvendors
npc_zephyr
npc_kservant
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*######
## npc_raliq_the_drunk
######*/

#define GOSSIP_RALIQ            "You owe Sim'salabim money. Hand them over or die!"

#define FACTION_HOSTILE_RD      45
#define FACTION_FRIENDLY_RD     35

#define SPELL_UPPERCUT          10966

struct TRINITY_DLL_DECL npc_raliq_the_drunkAI : public ScriptedAI
{
    npc_raliq_the_drunkAI(Creature* c) : ScriptedAI(c) { Reset(); }

    uint32 Uppercut_Timer;

    void Reset()
    {
        Uppercut_Timer = 5000;
        m_creature->setFaction(FACTION_FRIENDLY_RD);
    }

    void Aggro(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( Uppercut_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_UPPERCUT);
            Uppercut_Timer = 15000;
        }else Uppercut_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_raliq_the_drunk(Creature *_Creature)
{
    return new npc_raliq_the_drunkAI (_Creature);
}

bool GossipHello_npc_raliq_the_drunk(Player *player, Creature *_Creature )
{
    if( player->GetQuestStatus(10009) == QUEST_STATUS_INCOMPLETE )
        player->ADD_GOSSIP_ITEM(1, GOSSIP_RALIQ, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(9440, _Creature->GetGUID());
    return true;
}

bool GossipSelect_npc_raliq_the_drunk(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
    {
        player->CLOSE_GOSSIP_MENU();
        _Creature->setFaction(FACTION_HOSTILE_RD);
        ((npc_raliq_the_drunkAI*)_Creature->AI())->AttackStart(player);
    }
    return true;
}

/*######
# npc_salsalabim
######*/

#define FACTION_HOSTILE_SA              90
#define FACTION_FRIENDLY_SA             35
#define QUEST_10004                     10004

#define SPELL_MAGNETIC_PULL             31705

struct TRINITY_DLL_DECL npc_salsalabimAI : public ScriptedAI
{
    npc_salsalabimAI(Creature* c) : ScriptedAI(c) { Reset(); }

    uint32 MagneticPull_Timer;

    void Reset()
    {
        MagneticPull_Timer = 15000;
        m_creature->setFaction(FACTION_FRIENDLY_SA);
    }

    void Aggro(Unit *who) {}

    void DamageTaken(Unit *done_by, uint32 &damage)
    {
        if( done_by->GetTypeId() == TYPEID_PLAYER )
            if( (m_creature->GetHealth()-damage)*100 / m_creature->GetMaxHealth() < 20 )
        {
            ((Player*)done_by)->GroupEventHappens(QUEST_10004,m_creature);
            damage = 0;
            EnterEvadeMode();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if(!m_creature->SelectHostilTarget() || !m_creature->getVictim())
            return;

        if( MagneticPull_Timer < diff )
        {
            DoCast(m_creature->getVictim(),SPELL_MAGNETIC_PULL);
            MagneticPull_Timer = 15000;
        }else MagneticPull_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_salsalabim(Creature *_Creature)
{
    return new npc_salsalabimAI (_Creature);
}

bool GossipHello_npc_salsalabim(Player *player, Creature *_Creature)
{
    if( player->GetQuestStatus(QUEST_10004) == QUEST_STATUS_INCOMPLETE )
    {
        _Creature->setFaction(FACTION_HOSTILE_SA);
        ((npc_salsalabimAI*)_Creature->AI())->AttackStart(player);
    }
    else
    {
        if( _Creature->isQuestGiver() )
            player->PrepareQuestMenu( _Creature->GetGUID() );
        player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());
    }
    return true;
}

/*
##################################################
Shattrath City Flask Vendors provides flasks to people exalted with 3 factions:
Haldor the Compulsive
Arcanist Xorith
Both sell special flasks for use in Outlands 25man raids only,
purchasable for one Mark of Illidari each
Purchase requires exalted reputation with Scryers/Aldor, Cenarion Expedition and The Sha'tar
##################################################
*/

bool GossipHello_npc_shattrathflaskvendors(Player *player, Creature *_Creature)
{
    if(_Creature->GetEntry() == 23484)
    {
        // Aldor vendor
        if( _Creature->isVendor() && (player->GetReputationRank(932) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED) )
        {
            player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(11085, _Creature->GetGUID());
        }
        else
        {
            player->SEND_GOSSIP_MENU(11083, _Creature->GetGUID());
        }
    }

    if(_Creature->GetEntry() == 23483)
    {
        // Scryers vendor
        if( _Creature->isVendor() && (player->GetReputationRank(934) == REP_EXALTED) && (player->GetReputationRank(935) == REP_EXALTED) && (player->GetReputationRank(942) == REP_EXALTED) )
        {
            player->ADD_GOSSIP_ITEM(1, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
            player->SEND_GOSSIP_MENU(11085, _Creature->GetGUID());
        }
        else
        {
            player->SEND_GOSSIP_MENU(11084, _Creature->GetGUID());
        }
    }

    return true;
}

bool GossipSelect_npc_shattrathflaskvendors(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if( action == GOSSIP_ACTION_TRADE )
        player->SEND_VENDORLIST( _Creature->GetGUID() );

    return true;
}

/*######
# npc_zephyr
######*/

bool GossipHello_npc_zephyr(Player *player, Creature *_Creature)
{
    if( player->GetReputationRank(989) >= REP_REVERED )
        player->ADD_GOSSIP_ITEM(0, "Take me to the Caverns of Time.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    player->SEND_GOSSIP_MENU(_Creature->GetNpcTextId(), _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_zephyr(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    if( action == GOSSIP_ACTION_INFO_DEF+1 )
        player->CastSpell(player,37778,false);

    return true;
}

/*######
# npc_kservant
######*/

#define SAY1       "Follow me, stranger. This won't take long."
#define WHISP1     "Shattrath was once the draenei capital of this world. Its name means \"dwelling of light.\""
#define WHISP2     "When the Burning Legion turned the orcs against the draenei, the fiercest battle was fought here. The draenei fought tooth and nail, but in the end the city fell."
#define WHISP3     "The city was left in ruins and darkness... until the Sha'tar arrived."
#define WHISP4     "Let us go into the Lower City. I will warn you that as one of the only safe havens in Outland, Shattrath has attracted droves of refugees from all wars, current and past. "
#define WHISP5     "The Sha'tar, or \"born from light\" are the naaru that came to Outland to fight the demons of the Burning Legion."
#define WHISP6     "They were drawn to the ruins of Shattrath City where a small remnant of the draenei priesthood conducted its rites inside a ruined temple on this very spot."
#define WHISP7     "The priesthood, known as the Aldor, quickly regained its strength as word spread that the naaru had returned and reconstruction soon began. The ruined temple is now used as an infirmary for injured refugees."
#define WHISP8     "It wouldn't be long, however, before the city came under attack once again. This time, the attack came from Illidan's armies. A large regiment of blood elves had been sent by Illidan's ally, Kael'thas Sunstrider, to lay waste to the city."
#define WHISP9     "As the regiment of blood elves crossed this very bridge, the Aldor's exarchs and vindicators lined up to defend the Terrace of Light. But then the unexpected happened. "
#define WHISP10    "The blood elves laid down their weapons in front of the city's defenders; their leader, a blood elf elder known as Voren'thal, stormed into the Terrace of Light and demanded to speak to A'dal."
#define WHISP11    "As the naaru approached him, Voren'thal kneeled before him and uttered the following words: \"I've seen you in a vision, naaru. My race's only hope for survival lies with you. My followers and I are here to serve you.\""
#define WHISP12    "The defection of Voren'thal and his followers was the largest loss ever incurred by Kael's forces. And these weren't just any blood elves. Many of the best and brightest amongst Kael's scholars and magisters had been swayed by Voren'thal's influence."
#define WHISP13    "The naaru accepted the defectors, who would become known as the Scryers; their dwelling lies in the platform above. Only those initiated with the Scryers are allowed there."
#define WHISP14    "The Aldor are followers of the Light and forgiveness and redemption are values they understand. However, they found hard to forget the deeds of the blood elves while under Kaell's command."
#define WHISP15    "Many of the priesthood had been slain by the same magisters who now vowed to serve the naaru. They were not happy to share the city with their former enemies."
#define WHISP16    "The Aldor's most holy temple and its surrounding dwellings lie on the terrace above. As a holy site, only the initiated are welcome inside."
#define WHISP17    "The attacks against Shattrath continued, but the city did not fall, as you can see. On the contrary, the naaru known as Xi'ri led a successful incursion into Shadowmoon Valley - Illidan's doorstep."
#define WHISP18    "There he continues to wage war on Illidan with the assistance of the Aldor and the Scryers. The two factions have not given up on their old feuds, though."
#define WHISP19    "Such is their animosity that they vie for the honor of being sent to assist the naaru there. Each day, that decision is made here by A'dal. The armies gather here to receive A'dal's blessing before heading to Shadowmoon."
#define WHISP20    "Khadgar should be ready to see you again. Just remember that to serve the Sha'tar you will most likely have to ally with the Aldor or the Scryers. And seeking the favor of one group will cause the others' dislike."
#define WHISP21    "Good luck stranger, and welcome to Shattrath City."

struct TRINITY_DLL_DECL npc_kservantAI : public npc_escortAI
{
public:
        npc_kservantAI(Creature *c) : npc_escortAI(c) {    Reset();}


    void WaypointReached(uint32 i)
    {
        Unit *pTemp = Unit::GetUnit(*m_creature,PlayerGUID);
        if( !pTemp )
            return;

        switch(i)
        {
            case 0: DoSay(SAY1, LANG_UNIVERSAL, pTemp); break;
            case 4: DoWhisper(WHISP1, pTemp); break;
            case 6: DoWhisper(WHISP2, pTemp); break;
            case 7: DoWhisper(WHISP3, pTemp); break;
            case 8: DoWhisper(WHISP4, pTemp); break;
            case 17: DoWhisper(WHISP5, pTemp); break;
            case 18: DoWhisper(WHISP6, pTemp); break;
            case 19: DoWhisper(WHISP7, pTemp); break;
            case 33: DoWhisper(WHISP8, pTemp); break;
            case 34: DoWhisper(WHISP9, pTemp); break;
            case 35: DoWhisper(WHISP10, pTemp); break;
            case 36: DoWhisper(WHISP11, pTemp); break;
            case 43: DoWhisper(WHISP12, pTemp); break;
            case 44: DoWhisper(WHISP13, pTemp); break;
            case 49: DoWhisper(WHISP14, pTemp); break;
            case 50: DoWhisper(WHISP15, pTemp); break;
            case 51: DoWhisper(WHISP16, pTemp); break;
            case 52: DoWhisper(WHISP17, pTemp); break;
            case 53: DoWhisper(WHISP18, pTemp); break;
            case 54: DoWhisper(WHISP19, pTemp); break;
            case 55: DoWhisper(WHISP20, pTemp); break;
            case 56: DoWhisper(WHISP21, pTemp);
               if( PlayerGUID )
                {
                    Unit* player = ((Creature*)Unit::GetUnit((*m_creature), PlayerGUID));
                    if( player && player->GetTypeId() == TYPEID_PLAYER )
                        ((Player*)player)->GroupEventHappens(10211,m_creature);
                }
                break;
        }
    }

    void Aggro(Unit* who) {}

    void MoveInLineOfSight(Unit *who)
    {
        if( IsBeingEscorted )
            return;

        if( who->GetTypeId() == TYPEID_PLAYER )
        {
            if( ((Player*)who)->GetQuestStatus(10211) == QUEST_STATUS_INCOMPLETE )
            {
                float Radius = 10.0;
                if( m_creature->IsWithinDistInMap(who, Radius) )
                {
                    ((npc_escortAI*)(m_creature->AI()))->Start(false, false, false, who->GetGUID());
                }
            }
        }
    }

    void Reset() {}

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};
CreatureAI* GetAI_npc_kservantAI(Creature *_Creature)
{
    npc_kservantAI* kservantAI = new npc_kservantAI(_Creature);

    kservantAI->AddWaypoint(0, -1863.369019, 5419.517090, -10.463668, 4000);
    kservantAI->AddWaypoint(1, -1861.749023, 5416.465332, -10.508068);
    kservantAI->AddWaypoint(2, -1857.036133, 5410.966309, -12.428039);
    kservantAI->AddWaypoint(3, -1831.539185, 5365.472168, -12.428039);
    kservantAI->AddWaypoint(4, -1813.416504, 5333.776855, -12.428039);
    kservantAI->AddWaypoint(5, -1800.354370, 5313.290039, -12.428039);
    kservantAI->AddWaypoint(6, -1775.624878, 5268.786133, -38.809181);
    kservantAI->AddWaypoint(7, -1770.147339, 5259.268066, -38.829231);
    kservantAI->AddWaypoint(8, -1762.814209, 5261.098145, -38.848995);
    kservantAI->AddWaypoint(9, -1740.110474, 5268.858398, -40.208965);
    kservantAI->AddWaypoint(10, -1725.837402, 5270.936035, -40.208965);
    kservantAI->AddWaypoint(11, -1701.580322, 5290.323242, -40.209187);
    kservantAI->AddWaypoint(12, -1682.877808, 5291.406738, -34.429646);
    kservantAI->AddWaypoint(13, -1670.101685, 5291.201172, -32.786007);
    kservantAI->AddWaypoint(14, -1656.666870, 5294.333496, -37.862648);
    kservantAI->AddWaypoint(15, -1652.035767, 5295.413086, -40.245499);
    kservantAI->AddWaypoint(16, -1620.860596, 5300.133301, -40.208992);
    kservantAI->AddWaypoint(17, -1607.630981, 5293.983398, -38.577045, 5000);
    kservantAI->AddWaypoint(18, -1607.630981, 5293.983398, -38.577045, 5000);
    kservantAI->AddWaypoint(19, -1607.630981, 5293.983398, -38.577045, 5000);
    kservantAI->AddWaypoint(20, -1622.140869, 5301.955566, -40.208897);
    kservantAI->AddWaypoint(21, -1621.131836, 5333.112793, -40.208897);
    kservantAI->AddWaypoint(22, -1637.598999, 5342.134277, -40.208790);
    kservantAI->AddWaypoint(23, -1648.521606, 5352.309570, -47.496170);
    kservantAI->AddWaypoint(24, -1654.606934, 5357.419434, -45.870892);
    kservantAI->AddWaypoint(25, -1633.670044, 5422.067871, -42.835541);
    kservantAI->AddWaypoint(25, -1656.567505, 5426.236328, -40.405815);
    kservantAI->AddWaypoint(26, -1664.932373, 5425.686523, -38.846405);
    kservantAI->AddWaypoint(27, -1681.406006, 5425.871094, -38.810928);
    kservantAI->AddWaypoint(28, -1730.875977, 5427.413574, -12.427910);
    kservantAI->AddWaypoint(29, -1743.509521, 5369.599121, -12.427910);
    kservantAI->AddWaypoint(30, -1877.217041, 5303.710449, -12.427989);
    kservantAI->AddWaypoint(31, -1890.371216, 5289.273438, -12.428268);
    kservantAI->AddWaypoint(32, -1905.505737, 5266.534668, 2.630672);
    kservantAI->AddWaypoint(33, -1909.381348, 5273.008301, 1.663714, 10000);
    kservantAI->AddWaypoint(34, -1909.381348, 5273.008301, 1.663714, 12000);
    kservantAI->AddWaypoint(35, -1909.381348, 5273.008301, 1.663714, 8000);
    kservantAI->AddWaypoint(36, -1909.381348, 5273.008301, 1.663714, 15000);
    kservantAI->AddWaypoint(37, -1927.561401, 5275.324707, 1.984987);
    kservantAI->AddWaypoint(38, -1927.385498, 5300.879883, -12.427236);
    kservantAI->AddWaypoint(39, -1921.063965, 5314.318359, -12.427236);
    kservantAI->AddWaypoint(40, -1965.425415, 5379.298828, -12.427236);
    kservantAI->AddWaypoint(41, -1981.233154, 5450.743652, -12.427236);
    kservantAI->AddWaypoint(42, -1958.022461, 5455.904297, 0.487659);
    kservantAI->AddWaypoint(43, -1951.991455, 5463.580566, 0.874490, 10000);
    kservantAI->AddWaypoint(44, -1951.991455, 5463.580566, 0.874490, 12000);
    kservantAI->AddWaypoint(45, -1968.730225, 5481.752930, -12.427846);
    kservantAI->AddWaypoint(46, -1881.839844, 5554.040039, -12.427846);
    kservantAI->AddWaypoint(47, -1841.566650, 5545.965332, -12.427846);
    kservantAI->AddWaypoint(48, -1837.658325, 5523.780273, 0.558756);
    kservantAI->AddWaypoint(49, -1831.321777, 5534.821777, 1.221819, 6000);
    kservantAI->AddWaypoint(50, -1831.321777, 5534.821777, 1.221819, 8000);
    kservantAI->AddWaypoint(51, -1831.321777, 5534.821777, 1.221819, 5000);
    kservantAI->AddWaypoint(52, -1850.060669, 5472.610840, 0.857320, 6000);
    kservantAI->AddWaypoint(53, -1850.060669, 5472.610840, 0.857320, 8000);
    kservantAI->AddWaypoint(54, -1850.060669, 5472.610840, 0.857320, 9000);
    kservantAI->AddWaypoint(55, -1850.060669, 5472.610840, 0.857320, 9000);
    kservantAI->AddWaypoint(56, -1850.060669, 5472.610840, 0.857320, 4000);
    
    return (CreatureAI*)kservantAI;
}

void AddSC_shattrath_city()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_raliq_the_drunk";
    newscript->pGossipHello =  &GossipHello_npc_raliq_the_drunk;
    newscript->pGossipSelect = &GossipSelect_npc_raliq_the_drunk;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_salsalabim";
    newscript->GetAI = GetAI_npc_salsalabim;
    newscript->pGossipHello =  &GossipHello_npc_salsalabim;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_shattrathflaskvendors";
    newscript->pGossipHello =  &GossipHello_npc_shattrathflaskvendors;
    newscript->pGossipSelect = &GossipSelect_npc_shattrathflaskvendors;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_zephyr";
    newscript->pGossipHello =  &GossipHello_npc_zephyr;
    newscript->pGossipSelect = &GossipSelect_npc_zephyr;
    newscript->RegisterSelf();

       newscript = new Script;
    newscript->Name="npc_kservant";
    newscript->GetAI = GetAI_npc_kservantAI;
    newscript->RegisterSelf();
}
