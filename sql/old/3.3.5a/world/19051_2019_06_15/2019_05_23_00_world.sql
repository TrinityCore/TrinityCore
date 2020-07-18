-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (21394,21930, 21942, 21944, 21935);
UPDATE `creature_template_addon` SET `auras`="33356" WHERE `entry` IN (21930);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (21394,21930, 21942, 21944, 21935);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(21394,0,0,1,0),(21930,0,0,1,0),(21942,0,0,1,0),(21944,0,0,1,0),(21935,0,0,1,0);

DELETE FROM `spell_target_position` WHERE `ID` IN(37908,24831,36801);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`) VALUES 
(36801, 2, 530, 1920.06, 5581.87, 270.723, 5.1846),
(24831, 0, 0, -9569.6, -13.7809, 69.7455, 4.85433);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 37908;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES 
(37908, 36801, 0, 'Aura Visual Teleport - teleport');

UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `event_param3`=2000, `event_param4`=2000, `action_type`=86, `action_param3`=19, `action_param4`=21930 WHERE `entryorguid`=2146100 AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `event_param3`=2000, `event_param4`=2000, `action_type`=86, `action_param3`=19, `action_param4`=21944 WHERE `entryorguid`=2210483 AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `event_param3`=2000, `event_param4`=2000, `action_type`=86, `action_param3`=19, `action_param4`=21942 WHERE `entryorguid`=2167561 AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=2000, `event_param2`=2000, `event_param3`=2000, `event_param4`=2000, `action_type`=86, `action_param3`=19, `action_param4`=21413 WHERE `entryorguid`=2189022 AND `source_type`=9 AND `id`=5;
UPDATE `smart_scripts` SET `event_param1`=3000, `event_param2`=3000, `event_param3`=3000, `event_param4`=3000 WHERE `entryorguid`IN (2146100,2210483,2167561,2189022) AND `source_type`=9 AND `id`=6;
