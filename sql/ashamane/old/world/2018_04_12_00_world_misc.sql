-- Echo Isles --

-- Spawn some Monk Trainers

SET @CGUID:= 21014223;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1; 
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+0,63310,1,6453,4685,1,0,0,0,-1,42928,0,-1149,-5441,12.0329,1.65719,300,0,0,290,0,0,0,0,0,0,0,"",0),
(@CGUID+1,63272,0,0,0,1,0,0,0,-1,0,0,1857.09,1568.07,94.3135,6.28124,300,0,0,34506,0,0,0,0,0,0,0,"",0);

-- Fix Quests Monk Vers

UPDATE quest_template_addon SET AllowableClasses = 512 WHERE ID = 31159;
UPDATE quest_template_addon SET NextQuestID = 31163 WHERE ID = 31161;

-- Fix Troll Starting Area (Template_addon)

UPDATE quest_template_addon SET PrevQuestID = 0 AND (NextQuestID = 0) WHERE ID IN (24760,24752,26274,24766,24784,24772,24778,24640);
UPDATE quest_template_addon SET NextQuestID = 24643 WHERE ID = 24642;
UPDATE quest_template_addon SET NextQuestID = 24755 WHERE ID = 24754;
UPDATE quest_template_addon SET NextQuestID = 24763 WHERE ID = 24762;
UPDATE quest_template_addon SET NextQuestID = 24769 WHERE ID = 24768;
UPDATE quest_template_addon SET NextQuestID = 24775 WHERE ID = 24774;
UPDATE quest_template_addon SET NextQuestID = 24781 WHERE ID = 24780;
UPDATE quest_template_addon SET NextQuestID = 24787 WHERE ID = 24786;
UPDATE quest_template_addon SET NextQuestID = 26277 WHERE ID = 26276;

-- Fix Troll Starting Area (Quest_starter and ender)

DELETE FROM creature_queststarter WHERE quest IN (24760,24752,26274,24766,24784,24772,24778,24640);
DELETE FROM creature_questender WHERE quest IN (24760,24752,26274,24766,24784,24772,24778,24640);

-- Disable Deprecated Quests

DELETE FROM `disables` WHERE entry IN (24760,24752,26274,24766,24784,24772,24778,24640,24966,24967,24968,24969) AND (sourceType = 1);
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1,24760,0,'','',"Deprecated quest: The Arts of a Shaman"),
(1,24752,0,'','',"Deprecated quest: The Arts of a Mage"),
(1,26274,0,'','',"Deprecated quest: The Arts of a Warlock"),
(1,24766,0,'','',"Deprecated quest: The Arts of a Druid"),
(1,24784,0,'','',"Deprecated quest: Learnin' tha Word"),
(1,24772,0,'','',"Deprecated quest: The Arts of a Rogue"),
(1,24778,0,'','',"Deprecated quest: The Arts of a Hunter"),
(1,24640,0,'','',"Deprecated quest: The Arts of a Warrior"),
(1,24966,0,'','',"Deprecated quest: Of Light and Shadows"),
(1,24967,0,'','',"Deprecated quest: Stab!"),
(1,24968,0,'','',"Deprecated quest: Dark Deeds"),
(1,24969,0,'','',"Deprecated quest: Charging into Battle");


-- Fix Spitescale Wavethrasher 

UPDATE creature_template SET npcflag = 0, unit_flags = 32768 WHERE entry = 38300;
UPDATE creature SET unit_flags = 33024 WHERE guid IN (251623,251624,251626,251737,251632,251634);

-- Fix weird movements

UPDATE creature_template SET InhabitType = 1 WHERE entry IN (38437,38225,38423);

-- Fix Vol'jin Models

UPDATE creature SET modelid = 31232 WHERE ID IN (10540,31649,39654,38225,38966,40391,42283,52767,52924,53069);
UPDATE creature SET modelid = 47100 WHERE ID = 53069;

UPDATE creature_template SET modelid1 = 31232 WHERE entry IN (10540,31649,39654,38225,38966,40391,42283,52767,52924,53069);
UPDATE creature_template SET modelid1 = 47100 WHERE entry = 53069;
UPDATE creature_template SET modelid2 = 0 WHERE modelid2 = 10357;

-- Deathknell --

-- Fix Tombstone

