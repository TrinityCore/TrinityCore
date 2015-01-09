-- Various quest fixes in Grizzly Hills

SET @GUID :=408; -- 4.x
SET @OGUID :=122; -- 4.x

-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9426 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9615 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9426,0,0, 'Remove the Eye of the Prophets from the idol''s face.',1,1,0,0,0,0, ''),
(9615,1,0, 'I need another of your elixirs, Drakuru.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9426 AND `text_id` IN (12669,12670);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9426,12669),(9426,12670);

-- Creature Template update from sniff
UPDATE `creature_template` SET `minLevel`=70, `maxLevel`=70, `unit_flags`=33024, `AIName`='SmartAI' WHERE `entry` IN (26500);
UPDATE `creature_template` SET `npcflag`=2, `unit_flags`=33024, `AIName`='SmartAI' WHERE `entry` IN (26543,26701,26787);

UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=61 WHERE `item`=35799 AND `entry`=26447;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=58 WHERE `item`=35799 AND `entry`=26425;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE `item`=35836;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=49 WHERE `item`=36743 AND `entry`=26704;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=50 WHERE `item`=36743 AND `entry`=27554;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=51 WHERE `item`=36758 AND `entry`=26795;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=48 WHERE `item`=36758 AND `entry`=26797;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=66 WHERE `item`=38303 AND `entry`=26620;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=67 WHERE `item`=38303 AND `entry`=26639;
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=15 WHERE `item`=38303 AND `entry`=27431;

-- 4.x Same values
-- UPDATE `creature_involvedrelation` SET `id`=26543 WHERE `quest`=12007;
-- UPDATE `creature_involvedrelation` SET `id`=26701 WHERE `quest`=12802;
-- UPDATE `creature_involvedrelation` SET `id`=26787 WHERE `quest`=12068;
-- UPDATE `creature_questrelation` SET `id`=26543 WHERE `quest`=12042;
-- UPDATE `creature_questrelation` SET `id`=26701 WHERE `quest`=12068;
-- UPDATE `creature_questrelation` SET `id`=26787 WHERE `quest`=12238;

DELETE FROM `creature_text` WHERE `entry`=26500;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26500,0,0,'I''ll be waitin'' for ya, mon.',15,0,100,0,0,0,'Image of Drakuru');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47110;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9426 AND `SourceEntry`=12670;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9426 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9615 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47110,0,0,31,0,3,26498,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 01'),
(13,1,47110,0,1,31,0,3,26559,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 02'),
(13,1,47110,0,2,31,0,3,26700,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 03'),
(13,1,47110,0,3,31,0,3,26789,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 04'),
(13,1,47110,0,4,31,0,3,28015,0,0,0,'','Spell Summon Drakuru''s Image targets Drakuru''s Bunny 05'),
(14,9426,12670,0,0,2,0,35806,1,1,0,0,'','Seer of Zeb''Halak - Show different gossip if player has item Eye of the Propehts'),
(15,9426,0,0,0,9,0,12007,0,0,0,0,'','Seer of Zeb''Halak - Show gossip option if player has taken quest 12007'),
(15,9426,0,0,0,2,0,35806,1,1,1,0,'','Seer of Zeb''Halak - Show gossip option if player has not item Eye of the Propehts'),
(15,9615,1,0,0,8,0,11990,0,0,0,0,'','Drakuru - Show gossip option if player has rewarded quest 11990'),
(15,9615,1,0,0,8,0,12238,0,0,1,0,'','Drakuru - Show gossip option if player has not rewarded quest 12238'),
(15,9615,1,0,0,2,0,35797,1,1,1,0,'','Drakuru - Show gossip option if player has not item Drakuru''s Elixir');

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=188458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26498,26559,26700,26789);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26498,26500,26543,26559,26700,26701,26787,26789) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26423 AND `source_type`=0 AND `id` IN (2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=188458 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26423,0,2,3,62,0,100,0,9615,1,0,0,85,50021,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Invoker spellcast Replace Drakuru''s Elixir'),
(26423,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - Close gossip'),
(26498,0,0,0,8,0,100,0,47110,0,0,0,11,47117,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 01 - On spellhit - Spellcast Script Cast Summon Image of Drakuru'),
(26500,0,0,1,19,0,100,0,12007,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Say text'),
(26500,0,1,0,61,0,100,0,12007,0,0,0,11,47122,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru'),
(26543,0,0,1,19,0,100,0,12042,0,0,0,11,47308,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 02'),
(26559,0,0,0,8,0,100,0,47110,0,0,0,11,47149,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 02 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 02'),
(26700,0,0,0,8,0,100,0,47110,0,0,0,11,47316,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 03 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 03'),
(26701,0,0,1,19,0,100,0,12068,0,0,0,11,47403,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 03'),
(26787,0,0,1,19,0,100,0,12238,0,0,0,11,48417,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Drakuru - On quest accepted - Spellcast Strip Detect Drakuru 04'),
(26789,0,0,0,8,0,100,0,47110,0,0,0,11,47405,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru''s Bunny 04 - On spellhit - Spellcast Script Cast Summon Image of Drakuru 04'),
(188458,1,0,1,62,0,100,0,9426,0,0,0,85,47293,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seer of Zeb''Halak - On gossip option select - Invoker spellcast Create Eye of the Prophets'),
(188458,1,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Seer of Zeb''Halak - On gossip option select - Close gossip');

DELETE FROM `spell_scripts` WHERE `id` IN (47117,47149,47316,47405,50439);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(47117,0,0,15,47118,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru - Spellcast Envision Drakuru
(47149,0,0,15,47150,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 02 - Spellcast Envision Drakuru
(47316,0,0,15,47317,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 03 - Spellcast Envision Drakuru
(47405,0,0,15,47406,2,0,0,0,0,0), -- Script Cast Summon Image of Drakuru 04 - Spellcast Envision Drakuru
(50439,0,0,15,50440,2,0,0,0,0,0); -- Script Cast Summon Image of Drakuru 05 - Spellcast Envision Drakuru

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-47122,-47308,-47403,-48417);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-47122,-47118,0,'On Strip Detect Drakuru fade - Remove Envision Drakuru'),
(-47308,-47150,0,'On Strip Detect Drakuru 02 fade - Remove Envision Drakuru'),
(-47403,-47317,0,'On Strip Detect Drakuru 03 fade - Remove Envision Drakuru'),
(-48417,-47406,0,'On Strip Detect Drakuru 04 fade - Remove Envision Drakuru');

DELETE FROM `creature` WHERE `guid` in (@GUID+0,@GUID+1,@GUID+2,@GUID+3,@GUID+4,@GUID+5,@GUID+6,@GUID+7);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@GUID+0,26498,571,1,1,19595,0,3386.607,-1805.944,115.2497,3.001966,300,0,0,0,0,0,0,0,0),
(@GUID+1,26500,571,1,1,0,0,3386.272,-1805.434,115.4441,4.939282,300,0,0,0,0,0,0,0,0),
(@GUID+2,26559,571,1,1,19595,0,4243.962,-2024.805,238.2487,1.411705,300,0,0,0,0,0,0,0,0),
(@GUID+3,26543,571,1,1,0,0,4243.962,-2024.805,238.2487,1.411705,300,0,0,0,0,0,0,0,0),
(@GUID+4,26700,571,1,1,19595,0,4523.894,-3472.863,228.2441,4.695459,300,0,0,0,0,0,0,0,0),
(@GUID+5,26701,571,1,1,0,0,4523.894,-3472.863,228.2441,4.695459,300,0,0,0,0,0,0,0,0),
(@GUID+6,26787,571,1,1,0,0,4599.709,-4876.9,48.95556,0.719772,300,0,0,0,0,0,0,0,0),
(@GUID+7,26789,571,1,1,19595,0,4599.709,-4876.9,48.95556,0.719772,300,0,0,0,0,0,0,0,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (26500,26543,26701,26787);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(26500,0,0,65536,1,0,'43167 47119'),
(26543,0,0,65536,1,0,'43167 47119'),
(26701,0,0,65536,1,0,'43167 47119'),
(26787,0,0,65536,1,0,'43167 47119');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,188600,571,1,1,3980.721,-1956.352,210.6624,1.169369,0,0,0,1,120,255,1),
(@OGUID+1,188600,571,1,1,3957.188,-1908.295,209.97,0.8901166,0,0,0,1,120,255,1),
(@OGUID+2,188600,571,1,1,3964.761,-1884.524,208.2739,1.692969,0,0,0,1,120,255,1);
