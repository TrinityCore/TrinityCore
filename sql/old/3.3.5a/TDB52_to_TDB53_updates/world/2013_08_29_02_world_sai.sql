--  Suppression (7583)
SET @NPC_DEMON  := 12396;

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@NPC_DEMON;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC_DEMON;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC_DEMON);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_DEMON,0,0,0,0,0,100,0,5000,8000,18000,24000,11,16005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Doomguard Commander - Cast Rain of Fire'),
(@NPC_DEMON,0,1,0,0,0,100,0,12000,15000,20000,25000,11,16727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Doomguard Commander - Cast War Stomp'),
(@NPC_DEMON,0,2,0,0,0,100,0,2000,4000,25000,32000,11,20812,0,0,0,0,0,2,0,0,0,0,0,0,0,'Doomguard Commander - Cast Cripple'),
(@NPC_DEMON,0,3,0,0,0,100,0,7000,14000,17000,22000,11,15090,0,0,0,0,0,2,0,0,0,0,0,0,0,'Doomguard Commander - Cast Dispel Magic'),
--
(@NPC_DEMON,0,4,5,8,0,100,0,23019,0,0,0,56,18605,1,0,0,0,0,18,20,0,0,0,0,0,0,'Doomguard Commander - On spellhit - Add item Imprisoned Doomguard'),
(@NPC_DEMON,0,5,6,61,0,100,0,0,0,0,0,11,23020,0,0,0,0,0,1,0,0,0,0,0,0,0,'Doomguard Commander - On spellhit - Cast Crystal Imprisonment'),
(@NPC_DEMON,0,6,0,61,0,100,0,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Doomguard Commander - On spellhit - Despawn');

-- Conditions for Glowing Crystal Prison 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=23015;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,23015,0,0,31,1,3,12396,0,0,173,0,'','Glowing Crystal Prison target limit to Doomguard Commander');
