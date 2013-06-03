SET @ENTRY := 33499; -- Skeletal Woodcutter
SET @QUEST_LOOT := 45080; -- Large Femur
SET @QUEST := 13654; -- There's Something About the Squire
SET @SPELL1 := 63124; -- Incapacitate Maloric
SET @SPELL2 := 63126; -- Search Maloric

-- add quest item to Skeletal Woodcutter
UPDATE `creature_template` SET `lootid`=`entry` WHERE `entry`=@ENTRY;
DELETE FROM `creature_loot_template` WHERE `entry`=@ENTRY;
INSERT INTO `creature_loot_template` VALUES
(@ENTRY,@QUEST_LOOT,-100,1,0,1,1); -- 100% drop

-- set visual effects on the skeletons
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`emote`) VALUES
(@ENTRY,234); -- chopping wood

SET @ENTRY := 33498; -- Maloric
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,23,0,100,0,@SPELL1,1,0,0,81,16777216,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maloric - on Aura: Incapacitate Maloric - set npcflag: Spellclick'),
(@ENTRY,0,1,0,23,0,100,0,@SPELL1,0,0,0,81,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Maloric - on NoAura: Incapacitate Maloric - set npcflag: none');

-- conditions for Large Femur and Maloric
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=@QUEST_LOOT;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=@SPELL2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,@QUEST_LOOT,0,24,1,@ENTRY,0,0,'','Item:Large Femur only target Maloric'),
(17,0,@SPELL2,0,9,@QUEST,0,0,0,'','Needs taken Quest 13654 to perform Spell: Search Maloric');

-- cast search Maloric, get quest item, quest completed
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@ENTRY;
INSERT INTO `npc_spellclick_spells` VALUES
(@ENTRY,@SPELL2,@QUEST,1,@QUEST,2,0,0,0);
