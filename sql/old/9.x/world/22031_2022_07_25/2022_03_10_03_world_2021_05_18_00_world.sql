--
UPDATE `creature_text` SET `Emote` = 397 WHERE `CreatureID` = 24718 AND `GroupID` = 1;
UPDATE `creature_text` SET `Emote` = 396 WHERE `CreatureID` = 24718 AND `GroupID` = 2;

UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 24823;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24718,24823) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2471800,2471801,2482300) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- This is wrong. HE INDEED SHOULD walk over his rug to trigger the event, it's not LoS
-- We can implement it but it will be over complicated and still will not look like in retail
(24718,0,0,0,10,0,100,0,1,5,23000,23000,0,80,2471800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lebronski - LoS - Run Script"),
(24718,0,1,2,8,0,100,0,44562,0,0,0,0,1,2,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Lebronski - On Spellhit 'Bluff' - Say Line 2"),
(24718,0,2,0,61,0,100,0,0,0,0,0,0,11,44563,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lebronski - On Spellhit 'Bluff' - Cast 'Bluff Quest Credit'"),
-- Completely separate event(sniff) without condition, it doesn't matter if Lebronski started 2471800 or not,
-- Iron Rune Construct will say it anyway
(24718,0,3,0,8,0,100,0,44562,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lebronski - On Spellhit 'Bluff' - Say Line 0"),

-- All these events are scheduled at once in retail. Kinda. For example emote action may be delayed if he will be bluffed too fast
(2471800,9,0,0,0,0,100,0,0,0,0,0,0,54,23000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lebronski - On Script - Pause Waypoint"),
(2471800,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lebronski - On Script - Set Orientation Invoker"),
(2471800,9,2,0,0,0,100,0,2000,2000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Lebronski - On Script - Say Line 1"),
(2471800,9,3,0,0,0,100,0,0,0,0,0,0,11,44656,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lebronski - On Script - Cast 'Iron Dwarf Investigating'"),
(2471800,9,4,0,0,0,100,0,2000,2000,0,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lebronski - On Script - Play Emote 274"),
(2471800,9,5,0,0,0,100,0,17000,17000,0,0,0,28,44656,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lebronski - On Script - Remove Aura 'Iron Dwarf Investigating'");

DELETE FROM `spell_scripts` WHERE `id` = 44563;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(44563,0,0,15,44569,2,0,0,0,0,0,"Bluff Quest Credit - On Effect Hit (Dummy) - Target - Cast 'Bluff Quest Credit'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 24718 AND `SourceId` = 0 AND `SourceGroup` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,2,24718,0,0,1,1,44656,0,0,0,0,0,"","Group 0: Execute SAI (Action 1) if creature does have aura 'Iron Dwarf Investigating'");

UPDATE `spell_target_position` SET `PositionX` = 479.019, `PositionZ` = 308.82935, `VerifiedBuild` = 15595 WHERE `ID` IN (49984,49988,49990,49992);
