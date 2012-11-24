-- Quest "The Denouncement" (12273) (Converted&tweaked to SAI by Nay)
SET @Goodman := 27234; -- Blacksmith Goodman
SET @Zierhut := 27235; -- Lead Cannoneer Zierhut (npc)
SET @Mercer := 27236; -- Stable Master Mercer (npc)
SET @Jordan := 27237; -- Commander Jordan (npc)
SET @Rod := 37438; -- Rod of Compulsion (item)
SET @Compelled := 48714; -- Compelled (spell)
SET @DeathJordan := 48724; -- The Denouncement: Commander Jordan On Death
SET @DeathZierhut := 48726; -- The Denouncement: Lead Cannoneer Zierhut On Death
SET @DeathGoodman := 48728; -- The Denouncement: Blacksmith Goodman On Death
SET @DeathMercer := 48730; -- The Denouncement: Stable Master Mercer On Death
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry` IN (@Goodman,@Zierhut,@Mercer,@Jordan);
-- Spell scripts: Give kill credit through spell
DELETE FROM `spell_scripts` WHERE `id` IN (@DeathJordan,@DeathZierhut,@DeathGoodman,@DeathMercer);
INSERT INTO `spell_scripts`(`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(@DeathJordan,0,15,48723,1,0,0,0,0,0),  -- cast "The Denouncement: Commander Jordan Kill Credit" on player
(@DeathZierhut,0,15,48725,1,0,0,0,0,0), -- cast "The Denouncement: Lead Cannoneer Zierhut Kill Credit" on player
(@DeathGoodman,0,15,48727,1,0,0,0,0,0), -- cast "The Denouncement: Blacksmith Goodman Kill Credit" on player
(@DeathMercer,0,15,48729,1,0,0,0,0,0);  -- cast "The Denouncement: Stable Master Mercer Kill Credit" on player
-- Spell targets for spells that give quest credit through effect 77
DELETE FROM `conditions` where `SourceEntry` IN (@DeathJordan,@DeathZierhut,@DeathGoodman,@DeathMercer) AND `SourceTypeOrReferenceId`=13;
DELETE FROM `conditions` where `SourceEntry`=@Rod AND `SourceTypeOrReferenceId`=18;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`Comment`) VALUES
(13,0,@DeathJordan,0,18,1,@Jordan,0,0, 'The Denouncement: Jordan target'),
(13,0,@DeathZierhut,0,18,1,@Zierhut,0,0, 'The Denouncement: Zierhut target'),
(13,0,@DeathGoodman,0,18,1,0,0,0, 'The Denouncement: Goodman target'),
(13,0,@DeathMercer,0,18,1,@Mercer,0,0, 'The Denouncement: Mercer'),
(18,0,@Rod,0,24,1,@Goodman,0,0, 'The Denouncement: Rod - Goodman target'),
(18,0,@Rod,0,24,1,@Zierhut,0,0, 'The Denouncement: Rod - Zierhut target'),
(18,0,@Rod,0,24,1,@Mercer,0,0, 'The Denouncement: Rod - Mercer target'),
(18,0,@Rod,0,24,1,@Jordan,0,0, 'The Denouncement: Rod - Jordan target');
DELETE FROM `creature_text` WHERE `entry` IN (@Goodman,@Zierhut,@Mercer,@Jordan);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Goodman,0,0, 'You are being misled! The Onslaught is all lies! The Scourge and the Forsaken are not our enemies! Wake up!',1,0,100,5,0,0, 'Blacksmith Goodman'),
(@Jordan,0,0, 'High general Abbendis personally told me that it was a mistake to come north and that we''re doomed! I urge you all to lay down your weapons and leave before it''s too late!',1,0,100,5,0,0, 'Commander Jordan'),
(@Zierhut,0,0, 'Renounce the Scarlet Onslaught! Don''t listen to the lies of the high general and the grand admiral any longer!',1,0,100,5,0,0, 'Lead Cannoneer Zierhut'),
(@Mercer,0,0, 'Abbendis is nothing but a harlot and Grand Admiral Westwind is selling her cheap like he sold us out!',1,0,100,5,0,0, 'Stable Master Mercer');
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid` IN (@Goodman,@Zierhut,@Mercer,@Jordan);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@Goodman,0,0,0,8,0,100,0,@Compelled,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On spellhit set phase 2'),
(@Goodman,0,1,0,6,2,100,0,0,0,0,0,85,@DeathGoodman,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On death in phase 2 cast spell'),
(@Goodman,0,2,0,25,0,100,0,0,0,0,0,28,@Compelled,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On reset remove Compelled aura'),
(@Goodman,0,3,0,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On reset set phase 0'),
(@Goodman,0,4,0,6,2,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On death in phase 2 yell'),
(@Mercer,0,0,0,8,0,100,0,@Compelled,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Mercer: On spellhit set phase 2'),
(@Mercer,0,1,0,6,2,100,0,0,0,0,0,85,@DeathMercer,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Mercer: On death in phase 2 cast spell'),
(@Mercer,0,2,0,25,0,100,0,0,0,0,0,28,@Compelled,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Mercer: On reset remove Compelled aura'),
(@Mercer,0,3,0,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Mercer: On reset set phase 0'),
(@Mercer,0,4,0,6,2,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Mercer: On death in phase 2 yell'),
(@Zierhut,0,0,0,8,0,100,0,@Compelled,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Goodman: On spellhit set phase 2'),
(@Zierhut,0,1,0,6,2,100,0,0,0,0,0,85,@DeathZierhut,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Zierhut: On death in phase 2 cast spell'),
(@Zierhut,0,2,0,25,0,100,0,0,0,0,0,28,@Compelled,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Zierhut: On reset remove Compelled aura'),
(@Zierhut,0,3,0,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Zierhut: On reset set phase 0'),
(@Zierhut,0,4,0,6,2,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Zierhut: On death in phase 2 yell'),
(@Jordan,0,0,0,8,0,100,0,@Compelled,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Jordan: On spellhit set phase 2'),
(@Jordan,0,1,0,6,2,100,0,0,0,0,0,85,@DeathJordan,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Jordan: On death in phase 2 cast spell'),
(@Jordan,0,2,0,25,0,100,0,0,0,0,0,28,@Compelled,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Jordan: On reset remove Compelled aura'),
(@Jordan,0,3,0,25,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Jordan: On reset set phase 0'),
(@Jordan,0,4,0,6,2,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'The Denouncement/Jordan: On death in phase 2 yell');

-- Kill a unrelated console DB error
DELETE FROM `creature_addon` WHERE `guid`=88103;

-- Valiance Keep Footman SAI (by Malcrom)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25253;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-111383,-111377,-111378,-111382,-111379,-111380);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-111383,0,0,0,1,0,100,0,1000,2000,4000,5000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,'Attack emote every 4-5 sec'),
(-111377,0,0,0,1,0,100,0,3000,4000,4000,5000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,'Attack emote every 4-5 sec'),
(-111378,0,0,0,1,0,100,0,8000,8000,16000,16000,10,4,5,21,0,0,0,1,0,0,0,0,0,0,0,'Random cheer emote every 16 sec'),
(-111382,0,0,0,1,0,100,0,16000,16000,16000,16000,10,4,5,21,0,0,0,1,0,0,0,0,0,0,0,'Random cheer emote every 16 sec'),
(-111379,0,0,0,1,0,100,0,2000,2000,5000,5000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,'Attack emote every 5 sec'),
(-111379,0,1,0,1,0,100,0,4000,4000,7000,7000,5,36,0,0,0,0,0,10,111376,25253,0,0,0,0,0,'Attack emote dueler 2 sec later sec'),
(-111380,0,0,0,1,0,100,0,5000,5000,5000,5000,5,36,0,0,0,0,0,1,0,0,0,0,0,0,0,'Attack emote every 5 sec'),
(-111380,0,1,0,1,0,100,0,7000,7000,7000,7000,5,36,0,0,0,0,0,10,111381,25253,0,0,0,0,0,'Attack emote dueler 2 sec later sec');
