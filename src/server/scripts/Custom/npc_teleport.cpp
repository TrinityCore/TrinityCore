/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Vehicle.h"
#include "ScriptPCH.h"
#include "Common.h"
#include "Chat.h"
#include "Group.h"
#include "Player.h"
#include "DisableMgr.h"
#include "ChannelMgr.h"
#include "Config.h"
#include "Language.h"
#include "World.h"
#include "ScriptedGossip.h"
#include "DatabaseEnv.h"
#include <sstream>

/*
  alexkulya: Необходимо добавить локации Катаклизма и Пандарии для телепорта.
             Проверить доступ Альянса и Орды для некоторых точек телепорта.
*/

struct TeleportStructure
{
    uint32 menu_id, next_menu_id;
    uint8 icon;
    std::string name;
    uint32 cost;
    uint8 level, faction;
    uint32 map;
    float x, y, z, o;
};

typedef struct TeleportStructure Data;

Data Tele[] =
{
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportStormWind:25|t Штормград", 0, 0, 2, 0, -8842.09f, 626.358f, 94.0867f, 3.61363f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportOrgrimmar:25|t Оргриммар", 0, 0, 1, 1, 1601.08f, -4378.69f, 9.9846f, 2.14362f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportDarnassus:25|t Дарнас", 0, 0, 2, 1, 9869.91f, 2493.58f, 1315.88f, 2.78897f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportIronForge:25|t Стальгорн", 0, 0, 2, 0, -4900.47f, -962.585f, 501.455f, 5.40538f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportExodar:25|t Эксодар", 0, 0, 2, 530, -3864.92f, -11643.7f, -137.644f, 5.50862f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportThunderBluff:25|t Громовой утес", 0, 0, 1, 1, -1274.45f, 71.8601f, 128.159f, 2.80623f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportUnderCity:25|t Подгород", 0, 0, 1, 0, 1633.75f, 240.167f, -43.1034f, 6.26128f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportSilvermoon:25|t Луносвет", 0, 0, 1, 530, 9738.28f, -7454.19f, 13.5605f, 0.043914f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportDalaran:25|t Даларан", 0, 0, 0, 571, 5809.55f, 503.975f, 657.526f, 2.38338f},
    {1, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Arcane_TeleportShattrath:25|t Шаттрат", 0, 0, 0, 530, -1887.62f, 5359.09f, -12.4279f, 4.40435f},
    {1, 2, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/inv_helmet_74:25|t Классические подземелья", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 3, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/inv_helmet_90:25|t Подземелья BC", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 4, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/inv_helmet_151:25|t Подземелья WotLK", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 5, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/inv_helmet_100:25|t Подземелья Cataclysm", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 6, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/inv_helmet_mail_panda_b_01:25|t Подземелья Pandaria", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 7, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/thumbup:25|t Рейдовые телепорты", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 8, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/achievement_zone_easternkingdoms_01:25|t Восточные королевства", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 9, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/achievement_zone_kalimdor_01:25|t Калимдор", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 10, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/achievement_zone_outland_01:25|t Запределье", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 11, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/achievement_zone_northrend_01:25|t Нордскол", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 12, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/spell_shaman_stormearthfire:25|t Катаклизм", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 13, GOSSIP_ICON_TRAINER, "|TInterface/ICONS/expansionicon_mistsofpandaria:25|t Пандария", 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 20, GOSSIP_ICON_BATTLE, "|TInterface/ICONS/achievement_bg_winwsg:25|t PvP территории", 0, 0, 0, 0, 0, 0, 0, 0},

    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_Mekgineer_Thermaplugg .png:25|t Гномреган", 0, 0, 2, 0, -5163.54f, 925.423f, 257.181f, 1.57423f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_Bazil_Thredd:25|t Тюрьма", 0, 0, 2, 0, -8799.15f, 832.718f, 97.6348f, 6.04085f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Spell_Shadow_SummonFelGuard:25|t Огненная пропасть", 0, 0, 1, 1, 1811.78f, -4410.5f, -18.4704f, 5.20165f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_charlgarazorflank:25|t Лабиринты Иглошкурых", 0, 0, 1, 1, -4657.3f, -2519.35f, 81.0529f, 4.54808f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_amnennar_the_coldbringer:25|t Курганы Иглошкурых", 0, 0, 1, 1, -4470.28f, -1677.77f, 81.3925f, 1.16302f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_mutanus_the_devourer:25|t Пещеры стенаний", 0, 0, 1, 1, -731.607f, -2218.39f, 17.0281f, 2.78486f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_bazil_akumai:25|t Непроглядная пучина", 0, 0, 0, 1, 4249.99f, 740.102f, -25.671f, 1.34062f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_emperordagranthaurissan:25|t Глубины Черной горы", 0, 0, 0, 0, -7179.34f, -921.212f, 165.821f, 5.09599f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_generaldrakkisath:25|t Пик Черной горы", 0, 0, 0, 0, -7527.05f, -1226.77f, 285.732f, 5.29626f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/ability_warrior_decisivestrike:25|t Забытый Город", 0, 0, 0, 1, -3520.14f, 1119.38f, 161.025f, 4.70454f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_princesstheradras:25|t Мародон", 0, 0, 0, 1, -1421.42f, 2907.83f, 137.415f, 1.70718f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_deathknight_armyofthedead:25|t Стратхольм", 0, 0, 0, 0, 3352.92f, -3379.03f, 144.782f, 6.25978f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_shadeoferanikus:25|t Храм Атал'Хаккара", 0, 0, 0, 0, -10177.9f, -3994.9f, -111.239f, 6.01885f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_archaedas:25|t Ульдаман", 0, 0, 0, 0, -6071.37f, -2955.16f, 209.782f, 0.015708f},
    {2, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_chiefukorzsandscalp:25|t Зул'Фаррак", 0, 0, 0, 1, -6801.19f, -2893.02f, 9.00388f, 0.158639f},
    {2, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_talonkingikiss:25|t Сетеккские залы", 0, 0, 0, 530, -3362.2f, 4664.12f, -101.049f, 4.6605f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_exarch_maladaar:25|t Аукенайские гробницы", 0, 0, 0, 530, -3362.04f, 5209.85f, -101.05f, 1.60924f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_murmur:25|t Темный лабиринт", 0, 0, 0, 530, -3627.9f, 4941.98f, -101.049f, 3.16039f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_nexus_prince_shaffar:25|t Гробницы маны", 0, 0, 0, 530, -3104.18f, 4945.52f, -101.507f, 6.22344f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_epochhunter:25|t Побег из Дарнхольда", 0, 0, 0, 1, -8404.3f, -4070.62f, -208.586f, 0.237038f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_aeonus_01:25|t Черные топи", 0, 0, 0, 1, -8734.3f, -4230.11f, -209.5f, 2.16212f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_theblackstalker:25|t Нижетопь", 0, 0, 0, 530, 763.307f, 6767.81f, -67.7695f, 5.99726f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_quagmirran:25|t Узилище", 0, 0, 0, 530, 717.282f, 6979.87f, -73.0281f, 1.50287f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_warlord_kalithresh:25|t Паровое подземелье", 0, 0, 0, 530, 794.537f, 6927.81f, -80.4757f, 0.159089f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_kelidanthebreaker:25|t Кузня Крови", 0, 0, 0, 530, -291.324f, 3149.1f, 31.5541f, 2.27147f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_omartheunscarred_01:25|t Бастионы Адского Пламени", 0, 0, 0, 530, -360.671f, 3071.9f, -15.0977f, 1.89389f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_kargathbladefist_01:25|t Разрушенные залы", 0, 0, 0, 530, -305.79f, 3061.63f, -2.53847f, 1.88888f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_Kael\'thasSunstrider_01.png:25|t Терраса Магистров", 0, 0, 0, 530, 12884.6f, -7317.69f, 65.5023f, 4.799f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_pathaleonthecalculator:25|t Механар", 0, 0, 0, 530, 2867.12f, 1549.42f, 252.159f, 3.82218f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_harbinger_skyriss:25|t Аркатрац", 0, 0, 0, 530, 3308.92f, 1340.72f, 505.56f, 4.94686f},
    {3, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_warpsplinter:25|t Ботаника", 0, 0, 0, 530, 3407.11f, 1488.48f, 182.838f, 5.59559f},
    {3, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_azjoluppercity_heroic:25|t Азжол-Неруб", 0, 0, 0, 571, 3707.86f, 2150.23f, 36.76f, 3.22f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_azjollowercity_heroic:25|t Ан'кахет: Старое Королевство", 0, 0, 0, 571, 3707.86f, 2150.23f, 36.76f, 3.22f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_cotstratholme_heroic:25|t Очищение Стратхольма", 0, 0, 0, 1, -8756.39f, -4440.68f, -199.489f, 4.66289f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/inv_spear_05:25|t Испытание чемпиона", 0, 0, 0, 571, 8590.95f, 791.792f, 558.235f, 3.13127f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Dungeon_Drak\'Tharon_Heroic.png:25|t Крепость Драк'Тарон", 0, 0, 0, 571, 4765.59f, -2038.24f, 229.363f, 0.887627f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_gundrak_heroic:25|t Гундрак", 0, 0, 0, 571, 6722.44f, -4640.67f, 450.632f, 3.91123f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_lichking:25|t Ледяные залы", 0, 0, 0, 571, 5643.16f, 2028.81f, 798.274f, 4.60242f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_icecrown_pitofsaron:25|t Яма Сарона", 0, 0, 0, 571, 5643.16f, 2028.81f, 798.274f, 4.60242f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_icecrown_forgeofsouls:25|t Кузня Душ", 0, 0, 0, 571, 5643.16f, 2028.81f, 798.274f, 4.60242f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_icecrown_hallsofreflection:25|t Залы Отражений", 0, 0, 0, 571, 5643.16f, 2028.81f, 798.274f, 4.60242f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_nexus80_25man:25|t Подземелья Нексуса", 0, 0, 0, 571, 3782.89f, 6965.23f, 105.088f, 6.14194f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_nexus80_heroic:25|t Окулус", 0, 0, 0, 571, 3782.89f, 6965.23f, 105.088f, 6.14194f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_theviolethold_heroic:25|t Аметистовая крепость", 0, 0, 0, 571, 5693.08f, 502.588f, 652.672f, 4.0229f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_ulduar80_heroic:25|t Чертоги Молний", 0, 0, 0, 571, 9136.52f, -1311.81f, 1066.29f, 5.19113f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_ulduar77_heroic:25|t Чертоги Камня", 0, 0, 0, 571, 8922.12f, -1009.16f, 1039.56f, 1.57044f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_utgardekeep_heroic:25|t Крепость Утгард", 0, 0, 0, 571, 1203.41f, -4868.59f, 41.2486f, 0.283237f},
    {4, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_utgardepinnacle_heroic:25|t Вершина Утгард", 0, 0, 0, 571, 1267.24f, -4857.3f, 215.764f, 3.22768f},
    {4, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_ArchmageArugal:25|t Крепость Темного клыка", 0, 0, 1, 0, -234.675f, 1561.63f, 76.8921f, 1.24031f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_EdwinVancleef:25|t Мертвые Копи", 0, 0, 2, 0, -11209.6f, 1666.54f, 24.6974f, 1.42053f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_blackrockcaverns:25|t Пещеры Черной горы", 0, 0, 0, 0, -7571.42f, -1320.84f, 245.537f, 4.82323f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_throne-of-the-tides:25|t Трон Приливов", 0, 0, 0, 0, -5599.09f, 5412.06f, -1798.73f, 5.715f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_skywall:25|t Вершина Смерча", 0, 0, 0, 1, -11513.3f, -2309.88f, 608.393f, 3.80963f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_deepholm:25|t Каменные Недра", 0, 0, 0, 646, 1027.44f, 628.709f, 156.672f, 4.96118f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_lostcity-of-tolvir:25|t Затерянный город Тол'вир", 0, 0, 0, 1, -10679.7f, -1307.1f, 17.342f, 3.40863f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_halls-of-origination:25|t Чертоги Созидания", 0, 0, 0, 1, -10210.5f, -1837.61f, 20.127f, 3.14945f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_grimbatol:25|t Грим Батол", 0, 0, 0, 0, -4053.51f, -3447.71f, 283.403f, 0.278495f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_nefarion:25|t Твердыня Крыла Тьмы", 0, 0, 0, 0, -7539.44f, -1196.08f, 477.769f, 1.94431f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_fire_twilightcano:25|t Сумеречный бастион", 0, 0, 0, 0, -4888.41f, -4239.17f, 827.763f, 2.14347f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_murmur:25|t Трон Четырех Ветров", 0, 0, 0, 1, -11355.f, 58.1567f, 723.882f, 1.88463f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_magtheridon:25|t Крепость Барадин", 0, 0, 0, 732, -1266.98f, 1049.99f, 106.995f, 3.17061f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_firelands:25|t Огненные Просторы", 0, 0, 0, 1, 3987.92f, -2945.83f, 1002.55f, 1.94685f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/inv_misc_demonsoul:25|t Душа Дракона", 0, 0, 0, 1, -8269.14f, -4514.72f, -219.44f, 0.216964f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_infinitecorruptor:25|t Конец Времен", 0, 0, 0, 1, -8296.45f, -4458.88f, -208.44f, 0.375153f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievment_boss_wellofeternity:25|t Источник Вечности", 0, 0, 0, 1, -8596.36f, -4001.64f, -205.546f, 1.36386f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievment_raid_houroftwilight:25|t Время Сумерек", 0, 0, 0, 1, -8289.69f, -4580.73f, -225.664f, 4.56163f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_hakkar:25|t Зул'Гуруб", 0, 0, 0, 0, -11916.7f, -1215.72f, 92.289f, 4.72454f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_zuljin:25|t Зул'Аман", 0, 0, 1, 530, 6851.78f, -7972.57f, 179.242f, 4.64691f},
    {5, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_nexus70_heroic:25|t Нексус", 0, 0, 0, 571, 3782.89f, 6965.23f, 105.088f, 6.14194f},
    {5, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_shadowpan_hideout:25|t Монастырь Шадо-Пан", 0, 0, 0, 870, 3595.63f, 2547.25f, 768.581f, 6.17207f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_holy_senseundead:25|t Некроситет", 0, 0, 0, 0, 1269.64f, -2556.21f, 93.6088f, 0.620623f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/inv_helmet_52:25|t Монастырь Алого ордена", 0, 0, 0, 0, 2904.75f, -806.089f, 160.332f, 0.37437f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_mogupalace:25|t Дворец Могу'шан", 0, 0, 0, 870, 1383.72f, 446.928f, 479.028f, 5.45814f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/inv_helmet_52:25|t Залы Алого ордена", 0, 0, 0, 0, 2880.22f, -816.266f, 160.332f, 3.51989f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_greatwall:25|t Врата Заходящего Солнца", 0, 0, 0, 870, 685.091f, 2079.15f, 371.71f, 0.03351f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_siegeofniuzaotemple:25|t Осада храма Нюцзао", 0, 0, 0, 870, 1342.53f, 5005.28f, 116.351f, 0.800745f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_jadeserpent:25|t Храм Нефритовой Змеи", 0, 0, 0, 870, 961.388f, -2463.32f, 180.581f, 4.35546f},
    {6, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_brewery:25|t Хмелеварня Буйных Портеров", 0, 0, 0, 870, -706.385f, 1265.21f, 136.023f, 3.39964f},
    {6, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_illidan:25|t Черный храм", 0, 0, 0, 530, -3649.92f, 317.469f, 35.2827f, 2.94285f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_nefarion:25|t Логово Крыла Тьмы", 0, 0, 0, 229, 152.451f, -474.881f, 116.84f, 0.001073f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_Archimonde .png:25|t Битва за гору Хиджал", 0, 0, 0, 1, -8177.89f, -4181.23f, -167.552f, 0.913338f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_ladyvashj:25|t Змеиное святилище", 0, 0, 0, 530, 797.855f, 6865.77f, -65.4165f, 0.005938f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_reputation_argentchampion:25|t Испытание крестоносца", 0, 0, 0, 571, 8515.61f, 714.153f, 558.248f, 1.57753f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_gruulthedragonkiller:25|t Логово Груула", 0, 0, 0, 530, 3530.06f, 5104.08f, 3.50861f, 5.51117f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_magtheridon:25|t Логово Магтеридона", 0, 0, 0, 530, -336.411f, 3130.46f, -102.928f, 5.20322f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_icecrown_icecrownentrance:25|t Цитадель Ледяной Короны", 0, 0, 0, 571, 5855.22f, 2102.03f, 635.991f, 3.57899f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_princemalchezaar_02:25|t Каражан", 0, 0, 0, 0, -11118.9f, -2010.33f, 47.0819f, 0.649895f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_ragnaros:25|t Огненные Недра", 0, 0, 0, 230, 1126.64f, -459.94f, -102.535f, 3.46095f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_naxxramas_10man:25|t Наксрамас", 0, 0, 0, 571, 3668.72f, -1262.46f, 243.622f, 4.785f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_onyxia:25|t Логово Ониксии", 0, 0, 0, 1, -4708.27f, -3727.64f, 54.5589f, 3.72786f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_ossiriantheunscarred:25|t Руины Ан'Киража", 0, 0, 0, 1, -8409.82f, 1499.06f, 27.7179f, 2.51868f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_kiljaedan:25|t Плато Солнечного Колодца", 0, 0, 0, 530, 12574.1f, -6774.81f, 15.0904f, 3.13788f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_character_bloodelf_male:25|t Око", 0, 0, 0, 530, 3088.49f, 1381.57f, 184.863f, 4.61973f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_cthun:25|t Храм Ан'Киража", 0, 0, 0, 1, -8240.09f, 1991.32f, 129.072f, 0.941603f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Boss_Malygos_01:25|t Око Вечности", 0, 0, 0, 571, 3784.17f, 7028.84f, 161.258f, 5.79993f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_coablackdragonflight_10man:25|t Обсидиановое святилище", 0, 0, 0, 571, 3472.43f, 264.923f, -120.146f, 3.27923f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_shadow_twilight:25|t Рубиновое святилище", 0, 0, 0, 571, 3590.78f, 211.701f, -120.054f, 5.32784f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_dungeon_ulduarraid_misc_01:25|t Ульдуар", 0, 0, 0, 571, 9222.88f, -1113.59f, 1216.12f, 6.27549f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_boss_kologarn_01:25|t Склеп Аркавона", 0, 0, 0, 571, 5453.72f, 2840.79f, 421.28f, 0.0f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_raid_terraceofendlessspring04:25|t Терраса Вечной Весны", 0, 0, 0, 870, 954.384f, -56.9305f, 511.163f, 0.97367f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_raid_mantidraid07:25|t Сердце Страха", 0, 0, 0, 870, 170.539f, 4042.16f, 255.912f, 1.75736f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_moguraid_06:25|t Подземелья Могу'шан", 0, 0, 0, 870, 3990.67f, 1101.01f, 497.156f, 2.23107f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/archaeology_5_0_thunderkinginsignia:25|t Престол Гроз", 0, 0, 0, 1064, 7241.38f, 5038.15f, 76.22f, 5.4945f},
    {7, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/inv_axe_60:25|t Осада Оргриммара", 0, 0, 0, 870, 1198.17f, 650.096f, 347.513f, 5.43946f},
    {7, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0 },

    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_elwynnforest:25|t Элвиннский Лес", 0, 0, 2, 0, -9449.06f, 64.8392f, 56.3581f, 3.07047f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_eversongwoods:25|t Леса Вечной Песни", 0, 0, 1, 530, 9024.37f, -6682.55f, 16.8973f, 3.14131f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_dunmorogh:25|t Дун Морог", 0, 0, 2, 0, -5603.76f, -482.704f, 396.98f, 5.23499f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_tirisfalglades_01:25|t Тирисфальские Леса", 0, 0, 1, 0, 2274.95f, 323.918f, 34.1137f, 4.24367f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_ghostlands:25|t Призрачные Земли", 0, 0, 1, 530, 7595.73f, -6819.6f, 84.3718f, 2.56561f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_lochmodan:25|t Лок Модан", 0, 0, 2, 0, -5405.85f, -2894.15f, 341.972f, 5.48238f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_silverpine_01:25|t Серебрянный Бор", 0, 0, 1, 0, 505.126f, 1504.63f, 124.808f, 1.77987f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_westfall_01:25|t Западный край", 0, 0, 2, 0, -10684.9f, 1033.63f, 32.5389f, 6.07384f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_redridgemountains:25|t Красногорье", 0, 0, 2, 0, -9447.8f, -2270.85f, 71.8224f, 0.283853f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_duskwood:25|t Сумеречный лес", 0, 0, 2, 0, -10531.7f, -1281.91f, 38.8647f, 1.56959f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_hillsbradfoothills:25|t Предгорья Хилсбрада", 0, 0, 0, 0, -385.805f, -787.954f, 54.6655f, 1.03926f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_wetlands_01:25|t Болотина", 0, 0, 2, 0, -3517.75f, -913.401f, 8.86625f, 2.60705f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Zone_AlteracMountains_01:25|t Альтеракские горы", 0, 0, 0, 0, 275.049f, -652.044f, 130.296f, 0.502032f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_arathihighlands_01:25|t Нагорье Арати", 0, 0, 0, 0, -1581.45f, -2704.06f, 35.4168f, 0.490373f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Zone_Stranglethorn_01:25|t Тернистая долина", 0, 0, 0, 0, -11921.7f, -59.544f, 39.7262f, 3.73574f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_badlands_01:25|t Бесплодные земли", 0, 0, 0, 0, -6782.56f, -3128.14f, 240.48f, 5.65912f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_swampsorrows_01:25|t Болото печали", 0, 0, 0, 0, -10368.6f, -2731.3f, 21.6537f, 5.29238f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_hinterlands_01:25|t Внутренние земли", 0, 0, 0, 0, 112.406f, -3929.74f, 136.358f, 0.981903f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_searinggorge_01:25|t Тлеющее ущелье", 0, 0, 0, 0, -6686.33f, -1198.55f, 240.027f, 0.916887f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_blastedlands_01:25|t Выжженные земли", 0, 0, 0, 0, -11184.7f, -3019.31f, 7.29238f, 3.20542f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_burningsteppes_01:25|t Пылающие степи", 0, 0, 0, 0, -7979.78f, -2105.72f, 127.919f, 5.10148f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_westernplaguelands_01:25|t Западные Чумные земли", 0, 0, 0, 0, 1743.69f, -1723.86f, 59.6648f, 5.23722f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_easternplaguelands:25|t Восточные Чумные земли", 0, 0, 0, 0, 2280.64f, -5275.05f, 82.0166f, 4.7479f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_deadwindpass:25|t Перевал Мертвого Ветра", 0, 0, 0, 0, -10438.8f, -1932.75f, 104.617f, 4.77402f},
    {8, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_isleofqueldanas:25|t Остров Кель'Данас", 0, 70, 0, 0, 12806.5f, -6911.11f, 41.1156f, 2.22935f},
    {8, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_azuremystisle_01:25|t Остров лазурной дымки", 0, 0, 2, 530, -4192.62f, -12576.7f, 36.7598f, 1.62813f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_darnassus:25|t Тельдрассил", 0, 0, 2, 1, 9889.03f, 915.869f, 1307.43f, 1.9336f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_durotar:25|t Дуротар", 0, 0, 1, 1, 228.978f, -4741.87f, 10.1027f, 0.416883f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_mulgore_01:25|t Мулгор", 0, 0, 1, 1, -2473.87f, -501.225f, -9.42465f, 0.6525f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_bloodmystisle_01:25|t Остров кровавой дымки", 0, 0, 2, 530, -2095.7f, -11841.1f, 51.1557f, 6.19288f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_darkshore_01:25|t Темные берега", 0, 0, 2, 1, 6463.25f, 683.986f, 8.92792f, 4.33534f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_barrens_01:25|t Степи", 0, 0, 1, 1, -575.772f, -2652.45f, 95.6384f, 0.006469f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_stonetalon_01:25|t Когтистые горы", 0, 0, 0, 1, 1574.89f, 1031.57f, 137.442f, 3.8013f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_ashenvale_01:25|t Ясеневый лес", 0, 0, 0, 1, 1919.77f, -2169.68f, 94.6729f, 6.14177f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_thousandneedles_01:25|t Тысяча игл", 0, 0, 1, 1, -5375.53f, -2509.2f, -40.432f, 2.41885f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_desolace:25|t Пустоши", 0, 0, 0, 1, -656.056f, 1510.12f, 88.3746f, 3.29553f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_dustwallowmarsh:25|t Пылевые топи", 0, 0, 0, 1, -3350.12f, -3064.85f, 33.0364f, 5.12666f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_feralas:25|t Фералас", 0, 0, 0, 1, -4808.31f, 1040.51f, 103.769f, 2.90655f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_tanaris_01:25|t Танарис", 0, 0, 0, 1, -6940.91f, -3725.7f, 48.9381f, 3.11174f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_azshara_01:25|t Азшара", 0, 0, 0, 1, 3117.12f, -4387.97f, 91.9059f, 5.49897f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_felwood:25|t Оскверненный лес", 0, 0, 0, 1, 3898.8f, -1283.33f, 220.519f, 6.24307f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_ungorocrater_01:25|t Кратер Ун'Горо", 0, 0, 0, 1, -6291.55f, -1158.62f, -258.138f, 0.457099f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_silithus_01:25|t Силитус", 0, 0, 0, 1, -6815.25f, 730.015f, 40.9483f, 2.39066f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_winterspring:25|t Зимние ключи", 0, 0, 0, 1, 6658.57f, -4553.48f, 718.019f, 5.18088f},
    {9, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_arcane_teleportmoonglade:25|t Лунная поляна", 0, 0, 0, 1, 7654.3f, -2232.87f, 462.107f, 5.96786f},
    {9, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_hellfirepeninsula_01:25|t Полуостров Адского пламени", 0, 0, 0, 530, -207.335f, 2035.92f, 96.464f, 1.59676f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_zangarmarsh:25|t Зангартопь", 0, 0, 0, 530, -220.297f, 5378.58f, 23.3223f, 1.61718f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_terrokar:25|t Лес Тероккар", 0, 0, 0, 530, -2266.23f, 4244.73f, 1.47728f, 3.68426f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_nagrand_01:25|t Награнд", 0, 0, 0, 530, -1610.85f, 7733.62f, -17.2773f, 1.33522f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_bladesedgemtns_01:25|t Острогорье", 0, 0, 0, 530, 2029.75f, 6232.07f, 133.495f, 1.30395f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_netherstorm_01:25|t Пустоверть", 0, 0, 0, 530, 3271.2f, 3811.61f, 143.153f, 3.44101f},
    {10, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_shadowmoon:25|t Долина призрачной луны", 0, 0, 0, 530, -3681.01f, 2350.76f, 76.587f, 4.25995f},
    {10, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_boreantundra_01:25|t Борейская тундра", 0, 0, 0, 571, 2954.24f, 5379.13f, 60.4538f, 2.55544f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_howlingfjord_01:25|t Ревущий фьорд", 0, 0, 0, 571, 682.848f, -3978.3f, 230.161f, 1.54207f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_dragonblight_01:25|t Драконий погост", 0, 0, 0, 571, 2678.17f, 891.826f, 4.37494f, 0.101121f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_grizzlyhills_01:25|t Седые холмы", 0, 0, 0, 571, 4017.35f, -3403.85f, 290.0f, 5.35431f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_zuldrak_03:25|t Зул'Драк", 0, 0, 0, 571, 5560.23f, -3211.66f, 371.709f, 5.55055f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_sholazar_01:25|t Низина Шолазар", 0, 0, 0, 571, 5614.67f, 5818.86f, -69.722f, 3.60807f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_crystalsong_01:25|t Хрустальная песня", 0, 0, 0, 571, 5411.17f, -966.37f, 167.082f, 1.57167f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_stormpeaks_01:25|t Грозовая гряда", 0, 0, 0, 571, 6120.46f, -1013.89f, 408.39f, 5.12322f},
    {11, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_icecrown_01:25|t Ледяная корона", 0, 0, 0, 571, 8323.28f, 2763.5f, 655.093f, 2.87223f},
    {11, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {12, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {13, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},

    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_BG_killingblow_most:25|t Пиратская бухта", 0, 30, 0, 0, -14281.9f, 552.564f, 8.90422f, 0.860144f},
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_BG_killingblow_most:25|t Прибамбасск", 0, 40, 0, 1, -7177.15f, -3785.34f, 8.36981f, 6.10237f},
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_BG_killingblow_most:25|t Кабестан", 0, 10, 0, 1, -956.664f, -3754.709f, 5.33239f, 0.99663f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/spell_arcane_teleportmoonglade:25|t Ночная гавань", 0, 0, 0, 1, 7966.85f, -2491.04f, 487.734f, 3.205620f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_nagrand_01:25|t Халаа", 0, 64, 0, 530, -1563.05f, 7945.6699f, -22.556f, 1.13572f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_netherstorm_01:25|t Зона 52", 0, 67, 0, 530, 3043.33f, 3681.33f, 143.0418f, 5.07464f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_winterspring:25|t Круговзор", 0, 55, 0, 1, 6729.276f, -4646.653f, 721.8131f, 4.2781f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_stormpeaks_01:25|t К-З", 0, 77, 0, 571, 6123.6362f, -1060.933f, 402.585f, 5.8718f },
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Arena_2v2_7:25|t Арена Гурубаши", 0, 30, 0, 0, -13181.8f, 339.356f, 42.9805f, 1.18013f},
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Arena_2v2_7:25|t Арена в Круге Крови", 0, 57, 0, 530, 2839.44f, 5930.17f, 11.1002f, 3.16284f},
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/Achievement_Arena_2v2_7:25|t Круг Испытаний", 0, 57, 0, 530, -1999.94f, 6581.71f, 11.32f, 2.36528f},
    {20, 0, GOSSIP_ICON_TAXI, "|TInterface/ICONS/achievement_zone_stormpeaks_03:25|t Озеро ледяных оков", 0, 0, 0, 571, 4522.23f, 2828.01f, 389.975f, 0.215009f},
    {20, 1, GOSSIP_ICON_TALK, "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:25|t [Назад]", 0, 0, 0, 0, 0, 0, 0, 0},
};

enum TeleportData
{
    TEXT_MAIN_H = 300000,
    TEXT_MAIN_A = 300001,
    TEXT_DUNGEON = 300002,
    TEXT_RAID = 300003,
    TEXT_AREA = 300004,

    TELEPORT_COUNT = sizeof Tele / sizeof(*Tele)
};

#define ARE_YOU_SURE "Вы уверены, что вы хотите попасть\nна локацию:\n\n\n"
#define ERROR_COMBAT "|cffff0000Вы в бою!|r"

bool Custom_FactCheck(uint32 Fact, unsigned char Key)
{
    bool Show = false;

    switch (Tele[Key].faction)
    {
    case 0:
        Show = true;
        break;
    case 1:
        if (Fact == HORDE)
            Show = true;
        break;
    case 2:
        if (Fact == ALLIANCE)
            Show = true;
        break;
    }

    return (Show);
}

uint32 Custom_GetText(unsigned int menu, Player* pPlayer)
{
    uint32 TEXT = TEXT_AREA;

    switch (menu)
    {
    case 0:
    case 1:
        switch (pPlayer->GetTeam())
        {
        case ALLIANCE:
            TEXT = TEXT_MAIN_A;
            break;
        case HORDE:
            TEXT = TEXT_MAIN_H;
            break;
        }
        break;
    case 2:
    case 3:
    case 4:
        TEXT = TEXT_DUNGEON;
        break;
    case 5:
        TEXT = TEXT_RAID;
        break;
    }

    return (TEXT);
}

void Custom_GetMenu(Player* pPlayer, Creature* pCreature, uint32 Key)
{
    bool ENDMENU = false;

    for (uint32 i = 0; i < TELEPORT_COUNT; i++)
    {
        if (ENDMENU && Tele[i].menu_id != Key)
            break;

        if (Tele[i].menu_id == Key && pPlayer->getLevel() >= Tele[i].level && Custom_FactCheck(pPlayer->GetTeam(), i))
        {
            /*if (Tele[i].next_menu_id != 0)
                pPlayer->ADD_GOSSIP_ITEM_EXTENDED(Tele[i].icon, Tele[i].name, GOSSIP_SENDER_MAIN, i, "", Tele[i].cost, false);
            else
                pPlayer->ADD_GOSSIP_ITEM_EXTENDED(Tele[i].icon, Tele[i].name, GOSSIP_SENDER_MAIN, i, ARE_YOU_SURE + Tele[i].name + "|r?", Tele[i].cost, false);*/
            ENDMENU = true;
        }
    }

    pPlayer->PlayerTalkClass->SendGossipMenu(Custom_GetText(Key, pPlayer), pCreature->GetGUID());
}

class npc_teleport : public CreatureScript
{
public:
    npc_teleport() : CreatureScript("npc_teleport") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        Custom_GetMenu(pPlayer, pCreature, 1);
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        pPlayer->ModifyMoney(-1 * Tele[uiAction].cost);
        uint32 Key = Tele[uiAction].next_menu_id;

        if (Key == 0)
        {
            if (!pPlayer->IsInCombat())
            {
                //pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->TeleportTo(Tele[uiAction].map, Tele[uiAction].x, Tele[uiAction].y, Tele[uiAction].z, Tele[uiAction].o);
                return true;
            }
            pCreature->Whisper(ERROR_COMBAT, Language::LANG_COMMON ,pPlayer, true);
            Key = Tele[uiAction].menu_id;
        }

        Custom_GetMenu(pPlayer, pCreature, Key);
        return true;
    }
};

void AddSC_npc_teleport()
{
    new npc_teleport();
}
