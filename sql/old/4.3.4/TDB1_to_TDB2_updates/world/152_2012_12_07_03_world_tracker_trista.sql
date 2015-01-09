-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1550: Membership Benefits 9884/9885/9886/9887
-- Add special flags for monthly quests
UPDATE `quest_template` SET `SpecialFlags`=16 WHERE `Id` IN (9884,9885,9886,9887);
-- Add missing creature_quesrelation and involvedrealation that were blocking the next quests
DELETE FROM `creature_questrelation` WHERE `quest`=9884;
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(18265,9884);
DELETE FROM `creature_involvedrelation` WHERE `quest`=9884;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(18265,9884);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 1944: Fix quest Canyon Chase ID: 12145
-- Checked db and stuff from sniff, as lubomir8 said it had 2 times same credit required, following the alliance version, the fix is this:
-- UPDATE `quest_template` SET `RequiredNpcOrGo2`=0, `RequiredNpcOrGoCount2`=0 WHERE `Id`=12145; - Same values
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5971: Revenge for the Vargul
-- Closes: #4341 and #2201
-- Revenge for the Vargul (13059) quest fix by Trista
-- Thanks to Pitcrawler for helping with some sniffs and suggestions
-- Updated by nelegalno and  w1sht0l1v3
SET @Thane_Illskar := 30475;
SET @Volgur := 30483;
SET @Brita := 30484;
SET @ObjectiveCredit := 61779; -- spell, note there are 2 credits
SET @Arbiter := 30501; -- Val"kyr Arbiter
SET @TheDamned := 30523; -- Thane Illskar the Damned
SET @Script := 30475000;
SET @Script1 := 30475001;
SET @Script2 := 30501000;
SET @Summon := 55064; -- this get displayed correctly each time after an active core use it once /first time he start above ground and do all, all rest emerge from groun - core issue with loading addon data/.
SET @Judge := 55063; -- Arbiter - Judge the fallen vrykul, ascending them to Ymirjar or reducing them to vargul.
SET @Challenge := 36851;
SET @Teleport := 34427;
SET @Sword := 192558;
-- Increase "TEMP Thane Illskar be present and that he and his champions not be engaged in battle" GOs radius from 10 to 30
UPDATE `gameobject_template` SET `data1`=30 WHERE `entry` = 300235;
-- SAI Thane Illskar
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|4,`AIName`= 'SmartAI' WHERE `entry`=@Thane_Illskar;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Thane_Illskar;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid` IN (@Script,@Script1);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Thane_Illskar,0,0,1,8,0,100,0,@Challenge,0,0,0,85,@ObjectiveCredit,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - On spell hit by Sword Challenge - Invoker spell cast on self objectivecomplete credit'),
(@Thane_Illskar,0,1,0,61,0,100,0,0,0,0,0,80,@Script,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - Linked with event 0 - Start script 00'),
(@Thane_Illskar,0,2,0,38,0,100,0,0,1,0,0,80,@Script1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - On data set 0 1 - Start script 01'),
-- Script 00
(@Script,9,0,0,0,0,100,0,500,500,0,0,1,0,2000,0,0,0,0,21,60,0,0,0,0,0,0, 'Action 0 - Say text 0'),
(@Script,9,1,0,0,0,100,0,1500,1500,0,0,45,0,1,0,0,0,0,9,@Volgur,0,70,0,0,0,0, 'Action 1 - Set data 0 1 to Volgur to trigger his SAI'),
-- Script 01
(@Script1,9,0,0,0,0,100,0,500,500,0,0,1,1,2000,0,0,0,0,21,60,0,0,0,0,0,0, 'Action 0 - Say text 1'),
(@Script1,9,1,0,0,0,100,0,1500,1500,0,0,45,0,1,0,0,0,0,9,@Brita,0,70,0,0,0,0, 'Action 1 - Set data 0 1 to Brita to trigger her SAI'),
-- Continues normal events
(@Thane_Illskar,0,3,4,38,0,100,0,0,2,0,0,12,@Arbiter,2,180000,0,0,0,8,0,0,0,7851.866699,3399.678955,670.993225,3.665521, 'Thane - On Set data 0 2 - Summon Arbiter Val"kyr in air'),
(@Thane_Illskar,0,4,5,61,0,100,0,0,2,0,0,1,2,2000,0,0,0,0,21,50,0,0,0,0,0,0, 'Thane - Linked with event 3 - Say text 2'),
(@Thane_Illskar,0,5,6,61,0,100,0,0,0,0,0,1,3,2000,0,0,0,0,21,50,0,0,0,0,0,0, 'Thane - Linked with event 4 - Say text 3'),
(@Thane_Illskar,0,6,7,61,0,100,0,0,0,0,0,19,258,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - Linked with event 5 - Remove unattackable flag'),
(@Thane_Illskar,0,7,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0, 'Thane - Linked with event 6 - Attack player'),
(@Thane_Illskar,0,8,0,0,0,100,0,2000,6000,8500,15800,11,51779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Thane - IC - Cast spell Frostfire Bolt'),
(@Thane_Illskar,0,9,0,0,0,100,0,2100,8100,2000,9000,11,19816,0,0,0,0,0,0,0,0,0,0,0,0,0,'Thane - IC - Cast spell Fire Ball'),
(@Thane_Illskar,0,10,0,0,0,100,0,4200,10200,1000,10200,11,17145,0,0,0,0,0,2,0,0,0,0,0,0,0,'Thane - IC - Blast Wave'),
(@Thane_Illskar,0,11,0,0,0,100,0,4300,10000,13000,16000,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,'Thane - IC - Rain of Fire'),
(@Thane_Illskar,0,12,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@Arbiter,0,70,0,0,0,0, 'Thane - On death - Data set 0 1 on Val"kyr Arbiter'),
(@Thane_Illskar,0,13,14,38,0,100,0,0,3,0,0,11,@Summon,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - Action 0 - Cast Summon'),
(@Thane_Illskar,0,14,0,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - Linked with event 13 - Set unseen'),
(@Thane_Illskar,0,15,0,25,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane - Data set 0 0');
-- SAI for Volgur
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Volgur;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Volgur;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Volgur,0,0,1,38,0,100,0,0,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Volgur - On data set 0 1 - Remove flag immune to players'),
(@Volgur,0,1,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Volgur - Linked with event 0 - Attack player'),
(@Volgur,0,2,0,0,0,100,0,5000,5000,30000,31000,11,23262,0,0,0,0,0,2,0,0,0,0,0,0,0,'Volgur - IC - Cast spell Demoralize'),
(@Volgur,0,3,0,0,0,100,0,3000,3000,11000,12800,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,'Volgur - IC - Cast spell Chop'),
(@Volgur,0,4,0,9,0,100,0,6,30,15000,20000,11,49758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Volgur - On target in range more than 6 yards - Cast spell Charge'),
(@Volgur,0,5,0,0,0,100,0,8000,8000,15000,18000,11,49807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Volgur - IC - Cast spell Whirlwind'),
(@Volgur,0,6,0,6,0,100,0,0,0,0,0,45,0,1,0,0,0,0,9,@Thane_Illskar,0,80,0,0,0,0, 'Volgur - On death - Dataset 0 1 on Thane'),
(@Volgur,0,7,0,25,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Volgur - On Reset - Data set 0 0');
-- SAI for Brita
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Brita;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Brita;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Brita,0,0,1,38,0,100,0,0,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Brita - On data set 0 1 - Remove flag immune to players'),
(@Brita,0,1,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0, 'Brita - Linked with event 0 - Attack player'),
(@Brita,0,2,0,0,0,100,0,19500,19600,60000,60000,11,43414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Brita - IC - Cast spell Frost trap'),
(@Brita,0,3,0,0,0,100,0,2100,6100,5000,10000,11,44286,0,0,0,0,0,2,0,0,0,0,0,0,0,'Brita - IC - Cast spell Wing Clip'),
(@Brita,0,4,0,0,0,100,0,20000,21000,20000,21000,11,60932,0,0,0,0,0,2,0,0,0,0,0,0,0,'Brita - Linked with event 2 - Cast spell Disengage /Leaps backwards/'),
(@Brita,0,5,6,0,0,100,0,2500,3000,2000,2250,11,60954,1,0,0,0,0,2,0,0,0,0,0,0,0,'Brita - IC - Cast spell Aimed Shot /only out of melee range/'),
(@Brita,0,6,0,61,0,100,0,0,0,0,0,11,49712,0,0,0,0,0,2,0,0,0,0,0,0,0,'Brita - Linked with event 5 - Cast spell Shoot /only out of melee range/'),
(@Brita,0,7,0,6,0,100,0,0,0,0,0,45,0,2,0,0,0,0,9,@Thane_Illskar,0,80,0,0,0,0, 'Brita - On death - Dataset 0 2 on Thane'),
(@Brita,0,8,0,25,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Brita - On reset - Data set 0 0');
-- SAI for Arbiter
DELETE FROM `creature_template_addon` WHERE `entry`=@Arbiter;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`)
VALUES (@Arbiter, 0, 0, 33554432, 1, 0, NULL);
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@Arbiter;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@Arbiter;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@Script2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Arbiter,0,0,0,54,0,100,0,0,0,0,0,11,@Teleport,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arbiter - On spawn - Cast Ethereal Teleport on self'),
(@Arbiter,0,1,0,38,0,100,0,0,1,0,0,80,@Script2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Arbiter - On Data set 0 1 - Follow Thane Illskar'),
-- Start script 00 (Script2)
(@Script2,9,0,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,0,0,0,0,7835.128906,3389.118408,655.098083,3.915739, 'Action 0 - Move to pos (near Illskar body)'),
(@Script2,9,1,0,0,0,100,0,2250,2250,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 1 - Say text 0'),
(@Script2,9,2,0,0,0,100,0,2250,2250,0,0,1,1,2000,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 2 - Say text 1'),
(@Script2,9,3,0,0,0,100,0,0,0,0,0,11,@Judge,0,0,0,0,0,10,121005,@Thane_Illskar,0,0,0,0,0, 'Action 3 - Cast spell Arbiter Judgment /visual stuff/'),
(@Script2,9,4,0,0,0,100,0,5000,5000,0,0,45,0,3,0,0,0,0,10,121005,@Thane_Illskar,0,0,0,0,0, 'Action 4 - Data set 0 3 on Thane'),
(@Script2,9,5,0,0,0,100,0,0,0,0,0,69,1,0,0,0,0,0,0,0,0,0,7851.866699,3399.678955,670.993225,3.665521, 'Action 5 - Move to pos /starting one/'),
(@Script2,9,6,0,0,0,100,0,4000,4000,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 6 - Data set 0 0'),
(@Script2,9,7,0,0,0,100,0,0,0,0,0,78,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 7 - Reset'),
(@Script2,9,8,0,0,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 8 - Set unseen'),
(@Script2,9,9,0,0,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Action 9 - Despawn');
-- SAI for Thane Illskar the Damned and creature_template_addon data
DELETE FROM `creature_template_addon` WHERE `entry`=@TheDamned;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@TheDamned, 0, 0, 9, 1, 0, NULL);
UPDATE `creature_template` SET `unit_flags`=33024,`faction_A`=1885,`faction_H`=1885,`AIName`= 'SmartAI' WHERE `entry`=@TheDamned;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@TheDamned;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TheDamned,0,0,1,54,0,100,0,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane Illskar the Damned - On summon - Remove field byte that makes creature submurged under ground (to create emerge on surface effect)'),
(@TheDamned,0,1,2,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane Illskar the Damned - Linked with event 1 - Say text 0'),
(@TheDamned,0,2,3,61,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.9, 'Thane Illskar the Damned - Linked with event 2 - Set orientation to look towards Arbiter'),
(@TheDamned,0,3,0,61,0,100,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Thane Illskar the Damned - Linked with event 3 - Set unit field bytes for creature kneel state');
-- Add conditions for Judge
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=@Judge;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,@Judge,0,0,31,0,3,@Thane_Illskar,0,0,0,'','Judge can target only Illskar');
-- Add conditions for Challenge - player can only cast it, if no sword is already on ground /per 3 minutes/
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@Challenge;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Challenge,0,0,30,0,@Sword,30,0,1,0,'','Challenge can be used only, if no aura present from it');
-- Texts
DELETE FROM `creature_text` WHERE `entry` IN (@Thane_Illskar,@Arbiter,@TheDamned);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Thane_Illskar,0,0,'Bethod''s Sword?!! Very well, $r, I accept your challenge. But first, you must best my champions. Volgur! Squash this insect!',14,0,100,15,2000,0,'Thane'),
(@Thane_Illskar,1,0,'Brita, create a pincushion of this puny $c!',14,0,100,22,2000,0,'Thane'),
(@Thane_Illskar,2,0,'You may have defeated my champions, $c. I am something else entirely.',14,0,100,66,2000,0,'Thane'),
(@Thane_Illskar,3,0,'Pray to your gods for a quick death.',14,0,100,53,2000,0,'Thane'),
(@Arbiter,0,0,'Thane Illskar, you were challenged to honorable combat and failed.',14,0,100,0,2000,0,'Arbiter'),
(@Arbiter,1,0,'You have been found wanting and are judged accordingly. Now rise, Thane Illskar the Damned!',14,0,100,0,2000,0,'Arbiter'),
(@TheDamned,0,0,'NOOOOOOOOOOOOOOOOOO!',14,0,100,15,2000,0,'Illskar the Damned');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------
-- Issue 5928: Quests 10305, 10306, 10307 and 10182
-- Closes these issues: #3797 #1965 #1966 #1968 #1967
-- Implement [Q]{A/H} Abjurist Belmara ID: 10305 & [Q]{A/H} Conjurer Luminrath ID: 10306 &
-- [Q]{A/H} Cohlien Frostweaver: 10307 & [Q]{A/H} Battle-Mage Dathric: 10182
-- NPCs
SET @Belmara        := 19546; -- The required npc to be summoned to thank the player, give credit and despawn
SET @Luminrath      := 19580; -- The required npc to be summoned to thank the player, give credit and despawn /with cape/
SET @LCapeless      := 19544; -- /without cape/
SET @Dathric        := 19543; -- The required npc to be summoned to thank the player, give credit and despawn /with hat version/
SET @Frostweaver    := 19579; -- The required npc to be summoned to thank the player, give credit and despawn /with hat version/
SET @FHatless       := 19545; -- /without hat/
-- Involved spells and credits
SET @Book := 34140; -- The required spell that triggers the event below to summon the npc to give credit
SET @BelmaraCredit := 19547;
SET @Mantle := 34142; -- The required spell that triggers the event below to summon the npc to give credit
SET @LuminrathCredit := 19548;
SET @Hat := 34144; -- The required spell that triggers the event below to summon the npc to give credit
SET @FrostweaverCredit := 19550;
SET @Weapon := 34141; -- The required spell that triggers the event below to summon the npc to give credit
SET @DathricCredit := 19549;
-- Add SAI  and db updates for related npcs
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@Belmara,@Luminrath,@LCapeless,@Dathric,@Frostweaver,@FHatless);
UPDATE `creature_template` SET `maxlevel`=68,`minlevel`=68,`unit_class`=2 WHERE `entry`= @Luminrath;
UPDATE `creature_template` SET `maxlevel`=68,`minlevel`=68,`unit_class`=2 WHERE `entry`= @Frostweaver;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id` IN (@Belmara,@Luminrath,@LCapeless,@Dathric,@Frostweaver,@FHatless);
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Belmara,@Luminrath,@LCapeless,@Dathric,@Frostweaver,@FHatless);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Belmara,0,0,1,54,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ajdurist Belmara - On creature summoned - Switch faction to friendly'),
(@Belmara,0,1,2,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Ajdurist Belmara - Linked with event 0 - Say text 0'),
(@Belmara,0,2,0,61,0,100,0,0,0,0,0,33,@BelmaraCredit,0,0,0,0,0,23,0,0,0,0,0,0,0,'Ajdurist Belmara - Linked with event 1 - Call killcredit to player'),
(@Belmara,0,3,0,4,0,100,0,0,0,0,0,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ajdurist Belmara - On aggro - Cast to self Frost armor'),
(@Belmara,0,4,0,0,0,100,0,2000,5000,12000,22000,11,17740,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ajdurist Belmara - IC - Cast to self Mana shield'),
(@Belmara,0,5,0,0,0,100,0,0,6000,2500,8000,11,34447,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ajdurist Belmara - IC - Cast Arcane missles'),
(@Belmara,0,6,0,25,0,100,0,0,0,0,0,28,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ajdurist Belmara - On reset - Remove aura from Frost Armor'),
-- Luminrath /with cape/
(@Luminrath,0,0,0,54,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Conjurer Luminrath - On creature summoned - Say text 0'),
(@Luminrath,0,1,2,61,0,100,0,0,0,0,0,1,1,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Conjurer Luminrath - Linked with event 0 - Say text 1'),
(@Luminrath,0,2,0,61,0,100,0,0,0,0,0,33,@LuminrathCredit,0,0,0,0,0,21,20,0,0,0,0,0,0,'Conjurer Luminrath - Linked with event 1 - Call credit to player'),
-- Luminrath /without cape/
(@LCapeless,0,0,0,0,0,100,0,0,2500,1000,7500,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,'Conjurer Luminrath - IC - Cast Lightening bolt'),
(@LCapeless,0,1,0,0,0,100,0,0,5000,15000,30000,11,36110,0,0,0,0,0,2,0,0,0,0,0,0,0,'Conjurer Luminrath - IC - Cast Summon Dancing Swords'),
(@LCapeless,0,2,0,0,0,100,0,0,10000,5000,15000,11,36109,0,0,0,0,0,1,0,0,0,0,0,0,0,'Conjurer Luminrath - IC - Cast Blink'),
-- Frostweaver /without hat/
(@FHatless,0,0,0,0,0,100,0,0,1000,25000,30000,11,33245,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cohlien Frostweaver - IC - Cast Ice Barrier on self'),
(@FHatless,0,1,0,0,0,100,0,0,10000,2500,9500,11,11831,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cohlien Frostweaver - IC - Cast Frost Nova'),
(@FHatless,0,2,0,0,0,100,0,0,2500,2500,11000,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cohlien Frostweaver - IC - Cast Frostbolt'),
-- Frostweaver /with hat/
(@Frostweaver,0,0,1,54,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Cohlien Frostweaver - On creature summoned - Say text 0'),
(@Frostweaver,0,1,0,61,0,100,0,0,0,0,0,33,@FrostweaverCredit,0,0,0,0,0,21,20,0,0,0,0,0,0,'Cohlien Frostweaver - Linked with event 0 - Call credit to player'),
-- Dathric
(@Dathric,0,0,1,54,0,100,0,0,0,0,0,2,35,0,0,0,0,0,1,0,0,0,0,0,0,0,'Dathric - On creature summoned - Switch faction to friendly'),
(@Dathric,0,1,2,61,0,100,0,0,0,0,0,1,0,1000,0,0,0,0,1,0,0,0,0,0,0,0,'Dathric - Linked with event 0 - Say text 0'),
(@Dathric,0,2,0,61,0,100,0,0,0,0,0,33,@DathricCredit,0,0,0,0,0,21,20,0,0,0,0,0,0,'Dathric - Linked with event 1 - Call credit to player'),
(@Dathric,0,3,0,0,0,100,0,0,3000,3000,8000,11,36104,0,0,0,0,0,2,0,0,0,0,0,0,0,'Dathric - IC - Cast Torrent of Flames'),
(@Dathric,0,4,0,0,0,100,0,0,2500,8500,12000,11,17273,0,0,0,0,0,2,0,0,0,0,0,0,0,'Dathric - IC - Cast Pyroblast');
-- NPCs texts
DELETE FROM `creature_text` WHERE `entry` IN (@Dathric,@Frostweaver,@Luminrath,@Belmara);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Dathric,0,0,'I don''t know what I was thinking, going out without my sword. I would''ve put it on if I''d seen it here...',12,0,100,1,0,0,'Dathric gratitude'),
-- Frostweaver's text
(@Frostweaver,0,0,'Phew! There''s my lucky hat. I''ve been looking for it everywhere.',12,0,100,1,0,0,'Frostweaver gratitude'),
-- Luminrath's text
(@Luminrath,0,0,'I can''t possibly go out without my cloak. I hope it''s in here...',12,0,100,1,0,0,'Luminrath gratitude'),
(@Luminrath,1,0,'There it is! I could''ve sworn it wasn''t here last time I checked...',12,0,100,1,0,0,'Luminrath gratitude'),
-- Belmara's text
(@Belmara,0,0,'I can''t sleep without a good bedtime story. Now I''m certain to rest well.',12,0,100,1,0,0,'Belmara gratitude');
-- Gives support for send_event scripts in quest related spells
DELETE FROM `event_scripts` WHERE `id` IN (12607,12608,12609,12610);
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`x`,`y`,`z`,`o`) VALUES
(12607,0,10,@Belmara,25000,2242.230957,2389.818115,112.811760,2.941585),
(12608,0,10,@Dathric,25000,2228.003662,2314.015869,89.643219,4.822619),
(12609,0,10,@Luminrath,25000,2192.744873,2340.836182,90.353905,4.682819),
(12610,0,10,@Frostweaver,25000,2203.629883,2413.392090,109.257515,3.961037);
