-- Source: Sniffs
UPDATE `gameobject_template` SET `ScriptName` = "" WHERE `entry` = 187561;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (45446,45448,45449);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,45446,0,0,31,0,3,24771,0,0,0,0,"","Group 0: Spell 'Summon Arcane Prisoner' (Effect 0) targets creature 'Coldarra Invisman'"),
(13,1,45448,0,0,31,0,3,24771,0,0,0,0,"","Group 0: Spell 'Summon Arcane Prisoner' (Effect 0) targets creature 'Coldarra Invisman'"),
(13,1,45449,0,0,31,0,3,24771,0,0,0,0,"","Group 0: Spell 'Arcane Prisoner Rescue' (Effect 0) targets creature 'Coldarra Invisman'");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (25318,25320);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25318,25320) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2531800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25318,0,0,0,54,0,100,0,0,0,0,0,0,80,2531800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Just Summoned - Run Script"),
(25320,0,0,0,54,0,100,0,0,0,0,0,0,80,2531800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Just Summoned - Run Script"),

(2531800,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Script - Set Orientation Owner"),
(2531800,9,1,0,0,0,100,0,2000,2000,0,0,0,11,45456,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Script - Cast 'Arcane Prisoner Kill Credit'"),
(2531800,9,2,0,0,0,100,0,0,0,0,0,0,11,45451,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Script - Cast 'Cosmetic Hearthstone'"),
(2531800,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Arcane Prisoner - On Script - Say Line 0");

DELETE FROM `spell_scripts` WHERE `id` = 45451;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(45451,0,0,18,0,0,0,0,0,0,0,"Cosmetic Hearthstone - On Effect Hit (Dummy) - Caster Despawn Instant");

-- http://web.archive.org/web/20120714015749/www.wowhead.com/npc=25320
DELETE FROM `creature_text` WHERE `CreatureID` IN (25318,25320);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25318,0,0,"Avenge me....",12,0,100,0,0,0,24543,0,"Arcane Prisoner"),
(25318,0,1,"Thank you, $r. I shall not forget your kindness.",12,0,100,0,0,0,24544,0,"Arcane Prisoner"),
(25318,0,2,"You've saved me, $c. Thank you!",12,0,100,0,0,0,24545,0,"Arcane Prisoner"),
(25318,0,3,"Thank you, $r. Without your help I would have become one of them!",12,0,100,0,0,0,24546,0,"Arcane Prisoner"),
(25320,0,0,"Avenge me....",12,0,100,0,0,0,24543,0,"Arcane Prisoner"),
(25320,0,1,"Thank you, $r. I shall not forget your kindness.",12,0,100,0,0,0,24544,0,"Arcane Prisoner"),
(25320,0,2,"You've saved me, $c. Thank you!",12,0,100,0,0,0,24545,0,"Arcane Prisoner"),
(25320,0,3,"Thank you, $r. Without your help I would have become one of them!",12,0,100,0,0,0,24546,0,"Arcane Prisoner");
