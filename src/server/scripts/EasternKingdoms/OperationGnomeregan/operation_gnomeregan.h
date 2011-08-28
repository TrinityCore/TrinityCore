/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 gmlt.A
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
 
enum eSpells
{
    SPELL_MUSIC_START           = 75760,
    SPELL_MUSIC                 = 75765,
    SPELL_MUSIC_END             = 75767,

    SPELL_TRIGGER               = 72400, // 100% wrong. Used for some special cases

    SPELL_HEALTH_REGEN          = 74503,
    SPELL_BRILLIANT_TACTICS     = 74501,

    SPELL_ATTACK                = 74413,
    SPELL_SHOOT                 = 74414,
    SPELL_GRENADE               = 74707,

    SPELL_RAD_GRENADE           = 74764,

    SPELL_MACHINE_GUN           = 74438,
    SPELL_FLAME_SPRAY           = 74440,

    SPELL_EXPLOSION             = 74550,
    SPELL_CANNON_SHOT           = 74307,
    SPELL_CANNON_SHIELD         = 74458,
    SPELL_ROCKET                = 64979, // May be wrong

    SPELL_PARACHUTE             = 79397,
    SPELL_PARACHUTE_AURA        = 79404,

    SPELL_WRENCH_THROW          = 74785, // Seems to have wrong throw model

///-------Used in final cinematic------
  //SPELL_ATTACH_CAMERA         = 75512, // [Unused]
    SPELL_SPAWN_INVISIBILITY    = 75513,
    SPELL_SEE_INVISIBILITY      = 75514,
    SPELL_BINDSIGHT             = 75517, // Custom spell

  //SPELL_RECALL_TRIGGER        = 75553, // Triggers Camera Vehicle summon [Unused]
    SPELL_RECALL                = 75510, // Teleport to camera start position
    SPELL_RECALL_FINAL          = 74412, // Realy final?

    SPELL_RAD_EXPLOSION         = 75545,
};

enum eCreatures
{
///----------------Allies---------------
    NPC_MEKKATORQUE             = 39271,
    NPC_BATTLE_SUIT             = 39902,
    NPC_FASTBLAST               = 39910,
    NPC_INFANTRY                = 39252,
    NPC_COGSPIN                 = 39273,
    NPC_BOMBER                  = 39735,
    NPC_ELGIN                   = 40478,
    NPC_TANK                    = 39860,

///----------------Enemies--------------
    NPC_I_INFANTRY              = 39755,
    NPC_IRRADIATOR              = 39903,
    NPC_I_CAVALRY               = 39836,
    NPC_GASHERIKK               = 39799,
    NPC_BRAG_BOT                = 39901,
    NPC_BOLTCOG                 = 39837,
    NPC_I_TROGG                 = 39826,
    NPC_I_TANK                  = 39819,
    NPC_CANNON                  = 39759, // Tankbuster Cannon
    NPC_RL                      = 39820, // Rocket Launcher

///--------------Bunnies----------------
    NPC_EXPLOSION_BUNNY         = 40506,
    NPC_CAMERA_VEHICLE          = 40479,
};

enum eObjects
{
    GO_BANNER                  = 194498,
    GO_RAD_CONTROL             = 202767,
    GO_IRRADIATOR              = 202922,
};

enum eMisc
{
    QUEST_OPERATION_GNOMEREGAN  = 25393,
    DATA_MOUNT_MEK              = 31692,
    DATA_MOUNT_FAST             = 6569,
    DATA_MOUNT_COG              = 9473,
    FACTION_GNOMEREGAN          = 1770,
};

enum eEvents
{
    EVENT_SUMMON_TROGG          = 0,
};

enum eWorldstates
{
    WORLDSTATE_IN_PROCCESS                              = 4981,
    WORLDSTATE_RL_DESTROYED                             = 5027,
    WORLDSTATE_RL_DESTROYED_CTRL                        = 5040,
    WORLDSTATE_BATTLE_NEAR_WORKSHOPS                    = 5018,
    WORLDSTATE_AIRFIELD_ATTACKED                        = 5039,
    WORLDSTATE_AIRFIELD_CAPTURED                        = 5044,
    WORLDSTATE_CANNONS_DESTROYED                        = 5006,
    WORLDSTATE_CANNONS_DESTROYED_CTRL                   = 5018,
    WORLDSTATE_AIRFIELD_AND_COMMAND_CENTER_CAPTURED     = 5043,
    WORLDSTATE_BATTLE_NEAR_ENTRANCE                     = 5019,
    WORLDSTATE_SURFACE_CAPTURED                         = 5045,
    WORLDSTATE_BATLLE_IN_TUNNELS                        = 5021,
    WORLDSTATE_TUNNELS_CAPTURED                         = 5011,
    WORLDSTATE_COUNTDOWN                                = 5037,
    WORLDSTATE_COUNTDOWN_CTRL                           = 5038,
};

