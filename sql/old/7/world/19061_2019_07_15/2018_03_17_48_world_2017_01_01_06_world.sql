DELETE FROM `creature` WHERE `id` IN(22952,22950,22949,22951);
DELETE FROM `creature_summon_groups` WHERE `summonerId`=23426; -- Illidari Council Trigger
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`) VALUES
(23426,0,1,22952,697.495,310.651,277.527,3.1765 ,6,3600000), -- Veras Darkshadow
(23426,0,1,22950,700.792,307.192,277.526,3.14159,6,3600000), -- High Nethermancer Zerevor
(23426,0,1,22949,700.739,302.722,277.526,3.10669,6,3600000), -- Gathios the Shatterer
(23426,0,1,22951,697.409,299.377,277.526,3.07178,6,3600000); -- Lady Malande

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41333; -- Empyreal Equivalency
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41333,0,0,31,0,3,22950,0,0,0,0,'','Effect_0 hits High Nethermancer Zerevor'),
(13,1,41333,0,1,31,0,3,22949,0,0,0,0,'','Effect_0 hits Gathios the Shatterer'),
(13,1,41333,0,2,31,0,3,22951,0,0,0,0,'','Effect_0 hits Lady Malande'),
(13,1,41333,0,3,31,0,3,22952,0,0,0,0,'','Effect_0 hits Veras Darkshadow');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41499; --  Empyreal Balance
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41499,0,0,31,0,3,22950,0,0,0,0,'','Effect_0 hits High Nethermancer Zerevor'),
(13,1,41499,0,1,31,0,3,22949,0,0,0,0,'','Effect_0 hits Gathios the Shatterer'),
(13,1,41499,0,2,31,0,3,22951,0,0,0,0,'','Effect_0 hits Lady Malande'),
(13,1,41499,0,3,31,0,3,22952,0,0,0,0,'','Effect_0 hits Veras Darkshadow');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=41342; -- Shared Rule
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,41342,0,0,31,0,3,23426,0,0,0,0,'','Effect_0 hits The Illidari Council');

UPDATE `linked_respawn` SET `linkedGuid`=52479 WHERE `linkedGuid`=52762;

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128, `ScriptName`='npc_veras_vanish_effect' WHERE `entry`=23451;
UPDATE `creature_template` SET `ScriptName`='boss_illidari_council' WHERE `entry`=23426;
UPDATE `creature_template` SET `ScriptName`='' WHERE `entry`=23499;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN(
'spell_illidari_council_empyreal_balance',
'spell_illidari_council_empyreal_equivalency',
'spell_illidari_council_balance_of_power',
'spell_illidari_council_deadly_strike',
'spell_illidari_council_deadly_poison',
'spell_illidari_council_judgement',
'spell_illidari_council_seal',
'spell_boss_lady_malande_shield',
'spell_illidari_council_reflective_shield',
'spell_illidari_dampen_magic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(41499,'spell_illidari_council_empyreal_balance'),
(41333,'spell_illidari_council_empyreal_equivalency'),
(41341,'spell_illidari_council_balance_of_power'),
(41480,'spell_illidari_council_deadly_strike'),
(41485,'spell_illidari_council_deadly_poison'),
(41467,'spell_illidari_council_judgement'),
(41469,'spell_illidari_council_seal'),
(41459,'spell_illidari_council_seal'),
(41475,'spell_illidari_council_reflective_shield'),
(41478,'spell_illidari_dampen_magic');

DELETE FROM `creature_text` WHERE `CreatureID` IN(22951,22949,22950,22952) AND (`GroupID` IN(3,4,5,6) OR (`GroupID`=2 AND `ID`=1));
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`Comment`) VALUES
(22949,2,1,'You are MINE!',14,0,100,0,0,11427,21739,0,'council gath SPECIAL2'),
(22949,3,0,'Selama am\'oronor!',14,0,100,0,0,11423,21735,0,'council gath SLAY'),
(22949,4,0,'Well done!',14,0,100,0,0,11424,21736,0,'council gath SLAY_COMT'),
(22949,5,0,'Lord Illidan, I...',14,0,100,0,0,11425,21737,0,'council gath DEATH'),
(22951,2,1,'I\'m full of surprises!',14,0,100,0,0,11487,21719,0,'council mala SPECIAL2'),
(22951,3,0,'My work is done.',14,0,100,0,0,11483,21712,0,'council mala SLAY'),
(22951,4,0,'As it should be.',14,0,100,0,0,11484,21713,0,'council mala SLAY_COMT'),
(22951,5,0,'Destiny... awaits.',14,0,100,0,0,11485,21715,0,'council mala DEATH'),
(22950,2,1,'Sha\'amoor ara mashal?',14,0,100,0,0,11445,21731,0,'council zere SPECIAL2'),
(22950,3,0,'Shorel\'aran.',14,0,100,0,0,11441,21725,0,'council zere SLAY'),
(22950,4,0,'Belesa menoor!',14,0,100,0,0,11442,21727,0,'council zere SLAY_COMT'),
(22950,5,0,'Diel ma\'ahn... orindel\'o.',14,0,100,0,0,11443,21729,0,'council zere DEATH'),
(22952,2,1,'Anar\'alah belore!',14,0,100,0,0,11529,21705,0,'council vera SPECIAL2'),
(22952,3,0,'Valiant effort.',14,0,100,0,0,11525,21699,0,'council vera SLAY'),
(22952,4,0,'A glorious kill!',14,0,100,0,0,11526,21701,0,'council vera SLAY_COMT'),
(22952,5,0,'You got... lucky.',14,0,100,0,0,11527,21703,0,'council vera DEATH');
