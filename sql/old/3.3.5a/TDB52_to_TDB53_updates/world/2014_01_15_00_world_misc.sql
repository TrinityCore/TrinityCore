UPDATE `creature_template` SET `spell1`=66518, `spell2`=0 WHERE `entry`=34929; -- Alliance Gunship Cannon
UPDATE `creature_template` SET `spell1`=66218, `spell2`=66296, `spell8`=0, `unit_flags`=16384, `speed_walk`=2.8, `speed_run`=3.642857 WHERE `entry`=34793; -- Catapult
UPDATE `creature_template` SET `spell1`=66218, `spell2`=66296, `unit_flags`=16384, `speed_walk`=2.8, `speed_run`=3.642857 WHERE `entry`=35413; -- Catapult (1)             
UPDATE `creature_template` SET `spell1`=67440, `spell2`=67441, `unit_flags`=16384 WHERE `entry`=34775; -- Demolisher
UPDATE `creature_template` SET `spell1`=68068, `spell2`=67442, `unit_flags`=16384 WHERE `entry`=35415; -- Demolisher (1)           
UPDATE `creature_template` SET `spell1`=66456, `spell2`=67195, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384 WHERE `entry`=34802; -- Glaive Thrower (A)
UPDATE `creature_template` SET `spell1`=67034, `spell2`=67195, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384 WHERE `entry`=35273; -- Glaive Thrower (H)
UPDATE `creature_template` SET `spell1`=68826, `spell2`=69515, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384, `minlevel`=80, `maxlevel`=80, `speed_walk`=3.2, `speed_run`=1.14286 WHERE `entry`=35421; -- Glaive Thrower (1) (H)
UPDATE `creature_template` SET `spell1`=68827, `spell2`=69515, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384 WHERE `entry`=35419; -- Glaive Thrower (1) (A)
UPDATE `creature_template` SET `spell1`=66529, `spell2`=0 WHERE `entry`=34935; -- Horde Gunship Cannon
UPDATE `creature_template` SET `spell1`=67452, `spell2`=66541, `unit_flags`=16384 WHERE `entry`=34944; -- Keep Cannon -- sniff
UPDATE `creature_template` SET `spell1`=68170, `spell2`=68169, `unit_flags`=16384 WHERE `entry`=35429; -- Keep Cannon (1)          
UPDATE `creature_template` SET `spell1`=67796, `spell2`=67797, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16640 WHERE `entry`=35069; -- Siege Engine (H)
UPDATE `creature_template` SET `spell1`=67796, `spell2`=67797, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16640 WHERE `entry`=34776; -- Siege Engine (A)
UPDATE `creature_template` SET `spell1`=67816, `spell2`=69502, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16640, `speed_walk`=1.2, `speed_run`=1 WHERE `entry`=35433; -- Siege Engine (1) (H)
UPDATE `creature_template` SET `spell1`=67816, `spell2`=69502, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16640 WHERE `entry`=35431; -- Siege Engine (1) (A)

UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `spell1`=66186, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384, `VehicleId`=436 WHERE `entry`=34778; -- Flame Turret (A)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `spell1`=66186, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384 WHERE `entry`=36356; -- Flame Turret (H)
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `spell1`=68832, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384 WHERE `entry`=35417; -- Flame Turret (1) (A)
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `spell1`=68832, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384 WHERE `entry`=36358; -- Flame Turret (1) (H)

UPDATE `creature_template` SET `difficulty_entry_1`=35417 WHERE `entry`=34778; -- Flame Turret (A)
UPDATE `creature_template` SET `difficulty_entry_1`=36358 WHERE `entry`=36356; -- Flame Turret (H)

UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `spell1`=66203, `spell2`=67461, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384, `VehicleId`=436 WHERE `entry`=34777; -- Siege Turret (A)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `spell1`=66203, `spell2`=67461, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384 WHERE `entry`=36355; -- Siege Turret (H)
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `spell1`=67462, `spell2`=69505, `faction_A`=1732, `faction_H`=1732, `unit_flags`=16384 WHERE `entry`=35436; -- Siege Turret (1) (A)
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `spell1`=67462, `spell2`=69505, `faction_A`=1735, `faction_H`=1735, `unit_flags`=16384 WHERE `entry`=36357; -- Siege Turret (1) (H)

