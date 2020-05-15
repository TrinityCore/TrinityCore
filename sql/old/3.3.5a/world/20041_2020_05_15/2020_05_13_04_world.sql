-- 
DELETE FROM `gameobject` WHERE `guid` IN (2094, 2474, 9489, 9490) AND `id` IN (185522,185519,185460);
DELETE FROM `gameobject` WHERE `id` IN (185522,185519,185460) AND `map`=557 AND `spawnMask`=2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(2094, 185522, 557, 2, 1, -235.563, -13.4403, 17.066, 1.43332, 0, 0, 0.656869, 0.754005, 7200, 255, 1),
(2474, 185460, 557, 2, 1, -235.563, -13.4403, 17.066, 1.43332, 0, 0, 0.656869, 0.754005, 300, 255, 1),
(9489, 185460, 557, 2, 1, 8.73419, -223.864, -0.954936, 0.284522, 0, 0, 0.141782, 0.989898, 300, 255, 1),
(9490, 185519, 557, 2, 1, 8.73419, -223.864, -0.954936, 0.284522, 0, 0, 0.141782, 0.989898, 300, 255, 1);

UPDATE `creature_template` SET `flags_extra`=1 WHERE `entry`=22930;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI" WHERE `entry` = 185522;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 185522 AND `source_type` = 1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(185522,1,0,1,70,0,100,0,2,0,0,0,0,12,22930,8,0,0,0,0,1,0,0,0,0,0,0,0,0,"Shaffar's Stasis Chamber - On Gameobject State Changed - Summon Creature 'Yor'"),
(185522,1,1,0,61,0,100,0,0,0,0,0,0,2,16,0,0,0,0,0,19,22930,0,0,0,0,0,0,0,"Shaffar's Stasis Chamber - On Gameobject State Changed - Set Faction 'Yor'");

UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=185519;
DELETE FROM `smart_scripts` WHERE `entryorguid`=185519 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(185519, 1, 0, 1, 70, 0, 100, 0, 2, 0, 0, 0, 15, 10977, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 0, 0, 0, 'Mana Tombs Stasis Chamber - On Gameobject State Changed - Complete quest'),
(185519, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 22928, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Mana Tombs Stasis Chamber - On Gameobject State Changed - summon Ambassador Pax ivi');

-- Paxivi
SET @ENTRY := 22928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry` =@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 2292800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Pax ivi - On Just Summoned - Run Script'),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Pax ivi - Script - Say Line 0'),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Pax ivi - Script - Say Line 1'),
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 11, 34427, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Pax ivi - Script - Cast Teleport'),
(@ENTRY*100, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Ambassador Pax ivi - Script - Despawn');

DELETE FROM `creature_text` WHERE `CreatureId` = @ENTRY;
INSERT INTO `creature_text` (`CreatureId`, `GroupId`, `ID`, `Text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextId`) VALUES 
(@ENTRY, 0, 0, ' I... I am free! Ethereum were planning on torturing me until I gave in to their requests. I fear that, had you not come along, I would have surely given in to their torment.', 12, 0, 100, 0, 0, 0, 'Paxivi', 20633),
(@ENTRY, 1, 0, ' Know this, $r. Within Shaffar''s chambers at the end of these tombs rests a creature of unimaginable power. It is held in check be the power of the stasis chamber. You must return to Ameer before you venture further if you wish to destroy it!', 12, 0, 100, 0, 0, 0, 'Paxivi', 20634);
