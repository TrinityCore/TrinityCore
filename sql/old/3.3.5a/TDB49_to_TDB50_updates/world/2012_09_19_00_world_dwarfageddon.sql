-- Edit the required spell credit markers for Dwarfageddon (10/25 player) achievements
UPDATE `spell_dbc` SET `attributes`=0x00800100,`DmgMultiplier1`=0, `DmgMultiplier2`=0, `DmgMultiplier3`=0,`RangeIndex`=12 WHERE `ID`=65387; -- (SPELL_ATTR0_HIDE_IN_COMBAT_LOG, SPELL_ATTR0_CASTABLE_WHILE_DEAD)
-- Edit SAI support for Dwarfageddon (10 and 25 player) achievement /required changes since attribute castable_while_dead is not working/
SET @Defender := 33236;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Defender AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Defender,0,0,0,25,0,100,0,0,0,0,0,42,0,1,0,0,0,0,1,0,0,0,0,0,0,0,'Steelforged Defender - On reset - Set Invincibility for 1%'),
(@Defender,0,1,2,2,0,100,0,1,1,0,0,11,65387,0,0,0,0,0,1,0,0,0,0,0,0,0,'Steelforged Defender - Health Percentage (1%) - Cast spell for achievement credit'),
(@Defender,0,2,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Steelforged Defender - Linked with previous event - Die'),
(@Defender,0,3,0,0,0,100,0,0,2500,9000,12000,11,62845,0,0,0,0,0,2,0,0,0,0,0,0,0,'Steelforged Defender - IC - Hamstring'),
(@Defender,0,4,0,0,0,100,0,0,2600,13000,14000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,'Steelforged Defender - IC - Cast Sunder armor'),
(@Defender,0,5,0,0,0,100,0,500,4000,4500,9000,11,57780,0,0,0,0,0,2,0,0,0,0,0,0,0,'Steelforged Defender - IC - Cast Lightening Bolt');
-- Add conditions to prevent lag and for the sake of logic
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (65387);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,65387,0,1,31,0,4,0,0,0,0,'','Steelforged Defender kill credit for achievement can hit only players');