const Position iInfantrySpawn[26] =
{
    {-5355.43f, 530.67f, 385.17f, 3.37f},
    {-5356.68f, 535.13f, 385.54f, 3.43f},
    {-5360.16f, 549.49f, 387.26f, 2.87f},
    {-5360.22f, 555.62f, 387.21f, 3.02f},
    {-5359.59f, 561.08f, 387.01f, 3.02f},
    {-5336.43f, 541.66f, 384.97f, 2.67f},
    {-5333.62f, 541.52f, 384.91f, 3.29f},
    {-5345.95f, 532.78f, 384.68f, 2.82f},
    {-5145.95f, 452.20f, 393.56f, 2.32f},
    {-5137.67f, 460.88f, 393.24f, 2.34f},
    {-5115.88f, 434.75f, 397.49f, 1.91f},
    {-5128.01f, 430.56f, 396.55f, 1.70f},
    {-5107.13f, 462.23f, 402.25f, 3.70f},
    {-5103.22f, 455.80f, 402.69f, 3.66f},
    {-5095.57f, 470.80f, 403.48f, 3.96f},
    {-5090.65f, 466.22f, 404.34f, 3.96f},
    {-5081.96f, 453.46f, 409.65f, 2.18f},
    {-5087.25f, 448.15f, 409.30f, 2.17f},
    {-5189.41f, 583.61f, 404.02f, 4.82f},
    {-5178.16f, 583.22f, 403.94f, 4.60f},
    {-5193.70f, 594.34f, 408.54f, 5.20f},
    {-5195.24f, 597.54f, 409.39f, 5.20f},
    {-5191.03f, 598.42f, 408.85f, 4.92f},
    {-5171.88f, 593.29f, 407.82f, 4.17f},
    {-5174.75f, 596.12f, 408.08f, 4.17f},
    {-5171.76f, 597.32f, 408.66f, 4.17f}
};

const Position iTankSpawn[4] =
{
    {-5338.99f, 535.53f, 384.99f, 2.88f},
    {-5349.29f, 556.11f, 385.13f, 3.47f},
    {-5303.43f, 584.31f, 389.94f, 3.79f},
    {-5085.88f, 475.44f, 402.24f, 3.92f}
};

const Position iSoldierSpawn[5] =
{
    {-5040.80f, 739.75f, 256.47f, 6.2f},
    {-5043.66f, 731.75f, 256.47f, 6.2f},
    {-5039.70f, 734.17f, 256.47f, 6.2f},
    {-5044.24f, 737.27f, 256.47f, 6.2f},
    {-5046.30f, 733.86f, 256.47f, 6.2f}
};

const Position InfantrySpawn[19] =
{
    {-5334.11f, 563.10f, 395.79f, 0.71f},
    {-5303.73f, 588.68f, 390.12f, 5.27f},
    {-5308.05f, 587.04f, 389.93f, 5.08f},
    {-5271.25f, 572.90f, 387.12f, 4.93f},
    {-5280.78f, 564.26f, 386.08f, 5.65f},
    {-5085.68f, 480.86f, 401.69f, 4.12f},
    {-5080.83f, 477.69f, 401.76f, 4.12f},
    {-5085.44f, 446.00f, 410.11f, 2.51f},
    {-5081.82f, 451.51f, 410.33f, 2.46f},
    {-5152.82f, 455.32f, 392.82f, 2.49f},
    {-5142.35f, 468.65f, 392.38f, 2.33f},
    {-5191.10f, 574.74f, 400.96f, 1.51f},
    {-5177.70f, 574.41f, 400.40f, 1.51f},
    {-4975.04f, 736.62f, 256.91f, 3.04f},
    {-4976.25f, 723.63f, 256.91f, 3.04f},
    {-5103.44f, 724.77f, 257.77f, 6.24f},
    {-5109.18f, 725.26f, 255.98f, 6.24f},
    {-5104.79f, 717.42f, 257.53f, 6.24f},
    {-5109.95f, 717.81f, 255.92f, 6.24f}
};

const Position RLSpawn[4] =
{
    {-5350.35f, 574.63f, 387.12f, 4.7f},
    {-5331.62f, 545.17f, 385.22f, 5.0f},
    {-5324.26f, 588.66f, 389.01f, 3.7f},
    {-5294.58f, 571.73f, 386.93f, 5.3f}
};

const Position CannonSpawn[6] =
{
    {-5140.57f, 428.39f, 395.89f, 2.1f},
    {-5109.37f, 426.51f, 399.66f, 2.4f},
    {-5109.00f, 481.10f, 398.45f, 3.9f},
    {-5071.21f, 457.83f, 410.94f, 3.0f},
    {-5087.23f, 434.92f, 411.78f, 1.9f},
    {-5092.15f, 450.84f, 406.63f, 1.4f}
};

