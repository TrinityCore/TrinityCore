-- Set by TC Devs
SET @CGUID := 3000463; -- 3 needed
SET @NPCTEXTID := 530002; -- 3 needed

-- Darkspear Training Grounds

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID,63310,1,6453,4865,'0',0,0,-1,0,0,-1149.3906,-5441.252,12.12974,0.0860126,120,0,0,1,0,0,NULL,NULL,52607), -- Zabrax <Monk Trainer>
(@CGUID+1,63309,1,6453,4865,'0',0,0,-1,0,0,-1144.7935,-5441.1426,12.064628,3.116011,120,0,0,1,0,0,NULL,NULL,52607), -- Tsu the Wanderer
(@CGUID+2,90113,1,6453,4865,'0',0,0,-1,0,0,-1310.9911,-5557.339,21.042166,5.863887,120,0,0,1,0,0,NULL,NULL,52607); -- Ardsami

-- Troll Trainer Gossip
DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+2;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 42493, 0, 0, 0, 0, 0, 0, 0, 52649), -- Voldreka <Warlock Trainer> Entry: 42618
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 37957, 0, 0, 0, 0, 0, 0, 0, 52649), -- Legati <Rogue Trainer> Entry: 38244 
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 37932, 0, 0, 0, 0, 0, 0, 0, 52649); -- Nekali <Shaman Trainer> Entry: 38242

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_nortet" WHERE `entry` = 38037;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_tunari" WHERE `entry` = 38245;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_seratha" WHERE `entry` = 38246;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_legati" WHERE `entry` = 38244;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_nekali" WHERE `entry` = 38242;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_ertezza" WHERE `entry` = 38247;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_zentabra" WHERE `entry` = 38243;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_voldreka" WHERE `entry` = 42618;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_zabrax" WHERE `entry` = 63310;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_durotar_tiki_target" WHERE `entry` = 38038;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_darkspear_jailor" WHERE `entry` = 39062;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_captive_spitescale_scout" WHERE `entry` = 38142;

UPDATE `creature` SET `StringId`="darkspear_jailor_one" WHERE `guid`=309155;
UPDATE `creature` SET `StringId`="darkspear_jailor_two" WHERE `guid`=309082;
UPDATE `creature` SET `StringId`="captive_spitescale_scout_one" WHERE `guid`=309164;
UPDATE `creature` SET `StringId`="captive_spitescale_scout_two" WHERE `guid`=309093;

DELETE FROM `creature_text` WHERE `CreatureID` IN (39062,38142);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(39062, 0, 0, 'Get in the pit and show us your stuff, $G boy:girl;.', 12, 0, 100, 1, 0, 0, 0, 0, 'Darkspear Jailor'),
(38142, 0, 0, 'They sssend you to your death, youngling.', 12, 0, 100, 0, 0, 0, 0, 0, 'Captive Spitescale Scout');

-- Pathing for Darkspear Jailor One
SET @NPC := 309155;
SET @PATH := @NPC * 100;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH, @PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`wpguid`) VALUES
(@PATH,1,-1136.5938, -5425.422, 13.735447,NULL,0,1,0),
(@PATH,2,-1135.8698, -5416.757, 13.26898,NULL,0,1,0),
(@PATH+1,1,-1137.3177, -5429.087, 13.701913,NULL,0,0,0),
(@PATH+1,2,-1143.191, -5429.9634, 13.863617, 1.85005,0,0,0);

-- Pathing for Darkspear Jailor Two
SET @NPC := 309082;
SET @PATH := @NPC * 100;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH, @PATH+1);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`wpguid`) VALUES
(@PATH,1,-1158.1224,-5524.829,12.020827,NULL,0,1,0),
(@PATH,2,-1157.1224,-5521.829,12.270827,NULL,0,1,0),
(@PATH,3,-1153.5295,-5518.6094,12.005672,NULL,0,1,0),
(@PATH+1,1,-1156.4045,-5521.3184,12.229713,NULL,0,0,0),
(@PATH+1,2,-1157.6545,-5522.8184,12.229713,NULL,0,0,0),
(@PATH+1,3,-1159.2795,-5530.028,11.953753, 6.19592,0,0,0);

