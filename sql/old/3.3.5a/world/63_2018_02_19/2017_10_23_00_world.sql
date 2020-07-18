-- Warsong Battleguard (25242), Warsong Honor Guard (25243)
DELETE FROM `creature_text` WHERE `CreatureID` IN (25242,25243);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25242,0,0,"$g Sir:Ma'am;, my life for the Horde!",12,1,100,0,0,0,25267,0,'Warsong Battleguard'),
(25242,0,1,"Welcome back, champion.",12,1,100,0,0,0,25268,0,'Warsong Battleguard'),
(25242,0,2,"It is an honor to serve along your side, $g sir:ma'am;.",12,1,100,0,0,0,25269,0,'Warsong Battleguard'),
(25242,0,3,"Lok'tar ogar!",12,1,100,0,0,0,25270,0,'Warsong Battleguard'),
(25242,0,4,"Throm-Ka, hero!",12,1,100,0,0,0,25271,0,'Warsong Battleguard'),
(25242,0,5,"With your strength and determination, we cannot fail!",12,1,100,0,0,0,25272,0,'Warsong Battleguard'),
(25242,0,6,"There walks a hero!",12,1,100,0,0,0,25273,0,'Warsong Battleguard'),
(25242,0,7,"It's $n! Bow your heads!",12,1,100,0,0,0,25274,0,'Warsong Battleguard'),
(25242,0,8,"%s cheers at you.",16,1,100,0,0,0,25275,0,'Warsong Battleguard'),
(25243,0,0,"$g Sir:Ma'am;, my life for the Horde!",12,1,100,0,0,0,25267,0,'Warsong Honor Guard'),
(25243,0,1,"Welcome back, champion.",12,1,100,0,0,0,25268,0,'Warsong Honor Guard'),
(25243,0,2,"It is an honor to serve along your side, $g sir:ma'am;.",12,1,100,0,0,0,25269,0,'Warsong Honor Guard'),
(25243,0,3,"Lok'tar ogar!",12,1,100,0,0,0,25270,0,'Warsong Honor Guard'),
(25243,0,4,"Throm-Ka, hero!",12,1,100,0,0,0,25271,0,'Warsong Honor Guard'),
(25243,0,5,"With your strength and determination, we cannot fail!",12,1,100,0,0,0,25272,0,'Warsong Honor Guard'),
(25243,0,6,"There walks a hero!",12,1,100,0,0,0,25273,0,'Warsong Honor Guard'),
(25243,0,7,"It's $n! Bow your heads!",12,1,100,0,0,0,25274,0,'Warsong Honor Guard'),
(25243,0,8,"%s cheers at you.",16,1,100,0,0,0,25275,0,'Warsong Honor Guard');

UPDATE `creature_equip_template` SET `ItemID1`=34640, `ItemID2`=21549 WHERE `CreatureID`=25242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25242,25243);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25242,25243);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25242, 0, 0, 0, 10, 0, 40, 0, 1, 20, 120000, 180000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warsong Battleguard - OOC LOS - Say Line'),
(25242, 0, 1, 0, 9, 0, 100, 0, 5, 30, 2000, 2000, 11, 36980, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warsong Battleguard - At rang - Cast Shoot'),
(25242, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warsong Battleguard - HPCT - Cast Enrage'),
(25243, 0, 0, 0, 10, 0, 40, 0, 1, 20, 120000, 180000, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Warsong Honor Guard - OOC LOS - Say Line'),
(25243, 0, 1, 0, 9, 0, 100, 0, 5, 30, 2000, 2000, 11, 36980, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Warsong Honor Guard - At rang - Cast Shoot'),
(25243, 0, 2, 0, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Warsong Honor Guard - HPCT - Cast Enrage');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 22 AND `ConditionTypeOrReference`= 8 AND `SourceEntry` IN (25242,25243);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22, 1, 25242, 0, 0, 8, 0, 11916, 0, 0, 0, 0, 0, '', 'Warsong Battleguard - Only run SAI if quest 11916 is rewarded'),
(22, 1, 25243, 0, 0, 8, 0, 11916, 0, 0, 0, 0, 0, '', 'Warsong Honor Guard - Only run SAI if quest 11916 is rewarded');
