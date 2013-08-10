-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Mounts players mode 25
UPDATE `creature_template` SET `VehicleId`=220,`spell1`=56091,`spell2`=56092,`spell3`=57090,`spell4`=57143,`spell5`=57108,`spell6`=57092,`spell7`=60534,`InhabitType`=5 WHERE `entry`=31752;
-- Hover Disk mode 25
UPDATE `creature_template` SET `VehicleId`=224,`faction_A`=35,`faction_H`=35,`InhabitType`=5 WHERE `entry` IN (31749,31748);
-- spawn the focusing iris 25men
DELETE FROM gameobject WHERE id IN (193960);
INSERT INTO `gameobject`
(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(361,193960,616,2,1,754.362,1301.61,266.171,6.23742,0,0,0.022883,-0.999738,300,0,1);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- The Heart of the Storm (Issue 1959)
DELETE FROM `gameobject` WHERE `id`=192181;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(362,192181,571,1,1,7308.945,-727.9163,791.6083,1.53589,0,0,0.690772,0.723073,30,100,1);
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Add support for {Q} Corrupted Sabers ID: 4506 (Issue 2297)
SET @CommonKitten:=9937;
SET @CorruptedKitten :=9936;
SET @SGossip :=55002; -- Gossip for Kitten when near quest giver
SET @SpellVisual :=16510; -- Turn Kitten in Saber
SET @Winna   :=9996;  -- Winna Hazzard
SET @Saber   :=10042; -- Big green cat
-- Add SAI support for Corrupted Kitten
UPDATE `creature_template` SET `AIName`='SmartAI',`gossip_menu_id`=@SGossip,`npcflag`=1 WHERE `entry`=@CorruptedKitten;
UPDATE `creature_template` SET `AIName`='SmartAI',`gossip_menu_id`=@SGossip,`npcflag`=1 WHERE `entry`=@CommonKitten;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@CorruptedKitten, @CommonKitten);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@CommonKitten,0,0,1,54,0,100,0,0,0,0,0,36,@CorruptedKitten,0,0,0,0,0,1,0,0,0,0,0,0,0,'Common Kitten - On spawn - Change template to corrupted one'),
(@CommonKitten,0,1,2,61,0,100,0,0,0,0,0,11,@SpellVisual,0,0,0,0,0,1,0,0,0,0,0,0,0,'Common Kitten - On OOC of 10 sec - Cast Corrupted Saber visual to self'),
(@CommonKitten,0,2,0,61,0,100,0,0,0,0,0,3,@Saber,0,0,0,0,0,1,0,0,0,0,0,0,0,'Common Kitten - Linked with previous event - Morph to Corrupted Saber'),
(@CommonKitten,0,3,4,62,0,100,0,@SGossip,1,0,0,26,4506,0,0,0,0,0,7,0,0,0,0,0,0,0,'Common Kitten - On Gossip Select - Award quest,since no credit'),
(@CommonKitten,0,4,5,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Common Kitten - Linked with previous event - Close gossip'),
(@CommonKitten,0,5,6,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Common Kitten - Linked with previous event - Set unseen'),
(@CommonKitten,0,6,0,61,0,100,0,0,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Common Kitten - Linked with previous event - Despawn in 1 sec');
-- Insert Gossip /custom made id/
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@SGossip AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`) VALUES
(@SGossip,1,0,'I want to release the saber to Winna.',1,131,0);
-- Only show gossip if near Winna
DELETE FROM `conditions` WHERE `SourceGroup`=@SGOSSIP AND `SourceTypeOrReferenceId`=15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,@SGOSSIP,1,0,29,1,@Winna,5,0,0,0,'','Only show second gossip Corrupted Saber is near Wina in 5 yards');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Fix for Prepping the Speech by Gecko32 (Issue 2399)
SET @MEKKATORQUE :=39712;
SET @OZZIE       :=1268;
SET @MILLI       :=7955;
SET @TOG         :=6119;
-- Add creature text for npc's
DELETE FROM `creature_text` WHERE `entry`=@MEKKATORQUE;
DELETE FROM `creature_text` WHERE `entry`=@OZZIE;
DELETE FROM `creature_text` WHERE `entry`=@MILLI;
DELETE FROM `creature_text` WHERE `entry`=@TOG;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@MEKKATORQUE,0,0,'They may take our lives, but they''ll never take...',12,0,100,0,0,0,'High Tinker Mekkatorque to Milli Featherwhistle 1'),
(@MEKKATORQUE,1,0,'...our INNOVATION!',12,0,100,0,0,0,'High Tinker Mekkatorque to Milli Featherwhistle 2'),
(@MEKKATORQUE,2,0,'What I want out of each and every one of you is a hard-target search of every refuelling station, residence, warehouse, farmhouse, henhouse, outhouse, and doghouse in this area.',12,0,100,0,0,0,'High Tinker Mekkatorque to Ozzie Togglevolt 1'),
(@MEKKATORQUE,3,0,'Your fugitive''s name is Mekgineer Thermaplugg.',12,0,100,0,0,0,'High Tinker Mekkatorque to Ozzie Togglevolt 2'),
(@MEKKATORQUE,4,0,'Go get him.',12,0,100,0,0,0,'High Tinker Mekkatorque to Ozzie Togglevolt 3'),
(@MEKKATORQUE,5,0,'We will not go quietly into the night! We will not vanish without a fight!',12,0,100,0,0,0,'High Tinker Mekkatorque to Tog Rustsprocket 1'),
(@MEKKATORQUE,6,0,'We''re going to live on! We''re going to survive! Today we celebrate...',12,0,100,0,0,0,'High Tinker Mekkatorque to Tog Rustsprocket 2'),
(@MEKKATORQUE,7,0,'...our Autonomy Day!',12,0,100,0,0,0,'High Tinker Mekkatorque to Tog Rustsprocket 3'),
(@OZZIE,0,0,'Hmm, I suppose it could work. But it could really use a little more umph!',12,0,100,0,0,0,'Ozzie Togglevolt reply'),
(@MILLI,0,0,'What? I don''t even know what you''re talking about! That''s terrible!',12,0,100,0,0,0,'Milli Featherwhistle reply'),
(@TOG,0,0,'Horrible! Well, all right,maybe it just needs a little cleaning up?',12,0,100,0,0,0,'Tog Rustsprocket reply');
-- Add SAI for Milli Featherwhistle
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MILLI;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MILLI;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MILLI,0,0,0,8,0,100,1,74222,0,0,0,1,0,2000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On spell hit - High Tinker Mekkatorque say part1'),
(@MILLI,0,1,0,52,0,100,0,0,@MEKKATORQUE,0,0,1,1,4000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On text over - High Tinker Mekkatorque say part2'),
(@MILLI,0,2,3,52,0,100,0,1,@MEKKATORQUE,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On text over - Reply'),
(@MILLI,0,3,4,61,0,100,0,0,0,0,0,33,@MILLI,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On link - credit quest'),
(@MILLI,0,4,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On link - set data 1');
-- Add SAI for Ozzie Togglevolt
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@OZZIE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@OZZIE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@OZZIE,0,0,0,8,0,100,1,74222,0,0,0,1,2,2000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Ozzie Togglevolt - On spell hit - High Tinker Mekkatorque say part1'),
(@OZZIE,0,1,0,52,0,100,0,2,@MEKKATORQUE,0,0,1,3,4000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Ozzie Togglevolt - On text over - High Tinker Mekkatorque say part2'),
(@OZZIE,0,2,0,52,0,100,0,3,@MEKKATORQUE,0,0,1,4,4000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Ozzie Togglevolt - On text over - High Tinker Mekkatorque say part3'),
(@OZZIE,0,3,4,52,0,100,0,4,@MEKKATORQUE,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Ozzie Togglevolt - On text over - Reply'),
(@OZZIE,0,4,5,61,0,100,0,0,0,0,0,33,@OZZIE,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On link - credit quest'),
(@OZZIE,0,5,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Milli Featherwhistle - On link - set data 1');
-- Add SAI for Tog Rustsprocket
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@TOG;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@TOG;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TOG,0,0,0,8,0,100,1,74222,0,0,0,1,5,2000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On spell hit - High Tinker Mekkatorque say part1'),
(@TOG,0,1,0,52,0,100,0,5,@MEKKATORQUE,0,0,1,6,4000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On text over - High Tinker Mekkatorque say part2'),
(@TOG,0,2,0,52,0,100,0,6,@MEKKATORQUE,0,0,1,7,4000,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On text over - High Tinker Mekkatorque say part3'),
(@TOG,0,3,4,52,0,100,0,7,@MEKKATORQUE,0,0,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On text over - Reply'),
(@TOG,0,4,5,61,0,100,0,0,0,0,0,33,@TOG,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On link - credit quest'),
(@TOG,0,5,0,61,0,100,0,0,0,0,0,45,1,1,0,0,0,0,11,@MEKKATORQUE,10,0,0.0,0.0,0.0,0.0,'Tog Rustsprocket - On link - set data 1');
-- Add SAI for High Tinker Mekkatorque
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@MEKKATORQUE;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@MEKKATORQUE;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@MEKKATORQUE,0,0,0,38,0,100,1,1,1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,'High Tinker Mekkatorque - on data set- despawn');
-- add prev quest id to both Words for Delivery
UPDATE `quest_template` SET `PrevQuestId`=25283 WHERE `Id`=25500;-- below 75
UPDATE `quest_template` SET `PrevQuestId`=25283 WHERE `Id`=25286;-- 75+
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Where the Wild Things Roam by Shlomi155 (Issue 3038)
-- Quest item will work only at Dragonblight and if the quest is incomplete!
DELETE FROM `conditions` WHERE SourceEntry=47627;
INSERT INTO `conditions` VALUES
(17,0,47627,0,0,9,0,12111,0,0,0,0,'',NULL),
(17,0,47627,0,0,23,0,65,0,0,0,0,'',NULL);
UPDATE `creature_template` SET AIName='SmartAI' WHERE entry IN (26615,26482);
DELETE FROM `creature_ai_scripts`where creature_id IN (26615,26482);
DELETE FROM `smart_scripts` WHERE entryorguid IN (26615,26482);
INSERT INTO `smart_scripts` VALUES
(26615,0,0,0,9,0,100,1,0,5,8000,12000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Snowfall Elk - Cast Puncture'),
(26615,0,1,2,23,0,100,1,47628,1,1,1,11,47675,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snowfall Elk - On Aura - Cast Recently Inoculated'),
(26615,0,2,3,61,0,100,1,0,0,0,0,33,26895,0,0,0,0,0,18,40,0,0,0,0,0,0,'Snowfall Elk - Event Linked - Credit'),
(26615,0,3,0,61,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Snowfall Elk - Event Linked - Despawn Delay 5 Seconds'),
(26482,0,0,1,23,0,100,1,47628,1,1,1,11,47675,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arctic Grizzly - On Aura - Cast Recently Inoculated'),
(26482,0,1,2,61,0,100,1,0,0,0,0,33,26882,0,0,0,0,0,18,40,0,0,0,0,0,0,'Arctic Grizzly - Event Linked - Credit'),
(26482,0,2,0,61,0,100,1,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Arctic Grizzly - Event Linked - Despawn Delay 5 Seconds');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- [Q] [A/H] Catch the Wild Wolpertinger! by Discover (Issue 3131)
-- Wild Wolpertinger SAI
SET @WOLPERTINGER :=23487;
SET @SPELL_NET    :=41621;
SET @SPELL_CREATE_ITEM :=41622;
UPDATE `creature_template` SET `AIName`='SmartAI',`unit_flags`=`unit_flags`|512 WHERE `entry`=@WOLPERTINGER;
UPDATE `creature` SET `position_x`=24.539537 WHERE `guid`=207045 AND `id`=@WOLPERTINGER; -- For some reason this one was spawned in air
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@WOLPERTINGER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@WOLPERTINGER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@WOLPERTINGER,0,0,1,8,0,100,0,@SPELL_NET,0,0,0,11,@SPELL_CREATE_ITEM,2,0,0,0,0,7,0,0,0,0,0,0,0,"Wild Wolpertinger - On Spellhit - Cast Create Stunned Wolpertinger Item"),
(@WOLPERTINGER,0,1,0,61,0,100,0,0,0,0,0,41,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Wolpertinger - On Spellhit - Forced Despawn");
-- Condition for spell Wolpertinger Net
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL_NET;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@SPELL_NET,0,0,31,1,3,@WOLPERTINGER,0,0,0,'','Net can only hit Wolpertingers');
-- Update Wolpetinger flags to remove immunity to players,was 768 before
UPDATE `creature_template` SET `unit_flags`=512 WHERE `entry`=@WOLPERTINGER;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Fix quest Blinding the Eyes in the Sky ID: 13313 by Trista (Issue 3225)
SET @ReconFighter :=32189;
SET @Spell        :=60079;
-- Add SAI support Skybreaker Recon
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ReconFighter;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ReconFighter;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ReconFighter,0,0,1,8,0,100,0,@Spell,0,0,0,33,@ReconFighter,0,0,0,0,0,7,0,0,0,0,0,0,0,'Skybreaker Recon - On spell hit - Give kill credit to invoker'),
(@ReconFighter,0,1,0,61,0,100,0,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Skybreaker Recon - Linked with previous event - Kill self');
-- Update Vehicle_Accesorry to die along with the vehicle,otherwise little untargetable dwards fall on ground
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE `entry`=32189 AND `seat_id`=0;
-- Add conditions for spell to target only alive Recons
DELETE FROM `conditions` WHERE `SourceEntry`=@Spell and `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,@Spell,0,0,36,1,0,0,0,0,0,'','Fire SGM-3 can hit only alive Recon Fighter'),
(17,0,@Spell,0,0,31,1,3,@ReconFighter,0,0,0,'','Fire SGM-3 can hit Recon Fighter');
-- Keeping the Alliance Blind ID: 13331 quest requirements
UPDATE `quest_template` SET `PrevQuestId`=13313 WHERE `Id`=13331;
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Cleansing Drak'Tharon by gecko32 (Issue 3351)
-- Update Item Enduring Mojo is normal drop not quest drop
UPDATE `creature_loot_template` SET `ChanceOrQuestChance` = ABS(`ChanceOrQuestChance`) WHERE `item`=38303;
-- Add gossip menu option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9615 AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9615,1,0,'I need another of your elixirs, Drakuru.',1,1,0,0,0,0,'');
-- Add Conditions for Gossip
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9615 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,9615,1,0,1,2,0,35797,1,0,1,0,'','Drakuru''s Elixir - Must not already have item'),
(15,9615,1,0,1,28,0,11991,0,0,0,0,'','Drakuru''s Elixir - Must have quest Subject to Interpretation'),
(15,9615,1,0,2,2,0,35797,1,0,1,0,'','Drakuru''s Elixir - Must not already have item'),
(15,9615,1,0,2,9,0,12007,0,0,0,0,'','Drakuru''s Elixir - Must have quest Sacrifices Must be Made'),
(15,9615,1,0,3,2,0,35797,1,0,1,0,'','Drakuru''s Elixir - Must not already have item'),
(15,9615,1,0,3,28,0,12802,0,0,0,0,'','Drakuru''s Elixir - Must have quest My Heart is in Your Hands'),
(15,9615,1,0,4,2,0,35797,1,0,1,0,'','Drakuru''s Elixir - Must not already have item'),
(15,9615,1,0,4,9,0,12068,0,0,0,0,'','Drakuru''s Elixir - Must have quest Voices From the Dust'),
(15,9615,1,0,5,2,0,35797,1,0,1,0,'','Drakuru''s Elixir - Must not already have item'),
(15,9615,1,0,5,28,0,12238,0,0,0,0,'','Drakuru''s Elixir - Must have quest Cleansing Drak''Tharon');
-- Add SmartAI to give item
DELETE FROM `smart_scripts` WHERE `entryorguid`=26423 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26423,0,2,3,62,0,100,0,9615,1,0,0,11,50021,2,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - cast Replace Drakuru''s Elixir'),
(26423,0,3,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Drakuru - On gossip option select - close gossip');
-- Add TEMP Drakuru's Brazier In Drak'tharon Keep
DELETE FROM `gameobject` WHERE `guid`=364;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(364,300188,600,3,1,-236.766,-614.774,116.487,1.5708,0,0,0,1,300,100,1);
-- Conditions for spell Target
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=47110;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47110,0,1,31,0,3,26498,0,0,0,'',NULL),-- Drakuru's Bunny 01
(13,1,47110,0,2,31,0,3,26559,0,0,0,'',NULL),-- Drakuru's Bunny 02
(13,1,47110,0,3,31,0,3,26700,0,0,0,'',NULL),-- Drakuru's Bunny 03
(13,1,47110,0,4,31,0,3,26789,0,0,0,'',NULL),-- Drakuru's Bunny 04
(13,1,47110,0,5,31,0,3,28015,0,0,0,'',NULL); -- Drakuru's Bunny 05
-- Add Smart AI Drakuru Bunny
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26498,26559,26700,26789,28015);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26498,26559,26700,26789,28015);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26498,0,0,0,8,0,100,0,47110,0,0,0,12,26500,3,50000,0,0,0,8,0,0,0,3386.26,-1805.32,114.909,4.945,'Drakuru Bunny 01- On Spellhit - Summmon Image of Drakuru'),
(26559,0,0,0,8,0,100,0,47110,0,0,0,12,26543,3,50000,0,0,0,8,0,0,0,4243.98,-2025.08,238.248,1.431,'Drakuru Bunny 02- On Spellhit - Summmon Image of Drakuru'),
(26700,0,0,0,8,0,100,0,47110,0,0,0,12,26701,3,50000,0,0,0,8,0,0,0,4523.94,-3472.9,228.393,-0.803,'Drakuru Bunny 03- On Spellhit - Summmon Image of Drakuru'),
(26789,0,0,0,8,0,100,0,47110,0,0,0,12,26787,3,50000,0,0,0,8,0,0,0,4599.09,-4875.82,48.956,0.748,'Drakuru Bunny 04- On Spellhit - Summmon Image of Drakuru'),
(28015,0,0,0,8,0,100,0,47110,0,0,0,12,28016,3,50000,0,0,0,8,0,0,0,-236.77,-618.61,116.475,4.727,'Drakuru Bunny 05- On Spellhit - Summmon Drakuru');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Fix Neutralizing the Cauldrons (11647) quest by Shlomi1515 (Issue 3432)
UPDATE `creature_template` SET flags_extra='128', AIName='SmartAI' WHERE entry IN (25493,25490,25492);
DELETE FROM `smart_scripts` WHERE entryorguid IN (25493,25490,25492);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25493,0,0,0,8,0,100,0,45653,0,0,0,33,25493,0,0,0,0,0,7,0,0,0,0,0,0,0,'West Enkilah Cauldron - On Spell Hit - Kil Credit'),
(25490,0,0,0,8,0,100,0,45653,0,0,0,33,25490,0,0,0,0,0,7,0,0,0,0,0,0,0,'East Enkilah Cauldron - On Spell Hit - Kil Credit'),
(25492,0,0,0,8,0,100,0,45653,0,0,0,33,25492,0,0,0,0,0,7,0,0,0,0,0,0,0,'Central Enkilah Cauldron - On Spell Hit - Kil Credit');
-- ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-- Hallow's End Treats for Jesper/spoops 8311/8312 (Issue 3548)
-- Flexing for Nougat (Alliance)
SET @INNKEEPER=6740;
SET @QUEST=8356;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,2,0,22,0,100,0,41,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Allison - on /flex credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
-- Chicken Clucking for a Mint (Alliance)
SET @INNKEEPER=5111;
SET @QUEST=8353;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,2,0,22,0,100,0,22,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Firebrew - on /chicken credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
-- Dancing for Marzipan (Alliance)
SET @INNKEEPER=6735;
SET @QUEST=8357;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,2,0,22,0,100,0,34,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Saelienne - on /dance credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
-- Incoming Gumdrop (Alliance)
SET @INNKEEPER=6826;
SET @QUEST=8355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,0,0,22,0,100,0,264,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Talvash del Kissel - on /train credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
-- Flexing for Nougat (Horde)
SET @INNKEEPER=6929;
SET @QUEST=8359;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,2,0,22,0,100,0,41,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Gryshka - on /flex credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
-- Chicken Clucking for a Mint (Horde)
SET @INNKEEPER=6741;
SET @QUEST=8354;
-- SAI
UPDATE `smart_scripts` SET `link`=3 WHERE `entryorguid`=@INNKEEPER AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,3,0,61,0,100,0,0,0,0,0,15,@QUEST,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Norman - Link - exploreded for quest');
-- conditions
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,0,12,0,12,0,0,0,0,'',"Quest avialable only during Hallow's End event");
-- Dancing for Marzipan (Horde)
SET @INNKEEPER=6746;
SET @QUEST=8360;
SET @GOSSIP=21215;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@INNKEEPER;
-- Add trick or treat SAI since the .cpp script was removed
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,0,1,62,0,100,0,@GOSSIP,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Pala - On gossip option 0 select - Close gossip'),
(@INNKEEPER,0,1,0,61,0,100,0,0,0,0,0,85,24751,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Pala - On gossip option 0 select - Player cast Trick or Treat on self'),
(@INNKEEPER,0,2,0,22,0,100,0,34,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Innkeeper Pala - on /dance credit for quest');
-- Add gossip menu option for trick or treat
DELETE FROM `gossip_menu_option` WHERE `menu_id`=@GOSSIP;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(@GOSSIP,1,5,'Make this inn your home.',8,65536,0,0,0,0,''),
(@GOSSIP,2,1,'I want to browse your goods',3,128,0,0,0,0,''),
(@GOSSIP,0,0,'Trick or Treat!',1,1,0,0,0,0,'');
-- Add conditions must be hallows end for Dancing for Marzipan quest and trick or treat option
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
DELETE FROM `conditions` WHERE `SourceGroup`=@GOSSIP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL),
(15,@GOSSIP,0,0,12,12,0,0,0,'',NULL);
-- Incoming Gumdrop (Horde)
SET @INNKEEPER=11814;
SET @QUEST=8358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@INNKEEPER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@INNKEEPER;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@INNKEEPER,0,0,0,22,0,100,0,264,0,0,0,33,@INNKEEPER,0,0,0,0,0,7,0,0,0,0,0,0,0,'Kali Remik - on /train credit for quest');
DELETE FROM `conditions` WHERE `SourceEntry`=@QUEST;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,@QUEST,0,12,12,0,0,0,'',NULL);