const Position BattleSuitDriverSpawn[3] =
{
    {-5158.31f, 470.63f, 390.47f, 5.0f},
    {-5156.70f, 473.46f, 390.56f, 5.0f},
    {-5154.23f, 475.71f, 390.82f, 5.0f}
};

const Position BattleSuitSpawn[6] =
{
    {-5073.81f, 481.83f, 401.48f, 5.0f},
    {-5069.55f, 485.22f, 401.49f, 4.8f},
    {-5064.04f, 486.30f, 401.48f, 4.8f},
    {-5086.02f, 713.15f, 260.56f, 6.3f},
    {-5085.04f, 725.92f, 260.56f, 6.3f},
    {-5085.31f, 477.48f, 401.95f, 3.9f}
};

const Position TankSpawn[5] =
{
    {-5402.421387f, 543.972229f, 387.243896f, 6.1f},
    {-5404.228516f, 530.777527f, 387.151581f, 0.2f},
    {-5394.222656f, 519.042908f, 386.308929f, 1.0f},
    {-5280.954102f, 559.265808f, 385.679932f, 5.0f},
    {-5263.007813f, 572.262085f, 388.673157f, 5.0f}
};

const Position BragBotSpawn[2] =
{
    {-5183.73f, 599.90f, 408.96f, 4.6f},
    {-4933.62f, 717.18f, 261.65f, 1.6f}
};

const uint32 WorldStates[15] =
{
    4981,
    5027,
    5040,
    5018,
    5039,
    5044,
    5006,
    5018,
    5043,
    5019,
    5045,
    5021,
    5011,
    5037,
    5038
};

const Position BomberSpawn              = {-5314.53f, 564.82f, 391.43f, 5.7f};
const Position RadControlSpawn          = {-5072.80f, 441.48f, 410.97f, 2.6f};

const Position TroggSpawn               = {-5181.74f, 631.21f, 398.54f, 4.7f};

const Position ExplosionBunnySpawn      = {-5183.24f, 608.97f, 410.89f, 4.7f};

