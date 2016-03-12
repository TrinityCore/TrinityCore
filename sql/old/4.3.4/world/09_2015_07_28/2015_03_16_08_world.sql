-- 
SET @Oracle := 1544;
SET @Puddlejumper := 1543;
SET @OracleC := 39078;
SET @PuddlejumperC :=38923;
SET @Sparky :=39080;
SET @Speckle :=39079;
SET @Claston:= 38925;
SET @CGUID := 293940; -- Guid to change
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, @Sparky, 0, 1, 1, 2224.109375, 1010.946716, 44.425846, 2.491251, 300, 10, 2),
(@CGUID+1, @Speckle, 0, 1, 1, 2224.109375, 1010.946716, 44.425846, 2.491251, 300, 10, 2);
DELETE FROM `creature_template_addon` WHERE `entry` IN (@Sparky, @Speckle);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(@Sparky, @Sparky, 65536, 0, "73440"), -- seen by 73438
(@Speckle,@Speckle, 65536, 0, "73439"); -- seen by 73437
DELETE FROM `waypoint_data` WHERE `id` in (@Sparky, @Speckle);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@Sparky,1,2224.109375,1010.946716,44.425846,0,0,0,0,100,0),
(@Sparky,2,2225.722656,1013.930176,44.425846,0,0,0,0,100,0),
(@Sparky,3,2222.580566,1018.286926,44.425846,0,0,0,0,100,0),
(@Sparky,4,2220.414551,1020.660034,44.425846,0,15000,0,0,100,0),
(@Sparky,5,2221.984131,1016.882935,44.425846,0,0,0,0,100,0),
(@Sparky,6,2220.043701,1015.354858,44.425846,0,0,0,0,100,0),
(@Sparky,7,2214.370605,1020.559509,40.833614,0,0,0,0,100,0),
(@Sparky,8,2217.429688,1024.070801,40.833122,0,0,0,0,100,0),
(@Sparky,9,2223.840088,1017.623657,37.124043,0,0,0,0,100,0),
(@Sparky,10,2228.423340,1020.253601,37.115318,0,0,0,0,100,0),
(@Sparky,11,2222.105713,1012.602661,37.122444,0,20000,0,0,100,0),
(@Sparky,12,2222.545410,1019.843079,37.172771,0,0,0,0,100,0),
(@Sparky,13,2217.106201,1023.872314,40.835274,0,0,0,0,100,0),
(@Sparky,14,2214.000244,1020.534363,40.839729,0,0,0,0,100,0),
(@Sparky,15,2219.348633,1015.932861,44.425934,0,0,0,0,100,0),
(@Sparky,16,2224.586182,1016.131165,44.425934,0,0,0,0,100,0),
(@Sparky,17,2225.516846,1012.946350,44.425934,0,0,0,0,100,0),
(@Sparky,18,2223.854248,1010.827820,44.425934,0,10000,0,0,100,0),
(@Speckle,1,2224.109375,1010.946716,44.425846,0,0,0,0,100,0),
(@Speckle,2,2225.722656,1013.930176,44.425846,0,0,0,0,100,0),
(@Speckle,3,2222.580566,1018.286926,44.425846,0,0,0,0,100,0),
(@Speckle,4,2220.414551,1020.660034,44.425846,0,10000,0,0,100,0),
(@Speckle,5,2221.984131,1016.882935,44.425846,0,0,0,0,100,0),
(@Speckle,6,2220.043701,1015.354858,44.425846,0,0,0,0,100,0),
(@Speckle,7,2214.370605,1020.559509,40.833614,0,0,0,0,100,0),
(@Speckle,8,2217.429688,1024.070801,40.833122,0,0,0,0,100,0),
(@Speckle,9,2223.840088,1017.623657,37.124043,0,0,0,0,100,0),
(@Speckle,10,2228.423340,1020.253601,37.115318,0,0,0,0,100,0),
(@Speckle,11,2222.105713,1012.602661,37.122444,0,10000,0,0,100,0),
(@Speckle,12,2222.545410,1019.843079,37.172771,0,0,0,0,100,0),
(@Speckle,13,2217.106201,1023.872314,40.835274,0,0,0,0,100,0),
(@Speckle,14,2214.000244,1020.534363,40.839729,0,0,0,0,100,0),
(@Speckle,15,2219.348633,1015.932861,44.425934,0,0,0,0,100,0),
(@Speckle,16,2224.586182,1016.131165,44.425934,0,0,0,0,100,0),
(@Speckle,17,2225.516846,1012.946350,44.425934,0,0,0,0,100,0),
(@Speckle,18,2223.854248,1010.827820,44.425934,0,20000,0,0,100,0);
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Oracle AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Oracle*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Puddlejumper AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Puddlejumper*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @OracleC AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @OracleC*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @OracleC*100+1 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @PuddlejumperC AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @PuddlejumperC*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @PuddlejumperC*100+1 AND `source_type` = 9;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` in (@Claston, @Oracle, @Puddlejumper, @OracleC, @PuddlejumperC, @Sparky, @Speckle);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Oracle, 0, 0, 0, 8, 0, 100, 0, 73108, 0, 0, 0, 80, @Oracle*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oracle - On SpellHit - Actionlist'),
(@Oracle*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 73434, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Oracle - Actionlist - castSpellToSummon'),
(@Oracle*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oracle - Actionlist - Despawn'),
(@Oracle, 0, 1, 0, 23, 0, 100, 0, 12550, 0, 0, 0, 11, 12550, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Oracle - dont has aura - cast spell'),
(@Oracle, 0, 2, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 9532, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Oracle - IC - CAST'),
(@OracleC, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @OracleC*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - On Spawn - Actionlist'),
(@OracleC*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - On Script - Set React Passive'),
(@OracleC*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0,1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - On Script - Set Immune To NPC'),
(@OracleC*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @PuddlejumperC, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'OracleC - Actionlist - Credit quest'),
(@OracleC*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 82922, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - On spawn - Cast cosmetic chains'),
(@Puddlejumper, 0, 0, 0, 8, 0, 100, 0, 73108, 0, 0, 0, 80, @Puddlejumper*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Puddlejumper - On SpellHit - Actionlist'),
(@Puddlejumper*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 85, 73110, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Puddlejumper - Actionlist - castSpellToSummon'),
(@Puddlejumper*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Puddlejumper - Actionlist - Despawn'),
(@Puddlejumper, 0, 1, 0, 0, 0, 100, 0, 1000, 1000, 5000, 5000, 11, 75002, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Puddlejumper - IC - CAST'),
(@PuddlejumperC, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @PuddlejumperC*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - On Spawn - Actionlist'),
(@PuddlejumperC*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - On Script - Set React Passive'),
(@PuddlejumperC*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 512, 0, 0, 0, 0, 0,1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - On Script - Set Immune To NPC'),
(@PuddlejumperC*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, @PuddlejumperC, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - Actionlist - Credit quest'),
(@PuddlejumperC*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 85, 82922, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - On spawn - Cast cosmetic chains'),
(@OracleC, 0, 1, 0, 75, 0, 100, 1, 0, @Claston, 2, 0, 80, @OracleC*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - On Spawn - Actionlist'),
(@OracleC*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 38887, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'OracleC - Actionlist - Credit quest'),
(@OracleC*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OracleC - Actionlist - Credit quest'),
(@PuddlejumperC, 0, 1, 0, 75, 0, 100, 1, 0, @Claston, 2, 0, 80, @PuddlejumperC*100+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - On Spawn - Actionlist'),
(@PuddlejumperC*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 33, 38887, 0, 0, 0, 0, 0, 21, 10, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - Actionlist - Credit quest'),
(@PuddlejumperC*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'PuddlejumperC - Actionlist - Credit quest');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=73108;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,73108,0,0,38,1,30,2,0,0,0,0,'','the spell can be cast only at 30% of hp.'),
(17,0,73108,0,1,38,1,30,2,0,0,0,0,'','the spell can be cast only at 30% of hp.'),
(17,0,73108,0,0,31,1,3,@Oracle,0,0,0,0,'','Only Oracle are affected by the spell.'),
(17,0,73108,0,1,31,1,3,@Puddlejumper,0,0,0,0,'','Only Puddlejumper are affected by the spell.');
DELETE FROM `spell_area` WHERE `spell`=73438 AND `area`=159;
DELETE FROM `spell_area` WHERE `spell`=73437 AND `area`=159;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `racemask`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(73438, 159, 24974 , 0, 0, 1, 64, 0),
(73437, 159, 24974 , 0, 0, 1, 64, 0);
