-- https://www.youtube.com/watch?v=LS1elYT69Fc
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 39420;
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(39420,1,0,1,0,0,0);

UPDATE `creature_template_addon` SET `auras` = "75779" WHERE `entry` = 39420;
UPDATE `creature_template` SET `unit_flags` = 33555200, `AIName` = "SmartAI" WHERE `entry` = 39420;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 39396;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (39420,39396) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(39420,0,0,0,8,0,100,0,73082,0,0,0,0,11,73906,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"[DND] Probe Target Bunny - On Spellhit 'Deploy Radiageigatron' - Cast 'Quest Credit'"),

(39396,0,0,1,62,0,100,0,11211,0,0,0,0,11,73896,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"'Thunderflash' - On Gossip Option 0 Selected - Cast 'Mount Up'"),
(39396,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"'Thunderflash' - On Link - Close Gossip");

-- SPELL_ATTR0_CU_ALLOW_INFLIGHT_TARGET to quest credit spell
DELETE FROM `spell_custom_attr` WHERE `entry` = 73906;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(73906,262144);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 73082;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,73082,0,0,31,0,3,39420,0,0,0,0,"","Group 0: Spell 'Deploy Radiageigatron' (Effect 0) targets creature '[DND] Probe Target Bunny'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 11211;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,11211,0,0,0,9,0,25212,0,0,0,0,0,"","Group 0: Show Gossip Option 0 if player has taken quest 'Vent Horizon'");

DELETE FROM `creature` WHERE `guid` IN (130847,130848,130849,130853,130855,130906,130907,130908,130971) AND `id` = 39420;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(130847, 39420, 0, 1, 132, 1, 1, 0, 0, -5272.15, 471.593, 386.891, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(130848, 39420, 0, 1, 132, 1, 1, 0, 0, -5299.28, 554.822, 386.441, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(130849, 39420, 0, 1, 132, 1, 1, 0, 0, -5299.33, 466.906, 386.692, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(130853, 39420, 0, 1, 132, 1, 1, 0, 0, -5018.428711,545.312073,479.252350, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130855, 39420, 0, 1, 132, 1, 1, 0, 0, -5125.032715,595.284058,462.751038, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130906, 39420, 0, 1, 132, 1, 1, 0, 0, -5159.368164,630.042664,469.859955, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130907, 39420, 0, 1, 132, 1, 1, 0, 0, -5223.769531,625.570190,456.242004, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130908, 39420, 0, 1, 132, 1, 1, 0, 0, -5303.369629,663.695190,451.686462, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(130971, 39420, 0, 1, 132, 1, 1, 0, 0, -5347.992676,646.154907,447.260864, 4.171336, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `game_event_creature` WHERE `guid` IN (130847,130848,130849,130853,130855,130906,130907,130908,130971) AND `eventEntry` = 82;
INSERT INTO `game_event_creature` (`guid`,`eventEntry`) VALUES
(130847,82),
(130848,82),
(130849,82),
(130853,82),
(130855,82),
(130906,82),
(130907,82),
(130908,82),
(130971,82);
