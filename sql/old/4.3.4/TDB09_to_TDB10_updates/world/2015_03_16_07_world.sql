-- 
SET @Infiltrator:= 38949;
SET @InfiltratorS:= 38967;
SET @Decrepit:=1547;
SET @Cursed:=1548;
SET @Zygand:=1515;
UPDATE `creature_template` SET `unit_flags`=33024 WHERE `entry`=@Infiltrator;
DELETE FROM `creature_text` WHERE `entry`=@Infiltrator;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(@Infiltrator, 0, 0, 'You deserve to lose this land, for what you people did to us! Now back off, or face the wrath of the worgen!', 12, 0, 100, 1, 0, 0, 'Infiltrator', 38896);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Zygand AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Infiltrator AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @InfiltratorS AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Decrepit AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Decrepit*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cursed AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Cursed*100 AND `source_type` = 9;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Infiltrator, @InfiltratorS, @Cursed, @Decrepit, @Zygand);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Infiltrator, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Infiltrator - Just summoned - talk'),
(@Infiltrator, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 7, 24992, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, ' Infiltrator - Just summoned - addquest'),
(@InfiltratorS, 0, 0, 0, 1, 0, 100, 0, 2000, 2000, 2000, 2000, 11, 73167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'InfiltratorS - ooc - cast'),
(@Decrepit, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 82797, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Decrepit - IC - CAST'),
(@Decrepit, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 4000, 4000, 11, 17253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Decrepit - IC - CAST'),
(@Decrepit, 0, 2, 0, 4, 0, 100, 1, 0, 0, 0, 0, 80, @Decrepit*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Decrepit - On aggro - ActionList'),
(@Decrepit*100, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 85, 73150, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Decrepit - Actionlist - cast'),
(@Cursed, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 6000, 6000, 11, 82797, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cursed - IC - CAST'),
(@Cursed, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 4000, 4000, 11, 17253, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Cursed - IC - CAST'),
(@Cursed, 0, 2, 0, 4, 0, 100, 1, 0, 0, 0, 0, 80, @Cursed*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cursed - On aggro - ActionList'),
(@Cursed*100, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 85, 73150, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Cursed - Actionlist - cast'),
(@Zygand, 0, 0, 0, 20, 0, 100, 0, 24993, 0, 0, 0, 28, 73162, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zygand - On Quest rewarded - remove aura');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`IN (3) AND `SourceEntry` IN (@Decrepit, @Cursed);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`,NegativeCondition) VALUES
(22,3,@Decrepit,0,9,24992,0,0,0,'','event require quest not taken',1),
(22,3,@Decrepit,0,8,24992,0,0,0,'','event require quest not rewarded',1),
(22,3,@Decrepit,0,28,24992,0,0,0,'','event require quest not complete',1),
(22,3,@Cursed,0,9,24992,0,0,0,'','event require quest not taken',1),
(22,3,@Cursed,0,8,24992,0,0,0,'','event require quest not rewarded',1),
(22,3,@Cursed,0,28,24992,0,0,0,'','event require quest not complete',1);
SET @CGUID := 358988; -- Guid to change
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+9;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 38967, 0, 1, 1, 2215.87, 297.094, 34.2127, 3.91798, 300, 10, 1),
(@CGUID+1, 38967, 0, 1, 1, 2212.88, 320.079, 33.6986, 4.93019, 300, 10, 1),
(@CGUID+2, 38967, 0, 1, 1, 2256.88, 257.801, 33.6125, 4.91283, 300, 10, 1),
(@CGUID+3, 38967, 0, 1, 1, 2246.67, 267.875, 33.5188, 1.01928, 300, 10, 1),
(@CGUID+4, 38967, 0, 1, 1, 2234.85, 279.328, 33.5336, 2.6798, 300, 10, 1),
(@CGUID+5, 38967, 0, 1, 1, 2220.94, 303.420, 33.6573, 4.35522, 300, 10, 1),
(@CGUID+6, 38967, 0, 1, 1, 2256.60, 260.323, 33.7722, 5.99257, 300, 10, 1),
(@CGUID+7, 38967, 0, 1, 1, 2242.65, 287.036, 33.6569, 0.227549, 300, 10, 1),
(@CGUID+8, 38967, 0, 1, 1, 2294.16, 344.134, 34.0563, 2.51015, 300, 10, 1),
(@CGUID+9, 38967, 0, 1, 1, 2250.24, 255.973, 33.5953, 6.11434, 300, 10, 1);
DELETE FROM `creature_template_addon` WHERE `entry`=@InfiltratorS;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES (@InfiltratorS, 196608, 0, "32615 81464");
DELETE FROM `spell_area` WHERE `spell`=73162 AND `area`=159;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(73162, 159, 24993, 0, 0, 1, 8, 0);
