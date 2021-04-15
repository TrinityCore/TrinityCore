-- 
-- DB/Creature: Frost Freeze Trap - Spellcast
DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=70460;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0, 70460, 64, '', '', 'Ignore LOS for Coldflame Jets');
