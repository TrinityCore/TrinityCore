--
-- The Force of Neltharaku: Enslaved Netherwing Drake (21722)
UPDATE `creature_template_movement` SET `Flight`= 1 WHERE  `CreatureId`= 21722;
UPDATE `creature_addon` SET `bytes1`= 0 WHERE  `guid` IN (SELECT `guid` FROM `creature` WHERE `id`= 21722);
