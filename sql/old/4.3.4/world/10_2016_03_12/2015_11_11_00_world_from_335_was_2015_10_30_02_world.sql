--
UPDATE `npc_spellclick_spells` SET `cast_flags`=1 WHERE `npc_entry`=26477 AND `spell_id`=61832;

UPDATE smart_scripts SET action_param1=48600 WHERE entryorguid=27292 AND source_type=0 AND id=3;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=48600;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(13, 1, 48600, 31, 0, 3, 27292, "Ride Flamebringer effect only on Flamebringer");
