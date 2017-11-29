-------------------- QUEST_STATUS ----------------------

SET @QUEST_STATUS_NONE                  = 1;
SET @QUEST_STATUS_COMPLETE              = 2;
SET @QUEST_STATUS_INCOMPLETE            = 8;
SET @QUEST_STATUS_FAILED                = 32;
SET @QUEST_STATUS_REWARDED              = 64;

SET @QUEST_TAKEN                        = @QUEST_STATUS_INCOMPLETE | @QUEST_STATUS_FAILED | @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;
SET @QUEST_STATUS_NOT_COMPLETED         = @QUEST_STATUS_NONE | @QUEST_STATUS_INCOMPLETE | @QUEST_STATUS_FAILED;
SET @QUEST_STATUS_NOT_IN_PROGRESS       = @QUEST_STATUS_NONE | @QUEST_STATUS_FAILED | @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;
SET @QUEST_STATUS_COMPLETED_REWARDED    = @QUEST_STATUS_COMPLETE | @QUEST_STATUS_REWARDED;

-------------------- PHASES ----------------------

SET @PHASE_169  = 172329;
SET @PHASE_170  = 59073;
SET @PHASE_171  = 59074;
SET @PHASE_172  = 59087;
SET @PHASE_173  = 54341;
--SET @PHASE_174  = 0;
SET @PHASE_175  = 57569;
SET @PHASE_176  = 74789;
SET @PHASE_177  = 74092;
--SET @PHASE_178  = 0;
SET @PHASE_179  = 67789;
SET @PHASE_180  = 68480;
SET @PHASE_181  = 68481;
SET @PHASE_182  = 68482;
SET @PHASE_183  = 68483;
SET @PHASE_184  = 69077;
SET @PHASE_185  = 69078;
SET @PHASE_186  = 69484;
SET @PHASE_187  = 69485;
SET @PHASE_188  = 69486;
SET @PHASE_189  = 70695;

-------------------- QUESTS ----------------------

-- Blasted Land
SET @QUEST_THE_DARK_PORTAL                  = 36881;

-- Front of Portal
SET @QUEST_AZEROTH_LAST_STAND               = 35933;
SET @QUEST_ONSLAUGHT_END                    = 34392;
SET @QUEST_THE_PORTAL_POWER                 = 34393;
SET @QUEST_THE_COST_OF_WAR                  = 34420;

-- Bleeding Hollow
SET @QUEST_VENGEANCE_FOR_THE_FALLEN_A       = 35242;
SET @QUEST_VENGEANCE_FOR_THE_FALLEN_H       = 35241;
SET @QUEST_BLED_DRY_A                       = 35240;
SET @QUEST_BLED_DRY_H                       = 34421;
SET @QUEST_BLAZE_OF_GLORY                   = 34422;

SET @QUEST_ALTAR_ALTERCATION                = 34423;
SET @QUEST_THE_KARGATHAR_PROVING_GROUNDS    = 34425;

-- Shatered Hand

SET @QUEST_POTENTIAL_ALLY_A                 = 34478;
SET @QUEST_POTENTIAL_ALLY_H                 = 34427;

SET @QUEST_KILL_YOUR_HUNDRED                = 34429;

-- Shadowmoon

SET @QUEST_THE_SHADOWMOON_CLAN_A            = 34432;
SET @QUEST_THE_SHADOWMOON_CLAN_H            = 34739;

SET @QUEST_MASTERS_OF_SHADOW_A              = 34431;
SET @QUEST_MASTERS_OF_SHADOW_H              = 34737;

SET @QUEST_YREL_A                           = 34434;
SET @QUEST_YREL_H                           = 34740;

SET @QUEST_KELIDAN_THE_BREAKER_A            = 34436;
SET @QUEST_KELIDAN_THE_BREAKER_H            = 34741;

-- BlackHand

SET @QUEST_PREPARE_FOR_BATTLE_A             = 35019;
SET @QUEST_PREPARE_FOR_BATTLE_H             = 35005;
SET @QUEST_THE_BATTLE_OF_THE_FORGE          = 34439;

SET @QUEST_THE_GUNPOWDER_PLOT               = 34987;
SET @QUEST_THE_SHADOW_OF_THE_WORLDBREAKER   = 34958;

SET @QUEST_GANAR_OF_THE_FROSTWOLF           = 34442;
SET @QUEST_POLISHING_THE_IRON_THRONE        = 34925;
SET @QUEST_THE_PRODIGAL_FROSTWOLF           = 34437;

SET @QUEST_TRIP_TO_TOP_OF_TANK              = 35747;
SET @QUEST_TASTE_OF_IRON                    = 34445;

