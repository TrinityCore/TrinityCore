DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (28935, 28534);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Flight`) VALUES
(28935, 1, 1),
(28534, 1, 1);

UPDATE `smart_scripts` SET `action_type`=46 WHERE `entryorguid`=2861001 AND `id`=2 AND `source_type`=9;

DELETE FROM `gameobject_questender` WHERE `id`= 190936;
INSERT INTO `gameobject_questender` (`id`, `quest`) VALUES
(190936, 12717),
(190936, 12718);
