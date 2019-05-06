UPDATE `creature_template` SET `unit_flags`=32832 WHERE `entry`=24892;
UPDATE `creature_template` SET `flags_extra`= `flags_extra` |512 WHERE `entry`=24850;
UPDATE `creature_template` SET `unit_flags`=32832, `ScriptName`='boss_kalecgos_human' WHERE `entry`=24891;
UPDATE `gameobject_template` SET `ScriptName`='go_kalecgos_spectral_rift' WHERE `entry`=187055;

DELETE FROM `creature_template_addon` WHERE `entry` IN (24891,24892);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(24891,0,0,0,1,0,44801),
(24892,0,0,0,1,0,'44800 44801');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=46733;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46733,0,1,31,0,3,24892,0,0,0,0,'','Spell Tap Check targets Sathrovarr');

UPDATE `creature_text` SET `Type`=12 WHERE `CreatureID`=24850 AND `GroupID`=2 AND`ID`=0;
UPDATE `creature_text` SET `TextRange`=2 WHERE `CreatureID` IN(24850,24891,24892);
UPDATE `creature_text` SET `comment`='kalecgos SAY_OUTRO1' WHERE `CreatureID`=24850 and`GroupID`=2 and`ID`=0;
UPDATE `creature_text` SET `comment`='kalecgos SAY_GOOD_NEAR_DEATH1' WHERE `CreatureID`=24891 and`GroupID`=1 and`ID`=0;
DELETE FROM `creature_text` WHERE `CreatureID`=24891 AND `GroupID`=3;
DELETE FROM `creature_text` WHERE `CreatureID`=24850 AND `GroupID` IN(3,4,6);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24891,3,0,'There is no time to waste!',14,0,100,0,0,12435,24993,2,'kalecgos SAY_GOOD_DEATH'),
(24850,3,0,'Kil\'jaeden must be destroyed!',14,0,100,0,0,12433,25502,2,'SAY_OUTRO_2'),
(24850,4,0,'Sathrovarr drives Kalecgos into a crazed rage!',41,0,100,0,0,0,24983,2,'kalecgos SAY_ENRAGE'),
(24850,6,0,'I will purge you!',14,0,100,0,0,0,25497,2,'kalecgos SAY_ARCANE_BUFFET'),
(24850,6,1,'Your pain has only begun!',14,0,100,0,0,0,25498,2,'kalecgos SAY_ARCANE_BUFFET');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (44869,46019,46021,-46021);

DELETE FROM `spell_script_names` WhERE `ScriptName` IN
('spell_kalecgos_spectral_blast',
'spell_kalecgos_spectral_realm_trigger',
'spell_kalecgos_spectral_realm_aura',
'spell_kalecgos_curse_of_boundless_agony',
'spell_kalecgos_tap_check');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(44869,'spell_kalecgos_spectral_blast'),
(44811,'spell_kalecgos_spectral_realm_trigger'),
(46021,'spell_kalecgos_spectral_realm_aura'),
(45032,'spell_kalecgos_curse_of_boundless_agony'),
(45034,'spell_kalecgos_curse_of_boundless_agony'),
(46732,'spell_kalecgos_tap_check');
