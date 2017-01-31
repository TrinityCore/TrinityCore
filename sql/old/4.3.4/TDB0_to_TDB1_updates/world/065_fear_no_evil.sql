-- [Q] Fear No Evil

-- Injured Stormwind Infantry SAI
SET @ENTRY := 50047;
SET @SPELL_RENEWED_LIFE := 93097;
SET @SPELL_GET_BOYS_BACK := 93072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,90,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - Out of Combat - Emote State Sleep"), -- Doing this through SAI, else we can't cancel it
(@ENTRY,0,1,0,8,0,100,0,@SPELL_RENEWED_LIFE,0,0,0,80,@ENTRY*100,0,2,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Spellhit - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Script - Set Phase 1"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,90,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Script - Stop Sleeping"),
(@ENTRY*100,9,3,0,0,0,100,0,2000,2000,0,0,33,@ENTRY,0,0,0,0,0,7,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Script - Quest Credit"),
(@ENTRY*100,9,4,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Script - Say Line 0 (random)"),
(@ENTRY*100,9,5,0,0,0,100,0,4500,4500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Stormwind Infantry - On Script - Forced Despawn");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Bless you, hero!",12,0,100,0,0,0,"Injured Stormwind Infantry"),
(@ENTRY,0,1,"I live to fight another day!",12,0,100,0,0,0,"Injured Stormwind Infantry"),
(@ENTRY,0,2,"I... I'm ok! I'm ok!",12,0,100,0,0,0,"Injured Stormwind Infantry"),
(@ENTRY,0,3,"I will fear no evil!",12,0,100,0,0,0,"Injured Stormwind Infantry"),
(@ENTRY,0,4,"You're $N! The hero that everyone has been talking about! Thank you!",12,0,100,0,0,0,"Injured Stormwind Infantry"),
(@ENTRY,0,5,"Thank the Light!",12,0,100,0,0,0,"Injured Stormwind Infantry");


UPDATE `quest_template` SET `PrevQuestId`=28785 WHERE `Id`=28809;
UPDATE `quest_template` SET `PrevQuestId`=28784 WHERE `Id`=28810;
UPDATE `quest_template` SET `PrevQuestId`=28787 WHERE `Id`=28811;
UPDATE `quest_template` SET `PrevQuestId`=28788 WHERE `Id`=28812;
UPDATE `quest_template` SET `PrevQuestId`=28789 WHERE `Id`=28813;
UPDATE `quest_template` SET `PrevQuestId`=28780 WHERE `Id`=28806;
UPDATE `quest_template` SET `PrevQuestId`=28786 WHERE `Id`=28808;

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=@ENTRY;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`) VALUES
(@ENTRY,@SPELL_GET_BOYS_BACK,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=@ENTRY AND `SourceEntry`=@SPELL_GET_BOYS_BACK;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(18,@ENTRY,@SPELL_GET_BOYS_BACK,0,9,0,28812,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,1,9,0,28813,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,2,9,0,29082,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,3,9,0,28811,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,4,9,0,28810,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,5,9,0,28808,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,6,9,0,28809,0,0,0,'Required quest active for spellclick'),
(18,@ENTRY,@SPELL_GET_BOYS_BACK,7,9,0,28806,0,0,0,'Required quest active for spellclick');

-- Conditions for Get Our Boys Back Dummy
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceID`=13 AND `SourceEntry`=@SPELL_GET_BOYS_BACK;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`elseGroup`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(13,0,@SPELL_GET_BOYS_BACK,18,0,1,@ENTRY,1,0,"Get Our Boys Back Dummy targets Injured Stormwind Infantry");

UPDATE `creature_template` SET `gossip_menu_id`=7945 WHERE `entry`=52212; -- by malc (not related)
