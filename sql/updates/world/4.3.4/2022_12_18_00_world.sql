DELETE FROM `creature` WHERE `guid` IN (264981, 264983, 265265, 265267, 265269, 265272, 265286, 265291, 265293, 265295, 265297, 265300, 265404, 265411, 265420, 265422, 265424, 265435, 265437, 265444, 265446, 265451, 265453, 265571, 265574, 265579, 265593, 265597);
DELETE FROM `creature_addon` WHERE `guid` IN (264981, 264983, 265265, 265267, 265269, 265272, 265286, 265291, 265293, 265295, 265297, 265300, 265404, 265411, 265420, 265422, 265424, 265435, 265437, 265444, 265446, 265451, 265453, 265571, 265574, 265579, 265593, 265597);
DELETE FROM `spawn_group` WHERE `spawnType`= 0 AND `spawnId` IN (264981, 264983, 265265, 265267, 265269, 265272, 265286, 265291, 265293, 265295, 265297, 265300, 265404, 265411, 265420, 265422, 265424, 265435, 265437, 265444, 265446, 265451, 265453, 265571, 265574, 265579, 265593, 265597);

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 45716;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(45716, 45715, 0, 0, 'Orsis Suviror Vehicle - Orsis Survivor', 8, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (45716, 45715);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45716, 46598, 1, 0),
(45715, 85372, 1, 1);

UPDATE `creature_template` SET `npcflag`= 0x1000000 WHERE `entry`= 45715;
UPDATE `creature_template` SET `flags_extra`= 0x80 WHERE `entry`= 45716;

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (45715, 45716);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`,`Rooted`) VALUES
(45715, 1, 0, 0, 0),
(45716, 0, 0, 1, 1);

DELETE FROM `creature_text` WHERE `CreatureID`= 45715;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(45715, 0, 0, 'I... *cough*  I thank you, stranger.', 12, 0, 100, 0, 0, 0, 45820, 0, 'Orsis Survivor'),
(45715, 0, 1, 'I owe you my life.  My people have paid a high price for defying Deathwing.', 12, 0, 100, 0, 0, 0, 45821, 0, 'Orsis Survivor');

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_uldum_rescue_survivor';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(85372, 'spell_uldum_rescue_survivor');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 18 AND `SourceGroup`= 45715;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`, `Comment`) VALUES
(18, 45715, 85372, 9, 27519, '', 'Required quest active for spellclick');
