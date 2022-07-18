--
UPDATE `creature_template` SET `minlevel` = 1, `maxlevel` = 1, `exp` = 0 WHERE `entry` = 22444;
UPDATE `creature_template` SET `unit_flags` = 33024 WHERE `entry` = 22454;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22444,16878,22454) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2245400) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22444,0,0,0,60,0,100,0,5000,5000,5000,5000,0,11,39184,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Anchorite Relic Bunny - On Update - Cast 'Anchorite Contrition'"),

(16878,0,0,0,4,0,100,0,0,0,0,0,0,11,35570,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Shattered Hand Berserker - On Aggro - Cast 'Charge'"),
(16878,0,1,2,2,0,100,1,0,30,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shattered Hand Berserker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(16878,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shattered Hand Berserker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(16878,0,3,0,6,0,100,0,0,0,0,0,0,11,39190,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shattered Hand Berserker - On Death - Cast 'Send Vengeance'"),

(22454,0,0,0,11,0,100,0,0,0,0,0,0,80,2245400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Spirit - On Spawn - Run Script"),

(2245400,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Fel Spirit - On Script - Say Line 0"),
(2245400,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Fel Spirit - On Script - Set Orientation (Summoner)"),
(2245400,9,2,0,0,0,100,0,3000,3000,0,0,0,144,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fel Spirit - On Script - Set ImmunePC Off"),
(2245400,9,3,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Fel Spirit - On Script - Start Attack Summoner");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 16878 AND `SourceId` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 39190;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- Channeled aura is removed on death > condition always is false, this should be a bit better than previous SpellHit > Phase
(22,4,16878,0,0,29,1,22444,30,0,0,0,0,"","Group 0: Execute Event (Action 3) if creature 'Anchorite Relic Bunny' is within 30 yards"),
(13,1,39190,0,0,31,0,3,22444,0,0,0,0,"","Group 0: Spell 'Send Vengeance' (Effect 0) targets creature 'Anchorite Relic Bunny'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_hellfire_peninsula_send_vengeance',
'spell_hellfire_peninsula_send_vengeance_to_player');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(39190,'spell_hellfire_peninsula_send_vengeance'),
(39202,'spell_hellfire_peninsula_send_vengeance_to_player');

UPDATE `gameobject_template_addon` SET `flags` = 0 WHERE `entry` = 185298;
