SET @GUID := 303059;

-- Move some Earthen Ring Npc
UPDATE `creature` SET `orientation`=4.5618 WHERE `guid`=202734;
UPDATE `creature` SET `position_x`=-127.463, `position_y`=-130.762, `position_z`=-2.06541, `orientation`=4.90899 WHERE `guid`=202735;
UPDATE `creature` SET `position_x`=-141.138, `position_y`=-136.834, `position_z`=-1.59055, `orientation`=5.24279 WHERE `guid`=202736;
UPDATE `creature` SET `position_x`=-136.327, `position_y`=-132.425, `position_z`=-1.80894, `orientation`=5.06608 WHERE `guid`=202737;
UPDATE `creature` SET `position_x`=-138.054, `position_y`=-139.024, `position_z`=-1.67183, `orientation`=5.04643 WHERE `guid`=202738;
UPDATE `creature` SET `position_x`=-131.929, `position_y`=-135.194, `position_z`=-1.94897, `orientation`=4.99538 WHERE `guid`=202739;

-- Spawn Ahune + Bunnies
DELETE FROM `creature` WHERE `id` IN (25740,26190);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@GUID,'25740','547','1','1','0','0','-97.407','-238.3','-1.26481','1.43332','10','0','0','539000','0','0','0','0','0'),
(@GUID+1,'26190','547','1','1','0','0','-85.6774','-197.35','25.3171','4.4867','30','0','0','57','0','0','0','33554432','0'),
(@GUID+2,'26190','547','1','1','0','0','-121.318','-199.329','26.6837','5.17001','30','0','0','57','0','0','0','33554432','0'),
(@GUID+3,'26190','547','1','1','0','0','-105.895','-194.285','26.6837','4.98152','30','0','0','57','0','0','0','33554432','0'),
(@GUID+4,'26190','547','1','1','0','0','-96.5971','-195.524','26.6837','4.46316','30','0','0','57','0','0','0','33554432','0');

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(1,@GUID),
(1,@GUID+1),
(1,@GUID+2),
(1,@GUID+3),
(1,@GUID+4);

-- Update Templates
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82, `exp`=2, `faction_A`=14, `faction_H`=14 WHERE `entry` IN (25740,25865);
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82 WHERE `entry`=25952;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=128 WHERE `entry`=26190;
UPDATE `creature_template` SET `minlevel`=82, `maxlevel`=82, `flags_extra`=128 WHERE `entry`=25985;
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `exp`=2, `faction_A`=14, `faction_H`=14 WHERE `entry` IN (25755,25756,25757);
UPDATE `creature_template` SET `mechanic_immune_mask`=650854239 WHERE `entry` IN (25740,25865);
UPDATE `creature_template` SET `mindmg`=417, `maxdmg`=582, `dmg_multiplier`=2 WHERE `entry` IN (25756,25757);
UPDATE `creature_template` SET `mindmg`=417, `maxdmg`=582, `dmg_multiplier`=5 WHERE `entry`=25755;
UPDATE `quest_template` SET `SpecialFlags`=9 WHERE `entry`=25484;
UPDATE `gameobject_template` SET `flags`=16 WHERE `entry`=188077;

-- Frozen Core Hitbox
UPDATE `creature_model_info` SET `bounding_radius`=0.45, `combat_reach`=10 WHERE `modelid`=23447;

-- Cold Slap targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (46320,46735);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) VALUES
(13,46320,18,1,0),
(13,46735,18,1,26190);

-- Cold Slap related Script Effects
DELETE FROM `spell_scripts` WHERE `id` IN (46320,46735);
INSERT INTO `spell_scripts` (`id`, `effIndex`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
('46320','0','0','15','46145','0','0','0','0','0','0'),
('46735','0','0','15','46734','3','0','0','0','0','0');

-- Ice Chest - Loot
DELETE FROM `gameobject_loot_template` WHERE `entry`=28682;
INSERT INTO `gameobject_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
-- Cloaks
('28682','54801','0','1','1','1','1'),
('28682','54802','0','1','1','1','1'),
('28682','54803','0','1','1','1','1'),
('28682','54804','0','1','1','1','1'),
('28682','54805','0','1','1','1','1'),
-- Shards of Ahune
('28682','35723','100','1','0','1','1'),
-- Huge Snowball
('28682','35557','50','1','0','2','10'),
-- Lord of Frost Private Label
('28682','35720','10','1','0','6','6'),
-- Scorched Stone
('28682','34955','7','1','0','1','1'),
-- Frostscythe of Lord Ahune
('28682','54806','5','1','0','1','1'),
-- Formula: Enchant Weapon - Deathfrost
('28682','35498','5','1','0','1','1');

-- Pocket Full of Snow - Loot
DELETE FROM `item_loot_template` WHERE `entry`=35512;
INSERT INTO `item_loot_template` (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`) VALUES
('35512','17202','100','1','0','2','5');

-- Scriptnames
UPDATE `creature_template` SET `ScriptName`='npc_frostlord_ahune' WHERE `entry`=25740;
UPDATE `creature_template` SET `ScriptName`='npc_ahune_ice_spear' WHERE `entry`=25985;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25757,25756,25755);
UPDATE `gameobject_template` SET `ScriptName`='go_ahune_ice_stone' WHERE `entry`=187882;

-- Ahnuite Adds SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25757,25756,25755) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25757,0,0,0,25,0,100,0,0,0,0,0,75,51620,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ahunite Frostwind - Add Lightning Shield on Reset'),
(25757,0,1,0,0,0,100,0,5000,5000,7000,7000,11,46568,0,0,0,0,0,17,8,25,0,0,0,0,0, 'Ahunite Frostwind - Cast Wind Buffet'),
(25756,0,0,0,0,0,100,0,1000,5000,4000,5000,11,46406,0,0,0,0,0,5,0,0,0,0,0,0,0,'Ahunite Coldwave - Cast Bitter Blast'),
(25755,0,0,0,25,0,100,0,0,0,0,0,75,46542,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Ahunite Hailstone - Add Chilling Aura on Reset'),
(25755,0,1,0,0,0,100,0,2500,5000,6000,7000,11,2676,0x02,0,0,0,0,1,0,0,0,0,0,0,0, 'Ahunite Hailstone - Cast Pulverize');
