-- 
-- Baron Geddon: Ignite Mana isn't needed
DELETE FROM `spell_custom_attr` WHERE `entry`=19659;

-- Mana-Tombs: Death Coil must be negative
DELETE FROM `spell_custom_attr` WHERE `entry`=38065;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(38065,8192);
