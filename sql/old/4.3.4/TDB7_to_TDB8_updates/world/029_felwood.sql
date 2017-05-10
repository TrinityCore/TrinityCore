-- felwood
UPDATE `quest_template` SET `PrevQuestId`=28155 WHERE `Id` IN (28305);
UPDATE `quest_template` SET `PrevQuestId`=28190 WHERE `Id` IN (28214);
UPDATE `quest_template` SET `PrevQuestId`=28207 WHERE `Id` IN (28208);
UPDATE `quest_template` SET `PrevQuestId`=28213 WHERE `Id` IN (28306);

UPDATE `creature_template` SET `lootid`=47687 WHERE `entry`=47687;
DELETE FROM `creature_loot_template` WHERE `entry`=47687 AND `item`=63279;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(47687,63279,-100,1,0,1,1); -- Add missing quest item to Winna's Kitten for quest Winna's Kitten

UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=47747;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=48457;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (47747,48457);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(47747,89960,1,1),(48457,90102,1,1);

-- Add spell click conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry` IN (47747,48457);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 47747, 89960, 0, 0, 9, 28374, 0, 0, 0, '', 'Whisperwind Lasher Trigger Spell targets Whisperwind Lasher if player has quest Weeding the Lawn'),
(18, 48457, 90102, 0, 0, 9, 28361, 0, 0, 0, '', 'Squirrel Scrubber Vehicle Aura targets Tainted Squirrel if player has quest Squirrely Clean');

DELETE FROM `gameobject` WHERE `guid`=225984;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(225984, 206966, 1, 1, 1, 0, 6089.81, -871.783, 410.937, 0.174531, 0, 0, 0, 1, 120, 255, 1);
