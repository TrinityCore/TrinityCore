--
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (27405, 27406);
UPDATE `spell_area`  SET `quest_start` =0, `quest_start_status` =0, `quest_end_status` =0 WHERE `spell`  IN (48761, 48763);

UPDATE `smart_scripts` SET `event_phase_mask`=0 WHERE `entryorguid`=27202 AND `source_type`=0 AND `id` =3;
UPDATE `smart_scripts`  SET `link` =16 WHERE `entryorguid`=27202 AND `source_type`=0 AND `id` =12;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27405, 27406) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2740500, 2740600) AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27202 AND `source_type`=0 AND id>15 ;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27202, 0, 16, 17, 61, 0, 100, 0, 0, 0, 0, 0, 11, 48654, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Spellhit Banshee''s Magic Mirror - Cast The Perfect Dissemblance: Summon Priest''s Footman (No Repeat)'),
(27202, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 85, 48763, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Spellhit Banshee''s Magic Mirror - Cast Scarlet Raven Priest Image'),
(27202, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 85, 48761, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Spellhit Banshee''s Magic Mirror - Cast Scarlet Raven Priest Image'),
(27202, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Raven Priest - On Spellhit Banshee''s Magic Mirror - Set faction'),
(27405, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2740500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - On just summoned - Action list'),
(2740500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Set faction'),
(2740500, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Talk text1'),
(2740500, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Start attack'),
(27405, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 28000, 28000, 11, 50713, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - IC - Unrelenting Onslaught '),
(27406, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2740600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - On just summoned - Action list'),
(2740600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Set faction'),
(2740600, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Talk text1'),
(2740600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - Action list - Start attack'),
(27406, 0, 1, 0, 0, 0, 100, 0, 2000, 2000, 28000, 28000, 11, 50713, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Onslaught Footman - IC - Unrelenting Onslaught ');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (27202);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,18,27202,0,0,20,1,0,0,0,0,0,0,'','Onslaught Raven Priest SAI event 17 require a male character'),
(22,19,27202,0,0,20,1,1,0,0,0,0,0,'','Onslaught Raven Priest SAI event 17 require a female character');

DELETE FROM `creature_text` WHERE `entry` IN (27405, 27406);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(27405,0,0,'What''s going on here, sarge?',12,0,100,0,0,0,'Onslaught Footman', 26541),
(27406,0,0,'I don''t know. Better kill them both to be on the safe side!',12,0,100,0,0,0,'Onslaught Footman', 26542);
