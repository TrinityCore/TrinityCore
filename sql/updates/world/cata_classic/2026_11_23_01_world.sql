DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (16500, 17089, 16503, 16501, 16499);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(16500, 7264, 60192), -- Valaatu
(17089, 7522, 60192), -- Firmanvaar
(16503, 7263, 60192), -- Kore
(16501, 7260, 60192), -- Aurelon
(16499, 7262, 60192); -- Keilnei