DELETE FROM `page_text` WHERE ID = 3743;
insert into `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) values
(3743,"Here Lies $n",0,0,0,25996);

-- Fix Novice Elreth

UPDATE quest_template_addon SET NextQuestID = 28651 WHERE ID = 26801;
UPDATE quest_template_addon SET PrevQuestID = 26801 WHERE ID = 28651;

-- Fix Spawn Orientation

UPDATE creature SET orientation = 3.112240 WHERE id = 2113;

-- Tanaris --

-- Delete Multiplicated Spawns

DELETE FROM creature WHERE guid IN (138141,138135,138053,138047,138041,138035,93887,93851,138207,138206,138205,138204,138203,138202,138201,93893);
DELETE FROM creature WHERE id = 39696;
DELETE FROM creature WHERE id = 5808;

-- Fix some guards

UPDATE creature_template SET minlevel = 0, maxlevel = 0, HealthScalingExpansion = -1, npcflag = 1, flags_extra = 32768 WHERE entry = 9460;
UPDATE creature_template SET minlevel = 0, maxlevel = 0, HealthScalingExpansion = -1, flags_extra = 32768 WHERE entry = 68;
UPDATE creature_template SET minlevel = 0, maxlevel = 0, HealthScalingExpansion = -1 WHERE entry IN (14376,14375,15184,16222,36213,45015,45814,72501,72570,16733,11190,7980,5624,5595,4624,4262,3469,3502,3084,2041);
UPDATE creature_template SET minlevel = 5, maxlevel = 5, HealthScalingExpansion = -1 WHERE entry IN (3210,3213,3214,3211,1739,1737,1736);

-- Blasted Lands --

-- Delete Old Quest from Quest

DELETE FROM creature_queststarter WHERE quest = 26865;

-- Correct some queststarter

DELETE FROM creature_queststarter WHERE quest = 25697 AND (id = 7506);
DELETE FROM creature_queststarter WHERE quest = 25698 AND (id = 7506);
DELETE FROM creature_queststarter WHERE quest = 25699 AND (id = 7506);
DELETE FROM creature_queststarter WHERE quest = 6365 AND (id = 41140);
DELETE FROM creature_queststarter WHERE quest = 25693 AND (id = 7783);
DELETE FROM creature_queststarter WHERE quest = 25700 AND (id = 7783);
DELETE FROM creature_queststarter WHERE quest = 28865 AND (id = 41124);
DELETE FROM creature_queststarter WHERE quest = 28858 AND (id = 41124);
DELETE FROM creature_queststarter WHERE quest = 25682 AND (id = 41124);
DELETE FROM creature_queststarter WHERE quest = 28553 AND (id = 41124);
DELETE FROM creature_queststarter WHERE id IN (2119,2122,38911,2126,2124,2123);

-- Fix position

UPDATE creature SET position_x = -11466.2, position_y = -2634.2, position_z = 4.476 WHERE id = 7505;

-- Others --

-- Saurfang equipment

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (25256,25749,73716,93773,100636,89753,91195,111106,111105,110519,112590,93795,91498,109071,93791);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(25256,1,155857,0,0,0,0,0,0,0,0,25996),
(25749,1,155857,0,0,0,0,0,0,0,0,25996),
(73716,1,155857,0,0,0,0,0,0,0,0,25996),
(93773,1,155857,0,0,0,0,0,0,0,0,25996),
(100636,1,155857,0,0,0,0,0,0,0,0,25996),
(89753,1,155857,0,0,0,0,0,0,0,0,25996),
(91195,1,155857,0,0,0,0,0,0,0,0,25996),
(111106,1,155857,0,0,0,0,0,0,0,0,25996),
(111105,1,155857,0,0,0,0,0,0,0,0,25996),
(110519,1,155857,0,0,0,0,0,0,0,0,25996),
(112590,1,155857,0,0,0,0,0,0,0,0,25996),
(93795,1,155857,0,0,0,0,0,0,0,0,25996),
(91498,1,155857,0,0,0,0,0,0,0,0,25996),
(109071,1,155857,0,0,0,0,0,0,0,0,25996),
(93791,1,155857,0,0,0,0,0,0,0,0,25996);

-- Fix Gameobjects Loot

UPDATE gameobject_loot_template SET MinCount = 1 WHERE MinCount = 0;
UPDATE gameobject_loot_template SET MaxCount = 1 WHERE MaxCount = 0;
