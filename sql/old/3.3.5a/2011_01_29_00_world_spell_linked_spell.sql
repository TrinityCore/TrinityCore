-- Lunar Fireworks
DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (44430,44429);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(26286,44430,0,'Small Red Rocket - questcredit'),
(26292,44430,0,'Small Green Rocket - questcredit'),
(26291,44430,0,'Small Blue Rocket - questcredit'),
(26327,44429,0,'Red Firework Cluster - questcredit'),
(26325,44429,0,'Green Firework Cluster - questcredit'),
(26304,44429,0,'Blue Firework Cluster - questcredit');
