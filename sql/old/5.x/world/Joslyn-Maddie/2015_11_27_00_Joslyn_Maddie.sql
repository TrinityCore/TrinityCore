-- Northshire fixes.

-- Blackrock spy
UPDATE `creature_template` SET `npcflag` = '0' , `dynamicflags` = '0' WHERE `entry` = '49874' ;
-- Goblin Assassin
UPDATE `creature_template` SET `npcflag` = '0' , `dynamicflags` = '0' WHERE `entry` = '50039' ;

-- add telescope to.. a guy.
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('168346', '0', '0', '0', '0', '0', '141528');

-- northshire fires
-- the bunny

DELETE FROM `creature_template` WHERE `entry` = '42940' ;
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `difficulty_entry_4`, `difficulty_entry_5`, `difficulty_entry_6`, `difficulty_entry_7`, `difficulty_entry_8`, `difficulty_entry_9`, `difficulty_entry_10`, `difficulty_entry_11`, `difficulty_entry_12`, `difficulty_entry_13`, `difficulty_entry_14`, `difficulty_entry_15`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `speed_fly`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES('42940','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','16480','0','0','0','Northshire Vineyards Fire Trigger','','','0','1','1','0','0','35','35','3','0','1','1.14286','1.14286','1','0','1','2','0','0','1','2000','2000','1','33555200','2048','2048','0','0','0','0','0','1','2','0','10','1048576','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','1','1','1','1','1','0','0','0','0','0','0','0','0','1','0','0','128','','16048');

-- the aura for fire
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES ('42940', '0', '0', '0', '0', '0', '80175');

-- Extinguishing Hope
DELETE FROM`conditions` WHERE`SourceTypeOrReferenceId`= 13 AND`SourceEntry` IN (80208);
INSERT INTO`conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 0, 80208, 0, 18, 1, 42940, 0, 0, '', 'Spray Water'); -- "Spray Water" requires target"Northshire Vineyards Fire Trigger"

-- Northshire Vineyards Fire Trigger
SET@ENTRY:= 42940;
SET@SOURCETYPE:= 0;
DELETE FROM`smart_scripts` WHERE `entryorguid`= @ENTRY AND`source_type`= @SOURCETYPE;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= @ENTRY LIMIT 1;
INSERT INTO`smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,@SOURCETYPE,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - SetEventPhase_1 on Reset"),
(@ENTRY,@SOURCETYPE,1,0,23,1,100,0,80175,0,0,0,11,80175,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Cast_Vineyard Fire"),
(@ENTRY,@SOURCETYPE,2,3,8,1,100,0,80208,0,0,0,33,42940,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Give Kill Credit on SpellHit_Spray Water"),
(@ENTRY,@SOURCETYPE,3,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - SetEventPhase_2"),
(@ENTRY,@SOURCETYPE,4,0,8,2,100,0,80208,0,1000,1000,37,80223,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Northshire Vineyards Fire Trigger - Die on SpellHit_Spray Water");

-- fix report to goldshire quest being availible from start.

UPDATE `world`.`quest_template` SET `PrevQuestId` = '26390'  WHERE `Id` = '54' ;