//#define SOUND_NAME            soundID // Duration
#define MEK_1_1                 "Граждане и друзья Гномрегана!"
#define MEK_1_2                 "Сегодня мы отвоюем у подлого предателя Термоштепселя наш славный город!"
#define MEK_1_3                 "Встанем плечом к плечу в битве за родину!"
#define SOUND_MEK_1             17535 // 17150
#define MEK_2_1                 "Наш народ познал достаточно мук и унижений. Мы были изгоями, рабами, тянущими ярмо боевой машины безумца!"
#define SOUND_MEK_2             17536 // 12200
#define MEK_3_1                 "Правлению Термоштепселя приходит конец!"
#define MEK_3_2                 "Объявляю общий сбор!"
#define SOUND_MEK_3             17537 // 7050
#define MEK_4_1                 "Военная тактика и научный прогресс, вкупе с нашей решимостью, приведут нас к победе!"
#define MEK_4_2                 "Начинаем наступление!"
#define SOUND_MEK_4             17538 // 10180
#define MEK_5_1                 "Операция 'Гномреган' НАЧИНАЕТСЯ!"
#define MEK_5_2                 "Первый этап: захват аэродрома."
#define MEK_5_3                 "Уничтожтье ракетомёты врага, и мы получим превосходство в воздухе!"
#define SOUND_MEK_5             17539 // 13500
#define MEK_6_1                 "Цель в зоне видимости! Орудия к бою! Уничтожить ракетомёты противника!"
#define SOUND_MEK_6             17541 // 6730
#define MEK_7_1                 "Ха-ха, этот готов! Продолжаем наступление!"
#define SOUND_MEK_7             17542 // 4970
#define MEK_8_1                 "Ха-ха, ещё один разбит! Не ослабляйте натиск!"
#define SOUND_MEK_8             17543 // 6160
#define MEK_9_1                 "Отличная работа! Продолжайте в том же духе."
#define SOUND_MEK_9             17544 // 4140
#define MEK_10_1                "Аэродром взят, и небо над Гномреганом наше!"
#define MEK_10_2                "Теперь наши бомбисты могут уничтожить защищённые противотанковые пушки Термоштепселя."
#define MEK_10_3                "Второй этап операции: захват наземного командного поста!"
#define SOUND_MEK_10            17546 // 16970
#define MEK_11_1                "Наши бомбисты разрушили защиту противотанковых пушек! Уничтожьте их и обеспечьте безопасность наземного командного пункта!"
#define SOUND_MEK_11            17547 // 9740
#define MEK_12_1                "Наземная часть города захвачена. Операция 'Гномреган' проходит с эффективностью 93 процента... Всех хвалю!"
#define MEK_12_2                "Отключаю защитные радиационные насосы. Отряды, захватите оставшихся боевых роботов и продвигайтесь к главному входу!"
#define SOUND_MEK_12            17548 // 16660
#define MEK_13_1                "Мы стоим на пороге победы, друзья мои! Третий этап: проникнуть в туннели!"
#define MEK_13_2                "Как только захватим подземную железную дорогу и погрузочную платформу, мы сможем ворваться в самое сердце города!"
#define MEK_13_3                "Победа близка!"
#define SOUND_MEK_13            17549 // 17600
#define THERM_1_1               "НИКОГДА!!! Так... Оно включено? Эта кнопка? Раз-два, раз-два... О!"
#define THERM_1_2               "НИКОГДА!!! Гномреган МОЙ, Меггакрут!"
#define THERM_1_3               "Думаешь ты просто так войдёшь в МОЙ город?"
#define THERM_1_4               "Активировать систему однократной атомной защиты! ВЫПУСТИТЬ ТРОГГОВ!"
#define SOUND_THERM_1           17569 // 23190
#define MEK_14_1                "Ёлки-шестерёнки... Да тут, похоже, собрались все трогги города! Солдаты, окопаться!"
#define MEK_14_2                "Осколочные гранаты и заградительный огонь! ДЕРЖАТЬ СТРОЙ! Отступать нельзя!"
#define SOUND_MEK_14            17550 // 14230
#define MEK_15_1                "Тысяча сопливых титанят! Никогда не видел такого огромного трогга! Продолжать обстрел... уничтожить его!!!"
#define SOUND_MEK_15            17551 // 9560
#define MEK_16_1                "Слишком уж тихо. Где войска Термоштепселя?"
#define SOUND_MEK_16            17552 // 5520
#define MEK_17_1                "Что это? Похоже на ядерную бомбу, которая погубила Гномреган... Стоять! Враг идёт!"
#define SOUND_MEK_17            17553 // 9690
#define BOLTCOG_1               "Нашу защиту вам не преодолеть. МЫ истинные сыны Гномрегана!"
#define SOUND_BOLTCOG_1         17665 // 6100
#define THERM_2_1               "Нет! Нет, нет, НЕТ! Я не позволю тебе войти в своё королевство, узурпатор!"
#define THERM_2_2               "Активировать систему атомной защиты!"
#define THERM_2_3               "ДЕЗИНТЕГРИРОВАТЬ ИХ ВСЕХ!"
#define SOUND_THERM_2           17570 // 14640
#define MEK_18_1                "ЭТО ЛОВУШКА! Здесь работает облучатель!"
#define SOUND_MEK_18            17554 // 3830
#define THERM_3_1               "Так и есть. И она в ДВАДЦАТЬ ШЕСТЬ РАЗ мощнее первой!"
#define THERM_3_2               "Меггакрут, ты ПРОИГРАЛ! Я победил тебя раньше чем ты успел вступить в мой прекрасный город."
#define THERM_3_3               "А теперь УМРИ!"
#define THERM_3_4               "О, хотел бы я увидеть лицо этого жулика. Клянусь он... Что? Всё ещё включено? ВЫКЛЮЧИ!!!"
#define SOUND_THERM_3           17571 // 22980
#define IRRADIATOR_1_1          "Облучатель 3000 активирован. Внимание. Чрезвычайная ситуация. У вас осталось 10 минут для того, чтобы оказаться на минимальном безопасном расстоянии."
#define SOUND_IRRADIATOR_1      17635 // 10830
#define MEK_19_1                "Десять минут? Мы сто раз обезвредим устройство."
#define MEK_19_2                "Хинклс, протяни-ка трещащий бронзовый механизм и дай свежей воды! Шестерёнок, швырни мне грязное одеяние трогга и дай горсть медных винтов..."
#define SOUND_MEK_19            17556 // 14930
#define THERM_4_1               "ДЕСЯТЬ МИНУТ?! Ты оставил заводские настройки? Идиот, быстро отдай регулятор!"
#define SOUND_THERM_4           17572 // 9970
#define IRRADIATOR_2_1          "Внимание. Чрезвычайная ситуация. У вас осталось 10 секунд для того, чтобы оказаться на минимальном безопасном расстоянии."
#define SOUND_IRRADIATOR_2      17636 // 7670
#define MEK_20_1                "Надо убираться отсюда! Ла Форж, скорее телепортируй нас!"
#define SOUND_MEK_20            17557 // 4790
#define MEK_21_1                "Проклятье! Пришлось отступить. Но Термоштепсель проиграл, и он это знает... Он лишь получил небольшую отсрочку."
#define MEK_21_2                "Мы завладели поверхностью, а когда уровень радиации снизится, вернёмся с вдвое большей армией и отвоюем Гномреган!"
#define SOUND_MEK_21            17558 // 19280
