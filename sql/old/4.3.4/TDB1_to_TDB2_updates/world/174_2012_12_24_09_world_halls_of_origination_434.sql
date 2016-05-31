DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=76599;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 76599, 0, 0, 31, 0, 5, 207218, 0, 0, 0, 0, '', 'Activate Beacons - Beacon of Light'),
(13, 1, 76599, 0, 1, 31, 0, 5, 207219, 0, 0, 0, 0, '', 'Activate Beacons - Beacon of Light'),
(13, 1, 76599, 0, 2, 31, 0, 5, 203133, 0, 0, 0, 0, '', 'Activate Beacons - Beacon of Light'),
(13, 1, 76599, 0, 3, 31, 0, 5, 203136, 0, 0, 0, 0, '', 'Activate Beacons - Beacon of Light');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=75194;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 75194, 0, 0, 31, 0, 3, 40283, 0, 0, 0, 0, '', 'Burning Light - Searing Light');

UPDATE `creature_template` SET `ScriptName`='boss_temple_guardian_anhuur' WHERE `entry`=39425;
UPDATE `creature_template` SET `ScriptName`='',`unit_flags`=`unit_flags`|0x00000040|0x00008000  WHERE `entry`=40183;

DELETE FROM `spell_target_position` WHERE `id`=74969;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(74969, 644, -640.437, 335.306, 77.7573, 1.52073);

UPDATE `instance_template` SET `script`='instance_halls_of_origination' WHERE `map`=644;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (76573,74930);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 74930, 0, 0, 31, 0, 3, 40183, 0, 0, 0, 0, '', 'Shield of Light - Cave In Stalker'),
(13, 2, 76573, 0, 0, 31, 0, 3, 40183, 0, 0, 0, 0, '', 'Shield of Light - Cave In Stalker');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (74930,76573,76599,76606,76608,75592);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(74930, 'spell_anhuur_shield_of_light'),
(76573, 'spell_anhuur_shield_of_light'),
(76599, 'spell_anhuur_activate_beacons'),
(76606, 'spell_anhuur_disable_beacon_beams'),
(76608, 'spell_anhuur_disable_beacon_beams'),
(75592, 'spell_anhuur_divine_reckoning');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (76606,76608);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,76606,0,0,31,0,3,40183,0,0,0,'','Disable Beacon Beams L - Cave In Stalker'),
(13,1,76608,0,0,31,0,3,40183,0,0,0,'','Disable Beacon Beams R - Cave In Stalker');

DELETE FROM `creature_text` WHERE `entry`=39425;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(39425, 0, 0, 'Turn back, intruders! These halls must not be disturbed!', 14, 0, 100, 0, 0, 18580, 'Temple Guardian Anhuur - SAY_AGGRO'),
(39425, 1, 0, 'Beacons of light, bestow upon me your aegis!', 14, 0, 100, 0, 0, 18581, 'Temple Guardian Anhuur - SAY_SHIELD'),
(39425, 2, 0, '%s becomes protected by his defense beacons! Disable them by pulling the levers below!', 41, 0, 100, 0, 0, 0, 'Temple Guardian Anhuur - EMOTE_SHIELD'),
(39425, 3, 0, '%s is no longer protected by the beacons!', 41, 0, 100, 0, 0, 0, 'Temple Guardian Anhuur'),
(39425, 4, 0, 'I regret nothing.', 14, 0, 100, 0, 0, 18582, 'Temple Guardian Anhuur'),
(39425, 5, 0, 'What... have you... done?', 14, 0, 100, 0, 0, 18579, 'Temple Guardian Anhuur - SAY_DEATH');

-- Template updates for creature 40283 (Searing Light)
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`minlevel`=80,`maxlevel`=80,`baseattacktime`=2000,`unit_flags`=`unit_flags`|33555008 WHERE `entry`=40283; -- Searing Light
