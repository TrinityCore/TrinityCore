--
SET @Aura1:=44880;
SET @Flare:=24916;
SET @Grow:=44944;
SET @Visual:=44877;
SET @MiniExplosion:=44943;
SET @Unstable:=24958;
SET @Aura2:=46196;
SET @Explosion:=46225;
SET @credit:=44947;
SET @Flame:=22323;

UPDATE `creature_template` SET `unit_flags`=776, `faction`=1629, `InhabitType`=4, `AIName`='SmartAI' WHERE `entry`in (@Flare, @Unstable);
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`in (@Flame);

DELETE FROM `creature_template_addon` WHERE `entry`=@Flare;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@Flare,1,@Aura1);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Flame AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Flare AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Flare*100 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Flare*100+1 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Flare, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Just summoned - React passif'),
(@Flare, 0, 1, 0, 23, 0, 100, 1, @Grow, 8, 0, 0, 80, @Flare*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - has aura x 8 - Action list'),
(@Flare*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @MiniExplosion, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - cast'),
(@Flare*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 3, @Unstable, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - morph'),
(@Flare*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, @Aura1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - Remove aura'),
(@Flare*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Aura2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - Add aura'),
(@Flare*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 1, @Flare, 0, 0, 500, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - Start way point'),
(@Flare, 0, 2, 0, 58, 0, 100, 0, 0, 0, 0, 0, 80, @Flare*100+1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Unstable - On way point Ended - Action list'),
(@Flare*100+1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @Explosion, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - Cast'),
(@Flare*100+1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, @credit, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Unstable - Action list - Cast'),
(@Flare*100+1, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - Action list - despawn'),
(@Flare, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 11, @Visual, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flare - On data set- cast'),
(@Flame, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 5000, 5000, 11, 36247, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Flare - IC - Cast'),
(@Flame, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, @Flare, 40, 0, 0, 0, 0, 0, 'Flare - On death - Set Data');

DELETE FROM `waypoints` WHERE `entry`=@Flare;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Flare,1, 828.737000, 2509.100098, 300.700012,'Flare');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = @Visual;
INSERT INTO `spell_linked_spell` VALUES (@Visual, @Grow, 0, 'Flare Aura');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@Visual;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@Visual,0,0,31,0,3,@Flare,0,0,0,0,'','Only the Flare is a target for the spell.');
