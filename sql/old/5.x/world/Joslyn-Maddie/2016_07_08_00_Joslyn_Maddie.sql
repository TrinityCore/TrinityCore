-- Delete Double spawned Prince Liam Greymane.

DELETE FROM `creature` WHERE `guid` = '998074' ;


-- Delete Rampaging Worgen stuck behind fence.

DELETE FROM `creature` WHERE `guid` = '970560' ;

-- Update InhbitType of Worgen Runt, was in swim mode.

UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` = '35456' ;

-- Make a copy of worgen runt. 
DELETE FROM `creature_template` WHERE `entry` = '354566' ;
INSERT  INTO `creature_template`(`entry`,`difficulty_entry_1`,`difficulty_entry_2`,`difficulty_entry_3`,`difficulty_entry_4`,`difficulty_entry_5`,`difficulty_entry_6`,`difficulty_entry_7`,`difficulty_entry_8`,`difficulty_entry_9`,`difficulty_entry_10`,`difficulty_entry_11`,`difficulty_entry_12`,`difficulty_entry_13`,`difficulty_entry_14`,`difficulty_entry_15`,`KillCredit1`,`KillCredit2`,`modelid1`,`modelid2`,`modelid3`,`modelid4`,`name`,`subname`,`IconName`,`gossip_menu_id`,`minlevel`,`maxlevel`,`exp`,`exp_unk`,`faction_A`,`faction_H`,`npcflag`,`npcflag2`,`speed_walk`,`speed_run`,`speed_fly`,`scale`,`rank`,`mindmg`,`maxdmg`,`dmgschool`,`attackpower`,`dmg_multiplier`,`baseattacktime`,`rangeattacktime`,`unit_class`,`unit_flags`,`unit_flags2`,`dynamicflags`,`family`,`trainer_type`,`trainer_spell`,`trainer_class`,`trainer_race`,`minrangedmg`,`maxrangedmg`,`rangedattackpower`,`type`,`type_flags`,`type_flags2`,`lootid`,`pickpocketloot`,`skinloot`,`resistance1`,`resistance2`,`resistance3`,`resistance4`,`resistance5`,`resistance6`,`spell1`,`spell2`,`spell3`,`spell4`,`spell5`,`spell6`,`spell7`,`spell8`,`PetSpellDataId`,`VehicleId`,`mingold`,`maxgold`,`AIName`,`MovementType`,`InhabitType`,`HoverHeight`,`Health_mod`,`Mana_mod`,`Mana_mod_extra`,`Armor_mod`,`RacialLeader`,`questItem1`,`questItem2`,`questItem3`,`questItem4`,`questItem5`,`questItem6`,`movementId`,`RegenHealth`,`equipment_id`,`mechanic_immune_mask`,`flags_extra`,`ScriptName`,`WDBVerified`) VALUES 
(354566,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,36777,36778,36779,0,'Worgen Runt','','',0,3,4,0,0,2179,2179,0,0,1,1.14286,1.14286,1,0,7.6,9.5,0,57,1,2000,2000,1,32768,2048,0,0,0,0,0,0,3.8,5.7,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'SmartAI',0,0,1,1.6,1,1,1,0,0,0,0,0,0,0,0,1,0,0,0,'',1);

-- delete some original worgen runts
DELETE FROM `creature` WHERE `guid` = '970443' ;
DELETE FROM `creature` WHERE `guid` = '970442' ;

-- spawn the new Worgen Runts.
DELETE FROM `creature` WHERE `guid` = '998079' ;
DELETE FROM `creature` WHERE `guid` = '998077' ;
DELETE FROM `creature` WHERE `guid` = '998078' ;
INSERT  INTO `creature`(`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`npcflag2`,`unit_flags`,`unit_flags2`,`dynamicflags`,`isActive`,`protec_anti_doublet`) VALUES 
(998079,354566,654,4755,4762,1,65535,0,0,-1705.34,1470.29,52.2874,4.80192,300,0,0,275,0,0,0,0,0,0,0,0,NULL),
(998077,354566,654,4755,4762,1,65535,0,0,-1738.88,1432.38,52.2985,1.25193,300,0,0,275,0,0,0,0,0,0,0,0,NULL),
(998078,354566,654,4755,4762,1,65535,0,0,-1723.99,1453.41,52.2842,4.53489,300,0,0,275,0,0,0,0,0,0,0,0,NULL);

-- add fix for quest "By the Skin of his Teeth(14154)"
UPDATE `quest_template` SET `method` = '2'   WHERE `Id` = '14154' ;



-- Make slain guard(39095) non selectable.
UPDATE `creature_template` SET `unit_flags` = '33555200' , WHERE `entry` = '39095' ;




-- Fix phasemask for some "Gilneas City Guard's"
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970752' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970745' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970754' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970751' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970755' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970747' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970748' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970744' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970746' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970756' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970752' ;
UPDATE `creature` SET `phaseMask` = '4' WHERE `guid` = '970753' ;

-- Delete two Gilneas City Guards, I think it looks better without them.
DELETE FROM `creature` WHERE `guid` = '970749' ;
DELETE FROM `creature` WHERE `guid` = '970750' ;

-- fix quest "From the Shadows(14204)" should only be availible after finishing quest 14159.
UPDATE `quest_template` SET `PrevQuestId` = '14159' WHERE `Id` = '14204' ;
UPDATE `quest_template` SET `NextQuestId` = '14204' WHERE `Id` = '14159' ;

-- Increase King Genn Greymane hp, he died..
UPDATE `creature_template` SET `Health_mod` = '25' WHERE `entry` = '35550' ;