SET @QUEST_THE_HOME_STRETCH_A               = 35884;
SET @QUEST_THE_HOME_STRETCH_H               = 34446;

-------------------- AREAS ----------------------

SET @ZONE_TANAAN            = 7025;
SET @AREA_DARK_PORTAL       = 7037;
SET @AREA_HEARTH_BLOOD      = 7041;
SET @AREA_HEARTH_BLOOD_MAZE = 7038;
SET @AREA_BLEEDING_ALTAR    = 7039;
SET @AREA_TAR_THOG_BRIDGE   = 7129;
SET @AREA_KARGATHAR_ORDEAL  = 7040;
SET @AREA_BLADEFIST_PINACLE = 7130;
SET @AREA_UMBRAL_HALLS      = 7042;
SET @AREA_BLACKROCK_QUARY   = 7043;
SET @AREA_PATH_OF_GLORY     = 7044;
SET @AREA_IRON_STRONGHOLD   = 7045;

------------------- RACEMASK -------------------

SET @TEAM_BOTH      = -1;
SET @TEAM_ALLIANCE  =  0;
SET @TEAM_HORDE     =  1;

-------------------- SPELL_AREA ----------------------

DELETE FROM spell_area WHERE area IN (@ZONE_TANAAN, @AREA_DARK_PORTAL, @AREA_HEARTH_BLOOD, @AREA_HEARTH_BLOOD_MAZE, @AREA_BLEEDING_ALTAR, @AREA_TAR_THOG_BRIDGE,
                                      @AREA_KARGATHAR_ORDEAL, @AREA_BLADEFIST_PINACLE, @AREA_UMBRAL_HALLS, @AREA_BLACKROCK_QUARY, @AREA_PATH_OF_GLORY, @AREA_IRON_STRONGHOLD);
INSERT INTO spell_area (spell, area, quest_start, quest_end, teamid, quest_start_status, quest_end_status) VALUES
-- Phase            Area                    Quete Depart                            Quete Fin                               Faction             Quete depart doit etre              Quete fin ne doit pas etre

-------- GLOBAL --------

