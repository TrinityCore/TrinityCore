-- by Drahy
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.6453' WHERE `entry`=33763;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.67305' WHERE `entry`=50464;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.2' WHERE `entry`=5570;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7143' WHERE `entry`=44425;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1936' WHERE `entry`=11113;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1936' WHERE `entry`=31661;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.214' WHERE `entry`=120;
UPDATE `spell_bonus_data` SET `direct_bonus` = '1' WHERE `entry`=19750;
UPDATE `spell_bonus_data` SET `direct_bonus` = '1.66' WHERE `entry`=635;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.4280' WHERE `entry`=8092;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.2' WHERE `entry`=172;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.2129' WHERE `entry`=27243;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.2' WHERE `entry`=30108;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0' WHERE `entry`=17962;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.2140' WHERE `entry`=6789;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.4793' WHERE `entry`=48181;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7139' WHERE `entry`=29722;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.4293' WHERE `entry`=5676;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.8569' WHERE `entry`=686;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.4293' WHERE `entry`=17877;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1932' WHERE `entry`=30283;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.143' WHERE `entry`=689;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.429' WHERE `entry`=1120;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1427' WHERE `entry`=5857;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1427' WHERE `entry`=11681;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1427' WHERE `entry`=11682;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1427' WHERE `entry`=27214;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1427' WHERE `entry`=47822;
UPDATE `spell_bonus_data` SET `dot_bonus` = '0.0949' WHERE `entry`=1949;
UPDATE `spell_bonus_data` SET `ap_bonus` = '0.025' WHERE `entry`=31803;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42208; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42209; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42210; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42211; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42212; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42213; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42198; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42937; 
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.1437' WHERE `entry`= 42938;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.2861' WHERE `entry` =49821;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.2861' WHERE `entry` =53022;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=42223;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=42224;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=42225;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=42226;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=42218;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=47817;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.7024' WHERE `entry`=47818;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.4762' WHERE `entry`=379;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=25914;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=25913;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=25903;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=27175;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=33074;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.81' WHERE `entry`=48821;
UPDATE `spell_bonus_data` SET `direct_bonus` = '0.6453' WHERE `entry`=33763;
DELETE FROM `spell_bonus_data` WHERE `entry` IN (53742,61391,47897,50796,50590,58597,974,47757,52986,52987,52988);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES 
('53742', '0.013', '0', '0.025', 'Paladin - Blood Corruption'),
('61391', '0.193', '0', '0', 'Druid - Typhoon'),
('47897', '0.1064', '0.0667', '0', 'Warlock - Shadowflame'),
('50796', '0.7139', '0', '0', 'Warlock - Chaos Bolt'),
('50590', '0', '0.1622', '0', 'Warlock - Immolation Aura'),
('58597', '0.75', '0', '0', 'Paladin - Sacred Shield'),
('47757', '1.6135', '0', '0', 'Priest - Penance (Rank 1'),
('52986', '1.6135', '0', '0', 'Priest - Penance (Rank 2'),
('52987', '1.6135', '0', '0', 'Priest - Penance (Rank 3'),
('52988', '1.6135', '0', '0', 'Priest - Penance (Rank 4');
DELETE FROM `spell_bonus_data` WHERE `entry` IN (48505,50288,50294,53191,53188,53194,53189,53195,53190);
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES
(50288, 0.05, 0, 0, 'Druid - Starfall rank 1'),
(50294, 0.012, 0, 0, 'Druid - Starfall AOE rank 1'),
(53191, 0.05, 0, 0, 'Druid - Starfall rank 2'),
(53188, 0.012, 0, 0, 'Druid - Starfall AOE rank 2'),
(53194, 0.05, 0, 0, 'Druid - Starfall rank 3'),
(53189, 0.012, 0, 0, 'Druid - Starfall AOE rank 3'),
(53195, 0.05, 0, 0, 'Druid - Starfall rank 4'),
(53190, 0.012, 0, 0, 'Druid - Starfall AOE rank 4');

-- by nesocip
DELETE FROM `spell_bonus_data` WHERE `entry` IN (48721, 55078, 52212, 47632, 55095, 49184, 45477, 50536, 51373, 51374, 51375);
INSERT INTO spell_bonus_data( entry, ap_bonus, comments ) VALUES 
('48721', '0.04', 'DK - Blood Boil'),
('55078', '0.055', 'DK - Blood Plague'),
('52212', '0.0475', 'DK - Death and Decay'),
('47632', '0.15', 'DK - Death Coil'),
('55095', '0.055', 'DK - Frost Fever'),
('49184', '0.1', 'DK - Howling Blast'),
('45477', '0.1', 'DK - Icy Touch'),
('50536', '0.013', 'DK - Unholy Blight (Rank1)'),
('51373', '0.013', 'DK - Unholy Blight (Rank2)'),
('51374', '0.013', 'DK - Unholy Blight (Rank3)'),
('51375', '0.013', 'DK - Unholy Blight (Rank4)');
