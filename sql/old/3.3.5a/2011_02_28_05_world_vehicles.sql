-- Argent Tournament mounts implementation
SET @GUID = 151783;
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33870; -- Stabled Argent Warhorse
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33790; -- Stabled Exodar Elekk
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33791; -- Stabled Silvermoon Hawkstrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33792; -- Stabled Thunder Bluff Kodo
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33793; -- Stabled Gnomeregan Mechanostrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33794; -- Stabled Darnassian Nightsaber
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33795; -- Stabled Ironforge Ram
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33796; -- Stabled Darkspear Raptor
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33798; -- Stabled Forsaken Warhorse
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33799; -- Stabled Orgrimmar Wolf
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33800; -- Stabled Stormwind Steed
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33842; -- Stabled Sunreaver Hawkstrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`speed_run`=1.5714285714286 WHERE `entry`=33843; -- Stabled Quel'dorei Steed

UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=0 WHERE `modelid`=29255; -- Stabled Exodar Elekk
UPDATE `creature_model_info` SET `bounding_radius`=1.185,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=29256; -- Stabled Darnassian Nightsaber
UPDATE `creature_model_info` SET `bounding_radius`=0.818,`combat_reach`=2,`gender`=0 WHERE `modelid`=29258; -- Stabled Ironforge Ram
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29261; -- Stabled Darkspear Raptor
UPDATE `creature_model_info` SET `bounding_radius`=0,`combat_reach`=1,`gender`=2 WHERE `modelid`=28918; -- Stabled Argent Warhorse

DELETE FROM `creature_template_addon` WHERE `entry` IN (33870,33790,33791,33792,33793,33794,33795,33796,33798,33799,33800,33842,33843);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33870,0,0,1,0, NULL), -- Stabled Argent Warhorse
(33790,0,0,1,0, NULL), -- Stabled Exodar Elekk
(33791,0,0,1,0, NULL), -- Stabled Silvermoon Hawkstrider
(33792,0,0,1,0, NULL), -- Stabled Thunder Bluff Kodo
(33793,0,0,1,0, NULL), -- Stabled Gnomeregan Mechanostrider
(33794,0,0,1,0, NULL), -- Stabled Darnassian Nightsaber
(33795,0,0,1,0, NULL), -- Stabled Ironforge Ram
(33796,0,0,1,0, NULL), -- Stabled Darkspear Raptor
(33798,0,0,1,0, NULL), -- Stabled Forsaken Warhorse
(33799,0,0,1,0, NULL), -- Stabled Orgrimmar Wolf
(33800,0,0,1,0, NULL), -- Stabled Stormwind Steed
(33842,0,0,1,0, NULL), -- Stabled Sunreaver Hawkstrider
(33843,0,0,1,0, NULL); -- Stabled Quel'dorei Steed

UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33782; -- Argent Warhorse
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`faction_A`=35,`faction_H`=35,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33318; -- Exodar Elekk
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33323; -- Silvermoon Hawkstrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33322; -- Thunder Bluff Kodo
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`faction_A`=35,`faction_H`=35,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33317; -- Gnomeregan Mechanostrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`faction_A`=35,`faction_H`=35,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33319; -- Darnassian Nightsaber
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33316; -- Ironforge Ram
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33321; -- Darkspear Raptor
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33324; -- Forsaken Warhorse
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33320; -- Orgrimmar Wolf
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`faction_A`=35,`faction_H`=35,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33845; -- Quel'dorei Steed
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33844; -- Sunreaver Hawkstrider
UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216,`unit_flags`=0,`speed_run`=1.5714285714286,`vehicleid`=349 WHERE `entry`=33217; -- Stormwind Steed