-- The Rise of the Darkspear "Monk"
DELETE FROM `creature_queststarter` WHERE `id`=37951 AND `quest` = 31159;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(37951, 31159, 52607);

-- Fix Monk quest chain
DELETE FROM `quest_template_addon` WHERE `ID` IN (31159,31158,31160,31161,31163);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`) VALUES
(31159,512,0,0),
(31158,512,31159,0),
(31160,512,31158,0),
(31161,512,31160,0),
(31163,512,31161,0);

DELETE FROM `creature_text` WHERE `CreatureID` IN (38037,38245,38246,38244,38242,38247,38243,42618,63310);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
-- Nortet "Warrior Trainer"
(38037, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Nortet'),
(38037, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Nortet'),
-- Tunari "Priest Trainer"
(38245, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Tunari'),
(38245, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Tunari'),
-- Seratha "Mage Trainer"
(38246, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Seratha'),
(38246, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Seratha'),
-- Legati "Rogue Trainer"
(38244, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Legati'),
(38244, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Legati'),
-- Nekali "Shaman Trainer"
(38242, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Nekali'),
(38242, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Nekali'),
-- Ertezza "Hunter Trainer"
(38247, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Ertezza'),
(38247, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Ertezza'),
-- Zentabra "Druid Trainer"
(38243, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Zentabra'),
(38243, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Zentabra'),
-- Voldreka "Warlock Trainer"
(42618, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Voldreka'),
(42618, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Voldreka'),
-- Zabrax "Monk Trainer"
(63310, 0, 0, 'Not bad, $n. Not bad.', 12, 0, 100, 0, 0, 0, 37928, 0, 'Zabrax'),
(63310, 1, 0, 'Well done, $n!', 12, 0, 100, 0, 0, 0, 37898, 0, 'Zabrax');

-- Warrior Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_warrior" WHERE `ID` = 24639;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_warrior" WHERE `ID` = 24642;
-- Priest Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_priest" WHERE `ID` = 24783;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_priest" WHERE `ID` = 24786;
-- Mage Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_mage" WHERE `ID` = 24751;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_mage" WHERE `ID` = 24754;
-- Rogue Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_rogue" WHERE `ID` = 24771;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_rogue" WHERE `ID` = 24774;
-- Shaman Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_shaman" WHERE `ID` = 24759;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_shaman" WHERE `ID` = 24762;
-- Hunter Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_hunter" WHERE `ID` = 24777;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_hunter" WHERE `ID` = 24780;
-- Druid Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_druid" WHERE `ID` = 24765;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_druid" WHERE `ID` = 24768;
-- Warlock Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_warlock" WHERE `ID` = 26273;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_warlock" WHERE `ID` = 26276;
-- Monk Quest
UPDATE `quest_template_addon` SET `ScriptName` = "quest_the_basics_hitting_things_monk" WHERE `ID` = 31158;
UPDATE `quest_template_addon` SET `ScriptName` = "quest_proving_pit_monk" WHERE `ID` = 31161;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (91404);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(91404,'spell_durotar_summon_zuni');

-- Old spell has been replaced
DELETE FROM `playercreateinfo_cast_spell` WHERE spell IN (71033,91404);
INSERT INTO `playercreateinfo_cast_spell` (`raceMask`,`classMask`,`createMode`,`spell`,`note`) VALUES
(128,2015,0,91404,"Troll - Summon Zuni (Lvl 1)");

-- Fix Warrior questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24642 WHERE `ID`=24643;
-- Fix Priest questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24786 WHERE `ID`=24787;
DELETE FROM `creature_queststarter` WHERE `quest` = 24784;
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` = 24784;
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`comment`) VALUES
(1,24784,0,"Deprecated quest: Learnin' tha Word");
-- Fix mage questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24754 WHERE `ID`=24755;
-- Fix rogue questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24774 WHERE `ID`=24775;
-- Fix shaman questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24762 WHERE `ID`=24763;
-- Fix Hunter questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24780 WHERE `ID`=24781;
-- Fix Druid questline
UPDATE `quest_template_addon` SET `PrevQuestID`=24768 WHERE `ID`=24769;
-- Fix Warlock questline
UPDATE `quest_template_addon` SET `PrevQuestID`=26276 WHERE `ID`=26277;

