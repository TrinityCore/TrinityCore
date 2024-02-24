-- Add AnimTier Hover for two npc
UPDATE `creature_template_addon` SET `AnimTier`=2 WHERE `entry` IN (19152,26471);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (19152,26471);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(19152, 0, 0, 1, 0, 0, 0, NULL), -- 19152 (Interrogator Khan)
(26471, 0, 0, 1, 1, 0, 0, NULL); -- 26471 (Image of Archmage Aethas Sunreaver)
