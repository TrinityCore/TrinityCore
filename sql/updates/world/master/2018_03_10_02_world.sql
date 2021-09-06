-- Quest King of the Mountain
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=16 AND `SourceEntry` IN (31784,31785);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(16,0,31784,0,0,23,0,4513,0,0,0,0,0,'','Geargrinder\'s Jumpbot - Dismount when player is outside intended zone Ymirhein'),
(16,0,31785,0,0,23,0,4513,0,0,0,0,0,'','Thunderbomb\'s Jumpbot - Dismount when player is outside intended zone Ymirhein');

DELETE FROM `creature_template_addon` WHERE `entry` IN(31784,31785);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(31784, 0, 0, 0, 1, 0, 4341),
(31785, 0, 0, 0, 1, 0, 4341);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN(4338,59643);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,59643,0,0,31,0,3,23837,0,0,0,0,'','Spell Plant Horde Battle Standard targets ELM General Purpose Bunny'),
(13,1,4338,0,0,31,0,3,23837,0,0,0,0,'','Spell Plant Alliance Battle Standard targets ELM General Purpose Bunny');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (31784,31785) AND `spell_id`=46598;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(31784, 46598, 1, 0),
(31785, 46598, 1, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (31784,31785) AND `SourceEntry` IN(59593,59656,46598);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 31784, 59593, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Only player for SpellClick'),
(18, 31784, 46598, 0, 0, 31, 0, 3, 0, 0, 0, 0, 0, '', 'Only unit for SpellClick'),
(18, 31785, 59656, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Only player for SpellClick'),
(18, 31785, 46598, 0, 0, 31, 0, 3, 0, 0, 0, 0, 0, '', 'Only unit for SpellClick');

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN(31784, 31785);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES 
(31784,31801,1,1,'Geargrinder\'s Jumpbot',6,30000),
(31785,31801,1,1,'Thunderbomb\'s Jumpbot',6,30000);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_q13280_13283_jump_jets';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(4336,'spell_q13280_13283_jump_jets');

DELETE FROM `spell_proc` WHERE `SpellId`=4341;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(4341,0,0,0,0,0,4096,1,1,0,0,0,0,0,0);
