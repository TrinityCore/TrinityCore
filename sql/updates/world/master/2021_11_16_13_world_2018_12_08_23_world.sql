-- Jammal'an the Prophet
UPDATE `creature_text` SET `Sound`=5861 WHERE `CreatureID`=5710 AND `GroupID`=0;
UPDATE `creature_text` SET `Sound`=5864 WHERE `CreatureID`=5710 AND `GroupID`=1;
UPDATE `creature_text` SET `Sound`=5862 WHERE `CreatureID`=5710 AND `GroupID`=2;
UPDATE `creature_text` SET `Sound`=5865 WHERE `CreatureID`=5710 AND `GroupID`=3;

UPDATE `smart_scripts` SET `target_type`=1 WHERE `entryorguid`=5710 AND `source_type`=0 AND `id` IN (2,6);