-- Condition for Gossip menu option allow Monk to do Proving Pit quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10974 AND `ElseGroup`=9;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10974, 1, 0, 9, 8, 0, 31161, 0, 0, 1, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has not been rewarded.'),
(15, 10974, 1, 0, 9, 47, 0, 31161, 10, 0, 0, 0, 0, '', 'Show gossip menu 10974 option id 1 if quest Proving Pit has been taken.');

-- Add missing gossip menu for Jailor
DELETE FROM `gossip_menu` WHERE `MenuID`=10973;
INSERT INTO `gossip_menu` (`MenuID`,`TextID`,`VerifiedBuild`) VALUES
(10973,15252,50000);

-- Prevent player from stopping Jailor movement when opening gossip
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 39062;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(39062,1,0,0,0,0,0,0);

-- Nortet Warrior trainer Entry: 38037
DELETE FROM `gossip_menu` WHERE `MenuID`=14182;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14182, 15257, 52649),
(14182, 15265, 52649);

-- Condition for source Gossip menu condition Warrior trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14182;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14182, 15257, 0, 0, 15, 0, 1, 0, 0, 0, 0, 0, '', 'Show gossip menu 14182 text id 15257 if player is a Warrior.'),
(14, 14182, 15265, 0, 0, 15, 0, 1, 0, 0, 1, 0, 0, '', 'Show gossip menu 14182 text id 15265 if player is not a Warrior.');

-- Seratha Mage trainer Entry: 38246
UPDATE `creature_template_gossip` SET `MenuID`=14187,`VerifiedBuild`=52649 WHERE `CreatureID`=38246;
DELETE FROM `gossip_menu` WHERE `MenuID`=14187;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14187, 15275, 52649),
(14187, 15265, 52649);

-- Condition for source Gossip menu condition Mage trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14187;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14187, 15275, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip menu 14187 text id 15275 if player is a Mage.'),
(14, 14187, 15265, 0, 0, 15, 0, 128, 0, 0, 1, 0, 0, '', 'Show gossip menu 14187 text id 15265 if player is not a Mage.');

-- Mage trainer
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (20690,14187);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(20690, 47058, 1, 0, 'I would like to unlearn Arcane Momentum and Blink the direction I am facing.', 0, 0, 0, 0, 0, NULL, 0, 0, 'Are you sure you would like me to remove the knowledge of Arcane Momentum from your memory?', 0, NULL, NULL, 52649),
(20690, 47057, 0, 0, 'I would like to learn the Arcane Momentum technique and be able to Blink in the direction I am moving.', 0, 0, 0, 0, 0, NULL,0, 0, 'Are you sure you would like to learn this new technique?', 0, NULL, NULL, 52649),
(14187, 31252, 9, 0, 'I want to talk about the Arcane Momentum technique.', 0, 0, 0, 20690, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 52649);

-- Condition for source Gossip menu option condition Mage trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (14187,20690);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 14187, 9, 0, 0, 15, 0, 128, 0, 0, 0, 0, 0, '', 'Show gossip menu 14187 option id 9 if player is a Mage.'),
(15, 20690, 0, 0, 0, 25, 0, 56384, 0, 0, 1, 0, 0, '', 'Show gossip menu 20690 option id 0 if target does not have aura Arcane Momentum (effect 0).'),
(15, 20690, 1, 0, 0, 25, 0, 56384, 0, 0, 0, 0, 0, '', 'Show gossip menu 20690 option id 1 if target has aura Arcane Momentum (effect 0).');

-- Add gossip for Zen'tabra <Druid Trainer> Entry: 38243
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=38243;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(38243,14184,52649);

-- Zen'tabra <Druid Trainer> Entry: 38243
DELETE FROM `gossip_menu` WHERE `MenuID`=14184;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14184, 15272, 52649),
(14184, 15265, 52649);

-- Condition for source Gossip menu condition Druid Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14184;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14184, 15272, 0, 0, 15, 0, 1024, 0, 0, 0, 0, 0, '', 'Show gossip menu 14184 text id 15272 if player is a Druid.'),
(14, 14184, 15265, 0, 0, 15, 0, 1024, 0, 0, 1, 0, 0, '', 'Show gossip menu 14184 text id 15265 if player is not a Druid.');

