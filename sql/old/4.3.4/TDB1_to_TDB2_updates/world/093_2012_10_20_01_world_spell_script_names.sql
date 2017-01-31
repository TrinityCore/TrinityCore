-- Spellscript and conditions for spells of quest Gordunni Cobalt
DELETE FROM `spell_script_names` WHERE `spell_id`=19395;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(19395,'spell_gordunni_trap');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=11757;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(13,1,11757,31,5,144050,'Digging for Cobalt targets Gordunni Trap');
