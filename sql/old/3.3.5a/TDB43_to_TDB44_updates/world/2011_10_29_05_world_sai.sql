DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=33581; -- item
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (43315,43371); -- spell
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=43315; -- spell2
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- (13, 0, 43315, 0, 18, 1, 24238, 5, 0, '', 'Only use Insult on Bjorn Halgurdsson'),
-- (18, 0, 33581, 0, 24, 1, 24238, 0, 0, '', 'Only use Insult on Bjorn Halgurdsson'),
(17, 0, 43315, 0, 19, 24238, 0, 0, 63, '', 'Vrykul Insult - Bjorn Halgurdsson'), -- "Invalid Target" trinity_string
(13, 0, 43371, 0, 18, 1, 0, 0, 0, '', 'Bjorn Kill Credit - Players');

DELETE FROM `creature_text` WHERE `entry`=24238;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(24238, 0, 0, 'Drive the invaders out! For Queen Angerboda!', 14, 0, 100, 0, 0, 0, 'Bjorn Halgurdsson - On aggro 1'),
(24238, 1, 0, 'No one speaks of my mother in that manner!', 14, 0, 100, 0, 0, 0, 'Bjorn Halgurdsson - On aggro 2'),
(24238, 2, 0, 'Fight without fear and the Val''kyr will reward you!', 14, 0, 100, 0, 0, 0, 'Bjorn Halgurdsson - Random 1'),
(24238, 2, 1, 'The Winterskorn tribe will prevail!', 14, 0, 100, 0, 0, 0, 'Bjorn Halgurdsson - Random 2');

DELETE FROM `smart_scripts` WHERE `entryorguid`=24238 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(24238, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 43371, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - On death cast Bjorn Kill Credit (Quest: Adding Injury to Insult)'),
(24238, 0, 1, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - In combat (nr) say text 0'),
(24238, 0, 2, 0, 0, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - In combat (nr) say text 1'),
(24238, 0, 3, 0, 0, 0, 100, 0, 5000, 10000, 10000, 15000, 11, 32736, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - In combat cast Mortal Strike'),
(24238, 0, 4, 0, 0, 0, 100, 0, 0, 5000, 10000, 15000, 11, 33661, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bjorn Halgurdsson - In combat cast Crush Armor'),
(24238, 0, 5, 0, 0, 0, 100, 0, 10000, 150000, 10000, 15000, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 , 0, 0, 'Bjorn Halgurdsson - In combat say text 2');

UPDATE `creature_template` SET `AIName`='SmartAI', `mechanic_immune_mask`=`mechanic_immune_mask`|1|2|8|16|32|64|1024|2048|4096|16384|65536|131072|524288|2097152|8388608|536870912|67108864 WHERE `entry`=24238;
