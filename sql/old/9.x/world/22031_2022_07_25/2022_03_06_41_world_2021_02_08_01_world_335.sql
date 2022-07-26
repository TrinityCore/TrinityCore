-- Healthy Dragon Scale
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup` = 10678 AND `SourceEntry` = 13920;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(1,10678,13920,0,0,8,0,5529,0,0,0,0,0,"","Group 0: Item 'Healthy Dragon Scale' can be looted if quest 'Plagued Hatchlings' is rewarded");

UPDATE `creature_loot_template` SET `Chance` = 10 WHERE `Item` = 13920 AND `Reference` = 0;

-- Ras Frostwhisper
UPDATE `creature` SET `MovementType` = 2 WHERE `id` = 10508;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 10508);
UPDATE `creature_template_addon` SET `path_id` = 488500, `bytes2` = 4097 WHERE `entry` = 10508;
DELETE FROM `waypoint_data` WHERE `id` = 488500;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(488500,1,-22.732965,147.52971,83.90764,0,0,0,0,0,0),
(488500,2,-42.24653,147.56828,83.931465,0,0,0,0,0,0),
(488500,3,-42.204754,141.33911,83.93054,6.2831853072,90000,0,0,0,0),
(488500,4,-41.44412,134.91525,83.940956,0,0,0,0,0,0),
(488500,5,-22.852322,135.15367,83.90838,0,0,0,0,0,0),
(488500,6,-22.853083,141.41121,83.90816,0,0,0,0,0,0),
(488500,7,-25.107857,141.28365,83.91359,0.03490658476948738,75000,0,0,0,0);

-- Illusion of Jandice Barov
-- Cleave - removed, nothing in sniffs or another sources
-- Immunity - physical removed, they are immune only to AoE and for some reason not to Mind Flay (Wiki), not to all magic damage
UPDATE `creature_template` SET `spell_school_immune_mask` = 126 WHERE `entry` = 11439;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11439 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11439,0,0,0,54,0,100,0,0,0,0,0,0,11,17772,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Illusion of Jandice Barov - On Just Summoned - Cast 'Spread'"),
(11439,0,1,0,54,0,100,0,0,0,0,0,0,11,7131,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Illusion of Jandice Barov - On Just Summoned - Cast 'Illusion Passive'"),
(11439,0,2,0,32,0,100,1,1,100000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Illusion of Jandice Barov - On Damage Taken - Despawn Instant");