UPDATE `creature_template` SET `difficulty_entry_1`=35436 WHERE `entry`=34777; -- Siege Turret (A)
UPDATE `creature_template` SET `difficulty_entry_1`=36357 WHERE `entry`=36355; -- Siege Turret (H)

UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=1.142857 WHERE `entry` IN (34778,36356,35417,36358,34777,36355,35436,36357);

UPDATE `creature_template` SET `npcflag`=16777216, `baseattacktime`=2000, `rangeattacktime`=2000, `mechanic_immune_mask`=344276858 WHERE `entry` IN (34929,34793,35413,34775,35415,34802,35273,35421,35419,34935,34944,35429,35069,34776,35433,35431,34778,36356,35417,36358,34777,36355,35436,36357);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (34776,35069);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(34776,34778,1,1,'Siege Engine - Flame Turret',6,30000),
(34776,34778,2,1,'Siege Engine - Flame Turret',6,30000),
(34776,34777,7,1,'Siege Engine - Siege Turret',6,30000),
(35069,36356,1,1,'Siege Engine - Flame Turret',6,30000),
(35069,36356,2,1,'Siege Engine - Flame Turret',6,30000),
(35069,36355,7,1,'Siege Engine - Siege Turret',6,30000);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (34929,34793,35413,34775,35415,34802,35273,35421,35419,34935,34944,35429,35069,34776,35433,35431,34778,36356,35417,36358,34777,36355,35436,36357);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(34775,66245,1,0),
(34776,66245,1,0),
(34776,46598,1,0), -- accessorys
(34777,66245,1,0),
(34778,66245,1,0),
(34793,66245,1,0),
(34802,68503,1,0),
(34929,43671,1,0),
(34935,43671,1,0),
(34944,68458,1,0),
(35069,66245,1,0),
(35069,46598,1,0), -- accessorys
(35273,68503,1,0),
(35413,66245,1,0),
(35415,66245,1,0),
(35417,66245,1,0),
(35419,68503,1,0),
(35421,68503,1,0),
(35429,68458,1,0),
(35431,66245,1,0),
(35431,46598,1,0), -- accessorys
(35433,66245,1,0),
(35433,46598,1,0), -- accessorys
(35436,66245,1,0),
(36355,66245,1,0),
(36356,66245,1,0),
(36357,66245,1,0),
(36358,66245,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (34776,35069,35431,35433);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18,34776,66245,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,34776,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick'),
(18,35069,66245,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,35069,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick'),
(18,35431,66245,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,35431,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick'),
(18,35433,66245,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,35433,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick');

UPDATE `gameobject_template` SET `flags`=40 WHERE `entry` IN (195121,195276);


UPDATE `creature_template` SET `faction_A`=1732, `faction_H`=1732 WHERE `entry`=28312; -- Wintergrasp Siege Engine (A)
UPDATE `creature_template` SET `faction_A`=1735, `faction_H`=1735 WHERE `entry`=32627; -- Wintergrasp Siege Engine (H)
UPDATE `creature_template` SET `faction_A`=1732, `faction_H`=1732 WHERE `entry`=28319; -- Wintergrasp Siege Turret (A)
UPDATE `creature_template` SET `faction_A`=1735, `faction_H`=1735 WHERE `entry`=32629; -- Wintergrasp Siege Turret (H)

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (28312,32627,28319,32629);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(28312,60968,1,0),
(28312,46598,1,0), -- accessorys
(32627,60968,1,0),
(32627,46598,1,0), -- accessorys
(28319,60968,1,0),
(32629,60968,1,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (28312,32627,28319,32629);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18,28312,60968,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,28312,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick'),
(18,32627,60968,0,0,31,0,4,0,0,0,0,0,'','Require player for spellclick'),
(18,32627,46598,0,0,31,0,3,0,0,0,0,0,'','Require unit for spellclick');


UPDATE `creature_template` SET `faction_A`=71, `faction_H`=71, `unit_flags`=32768, `baseattacktime`=2000, `rangeattacktime`=2000 WHERE `entry`=5624; -- Undercity Guardian
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry`=25422; -- Mystical Webbing
UPDATE `creature_template` SET `faction_A`=2148, `faction_H`=2148 WHERE `entry`=27189; -- Unu'pe Spearman