-- Add gossip for Zabrax <Monk Trainer> Entry: 63310
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=63310;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(63310,13865,52649);

-- Zabrax <Monk Trainer> Entry: 63310
DELETE FROM `gossip_menu` WHERE `MenuID`=13865;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(13865, 20034, 52649);

-- Add gossip for Ortezza <Hunter Trainer> Entry: 38247
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=38247;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(38247,14188,52649);

-- Ortezza <Hunter Trainer> Entry: 38247
DELETE FROM `gossip_menu` WHERE `MenuID`=14188;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14188, 15276, 52649),
(14188, 15265, 52649);

-- Condition for source Gossip menu condition Hunter Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14188;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14188, 15276, 0, 0, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Show gossip menu 14188 text id 15276 if player is a Hunter.'),
(14, 14188, 15265, 0, 0, 15, 0, 4, 0, 0, 1, 0, 0, '', 'Show gossip menu 14188 text id 15265 if player is not a Hunter.');

-- Add gossip for Tunari <Priest Trainer> Entry: 38245
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=38245;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(38245,14186,52649);

-- Tunari <Priest Trainer> Entry: 38245
DELETE FROM `gossip_menu` WHERE `MenuID`=14186;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14186, 15274, 52649),
(14186, 15265, 52649);

-- Condition for source Gossip menu condition Priest Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14186;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14186, 15274, 0, 0, 15, 0, 16, 0, 0, 0, 0, 0, '', 'Show gossip menu 14186 text id 15274 if player is a Priest.'),
(14, 14186, 15265, 0, 0, 15, 0, 16, 0, 0, 1, 0, 0, '', 'Show gossip menu 14186 text id 15265 if player is not a Priest.');

-- Nekali <Shaman Trainer> Entry: 38242
DELETE FROM `gossip_menu` WHERE `MenuID`=14183;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14183, @NPCTEXTID+2, 52649),
(14183, 15265, 52649);

-- Condition for source Gossip menu condition Shaman Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14183;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14183, @NPCTEXTID+2, 0, 0, 15, 0, 64, 0, 0, 0, 0, 0, '', 'Show gossip menu 14183 text id @NPCTEXTID+2 if player is a Shaman.'),
(14, 14183, 15265, 0, 0, 15, 0, 64, 0, 0, 1, 0, 0, '', 'Show gossip menu 14183 text id 15265 if player is not a Shaman.');

-- Add gossip for Legati <Rogue Trainer> Entry: 38244
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=38244;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(38244,14185,52649);

-- Legati <Rogue Trainer> Entry: 38244
DELETE FROM `gossip_menu` WHERE `MenuID`=14185;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14185, @NPCTEXTID+1, 52649),
(14185, 15265, 52649);

-- Condition for source Gossip menu condition Rogue Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14185;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14185, @NPCTEXTID+1, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, '', 'Show gossip menu 14185 text id XXXXX if player is a Rogue.'),
(14, 14185, 15265, 0, 0, 15, 0, 8, 0, 0, 1, 0, 0, '', 'Show gossip menu 14185 text id 15265 if player is not a Rogue.');

-- Add gossip for Voldreka <Warlock Trainer> Entry: 42618
DELETE FROM `creature_template_gossip` WHERE `CreatureID`=42618;
INSERT INTO `creature_template_gossip` (`CreatureID`,`MenuID`,`VerifiedBuild`) VALUES
(42618,14196,52649);

-- Voldreka <Warlock Trainer> Entry: 42618
DELETE FROM `gossip_menu` WHERE `MenuID`=14196;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14196, @NPCTEXTID+0, 52649),
(14196, 15265, 52649);

-- Condition for source Gossip menu condition Warlock Trainer
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=14196;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 14196, @NPCTEXTID+0, 0, 0, 15, 0, 256, 0, 0, 0, 0, 0, '', 'Show gossip menu 14196 text id XXXXX if player is a Warlock.'),
(14, 14196, 15265, 0, 0, 15, 0, 256, 0, 0, 1, 0, 0, '', 'Show gossip menu 14196 text id 15265 if player is not a Warlock.');
