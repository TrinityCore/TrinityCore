-- Rewrite [Qs] Gruesome, But Necessary /11257-H,11246-A /using some of old event data, fix visual bugs, death states, adds conditions
-- Rewrite scripts from EAI to SAI to add spells to the Winterskorn creatures, add some that are missing at all, add texts, fix dynamicflags, remove pointless phasing that created some bugs
SET @Tribesman:= 23661;
SET @Woodsman := 23662;
SET @Shield_Maiden := 23663;
SET @Warrior := 23664;
SET @Raider := 23665;
SET @Berserker := 23666;
SET @Rune_Seer := 23667;
SET @Rune_Caster := 23668;
SET @Oracle := 23669;
SET @Elder := 23670;
SET @Dismember := 43036;
SET @Transform := 43059;
SET @Credit := 43037;

-- Delete the old EAIs while using part of their data
/*
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Tribesman;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Woodsman;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Shield_Maiden;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Warrior;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Raider;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Berserker;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Rune_Seer;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Rune_Caster;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@Oracle;
*/

-- Winterskorn Tribesman
UPDATE `creature_template` SET `AIName`='SmartAI ' WHERE `entry`=@Tribesman;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Tribesman;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Tribesman,0,0,1,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tribesman - On hit by spell Dismember - Cast spell trasnform on self'),
(@Tribesman,0,1,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Tribesman - Linked with previous event - Cast kill credit to player'),
(@Tribesman,0,2,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Tribesman - IC - Say random text from id 0');

-- Winterskorn Woodsman
UPDATE `creature_template` SET `AIName`='SmartAI ' WHERE `entry`=@Woodsman;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Woodsman;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Woodsman,0,0,0,0,0,100,0,100,1000,5000,14500,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Woodsman - IC - Cast spell Throw on victim'),
(@Woodsman,0,1,0,0,0,100,0,1000,4500,4900,8100,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Woodsman - IC - Cast spell Chop on victim'),
(@Woodsman,0,2,3,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Woodsman - On hit by spell Dismember - Cast spell trasnform on self'),
(@Woodsman,0,3,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Woodsman - Linked with previous event - Cast kill credit to player'),
(@Woodsman,0,4,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Woodsman - IC - Say random text from id 0');

-- Winterskorn Shield-Maiden
UPDATE `creature_template` SET `AIName`='SmartAI ' WHERE `entry`=@Shield_Maiden;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Shield_Maiden;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Shield_Maiden,0,0,0,0,0,100,0,1000,2000,6000,14500,11,43416,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Shield_Maiden - IC - Throw Shield'),
(@Shield_Maiden,0,1,2,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shield_Maiden - On hit by spell Dismember - Cast spell trasnform on self'),
(@Shield_Maiden,0,2,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Shield_Maiden - Linked with previous event - Cast kill credit to player'),
(@Shield_Maiden,0,3,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shield_Maiden - IC - Say random text from id 0'),
(@Shield_Maiden,0,4,0,1,0,100,0,0,60000,15000,70000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shield_Maiden - OOC - Say random text from id 1');

-- Winterskorn Warrior
UPDATE `creature_template` SET `AIName`='SmartAI ' WHERE `entry`=@Warrior;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Warrior;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Warrior,0,0,1,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warrior - On hit by spell Dismember - Cast spell trasnform on self'),
(@Warrior,0,1,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Warrior - Linked with previous event - Cast kill credit to player'),
(@Warrior,0,2,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warrior - IC - Say random text from id 0'),
(@Warrior,0,3,0,1,0,100,0,0,60000,15000,70000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warrior - OOC - Say random text from id 1');

-- Winterskorn Raider
UPDATE `creature_template` SET `InhabitType`=`InhabitType`|1,`AIName`='SmartAI ' WHERE `entry`=@Raider;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Raider;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Raider,0,0,0,13,0,100,0,4500,14000,0,0,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Raider - On target casting spell - Cast kick to interrupt and silence'),
(@Raider,0,1,2,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Raider - On hit by spell Dismember - Cast spell trasnform on self'),
(@Raider,0,2,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Raider - Linked with previous event - Cast kill credit to player'),
(@Raider,0,3,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Raider - IC - Say random text from id 0'),
(@Raider,0,4,0,1,0,100,0,0,60000,15000,70000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Raider - OOC - Say random text from id 1');

-- Winterskorn Berserker
UPDATE `creature_template` SET dynamicflags=8,`AIName`='SmartAI ' WHERE `entry`=@Berserker;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Berserker;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Berserker,0,0,1,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Berserker - On hit by spell Dismember - Cast spell trasnform on self'),
(@Berserker,0,1,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Berserker - Linked with previous event - Cast kill credit to player'),
(@Berserker,0,2,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Berserker - IC - Say random text from id 0'),
(@Berserker,0,3,0,1,0,100,0,0,60000,15000,70000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Berserker- OOC - Say random text from id 1');

-- Winterskorn Rune-Seer
UPDATE `creature_template` SET `AIName`='SmartAI ' WHERE `entry`=@Rune_Seer;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Rune_Seer;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Rune_Seer,0,0,0,0,0,100,0,1000,3500,8000,12000,11,43453,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Seer - IC - Cast spell Rune Ward on self'),
(@Rune_Seer,0,1,0,0,0,100,0,1500,4500,2900,8000,11,43083,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rune_Seer - IC - Cast spell Frostbolt on victim'),
(@Rune_Seer,0,2,0,0,0,100,0,100,4500,10000,14500,11,34787,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rune_Seer - IC - Cast spell Freezing circle victim /aoe/'),
(@Rune_Seer,0,3,0,2,0,100,0,10,90,7500,20100,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Seer - On HP% - Cast spell Healing wave on self'),
(@Rune_Seer,0,4,0,14,0,100,0,1000,20,8000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rune_Seer - On friednly HP deficit  - Cast spell Healing wave on ally'),
(@Rune_Seer,0,5,6,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Seer - On hit by spell Dismember - Cast spell trasnform on self'),
(@Rune_Seer,0,6,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rune_Seer - Linked with previous event - Cast kill credit to player'),
(@Rune_Seer,0,7,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Seer - IC - Say random text from id 0');

-- Winterskorn Rune-Caster
UPDATE `creature_template` SET dynamicflags=8,`AIName`='SmartAI ' WHERE `entry`=@Rune_Caster;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Rune_Caster;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Rune_Caster,0,0,0,0,0,100,0,1000,3500,3000,9000,11,43083,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rune_Caster - IC - Cast spell Frostbolt'),
(@Rune_Caster,0,1,0,0,0,100,0,2500,6500,8000,11000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rune_Caster - IC - Cast spell Frost Shock'),
(@Rune_Caster,0,2,0,0,0,100,0,0,5500,8000,12500,11,37798,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Rune_Caster - IC - Cast spell Exploding Rune'),
(@Rune_Caster,0,3,4,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Caster - On hit by spell Dismember - Cast spell trasnform on self'),
(@Rune_Caster,0,4,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Rune_Caster - Linked with previous event - Cast kill credit to player'),
(@Rune_Caster,0,5,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Rune_Caster - IC - Say random text from id 0');

-- Winterskorn Oracle
UPDATE `creature_template` SET dynamicflags=8,`AIName`='SmartAI ' WHERE `entry`=@Oracle;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Oracle;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Oracle,0,0,0,0,0,100,0,1000,3500,3000,9000,11,43083,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Oracle - IC - Cast spell Frostbolt'),
(@Oracle,0,1,2,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oracle - On hit by spell Dismember - Cast spell trasnform on self'),
(@Oracle,0,2,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Oracle - Linked with previous event - Cast kill credit to player'),
(@Oracle,0,3,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Oracle - IC - Say random text from id 0');

-- Winterskorn Elder
UPDATE `creature_template` SET dynamicflags=8,`AIName`='SmartAI ' WHERE `entry`=@Elder;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@Elder;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Elder,0,0,0,0,0,100,0,0,500,120000,120000,11,32734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elder - IC - Cast spell Eearth Shield'),
(@Elder,0,1,0,0,0,100,0,2000,3800,3000,8500,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Elder - IC - Cast spell Lightening bolt'),
(@Elder,0,2,0,2,0,100,0,10,90,7500,20100,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elder - On HP% - Cast spell Healing wave on self'),
(@Elder,0,3,0,14,0,100,0,1000,20,8000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder - On friednly HP deficit  - Cast spell Healing wave on ally'),
(@Elder,0,4,0,6,0,100,0,0,0,0,0,28,32734,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elder - On death - Remove auras from Eearth Shield'),
(@Elder,0,5,6,8,0,100,0,@Dismember,0,0,0,11,@Transform,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elder - On hit by spell Dismember - Cast spell trasnform on self'),
(@Elder,0,6,0,61,0,100,0,0,0,0,0,11,@Credit,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Elder - Linked with previous event - Cast kill credit to player'),
(@Elder,0,7,0,0,0,100,0,1000,15000,7200,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Elder - IC - Say random text from id 0');

-- Add conditions for Dismember - cannot be used on Transformed units
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@Dismember;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Dismember,0,0,1,1,@Transform,0,0,1,0,'','Amulet can target only Iskalder');

-- Add texts:
DELETE FROM `creature_text` WHERE `entry`=@Tribesman;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Tribesman,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Tribesman'),
(@Tribesman,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Tribesman');

DELETE FROM `creature_text` WHERE `entry`=@Woodsman;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Woodsman,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Woodsman'),
(@Woodsman,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Woodsman');

DELETE FROM `creature_text` WHERE `entry`=@Berserker;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Berserker,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,0,'Come on, stop trying to hit me and hit me already!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,1,'I train better against a target dummy.',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,2,'Practice or not, you''re going to spit teeth!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,3,'Sure you don''t need a break, old woman?',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,4,'When the little ones come, I won''t hold back like I am with you.',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,5,'You practice as if you''re still asleep.',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,6,'You spar like a girl!',12,0,100,1,0,0,'Winterskon Berserker'),
(@Berserker,1,7,'Your sparring is feeble!',12,0,100,1,0,0,'Winterskon Berserker');

DELETE FROM `creature_text` WHERE `entry`=@Warrior;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Warrior,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,0,'Come on, stop trying to hit me and hit me already!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,1,'I train better against a target dummy.',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,2,'Practice or not, you''re going to spit teeth!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,3,'Sure you don''t need a break, old woman?',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,4,'When the little ones come, I won''t hold back like I am with you.',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,5,'You practice as if you''re still asleep.',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,6,'You spar like a girl!',12,0,100,1,0,0,'Winterskon Warrior'),
(@Warrior,1,7,'Your sparring is feeble!',12,0,100,1,0,0,'Winterskon Warrior');

DELETE FROM `creature_text` WHERE `entry`=@Raider;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Raider,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,0,'Come on, stop trying to hit me and hit me already!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,1,'I train better against a target dummy.',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,2,'Practice or not, you''re going to spit teeth!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,3,'Sure you don''t need a break, old woman?',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,4,'When the little ones come, I won''t hold back like I am with you.',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,5,'You practice as if you''re still asleep.',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,6,'You spar like a girl!',12,0,100,1,0,0,'Winterskon Raider'),
(@Raider,1,7,'Your sparring is feeble!',12,0,100,1,0,0,'Winterskon Raider');

DELETE FROM `creature_text` WHERE `entry`=@Shield_Maiden;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Shield_Maiden,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,0,'Come on, stop trying to hit me and hit me already!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,1,'I train better against a target dummy.',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,2,'Practice or not, you''re going to spit teeth!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,3,'When the little ones come, I won''t hold back like I am with you.',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,4,'You practice as if you''re still asleep.',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,5,'You spar like a girl!',12,0,100,1,0,0,'Winterskon Shield_Maiden'),
(@Shield_Maiden,1,6,'Your sparring is feeble!',12,0,100,1,0,0,'Winterskon Shield_Maiden');

DELETE FROM `creature_text` WHERE `entry`=@Elder;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Elder,0,0,'For Ymiron!',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,1,'I will break you!',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,2,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,3,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,4,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,5,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Elder'),
(@Elder,0,6,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Elder');

DELETE FROM `creature_text` WHERE `entry`=@Rune_Caster;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Rune_Caster,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Rune_Caster'),
(@Rune_Caster,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Rune_Caster');

DELETE FROM `creature_text` WHERE `entry`=@Rune_Seer;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Rune_Seer,0,0,'Die, maggot!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,1,'For Ymiron!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,2,'Haraak foln!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,3,'I spit on you!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,4,'I will break you!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,5,'I will feed you to the dogs!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,6,'I will take pleasure in gutting you!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,7,'I''ll eat your heart!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,8,'Look what''s come to play.',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,9,'My life for Ymiron!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,10,'Sniveling pig!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,11,'There will be no everlasting life for you!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,12,'Ugglin oo bjorr!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,13,'YAAARRRGH!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,14,'You come to die!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,15,'You tiny creatures disgust me!',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,16,'Your entrails will make a fine necklace.',12,0,100,1,0,0,'Winterskon Rune_Seer'),
(@Rune_Seer,0,17,'Your race is a disease upon the world!',12,0,100,1,0,0,'Winterskon Rune_Seer');