UPDATE `creature_template` SET
`spell1`=62544, -- Thurst
`spell2`=62575, -- Shield-Breaker
`spell3`=62960, -- Charge
`spell4`=62552, -- Defend
`spell5`=64077, -- Refresh Mount
`spell6`=62863, -- Duel
`spell7`=63034  -- Player On Tournament Mount (aura)
WHERE `vehicleid`=349;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33870,33790,33791,33792,33793,33794,33795,33796,33798,33799,33800,33842,33843);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33870,63663,13664,1,1,1,62853,0,0), -- Stabled Argent Warhorse           - Summon Tournament Argent Charger         - requires quest The Black Knight's Fall (shall not be completed nor rewarded)
(33790,62781,13690,0,0,1,62853,0,0), -- Stabled Exodar Elekk              - Summon Tournament Elekk                  - requires quest A Valiant Of The Exodar
(33791,62786,13696,0,0,1,62853,0,0), -- Stabled Silvermoon Hawkstrider    - Summon Tournament Hawkstrider            - requires quest A Valiant Of Silvermoon
(33792,62785,13694,0,0,1,62853,0,0), -- Stabled Thunder Bluff Kodo        - Summon Tournament Kodo                   - requires quest A Valiant Of Thunder Bluff
(33793,62780,13688,0,0,1,62853,0,0), -- Stabled Gnomeregan Mechanostrider - Summon Tournament Mechanostrider         - requires quest A Valiant Of Gnomeregan
(33794,62782,13689,0,0,1,62853,0,0), -- Stabled Darnassian Nightsaber     - Summon Tournament Nightsaber             - requires quest A Valiant Of Darnassus
(33795,62779,13685,0,0,1,62853,0,0), -- Stabled Ironforge Ram             - Summon Tournament Ram                    - requires quest A Valiant Of Ironforge
(33796,62784,13693,0,0,1,62853,0,0), -- Stabled Darkspear Raptor          - Summon Tournament Raptor                 - requires quest A Valiant Of Sen'jin
(33798,62787,13695,0,0,1,62853,0,0), -- Stabled Forsaken Warhorse         - Summon Tournament Warhorse               - requires quest A Valiant Of Undercity
(33799,62783,13691,0,0,1,62853,0,0), -- Stabled Orgrimmar Wolf            - Summon Tournament Wolf                   - requires quest A Valiant Of Orgrimmar
(33800,62774,13684,0,0,1,62853,0,0), -- Stabled Stormwind Steed           - Summon Tournament Charger                - requires quest A Valiant Of Stormwind
(33842,63791,13668,0,0,1,62853,0,0), -- Stabled Sunreaver Hawkstrider     - Summon Tournament Hawkstrider (Aspirant) - requires quest The Argent Tournament (H/Argent Aspiration)
(33843,63792,13667,0,0,1,62853,0,0); -- Stabled Quel'dorei Steed          - Summon Tournament Steed (Aspirant)       - requires quest The Argent Tournament (A/Argent Aspiration)
-- Note: spell 62853 (Lance Equipped) is required for all vehicles.

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `ConditionTypeOrReference`=1 AND `ConditionValue1`=64373;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- dismount in wrong zones condition
(16,0,33782,0,1,64373,0,0,0,'', 'Vehicle Argent Warhorse requires aura Armistice'),
(16,0,33318,0,1,64373,0,0,0,'', 'Vehicle Exodar Elekk requires aura Armistice'),
(16,0,33323,0,1,64373,0,0,0,'', 'Vehicle Silvermoon Hawkstrider requires aura Armistice'),
(16,0,33322,0,1,64373,0,0,0,'', 'Vehicle Thunder Bluff Kodo requires aura Armistice'),
(16,0,33317,0,1,64373,0,0,0,'', 'Vehicle Gnomeregan Mechanostrider requires aura Armistice'),
(16,0,33319,0,1,64373,0,0,0,'', 'Vehicle Darnassian Nightsaber requires aura Armistice'),
(16,0,33316,0,1,64373,0,0,0,'', 'Vehicle Ironforge Ram requires aura Armistice'),
(16,0,33321,0,1,64373,0,0,0,'', 'Vehicle Darkspear Raptor requires aura Armistice'),
(16,0,33324,0,1,64373,0,0,0,'', 'Vehicle Forsaken Warhorse requires aura Armistice'),
(16,0,33320,0,1,64373,0,0,0,'', 'Vehicle Orgrimmar Wolf requires aura Armistice'),
(16,0,33845,0,1,64373,0,0,0,'', 'Vehicle Quel''dorei Steed requires aura Armistice'),
(16,0,33844,0,1,64373,0,0,0,'', 'Vehicle Sunreaver Hawkstrider requires aura Armistice'),
(16,0,33217,0,1,64373,0,0,0,'', 'Vehicle Stormwind Steed requires aura Armistice');
-- race conditions

DELETE FROM `creature_template_addon` WHERE `entry` IN (33782,33318,33323,33322,33317,33319,33316,33321,33324,33320,33845,33844,33217);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33782,0,0,2305,0, NULL), -- Argent Warhorse
(33318,0,0,2305,0, NULL), -- Exodar Elekk
(33323,0,0,2305,0, NULL), -- Silvermoon Hawkstrider
(33322,0,0,2305,0, NULL), -- Thunder Bluff Kodo
(33317,0,0,2305,0, NULL), -- Gnomeregan Mechanostrider
(33319,0,0,2305,0, NULL), -- Darnassian Nightsaber
(33316,0,0,2305,0, NULL), -- Ironforge Ram
(33321,0,0,2305,0, NULL), -- Darkspear Raptor
(33324,0,0,2305,0, NULL), -- Forsaken Warhorse
(33320,0,0,2305,0, NULL), -- Orgrimmar Wolf
(33845,0,0,2305,0, NULL), -- Quel''dorei Steed
(33844,0,0,2305,0, NULL), -- Sunreaver Hawkstrider
(33217,0,0,2305,0, NULL); -- Stormwind Steed

UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1,`gender`=0 WHERE `modelid`=29255; -- Exodar Elekk
UPDATE `creature_model_info` SET `bounding_radius`=1.185,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=29256; -- Darnassian Nightsaber
UPDATE `creature_model_info` SET `bounding_radius`=2,`combat_reach`=0,`gender`=0 WHERE `modelid`=29258; -- Ironforge Ram
UPDATE `creature_model_info` SET `bounding_radius`=0.35,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=29261; -- Darkspear Raptor

-- Add more Tournament Stables to enable the use of all spawned vehicles
UPDATE `gameobject` SET `rotation0`=0,`rotation1`=0,`rotation2`=0,`rotation3`=0,`spawntimesecs`=300,`animprogress`=0 WHERE `id`=300008; -- equal field values for all the entries
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+6 AND `id`=300008; -- TEMP Tournament Stables
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID+0,300008,571,1,1,8569.54,670.423,547.397,5.96851,0,0,0.156691,-0.987648,300,0,1),
(@GUID+1,300008,571,1,1,8569.74,658.995,547.453,6.07846,0,0,0.102183,-0.994766,300,0,1),
(@GUID+2,300008,571,1,1,8409.89,707.879,547.314,3.5212,0,0,0.982041,-0.188668,300,0,1),
(@GUID+3,300008,571,1,1,8421.63,707.685,547.37,4.31917,0,0,0.831614,-0.555354,300,0,1),
(@GUID+4,300008,571,1,1,8488.82,920.117,547.293,5.78943,0,0,0.244376,-0.969681,300,0,1),
(@GUID+5,300008,571,1,1,8486.61,935.808,547.293,5.73289,0,0,0.271691,-0.962385,300,0,1),
(@GUID+6,300008,571,1,1,8490.55,953.448,547.293,4.61212,0,0,0.741653,-0.670784,300,0,1);
