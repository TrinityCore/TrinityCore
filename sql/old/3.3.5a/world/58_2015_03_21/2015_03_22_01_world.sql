SET @Cannon:= 186432;
SET @Tethyr:=23899;
SET @Marksman:=23900;
SET @Blast:=42578;
SET @Mills:=23905;
SET @Counter:=52500;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (@Tethyr, @Mills, @Marksman);
UPDATE `creature_template` SET `InhabitType`=2 WHERE `entry` IN (@Tethyr);
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@Cannon;

DELETE FROM `creature_text` WHERE `entry`=@Mills;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextID`) VALUES
(@Mills,0,0,'Marksmen, form up and take your positions!',14,0,100,0,0,0, 'Major Mills', 22447),
(@Mills,1,0,'Prepare to fire upon my command! Ready, aim...',14,0,100,0,0,0, 'Major Mills', 22448),
(@Mills,2,0,'FIRE AT WILL!',14,0,100,0,0,0, 'Major Mills', 22449),
(@Mills,3,0,'We did it! We''ve defeated Tethyr!',14,0,100,0,0,0, 'Major Mills', 22633);

DELETE FROM `waypoints` WHERE `entry`=@Tethyr;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@Tethyr,1, -3882.588379,-4670.275391,-1.823548,'Tethyr');
UPDATE `quest_template` SET `SpecialFlags`=2 WHERE `Id`=11198;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Cannon) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Marksman) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Marksman*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Mills) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Mills*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Marksman*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Marksman*100+1) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Tethyr) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Tethyr*100) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@Tethyr*100+1) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Mills,0,0,0,19,0,100,0,11198,0,0,0,80,@Mills*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Major Mills: On quest accept call main script'),
(@Mills*100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Take Down Tethyr: Remove npcflag'),
(@Mills*100,9,1,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Take Down Tethyr: Talk'),
(@Mills*100,9,2,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3904.77,-4635.09,9.62735,5.49334, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,3,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3856.59,-4622.45,9.24753,3.87856, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,4,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3917.6,-4648.53,9.32604,5.56795, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,5,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3890.48,-4620.7,9.55527,4.99383, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,6,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3865.94,-4617.2,9.26262,4.16523, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,7,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3834.8,-4645.41,9.25827,3.61152, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,8,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3826.61,-4655.32,9.21484,3.13243, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,9,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3830.76,-4673.74,9.50962,2.70832, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,10,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3843.65,-4687.59,9.6436,2.43735, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,11,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3858.49,-4703.49,9.17411,2.33525, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,12,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3851.97,-4697.24,9.36834,2.33525, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,13,0,0,0,100,0,0,0,0,0,12,@Marksman,1,900000,0,0,0,8,0,0,0,-3924.35,-4656.55,9.15409,5.80749, 'Take Down Tethyr: Summon Theramore Marksman'),
(@Mills*100,9,14,0,0,0,100,0,0,0,0,0,12,@Tethyr,1,900000,0,0,0,8,0,0,0,-3897.365479, -4750.632813, -1.719010, 1.791049, 'Take Down Tethyr: Summon Tethyr'),
(@Mills*100,9,15,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Take Down Tethyr: Talk'),
(@Mills*100,9,16,0,0,0,100,0,10000,10000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Take Down Tethyr: Talk'),
(@Mills*100,9,17,0,0,0,100,0,0,0,0,0,106,16,0,0,0,0,0,14,10824,@Cannon,0,0, 0, 0, 0, 'Take Down Tethyr: Remove Flag from GO'),
(@Mills*100,9,18,0,0,0,100,0,0,0,0,0,106,16,0,0,0,0,0,14,10227,@Cannon,0,0, 0, 0, 0, 'Take Down Tethyr: Remove Flag from GO'),
(@Mills*100,9,19,0,0,0,100,0,0,0,0,0,106,16,0,0,0,0,0,14,11186,@Cannon,0,0, 0, 0, 0, 'Take Down Tethyr: Remove Flag from GO'),
(@Tethyr,0,0,0,54,0,100,0,0,0,0,0,80,@Tethyr*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Just Summoned - Action list'),
(@Tethyr*100,9,0,0,0,0,100,0,0,0,0,0,53,0,@Tethyr,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Action list - Start wp'),
(@Tethyr*100,9,1,0,0,0,100,0,0,0,0,0,102,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Action list - REGEN HEALTH OFF'),
(@Tethyr*100,9,2,0,0,0,100,0,0,0,0,0,18,128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Action list - Add unit flag'),
(@Tethyr,0,1,0,23,0,100,1,@Counter,5,0,0,80,@Tethyr*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - On data set - ActionList'),
(@Tethyr*100+1,9,3,0,0,0,100,0,0,0,0,0,6,11198,0,0,0,0,0,18,90,0,0,0,0,0,0,'Tethyr - Action list - Quest Failed'),
(@Tethyr*100+1,9,4,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,11,@Marksman,80,0,0,0,0,0,'Tethyr - Action list - Despawn'),
(@Tethyr*100+1,9,5,0,0,0,100,0,0,0,0,0,45,0,2,0,0,0,0,10,31075,@Mills,0,0,0,0,0,'Tethyr - Action list - Set Data'),
(@Tethyr*100+1,9,6,0,0,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Action list - Despawn'),
(@Tethyr,0,1,2,40,0,100,0,1,@Tethyr,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Waypoint reached - Set home position'),
(@Tethyr,0,2,0,61,0,100,0,0,0,0,0,19,128,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Just Summoned - Remove unit flag'),
(@Tethyr,0,3,0,0,0,100,0,3000,3000,7000,7000,11,42584,0,0,0,0,0,5,0,0,0,0,0,0,0,'Tethyr - Occ - Cast'),
(@Tethyr,0,4,0,0,0,100,0,5000,5000,8000,8000,11,42574,0,0,0,0,0,5,0,0,0,0,0,0,0,'Tethyr - Occ - Cast'),
(@Tethyr,0,5,0,8,0,100,0,@Blast,0,0,0,11,36662,2,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Spell Hist - Cast'),
(@Tethyr,0,6,7,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,10,31075,@Mills,0,0,0,0,0,'Tethyr - On Death - Set Data'),
(@Tethyr,0,7,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,11,@Marksman,80,0,0,0,0,0,'Tethyr - On Death - Set Data'),
(@Mills,0,1,2,38,0,100,0,0,1,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - On data set - Add npcflag'),
(@Mills,0,2,3,61,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - On data set - talk'),
(@Mills,0,3,0,61,0,100,0,0,0,0,0,15,11198,0,0,0,0,0,18,100,0,0,0,0,0,0,'Tethyr - On data sett - Area explored'),
(@Mills,0,4,0,38,0,100,0,0,2,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - On data set - Add npcflag'),
(@Marksman,0,0,0,38,0,100,0,0,1,0,0,80,@Marksman*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - On DATA set - Action List'),
(@Marksman*100+1,9,1,0,0,0,100,0,2000,2000,0,0,11,66402,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,2,0,0,0,100,0,2000,2000,0,0,11,66400,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,3,0,0,0,100,0,2000,2000,0,0,11,66402,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,4,0,0,0,100,0,2000,2000,0,0,11,66400,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,5,0,0,0,100,0,2000,2000,0,0,11,66402,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,6,0,0,0,100,0,2000,2000,0,0,11,66400,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - cast Fireworks'),
(@Marksman*100+1,9,7,0,0,0,100,0,2000,2000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Tethyr - Just Summoned - Despawn'),
(@Marksman,0,1,0,54,0,100,1,0,0,0,0,80,@Marksman*100,2,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Just Summoned - Action list'),
(@Marksman*100,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - React passif'),
(@Marksman*100,9,1,0,0,0,100,0,0,0,0,0,18,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - Add unit flag'),
(@Marksman*100,9,2,0,0,0,100,0,16000,16000,0,0,19,131072,0,0,0,0,0,1,0,0,0,0,0,0,0,'Marksman - Action list - Remove unit flag'),
(@Marksman,0,2,0,1,0,100,0,3000,3000,2000,2000,11,42580,0,0,0,0,0,19,@Tethyr,80,0,0,0,0,0,'Tethyr - Occ - Cast'),
(@Marksman,0,3,0,0,0,100,0,3000,3000,2000,2000,11,42580,0,0,0,0,0,19,@Tethyr,80,0,0,0,0,0,'Tethyr - IC - Cast'),
(@Marksman,0,4,0,6,0,100,0,0,0,0,0,75,@Counter,0,0,0,0,0,19,@Tethyr,80,0,0,0,0,0,'Tethyr - On death - Set data1');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = @Blast;
INSERT INTO `spell_linked_spell` VALUES (@Blast, 42576, 0, 'Theramore Cannon blast');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@Blast;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, @Blast, 0, 31, 3, @Tethyr, 0, 0, '', 'Blast cannon target');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=42576;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 42576, 0, 31, 3, @Tethyr, 0, 0, '', 'Blast cannon target');
