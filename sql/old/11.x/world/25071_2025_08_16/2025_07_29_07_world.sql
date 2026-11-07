-- Class Death Knight
DELETE FROM `playercreateinfo_action` WHERE (`race`=1 AND `class`=6 AND `button`=10) OR (`race`=5 AND `class`=6 AND `button`=9) OR (`race`=10 AND `class`=6 AND `button`=10) OR (`race`=25 AND `class`=6 AND `button`=9) OR (`race`=25 AND `class`=6 AND `button`=4) OR (`race`=25 AND `class`=6 AND `button`=3) OR (`race`=25 AND `class`=6 AND `button`=1) OR (`race`=25 AND `class`=6 AND `button`=0) OR (`race`=26 AND `class`=6 AND `button`=0) OR (`race`=26 AND `class`=6 AND `button`=1) OR (`race`=26 AND `class`=6 AND `button`=2) OR (`race`=26 AND `class`=6 AND `button`=3) OR (`race`=26 AND `class`=6 AND `button`=5) OR (`race`=26 AND `class`=6 AND `button`=9);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(1, 6, 10, 1231411, 0), -- Recuperate
(5, 6, 9, 7744, 0), -- Will of the Forsaken
(10, 6, 10, 50613, 0), -- Arcane Torrent
(25, 6, 0, 316239, 0), -- Rune Strike
(25, 6, 1, 47541, 0), -- Death Coil
(25, 6, 3, 43265, 0), -- Death and Decay
(25, 6, 4, 49576, 0), -- Death Grip
(25, 6, 9, 107079, 0), -- Quaking Palm
(26, 6, 0, 316239, 0), -- Rune Strike
(26, 6, 1, 47541, 0), -- Death Coil
(26, 6, 2, 53428, 0), -- Runeforging
(26, 6, 3, 43265, 0), -- Death and Decay
(26, 6, 5, 49576, 0), -- Death Grip
(26, 6, 9, 107079, 0); -- Quaking Palm

UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=1 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=2 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=3 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=4 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=5 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=6 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=7 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=8 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=9 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=10 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=11 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=316239 WHERE (`race`=22 AND `class`=6 AND `button`=0); -- Rune Strike
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=1 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=2 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=3 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=4 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=5 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=6 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=7 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=8 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=9 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=10 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=11 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=47541 WHERE (`race`=22 AND `class`=6 AND `button`=1); -- Death Coil
UPDATE `playercreateinfo_action` SET `action`=53428 WHERE (`race`=27 AND `class`=6 AND `button`=2); -- Runeforging
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=1 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=2 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=3 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=4 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=5 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=6 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=7 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=8 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=9 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=10 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=11 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=43265 WHERE (`race`=22 AND `class`=6 AND `button`=3); -- Death and Decay
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=1 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=2 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=3 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=4 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=5 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=6 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=7 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=8 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=9 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=10 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=11 AND `class`=6 AND `button`=5); -- Death Grip
UPDATE `playercreateinfo_action` SET `action`=49576 WHERE (`race`=22 AND `class`=6 AND `button`=5); -- Death Grip
