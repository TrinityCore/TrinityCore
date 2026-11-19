--
UPDATE `creature_template` SET `ScriptName`= 'npc_volkhan_molten_golem' WHERE `entry`= 28695;
UPDATE `creature_template` SET `mechanic_immune_mask`= `mechanic_immune_mask` | 0x2000000 | 0x100 WHERE `entry` IN (28587, 31536);

UPDATE `creature` SET `wander_distance`= 0, `MovementType`= 0 WHERE `guid`= 126875;
DELETE FROM `creature_template_movement` WHERE `CreatureId`= 28823;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(28823, 0, 0, 1, 1);

DELETE FROM `creature_text` WHERE `CreatureID`= 28587;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(28587, 0, 0, 'It is you who have destroyed my children? You... shall... pay!', 14, 0, 100, 0, 0, 13960, 31415, 'Volkhan - Aggro'),
(28587, 1, 0, '%s runs to his anvil!', 41, 0, 100, 0, 0, 0, 32214, 'Volkhan - Announce Run to Anvil'),
(28587, 2, 0, 'Nothing is wasted in the process. You will see....', 14, 0, 100, 0, 0, 13962, 31417, 'Volkhan - Run to Anvil'),
(28587, 2, 1, 'Life from lifelessness... death for you.', 14, 0, 100, 0, 0, 13961, 31416, 'Volkhan - Run to Anvil'),
(28587, 3, 0, 'All my work... undone!', 14, 0, 100, 0, 0, 13964, 31419, 'Volkhan - Shattering Stomp'),
(28587, 3, 1, 'I will crush you beneath my boots!', 14, 0, 100, 0, 0, 13963, 31418, 'Volkhan - Shattering Stomp'),
(28587, 4, 0, '%s prepares to shatter his Brittle Golems!', 41, 0, 100, 0, 0, 0, 29823, 'Volkhan - Announce Shattering Stomp'),
(28587, 5, 0, 'The master was right... to be concerned.', 14, 0, 100, 0, 0, 13968, 31423, 'Volkhan - Death'),
(28587, 6, 0, 'The armies of iron will conquer all!', 14, 0, 100, 0, 0, 13965, 31420, 'Volkhan - Slay'),
(28587, 6, 1, 'Feh! Pathetic!', 14, 0, 100, 0, 0, 13966, 31421, 'Volkhan - Slay'),
(28587, 6, 2, 'You have cost me too much work!', 14, 0, 100, 0, 0, 13967, 31422, 'Volkhan - Slay');

DELETE FROM `conditions` WHERE `SourceEntry` IN (52661, 52654, 52238, 52387, 59528) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 52661, 0, 0, 31, 0, 3, 28823, 0, 0, 0, '', 'Temper - Target Volkhan''s Anvil'),
(13, 1, 52654, 0, 0, 31, 0, 3, 28823, 0, 0, 0, '', 'Temper - Target Volkhan''s Anvil'),
(13, 1, 52238, 0, 0, 31, 0, 3, 28823, 0, 0, 0, '', 'Temper - Target Volkhan''s Anvil'),
(13, 1, 52387, 0, 0, 31, 0, 3, 28695, 0, 0, 0, '', 'Heat - Target Molten Golem'),
(13, 1, 59528, 0, 0, 31, 0, 3, 28695, 0, 0, 0, '', 'Heat - Target Molten Golem');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_volkhan_temper_dummy',
'spell_volkhan_cool_down',
'spell_volkhan_cosmetic_stun_immune_permanent',
'spell_volkhan_shattering_stomp');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52654, 'spell_volkhan_temper_dummy'),
(52238, 'spell_volkhan_temper_dummy'),
(52441, 'spell_volkhan_cool_down'),
(59123, 'spell_volkhan_cosmetic_stun_immune_permanent'),
(52237, 'spell_volkhan_shattering_stomp'),
(59529, 'spell_volkhan_shattering_stomp');
