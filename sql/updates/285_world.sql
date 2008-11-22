-- general stuff

REPLACE INTO gameobject_template VALUES (178364,1,5773,"Horde Banner","",84,0,1,0,1479,196608,180101,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (178365,1,5771,"Alliance Banner","",83,0,1,0,1479,196608,180100,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (178925,1,5651,"Alliance Banner","",83,0,1,0,1479,196608,180421,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (178940,1,5653,"Contested Banner","",83,0,1,0,1479,196608,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (178943,1,5652,"Horde Banner","",84,0,1,0,1479,196608,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (179286,1,5772,"Contested Banner","",83,0,1,0,1479,196608,180102,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (179287,1,5774,"Contested Banner","",84,0,1,0,1479,0,180102,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (179435,1,5654,"Contested Banner","",84,0,1,0,1479,196608,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180100,6,2232,"Alliance Banner Aura","",0,0,2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180101,6,1311,"Horde Banner Aura","",0,0,2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180102,6,266,"Neutral Banner Aura","",0,0,2,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180418,1,6211,"Snowfall Banner","",0,0,1,0,1479,196608,180100,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180421,6,2232,"Alliance Banner Aura, Large","",0,0,5,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180422,6,1311,"Horde Banner Aura, Large","",0,0,5,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180423,6,266,"Neutral Banner Aura, Large","",0,0,5,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"");
REPLACE INTO gameobject_template VALUES (180424,0,3751,"Alterac Valley Gate","",100,0,3.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"");

-- following is the player loot.. it takes the id 1 - be sure that i don't delete anything
REPLACE INTO `world`.`creature_loot_template` (`entry` ,`item` ,`ChanceOrQuestChance` ,`groupid` ,`mincountOrRef` ,`maxcount` ,`lootcondition` ,`condition_value1` ,`condition_value2`)
VALUES ('1', '17306', '33', '0', '5', '15',  '6', '67', '0'),
('1', '17422', '100', '0', '20', '40', '0', '0', '0'),
('1', '17423', '33', '0', '5', '15',  '6', '469', '0'),
( '1', '17502', '30', '1', '5', '10', '6', '469', '0' ),
( '1', '17503', '30', '1', '5', '10', '6', '469', '0'),
( '1', '17504', '30', '1', '5', '10', '6', '469', '0' ),
( '1', '17326', '30', '2', '5', '10', '6', '67', '0' ),
( '1', '17327', '30', '2', '5', '10', '6', '67', '0' ),
( '1', '17328', '30', '2', '5', '10', '6', '67', '0' );

-- blizzlike mobs in the mines don't have any loot (not even gold, it doesn't show the looticon if i go with my mouse over them)
-- broken after the strange new loot-table appeared (but not important)  delete from creature_loot_template where entry in (13396,13080,13098,13078,13397,13099,13081,13079,11603,11604,11605,11677,10982,13317,13096,13087,13086,13316,13097,13089,13088);
-- TODO: write own loottable



-- language

delete from trinity_string where entry>716 and entry<750;
INSERT INTO trinity_string VALUES
(717,'Alliance',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(718,'Horde',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(719,'%s was destroyed by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(720,'The %s is under attack! If left unchecked, the %s will destroy it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(721,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(722,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(723,'The %s was taken by the %s!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(724,'The %s is under attack! If left unchecked, the %s will capture it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(725,'The %s has taken the %s! Its supplies will now be used for reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(726,'Irondeep Mine',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(727,'Coldtooth Mine',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(728,'Stormpike Aid Station',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(729,'Dun Baldar South Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(730,'Dun Baldar North Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(731,'Stormpike Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(732,'Icewing Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(733,'Stonehearth Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(734,'Stonehearth Bunker',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(735,'Snowfall Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(736,'Iceblood Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(737,'Iceblood Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(738,'Tower Point',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(739,'Frostwolf Graveyard',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(740,'East Frostwolf Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(741,'West Frostwolf Tower',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(742,'Frostwolf Relief Hut',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(743,'The Battle for Alterac Valley begins in 1 minute.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(744,'The Battle for Alterac Valley begins in 30 seconds. Prepare yourselves!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(745,'The Battle for Alterac Valley has begun!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(746,'The Alliance Team is running out of reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(747,'The Horde Team is running out of reinforcements!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(748,'The Frostwolf General is Dead!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(749,'The Stormpike General is Dead!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL)
;

UPDATE trinity_string SET content_loc3='Allianz' WHERE entry=717;
UPDATE trinity_string SET content_loc3='Horde' WHERE entry=718;

UPDATE trinity_string SET content_loc3='%s wurde von der %s zerstört!' WHERE entry=719;

UPDATE trinity_string SET content_loc3='%s wird angegriffen! Wenn er unbewacht bleibt, wird die %s ihn zerstören!' WHERE entry=720;
-- Wenn _sie_ unbewacht bleibt wird allianz _sie_ TODO: don't store towers and gravenames, store complete strings with the names inside it, else i don't know how to implement this feature

UPDATE trinity_string SET content_loc3='%s wurde von der %s erobert!' WHERE entry=721;
UPDATE trinity_string SET content_loc3='%s wurde von der %s erobert!' WHERE entry=722;
UPDATE trinity_string SET content_loc3='%s wurde von der %s erobert!' WHERE entry=723;

UPDATE trinity_string SET content_loc3='%s wird angegriffen! Wenn er unbewacht bleibt, wird die %s ihn erobern!' WHERE entry=724;
-- Wenn _sie_ unbewacht bleibt ... TODO...

UPDATE trinity_string SET content_loc3='Die %s hat die %s eingenommen! Die dort befindlichen Vorräte werden zur Verstärkung eingesetzt!' WHERE entry=725;

UPDATE trinity_string SET content_loc3='Eisenschachtmine' WHERE entry=726;
UPDATE trinity_string SET content_loc3='Eisbeißermine' WHERE entry=727;
UPDATE trinity_string SET content_loc3='Das Lazarett der Sturmlanzen' WHERE entry=728;
UPDATE trinity_string SET content_loc3='Der Südbunker von Dun Baldar' WHERE entry=729;
UPDATE trinity_string SET content_loc3='Der Nordbunker von Dun Baldar' WHERE entry=730;
UPDATE trinity_string SET content_loc3='Der Friedhof der Sturmlanzen' WHERE entry=731;
UPDATE trinity_string SET content_loc3='Der Eisschwingenbunker' WHERE entry=732;
UPDATE trinity_string SET content_loc3='Der Steinbruchfriedhof' WHERE entry=733;
UPDATE trinity_string SET content_loc3='Der Steinbruchbunker' WHERE entry=734;
UPDATE trinity_string SET content_loc3='Der Schneewehenfriedhof' WHERE entry=735;
UPDATE trinity_string SET content_loc3='Der Eisblutturm' WHERE entry=736;
UPDATE trinity_string SET content_loc3='Der Eisblutfriedhof' WHERE entry=737;
UPDATE trinity_string SET content_loc3='Die Turmstellung' WHERE entry=738;
UPDATE trinity_string SET content_loc3='Der Friedhof der Frostwölfe' WHERE entry=739;
UPDATE trinity_string SET content_loc3='Der östliche Frostwolfturm' WHERE entry=740;
UPDATE trinity_string SET content_loc3='Der westliche Frostwolfturm' WHERE entry=741;
UPDATE trinity_string SET content_loc3='Die Heilerhütte der Frostwölfe' WHERE entry=742;
UPDATE trinity_string SET content_loc3='Der Kampf um das Alteractal beginnt in 1 Minute.' WHERE entry=743;
UPDATE trinity_string SET content_loc3='Der Kampf um das Alteractal beginnt in 30 Sekunden.' WHERE entry=744;
UPDATE trinity_string SET content_loc3='Der Kampf um das Alteractal hat begonnen!' WHERE entry=745;
UPDATE trinity_string SET content_loc3='Die Allianz hat nurnoch wenige Verstärkungspunkte' WHERE entry=746; -- TODO find right msg
UPDATE trinity_string SET content_loc3='Die Horde hat nurnoch wenige Verstärkungspunkte' WHERE entry=747; -- TODO same here
UPDATE trinity_string SET content_loc3='Der General der Allianz ist tot!' WHERE entry=748;
UPDATE trinity_string SET content_loc3='Der General der Horde ist tot!' WHERE entry=749;


-- CHAT_MSG_BG_SYSTEM_ALLIANCE', 'txt': '$N hat den Schneewehenfriedhof besetzt! Wenn niemand eingreift, erlangt die Allianz die Kontrolle \xc3\xbcber ihn

-- creature stats

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (11946, 0, 11894, 0, 11894, 0, 'Drek\'Thar', 'Frostwolf General', '', 72, 72, 220000, 250000, 0, 0, 0, 1214, 1214, 1, 2, 1, 3, 5000, 8000, 0, 15000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 203.77, 289.86, 100, 7, 4, 0, 11946, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 0, 1, 994, 80428891, 1, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (11947, 0, 11895, 0, 11895, 0, 'Captain Galvangar', 'Frostwolf Captain', '', 71, 71, 180000, 200000, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 4000, 4000, 0, 8000, 2000, 0, 4160, 0, 0, 0, 0, 0, 0, 172.1, 240.07, 100, 7, 4, 11947, 11947, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24055, 31418, '', 1, 3, 0, 1, 1389, 80428891, 1, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (11948, 0, 11896, 0, 11896, 0, 'Vanndar Stormpike', 'Stormpike General', '', 73, 73, 220000, 250000, 0, 0, 0, 1216, 1216, 0, 2, 1, 3, 5000, 8000, 0, 15000, 1158, 1274, 0, 0, 0, 0, 0, 0, 0, 203.77, 289.86, 100, 7, 4, 11948, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 0, 1, 0, 80428891, 1, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (11949, 0, 12823, 0, 12823, 0, 'Captain Balinda Stonehearth', 'Stormpike Captain', '', 71, 71, 180000, 200000, 38772, 38772, 0, 1216, 1216, 0, 2, 1, 3, 1000, 2000, 0, 2000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 172.1, 240.07, 100, 7, 4, 11949, 11949, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19805, 25868, '', 1, 3, 0, 1, 1364, 80428891, 1, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (13358, 0, 13390, 0, 13393, 0, 'Stormpike Bowman', '', '', 69, 70, 4500, 10000, 0, 0, 0, 1216, 1216, 0, 1.27, 1, 0, 65, 135, 0, 696, 2000, 0, 4608, 0, 0, 0, 0, 0, 0, 200, 600, 1000, 7, 0, 13358, 13358, 0, 0, 0, 0, 0, 0, 0, 22121, 0, 0, 0, 0, 260, 344, '', 0, 3, 0, 1, 8, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (13359, 0, 13398, 0, 13401, 0, 'Frostwolf Bowman', '', '', 69, 70, 4500, 10000, 0, 0, 0, 1214, 1214, 0, 1.27, 1, 0, 66, 137, 0, 712, 2000, 0, 4608, 0, 0, 0, 0, 0, 0, 200, 600, 1000, 7, 0, 13359, 13359, 0, 0, 0, 0, 0, 0, 0, 22121, 0, 0, 0, 0, 262, 347, '', 0, 3, 0, 1, 6, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14770, 0, 14797, 0, 14798, 0, 'Dun Baldar North Warmaster', '', '', 70, 70, 139780, 139780, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 5000, 0, 2175, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 14770, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14771, 0, 14798, 0, 14799, 0, 'Dun Baldar South Warmaster', '', '', 70, 70, 36600, 36600, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 14771, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14772, 0, 14798, 0, 14800, 0, 'East Frostwolf Warmaster', '', '', 70, 70, 139362, 139362, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 59.9488, 82.4296, 100, 7, 0, 14772, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6049, 7904, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14773, 0, 14797, 0, 14797, 0, 'Iceblood Warmaster', '', '', 70, 70, 141144, 141144, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14774, 0, 14800, 0, 14800, 0, 'Icewing Warmaster', '', '', 70, 70, 122300, 122300, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 14774, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6049, 7904, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14775, 0, 14798, 0, 14800, 0, 'Stonehearth Warmaster', '', '', 70, 70, 140204, 140204, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 14775, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6049, 7904, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14776, 0, 14798, 0, 14800, 0, 'Tower Point Warmaster', '', '', 70, 70, 131536, 131536, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 62.016, 85.272, 100, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (14777, 0, 14797, 0, 14798, 0, 'West Frostwolf Warmaster', '', '', 70, 70, 138920, 138920, 0, 0, 0, 1214, 1214, 0, 2, 1, 3, 3000, 6000, 0, 10000, 2000, 0, 4096, 0, 0, 0, 0, 0, 0, 59.9488, 82.4296, 100, 7, 0, 14777, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 1, 3, 0, 1, 1416, 0, 0, 'mob_eventai');

REPLACE INTO creature_template
   (`entry`, `heroic_entry`, `modelid_A`, `modelid_A2`, `modelid_H`, `modelid_H2`, `name`, `subname`, `IconName`, `minlevel`, `maxlevel`, `minhealth`, `maxhealth`, `minmana`, `maxmana`, `armor`, `faction_A`, `faction_H`, `npcflag`, `speed`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `baseattacktime`, `rangeattacktime`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `class`, `race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `PetSpellDataId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `RacialLeader`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`)
VALUES
   (25040, 0, 4606, 0, 4606, 0, 'Greater Water Elemental', '', '', 1, 1, 1, 1, 0, 0, 0, 35, 35, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 0, 1, 0, 0, 0, 'mob_eventai');

   
-- eventai

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1335801, 13358, 0, 0, 100, 1, 1000, 1000, 3000, 3000, 11, 22121, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bowman AV shoot');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1335901, 13359, 0, 0, 100, 1, 1000, 1000, 3000, 3000, 11, 22121, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Bowman AV shoot');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194901, 11949, 0, 0, 100, 1, 10000, 15000, 10000, 15000, 11, 46608, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Balinda AV AoE');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194902, 11949, 0, 0, 100, 1, 6000, 8000, 10000, 20000, 11, 38384, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Balinda AV CoC');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194903, 11949, 0, 0, 50, 1, 1000, 1000, 4000, 6000, 11, 46988, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Balinda AV fireball');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194904, 11949, 0, 0, 50, 1, 1000, 2000, 5000, 7000, 11, 46987, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Balinda AV frostbolt');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194905, 11949, 0, 0, 100, 1, 3000, 4000, 20000, 20000, 11, 45067, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Balinda AV Summon');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194801, 11948, 0, 0, 100, 1, 2000, 3000, 15000, 18000, 11, 19135, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Vanndar AV avatar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194802, 11948, 0, 0, 100, 1, 4000, 4000, 6000, 15000, 11, 15588, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Vanndar AV thunderclap');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194803, 11948, 0, 0, 100, 1, 6000, 8000, 5000, 25000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Vanndar AV cleave');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (2504001, 25040, 0, 0, 100, 1, 1000, 1000, 2000, 2000, 11, 46983, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'water element AV waterbolt');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194701, 11947, 0, 0, 100, 1, 1000, 11000, 10000, 16000, 11, 15284, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Galvanar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194702, 11947, 0, 0, 100, 1, 2000, 20000, 10000, 15000, 11, 19134, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'galvanar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194703, 11947, 0, 0, 100, 1, 1000, 12000, 6000, 20000, 11, 16856, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'galvanar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194704, 11947, 0, 0, 100, 1, 5000, 20000, 10000, 25000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'galvangar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194705, 11947, 0, 0, 100, 1, 5000, 20000, 10000, 25000, 11, 13736, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'galvangar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194601, 11946, 0, 0, 100, 1, 5000, 6000, 20000, 21000, 11, 8269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'drekthar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194602, 11946, 0, 0, 100, 1, 10000, 12000, 10000, 15000, 11, 19128, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'drekthar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194603, 11946, 0, 0, 100, 1, 1000, 20000, 8000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'drekthar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194604, 11946, 0, 0, 100, 1, 1000, 25000, 7000, 25000, 11, 13736, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'drejthar');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477001, 14770, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477002, 14770, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477003, 14770, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477101, 14771, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477102, 14771, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477103, 14771, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477201, 14772, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477202, 14772, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477203, 14772, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477301, 14773, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477302, 14773, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477303, 14773, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477401, 14774, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477402, 14774, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477403, 14774, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477501, 14775, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477502, 14775, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477503, 14775, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477601, 14776, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477602, 14776, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477603, 14776, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477701, 14777, 0, 0, 100, 1, 10, 10, 10000, 15000, 11, 22911, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477702, 14777, 0, 0, 100, 1, 3000, 5000, 10000, 15000, 11, 40504, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477703, 14777, 0, 0, 100, 1, 5000, 15000, 10000, 20000, 11, 15589, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194906, 11949, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1194804, 11948, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477004, 14770, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477104, 14771, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477204, 14772, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477304, 14773, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477404, 14774, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477504, 14775, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477604, 14776, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

REPLACE INTO eventai_scripts
   (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
   (1477704, 14777, 7, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');