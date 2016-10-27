--
DELETE FROM creature_model_info WHERE `DisplayID` IN (64716, 62440, 64184, 64185, 63927, 64703, 62103);
INSERT INTO creature_model_info (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`) VALUES
(64716, 0.306, 1.5, 0), -- 64716
(62440, 0.105, 0.3, 0), -- 62440
(64184, 0.465, 1.5, 0), -- 64184
(64185, 0.465, 1.5, 0), -- 64185
(63927, 2, 1.5, 0), -- 63927
(64703, 0.345, 1.725, 0), -- 64703
(62103, 1, 1.5, 0); -- 62103
