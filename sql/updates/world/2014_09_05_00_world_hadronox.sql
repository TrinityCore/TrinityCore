-- Add support for Hadronox's event and achievement "Hadronox Denied"
-- Index of guids/entries and ids
SET @Hadronox                := 28921;
SET @Crusher                 := 28922;
SET @NoSpellNecromancer      := 29119; -- These 3 are used for initial spawns and reinforcement groups
SET @NoSpellChampion         := 29117; -- -//-
SET @NoSpellFiend            := 29118; -- -//-
SET @AttackingNecromancer    := 28925; -- Periodically sent NPCs to attack player (max 3 for each front door)
SET @AttackingChampion       := 28924; -- -//-
SET @AttackingFiend          := 29051; -- -//-
SET @LARGE_TRIGGER_AOI       := 23472; -- Triggers used at doors to summon spider trash
SET @WP_Hadronox             := 28921*10; -- Hadronox path through tunnel
SET @WEB_SIDE_DOOR           := 53185; -- Spell used to "web" spawning doors
SET @WEB_FRONT_DOORS         := 53177; -- -//-
SET @StaticCrusher           := 127402; -- Guid of static spawned Crusher
SET @GUID1                   := 127379; -- Guids of 2 guards of initial Crusher
SET @GUID2                   := 127380; -- -//-

-- Delete addon data from previous mentioned wrong spanws
DELETE FROM `creature_addon` WHERE `guid`=127401; -- hadronox

-- Assign ScriptNames to creature_templates
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_crusher' WHERE `entry` IN (28922); -- Anub'Ar Crusher
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_champion' WHERE `entry` IN (29117,28924,29096,29062); -- Anub'Ar Champions
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_necromancer' WHERE `entry` IN (29119,28925,29064,29098); -- Anub'Ar Necromancers
UPDATE `creature_template` SET `ScriptName`='npc_anub_ar_crypt_fiend' WHERE `entry` IN (29118,29051,29063,29097); -- Anub'Ar Crypt Fiends

-- Replace wrong faction
-- UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14 WHERE `entry` IN (28924,28925,29051);

-- Remove smart_ai support where there was one
DELETE FROM `smart_scripts` WHERE `creature_id` IN (@Crusher,@NoSpellChampion,@NoSpellNecromancer,@NoSpellFiend,@AttackingNecromancer,@AttackingFiend,@AttackingChampion,29062,29096,29063,29097,29064,29098);
UPDATE `creature_template` SET `AIName`='' WHERE `entry` IN (@Crusher,@NoSpellChampion,@NoSpellNecromancer,@NoSpellFiend,@AttackingNecromancer,@AttackingFiend,@AttackingChampion,29062,29096,29063,29097,29064,29098);

-- @todo: Update bounding radius and combat reach
/*
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1 WHERE `modelid` IN (29096,29062,29064,28924);
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=1.25 WHERE `modelid` IN (29097,29063,28921);
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1.5 WHERE `modelid` IN (29098,29119,28925);
UPDATE `creature_model_info` SET `bounding_radius`=1.35,`combat_reach`=1.6875 WHERE `modelid` IN (29118,29051);
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=1.25 WHERE `modelid`=29117;
UPDATE `creature_model_info` SET `bounding_radius`=0.375,`combat_reach`=7.5 WHERE `modelid`=28922;
UPDATE `creature_model_info` SET `bounding_radius`=0.85,`combat_reach`=1.275 WHERE `modelid`=29153;
*/

