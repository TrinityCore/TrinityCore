-- 
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=6491);
UPDATE `creature_template_addon` SET `auras`='9036 10848' WHERE `entry` IN (6491,29259); -- Spirit Healer - 9036 - Ghost, 10848 - Shroud of Death
