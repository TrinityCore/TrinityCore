-- 
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=28379;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=28379 AND `SourceEntry`=51658;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=51659;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 51659, 0, 0, 31, 1, 3, 28379, 0, 0, 0, 0, '', ''),
(17, 0, 51659, 0, 0, 9, 0, 12607, 0, 0, 0, 0, 0, '', '');

DELETE FROM `spell_scripts` WHERE `id`=51659;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(51659,0,0,15,51658,0,0,0,0,0,0);