-- Insert into creature_text - Anub'ar Crusher and Hadronox texts
DELETE FROM `creature_text` WHERE `entry` IN (@Crusher,@Hadronox);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextID`,`TextRange`) VALUES
(@Crusher,0,0,'The gate has been breached! Quickly, divert forces to deal with these invaders!',14,0,100,1,2500,0,'Anub''ar Crusher',29473,0),
(@Crusher,1,0,'%s goes into a frenzy!',41,0,100,1,1000,0,'Anub''ar Crusher',2384,0),
(@Hadronox,0,0,'%s moves up the tunnel!',41,0,100,1,1000,0,'Hadronox',29852,3);

-- Add some needed conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (53826,53827,53828,@WEB_SIDE_DOOR,@WEB_FRONT_DOORS) AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Don't asky me why, but they hit only the very caster implicitly?!
(13,1,53826,0,0,31,0,3,23472,0,0,0,'', 'Event 0 of Anub''ar Champion can hit only trigger'),
(13,1,53826,0,0,33,0,1,0,0,0,0,'', 'Event 2 of  Anub''ar Champion caster and hit target can only be same npc'),
(13,1,53827,0,0,31,0,3,23472,0,0,0,'', 'Event 0 of  Anub''ar Necromancer can hit only trigger'),
(13,1,53827,0,0,33,0,1,0,0,0,0,'', 'Event 2 of  Anub''ar Necromancer caster and hit target can only be same npc'),
(13,1,53828,0,0,31,0,3,23472,0,0,0,'', 'Event 0 of  Anub''ar Crypt Fiend can hit only trigger'),
(13,1,53828,0,0,33,0,1,0,0,0,0,'', 'Event 2 of  Anub''ar Crypt Fiend caster and hit target can only be same npc'),
(13,1,@WEB_SIDE_DOOR,0,0,31,0,3,23472,0,0,0,'', 'Web Side Door can hit only World Trigger Large AOI'),
(13,1,@WEB_FRONT_DOORS,0,0,31,0,3,23472,0,0,0,'', 'Web Front Doors can hit only World Trigger Large AOI');

-- Insert into waypoint_data - Hadronox waypoints on the way up
DELETE FROM `waypoint_data` WHERE `id`=@WP_Hadronox;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@WP_Hadronox,1,530.406128,539.697144,678.06640,0,1,0,0,100,0),
(@WP_Hadronox,2,539.736572,533.151306,684.36322,0,1,0,0,100,0),
(@WP_Hadronox,3,554.09241,520.610229,690.13574,0,1,0,0,100,0),
(@WP_Hadronox,4,573.976929,513.072876,698.37188,0,1,0,0,100,0),
(@WP_Hadronox,5,566.644714,513.355530,698.91723,0,1,0,0,100,0),
(@WP_Hadronox,6,584.711609,509.847137,696.98925,0,1,0,0,100,0),
(@WP_Hadronox,7,588.071411,511.273407,695.12219,0,1,0,0,100,0),
(@WP_Hadronox,8,602.654419,511.136871,694.73089,0,1,0,0,100,0),
(@WP_Hadronox,9,617.250305,522.585205,695.48046,0,1,0,0,100,0),
(@WP_Hadronox,10,623.674683,536.210999,704.561,0,1,0,0,100,0),
(@WP_Hadronox,11,620.4,561.0,717.8,0,1,0,0,100,0),
(@WP_Hadronox,12,602.9,579.5,724.0,0,1,0,0,100,0),
(@WP_Hadronox,13,532.5,560.0,732.0,0,0,1,0,100,0);

-- Update orientation of the guards of initial Crusher
UPDATE `creature` SET `orientation`=4.8 WHERE `guid` IN (@GUID1,@GUID2);

-- Linked respawn - remove linked_respawn of unblizzlike spawned trash
DELETE FROM `linked_respawn` WHERE `guid` IN (127379,127380);

-- Linked respawn - link initial spawned in db first Crusher's group to first boss death in order to bound the id,
-- since Hadronox actions are permanent (and adds won't reset on even rest, also bound triggers).
DELETE FROM `linked_respawn` WHERE `guid` IN (@StaticCrusher,@GUID1,@GUID2,127376,127377,127378);
INSERT INTO `linked_respawn` (`guid`,`linkedGuid`,`linkType`) VALUES
(@GUID1,127214,0),
(@GUID2,127214,0),
(@StaticCrusher,127214,0),
(127376,127214,0), -- Large Trigger AOI
(127377,127214,0), -- -//-
(127378,127214,0); -- -//-

-- Add all 3 auras to each of the invisible triggers
DELETE FROM `creature_addon` WHERE `guid` IN (127376,127377,127378);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(127376,0,0,0,1,0, '53035 53036 53037'), -- Anub'ar Champion, Necromancer and Crypt Fiend Periodic
(127377,0,0,0,1,0, '53035 53036 53037'), -- Anub'ar Champion, Necromancer and Crypt Fiend Periodic
(127378,0,0,0,1,0, '53035 53036 53037'); -- Anub'ar Champion, Necromancer and Crypt Fiend Periodic

-- Update orientations of triggers to set webbed doors animation correctly
UPDATE `creature` SET `orientation`=2.4360 WHERE `guid`=127377;
UPDATE `creature` SET `orientation`=0.694 WHERE `guid`=127378;
UPDATE `creature` SET `orientation`=2.202 WHERE `guid`=127376;

-- Creature template addon updates - add missing auras to some trash adds
DELETE FROM `creature_template_addon` WHERE `entry` IN (@AttackingChampion,@AttackingNecromancer,@AttackingFiend,29117,29118,29119,29062,29063,29064,29096,29097,29098,@Hadronox);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
-- All these 53255 auras are used to check if event was reseted
(@AttackingChampion,0,0,0,1,0, '53255'),
(@AttackingNecromancer,0,0,0,1,0, '53255'),
(@AttackingFiend,0,0,0,1,0, '53255'),
(29117,0,0,0,1,0, ''),
(29118,0,0,0,1,0, ''),
(29119,0,0,0,1,0, ''),
(29063,0,0,0,1,0, ''),
(29097,0,0,0,1,0, ''),
(29062,0,0,0,1,0, ''),
(29096,0,0,0,1,0, ''),
(29064,0,0,0,1,0, ''),
(29098,0,0,0,1,0, ''),
(@Hadronox,0,0,0,1,0, '');

-- Update position - Adjust Hadronox spawning position
UPDATE `creature` SET `position_x`=515.5848,`position_y`=544.2007,`position_z`=673.6272,`orientation`=5.647 WHERE `guid`=127401;

-- Add spelldifficulty spells
DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (53030,53400,57731,53406,53318,53330,53322,53317,53394);
INSERT INTO `spelldifficulty_dbc`(`id`,`spellid0`,`spellid1`) VALUES
(53030,53030,59417), -- Spell Leech Poison
(53400,53400,59419), -- Spell Acid Cloud
(57731,57731,59421), -- Spell Web Grab - cast only when players are fighting boss
(53406,53406,59420), -- Spell Web Grab - cast when players aren't fighting boss
(53318,53318,59346), -- Spell Smash used by Anub'Ar Crusher
(53330,53330,59348), -- Spell Infected Wounds used by Anub'Ar Crypt Fiend
(53322,53322,59347), -- Spell Crushing Webs used by Anub'Ar Crypt Fiend
(53317,53317,59343), -- Spell Rend used by Anub'Ar Champion
(53394,53394,59344); -- Spell Pummel used by Anub'Ar Champion

-- Add spell_script names
DELETE FROM `spell_script_names` WHERE `spell_id` IN (53035,53037,53036,@WEB_FRONT_DOORS,@WEB_SIDE_DOOR,53255);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53035, 'spell_trigger_large_aoi_summon_anubar_champion_periodic'),
(53037, 'spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic'),
(53036, 'spell_trigger_large_aoi_summon_anubar_necromancer_periodic'),
(53255, 'spell_hadronox_event_check_reset'),
(@WEB_FRONT_DOORS, 'spell_hadronox_web_front_doors'),
(@WEB_SIDE_DOOR, 'spell_hadronox_web_side_door');

-- Remove http://www.wowhead.com/achievement=1297 "Hadronox Denied" from disabled
DELETE FROM `disables` WHERE `sourceType`=4 AND `entry`=4244;

-- Achievement criteria data - instance script support
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`=4244 AND `type`=11;
INSERT INTO `achievement_criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`) VALUES
(4244,11,0,0, 'achievement_hadronox_denied');

-- Add crusher reinforcement groups to summon groups
DELETE FROM `creature_summon_groups` WHERE `summonerId` IN (@LARGE_TRIGGER_AOI);
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(@LARGE_TRIGGER_AOI,0,0,@Crusher,476.3005,620.2604,771.4703,5.4,8,0),
(@LARGE_TRIGGER_AOI,0,0,@NoSpellNecromancer,476.3005,620.2604,771.4703,5.4,8,0),
(@LARGE_TRIGGER_AOI,0,0,@NoSpellChampion,476.3005,620.2604,771.4703,5.4,8,0),
(@LARGE_TRIGGER_AOI,0,1,@Crusher,584.8197,618.6154,771.4528,3.9,8,0),
(@LARGE_TRIGGER_AOI,0,1,@NoSpellNecromancer,584.8197,618.6154,771.4528,3.9,8,0),
(@LARGE_TRIGGER_AOI,0,1,@NoSpellFiend,584.8197,618.6154,771.4528,3.9,8,0);