-- Porte
-- Entiere
(@PHASE_170,        @ZONE_TANAAN,           0,                                      @QUEST_TASTE_OF_IRON,                   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),
-- Cassée
(@PHASE_171,        @ZONE_TANAAN,           @QUEST_TASTE_OF_IRON,                   0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-------- AREA DE LA PORTE --------

(@PHASE_172,        @AREA_DARK_PORTAL,      0,                                      @QUEST_THE_SHADOWMOON_CLAN_A,           @TEAM_BOTH,         0,                                  @QUEST_TAKEN                        ),

-- Kahdgar & Thrall
(@PHASE_173,        @AREA_DARK_PORTAL,      0,                                      @QUEST_THE_COST_OF_WAR,                 @TEAM_BOTH,         0,                                  @QUEST_TAKEN                        ),

-- Tours
 -- Right Cho'Gall
(@PHASE_175,        @AREA_DARK_PORTAL,      0,                                      @QUEST_ONSLAUGHT_END,                   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),
 -- Left Teron'Gor
(@PHASE_176,        @AREA_DARK_PORTAL,      0,                                      @QUEST_ONSLAUGHT_END,                   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Gul'dan
(@PHASE_177,        @AREA_DARK_PORTAL,      0,                                      @QUEST_THE_PORTAL_POWER,                @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Door color + collision
(@PHASE_179,        @AREA_DARK_PORTAL,      0,                                      @QUEST_ONSLAUGHT_END,                   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_180,        @AREA_DARK_PORTAL,      @QUEST_ONSLAUGHT_END,                   @QUEST_THE_PORTAL_POWER,                @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),


-- Main troops, they appear after Gul'dan and go with Kahdgat & Thrall
(@PHASE_181,        @AREA_DARK_PORTAL,      @QUEST_THE_PORTAL_POWER,                @QUEST_THE_COST_OF_WAR,                 @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),

-------- AREA SANG DU COEUR --------

-- We see this zone from the door so we cannot start over

-- Main troops, in the hut
(@PHASE_182,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 @QUEST_BLAZE_OF_GLORY,                  @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
-- Corpses in the hut, they'll stay forever
(@PHASE_183,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-- Quests givers
(@PHASE_184,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 0,                                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
(@PHASE_185,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 0,                                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-- From here we can't see it from door, so we can start over
-- South & East cage

-- alliance
(@PHASE_172,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_A,                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_172,        @AREA_HEARTH_BLOOD_MAZE,@QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_A,                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_173,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_A,                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),

-- horde
(@PHASE_175,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_H,                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_175,        @AREA_HEARTH_BLOOD_MAZE,@QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_H,                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_176,        @AREA_HEARTH_BLOOD,     @QUEST_THE_COST_OF_WAR,                 @QUEST_BLED_DRY_H,                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Top hill troops
(@PHASE_177,        @AREA_HEARTH_BLOOD,     @QUEST_BLAZE_OF_GLORY,                  @QUEST_ALTAR_ALTERCATION,               @TEAM_BOTH,         @QUEST_TAKEN,                       @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_179,        @AREA_HEARTH_BLOOD,     @QUEST_BLAZE_OF_GLORY,                  @QUEST_ALTAR_ALTERCATION,               @TEAM_ALLIANCE,     @QUEST_TAKEN,                       @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_180,        @AREA_HEARTH_BLOOD,     @QUEST_BLAZE_OF_GLORY,                  @QUEST_ALTAR_ALTERCATION,               @TEAM_HORDE,        @QUEST_TAKEN,                       @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Ariok phase, top hill
(@PHASE_181,        @AREA_HEARTH_BLOOD,     @QUEST_BLAZE_OF_GLORY,                  @QUEST_ALTAR_ALTERCATION,               @TEAM_BOTH,         @QUEST_TAKEN,                       @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Bridges, they must be visible from 3 different areas

-- Intact
(@PHASE_185,        @AREA_BLEEDING_ALTAR,   0,                                      @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_185,        @AREA_TAR_THOG_BRIDGE,  0,                                      @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),
(@PHASE_185,        @AREA_KARGATHAR_ORDEAL, 0,                                      @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         0,                                  @QUEST_STATUS_COMPLETED_REWARDED    ),

-- Broke
(@PHASE_186,        @AREA_BLEEDING_ALTAR,   @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
(@PHASE_186,        @AREA_TAR_THOG_BRIDGE,  @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
(@PHASE_186,        @AREA_KARGATHAR_ORDEAL, @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-- Kahdgar after bridge
(@PHASE_187,        @AREA_BLEEDING_ALTAR,   @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         @QUEST_STATUS_NONE,                 @QUEST_TAKEN                        ),
(@PHASE_187,        @AREA_TAR_THOG_BRIDGE,  @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         @QUEST_STATUS_NONE,                 @QUEST_TAKEN                        ),
(@PHASE_187,        @AREA_KARGATHAR_ORDEAL, @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @TEAM_BOTH,         @QUEST_STATUS_NONE,                 @QUEST_TAKEN                        ),

-- Kahdgar with troops, we can start over from here
(@PHASE_172,        @AREA_KARGATHAR_ORDEAL, @QUEST_THE_KARGATHAR_PROVING_GROUNDS,   @QUEST_KILL_YOUR_HUNDRED,               @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),

(@PHASE_173,        @AREA_KARGATHAR_ORDEAL, @QUEST_POTENTIAL_ALLY_A,                @QUEST_KILL_YOUR_HUNDRED,               @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
(@PHASE_173,        @AREA_KARGATHAR_ORDEAL, @QUEST_POTENTIAL_ALLY_H,                @QUEST_KILL_YOUR_HUNDRED,               @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),

(@PHASE_175,        @AREA_KARGATHAR_ORDEAL, @QUEST_ALTAR_ALTERCATION,               @QUEST_KILL_YOUR_HUNDRED,               @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
-- alliance or horde slaves
(@PHASE_176,        @AREA_KARGATHAR_ORDEAL, @QUEST_ALTAR_ALTERCATION,               @QUEST_KILL_YOUR_HUNDRED,               @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
(@PHASE_177,        @AREA_KARGATHAR_ORDEAL, @QUEST_ALTAR_ALTERCATION,               @QUEST_KILL_YOUR_HUNDRED,               @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),

---- Shadowmoon

-- Cavern troops (beginning)
(@PHASE_172,        @AREA_UMBRAL_HALLS,     @QUEST_KILL_YOUR_HUNDRED,               0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
-- horde or alliance slaves
(@PHASE_173,        @AREA_UMBRAL_HALLS,     @QUEST_KILL_YOUR_HUNDRED,               0,                                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
(@PHASE_175,        @AREA_UMBRAL_HALLS,     @QUEST_KILL_YOUR_HUNDRED,               0,                                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
-- Olin & Liadrin
(@PHASE_176,        @AREA_UMBRAL_HALLS,     @QUEST_KILL_YOUR_HUNDRED,               0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
-- Maladaar & Qiana
(@PHASE_177,        @AREA_UMBRAL_HALLS,     @QUEST_KILL_YOUR_HUNDRED,               0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-- Yrel in front of the corpse
(@PHASE_179,        @AREA_UMBRAL_HALLS,     0,                                      @QUEST_YREL_A,                          @TEAM_ALLIANCE,     0,                                  @QUEST_TAKEN                        ),
(@PHASE_179,        @AREA_UMBRAL_HALLS,     0,                                      @QUEST_YREL_H,                          @TEAM_HORDE,        0,                                  @QUEST_TAKEN                        ),
-- Yrel behind maraad, top
(@PHASE_180,        @AREA_UMBRAL_HALLS,     @QUEST_YREL_A,                          @QUEST_KELIDAN_THE_BREAKER_A,           @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
(@PHASE_180,        @AREA_UMBRAL_HALLS,     @QUEST_YREL_H,                          @QUEST_KELIDAN_THE_BREAKER_H,           @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
-- maraad, top
(@PHASE_181,        @AREA_UMBRAL_HALLS,     0,                                      @QUEST_KELIDAN_THE_BREAKER_A,           @TEAM_ALLIANCE,     0,                                  @QUEST_TAKEN                        ),
-- Liadrin, top
(@PHASE_182,        @AREA_UMBRAL_HALLS,     0,                                      @QUEST_KELIDAN_THE_BREAKER_H,           @TEAM_HORDE,        0,                                  @QUEST_TAKEN                        ),

---- Blackrock

-- Slaves
(@PHASE_172,        @AREA_BLACKROCK_QUARY,  @QUEST_KELIDAN_THE_BREAKER_A,           @QUEST_PREPARE_FOR_BATTLE_A,            @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_REWARDED              ),
(@PHASE_172,        @AREA_BLACKROCK_QUARY,  @QUEST_KELIDAN_THE_BREAKER_H,           @QUEST_PREPARE_FOR_BATTLE_H,            @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_REWARDED              ),

-- Main npcs
(@PHASE_173,        @AREA_BLACKROCK_QUARY,  @QUEST_KELIDAN_THE_BREAKER_A,           @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),
(@PHASE_173,        @AREA_BLACKROCK_QUARY,  @QUEST_KELIDAN_THE_BREAKER_H,           @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_TAKEN                        ),

-- Phase de la carrière avec uniquement les porteurs / travailleurs
(@PHASE_175,        @AREA_BLACKROCK_QUARY,  0,                                      @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_BOTH,         0,                                  @QUEST_TAKEN                        ),

-- Phase avec la bataille
(@PHASE_176,        @AREA_BLACKROCK_QUARY,  @QUEST_THE_BATTLE_OF_THE_FORGE,         @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_BOTH,         @QUEST_TAKEN,                       @QUEST_STATUS_REWARDED              ),

-- Kahdgar sur le rocher
(@PHASE_177,        @AREA_BLACKROCK_QUARY,  @QUEST_THE_BATTLE_OF_THE_FORGE,         @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_BOTH,         @QUEST_TAKEN,                       @QUEST_STATUS_REWARDED              ),

-- Barrage
(@PHASE_179,        @AREA_BLACKROCK_QUARY,  0,                                      @QUEST_THE_BATTLE_OF_THE_FORGE,         @TEAM_BOTH,         0,                                  @QUEST_STATUS_REWARDED              ),

-- Troupe en haut
(@PHASE_180,        @AREA_BLACKROCK_QUARY,  @QUEST_THE_BATTLE_OF_THE_FORGE,         0,                                      @TEAM_BOTH,         @QUEST_STATUS_REWARDED,             0                                   ),

-- Troupe en haut
(@PHASE_181,        @AREA_BLACKROCK_QUARY,  @QUEST_GANAR_OF_THE_FROSTWOLF,          0,                                      @TEAM_BOTH,         @QUEST_TAKEN,                       0                                   ),

-- Ganar Chiottes
(@PHASE_182,        @AREA_BLACKROCK_QUARY,  0,                                      @QUEST_THE_PRODIGAL_FROSTWOLF,          @TEAM_BOTH,         0,                                  @QUEST_TAKEN                        ),
-- Ganar avec troupe
(@PHASE_183,        @AREA_BLACKROCK_QUARY,  @QUEST_THE_PRODIGAL_FROSTWOLF,          0,                                      @TEAM_BOTH,         @QUEST_TAKEN,                       0                                   ),
-- Thaelin avec la troupe
(@PHASE_184,        @AREA_BLACKROCK_QUARY,  @QUEST_THE_BATTLE_OF_THE_FORGE,         0,                                      @TEAM_BOTH,         @QUEST_STATUS_REWARDED,             0                                   ),

--- Sentier de la Gloire

-- Thaelin sur canon
(@PHASE_172,        @AREA_PATH_OF_GLORY,    @QUEST_TRIP_TO_TOP_OF_TANK,             @QUEST_TASTE_OF_IRON,                   @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_TAKEN                 ),
(@PHASE_172,        @AREA_PATH_OF_GLORY,    @QUEST_TASTE_OF_IRON,                   @QUEST_THE_HOME_STRETCH_A,              @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_TAKEN                 ),
(@PHASE_172,        @AREA_PATH_OF_GLORY,    @QUEST_TASTE_OF_IRON,                   @QUEST_THE_HOME_STRETCH_H,              @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   @QUEST_STATUS_TAKEN                 ),
-- Gogluk
(@PHASE_173,        @AREA_PATH_OF_GLORY,    @QUEST_TRIP_TO_TOP_OF_TANK,             @QUEST_TRIP_TO_TOP_OF_TANK,             @TEAM_BOTH,         @QUEST_TAKEN,                       @QUEST_STATUS_COMPLETED_REWARDED    ),
-- Les canons de coté
(@PHASE_175,        @AREA_PATH_OF_GLORY,    @QUEST_TRIP_TO_TOP_OF_TANK,             0,                                      @TEAM_BOTH,         @QUEST_TAKEN,                       0                                   ),
-- Gob décoratifs près du déclencheur, géré par le sceneobjet
(@PHASE_176,        @AREA_PATH_OF_GLORY,    @QUEST_TASTE_OF_IRON,                   0,                                      @TEAM_BOTH,         @QUEST_STATUS_NOT_IN_PROGRESS,      0                                   ),
-- Bataille post-canons
(@PHASE_179,        @AREA_PATH_OF_GLORY,    @QUEST_TASTE_OF_IRON,                   0,                                      @TEAM_BOTH,         @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),


-- Mobs décoratifs penadnt la course, on les voit au début depuis le canon qui est dans AREA_PATH_OF_GLORY
(@PHASE_180,        @AREA_PATH_OF_GLORY,    @QUEST_THE_HOME_STRETCH_A,              0,                                      @TEAM_ALLIANCE,     @QUEST_TAKEN,                       0                                   ),
(@PHASE_180,        @AREA_IRON_STRONGHOLD,  @QUEST_THE_HOME_STRETCH_A,              0,                                      @TEAM_ALLIANCE,     @QUEST_TAKEN,                       0                                   ),

-- Pareil mais pour la horde
(@PHASE_181,        @AREA_PATH_OF_GLORY,    @QUEST_THE_HOME_STRETCH_H,              0,                                      @TEAM_HORDE,        @QUEST_TAKEN,                       0                                   ),
(@PHASE_181,        @AREA_IRON_STRONGHOLD,  @QUEST_THE_HOME_STRETCH_H,              0,                                      @TEAM_HORDE,        @QUEST_TAKEN,                       0                                   ),

-- Phase de la derniere troupe
(@PHASE_172,        @AREA_IRON_STRONGHOLD,  @QUEST_THE_HOME_STRETCH_A,              0,                                      @TEAM_ALLIANCE,     @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),
(@PHASE_172,        @AREA_IRON_STRONGHOLD,  @QUEST_THE_HOME_STRETCH_H,              0,                                      @TEAM_HORDE,        @QUEST_STATUS_COMPLETED_REWARDED,   0                                   ),

-- Phase des bateaux
(@PHASE_173,        @AREA_IRON_STRONGHOLD,  0,                                      @QUEST_THE_HOME_STRETCH_A,              @TEAM_ALLIANCE,     0,                                  @QUEST_STATUS_REWARDED              ),
(@PHASE_173,        @AREA_IRON_STRONGHOLD,  0,                                      @QUEST_THE_HOME_STRETCH_H,              @TEAM_HORDE,        0,                                  @QUEST_STATUS_REWARDED              );

UPDATE spell_area set autocast = 1 WHERE area IN (@ZONE_TANAAN, @AREA_DARK_PORTAL, @AREA_HEARTH_BLOOD, @AREA_HEARTH_BLOOD_MAZE, @AREA_BLEEDING_ALTAR, @AREA_TAR_THOG_BRIDGE,
                                                  @AREA_KARGATHAR_ORDEAL, @AREA_BLADEFIST_PINACLE, @AREA_UMBRAL_HALLS, @AREA_BLACKROCK_QUARY, @AREA_PATH_OF_GLORY, @AREA_IRON_STRONGHOLD);
